/*******************************************************************************/
/*  Fichier : NIM_IO.H                                                         */
/*  Auteurs : BOIRET Romain   BOIR71300401		                               */
/*            LENGA  Amorella LENA91330301                                     */
/*  Date de cr�ation : <17 / 10 / 2023>                                        */
/*                                                                             */
/*  Ce module contient les fonctions nec�ssaires au d�roulement du jeu NIM.    */
/*******************************************************************************/
#pragma once

#include "WinConsole.h"
#include "nim.h"

#define FFLUSH while(getchar() != '\n') {} //Fonction � impl�menter derri�re chaque instruction scanf().

#define TOUCHE_ENTREE 13                   //La valeur 13 repr�sente la touche "entr�e"
#define TOUCHE_DROITE 77                   //La valeur 77 repr�sente la touche "touche_droite"
#define TOUCHE_GAUCHE 75                   //La valeur 75 repr�sente la touche "touche_gauche"
#define TOUCHE_ESPACE 32                   //La valeur 32 repr�sente la touche "espace"

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

/******** LIRE_ENTIER ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Demande � l'usager de saisir un entier entre les bornes "min" et "max" (inclusivement). La fonction doit valider la saisie et redemander � l'usager de saisir une valeur jusqu'� l'obtention d'une valeur satisfaisante.
//Retourne l'entier saisie par l'utilisateur.
int lire_entier(int min, int max);   
// min : Correspond � la valeur minimal que peut valoir l'entier choisi.
// max : Correspond � la valeur maximal que peut valoir l'entier choisi.


/******** PLATEAU_AFFICHER ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre al�atoire de pi�ces entre 1 et PLATEAU_MAX_PIECES = 35. 
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select, int humtobot);
// plateau[]   : Contient le nombre pi�ces pour chaque colonne allant de 1 � 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 � 20.
// col_select  : Contient la valeur de la colonne selectionn� allant de 0 � nb_colonnes.
// humtobot    : Sert � changer la couleur de la colonne selectionn� du rouge au bleu, la valeur contenue par ce param�tre varie entre -1 et 1.


/******** TOUR_HUMAIN ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//D�clenche le tour de l'humain en demandant � l'usager de choisir la colonne (avec un appel � "choisir_colonne") et le nombre de pi�ces � retirer du plateau de jeu.  Une fois le choix effectu�, la fonction doit faire appel � "nim_jouer_tour" pour appliquer les changements au plateau. 
void tour_humain(int plateau[], int nb_colonnes);                                       
// plateau[]   : Contient le nombre pi�ces pour chaque colonne allant de 1 � 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 � 20.


/******** TOUR_IA ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//D�clenche le tour de l'ordinateur. Pour connaitre le choix de l'ordinateur, on fait appel � la fonction "nim_choix_ia".
void tour_ia(int plateau[], int nb_colonnes, int niveau);
// plateau[]   : Contient le nombre pi�ces pour chaque colonne allant de 1 � 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 � 20.
// niveau      : Correspond � la valeur correspondant au niveau choisi par le joueuir, ce param�tre peut contenir une valeur de 1 � 3.


/******** DEMARRER_JEU ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Fonction qui contr�le le jeu de nim: elle donne la main, tour � tour, � chacun des deux joueurs et d�clare le gagnant une fois la partie termin�e. On quitte cette fonction quand la partie est termin�e. 
void demarrer_jeu(int niveau); 
// niveau      : Correspond � la valeur correspondant au niveau choisi par le joueuir, ce param�tre peut contenir une valeur de 1 � 3.
