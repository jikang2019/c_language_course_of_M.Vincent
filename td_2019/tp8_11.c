/*
 *To test conditional compliation
 */

#include<stdio.h>
#include<stdlib.h>
#include"param.h"

//#define SIZE 2048
#if SIZE<1024
    #error SIZE should be >=1024
#else
double tab[SIZE];
#endif

int main(void){
#ifdef DEBUG
  printf("size= %d\n",SIZE);
#endif

  return EXIT_SUCCESS;
}
