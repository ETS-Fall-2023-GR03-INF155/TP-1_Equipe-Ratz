/********************************************************************************************************/
/*  Fichier : CODAGE_NUMERIQUE.H                                                                        */
/*  Auteurs : BOIRET Romain   BOIR71300401		                                                        */
/*            LENGA  Amorella LENA91330301                                                              */
/*  Date de cr�ation : <04 / 11 / 2023>                                                                 */
/*                                                                                                      */
/*  Ce module contient les fonctions nec�ssaires aux conversions d�cimal vers binaire et inversement.	*/
/********************************************************************************************************/
#pragma once
#ifndef _test_h_
#define _test_h_

#define CODAGE_NB_BITS 8 	//Nombre maximal de bits.

/*******************************************************************************/
/*                   D�CLARATION DES FONCTIONS PUBLIQUES                       */
/*******************************************************************************/

/******** INVERSER_TAB_BITS ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Fonction qui inverse les "nb_bits/2" premi�res valeurs d'un tableau de bits: le premier bit devient la dernier (et inversement), le deuxi�me devient l'avant dernier, etc. Cette fonction est utilis�e par la fonction "codage_dec2bin". 
//Retour de 1 si l�op�ration a �t� effectu�e et 0 sinon("nb_bits" trop gros).
int inverser_tab_bits(int tab_bits[], int nb_bits);     
// tab_bits[]	: Tableaux contenant les bits.
// nb_bits      : Contient le nombre de bits qui constitue le tableaux.


/******** CODAGE_DEC2BIN ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Traduit un nombre d�cimal en binaire. Le r�sultat est stock� dans le tableau "resultat" et le nombre de bits utilis�s est renvoy�. 
//fonction renvoie le nombre de bits qui a �t� n�cessaire pour coder le nombre en binaire. Si le nombre requiert plus que CODAGE_NB_BITS, la fonction renvoie 0.
int codage_dec2bin(int nombre, int resultat[]);        
// nombre		: Contient le nombre d�cimal qui va �tre converti en nombre binaire.
// resultat[]	: Contient le nombre binaire qui a �t� converti.


/******** AFFICHER_TAB_BITS ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Affiche un tableau contenant des bits � l'�cran. Cette fonction est utilis�e pour des fins de test. 
void afficher_tab_bits(const int tab_bits[], int nb_bits);
// tab_bits[]	: Tableaux contenant les bits.
// nb_bits      : Contient le nombre de bits qui constitue le tableaux.


/******** CODAGE_BIN2DEC ******/ // <--[fonction publique].
//Auteurs : BOIRET Romain & LENGA Amorella.
//Traduit un tableau de bits, repr�sentant un nombre en binaire, vers sa repr�sentation d�cimale. La valeur d�cimale est retourn�e par la fonction.
//Retourne la valeur d�cimale.
int codage_bin2dec(const int tab_bits[]);
// tab_bits[]	: Tableaux contenant les bits.

#endif