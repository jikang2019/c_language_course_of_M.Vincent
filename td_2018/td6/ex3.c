#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define M 20

//计算 1/i 的和
double somme(int n){
  double sum=0;
  for(int i=1;i<=n;i++)
    sum=sum+(1.0/i);
  
  return sum;
}

//打印在[a,b]范围中 i×i×i/2的值
void printFct(int a,int b){
  for(int i=a;i<=b;i++)
    printf("%lf ",i*i*i/2.0);
  printf("\n");

}

//数组初始化
/*
void initTab(int t[N],int n){
  for(int i=0;i<N;i++)
    t[i]=rand()%100;
  
}
*/
void initTab(int t[],int n){
  srand(time(NULL));//时间随机time.h
  for(int i=0;i<n;i++)
    t[i]=rand()%100;

}
//数组打印
void printTab(int t[N],int n){
  for(int i=0;i<n;i++)
    printf("%-4d",t[i]);
  printf("\n");
}


int main(void){
  int n;
  scanf("%d",&n);
  printf("%lf\n",somme(n));

  int tab1[N];
  int tab2[M];
  initTab(tab1,N);
  initTab(tab2,M);
 
  
  printTab(tab1,N);
  printf("----------------------------------------------------\n");
  printTab(tab2,M);
  
  return EXIT_SUCCESS;
}
