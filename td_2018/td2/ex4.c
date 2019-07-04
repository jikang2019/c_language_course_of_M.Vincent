#include<stdio.h>
#include<stdlib.h>

int main(void){
  enum booleen {FAUX,VRAI};
  enum booleen a;
  enum booleen b;
  a=VRAI;
  b=FAUX;
  printf("a=%d\n",a);
  printf("b=%s\n",b?"vrai":"faux");

  return EXIT_SUCCESS;
  
}
