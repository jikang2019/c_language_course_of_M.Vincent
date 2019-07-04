/*
 * TP8  : CPP
 * Sec  : 7-11
 * Date : 28_5_1019
 */

#include<stdio.h>
#include<stdlib.h>

#define MAX2(x,y) (x)>(y)?(x):(y)
//#define MAX3(x,y,z) ((x)>(y)?(x):(y))>z?((x)>(y) ? (x):(y)):z
#define MAX3(x,y,z) MAX2((x),MAX2((y),(z)))

int max2(int x,int y){
  return x>y?x:y;
}

int max3(int x,int y,int z){
  //int maxnum;
  //maxnum=x>y?x:y;
  //return maxnum>z ? maxnum:z;
  return max2(max2(x,y),z);
}

int main(void){
 
  int a=3,b=2,c=18;
  printf("max= %d\n",max2(a,b));
  printf("MAX= %d\n",MAX2(a,b));
  //printf("max= %d\n",max2(++a,b)); max=4
  //printf("MAX= %d\n",MAX2(++a,b));MAX=5  is  (++a)>(b)?(++a):(b)
  printf("max= %d\n",max3(a,b,c));
  printf("MAX= %d\n",MAX3(a,b,c));
  
  return EXIT_SUCCESS;
}
