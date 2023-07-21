#include<stdio.h>
#include<stdlib.h>



int main() {

	FILE *fp;
	int X = 296, Y = 302;
	unsigned char Readbuf[X][Y][3];
	unsigned char Writebuf[X][Y];
	int i = 0, j = 0;

	  
	fp = fopen("pepero.raw", "rb");

	//초기화
	for(i = 0; i < X; i++)
		for(j = 0; j < Y; j++)
			fread(Readbuf[i][j], 1, 3, fp);

	fclose(fp);

	double T[3] = {0.299, 0.589, 0.114};

	for(i = 0; i < X; i++){
		for(j = 0; j < Y; j++){
			Writebuf[i][j] = Readbuf[i][j][0] * T[0] + Readbuf[i][j][1] * T[1] + Readbuf[i][j][2] * T[2];
		}
	}


	//영상저장 
	fp = fopen("peperogray.raw", "wb");

	for(i = 0; i < X; i++)
		fwrite(Writebuf[i], 1, Y, fp);

	fclose(fp);



	return 0;
}
