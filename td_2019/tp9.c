/*
 * TP9  : Struct et Typedef
 * Sec  : Exercices sur les dates
 * Date : 29_5_2019
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ANNEEMIN 1582
//#define MAXALPHA 10

typedef struct {
  int jour,mois,annee;
  char *nomDuMois;
} Date;

typedef struct{
  char *nom;
  int  maxJours;
}mois;

mois lesMois[]={ {"janvier",31},{"fevrier",28},{"mars",31},
		 {"avril",30},{"mai",31},{"juin",30},
		 {"juillet",31},{"aout",31},{"septembre",30},
		 {"octobre",31},{"novembre",30},{"decembre",31} };


/*
 * revoie 1 si l'annee est bissextile,et revoie 0 sinon
 */
int bissextile(int a){
  return (a%4==0 && a%100!=0) || a%400==0;
}


/* 
 * Antecedent : 1<=d.mois <= 12
 * Role : revoie le nb de jours max du mois de la date d 
 */
int maxJourDanMois(const Date d){
  if(d.mois==2) return bissextile(d.annee) ? 29 :28;
  //cas general
  return lesMois[d.mois-1].maxJours;
}


/* Role : teste le le nom du mois corrrespond au numero du mois
 *        dans la date d
 */
int nomDuMoisValide(const Date d){
  //d.mois et d.nomDuMois
  return strcmp(d.nomDuMois, lesMois[d.mois-1].nom)==0;
}


/*
 *Role : revoie 1 si la date d est valide et 0 sinon
 */
int DateValide(const Date d){
  if(d.annee<ANNEEMIN) return 0;
  // l'annee est valide
  if(d.mois<1 || d.mois>12) return 0;
  // l'annee et le mois sont valides
  if(d.jour<1 || d.jour>maxJourDanMois(d)) return 0;
  // l'annee, le mois et le jour sont valides
  return nomDuMoisValide(d);
}


int main(void){
  Date d1 = { 120, 4, 2017, "avril"};
  Date d2 = { 29, 2, 2017, "fevrier"};

  printf("%d\n",DateValide(d1));
  printf("%d\n",DateValide(d2));
  
  
}
