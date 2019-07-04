#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>

#include"pile.h"
#include"cal.h"

const Pile PileVide = NULL;

// Role : Si p est vile, revoie 1
int estVide(Pile p){
  return p==PileVide;
}
// Role : Revoie le elt de p
T sommet(Pile p){
  assert(!estVide(p));
  return p->elt;
}
// Role : Change le p, p poiteur new pile
void empiler(Pile *p, T x){
  struct noeud *q = malloc(sizeof(struct noeud));
  q->elt=x;
  q->next=*p;
  *p=q;
}
// Role : Change le valaur de p,p poiteur sur next pile
void depiler(Pile *p){
  assert(!estVide(*p));
  struct noeud *q = *p; // q pour free le memoie
  *p = (*p)->next;
  free(q);
}

