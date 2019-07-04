/*
 * TP10c : Pointeurs
 * Sec   : ex1
 * Date  : 3_6_2019
 */
#include<stdio.h>
#include<stdlib.h>

typedef enum { carre, rond, triangle} forme;

forme *creeForme(forme f){
  forme *p = malloc(sizeof(forme));
  *p = f;
  return p;
}

void afficherForme( forme f){
  switch(f){
  case carre :    printf("carre");    break;
  case rond :     printf("rond");     break;
  case triangle : printf("triangle"); break;
  default :       printf("forme inconnue");
  }
}

void afficherLnForme( forme f){
  void afficherForme( f);
  printf("\n");
}

int main(void){
  // 1
  forme *p,*q,*r;
  // 2
  p = creeForme(carre);
  q = creeForme(rond);
  //3
  afficherLnForme(*p);
  afficherLnForme(*q);
  //4
  r = p;
  afficherLnForme(*r);
  //5
  *p = triangle;
  afficherLnForme(*r);
  //6-7
  free(p);
  afficherForme(*r);

  return EXIT_SUCCESS;
}
