#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
  char str1[10] = {'c','o','t','\0'};
  char str2[] = "abri";

  printf("(%s):(%s)\n",str1,str2);
  printf("(%c):(%c)\n",str1[1],str2[1]);
  printf("(%zd):(%zd)\n",strlen(str1),strlen(str2));
  printf("(%s)\n",strcat(str2,str1));

  return EXIT_SUCCESS;
}
