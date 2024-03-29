#include <stdio.h>
#include <stdlib.h>
#include "autom.h"

/*struct Automate{
  //nb d'etat et nb de symbole et la matrice
   int nbE;
   //nb de symbole
   int nSy;
   //nb de transition
   int transition;
  // matrice à 3 dimensions
   int ***mat;
};
typedef struct Automate Automate;*/ 
//remplir les champs de l'automate
void remplirAutomate(Automate*automate){
  int i, j,z;
  for ( i = 0; i <automate->nbE; i++) {
      for (j=0;j <automate->nSy; j++) {
          for (z = 0; z < automate->nbE; z++) {
          printf("Y a-t-il une transition entre Q%d et Q%d en passant par %d (1 si oui, 0 sinon) ?\n", i, z, j);
          scanf("%d", &(automate->mat[i][j][z]));
                        }
       }
  }
  };
// allouer de la mémoire pour un nouvel automate
Automate creerAutomate (){
  int i,j;
  Automate automate;
  printf("Quel est le nombre d'état?\n" );
  scanf("%d", &automate.nbE);
  printf("Quel est le nombre de symboles?\n" );
  scanf("%d", &automate.nSy);
  printf("Quel est le nombre de transitions ?\n");
  scanf("%d", &automate.transition);
  //alloction de la memoire pour les lignes
  automate.mat=(int***)calloc(automate.nbE,sizeof(int));
	//alloction de la memoire pour les colones
	for ( i = 0; i < automate.nbE; i++) {
		automate.mat[i]=(int**)calloc(automate.nbE,sizeof(int));
	}
	for ( i = 0; i < automate.nbE; i++) {
	    for (j = 0; j < automate.nSy; j++) {
	      automate.mat[i][j]=(int*)calloc(automate.nSy,sizeof(int));
	    }
	}
	remplirAutomate(&automate);
	return automate;
  };

//afficher l'Automate
void afficherAutomate (Automate*automate){
  int i,j,z;
  for( i=0; i< automate->nbE; i++) {
    for( j=0;j<automate->nSy; j++){
       for(z=0; z< automate->nSy; z++){
          if( automate->mat[i][j][z] == 1){
          printf("[Q%d][A%d][Q%d]=[%d]\t", i,j,z, automate->mat[i][j][z] );
             }
         }
    }
      printf("\n");
  }
};
/*
void saisirtransition(Automate*automate){
    int i, from, to, symbole;
    printf("Saisie des transition:\n");
    for ( i = 0; i < automate->transition; i++) {
      printf("Transition %d: \n",i+1 );
      printf(" Etat de départ:");
      scanf("%d", &from );
      printf("Symbole: \n");
      scanf("%d", &symbole);
      printf("Etat d'arrivée:\n");
      scanf("%d", &to);
      // vérifications du nombre des états et symbole
      if (from >=0 && from < automate->nbE && to >=0 && to < automate->nbE &&
      symbole >=0 && symbole < automate->nSy) {
        automate->mat[from][symbole][to]= 1;
      }
      else {
         printf("Erreur: Etat ou symbole hors des limites\n");
         -- i; //retour à la transition précédente
      }
    }
};
*/
//liberer mémoire de la liste
void libererListe(Noeud tete) {
    Noeud courant = tete;
    while (courant != NULL) {
        Noeud temp = courant;
        courant = courant->suivant;
        free(temp);
    }
}
// Fonction qui vérifier un mot
int verifierMot( Automate* automate, Noeud mot){
  int etatcourant = 0; // État initial
  Noeud courant = mot;

  while (courant !=NULL || etatcourant > automate->nbE){
    int symbole = courant -> valeur;
    if( symbole< 0 || symbole >= automate->nSy){
        printf("Erreur : Symbole non reconnu.\n");
        libererListe(mot);
        return 0;
    }
    int etatsuivant = -1;
    // Chercher une transition depuis l'état courant avce le symbole donné
    for (int j = 0; j < automate->nbE; j++) {
      if (automate->mat[etatcourant][symbole][j] == 1){
          etatsuivant = j;
          break;
      }
    }
    if (etatsuivant == -1) {
      //aucune transitions
      return 0; // mot non reconnu
    }
    etatcourant = etatsuivant;
    courant= courant -> suivant;
  }
	if (courant == NULL){
	printf("mot reconnu\n");
 
	return 1; //mot reconnu
	}
 
  printf("mot non reconnu \n");
  libererListe(mot);
  return 0; //mot non reconnu
}

//liberation de la mémoire
void supprimerAutomate(Automate*automate){
   int i,j;
  for (i = 0; i < automate->nbE; i++) {
    for (j = 0; j< automate->nSy; j++) {
        free(automate->mat[i][j]);
    }
    free(automate->mat[i]);
   }
   //free(automate->mat);
};
 
int main(){
	Automate* aef;
	Noeud mot;
	mot->valeur = 1;
	*aef = creerAutomate();
	afficherAutomate(aef);
	verifierMot(aef, mot);
	return 0;
}
