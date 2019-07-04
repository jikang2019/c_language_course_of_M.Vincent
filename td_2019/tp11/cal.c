#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "pile.h"
#include "cal.h"

int estUnEntier(const char *s){
  if(*s=='\0') return 0;
  // s n'est pa vide
  while(*s){
    if(!isdigit(*s)) return 0;
    s++;
  }
  return 1;
}

int estUnOperateur(const char *s){
  return (*s=='+'||*s=='-'||*s=='/'||*s=='X')
    && *(s+1)=='\0';
}

T cal(T D,T G,char op){
  switch(op){
  case '+' : return G + D; 
  case '-' : return G - D; 
  case 'X' : return G * D; 
  case '/' :
    if (D==0) {
      fprintf(stderr,"erreur : division par zero\n");
      exit(EXIT_FAILURE);
    }
    else return G / D;
  }
  fprintf(stderr,"erreur : item inconnu\n");
  exit(EXIT_FAILURE);
}

