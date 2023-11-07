#pragma once
#ifndef _test_h_
#define _test_h_

#define CODAGE_NB_BITS 8

/*Fonction M*/ int inverser_tab_bits(int tab_bits[], int nb_bits);
/*Fonction N*/ int codage_dec2bin(int nombre, int resultat[]);
/*Fonction O*/ void afficher_tab_bits(const int tab_bits[], int nb_bits);
/*Fonction P*/ int codage_bin2dec(const int tab_bits[]);
#endif