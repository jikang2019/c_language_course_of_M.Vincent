#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sudoku.h"
#include "libsx.h"
#include "data.h"
#include "callback.h"

/* Callback bouton quit
 * Rôle : terminer l'application
 */
void quit(Widget w, void *data){
  ValeurSudoku *d = data;

  // free d.valeur
  for(int i=0; i<M; i++)  // M est le nombre de lignes dans le sudoku  
    for(int j=0; j<N; j++){  // N le nombre de colonnes dans le sudoku
      free(d[i*N+j].valeur);
    }
  //terminer l'application
  exit(EXIT_SUCCESS);
}

/* Rôle : Fermer la fenêtre en cours */
static void closewindow(Widget w,void *data){
  CloseWindow();
}

/* Rôle : Fenêtre pop-up, Afficher le résultat de la vérification*/
static void affichValideWindow(int nombre){
  Widget
    BRetour,    // le bouton Retour pour fermer la fenêtre en cours
    TXTaffich;  // le TextWidget TXTaffich pour afficher le texte de l'invite
  // Obtenir la police
  XFont font = GetFont("10*20"); 

  // nombre == 0 est il'y a pas d'erreur
  if(nombre==0){
    MakeWindow("Bon!",SAME_DISPLAY, EXCLUSIVE_WINDOW);
    TXTaffich = MakeTextWidget("C'est vrai !",FALSE,FALSE,250,30);
  }
  // nombre > 0 est il'y a des erreurs
  else{
    MakeWindow("Erreur",SAME_DISPLAY, EXCLUSIVE_WINDOW);
    TXTaffich = MakeTextWidget("Erreur : valeur invalide",FALSE,FALSE,250,30);
  }
  // Définir la police de TXTaffich
  SetWidgetFont(TXTaffich,font);
  // Créartion et assenblage des Button
  BRetour = MakeButton(" \n            Retour           \n ", closewindow, NULL);
  SetWidgetPos(BRetour,PLACE_UNDER,TXTaffich,NO_CARE,NULL);

  ShowDisplay();
  MainLoop();
}

/* Callback bouton Reveler
 * Rôle : révéler la solution du sudoku
 */
void reveler(Widget w, void *data){
  ValeurSudoku *d = data;
  // Définir un tableau de la solution
  ValeurSudoku dsol[M][N];
  Widget BClose;   // le bouton Close pour fermer la fenêtre

  // Copiez la question dans dsol[][]
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
      dsol[i][j].valeur = calloc(ZoneAffichSIZE+1,1);
      strcpy(dsol[i][j].valeur,d[i*N+j].valeur);
      dsol[i][j].nature = d[i*N+j].nature;
    }
  // Calculer la solution
  solution(dsol);

  // Création et assenblage des window et widgets du solution
  MakeWindow("***SOLUTION DE SUDOKU***",SAME_DISPLAY, EXCLUSIVE_WINDOW);
  XFont font = GetFont("12*24");
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
      dsol[i][j].ZoneAffich = MakeTextWidget(NULL, FALSE, FALSE, LARGE, LONG);
      SetWidgetFont(dsol[i][j].ZoneAffich,font);
      if(i>0 && j==0)
	SetWidgetPos(dsol[i][j].ZoneAffich, PLACE_UNDER,dsol[i-1][j].ZoneAffich,NO_CARE,NULL);
      if(i==0 && j>0)
	SetWidgetPos(dsol[i][j].ZoneAffich, PLACE_RIGHT,dsol[i][j-1].ZoneAffich,NO_CARE,NULL);
      if(i>0 && j>0)
	SetWidgetPos(dsol[i][j].ZoneAffich, PLACE_RIGHT,dsol[i][j-1].ZoneAffich,PLACE_UNDER,dsol[i-1][j].ZoneAffich);
    }
  BClose = MakeButton(" \nCLOSE\n ",closewindow,NULL);
  SetWidgetPos(BClose,PLACE_UNDER,dsol[8][0].ZoneAffich,NO_CARE,NULL);
  // afficher la solution
  affichSudoku1(dsol);

  // free sol.valeur
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++)
      free(dsol[i][j].valeur);

  ShowDisplay();
  MainLoop();
  // free font
  FreeFont(font);
}


/* Role des fonctions suivante: 
 * Créer deux windows pour sélectionner la difficulté et le mode
 */
/* Le callback du mode 1 */
static void mode1(Widget w,void *data){
  // Fermer la fenêtre précédente
  CloseWindow();
  // Créartion le window et assenblage de la zone d'affichage du mode 1
  makeZoneAffich1(data);
  // Créartion et assenblage des Button du mode 1 ,et showdisplay
  makeDisplay1(data);
  // affichager les valeurs
  affichSudoku1(data);
}
/* Le callback du mode 1 */
static void mode2(Widget w,void *data){
  // Fermer la fenêtre précédente
  CloseWindow();
  // Créartion le window et assenblage de la zone d'affichage du mode 2,
  // et afficher les valeurs
  makeZoneAffich2(data);
  // Créer un fond pour Mode 2
  fondAffich(NULL);
  // Créartion et assenblage des Button du mode 2 ,et showdisplay
  makeDisplay2(data);
}

/* Création et assenblage des window et widgets du Sélection du mode*/
static void chooseMode(void *data){
  ValeurSudoku *d = data;
  Widget
    TXTaffich,   // Zone de texte affichant l'invite
    BMode1,BMode2,BQuit;  // bouton du Mode1 ,Mode2, Quit

  // Obtenir la police de texte affichant l'invite
  XFont font = GetFont("10*20");
  
  // Créartion des zones d'affichage et boutons
  MakeWindow("***MODE DE IMPORTATION***",SAME_DISPLAY, NONEXCLUSIVE_WINDOW);
  TXTaffich = MakeTextWidget("     Selectionner la mode de importation",FALSE,FALSE,470,30);
  BMode1    = MakeButton(" \n   MODE 1: Mode de Clavier   \n ", mode1, d);
  BMode2    = MakeButton(" \n   MODE 2: Mode de Souris   \n ", mode2, d);
  BQuit     = MakeButton(" \n Quit \n ", quit, d);
  // Placement des zones d'affichage et boutons
  SetWidgetFont(TXTaffich,font);
  SetWidgetPos(BMode1,PLACE_UNDER, TXTaffich,NO_CARE,NULL);
  SetWidgetPos(BMode2,PLACE_UNDER, TXTaffich,PLACE_RIGHT,BMode1);
  SetWidgetPos(BQuit,PLACE_UNDER, TXTaffich,PLACE_RIGHT,BMode2);
  
  ShowDisplay();
  // free font
  FreeFont(font);
}


/* Callback bouton NiveauDeDifficile
 * Rôle : Selectionner la difficulte
 */
void niveauDeDifficile(Widget w, void *data){
  ValeurSudoku *d = data;
  // c'eat callback de bouton ,Ce n'est pas la première fois de choisir la difficulté
  int FirstOpen = 0;
  // Créer une fenêtre de difficulté
  difficulte(d,FirstOpen);
}

/* Callback bouton FACILE */
static void facile(Widget w,void *data){
  CloseWindow();
  ValeurSudoku *d = data;

  // Lire le fichier de sudoku
  initSudoku(d, "Facile");
  // Choisissez le mode
  chooseMode(d);
}
/* Callback bouton MOYEN */
static void moyen(Widget w,void *data){
  CloseWindow();
  ValeurSudoku *d = data;

  // Lire le fichier de sudoku
  initSudoku(d, "Moyen");
  // Choisissez le mode
  chooseMode(d);
}
/* Callback bouton DIFFICILE */
static void difficile(Widget w,void *data){
  CloseWindow();
  ValeurSudoku *d = data;

  // Lire le fichier de sudoku
  initSudoku(d, "Difficile");
  // Choisissez le mode
  chooseMode(d);
}
/* Callback bouton EXPERT */
static void expert(Widget w,void *data){
  CloseWindow();
  ValeurSudoku *d = data;

  // Lire le fichier de sudoku
  initSudoku(d, "Expert");
  // Choisissez le mode
  chooseMode(d);

}

/* Rôle : Création et assenblage des window et widgets de Choix de difficulte */
void difficulte(void *data,int FirstOpen){
  // Si ce n'est pas le premier appel,close le precedent window;
  if(!FirstOpen)
    CloseWindow();
  ValeurSudoku *d = data;
  Widget
    TXTaffich,  // Zone de texte affichant l'invite
    BFacile, BMoyen, BDifficile, BExpert,BQuit;

  // Obtenir la police de texte affichant l'invite
  XFont font = GetFont("10*20");

  // Créartion des zones d'affichage et boutons
  MakeWindow("***SUDOKU***",SAME_DISPLAY, NONEXCLUSIVE_WINDOW);
  TXTaffich  = MakeTextWidget("       Selectionner la difficulte",FALSE,FALSE,400,30);
  BFacile    = MakeButton(" \n  FACILE   \n ", facile, d);
  BMoyen     = MakeButton(" \n   MOYEN   \n ", moyen, d);
  BDifficile = MakeButton(" \n DIFFICILE \n ", difficile, d);
  BExpert    = MakeButton(" \n   EXPERT  \n ", expert, d);
  BQuit    = MakeButton(" \n Quit \n ", quit, d);
  
  // Placement des zones d'affichage et boutons
  SetWidgetFont(TXTaffich,font);
  SetWidgetPos(BFacile,PLACE_UNDER, TXTaffich,NO_CARE,NULL);
  SetWidgetPos(BMoyen,PLACE_UNDER, TXTaffich,PLACE_RIGHT,BFacile);
  SetWidgetPos(BDifficile,PLACE_UNDER, TXTaffich,PLACE_RIGHT,BMoyen);
  SetWidgetPos(BExpert,PLACE_UNDER, TXTaffich,PLACE_RIGHT,BDifficile);
  SetWidgetPos(BQuit,PLACE_UNDER, TXTaffich,PLACE_RIGHT,BExpert);
  
  ShowDisplay();
  // free font
  FreeFont(font);
}



/* afficher les valeur du mode 1*/
void affichSudoku1(void *data){
  ValeurSudoku *d = data;
  
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++)
      // '0' est NULL pour le sudoku
      if(d[i*N+j].valeur[0] != '0')
	SetTextWidgetText(d[i*N+j].ZoneAffich, d[i*N+j].valeur,FALSE);
}

/* Callback bouton BVerificationFinale
 * Rôle : vérifier la validité de toutes les grilles
 */
void verifierDeFin(Widget w, void *data){
  ValeurSudoku *d = data;
  char *instr=NULL;  //la valeur de zoneaffich
  int nb=0;  // le nombre des erreurs
  
  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
      if(d[i*N+j].nature == constant)
	continue;
      // La grille actuelle est modifiable

      // Lire la valeur de zoneaffich
      instr = GetTextWidgetText(d[i*N+j].ZoneAffich);
      
      if(valeurValide(d, instr, i, j))
	// string entree est valide
	// Remplissez les chiffres
	strcpy( d[i*N+j].valeur, instr);
      else
	// string entree est invalide
	nb++;
    }
  //Fenêtre affichant les résultats
  affichValideWindow(nb);
}

/* Callback bouton BVerificationIntermediaire
 * Rôle : vérifier la validité de le grille remplie
 */
void verifierDeCours(Widget w, void *data){
  ValeurSudoku *d = data;
  char *instr=NULL;   //la valeur de zoneaffich
  int nb=0;   // le nombre des erreurs

  for(int i=0; i<M; i++)
    for(int j=0; j<N; j++){
      if(d[i*N+j].nature == constant)
	continue;
      // La grille actuelle est modifiable

      // Lire la valeur de zoneaffich
      instr = GetTextWidgetText(d[i*N+j].ZoneAffich);
      
      if(*instr == '\0')
	continue;
      // La fenêtre en cours est remplie
      if(valeurValide(d, instr, i, j))
	// string entree est valide
	strcpy( d[i*N+j].valeur, instr);
      else
	// string entree est invalide
	nb++;
    }
  //Fenêtre affichant les résultats
  affichValideWindow(nb);
}


// le struct de nombre de clavier
typedef struct{
  int nombre;       // nombre du clavier
  ValeurSudoku *d;  // data du sudoku
}Clavier;

/* Role : Tracer des lignes épaisses sur le fond */
void fond(Widget w,int x,int y,void *data){
  SetLineWidth(4);
  DrawLine(165,0,165,498);
  DrawLine(333,0,333,498);
  DrawLine(0,165,498,165);
  DrawLine(0,333,498,333);
}

/* Role : afficher les valeurs du mode2 */
void affichSudoku2(Widget w,int width,int height,void *data){
  ValeurSudoku *d = data;
  // '0' est null pour le sudoku
  if(atoi(d->valeur) !=0)
    DrawText(d->valeur,19,37);
}

// Role : Revois 1 si tous est valide ,sinon revois 0
static int tousValide(void *data){
   ValeurSudoku *d = data;
   
  for(int i=0;i<M*N;i++)
    if(atoi(d[i].valeur) == 0)
       return 0;
  return 1;
}

/* Callback le button de chiffre de clavier
 * Role : Déterminer la validité du chiffre,
 *        et Remplissez le chiffre
 */
static void input(Widget w,void *data){
  // Fermer la fenêtre précédente
  CloseWindow();
  Clavier *button = data;
  char *s = malloc(10);
  int x=(*button).d->x; int y=(*button).d->y;

  // Convertir des nombres en caractères de chaine
  sprintf(s,"%d",button->nombre);

  if(valeurValide((*button).d-x*N-y, s, x, y)){
    // string entree est valide
    strcpy( (*button).d->valeur, s);
    // afficher le valeur
    DrawText(s,19,37);
  }
  else
    // afficher window invalide
    affichValideWindow(1);

  // si il est Fin du jeu
  if(tousValide(button->d))
    affichValideWindow(0);
}

/* Création et assenblage des window et widgets de clavier */
void openClavier(Widget w,int a,int b,int c,void *data){
  ValeurSudoku *d = data;
  int nombre = 1;  // le nombre du clavier
  Clavier button_cla[3][3];
  
  for(int i=0;i<3;i++)  // le nombre de lignes du clavier
    for(int j=0;j<3;j++){  // le nombre de colonnes du clavier
    button_cla[i][j].nombre = nombre++;
    button_cla[i][j].d = d;  // le data du sudoku
  }
  
  XFont font = GetFont("12*24");
  Widget BChoose[3][3];
  MakeWindow("choice le nombre",SAME_DISPLAY,EXCLUSIVE_WINDOW);
  int i,j;

  // Créartion assenblage des Button du clavier
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      char *str = malloc(10);
      
      // Convertir des nombres du clavier en caractères de chaine
      sprintf(str," %d ",button_cla[i][j].nombre);
      BChoose[i][j]=MakeButton(str,input,&button_cla[i][j]);
      // set font du lacvier 
      SetWidgetFont(BChoose[i][j],font);
      free(str);
    }
  }
  // assenblage des Button du clavier
  for(i=0;i<2;i++) {
    for(j=0;j<2;j++){
      SetWidgetPos(BChoose[i][j+1],PLACE_RIGHT,BChoose[i][j],NO_CARE,NULL);
      SetWidgetPos(BChoose[i+1][j],PLACE_UNDER,BChoose[i][j],NO_CARE,NULL);
      SetWidgetPos(BChoose[i+1][j+1],PLACE_RIGHT,BChoose[i+1][j],PLACE_UNDER,BChoose[i][j]);
    }
  }

  // free font 
  FreeFont(font);
  ShowDisplay();
  MainLoop();
}


