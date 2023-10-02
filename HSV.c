#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;


int main() {

	FILE *fp;

	int X = 296, Y = 302;
	unsigned char Readbuf[X][Y][3];
	unsigned char Writebuf[X][Y];
	int i = 0, j = 0;
	double V = 0.0, S = 0.0, H = 0.0;

	fp = fopen("pepero.raw", "rb");

	//초기화
	for(i = 0; i < X; i++)	
		for(j = 0; j < Y; j++)
			fread(Readbuf[i][j], 1, 3, fp);

	fclose(fp);

	double R = (double)Readbuf[1][1][0] / 255.0;
	double G = (double)Readbuf[1][1][1] / 255.0;
	double B = (double)Readbuf[1][1][2] / 255.0;

	V = max(R, max(G, B));

	double minus = (V - (min(R, min(G, B))));

	if(V == 0) 
		S = 0;
	else 
		S = minus / V;


	if(V == R)
		H = (60 * (G - B)) / minus;
	else if(V == G)
		H = (60 * (B - R)) / minus + 120;
	else if(V == B)
		H = (60 * (R- G)) / minus + 240;


	if(H < 0)
		H = H + 360;

	H = 255.0 / 360.0 * H;
	S = S * 255.0;
	V = V * 255.0;

	printf("H: %0.1lf S: %0.1lf V: %0.1lf", H, S, V);


	return 0;

}
