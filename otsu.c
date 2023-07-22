 #include <stdio.h>

#include <windows.h>
#pragma warning(disable:4996)


int main() {

	FILE* fp;

	unsigned char Readbuf[256][256];
	unsigned char Writebuf[256][256];
	unsigned long histogram[256] = { 0 };
	double histogram_n[256] = { 0 };
	double histogram_c[256];
	float scale = 256 * 256;

 
	fp = fopen("LENA_256x256_8bit.raw", "rb");

	for (int i = 0; i < 256; i++)
		fread(Readbuf[i], 1, 256, fp);

 	fclose(fp);

 

	//히스토그램
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			histogram[Readbuf[i][j]]++;
		}
	}

 

	int result, wb, wf, ub, uf, u, max, temp;
	result = wb = wf = ub = uf = u = max = temp = 0;

 
	// 오츄

	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < i + 1; j++) { // background
			wb += histogram[j];  // weight
			ub = (double)(ub + j * histogram[i] / wb);  // mean
		}

		for (int j = i + 1; j < 256; j++) { // foreground
			wf += histogram[j];   // weight
			uf = (double)(uf + j * histogram[j] / wf);  // mean
		}

 		u = (wb * ub) + (wf * uf);  // total mean
		result = wb * wf * (uf - ub) * (uf - ub);  //between variance
		// result = (wb*(ub-u)*(ub-u)) + (wf*(uf-u)*(uf-u))

		if (result > max) {
			max = result;
			temp = i;
		}
	}

	//임계값 T 
 	int T = temp;
	printf("T = %d", T);


	//영상 이진화
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 256; j++) {
			if(Readbuf[i][j] > T)
				Writebuf[i][j] = 255;
			else
				Writebuf[i][j] = 0;
		}
	}

	

	//영상 저장
	fp = fopen("lena.raw", "wb");


	for (int i = 0; i < 256; i++)

		fwrite(Writebuf[i], 1, 256, fp);

 

	fclose(fp);

 

	return 0;

}



int otsh_threshold = 0;
double inter_class_variance = 0;
double calcBinary[256];
Mat dst; // 사전에 정규화된 히스토그램 행렬

// 0 ~ 256 사이의 임계값 구하기
for (int i = 0; i < 256; i++) {
    int alpha = 0, beta = 0;
    int sum1 = 0, sum2 = 0;
    double avg1 = 0, avg2 = 0;

    // w0 계산 (0 ~ t까지의 누적합)
    for (int j = 0; j < i; j++)
        sum1 += calcBinary[j];

    // w1 계산 (t + 1 ~ L - 1까지의 누적합)
    sum2 = dst.rows * dst.cols - sum1;

    // w0과 w1의 가중치 구하기
    alpha = (double)sum1 / (double)calcBinary.size();
    beta = (double)sum2 / (double)calcBinary.size();

    // μ0과 μ1 구하기 (w0과 w1의 평균)
    for (int m = 0; m < i; m++)
        avg1 += (double)(m * calcBinary[m]) / (double)sum1;

    for (int m = i; m < 256; m++)
        avg2 += (double)(m * calcBinary[m]) / (double)sum2;

    // v0과 v1 구하기 (분산)
    double temp = alpha * beta * pow((avg1 - avg2), 2);

    // 가장 큰 V between(t)를 임계값 T로 취한다.
    if (inter_class_variance < temp) {
        inter_class_variance = temp;
        otsh_threshold = i;
    }
}

