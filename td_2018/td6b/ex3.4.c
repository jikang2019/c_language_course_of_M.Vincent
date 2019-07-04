//杨辉三角

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>
//#define N 10
//#define M 100

void triangleDePascal(int n,int tp[][n+1]){
  assert(n>=1);
  tp[0][0]=1;
  for(int i=1;i<=n;i++){
    tp[i][0]=tp[i][i]=1;
      for(int j=1;j<i;j++)
	tp[i][j]=tp[i-1][j-1]+tp[i-1][j];
  }
}

void printTriangleDePascal(int n,int tp[][n+1]){
  for(int i=0;i<=n;i++){
    for(int j=0;j<=i;j++){
      printf("%4d",tp[i][j]);
      //     sleep(1);
    }
    printf("\n");
  }
}
int main(void){
  int n;
   scanf("%d",&n);
  int tp[n+1][n+1];
  triangleDePascal(n,tp);
  printTriangleDePascal(n,tp);

  return EXIT_SUCCESS;
}
