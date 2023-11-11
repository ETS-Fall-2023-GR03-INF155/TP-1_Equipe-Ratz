/************************************************************************************************************************************************************************************/
/*  Fichier : NIM_IO.C																						                                                                        */
/*  Auteurs : BOIRET Romain   BOIR71300401																		                                                                    */
/*	          LENGA  Amorella LENA91330301																		                                                                    */
/*  Date de création : <17 / 10 / 2023>																		                                                                        */
/*                                                                                                                                                                                  */
/*  Ce module contient les définitions des fonctions suivantes : "lire_entier()", "afficher()", "plateau_afficher", "choisir_colonne", "tour_humain", "tour_ia", "demarrer_jeu".    */
/************************************************************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "nim_io.h"

/***************************************************************************************/
/*                         DECLARATION DES FONCTIONS PRIVÉES                           */
/***************************************************************************************/

/******** CHOISIR_COLONNE ******/ // <--[fonction privée].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Permet de choisir une colonne du plateau de jeu avec les touches fléchées (gauche, droite) ou l’espace (‘ ‘). Au départ, on commence par la colonne [0].
static int choisir_colonne(int plateau[], int nb_colonnes, int humtobot);
// plateau[]   : Contient le nombre pièces pour chaque colonne allant de 1 à 35.
// nb_colonnes : Contient le nombre de colonne du plateau allant de 2 à 20.
// humtobot    : Sert à changer la couleur de la colonne selectionné du rouge au bleu, la valeur contenue par ce paramètre varie entre -1 et 1.

/******** AFFICHER ******/ // <--[fonction privée].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Permet d'afficher la colonne choisie par le joueur en rouge et celle choisie par l'ordinateur en bleu, ainsi que d'indiquer la position des pièces sur le plateau.
static void afficher(int x, int y, int is_selected, int humtobot);
// x : Sert pour la fonction "gotoxy()" indique la position en abscisse.
// y : Sert pour la fonction "gotoxy()" indique la position en ordonnée.
// is_selected : Contient la valeur de la colonne selectionné allant de 0 à nb_colonnes.
// humtobot    : Sert à changer la couleur de la colonne selectionné du rouge au bleu, la valeur contenue par ce paramètre varie entre -1 et 1.

/***************************************************************************************/
/*                             DEFINITION DES FONCTIONS                                */
/***************************************************************************************/

/*==========================================================*/
//Fonction "lire_entier" - La fonction doit valider la saisie et redemander à l'usager de saisir une valeur jusqu'à l'obtention d'une valeur satisfaisante.
int lire_entier(int min, int max)
{
    int entier; //Représente l'entier que l'utilisateur choisi.
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

/*==========================================================*/
//Fonction "afficher" - Donne la position et la couleur de "is_selected".
static void afficher(int x, int y, int is_selected, int humtobot)
{
    if (x == is_selected * 3)
    {
        if (humtobot == 1)
        {
            textcolor(WHITE);
            textbackground(RED); //Fond rouge pour la colonne select.
            gotoxy(x + 4, y);
        }
        else
        {
            textcolor(WHITE);
            textbackground(BLUE); //Fond bleu pour la colonne select.
            gotoxy(x + 4, y);
        }
    }
    else
    {
        textcolor(WHITE);
        textbackground(BLACK); //Fond noir pour les autres colonnes.
        gotoxy(x + 4, y);
    }
}

/*==========================================================*/
//Fonction "plateau_afficher" - Elle affiche chaque colonne en mettant une pièce (étoile) par ligne, selon le nombre de pièces présentes dans la colonne en question. Les numéros de colonnes ainsi qu’une colonne de chiffres à gauche indiquant le nombre de pièces sont également affichés.
void plateau_afficher(const int plateau[], int nb_colonnes, int col_select, int humtobot)
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
//Fonction "choisir_colonne" - Au départ, on commence par la colonne [0]. La colonne actuellement sélectionnée sera toujours affichée en ROUGE ou en BLEU (dépendamment de si c'est au tour de l'utilisateur ou de l'ordinateur) avec la fonction "plateau_afficher". Le choix définitif est fait avec la touche ENTER et on retourne le numéro de la colonne choisie. 
static int choisir_colonne(int plateau[], int nb_colonnes, int humtobot)
{
    unsigned char C; //Stocke la valeur que représente la touche présée par le joueur.
    int col_select = 0; //Stocke la colonne séléctionné.
    while (TRUE)
    {
        plateau_afficher(plateau, nb_colonnes, col_select, humtobot);
        gotoxy(0, 2); printf("==> Veuillez choisir la colonne souhaitee");
        gotoxy(3, 4); printf("<- , -> , <ESPACE> : Changer la selection     <ENTER> : Valider");

        C = _getch();

        if (C == 0 || C == 224)
        {
            C = _getch();
        }

        switch (C)
        {
            case TOUCHE_ENTREE:
            {
                return col_select;
            }
            case TOUCHE_GAUCHE: //Flèche gauche si la colonne choisie est inférieure, on diminue de 1.
            {
                if (col_select > 0)
                {
                    col_select--;
                }
                else col_select = nb_colonnes - 1;
                break;
            }
            case TOUCHE_DROITE: case TOUCHE_ESPACE: //Flèche droite.
            {
                if (col_select < nb_colonnes - 1)
                {
                    col_select++; //Si la colonne est supérieur on tasse à droite.
                }
                else col_select = 0;
                break;
            }
        }
    }
}

/*==========================================================*/
//Fonction "tour_humain" - déclenche le tour de l'humain en demandant à l'usager de choisir la colonne et le nombre de pièces à retirer du plateau de jeu. Une fois le choix effectué, la fonction doit faire appel à "nim_jouer_tour" pour appliquer les changements au plateau.
void tour_humain(int plateau[], int nb_colonnes)
{
    int colonnechoisie = 0; //Représente la colonne choisie.
    int nb_pieces; //Représente le nombre de pieces choisies par le joueur.

    colonnechoisie = choisir_colonne(plateau, nb_colonnes, 1);

    clrscr();				//clears the contents of the console
    plateau_afficher(plateau, nb_colonnes, colonnechoisie, 1);

    gotoxy(0, 2); printf("==> Nombre de pieces: ");
    nb_pieces = lire_entier(1, plateau[colonnechoisie]);

    nim_jouer_tour(plateau, nb_colonnes, colonnechoisie, nb_pieces);
}

/*==========================================================*/
//Fonction "tour_ia" - Pour connaitre le choix de l'ordinateur, on fait appel à la fonction "nim_choix_ia". Une fois le choix effectué, la fonction doit faire appel à "nim_jouer_tour" pour appliquer les changements au plateau.
void tour_ia(int plateau[], int nb_colonnes, int difficulte)
{
    int choix_colonne; //Représente la colonne choisie par l'ordinateur.
    int choix_nb_pieces; //Représente le nombre de pieces choisies par l'ordinateur.

    nim_choix_ia(plateau, nb_colonnes, difficulte, &choix_colonne, &choix_nb_pieces);

    plateau_afficher(plateau, nb_colonnes, choix_colonne, -1);
    gotoxy(0, 0); printf("****** Tour Ordinateur ******");
    gotoxy(0, 2); printf("L'ordinateur va retirer %d pieces de la colonne %d\n", choix_nb_pieces, choix_colonne);
    system("pause");

    nim_jouer_tour(plateau, nb_colonnes, choix_colonne, choix_nb_pieces);
}
/*==========================================================*/
//Fonction "demarrer_jeu" - Pour donner la main aux joueurs, on appelle les fonctions "tour_humain" et "tour_ia" en alternance.  Après chaque tour, cette fonction se charge de défragmenter le plateau de jeu, de modifier la taille du plateau à l'écran et d'afficher la nouvelle configuration du plateau de jeu. 
void demarrer_jeu(int niveau)
{
    static int humtobot = 1; //Détecte si c'est le tour de l'humain ou de l'ordinateur.
    int plateau[PLATEAU_MAX_COLONNES]; //Tableau qui stocke le nombre de pièces de chaque colonne.
    int nb_colonne; //Représente le nombre de colonne qui constitue le jeu.
    static int choix_colonne; //Représente la colonne séléctionné.
    static int choix_nb_pieces; //Représente le nombre de pièces choisie.
    int difficulte = 2; //Représente la difficulté du jeu.
    int un_sur_deux = -1; //Quand le niveau choisi est 2, une fois sur deux, l'ordinateur joue aléatoirement et l'autre fois il joue intéligemment.
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
