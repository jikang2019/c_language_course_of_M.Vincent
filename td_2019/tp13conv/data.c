/*
 * Author: Vincent.GRANET "vg@unice.fr"
 * Last file update: 20-Apr-2016 13:05
*/

#include <stdlib.h>
#include <stdio.h>
#include "data.h"

/* Rôle : initialise à 0 la valeur courante. 
 *        ??? Initialisation du taux de change
 */
void initValeurCourante(ValeurCourante *d) {
  d->tauxDeChange = 0.145;
}

void setZoneAffich(ValeurCourante *d, Widget w) {
    d->ZoneAffich = w;
}

/*
 * Rôle : affecte la valeur réelle n à la valeur courante
 */
void setValeur(ValeurCourante *d, double n) {
  d->valeur=n;
}

void setTauxDeChange(ValeurCourante *d, double tc) {
  d->tauxDeChange=tc;
}

/*
 * Rôle : renvoie la valeur courante
 */
double getValeur(ValeurCourante *d) {
  return d->valeur;
}

void convertirEnYuans(ValeurCourante *d) {
  /* la valeur courante est en euros =>
   * la convertir en yuans. 
   */
  d->valeur =  d->valeur * d->tauxDeChange;
}

void convertirEnEuros(ValeurCourante *d) {
  /* la valeur courante est en yuans =>
   * la convertir en euros. 
   */
  d->valeur =  d->valeur / d->tauxDeChange;
}
