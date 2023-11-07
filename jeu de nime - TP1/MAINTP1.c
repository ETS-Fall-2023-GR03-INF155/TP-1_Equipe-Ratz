/*
    Auteurs: <Romain & Amorella>
    Date de fin: <12/11/2023>
    But du programme: Jeu de Nim
*/
#define _CRT_SECURE_NO_WARNINGS
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "nim_io.h"
#include "m_distributions.h"


/***************************************************************************************/
/*                                 PROGRAMME PRINCIPAL                                 */
/***************************************************************************************/

int main(void)
{
	int niveau;

	gotoxy(0, 0); printf("MENU:");
	gotoxy(0, 1); printf("==> Niveau de difficulte");
	gotoxy(0, 2); printf("(1) Jeu niveau FACILE");
	gotoxy(0, 3); printf("(2) Jeu niveau MOYEN");
	gotoxy(0, 4); printf("(3) Jeu niveau DIFFICILE");
	gotoxy(0, 5); printf("(4) Quitter");
	gotoxy(0, 7); niveau = lire_entier(1, 4);

	if (niveau == 4) exit(1);

	demarrer_jeu(niveau);

    system("pause");
    return EXIT_SUCCESS;
}
