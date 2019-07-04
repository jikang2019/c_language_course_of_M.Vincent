#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

int main(void){
  double a,b,c,dalt;
  double r1,r2,i1,i2;
  scanf("%lf%lf%lf",&a,&b,&c);

  assert(a!=0);
  
  dalt=b*b-4*a*c;

  if(dalt>=0){
    if(b<0){
    r1=(-b+sqrt(dalt))/(2*a);
    r2=c/(a*r1);
    }
    else{
    r2=(-b-sqrt(dalt))/(2*a);
    r1=c/(a*r2);
    i1=i2=0;
    }
    
  }
  if(dalt<0){
    r1=r2=(-b)/(2*a);
    i1=sqrt(-dalt)/(2*a);
    i2=-i1;
  }
  printf("rac1 = (%f,%f) ,rac2 = (%f,%f)\n",r1,i1,r2,i2);
  return EXIT_SUCCESS;
    
}
