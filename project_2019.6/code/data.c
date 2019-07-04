#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "libsx.h"
#include "data.h"

/* Allouer de la mémoire pour d.valeur */
void initValeur(void *data){
  ValeurSudoku *d = data;
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      d[i*N+j].valeur =  calloc(ZoneAffichSIZE+1,1);
}

/* Lire le fichier du projet du sudoku*/
void initSudoku(void *data, char *nomDuFichier){
  ValeurSudoku *d = data;
  FILE *fp;
  char *s = calloc(ZoneAffichSIZE+1,1); //

  if((fp=fopen(nomDuFichier,"r")) == NULL){
    perror(nomDuFichier);
    exit(EXIT_FAILURE);
  }
  // Ouvrir le fichier avec succès
  
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
      
      while(fscanf(fp,"%s",s)>0){
	if(atoi(s)>=0 && atoi(s)<=9)
	  break;
      }
      // s est chiffre 0-9
      strcpy(d[i*N+j].valeur,s);

      // Déterminer si cela peut être changé par l'utilisateur
      if(atoi(s) == 0)
	d[i*N+j].nature = variable;
      else d[i*N+j].nature = constant;

      // Coordonnées de la grille
      d[i*N+j].x = i;
      d[i*N+j].y = j;
    }
  
  // free s, Fermer le fichier
  free(s);
  fclose(fp);
}

/* Role : Controle de validite 
 * 0 est invalide , 1 est valide
 */
int valeurValide(ValeurSudoku *d, char *s, int x, int y){
  if(strlen(s) != 1)
    return 0;
  // string valeur a seul un caractere;
  
  if(strcmp(s, "9") > 0 || strcmp(s, "1") < 0 )
    return 0;
  // valeur est entre 1-9

  for(int i=0; i<9; i++){
    if(i == x) continue;
    if(strcmp(s, d[i*N+y].valeur) == 0)
      return 0;
  }
  // Cette colonne est valide
  
  for(int j=0; j<9; j++){
    if(j == y) continue;
    if(strcmp(s, d[x*N+j].valeur) == 0)
      return 0;
}
  // Cette range est valide
  
  int
    range   = x/3*3,  // le range de Premier petit grille de grande grille
    colonne = y/3*3;  // le colonne de Premier petit grille de grande grille
  for(int i=range; i<range+3; i++)  // le range de dernier petit grille de grande grille
    for(int j=colonne; j<colonne+3; j++){ // le colonne de dernier petit grille de grande grille
      if(i == x && j == y) continue;   // il ne lui compare pas
      // compare 
      if(strcmp(s, d[i*N+j].valeur) == 0)
	return 0;
 }
  // Grande grille est valide

  // Tous est valide
  return 1;
}

/*
 * La fonction suivante est utilisée 
 * pour calculer le résultat de Sudoku
 */

/* Role : Si p est vile, revoie 1 */
static int estVide(LISTE_CIR l){
  return l.first==NULL && l.last==NULL;
}

/* Role : Change le p, p poiteur new pile */
static void empiler(LISTE_CIR *l,int chiffre,int x,int y){
  List *p = malloc(sizeof(struct noeud));
  
  p->valeur = chiffre;
  p->x = x;
  p->y = y;
  
  if(estVide(*l)){
    (*l).first = p;
    (*l).last = p;
    p->suivant = NULL;
  }else{
    p->suivant = (*l).first;
    (*l).first = p;
  }
}

/* Role : Change le p, p poiteur new pile */
static void depile(LISTE_CIR *l){
  assert(!estVide(*l));
  List *p = (*l).first;
  
  (*l).first = (*l).first->suivant;
  if(p == (*l).last)
    (*l).last = NULL;
  
  free(p);
  p = NULL;
}

/* Calculer les solution de Sudoku*/
void solution(void *data){
  ValeurSudoku *d = data;
  LISTE_CIR l = {NULL, NULL};
  
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
      if(d[i*N+j].nature == constant)
	continue;
      // d[i][j].valeur peut être changée
      
      int chiffre = 1;
      empiler(&l,chiffre,i,j);
      strcpy(d[i*N+j].valeur,"0");
      
      // Calculer la réponse au sudoku
	while(TRUE){
	  // Si le valeur > 9, depile 
	  if(l.first->valeur > 9){
	    strcpy(d[i*N+j].valeur,"0");
	    depile(&l);
	    i = l.first->x;
	    j = l.first->y;
	    strcpy(d[i*N+j].valeur,"0");
	  }else{
	    // Si 1< valeur <9
	    char strDeValeur[10];
	    sprintf(strDeValeur,"%d",l.first->valeur);
	    // Si valeur est valide , Attribuer strvaleur à d[i][j].valeur
	    if(valeurValide(d,strDeValeur,i,j)){
	      strcpy(d[i*N+j].valeur,strDeValeur);
	      break;
	    }
	  }
	  // 
	  l.first->valeur++;
	}
    }

  // Supprimer toutes les piles
  while(!estVide(l))
    depile(&l);
}
