#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include "nim_test.h"
#include "m_distributions.h"
#include "codage_numerique.h"


void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces);

void main()
{
	int plateau[PLATEAU_MAX_COLONNES], niveau, nb_colonne, choix_colonne, choix_nb_pieces;
	int  un_sur_deux = 1;

	gotoxy(0, 0); printf("MENU:");
	gotoxy(0, 1); printf("==> Niveau de difficulte");
	gotoxy(0, 2); printf("(1) Jeu niveau FACILE");
	gotoxy(0, 3); printf("(2) Jeu niveau MOYEN");
	gotoxy(0, 4); printf("(3) Jeu niveau DIFFICILE");
	gotoxy(0, 5); printf("(4) Quitter");
	gotoxy(2, 7); niveau = lire_entier(1, 4) ;

	if (niveau == 4) exit(1);

	demarrer_jeu(niveau);
}

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

			printf("L'ordinateur va retirer %d pieces de la colonne %d\n", pieces, colonne);
			system("pause");

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

				printf("L'ordinateur va retirer %d pieces de la colonne %d\n", pieces, colonne);
				system("pause");

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

				printf("L'ordinateur va retirer %d pieces de la colonne %d\n", pieces, i);
				system("pause");
			}

			break;
		}
	}
}
