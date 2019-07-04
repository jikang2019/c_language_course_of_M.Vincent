/*
 * TP10a : Pointeurs
 * Sec   : 4_Argv/argc
 * Date  : 31_5_2019
 */
#include<stdio.h>
#include<stdlib.h>

#define USAGE "Usage: calc int op int"

void error(){
  fprintf(stderr, "%s\n",USAGE);
  exit(EXIT_FAILURE);
}

int estUnEntier(const char *s){
  while(*s){
    if(*s > '9' || *s < '0')
      return 0;
    s++;
      }
  return 1;
}

int estUnOperateur(const char *s){
  while(*s){
    if(*s!='+' && *s!='-' && *s!='X'&& *s!='/')
      return 0;
    s++;
      }
  return 1;
}

int main(int argc, char *argv[]){
  // 1 : verifier argc
  if (argc!=4) error();
  // 2 : verifier que les operandes
  if(!estUnEntier(argv[1])||!estUnEntier(argv[3]))
    error();
  // 3 : verifier l'operateur
  if(!estUnOperateur(argv[2])) error();
  // 4 : OK tout est bon
  char op = *argv[2];
  int opG = atoi(argv[1]);
  int opD = atoi(argv[3]);
  int res;
  switch(op){
  case '+' : res = opG+opD; break;
  case '-' : res = opG-opD; break;
  case 'X' : res = opG*opD; break;
  case '/' : if(opD==0) error(); res = opG/opD; break;
  }
  //afincher le resulat
  printf("%d\n",res);

  return EXIT_SUCCESS;
}
