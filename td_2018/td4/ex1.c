#include<stdio.h>
#include<stdlib.h>

#define ANNEEMIN 1600

void ecrireDate(int jour,int mois,int annee){
  printf("La date est :%2d ",jour);
   switch(mois){
      case 1:printf("Janvier");break;
      case 2:printf("fevrier");break;
      case 3:printf("mars");break;
      case 4:printf("avril");break;
      case 5:printf("mai");break;
      case 6:printf("juin");break;
      case 7:printf("juillet");break;
      case 8:printf("aout");break;
      case 9:printf("aeptembre");break;
      case 10:printf("octobre");break;
      case 11:printf("novembre");break;
      case 12:printf("decembre");break;
   }
   printf(" %4d annee\n",annee);
   
}

int bissextile(int annee){
  if(annee%100!=0){
    if(annee%4==0)
      return 1;
    else return 0;
  }else{
    if(annee%400==0)
      return 1;
    else return 0;
  }

}

int jourDanMois(int mois,int annee){
  switch(mois){
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:return 31;
  case 4:
  case 6:
  case 9:
  case 11:return 30;
  case 2:return bissextile(annee)?29:28;
  }

}

int valide(int jour,int mois,int annee){
  if(jour>jourDanMois(mois,annee)||jour<1)
    return 0;
  if(mois>12||mois<1)
    return 0;
  if(annee<ANNEEMIN)
    return 0;
  return 1;
}

int main(void){
  int j,m,a;
  scanf("%d %d %d",&j,&m,&a);
  if(!valide(j,m,a)){
    printf("error\n");
    return EXIT_SUCCESS;
  }
    
  ecrireDate(j,m,a);
  if(bissextile(a))
    printf("annee bissextile\n");
  else printf("annee commune\n");
  printf("la jours dans mois est : %d\n",jourDanMois(m,a));
 
  return EXIT_SUCCESS;
}
