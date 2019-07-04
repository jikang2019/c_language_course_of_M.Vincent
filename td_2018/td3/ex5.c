#include<stdio.h>
#include<stdlib.h>

int main(void){
  double a,b,c;
  double mid;
  scanf("%lf %lf %lf",&a,&b,&c);

  if(a>b){
    mid=a;
    a=b;
    b=mid;
      }
  if(a>c){
    mid=a;
    a=c;
    c=mid;
  }
  if(b>c){
    mid=b;
    b=c;
    c=mid;
  }
  printf("%lf %lf %lf\n",a,b,c);

  return 0;
}
