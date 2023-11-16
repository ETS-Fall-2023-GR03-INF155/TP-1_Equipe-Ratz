/*******************************************************************************/
/*  Fichier : NIM_IO.H                                                         */
/*  Auteurs : BOIRET Romain   BOIR71300401		                               */
/*            LENGA  Amorella LENA91330301                                     */
/*  Date de création : <17 / 10 / 2023>                                        */
/*                                                                             */
/*  Ce module contient les fonctions necéssaires au déroulement du jeu NIM.    */
/*******************************************************************************/
#pragma once

#include "WinConsole.h"
#include "nim.h"

#define FFLUSH while(getchar() != '\n') {} //Fonction à implémenter derrière chaque instruction scanf().

#define TOUCHE_ENTREE 13                   //La valeur 13 représente la touche "entrée"
#define TOUCHE_DROITE 77                   //La valeur 77 représente la touche "touche_droite"
#define TOUCHE_GAUCHE 75                   //La valeur 75 représente la touche "touche_gauche"
#define TOUCHE_ESPACE 32                   //La valeur 32 représente la touche "espace"

/*******************************************************************************/
/*                   DÉCLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

/******** LIRE_ENTIER ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Demande à l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement). La fonction doit valider la saisie et redemander à l'usager de saisir une valeur jusqu'à l'obtention d'une valeur satisfaisante.
//Retourne l'entier saisie par l'utilisateur.
int lire_entier(int min, int max);   
// min : Correspond à la valeur minimal que peut valoir l'entier choisi.
// max : Correspond à la valeur maximal que peut valoir l'entier choisi.


/******** PLATEAU_AFFICHER ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aléatoire de pièces entre 1 et PLATEAU_MAX_PIECES = 35. 
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select, int humtobot);
// plateau[]   : Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 à 20.
// col_select  : Contient la valeur de la colonne selectionné allant de 0 à nb_colonnes.
// humtobot    : Sert à changer la couleur de la colonne selectionné du rouge au bleu, la valeur contenue par ce paramètre varie entre -1 et 1.


/******** TOUR_HUMAIN ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Déclenche le tour de l'humain en demandant à l'usager de choisir la colonne (avec un appel à "choisir_colonne") et le nombre de pièces à retirer du plateau de jeu.  Une fois le choix effectué, la fonction doit faire appel à "nim_jouer_tour" pour appliquer les changements au plateau. 
void tour_humain(int plateau[], int nb_colonnes);                                       
// plateau[]   : Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 à 20.


/******** TOUR_IA ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Déclenche le tour de l'ordinateur. Pour connaitre le choix de l'ordinateur, on fait appel à la fonction "nim_choix_ia".
void tour_ia(int plateau[], int nb_colonnes, int niveau);
// plateau[]   : Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 à 20.
// niveau      : Correspond à la valeur correspondant au niveau choisi par le joueuir, ce paramètre peut contenir une valeur de 1 à 3.


/******** DEMARRER_JEU ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Fonction qui contrôle le jeu de nim: elle donne la main, tour à tour, à chacun des deux joueurs et déclare le gagnant une fois la partie terminée. On quitte cette fonction quand la partie est terminée. 
void demarrer_jeu(int niveau); 
// niveau      : Correspond à la valeur correspondant au niveau choisi par le joueuir, ce paramètre peut contenir une valeur de 1 à 3.
