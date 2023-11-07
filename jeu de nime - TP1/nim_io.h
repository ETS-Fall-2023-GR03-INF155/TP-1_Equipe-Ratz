#pragma once
#ifndef _test_h_
#define _test_h_

#include "WinConsole.h"
#include "nim.h"

#define FFLUSH while(getchar() != '\n') {}

/*Fonction A*/ int lire_entier(int min, int max);   // <-- fonction publique.
/*Fonction C*/ void plateau_afficher(const int plateau[], int nb_colonnes, int col_select, int humtobot);   // <-- fonction publique.
/*Fonction J*/ void tour_humain(int plateau[], int nb_colonnes);   // <-- fonction publique.
/*Fonction K*/ void tour_ia(int plateau[], int nb_colonnes, int niveau);   // <-- fonction publique.
/*Fonction L*/ void demarrer_jeu(int niveau);   // <-- fonction publique.

#endif