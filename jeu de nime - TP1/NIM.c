/************************************************************************************************************************************************************************************/
/*  Fichier : NIM_IO.C																						                                                                        */
/*  Auteurs : BOIRET Romain   BOIR71300401																		                                                                    */
/*	          LENGA  Amorella LENA91330301																		                                                                    */
/*  Date de cr�ation : <17 / 10 / 2023>																		                                                                        */
/*                                                                                                                                                                                  */
/*  Ce module contient les d�finitions des fonctions suivantes : "plateau_init()", "nim_jouer_tour()", "plateau_afficher", "plateau_supprimer_colonne", "plateau_defragmenter",     */
/*  "nim_choix_ia_aleatoire", "nim_choix_ia", "construire_mat_binaire", "sommes_mat_binaire", "position_premier_impaire".                                                           */
/************************************************************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "nim.h"

/***************************************************************************************/
/*                         DECLARATION DES FONCTIONS PRIV�ES                           */
/***************************************************************************************/

/******** PLATEAU_SUPPRIMER_COLONNE ******/ // <--[fonction priv�e].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Supprime la colonne "col_a_supprimer" du plateau. 
static void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);
// plateau[]		: Contient le nombre pi�ces pour chaque colonne allant de 1 � 35.
// nb_colonnes      : Contient le nombre de colonne du plateau allant de 2 � 20.
// col_a_supprimer	: Contient la valeur de la colonne � supprimer allant de 0 � nb_colonnes.


/******** CONSTRUIRE_MAT_BINAIRE ******/ // <--[fonction priv�e].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Construit la matrice binaire n�cessaire � l'algorithme de choix de jeu de l'ordinateur.
static void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]);
// plateau[]					: Contient le nombre pi�ces pour chaque colonne allant de 1 � 35.
// nb_colonnes					: Contient le nombre de colonne du plateau allant de 2 � 20.
// matrice[][CODAGE_NB_BITS]	: Repr�sente la matrice binaire util� par l'ordinateur pour les niveaux 2 et 3.


/******** SOMMES_MAT_BINAIRE ******/ // <--[fonction priv�e].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Calcule les sommes des colonnes d'une matrice binaire de taille "nb_lignes" * CODAGE_NB_BITS. 
static void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]);
// matrice[][CODAGE_NB_BITS]	: Repr�sente la matrice binaire util� par l'ordinateur pour les niveaux 2 et 3.
// nb_lignes					: Contient le nombre de lignes de la matrice allant de 2 � 20.
// sommes[]						: Contient les sommes correspondant au nombre de bits �gal � 1.


/******** POSITION_PREMIER_IMPAIRE ******/ // <--[fonction priv�e].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Recherche la premi�re valeur impaire d'un tableau tab et retourne son indice. 
//Retourne la position du tableaux contenant la premiere somme impaire, sinon elle retourne la valeur -1.
static int position_premier_impaire(const int tab[]);
// tab[] : Contient la colonne de la matrice correspondant � la premiere somme impair.

/***************************************************************************************/
/*                             DEFINITION DES FONCTIONS                                */
/***************************************************************************************/

/*==========================================================*/
//Fonction "plateau_init" - Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre al�atoire de pi�ces entre 1 et PLATEAU_MAX_PIECES = 35 � l'aide de la fonction "md_randi()". 
void plateau_init(int plateau[], int nb_colonnes)
{
	int i; //Variable temporaire pour la boucle for.

	for (i = 0; i < nb_colonnes; i++)
	{
		plateau[i] = md_randi(PLATEAU_MAX_PIECES);
	}
}

/*==========================================================*/
//Fonction "nim_jouer_tour" - Pour �tre valide, la colonne doit exister et nombre de pi�ces retir�es doit �tre <= au nombre de pi�ces actuellement pr�sentes dans la colonne en question. 
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces)
{
	if (colonne == -858993460) //Forcer colonne � 0 lorsqu'il n'est pas renseign�.
	{
		colonne = 0;
	}

	if (colonne <= nb_colonnes && nb_pieces <= plateau[colonne])
	{
		plateau[colonne] -= nb_pieces;
		return TRUE;
	}
	else
		return FALSE;
}

/*==========================================================*/
//Fonction "plateau_supprimer_colonne" - Supprime la colonne "col_a_supprimer" du plateau. On devra donc copier les valeurs de toutes les colonnes suivantes du plateau d�une position vers la gauche. 
static void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
	int i; //Variable temporaire pour la boucle for.

	for (i = col_a_supprimer; i <= nb_colonnes; i++)
	{
		plateau[i] = plateau[i + 1];
	}

	nb_colonnes--;
}

/*==========================================================*/
//Fonction "plateau_defragmenter" - Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne". 
int plateau_defragmenter(int plateau[], int nb_colonnes)
{
	int i; //Variable temporaire pour la boucle for.
	int N = nb_colonnes; //Repr�sente le nombre de colonnes avant la suppression et apr�s.

	for (i = 0; i <= nb_colonnes; i++)
	{
		if (plateau[i] == 0)
		{
			plateau_supprimer_colonne(plateau, nb_colonnes, i);
			N--;
		}
	}

	return N;
}

/*==========================================================*/
//Fonction "nim_choix_ia_aleatoire" - Fonction qui effectue un jeu aleatoire en choisissant au hasard une colonne, puis au hasard le nombre de pieces a jouer de cette colonne � l'aide de la fonction "rand()". 
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{
	*choix_colonne = rand() % nb_colonnes;

	*choix_nb_pieces = 1 + rand() % (plateau[*choix_colonne]);
}

/*==========================================================*/
//Fonction "nim_choix_ia" - Le "niveau" de difficult� (entre 0 et 2) d�termine le niveau de difficult� que doit avoir l�ordinateur. Si le niveau de difficult� est 0 (FACILE), l�ordinateur joue al�atoirement. Avec le niveau 1 (MOYEN), il utilise son algorithme dans 50% du temps. Avec le niveau 2 (DIFICILE), l�ordinateur joue de fa�on intelligente avec l�algorithme pour tous ses coups.
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces)
{
	int matrice[PLATEAU_MAX_COLONNES][CODAGE_NB_BITS]; //Stocke la matrice binaire.
	int sommes[CODAGE_NB_BITS]; //Stocke la sommes des bits.
	int tab_ligne[CODAGE_NB_BITS]; //Repr�sente une ligne de la matrice.
	int colonne; //Repr�sente la colonne choisie par l'ordinateur.
	int pieces; //Repr�sente le nombre de pi�ces choisies par l'ordinateur.
	int i_impaire; //Repr�sente la premi�re somme impaire.
	int val_bit; //Sert � d�tect� le premier bits �gal � 1.
	int deci; //Repr�sente le nombre de pi�ces restantes apr�s le tour de l'ordinateur.
	int i, j; //Variables temporaires pour les boucles for.
	srand(time(NULL));

	switch (niveau)
	{
		case FACILE: //si le jeu est de niveau facile, on joue al�atoirement. J'apelle la fonction al�atoire
		{
			nim_choix_ia_aleatoire(plateau, nb_colonnes, &colonne, &pieces);

			*choix_colonne = colonne;
			*choix_nb_pieces = pieces;

			break;
		}

		case MOYEN: case DIFFICILE: //si le jeu est jou� de fa�on intelligente.
		{
			construire_mat_binaire(plateau, nb_colonnes, matrice);
			sommes_mat_binaire(matrice, nb_colonnes, sommes);

			i_impaire = position_premier_impaire(sommes);

			if (i_impaire == -1) // �tat pair.
			{
				nim_choix_ia_aleatoire(plateau, nb_colonnes, &colonne, &pieces);

				*choix_colonne = colonne;
				*choix_nb_pieces = pieces;

				break;
			}
			else // �tat impair.
			{
				// d�tecte le premier bit �gale � 1.
				for (i = 0; i < nb_colonnes; i++)
				{
					val_bit = matrice[i][i_impaire];

					if (val_bit == 1)
						break;
				}

				*choix_colonne = i;

				// change les bits pour les sommes impaires.
				for (j = 0; j < CODAGE_NB_BITS; j++)
				{
					if (sommes[j] % 2 != 0) // si la somme est impaire
					{
						if (matrice[i][j] == 1) matrice[i][j] = 0;
						else if (matrice[i][j] == 0) matrice[i][j] = 1;
					}

					tab_ligne[j] = matrice[i][j];
				}

				deci = codage_bin2dec(tab_ligne);

				pieces = plateau[i] - deci;
	
				*choix_nb_pieces = pieces;
			}

			break;
		}
	}
}

/*==========================================================*/
//Fonction "construire_mat_binaire" - Chaque ligne de la matrice correspond � une colonne du plateau de jeu et contient la repr�sentation binaire du nombre de pi�ces pr�sentes sur la colonne en question.
static void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS])
{
	int convert[CODAGE_NB_BITS]; //Tableau temporaire.
	int val; //Stocke la valeur d'une colonne du plateau.
	int val_bin; //Stocke la valeur binaire convertie.
	int i, j; //Variables temporaires pour les boucles for.

	for (i = 0; i < nb_colonnes; i++)
	{
		val = plateau[i];
		val_bin = codage_dec2bin(val, convert);

		for (j = 0; j < CODAGE_NB_BITS; j++)
		{
			matrice[i][j] = convert[j];
		}
	}
}

/*==========================================================*/
//Fonction "sommes_mat_binaire" - Calcule les sommes des colonnes d'une matrice binaire de taille "nb_lignes" * CODAGE_NB_BITS. Les r�sultats sont stock�s dans le tableau "sommes", on assume que le tableau est au moins de taille CODAGE_NB_BITS.
static void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[])
{
	int S; //Repr�sente la somme des bits d'une colonne de la matrice binaire.
	int i, j; //Variables temporaires pour les boucles for.

	for (j = 0; j < CODAGE_NB_BITS; j++)
	{
		S = 0;

		for (i = 0; i < nb_lignes; i++)
		{
			S += matrice[i][j];
		}

		sommes[j] = S;
	}
}

/*==========================================================*/
//Fonction "position_premier_impaire" - Recherche la premi�re valeur impaire d'un tableau tab et retourne son indice. Si le tableau ne contient aucune valeur impaire, la fonction retourne -1. 
static int position_premier_impaire(const int tab[])
{
	int i; //Variable temporaire pour la boucle for.
    
	for (i = 0; i < CODAGE_NB_BITS; i++)
	{
		if (tab[i] % 2 != 0)
		{
			return i;
		}
	}

	return -1;
}
