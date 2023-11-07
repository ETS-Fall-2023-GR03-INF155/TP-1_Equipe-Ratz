/*******************************************************************************/
/*  NIM.H                                                                      */
/*  Ce module contient les fonctions necéssaires à l'implémantation du jeu NIM */
/*******************************************************************************/
#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_

#include "codage_numerique.h"
#include "m_distributions.h"

#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau
#define PLATEAU_MAX_PIECES 35		//Nombre maximal de pièces par colonne
#define TRUE   1
#define FALSE  0

/*******************************************************************************/
/*                   DÉCLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

/*PARTIE 1:*/
/*Fonction B*/ void plateau_init(int plateau[], int nb_colonnes); // <-- fonction publique.
/*Fonction D*/ int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);  // <-- fonction publique.
/*Fonction F*/ int plateau_defragmenter(int plateau[], int nb_colonnes); // <-- fonction publique.
/*Fonction G*/ void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces);  // <-- fonction publique.
/*Fonction H*/ void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces);  // <-- fonction publique.
#endif