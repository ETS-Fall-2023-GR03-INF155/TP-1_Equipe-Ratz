/************************************************************************************************************************************************************************************/
/*  Fichier : CODAGE_NUMERIQUE.C																						                                                            */
/*  Auteurs : BOIRET Romain   BOIR71300401																		                                                                    */
/*	          LENGA  Amorella LENA91330301																		                                                                    */
/*  Date de création : <04 / 11 / 2023>																                                                                                */
/*                                                                                                                                                                                  */
/*  Ce module contient les définitions des fonctions suivantes : "inverser_tab_bits()", "codage_dec2bin()", "afficher_tab_bits", "codage_bin2dec".                                  */
/************************************************************************************************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "codage_numerique.h"

/***************************************************************************************/
/*                             DEFINITION DES FONCTIONS                                */
/***************************************************************************************/

/*==========================================================*/
//Fonction "inverser_tab_bits" - Fonction qui inverse les "nb_bits/2" premières valeurs d'un tableau de bits: le premier bit devient la dernier (et inversement), le deuxième devient l'avant dernier, etc. Cette fonction est utilisée par la fonction "codage_dec2bin". 
int inverser_tab_bits(int tab_bits[], int nb_bits)
{
    int i; //Variable temporaire pour la boucle for.
    int temp; //Variable temporaire qui permet de stocker la valeur d'une position du tableau tab_bits[].

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
//Fonction "codage_dec2bin" - Le résultat est stocké dans le tableau "resultat" et le nombre de bits utilisés est renvoyé. Le codage du nombre décimal doit se faire en un maximum de CODAGE_NB_BITS (fixée à 8).
int codage_dec2bin(int nombre, int resultat[])
{
    int compt = 0; //Compter chaque fois pour renvoyer le nombre de bits nécessaire pour ce nombre.
    int bin; //Permet destocker le résultat de la division euclidienne du nombre par 2.
    int inverse; //Permet de stocker la valeur retourné par le fonction "inverser_tab_bits".
    int i; //Variable temporaire pour la boucle for.

    //stocker résultat dans le tableau, jusquà 8 bits

    while (nombre > 0)
    {
        bin = nombre % 2; //fais le modulo de 2
        nombre /= 2;
        resultat[compt] = bin; //ajoute ce résultat dans la position
        compt++; 
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
//Fonction "afficher_tab_bits" - Affiche un tableau contenant des bits à l'écran. Cette fonction est utilisée pour des fins de test. 
void afficher_tab_bits(const int tab_bits[], int nb_bits)
{
    int i; //Variable temporaire pour la boucle for.

    for (i = 0; i < nb_bits; i++)
    {
        printf("%d", tab_bits[i]);
    }
}

/*==========================================================*/
//Fonction "codage_bin2dec" - Traduit un tableau de bits, représentant un nombre en binaire, vers sa représentation décimale. La valeur décimale est retournée par la fonction. On présume ici que le tableau de bits est de taille exactement égale à CODAGE_NB_BITS et que le bit de poids fort est à la case 0 du tableau.
int codage_bin2dec(const int tab_bits[])
{
    int valdeci = 0; //Permet de stocker la valeur décimale du nombre binaire reçu dans le tableau en paramètre.
    int i; //Variable temporaire pour la boucle for.

    for (i = CODAGE_NB_BITS - 1; i >= 0; i--)
    {
        if (tab_bits[i] == 1)
        {
            valdeci += (int)pow(2, CODAGE_NB_BITS - 1 - i);
        }
    }

    return valdeci;
}
