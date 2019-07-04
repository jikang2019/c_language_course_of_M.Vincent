/*
 * TP10a : Pointeurs
 * sec   : 2_Parametres resultats
 *         3_Chaines
 * Date  : 30_5_2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void swap( int* a, int* b){
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

char *Strchr(char *s, const char c){
  while(*s){
    if (c == *s)
      return s;
    s++;
  }
  return NULL;
}

char *Strcpy(char *s1,  char *s2){
  char *p = s1;
  while(*s1++ = *s2++);
  return p;
}

char *Strcat(char *s1, char *s2){
  char *p = s1;
  while(*s1) s1++;
  while(*s1++ = *s2++);
  return p;
}

int Compare(const char *s1, const char *s2){
  while(*s1 == *s2){
    if(*s1 == '\0')
      return 0;
    s1++;s2++;
  }
  //*s1 +/- s2
  return *s1 - *s2;
}

char *metEnMajuscule(char *s){
  char *p = s;
  while(*s){
    //*s = *s-32;
    *s = toupper(*s);
    s++;
  }
  return p;
}
      
int main(void){
  int x = 10, y = 2;
  char s1[10] = "bonjour";
  char s2[] = " a tous";
  char c = 'j';
  swap(&x, &y);
  printf("a= %d,b= %d\n",x,y);

  printf("%c\n",*Strchr(s1, c));
  printf("%d\n",Compare(s1, s2));
  printf("%s\n",metEnMajuscule(s1));
  
  return EXIT_SUCCESS;
	     
}
