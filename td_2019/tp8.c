/*
 * TP8  : CPP
 * Sec  : 4-7
 * Date : 28_5_1019
 */


#include<stdio.h>
#include<stdlib.h>

#ifndef MAX
   #define MAX 100
#endif

//
#define MAX2(x,y) (x)>(y)?(x):(y)

int max2(int x,int y){
  return x>y?x:y;
}

int main(void){
  // printf("%d\n",MAX);
  printf("%s %d\n",__FILE__,MAX);

  printf("(%s) (%s) (%s) (%s) (%d) (%s)\n",__DATE__,__TIME__,__FILE__,__TIMESTAMP__,__LINE__,__func__);

  //
  int a=3,b=2;
  printf("max= %d\n",max2(a,b));
  printf("MAX= %d\n",MAX2(a,b));
  //printf("max= %d\n",max2(++a,b)); max=4
  //printf("MAX= %d\n",MAX2(++a,b));MAX=5  is  (++a)>(b)?(++a):(b)

  return EXIT_SUCCESS;
}
