#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//#define M 5
#define N 10
//INI_MIN  INI_MAX

void identite(int mat[N][N]){
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(i==j)
	mat[i][j]=1;
      else mat[i][j]=0;
}

void ecrireMatrice(int mat[N][N]){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      printf("%d ",mat[i][j]);
    printf("\n");
  }

}

void iniRandom(int t[N][N]){
  srand(time(NULL));//时间随机time.h
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      t[i][j]=rand()%100;

}

int  minMat(int mat[N][N]){
  int min=mat[0][0];
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(mat[i][j]<min)
	min=mat[i][j];
  return min;
}

int main(void){
  int mat[N][N];
  int minimum;
  identite(mat);
  ecrireMatrice(mat);
  iniRandom(mat);
  printf("\n");
  ecrireMatrice(mat);
  minimum=minMat(mat);
  printf("%d\n",minimum);

  return EXIT_SUCCESS;
}
 
