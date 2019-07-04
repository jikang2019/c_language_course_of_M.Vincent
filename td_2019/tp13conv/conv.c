/*
  Author: Vincent.GRANET "vg@unice.fr"
  Last file update: 20-Apr-2016 13:03
*/

#include <stdio.h>
#include <stdlib.h>
#include <libsx.h>
#include "data.h"
#include "callbacks.h"

#define TAILLEZONEAFFICHAGE 260

/* Rôle: création et assemblage des widgets */
void init_display(int argc, char *argv[], void *d)
{
  ValeurCourante * vc = d;

  Widget 
    BQuit,      /* le  bouton Quit pour terminer le programme      */
    BYuans,    /* le  bouton BFrancs pour la conversion en yuans */
    BEuros,     /* le  bouton BEuros pour la conversion en euros   */
    BTaux,
    ZoneAffich; /* la zone d'affichage */

  /* Création de la zone d'affichage */
  ZoneAffich = MakeStringEntry(NULL, TAILLEZONEAFFICHAGE, NULL, d); 
  setZoneAffich(vc, ZoneAffich);
  /* Création des boutons  Quit, BYuans, BEuros */
  BQuit  = MakeButton("Quit", quit, NULL);
  BYuans = MakeButton("Yuans", yuans, d);
  BEuros = MakeButton("Euros", euros, d);
  BTaux = MakeButton("Taux de change", tauxchange, d);

  /* Placement des boutons dans la fenêtre graphique */
  SetWidgetPos(BQuit, PLACE_UNDER, ZoneAffich,   NO_CARE, NULL);
  SetWidgetPos(BYuans, PLACE_RIGHT, BQuit, PLACE_UNDER, ZoneAffich);
  SetWidgetPos(BEuros, PLACE_RIGHT, BYuans, PLACE_UNDER, ZoneAffich);
  SetWidgetPos(BTaux, PLACE_RIGHT, BEuros, PLACE_UNDER, ZoneAffich);

  /* pour gérer les couleurs */
  GetStandardColors();
  /* pour afficher l'interface */
  ShowDisplay();
}

int main(int argc, char *argv[]) {
    ValeurCourante d;

    if (OpenDisplay(argc, argv) == 0) {
      fprintf(stderr,"Can't open display\n");
      return EXIT_FAILURE;
    }

    initValeurCourante(&d);
    init_display(argc, argv, &d);
    MainLoop();

    return EXIT_SUCCESS;
}

