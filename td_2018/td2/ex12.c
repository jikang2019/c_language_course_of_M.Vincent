#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
  float s;
  int h,min,second,cent;
  int remainder;
  
  scanf("%f",&s);
  h=(int)s/3600;
  remainder=(int)s%3600;
  min=remainder/60;
  remainder=remainder%60;
  second=remainder;
  
  //s=s-floor(s);
  //cent=s*1000;
  cent=s*100-(int)floor(s)*100;
  //printf("%lf\n",s-floor(s));
  printf("%dh %dmin %ds %dcent\n",h,min,second,cent);

  return EXIT_SUCCESS;
  
}
