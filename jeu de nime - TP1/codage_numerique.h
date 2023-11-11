/********************************************************************************************************/
/*  Fichier : CODAGE_NUMERIQUE.H                                                                        */
/*  Auteurs : BOIRET Romain   BOIR71300401		                                                        */
/*            LENGA  Amorella LENA91330301                                                              */
/*  Date de création : <04 / 11 / 2023>                                                                 */
/*                                                                                                      */
/*  Ce module contient les fonctions necéssaires aux conversions décimal vers binaire et inversement.	*/
/********************************************************************************************************/
#pragma once
#ifndef _test_h_
#define _test_h_

#define CODAGE_NB_BITS 8 	//Nombre maximal de bits.

/*******************************************************************************/
/*                   DÉCLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

/******** INVERSER_TAB_BITS ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Fonction qui inverse les "nb_bits/2" premières valeurs d'un tableau de bits: le premier bit devient la dernier (et inversement), le deuxième devient l'avant dernier, etc. Cette fonction est utilisée par la fonction "codage_dec2bin". 
//Retour de 1 si l’opération a été effectuée et 0 sinon("nb_bits" trop gros).
int inverser_tab_bits(int tab_bits[], int nb_bits);     
// tab_bits[]	: Tableaux contenant les bits.
// nb_bits      : Contient le nombre de bits qui constitue le tableaux.


/******** CODAGE_DEC2BIN ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Traduit un nombre décimal en binaire. Le résultat est stocké dans le tableau "resultat" et le nombre de bits utilisés est renvoyé. 
//fonction renvoie le nombre de bits qui a été nécessaire pour coder le nombre en binaire. Si le nombre requiert plus que CODAGE_NB_BITS, la fonction renvoie 0.
int codage_dec2bin(int nombre, int resultat[]);        
// nombre		: Contient le nombre décimal qui va être converti en nombre binaire.
// resultat[]	: Contient le nombre binaire qui a été converti.


/******** AFFICHER_TAB_BITS ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Affiche un tableau contenant des bits à l'écran. Cette fonction est utilisée pour des fins de test. 
void afficher_tab_bits(const int tab_bits[], int nb_bits);
// tab_bits[]	: Tableaux contenant les bits.
// nb_bits      : Contient le nombre de bits qui constitue le tableaux.


/******** CODAGE_BIN2DEC ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Traduit un tableau de bits, représentant un nombre en binaire, vers sa représentation décimale. La valeur décimale est retournée par la fonction.
//Retourne la valeur décimale.
int codage_bin2dec(const int tab_bits[]);
// tab_bits[]	: Tableaux contenant les bits.

#endif