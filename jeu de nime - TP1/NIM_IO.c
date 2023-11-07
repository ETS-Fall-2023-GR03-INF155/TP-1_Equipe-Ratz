#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "nim_io.h"

/*Fonction privé appartenant à tour_humain*/ static int choisir_colonne(int plateau[], int nb_colonnes, int humtobot);
/*Fonction privé appartenant à plateau_affiché*/ static void afficher(int x, int y, int is_selected, int humtobot);

/*==========================================================*/
//Fonction A - Demande a l'usager de saisir un entier entre les bornes "min" et "max".
int lire_entier(int min, int max)
{
	int entier, valide;

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

/*==========================================================*/
//Fonction C - Affiche la configuration du plateau à l'écran.
static void afficher(int x, int y, int is_selected, int humtobot)
{
    if (x == is_selected * 3)
    {
        if (humtobot == 1)
        {
            textcolor(WHITE);
            textbackground(RED); // Fond rouge pour la colonne select
            gotoxy(x + 4, y);
        }
        else
        {
            textcolor(WHITE);
            textbackground(BLUE); // Fond bleu pour la colonne select
            gotoxy(x + 4, y);
        }
    }
    else
    {
        textcolor(WHITE);
        textbackground(BLACK); // Fond noir pour les autres colonnes
        gotoxy(x + 4, y);
    }
}

void plateau_afficher(const int plateau[], int nb_colonnes, int col_select, int humtobot)
{
    int ligne = 6; //pour la marge
    int i, j;

    clrscr();				//clears the contents of the console
    gotoxy(0, 0); printf("****** Tour Joueur ******");

    for (i = PLATEAU_MAX_PIECES; i >= 1; i--)
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
        else if(i == nb_colonnes)
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

/*==========================================================*/
//Fonction I - Permet de choisir une colonne avec les fleches directionnelles .
static int choisir_colonne(int plateau[], int nb_colonnes, int humtobot)
{
    unsigned char c;
    int col_select = 0;
    while (TRUE)
    {
        plateau_afficher(plateau, nb_colonnes, col_select, humtobot);
        gotoxy(0, 2); printf("==> Veuillez choisir la colonne souhaitee");
        gotoxy(3, 4); printf("<- , -> , <ESPACE> : Changer la selection     <ENTER> : Valider");

        c = _getch();

        if (c == 0 || c == 224)
        {
            c = _getch();
        }

        switch (c)
        {
            case 13:
            {
                return col_select;
            }
            case 75: // Flèche gauche si la colonne choisie est inférieure, on diminue de 1
            {
                if (col_select > 0)
                {
                    col_select--;
                }
                else col_select = nb_colonnes - 1;
                break;
            }
            case 77: case 32: // Flèche droite
            {
                if (col_select < nb_colonnes - 1)
                {
                    col_select++; //si la colonne est supérieur on tasse à droite 
                }
                else col_select = 0;
                break;
            }
        }
    }
}

/*==========================================================*/
//Fonction J - déclenche le tour de l'humain en demandant à l'usager de choisir la colonne et le nombre de pièces à retirer du plateau de jeu.
void tour_humain(int plateau[], int nb_colonnes)
{
    int colonnechoisie = 0, nb_pieces;

    colonnechoisie = choisir_colonne(plateau, nb_colonnes, 1);

    clrscr();				//clears the contents of the console
    plateau_afficher(plateau, nb_colonnes, colonnechoisie, 1);

    gotoxy(0, 2); printf("==> Nombre de pieces: ");
    nb_pieces = lire_entier(1, plateau[colonnechoisie]);

    nim_jouer_tour(plateau, nb_colonnes, colonnechoisie, nb_pieces);
}

/*==========================================================*/
//Fonction K - Déclenche le tour de l'ordinateur.
void tour_ia(int plateau[], int nb_colonnes, int difficulte)
{
    int choix_colonne, choix_nb_pieces;

    nim_choix_ia(plateau, nb_colonnes, difficulte, &choix_colonne, &choix_nb_pieces);

    plateau_afficher(plateau, nb_colonnes, choix_colonne, -1);
    gotoxy(0, 0); printf("****** Tour Ordinateur ******");
    gotoxy(0, 2); printf("L'ordinateur va retirer %d pieces de la colonne %d\n", choix_nb_pieces, choix_colonne);
    system("pause");

    nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
}
/*==========================================================*/
//Fonction L - Fonction qui contrôle le jeu de nim: elle donne la main, tour à tour, à chacun des deux joueurs et déclare le gagnant une fois la partie terminée.
void demarrer_jeu(int niveau)
{
    static int humtobot = 1; // detecte si c'est le tour de l'humain ou de l'ordinateur.
    int plateau[PLATEAU_MAX_COLONNES], nb_colonne;
    static int choix_colonne, choix_nb_pieces;
    int difficulte = 2, un_sur_deux = -1;
    srand(time(NULL));

    clrscr();				//clears the contents of the console
    gotoxy(0, 0); printf("***** NOUVELLE PARTIE *****");
    gotoxy(0, 1); printf("Nombre de colonnes:");
    gotoxy(0, 2); nb_colonne = lire_entier(2, PLATEAU_MAX_COLONNES);
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

        if (niveau == 2)
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