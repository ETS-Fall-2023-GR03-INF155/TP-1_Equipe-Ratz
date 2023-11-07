#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "nim.h"

/*Fonction E*/ static void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer);
/*PARTIE 2:*/
/*Fonction Q*/ static void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS]);
/*Fonction R*/ static void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[]);
/*Fonction S*/ static int position_premier_impaire(const int tab[]);

/*==========================================================*/
//Fonction B - Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre aleatoire de pieces entre 1 et PLATEAU_MAX_PIECES = 35.
void plateau_init(int plateau[], int nb_colonnes)
{
	int i;

	for (i = 0; i < nb_colonnes; i++)
	{
		plateau[i] = md_randi(PLATEAU_MAX_PIECES);
	}
}

/*==========================================================*/
//Fonction D - Applique des changements a la configuration du plateau de jeu en retirant "nb_pieces" de la colonne "colonne" du plateau.
int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces)
{
	if (colonne == -858993460) //forcer colonne à 0 lorsqu'il n'est pas renseigné.
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
//Fonction E - Supprime la colonne "col_a_supprimer" du plateau.
static void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
	int i;

	for (i = col_a_supprimer; i <= nb_colonnes; i++)
	{
		plateau[i] = plateau[i + 1];
	}

	nb_colonnes--;
}

/*==========================================================*/
//Fonction F - Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne". Le nombre de colonnes restant est retourne.
int plateau_defragmenter(int plateau[], int nb_colonnes)
{
	int i, N = nb_colonnes;

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
//Fonction G - Fonction qui effectue un jeu aleatoire en choisissant au hasard une colonne, puis au hasard le nombre de pieces a jouer de cette colonne. 
void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{
	*choix_colonne = rand() % nb_colonnes;

	*choix_nb_pieces = 1 + rand() % (plateau[*choix_colonne]);
}

/*==========================================================*/
//Fonction H - Fonction qui détermine quel doit être le jeu de l'ordinateur.
void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces)
{
	int colonne, pieces, i_impaire;

	srand(time(NULL));

	int i, j;
	int val_bit, deci;
	int matrice[PLATEAU_MAX_COLONNES][CODAGE_NB_BITS], sommes[CODAGE_NB_BITS], tab_ligne[CODAGE_NB_BITS];

	switch (niveau)
	{
		case 1: //si le jeu est de niveau facile, on joue aléatoirement. J'apelle la fonction aléatoire
		{
			nim_choix_ia_aleatoire(plateau, nb_colonnes, &colonne, &pieces);

			*choix_colonne = colonne;
			*choix_nb_pieces = pieces;

			break;
		}

		case 2: case 3: //si le jeu est joué de façon intelligente.
		{
			construire_mat_binaire(plateau, nb_colonnes, matrice);
			sommes_mat_binaire(matrice, nb_colonnes, sommes);

			i_impaire = position_premier_impaire(sommes);

			if (i_impaire == -1) // état pair.
			{
				nim_choix_ia_aleatoire(plateau, nb_colonnes, &colonne, &pieces);

				*choix_colonne = colonne;
				*choix_nb_pieces = pieces;

				break;
			}
			else // état impair.
			{
				for (i = 0; i < nb_colonnes; i++)
				{
					val_bit = matrice[i][i_impaire];

					if (val_bit == 1)
						break;
				}

				*choix_colonne = i;

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
//Fonction Q - Construit la matrice binaire nécessaire à l'algorithme de choix de jeu de l'ordinateur.
static void construire_mat_binaire(const int plateau[], int nb_colonnes, int matrice[][CODAGE_NB_BITS])
{
	int convert[CODAGE_NB_BITS]; //tableau temporaire.
	int i, j, val, val_bin;

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
//Fonction R - Calcule les sommes des colonnes d'une matrice binaire de taille "nb_lignes" * CODAGE_NB_BITS.
static void sommes_mat_binaire(const int matrice[][CODAGE_NB_BITS], int nb_lignes, int sommes[])
{
	int i, j, S;

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
//Fonction S - Recherche la première valeur impaire d'un tableau tab et retourne son indice.
static int position_premier_impaire(const int tab[])
{
	int i;
    
	for (i = 0; i < CODAGE_NB_BITS; i++)
	{
		if (tab[i] % 2 != 0)
		{
			return i;
		}
	}

	return -1;
}