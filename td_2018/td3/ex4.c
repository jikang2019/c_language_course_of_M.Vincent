#include<stdio.h>
#include<stdlib.h>

int main(void){
  int num;
  scanf("%d",&num);
  if(num>0)
    printf("positif");
  else if(num<0)
    printf("negatif");
  else printf("zero");
  printf("\n");
 
  if(num%2)
    printf("impair\n");
  else printf("pair\n");

  return EXIT_SUCCESS;
}
