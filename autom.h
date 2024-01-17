/**
 * @file autom.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-01-16
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdlib.h>
#include <stdio.h>

#ifndef AUTOM_H
    #define   AUTOM_H
#endif
struct Automate{
  //nb d'etat et nb de symbole et la matrice
   int nbE;
   //nb de symbole
   int nSy;
   //nb de transition
   int transition;
  // matrice à 3 dimensions
   int ***mat;
};
typedef struct Automate Automate;


struct Noeud{
  int valeur;
  struct Noeud *suivant;
};
typedef struct Noeud *Noeud;

/**
 * @brief
 *
 * @return Automate
 */
Automate nouvelAutomate();

/**
 * @brief
 *
 * @param automate
 */
void creerAutomate (Automate* automate);

/**
 * @brief
 *
 * @param automate
 */


/**
 * @brief
 *
 * @param automate
 */
void remplirAutomate(Automate* automate);

/**
 * @brief
 *
 * @param automate
 */
void afficherAutomate (Automate* automate);

int sauvegarderAutomate(const char *nomFichier, Automate *automate);

int importerAutomate(const char *nomFichier, Automate *automate);

int estAutomateComplet(Automate *automate);

void rendreAutomateComplet(Automate *automate);

int estAutomateDeterministe(Automate *automate);

Automate rendreDeterministe(const Automate *automate);

/**
 * @brief
 *
 * @param automate
 */
void supprimerAutomate(Automate* automate);

/**
 * @brief
 *
 * @param automate
 */
void saisirtransition(Automate* automate);

/**
 * @brief
 *
 * @param tete
 */
void libererListe(Noeud tete);

/**
 * @brief
 *
 * @param automate
 * @param mot
 * @return int
 */
int verifierMot(Automate* automate, Noeud mot);

/**
 * @brief
 *
 */
/*void copierAutomate(Automate* automate);*/
/**
 * @brief
 *
 * @param tete
 * @param valeur
 * @return Noeud
 */
Noeud ajouterEnTete(Noeud tete, int valeur);

/**
 * @brief
 *
 * @param tete
 */
void affiche( Noeud tete);

/**
 * @brief
 *
 * @param tete
 * @param valeur
 * @return Noeud
 */
Noeud ajouterEnQueue(Noeud tete, int valeur);

/**
 * @brief
 *
 * @param tete
 * @return int
 */
int estVide (Noeud tete);

/**
 * @brief
 *
 * @param tete
 * @return Noeud
 */
Noeud supprimerEnTete(Noeud tete);

/**
 * @brief
 *
 * @return Noeud
 */
Noeud saisirListe();
