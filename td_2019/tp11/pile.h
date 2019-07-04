#pragma once

typedef int T;

typedef struct noeud{
  T elt;
  struct noeud *next;
} * Pile;

extern const Pile PileVide;
extern int estVide(Pile);
extern T sommet(Pile);
extern void empiler(Pile*, T);
extern void depiler(Pile*);
