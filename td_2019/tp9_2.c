/*
 * TP9  : Struct et Typedef
 * Sec  : Exercices sur les complexe
 * Date : 29_5_2019
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define eps 1e-50

typedef struct{
  double reel;
  double img;
}Complexe;

const Complexe I = {0, 1};

//Role : Revoie un complexe (r,i)
Complexe iniComplexe(const double r, const double i){
  Complexe c = {r, i};
  return c;
}

void ecrireComplexe(const Complexe c){
  printf("(%.2f,%.2f)",c.reel,c.img);
}

void ecrireLnComplexe(const Complexe c){
  ecrireComplexe(c);
  printf("\n");
}

//Role : Revoie le reelle de complexe
double partieReelle(const Complexe c){
  return c.reel;
}
//Role : Revoie le imaginaire de complexe
double partiImaginaire(const Complexe c){
  return c.img;
}

// Role : Calcule le module du Complexe
double rho(const Complexe c){
  return sqrt(pow(c.reel,2)+pow(c.img,2));
}

// Role : Calcule l'argument du Complexe
double theta(const Complexe c){
  return atan2(c.img, c.reel);
}

// Role : revoie le complexe de rho et theta
Complexe polComplexe(const double rho, const double theta){
  return iniComplexe(rho * cos(theta), rho * sin(theta));
}

// Role : Calcule a+b et revoie le resultat
Complexe plus(const Complexe a, const Complexe b){
  Complexe sum;
  sum.reel = a.reel + b.reel;
  sum.img = a.img + b.img;
  return sum;
}
// Role : Calcule a-b et revoie le resultat
Complexe moins(const Complexe a, const Complexe b){
  Complexe moin;
  moin.reel = a.reel - b.reel;
  moin.img = a.img - b.img;
  return moin;
}
// Role : Clacule a*b et revoie le resultat
Complexe mult(const Complexe a, const Complexe b){
  return polComplexe(rho(a)*rho(b), theta(a)+theta(b));
}
// Role : Calcule a/b et revoie le resultat
Complexe divi(const Complexe a, const Complexe b){
  return polComplexe(rho(a)/rho(b),theta(a)-theta(b));
}

//
int egal(const Complexe a, const Complexe b){
  return fabs(a.reel - b.reel) < eps && fabs(a.img - b.img) < eps;
}
//
int different(const Complexe a, const Complexe b){
  return fabs(a.reel - b.reel) > eps || fabs(a.img - b.img) > eps;
}

int main(void){

  Complexe c1 = iniComplexe( 12.4, -3);
  Complexe c2 = iniComplexe( 13.4, 6);
  
  ecrireLnComplexe(c1);
  ecrireLnComplexe(c2);
  ecrireLnComplexe(mult(c1,c2));

  printf("module est %f\n",rho(c1));
  printf("argument est %f\n",theta(c1));
  printf("c1=");ecrireLnComplexe( polComplexe(rho(c1),theta(c1)) );
  printf("c1*c2= ");ecrireLnComplexe( mult(c1, c2) );
  
  return EXIT_SUCCESS;
}
