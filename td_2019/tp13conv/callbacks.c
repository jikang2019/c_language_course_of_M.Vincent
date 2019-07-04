/*
 * Author: Vincent.GRANET "vg@unice.fr"
 * Last file update: 20-Apr-2016 13:03
*/

#include <stdlib.h>
#include <stdio.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"

/* Callback bouton quit. 
 * Rôle : terminer l'application 
 */
void quit(Widget w, void *data) {
  exit(EXIT_SUCCESS);
}

/* Rôle : affiche la valeur courante réelle de d
 *        dans la zone d'affichage
 */ 
static void afficher(ValeurCourante *d) {
  char *s = malloc(ZoneAffichSIZE+1);
  sprintf(s,"%-f", getValeur(d));
  SetStringEntry(d->ZoneAffich,s);
  free(s);
}

/* Callback bouton yuans. 
 * Rôle : remplace la valeur de la zone d'affichage 
 *        par sa valeur convertie en yuans
 *        
 */
void yuans(Widget w, void *data) {
  ValeurCourante *d = data;
  setValeur(d, strtod(GetStringEntry(d->ZoneAffich), NULL));
  convertirEnEuros(d);
  afficher(d);
}

/* Callback bouton euros. 
 * Rôle : remplace la valeur de la zone d'affichage 
 *        par sa valeur convertie en euros
 *        
 */
void euros(Widget w, void *data) {
  ValeurCourante *d = data;
  setValeur(d, strtod(GetStringEntry(d->ZoneAffich), NULL));
  convertirEnYuans(d);
  afficher(d);
}

static void annuler(Widget w, void *data) {
  CloseWindow(); 
}

static Widget entree;

static void valider(Widget w, void *d) {
  setTauxDeChange((ValeurCourante *) d,strtod(GetStringEntry(entree), NULL));
  CloseWindow(); 
}

void tauxchange(Widget w, void *data) {
  MakeWindow("Taux de Change", SAME_DISPLAY, EXCLUSIVE_WINDOW);
  entree = MakeStringEntry(NULL, 120, NULL, data); 
  Widget BAnnuler = MakeButton("Annuler", annuler, NULL);
  Widget BValider = MakeButton("valider", valider, data);
  SetWidgetPos(BAnnuler, PLACE_UNDER, entree,  NO_CARE, NULL);
  SetWidgetPos(BValider, PLACE_RIGHT , BAnnuler, PLACE_UNDER, entree); 
  ShowDisplay();
}
