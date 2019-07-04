/**
 *  ******** Jeu de sudoku********
 *
 *   @author Wangjikang 16029110064
 *           Majiayu    17029110076
 *
 *  Creation @date: 2019/1/5
 */


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*Jeu de sudoku*/


/*Role:Déterminer si le jeu de Sudoku est terminé*/
int fin(int jeuDeSudoku[][9]){
  //Si chaque position n'est pas zero,Retour 1.sinon retour 0;
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      if(jeuDeSudoku[i][j]==0)
	return 0;
  return 1;
}

/*Role:Imprimer une matrice de sudoku*/
void printSudoku(int jeuDeSudoku[][9]){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      //Si c'est zéro,Imprimer ".",Sinon imprimer les chiffres
      if(jeuDeSudoku[i][j])
	printf("%2d",jeuDeSudoku[i][j]);
      else printf(" .");
    }
    //Après avoir imprimé chaque ligne, envelopper
    printf("\n");
  }
}

/*Role:Déterminer si la réponse est correcte*/
void valide(int jeuDeSudoku[][9],int x,int y,int chiffre){
  int rangee,colonne;
  
  //Déterminer si le chiffre est compris entre 1 et 9
  if(chiffre<1||chiffre>9){
    printf("Mauvais numéro\n");
    return;
  }

  //Juger qu'il n'est pas rempli
  if(jeuDeSudoku[x][y]!=0){
    printf("placemen invalide\n");
    return;
  }

  //Déterminez le nombre dans la colonne.
  for(int i=0;i<9;i++)
    if(jeuDeSudoku[i][y]==chiffre){
      printf("placemen invalide\n");
      return;
  }

  //Déterminer le numéro de la rangee.
  for(int j=0;j<9;j++)
    if(jeuDeSudoku[x][j]==chiffre){
      printf("placemen invalide\n");
      return;
  }

  //rangee et colonne est Grille initiale des grands carrés.
  rangee=(x/3)*3;
  colonne=(y/3)*3;
  //Détermine le nombre du grand carré
  //les invariants de boucle est rangee+3 et colonne+3
  for(int i=rangee;i<rangee+3;i++)
    for(int j=colonne;j<colonne+3;j++)
      if(jeuDeSudoku[i][j]==chiffre){
	printf("placemen invalide\n");
	return;
      }
  
  jeuDeSudoku[x][y]=chiffre;     
}

/*Fonction principale*/
int main(){
  int jeuDeSudoku[9][9]={{7,0,0,0,5,8,1,0,0},
			 {0,0,2,3,0,0,0,8,0},
			 {0},
			 {0,1,0,2,0,0,0,0,6},
			 {0,0,0,0,0,0,4,9,1},
			 {5,0,6,9,0,4,0,0,0},
			 {6,0,0,1,0,7,0,0,9},
			 {8,7,0,0,0,0,0,0,2},
			 {0,0,0,0,6,0,0,0,0}};
  int x,y,chiffre;

  //Imprimer Sudoku jeu
  printSudoku(jeuDeSudoku);

  //Commencer le jeu
  while(!fin(jeuDeSudoku)){
    scanf("%d,%d:%d",&x,&y,&chiffre);
    valide(jeuDeSudoku,x-1,y-1,chiffre);
    printSudoku(jeuDeSudoku);
  }

  //Fin du jeu, sortie "Bravo, sudolu resolu!"
  printf("Bravo, sudolu resolu!"); 

  return EXIT_SUCCESS;

}
