/**
 *  ******** Projet C : Sudoku ********
 *
 *   @author Wangjikang  16029110064 (Deux premiers chiffres est 16)
 *           ChenXiangru 17029110056
 *
 *  Creation @date: 2019/6/08
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "sudoku.h"
#include "libsx.h"
#include "data.h"
#include "callback.h"

/*
 * Rôle : Création et assenblage des window et widgets du mode 1
 */
/* Rôle : Créartion et assenblage de la zone d'affichage du mode 1 */
void makeZoneAffich1(void *data){
  // Création des window du Mode 1
  MakeWindow("***SUDOKU***",SAME_DISPLAY, NONEXCLUSIVE_WINDOW);
  ValeurSudoku *d = data;
  // Obtenir la police de la zone d'affichage
  XFont font = GetFont("12*24");
  
  // Créartion et Placement des zones d'affichage dans la fenetre graphique
  for(int i=0; i<M; i++)  // M est le nombre de lignes dans le sudoku  
    for(int j=0; j<N; j++){  // N le nombre de colonnes dans le sudoku
      // Créartion des zones d'affichage
      if(d[i*N+j].nature == constant)
	d[i*N+j].ZoneAffich = MakeTextWidget(NULL, FALSE, FALSE, LARGE, LONG);
      else
	d[i*N+j].ZoneAffich = MakeTextWidget(NULL, FALSE, TRUE, LARGE, LONG);
      // Définir la police de zone d'affichage
      SetWidgetFont(d[i*N+j].ZoneAffich,font);
      
      // Placement des zone d'affichage dans la fenetre graphique
      if(i>0 && j==0)
	SetWidgetPos(d[i*N+j].ZoneAffich, PLACE_UNDER,d[(i-1)*N+j].ZoneAffich,NO_CARE,NULL);
      if(i==0 && j>0)
	SetWidgetPos(d[i*N+j].ZoneAffich, PLACE_RIGHT,d[i*N+j-1].ZoneAffich,NO_CARE,NULL);
      if(i>0 && j>0)
	SetWidgetPos(d[i*N+j].ZoneAffich, PLACE_RIGHT,d[i*N+j-1].ZoneAffich,PLACE_UNDER,d[(i-1)*N+j].ZoneAffich);
    }
}

/* Rôle : Créartion et assenblage des Button du mode 1 */
void makeDisplay1(void *data){
  ValeurSudoku *d = data;
  Widget
    BQuit,                      // le bouton Quit pour teminer le programme
    BReveler,                   // le bouton Reveler pour révéler la solution du sudoku
    BVerificationFinale,        // le bouton VérificationFinal pour vérifier la validité de toutes les grilles
    BVerificationIntermediaire, // le bouton VerificationIntermediaire pour vérifier la validité de le grille remplie
    BNiveauDeDifficile;         // le bouton NiveauDeDifficile pour sélectionner la difficulté

  // Créartion des buttons Quit, Reveler, VerificationFinale, VerificationIntermediaire et NiveauDeDifficile
  BQuit = MakeButton(" \n Quit \n ",quit,d);
  BVerificationFinale = MakeButton(" \n  Verification finale  \n ",verifierDeFin,d); ////////////
  BVerificationIntermediaire = MakeButton(" \n  Verification intermediaire  \n ",verifierDeCours,d);
  BNiveauDeDifficile = MakeButton(" \nSelectionner la difficulte\n ", niveauDeDifficile, d);
  BReveler =  MakeButton(" \nReveler la solution\n ",reveler, d);
  
  // Placement des boutons dans la fenetre graphique
  SetWidgetPos(BVerificationIntermediaire,PLACE_UNDER,d[8*N].ZoneAffich,NO_CARE,NULL);
  SetWidgetPos(BVerificationFinale,PLACE_UNDER,d[8*N].ZoneAffich,PLACE_RIGHT,BVerificationIntermediaire);
  SetWidgetPos(BQuit,PLACE_UNDER,BVerificationIntermediaire,NO_CARE,NULL);
  SetWidgetPos(BNiveauDeDifficile,PLACE_UNDER,BVerificationIntermediaire,PLACE_RIGHT,BQuit);
  SetWidgetPos(BReveler,PLACE_UNDER,BVerificationIntermediaire,PLACE_RIGHT,BNiveauDeDifficile);
  
  // Pour afficher le Window
  ShowDisplay();
  // set color
  for(int i=0; i<M*N ;i++)
    if(d[i].nature == constant)
      SetFgColor(d[i].ZoneAffich, GetRGBColor(0, 0, 254));
}



/*
 * Création et assenblage des window et widgets du mode 2
 */
/* Rôle : Créartion et assenblage de la zone d'affichage du mode 2  */
void makeZoneAffich2(void *data){
  // Création des window du Mode 2
  MakeWindow("***SUDOKU***",SAME_DISPLAY, NONEXCLUSIVE_WINDOW);
  ValeurSudoku *d = data;
  // Obtenir la police
  XFont font = GetFont("12*24");

  // Créartion et Placement des zones d'affichage dans la fenetre graphique
  for(int i=0;i<M;i++)  // M est le nombre de lignes de sudoku  
    for(int j=0;j<N;j++){  // N le nombre de colonnes de sudoku
      // Créartion des zones d'affichage
      d[i*N+j].ZoneAffich = MakeDrawArea(LARGE,LONG,affichSudoku2,&d[i*N+j]);
      // Si le grille n'est pas sujet, définissez-le pour qu'il soit cliqué
      if(d[i*N+j].nature != constant)
	SetButtonDownCB(d[i*N+j].ZoneAffich,openClavier);
      //SetEnterCB(BScreen[i][j],color); //////////////////////////
      // Définir la police de zone d'affichage
      SetWidgetFont(d[i*N+j].ZoneAffich,font);
    }
  
  // Placement des zone d'affichage dans la fenetre graphique
  for(int i=0;i<M-1;i++)
    for(int j=0;j<N-1;j++){
      SetWidgetPos(d[i*N+j+1].ZoneAffich,PLACE_RIGHT,d[i*N+j].ZoneAffich,NO_CARE,NULL);
      SetWidgetPos(d[(i+1)*N+j].ZoneAffich,PLACE_UNDER,d[i*N+j].ZoneAffich,NO_CARE,NULL);
      SetWidgetPos(d[(i+1)*N+j+1].ZoneAffich,PLACE_RIGHT,d[(i+1)*N+j].ZoneAffich,PLACE_UNDER,d[i*N+j].ZoneAffich);
    }
  //free font
  FreeFont(font);
}

/* Rôle : Créer un fond pour Mode 2 */
void fondAffich(void *data){
  MakeDrawArea(498,498,fond,NULL);
}

/* Rôle : Créartion et assenblage des Button du mode 2 */
void makeDisplay2(void *data){
  ValeurSudoku *d = data;
  Widget
    BQuit,               // le bouton Quit pour teminer le programme
    BReveler,            // le bouton Reveler pour révéler la solution du sudoku
    BNiveauDeDifficile;  // le bouton NiveauDeDifficile pour sélectionner la difficulté

  // Créartion des buttons Quit, Reveler et NiveauDeDifficile
  BQuit = MakeButton(" \n Quit \n ",quit,d);
  BNiveauDeDifficile = MakeButton(" \nSelectionner la difficulte\n ", niveauDeDifficile, d);
  BReveler =  MakeButton(" \nReveler la solution\n ",reveler, d);

  // Placement des boutons dans la fenetre graphique
  SetWidgetPos(BQuit,PLACE_UNDER,d[8*N].ZoneAffich,NO_CARE,NULL);
  SetWidgetPos(BNiveauDeDifficile,PLACE_UNDER,d[8*N].ZoneAffich,PLACE_RIGHT,BQuit);
  SetWidgetPos(BReveler,PLACE_UNDER,d[8*N].ZoneAffich,PLACE_RIGHT,BNiveauDeDifficile);
  
  // Pour afficher le Window
  ShowDisplay();
  // set color
  for(int i=0; i<M*N ;i++)
    if(d[i].nature == constant)
      SetFgColor(d[i].ZoneAffich, GetRGBColor(0, 0, 254));
}



/* Rôle : Création et assemblage des widget */
void init_display(int argc, char *argv[], ValeurSudoku d[][N]){
  if (OpenDisplay(argc, argv) == 0) {
    fprintf(stderr,"Can't open display\n");
    exit(EXIT_FAILURE);
  }
  // Open display success
  
  int FirstOpen = 1;  // Première ouverture est 1,sinon 0
  //Créer une Window pour choisir la difficulté
  difficulte(d,FirstOpen);

  // Pour gérer les couleurs
  GetStandardColors();
  // Pour afficher l'interface
  ShowDisplay();
}

int main(int argc, char *argv[]){
  ValeurSudoku d[M][N];
  
  // Allouer de la mémoire pour d.valeur
  initValeur(d);
  init_display(argc, argv, d);
  MainLoop();

  return EXIT_SUCCESS;
}
