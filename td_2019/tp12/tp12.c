#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

void creeFichEntier(char *f,int n){
  FILE *fd;
  if((fd=fopen(f,"w"))==NULL){
    //fprintf(stderr,"erreur\n");
    perror(f);
    exit(errno);
  } 
  srandom(time(NULL));
  for (int i=0;i<n;i++){
    long x = random()%100;
    fwrite(&x, sizeof(long), 1, fd);
  }
  fclose(fd);
}

void afficherFichEntiers(char *f){
  FILE *fd;
  if((fd = fopen(f,"r")) == NULL){
    perror(f);
    exit(errno);
  }
  //
  long x = 0;
  while(fread(&x, sizeof(long), 1,fd)>0)
    printf("%3ld", x);
  //
  printf("\n");
  fclose(fd);
}


void PairsImpairs(char *f, char *fPairs, char *fImpairs){
  FILE *in,*outE,*outO;
  if((in=fopen(f,"r"))==NULL){
    perror(f);
    exit(errno);
  }
    
  if((outE=fopen(fPairs,"w"))==NULL){
    perror(fPairs);
    exit(errno);
  }
  if((outO=fopen(fImpairs,"w"))==NULL){
    perror(fImpairs);
    exit(errno);
  }
  // les fichiers son ouverts
  long x;
  while(fread(&x, sizeof(long), 1,in)>0){
    if((x&1) == 0)
      fwrite(&x, sizeof(long), 1,outE);
    else
      fwrite(&x, sizeof(long), 1,outO);
      }
  // fermer les fichiers
  fclose(in);fclose(outE);fclose(outO);
}

int main(void){
  creeFichEntier("MaSuite",20);
  creeFichEntier("MaSuite2",20);
  afficherFichEntiers("MaSuite");
  
  PairsImpairs("MaSuite","Pairs","Impairs");
  printf("-------------------------pairs\n");
  afficherFichEntiers("Pairs");
  printf("-------------------------impairs\n");
  afficherFichEntiers("Impairs");
  
  return EXIT_SUCCESS;
}

//ls -l MaSuite
