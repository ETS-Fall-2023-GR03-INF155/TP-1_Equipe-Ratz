/*************************************************************************************************************************************/
/*  Fichier : NIM_TEST.C																							                 */
/*  Auteurs : BOIRET Romain   BOIR71300401																		                     */
/*	          LENGA  Amorella LENA91330301																		                     */
/*  Date de cr�ation : <17 / 10 / 2023>																		                         */
/*                                                                                                                                   */
/*  Ce module sert � tester les fonctions qui seront utilent au programme.                                                           */
/*************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include "nim_io.h"

/***************************************************************************************/
/*                             DEFINITION DES FONCTIONS                                */
/***************************************************************************************/

/*==========================================================*/
//Fonction "lire_entier" - La fonction doit valider la saisie et redemander � l'usager de saisir une valeur jusqu'� l'obtention d'une valeur satisfaisante.
/*int lire_entier(int min, int max)
{
    int entier; //Repr�sente l'entier que l'utilisateur choisi.
    int valide; //Permet de valider l'entier choisi.

    do
    {
        printf("Choisissez une valeur entre %d et %d: ", min, max);
        valide = scanf("%d", &entier);
        FFLUSH;

        if (min > entier || entier > max)
        {
            printf("Recommencez\n");
            system("pause");
        }

    } while (min > entier || entier > max || valide != 1);

    return entier;
}
*/

/*==========================================================*/
//Fonction "plateau_afficher" - Elle affiche chaque colonne en mettant une pi�ce (�toile) par ligne, selon le nombre de pi�ces pr�sentes dans la colonne en question. Les num�ros de colonnes ainsi qu�une colonne de chiffres � gauche indiquant le nombre de pi�ces sont �galement affich�s.
/*void plateau_afficher(const int plateau[], int nb_colonnes, int col_select, int humtobot)
{
    int ligne = 6; //Pour la marge.
    int i, j; //Variables temporaires pour les boucles for.

    clrscr();				//clears the contents of the console
    gotoxy(0, 0); printf("****** Tour Joueur ******");

    for (i = PLATEAU_MAX_PIECES; i >= PLATEAU_MIN_PIECES; i--)
    {
        afficher(-4, ligne, 0, humtobot);
        printf("%d", i);

        for (j = 0; j <= nb_colonnes; j++)
        {
            if (i <= plateau[j])
            {
                afficher(j * 3, ligne, col_select, humtobot);
                printf("*");
            }
            else
            {
                textbackground(BLACK);
                gotoxy(j * 3 + 4, ligne);
                printf(" ");
            }
        }
        ligne++;
    }

    int ligne2 = ligne + 1;

    for (i = 0; i <= nb_colonnes; i++)
    {
        if (i <= plateau[i])
        {
            afficher(i * 3, ligne2, col_select, humtobot);
            printf("%d", i);
        }
        else if (i == nb_colonnes)
        {
            textbackground(BLACK);
            gotoxy(i * 3 + 4, ligne2);
            printf(" ");
        }
        else
        {
            textbackground(BLACK);
            gotoxy(i * 3 + 4, ligne2);
            printf("%d", i);
        }
    }

    textbackground(BLACK);
}
*/

/*==========================================================*/
//Fonction "tour_humain" - d�clenche le tour de l'humain en demandant � l'usager de choisir la colonne et le nombre de pi�ces � retirer du plateau de jeu. Une fois le choix effectu�, la fonction doit faire appel � "nim_jouer_tour" pour appliquer les changements au plateau.
/*void tour_humain(int plateau[], int nb_colonnes)
{
    int colonnechoisie = 0; //Repr�sente la colonne choisie.
    int nb_pieces; //Repr�sente le nombre de pieces choisies par le joueur.

    colonnechoisie = choisir_colonne(plateau, nb_colonnes, 1);

    clrscr();				//clears the contents of the console
    plateau_afficher(plateau, nb_colonnes, colonnechoisie, 1);

    gotoxy(0, 2); printf("==> Nombre de pieces: ");
    nb_pieces = lire_entier(1, plateau[colonnechoisie]);

    nim_jouer_tour(plateau, nb_colonnes, colonnechoisie, nb_pieces);
}
*/

/*==========================================================*/
//Fonction "tour_ia" - Pour connaitre le choix de l'ordinateur, on fait appel � la fonction "nim_choix_ia". Une fois le choix effectu�, la fonction doit faire appel � "nim_jouer_tour" pour appliquer les changements au plateau.
/*void tour_ia(int plateau[], int nb_colonnes, int difficulte)
{
    int choix_colonne; //Repr�sente la colonne choisie par l'ordinateur.
    int choix_nb_pieces; //Repr�sente le nombre de pieces choisies par l'ordinateur.

    nim_choix_ia(plateau, nb_colonnes, difficulte, &choix_colonne, &choix_nb_pieces);

    plateau_afficher(plateau, nb_colonnes, choix_colonne, -1);
    gotoxy(0, 0); printf("****** Tour Ordinateur ******");
    gotoxy(0, 2); printf("L'ordinateur va retirer %d pieces de la colonne %d\n", choix_nb_pieces, choix_colonne);
    system("pause");

    nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
}
*/

/*==========================================================*/
//Fonction "demarrer_jeu" - Pour donner la main aux joueurs, on appelle les fonctions "tour_humain" et "tour_ia" en alternance.  Apr�s chaque tour, cette fonction se charge de d�fragmenter le plateau de jeu, de modifier la taille du plateau � l'�cran et d'afficher la nouvelle configuration du plateau de jeu. 
/*void demarrer_jeu(int niveau)
{
    static int humtobot = 1; //D�tecte si c'est le tour de l'humain ou de l'ordinateur.
    int plateau[PLATEAU_MAX_COLONNES]; //Tableau qui stocke le nombre de pi�ces de chaque colonne.
    int nb_colonne; //Repr�sente le nombre de colonne qui constitue le jeu.
    static int choix_colonne; //Repr�sente la colonne s�l�ctionn�.
    static int choix_nb_pieces; //Repr�sente le nombre de pi�ces choisie.
    int difficulte = 2; //Repr�sente la difficult� du jeu.
    int un_sur_deux = -1; //Quand le niveau choisi est 2, une fois sur deux, l'ordinateur joue al�atoirement et l'autre fois il joue int�ligemment.
    srand(time(NULL));

    clrscr();				//clears the contents of the console
    gotoxy(0, 0); printf("***** NOUVELLE PARTIE *****");
    gotoxy(0, 1); printf("Nombre de colonnes:");
    gotoxy(0, 2); nb_colonne = lire_entier(PLATEAU_MIN_COLONNES, PLATEAU_MAX_COLONNES);
    plateau_init(plateau, nb_colonne);

    while (nb_colonne > 0)
    {
        humtobot = 1;

        tour_humain(plateau, nb_colonne);
        nb_colonne = plateau_defragmenter(plateau, nb_colonne);
        if (nb_colonne == 0)
        {
            plateau_afficher(plateau, 1, PLATEAU_MAX_COLONNES + 1, humtobot);
            clrscr();				//clears the contents of the console
            gotoxy(0, 0); printf("Bravo vous avez gagne !\n");

            break;
        }

        if (niveau == MOYEN)
        {
            difficulte += un_sur_deux; // difficulte = 1 ou 2
        }
        else
        {
            difficulte = niveau;
        }

        humtobot *= -1;

        tour_ia(plateau, nb_colonne, difficulte);

        nb_colonne = plateau_defragmenter(plateau, nb_colonne);

        if (nb_colonne == 0)
        {
            plateau_afficher(plateau, 1, PLATEAU_MAX_COLONNES + 1, humtobot);
            clrscr();				//clears the contents of the console
            gotoxy(0, 0); printf("Desole vous avez perdu...\n");

            break;
        }
        un_sur_deux *= -1; // un_sur_deux = 1 ou -1
    }
}
*/

/*==========================================================*/
//Fonction "plateau_init" - Initialise le plateau de jeu en remplissant les "nb_colonnes" d'un nombre al�atoire de pi�ces entre 1 et PLATEAU_MAX_PIECES = 35 � l'aide de la fonction "md_randi()". 
/*void plateau_init(int plateau[], int nb_colonnes)
{
	int i; //Variable temporaire pour la boucle for.

	for (i = 0; i < nb_colonnes; i++)
	{
		plateau[i] = md_randi(PLATEAU_MAX_PIECES);
	}
}
*/

/*==========================================================*/
//Fonction "nim_jouer_tour" - Pour �tre valide, la colonne doit exister et nombre de pi�ces retir�es doit �tre <= au nombre de pi�ces actuellement pr�sentes dans la colonne en question. 
/*int nim_jouer_tour(int plateau[], int nb_colonnes, int colonne, int nb_pieces)
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
*/

/*==========================================================*/
//Fonction "plateau_defragmenter" - Fonction qui supprime les colonnes vides du tableau en utilisant la fonction "plateau_supprimer_colonne". 
/*int plateau_defragmenter(int plateau[], int nb_colonnes)
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
*/

/*==========================================================*/
//Fonction "nim_choix_ia_aleatoire" - Fonction qui effectue un jeu aleatoire en choisissant au hasard une colonne, puis au hasard le nombre de pieces a jouer de cette colonne � l'aide de la fonction "rand()". 
/*void nim_choix_ia_aleatoire(const int plateau[], int nb_colonnes, int* choix_colonne, int* choix_nb_pieces)
{
	*choix_colonne = rand() % nb_colonnes;

	*choix_nb_pieces = 1 + rand() % (plateau[*choix_colonne]);
}
*/

/*==========================================================*/
//Fonction "nim_choix_ia" - Le "niveau" de difficult� (entre 0 et 2) d�termine le niveau de difficult� que doit avoir l�ordinateur. Si le niveau de difficult� est 0 (FACILE), l�ordinateur joue al�atoirement. Avec le niveau 1 (MOYEN), il utilise son algorithme dans 50% du temps. Avec le niveau 2 (DIFICILE), l�ordinateur joue de fa�on intelligente avec l�algorithme pour tous ses coups.
/*void nim_choix_ia(const int plateau[], int nb_colonnes, int niveau, int* choix_colonne, int* choix_nb_pieces)
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
*/
