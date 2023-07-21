#include <stdio.h>
#include <stdlib.h>
#define SWAP(a, b, tmp) {tmp=a; a=b; b=tmp;}
#pragma warning(disable:4996)


//컨볼루션
int convolution(unsigned char buf[][256], int x, int y){

 	int sum = 0;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			sum += (buf[x - i][y - j]/9);

	return sum;

}


//메디안
int median(unsigned char buf[][256], int x, int y) {

	unsigned char temp[9];
	int temp_cnt = 0;
	int sum = 0;

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			temp[temp_cnt++] = buf[x - i][y - j];



	int tmp;

	for (int i = 0; i < 9 - 1; i++)
		for (int j = 0; j < 9 - 1 - i; j++)
			if (temp[j] > temp[j + 1])
				SWAP(temp[j], temp[j + 1], tmp);	//정렬 


	return temp[5];	//중간값
}



int main()

{

	unsigned char Readbuf[256][256];
	unsigned char Writebuf1[256][256] = { 0, };
	unsigned char Writebuf2[256][256] = { 0, };


	//영상 읽기 
	FILE* fp = fopen("LENA_256x256_8bit.raw", "rb");

	for (int i = 0; i < 256; i++)
		fread(Readbuf[i], 1, 256, fp);

	fclose(fp);


	//영상 편집 -> 컨볼루션 and 메디안
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++)
			Writebuf2[i][j] = Readbuf[i][j];

	for (int i = 1; i < 256 - 1; i++) {
		for (int j = 1; j < 256 - 1; j++) {
			Writebuf1[i][j] = convolution(Readbuf, i, j);//convolution
			Writebuf2[i][j] = median(Readbuf, i, j);//median

		}
	}



	//영상 저장
	FILE *fp1 = fopen("LENA_convolution.raw", "wb");
	FILE *fp2 = fopen("LENA_median.raw", "wb");

	for (int i = 0; i < 256; i++) {
		fwrite(Writebuf1[i], 1, 256, fp1);
		fwrite(Writebuf2[i], 1, 256, fp2);
	}

	fclose(fp1);
	fclose(fp2);

	return 0;

}
