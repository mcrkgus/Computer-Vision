#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

int main() {

  FILE *fp; 
  unsigned char Readbuf[562][750];
  unsigned char Writebuf[562][750];
  
  
  
  //영상 읽기 
  fp = fopen("짱구.raw", "rb");

  for (int i = 0; i < 562; i++)
    fread(Readbuf[i], 1, 750, fp);  
  
  fclose(fp);
  
  
  
  //영상 편집
  for (int i = 0; i < 562; i++)
    for (int j = 0; j < 750; j++)
      Writebuf[i][j] = Readbuf[i][750 - j];
  
  
  
  //영상 저장
  fp = fopen("짱구놀자.raw", "wb");
  
  for (int i = 0; i < 562; i++)
    fwrite(Writebuf[i], 1, 750, fp);
  
  fclose(fp);
  
  
  
  return 0;


}
