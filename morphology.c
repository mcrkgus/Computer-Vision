#include<stdio.h>

#include<windows.h>

#pragma warning(disable:4996)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))


int main() {

	FILE* fp;



	unsigned char Readbuf[X][Y];
	unsigned char Writebuf[X][Y];
	unsigned char Writebuf2[X][Y];
	unsigned char median[9];

	short mask[A][B] = { {9,9,9},{9,9,9},{9,9,9} };



	fp = fopen("lena.raw", "rb");

	for (int i = 0; i < X; i++)

	fread(Readbuf[i], 1, Y, fp);

	fclose(fp);


	//침식
	for(int i = 0; i < 256; i++) {
		for(int j = 0; j < 256; j++) {
			for(int x = 0; x < 3; x++) {
				for(int y = 0; y < 3; y++) {
					D[i][j] = min(Readbuf[i+x][j+y], Readbuf[i-1+x][j-1+y]);
				}
			}
		}
	}

	//팽창
	for(int i = 0; i < 256; i++) {
		for(int j = 0; j < 256; j++) {
			for(int x = 0; x < 3; x++) {
				for(int y = 0; y < 3; y++) {
					E[i][j] = max(Readbuf[i-x][j-y], Readbuf[i-1-x][j-1-y]);
				}
			}
		}
	}

	



	fp = fopen("박스.raw", "wb");

	for (int i = 0; i < X; i++)

	fwrite(Writebuf[i], 1, Y, fp);

	fclose(fp);



	fp = fopen("메디안.raw", "wb");

	for (int i = 0; i < X; i++)

	fwrite(Writebuf2[i], 1, Y, fp);

	fclose(fp);



	return 0;

}
