#include <stdio.h>

#include <windows.h>



#pragma warning(disable:4996)

//영상의 히스토그램을 구하는 함수
void IppHistogram(IppByteImage& img, float histo[256])
{
    int size = img.GetSize();
    BYTE* p = img.GetPixels();

    // 히스토그램 계산
    int cnt[256];
    memset(cnt, 0, sizeof(int) * 256);
    for (int i = 0; i < size; i++)
        cnt[p[i]]++;

    // 히스토그램 정규화(histogram normalization)
    for (int i = 0; i < 256; i++)
    {
        histo[i] = static_cast<float>(cnt[i]) / size;	//histo[i] = histo[i] / (256*256)
    }
}


int main() {

	FILE *fp;
	unsigned char Readbuf[256][256];
	unsigned char Writebuf[256][256];

//영상 읽기 //1826
	fp = fopen("lena_graycsale.bmp", "rb");	

	for (int i = 0; i < 256; i++)
		fread(Readbuf[i], 1, 256, fp);

	fclose(fp);


//영상 편집
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < 256; j++)
			Writebuf[j][i] = Readbuf[j][i];


//히스토그램 정규화
	for (int i = 0; i < 256; i++)
		for(int j = 0; j < 256; j++)
			histo[i][j] = histo[i][j] / (256 * 256)

//영상 저장
	fp= fopen("lena(BMP).raw", "wb");

	for (int i = 0; i < 256; i++)
		fwrite(Writebuf[i], 1, 256, fp);

	fclose(fp);


	return 0;
}
