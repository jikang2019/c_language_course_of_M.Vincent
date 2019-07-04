#include <stdio.h>
#include <stdlib.h>

#include "pile.h"
#include "cal.h"

int main(int argc, char *argv[]){
  Pile p = PileVide;
  
  for (int i=1; i<argc; i++){
    //argv[i] operande
    if (estUnEntier(argv[i])){
      empiler(&p, atoi(argv[i]));
    }
    else
      if(estUnOperateur(argv[i])){
	T opD,opG;
	opD = sommet(p);depiler(&p);
	opG = sommet(p);depiler(&p);
	//
	empiler(&p,cal(opD,opG,*argv[i]));
      }
      else{
	fprintf(stderr,"erreur : item inconnu\n");
	exit(EXIT_FAILURE);//exit_failure
      }
  }
  //on a evalue l'expression
  printf("res = %d\n",sommet(p));
  
  return EXIT_SUCCESS;
}






/*switch(*argv[i]){
  case '+' : empiler(&p,opG + opD);break;
  case '-' : empiler(&p,opG - opD);break;
  case 'X' : empiler(&p,opG * opD);break;
  case '/' : empiler(&p,opG / opD);break;
  }
*/
