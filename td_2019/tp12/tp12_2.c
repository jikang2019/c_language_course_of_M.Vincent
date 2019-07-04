/*
 * Ce programme copie un ficher argv[1]
 * dans un second fichier argv[2]
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error(){
  fprintf(stderr,"Usage: copie f1 f2\n");
  exit(EXIT_FAILURE);
}

void copie(const char *f1,const char *f2){
  FILE *in, *out;
  if((in=fopen(f1,"r"))==NULL){
    perror(f1);
    exit(errno);
  }
  if((out=fopen(f2,"w"))==NULL){
    perror(f2);
    exit(errno);
  }
  // copier f1 dans f2
  char buf[BUFSIZ];
  int n;
  while((n=fread(buf, 1, BUFSIZ, in))>0)
    fwrite(buf, 1, n, out);
  //
  fclose(in);fclose(out);
}

  
int main(int argc,char *argv[]){
  if(argc!=3) error();
  //nombre de parametres programme OK
  copie(argv[1],argv[2]);
  
  return EXIT_SUCCESS;
}

/*
  int c;
  while((c=fgetc(in)) != EOF)
    fputc(c,out);
*/
