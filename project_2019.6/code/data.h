#pragma once

#define ZoneAffichSIZE 100
#define M 9
#define N 9
#define LARGE 50
#define LONG 50

// struct de LIST
typedef struct noeud{
  int valeur,x,y;
  struct noeud *suivant;
}List;

typedef struct{
  List *first;
  List *last;
}LISTE_CIR;

// struct de sudoku
typedef struct grille{
  Widget ZoneAffich; // zone d'affichage
  char *valeur;      // le valeur de grille
  enum{constant, variable}  nature;       // Si la valeur peut être changée
  int x,y;           // Coordonnées de la grille
} ValeurSudoku;


extern void initSudoku(void *,char *);
extern int grilleValide(ValeurSudoku *,char *);
extern int valeurValide(ValeurSudoku *, char *, int , int );
extern void initValeur(void *);
extern void solution(void *);
