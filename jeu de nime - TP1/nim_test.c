#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include "m_distributions.h"
#include "nim_test.h"
#include "nim.h"

#define TAILLE 5

void main()
{
	int plateau[TAILLE];
	plateau_supprimer_colonne(plateau, 5, 2);
}

void plateau_supprimer_colonne(int plateau[], int nb_colonnes, int col_a_supprimer)
{
	int i;

	nb_colonnes--;

	for (i = col_a_supprimer; i < nb_colonnes; i++)
	{
		plateau[i] = plateau[i + 1];
	}
}