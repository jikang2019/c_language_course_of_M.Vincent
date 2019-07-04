/*
 * Author: Vincent.GRANET "vg@unice.fr"
 * Last file update: 20-Apr-2016 13:04
*/
#ifndef _DATAH
#define _DATAH

#include  <libsx.h>

#define ZoneAffichSIZE 19  /* taille de la zone d'affichage  */
/*
 *  Définition du type ValeurCourante qui représente la valeur
 *  courante de la zone d'affichage, avec le taux de change
*/
typedef struct {
  Widget ZoneAffich; /* widget d'affichage du nombre courant */
  double tauxDeChange;
  double valeur;
} ValeurCourante;

extern void initValeurCourante(ValeurCourante *);
extern void setValeur(ValeurCourante *d, double n);
extern double getValeur(ValeurCourante *d);
extern void convertirEnYuans(ValeurCourante *d);
extern void convertirEnEuros(ValeurCourante *d);
extern void setTauxDeChange(ValeurCourante *d, double tc);
extern void setZoneAffich(ValeurCourante *d, Widget w);
#endif
