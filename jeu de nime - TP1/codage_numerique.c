#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "codage_numerique.h"

/*==========================================================*/
//Fonction M - Fonction qui inverse les "nb_bits/2" premières valeurs d'un tableau de bits.
int inverser_tab_bits(int tab_bits[], int nb_bits)
{
    int i, temp;

    if (nb_bits <= CODAGE_NB_BITS)
    {
        for (i = 0; i < nb_bits / 2; i++)
        {
            temp = tab_bits[i]; //exemple 0 est mise dans la variable temp
            tab_bits[i] = tab_bits[nb_bits - i - 1]; // i devient donc 7
            tab_bits[nb_bits - i - 1] = temp; //et le dernier élément devient donc 
        }

        return 1;
    }
    else
        return 0;
}

/*==========================================================*/
//Fonction N - Traduit un nombre décimal en binaire.
int codage_dec2bin(int nombre, int resultat[])
{
    int compt = 0;
    int bin;
    int inverse;
    int i;

    //stocker résultat dans le tableau, jusquà 8 bits

    while (nombre > 0)
    {
        bin = nombre % 2; //fais le modulo de 2
        nombre /= 2;
        resultat[compt] = bin; //ajoute ce résultat dans la position
        compt++; //compter chaque fois pour renvoyer le nombre de bits nécessaire pour ce nombre
    }

    for (i = compt; i < CODAGE_NB_BITS; i++)
    {
        resultat[i] = 0;
    }

    inverse = inverser_tab_bits(resultat, CODAGE_NB_BITS);

    if (compt > CODAGE_NB_BITS)
    {
        return 0;
    }
    else
        return compt;
}

/*==========================================================*/
//Fonction O - Affiche un tableau contenant des bits à l'écran.
void afficher_tab_bits(const int tab_bits[], int nb_bits)
{
    int i;

    for (i = 0; i < nb_bits; i++)
    {
        printf("%d", tab_bits[i]);
    }
}

/*==========================================================*/
//Fonction P - Traduit un tableau de bits, représentant un nombre en binaire, vers sa représentation décimale.

int codage_bin2dec(const int tab_bits[])
{
    int valdeci = 0;
    int i;

    for (i = CODAGE_NB_BITS - 1; i >= 0; i--)
    {
        if (tab_bits[i] == 1)
        {
            valdeci += pow(2, CODAGE_NB_BITS - 1 - i);
        }
    }

    return valdeci;
}
