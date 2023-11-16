/************************************************************************************/
/*  Fichier : NIM.H                                                                 */
/*  Auteurs : BOIRET Romain   BOIR71300401		                                    */
/*            LENGA  Amorella LENA91330301                                          */
/*  Date de création : <17 / 10 / 2023>                                             */
/*                                                                                  */
/*  Ce module contient les fonctions necéssaires à l'implémantation du jeu NIM.		*/
/************************************************************************************/
#ifndef MANIP_PLATEAU_H_
#define MANIP_PLATEAU_H_

#include "codage_numerique.h"
#include "m_distributions.h"

#define PLATEAU_MAX_COLONNES 20		//Nombre maximal de colonnes sur le plateau.
#define PLATEAU_MIN_COLONNES  2		//Nombre minimal de colonnes sur le plateau.
#define PLATEAU_MAX_PIECES   35		//Nombre maximal de pièces par colonne.
#define PLATEAU_MIN_PIECES    1		//Nombre minimal de pièces par colonne.
#define TRUE   1                    //Permet de valider un entier.
#define FALSE  0                    //Permet de refuser un entier.

#define FACILE    1                 //Si le joueur saisie la valeur 1 dans le menu de choix des niveaux, le niveau choisi est "Facile".
#define MOYEN     2                 //Si le joueur saisie la valeur 2 dans le menu de choix des niveaux, le niveau choisi est "Moyen".
#define DIFFICILE 3                 //Si le joueur saisie la valeur 3 dans le menu de choix des niveaux, le niveau choisi est "Difficile".
#define QUITTER   4                 //Si le joueur saisie la valeur 4 dans le menu de choix des niveaux, le programme s'arrête.

/*******************************************************************************/
/*                   DÉCLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

/******** PLATEAU_INIT ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aléatoire de pièces entre 1 et PLATEAU_MAX_PIECES = 35.
void plateau_init(int plateau[], int nb_colonnes);                  
// plateau[]   : Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 à 20.


/******** NIM_JOUER_TOUR ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Applique des changements à la configuration du plateau de jeu en retirant "nb_pieces" de la colonne "colonne" du plateau. 
//Retourne "TRUE" si la valeur de "colonne" est correct, sinon elle retourne "FALSE".
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces);
// plateau[]   : Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 à 20.
// colonne     : Contient la valeur de la colonne selectionné allant de 0 à nb_colonnes.
// nb_pieces   : Représente le nombre de pièces qui va être retirer durant le tour allant de 1 au nombre total de pièces restantes dans la colonne.


/******** PLATEAU_DEFRAGMENTER ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne". 
//Retourne le nombre de colonnes restantes.
int plateau_defragmenter(int plateau[], int nb_colonnes);
// plateau[]   : Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 à 20.


/******** NIM_CHOIX_IA_ALEATOIRE ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Fonction qui effectue un jeu aléatoire en choisissant au hasard une colonne, puis au hasard le nombre de pièces à jouer de cette colonne. 
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces);
// plateau[]			: Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes			: Contient le nombre de colonne du plateau allant de 2 à 20.
// * choix_colonne		: Contient la valeur de la colonne selectionnée par l'ordinateur allant de 0 à nb_colonnes.
// * choix_nb_pieces	: Contient le bnombres de pièces que l'ordinateur souhaite retirer.


/******** NIM_CHOIX_IA ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Fonction qui détermine quel doit être le jeu de l'ordinateur.
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces);
// plateau[]			: Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes			: Contient le nombre de colonne du plateau allant de 2 à 20.
// niveau				: Contient le niveau choisi par l'utilisateur au début du programme.
// * choix_colonne		: Contient la valeur de la colonne selectionnée par l'ordinateur allant de 0 à nb_colonnes.
// * choix_nb_pieces	: Contient le bnombres de pièces que l'ordinateur souhaite retirer.

#endif