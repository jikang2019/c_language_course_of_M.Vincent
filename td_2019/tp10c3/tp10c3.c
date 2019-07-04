#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabdyn.h"


int *newInt(int n){
  int *p = malloc(sizeof(int));
  *p = n;
  return p;
}

char *newString(char *s){
  /*char *p = malloc(sizeof(*s));
  *p = *s;
  return p; */
  return strdup(s);
}

int main(void){
  TabDyn  t = newTabDyn(10);

  set(&t, 2, newInt(16));
  printf("%d\n",*((int *)get(t,2)) );

  set(&t, 4, newString("toto"));
  printf("%s\n",((char *)get(t,4)) );
  
  return EXIT_SUCCESS;
}
