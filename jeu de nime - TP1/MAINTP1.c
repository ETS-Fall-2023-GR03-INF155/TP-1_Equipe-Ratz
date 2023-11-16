/*************************************************************************************************************************************/
/*  Fichier : MAINTP1.C																							                     */
/*  Auteurs : BOIRET Romain   BOIR71300401																		                     */
/*	          LENGA  Amorella LENA91330301																		                     */
/*  Date de création : <17 / 10 / 2023>																		                         */
/*                                                                                                                                   */
/*  Ce module contient la fonction main(), le menu de selection des niveaux, ainsi que l'appel de la fonction "demarrer_jeu()".		 */
/*                                                                                                                                   */
/*  But du programme : Ce programme permet de jouer à une des versions du jeu de Nim.                                                */
/*************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "m_distributions.h"
#include "nim_test.c"

/***************************************************************************************/
/*                                 PROGRAMME PRINCIPAL                                 */
/***************************************************************************************/

int main(void)
{
	int niveau; //Représente le niveau choisi par le joueur.
	
	do
	{
		gotoxy(0, 0); printf("MENU:");
		gotoxy(0, 1); printf("==> Niveau de difficulte");
		gotoxy(0, 2); printf("(1) Jeu niveau FACILE");
		gotoxy(0, 3); printf("(2) Jeu niveau MOYEN");
		gotoxy(0, 4); printf("(3) Jeu niveau DIFFICILE");
		gotoxy(0, 5); printf("(4) Quitter");
		gotoxy(0, 7); niveau = lire_entier(FACILE, QUITTER);

		if (niveau == QUITTER) exit(1);

		demarrer_jeu(niveau);

		system("pause");
		clrscr();				//clears the contents of the console

	} while (niveau != QUITTER);

    return EXIT_SUCCESS;
}
