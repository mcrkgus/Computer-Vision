#include<stdio.h>
#define min (a, b, c, d) 

int main() {
	Mat img = read
	int S01 = 0;
	int S0_1 = 0;
	int S10 = 0;
	int S_10 = 0;
	int x;
	int y;
	int C = 0;

//S01 = 4
	for (y = 4; y <= 6; y++) {
		for (x = 2; x <= 4; x++) {
			S01 += ((img.at<uchar>(y, x+1) - img.ar<uchar>(y, x)) * (img.at<uchar>(y, x+1) - img.ar<uchar>(y, x)));
		}
	}

//S0-1 = 3
	for (y = 4; y <= 6; y++) {
		for (x = 2; x <= 4; x++) {
			S0_1 += ((img.ar<uchar>(y, x-1) - img.at<uchar>(y, x)) * (img.ar<uchar>(y, x-1) - img.at<uchar>(y, x)));
		}
	}

//S10
	for (y = 4; y <= 6; y++) {
		for (x = 2; x <= 4; x++) {
			S10 += ((img.ar<uchar>(y+1, x) - img.at<uchar>(y, x)) * (img.ar<uchar>(y+1, x) - img.at<uchar>(y, x)));
		}
	}

//S-10
	for (y = 4; y <= 6; y++) {
		for (x = 2; x <= 4; x++) {
			S10 += ((img.ar<uchar>(y-1, x) - img.at<uchar>(y, x)) * (img.ar<uchar>(y-1, x) - img.at<uchar>(y, x)));
		}
	}

	C = min(S01, S0_1, S10, S_10);

	


}
