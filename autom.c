/**
 * @file autom.c
 * @author ANCE
 * @brief
 * @version 0.1
 * @date 2024-01-16
 *
 * @copyright Copyright (c) 2024
 *
 */
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

// allouer de la mémoire pour un nouvel automate
/**
 * @brief
 *
 * @param automate
 */
void creerAutomate (Automate*automate){
  int i,j;

  printf("Quel est le nombre d'état?\n" );
  scanf("%d", &(automate->nbE));

  printf("Quel est le nombre de symboles?\n" );
  scanf("%d", &(automate->nSy));

  printf("Quel est le nombre de transistions ?");
  scanf("%d", &(automate->transition));

  //alloction de la memoire pour les lignes
  /**
   * @brief
   *
   */
  automate->mat=(int***)calloc(automate->nbE,sizeof(int));

   //alloction de la memoire pour les colones
    for ( i = 0; i < automate->nbE; i++) {

     automate->mat[i]=(int**)calloc(automate->nbE,sizeof(int));
     }

          for ( i = 0; i < automate->nbE; i++) {

                    for (j = 0; j < automate->nSy; j++) {
                      automate->mat[i][j]=(int*)calloc(automate->nSy,sizeof(int));
                              }
                    }

  };

  //créer un Automate
  /**
   * @brief
   *
   * @return Automate
   */
Automate nouvelAutomate(){
  Automate monAutomate;
  creerAutomate(&monAutomate);
  saisirtransition(&monAutomate);
  return monAutomate ;
  }

//remplir les champs de l'automate
/**
 * @brief
 *
 * @param automate
 */
void remplirAutomate(Automate*automate){
  int i, j,z;

  for ( i = 0; i <automate->nbE; i++) {
      for (j=0;j <automate->nSy; j++) {
          for (z = 0; z < automate->nbE; z++) {
          printf("valeur de mat[q%d][a%d][q%d]\n", i,j,z);
          scanf("%d", &(automate->mat[i][j][z]));
                        }
       }
  }


};
//afficher l'Automate
/**
 * @brief
 *
 * @param automate
 */
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

/**
 * @saisir un les transistion
 *
 * @param automate
 */
 void saisirtransition(Automate *automate) {
    int i, from, symbole, to;

    printf("Saisie les transitions :\n");

    for (i = 0; i < automate->transition; ++i) {
        printf("Transition %d:\n", i + 1);

        printf("État de départ : ");
        scanf("%d", &from);

        printf("Symbole : ");
        scanf("%d", &symbole);

        printf("État d'arrivée : ");
        scanf("%d", &to);

        // Vérification des limites des états et symboles
        if (from >= 0 && from < automate->nbE && to >= 0 && to < automate->nbE &&
            symbole >= 0 && symbole < automate->nSy) {

            automate->mat[from][symbole][to] = 1;
        } else {
            printf("Erreur : État ou symbole hors des limites\n");
            --i; // Retour à la transition précédente
        }
    }
}


/**
 * @Fonction pour importer un automate depuis un fichier
 * 
 * @param nomFichier 
 * @param automate 
 * @return int 
 */
int importerAutomate(const char *nomFichier, Automate *automate) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 0; // Échec de l'ouverture du fichier
    }

    // Lecture des informations de l'automate depuis le fichier
    fscanf(fichier, "%d %d %d", &(automate->nbE), &(automate->nSy), &(automate->transition));

    // Allocation de la mémoire pour la matrice de transitions
    automate->mat = (int ***)calloc(automate->nbE, sizeof(int **));
    for (int i = 0; i < automate->nbE; i++) {
        automate->mat[i] = (int **)calloc(automate->nSy, sizeof(int *));
        for (int j = 0; j < automate->nSy; j++) {
            automate->mat[i][j] = (int *)calloc(automate->nbE, sizeof(int));
        }
    }

    // Lecture des valeurs de la matrice depuis le fichier
    for (int i = 0; i < automate->nbE; i++) {
        for (int j = 0; j < automate->nSy; j++) {
            for (int k = 0; k < automate->nbE; k++) {
                fscanf(fichier, "%d", &(automate->mat[i][j][k]));
            }
        }
    }

    fclose(fichier);
    return 1; // Succès de l'importation
}

/**
 * @Fonction pour sauvegarder un automate dans un fichier
 * 
 * @param nomFichier 
 * @param automate 
 * @return int 
 */
int sauvegarderAutomate(const char *nomFichier, Automate *automate) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 0; // Échec de l'ouverture du fichier
    }

    // Écriture des informations de l'automate dans le fichier
    fprintf(fichier, "%d %d %d\n", automate->nbE, automate->nSy, automate->transition);

    // Écriture des valeurs de la matrice dans le fichier
    for (int i = 0; i < automate->nbE; i++) {
        for (int j = 0; j < automate->nSy; j++) {
            for (int k = 0; k < automate->nbE; k++) {
                fprintf(fichier, "%d ", automate->mat[i][j][k]);
            }
            fprintf(fichier, "\n"); // Nouvelle ligne après chaque ligne de symboles
        }
    }

    fclose(fichier);
    return 1; // Succès de la sauvegarde
}


//liberer mémoire de la liste
/**
 * @brief
 *
 * @param tete
 */
void libererListe(Noeud tete) {
    Noeud courant = tete;
    while (courant != NULL) {
        Noeud temp = courant;
        courant = courant->suivant;
        free(temp);
    }
}

// Fonction qui vérifier un mot
/**
 * @brief
 *
 * @param automate
 * @param mot
 * @return int
 */
int verifierMot( Automate* automate, Noeud mot){
  int etatcourant = 0; // État initial
  //int i = 0;
  Noeud courant = mot;


  while (courant !=NULL){

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
      //aucune transistions
      return 0; // mot non reconnu
    }
    etatcourant = etatsuivant;
    //++i;
    courant= courant -> suivant;
  }
  for (int k = 0; k < automate->nbE; k++) {
      if (etatcourant == automate->nbE-1){
        printf("mot reconnu\n");

        return 1; //mot reconnu
      }
  }
  printf("mot non reconnu \n");
  libererListe(mot);
  return 0; //mot non reconnu
}


/**
 * @verifie si un automate est complet
 * 
 * @param automate 
 * @return int 
 */
int estAutomateComplet(Automate *automate) {
    // Parcourir chaque état et chaque symbole
    for (int etat = 0; etat < automate->nbE; etat++) {
        for (int symbole = 0; symbole < automate->nSy; symbole++) {
            // Vérifier s'il existe une transition définie pour chaque combinaison
            int transitionTrouvee = 0;
            for (int etatSuivant = 0; etatSuivant < automate->nbE; etatSuivant++) {
                if (automate->mat[etat][symbole][etatSuivant] == 1) {
                    transitionTrouvee = 1;
                    break;
                }
            }
            // Si aucune transition n'est trouvée, l'automate n'est pas complet
            if (!transitionTrouvee) {
                return 0;
            }
        }
    }
    // Si toutes les combinaisons ont une transition, l'automate est complet
    return 1;
}

    /**
     * @Fonction pour rendre un automate complet
     * 
     * @param automate 
     */
void rendreAutomateComplet(Automate *automate) {
        // Parcourir chaque état et chaque symbole
        for (int etat = 0; etat < automate->nbE; etat++) {
            for (int symbole = 0; symbole < automate->nSy; symbole++) {
                // Si aucune transition n'est définie, ajouter une transition vers un état arbitraire
                int transitionTrouvee = 0;
                for (int etatSuivant = 0; etatSuivant < automate->nbE; etatSuivant++) {
                    if (automate->mat[etat][symbole][etatSuivant] == 1) {
                        transitionTrouvee = 1;
                        break;
                    }
                }
                // Si aucune transition n'est trouvée, ajouter une transition vers l'état 0
                if (!transitionTrouvee) {
                    automate->mat[etat][symbole][0] = 1;
                }
            }
        }
    }

// Fonction qui vérifie si l'automate est déterministe
/**
 * @brief 
 * 
 * @param automate 
 * @return int 
 */
int estAutomateDeterministe(Automate *automate) {
    // Parcourir chaque état
    for (int etat = 0; etat < automate->nbE; etat++) {
        // Parcourir chaque symbole
        for (int symbole = 0; symbole < automate->nSy; symbole++) {
            // Compter le nombre de transitions pour l'état et le symbole donnés
            int nombreTransitions = 0;
            for (int etatSuivant = 0; etatSuivant < automate->nbE; etatSuivant++) {
                if (automate->mat[etat][symbole][etatSuivant] == 1) {
                    nombreTransitions++;
                }
            }
            // Si le nombre de transitions est supérieur à 1, l'automate n'est pas déterministe
            if (nombreTransitions > 1) {
                return 0;
            }
        }
    }
    // L'automate est déterministe
    return 1;
}

typedef struct {
    int *ensemble;
    int taille;
} EnsembleEtats;

/**
 * initialise la structure des états
 * 
 * @param ensemble 
 */
void initialiserEnsemble(EnsembleEtats *ensemble) {
    ensemble->ensemble = NULL;
    ensemble->taille = 0;
}

void ajouterEtat(EnsembleEtats *ensemble, int etat) {
    ensemble->ensemble = realloc(ensemble->ensemble, (ensemble->taille + 1) * sizeof(int));
    ensemble->ensemble[ensemble->taille] = etat;
    ensemble->taille++;
}

void libererEnsemble(EnsembleEtats *ensemble) {
    free(ensemble->ensemble);
    ensemble->ensemble = NULL;
    ensemble->taille = 0;
}

void fermetureEpsilon(const Automate *automate, EnsembleEtats *fermeture, int etat) {
    ajouterEtat(fermeture, etat);

    for (int i = 0; i < automate->nbE; i++) {
        if (automate->mat[etat][automate->nSy - 1][i] == 1) {  // Dernier symbole représente l'epsilon
            fermetureEpsilon(automate, fermeture, i);
        }
    }
}

/**
 * @fonction qui rend un automate déterministe
 * 
 * @param automate 
 * @return Automate 
 */
Automate rendreDeterministe(const Automate *automate) {
    Automate deterministe;

    deterministe.nbE = 0;
    deterministe.nSy = automate->nSy - 1;  // Ignorer le symbole epsilon
    deterministe.transition = 0;
    deterministe.mat = NULL;

    EnsembleEtats *ensembles = (EnsembleEtats *)malloc(sizeof(EnsembleEtats));
    initialiserEnsemble(&ensembles[0]);
    fermetureEpsilon(automate, &ensembles[0], 0);

    for (int i = 0; i < deterministe.nbE; i++) {
        for (int j = 0; j < deterministe.nSy; j++) {
            EnsembleEtats nouvelEnsemble;
            initialiserEnsemble(&nouvelEnsemble);

            for (int k = 0; k < ensembles[i].taille; k++) {
                int etatCourant = ensembles[i].ensemble[k];
                for (int l = 0; l < automate->nbE; l++) {
                    if (automate->mat[etatCourant][j][l] == 1) {
                        fermetureEpsilon(automate, &nouvelEnsemble, l);
                    }
                }
            }

            int ensembleExiste = 0;
            for (int k = 0; k < deterministe.nbE; k++) {
                if (nouvelEnsemble.taille == ensembles[k].taille) {
                    int memeEnsemble = 1;
                    for (int l = 0; l < nouvelEnsemble.taille; l++) {
                        if (nouvelEnsemble.ensemble[l] != ensembles[k].ensemble[l]) {
                            memeEnsemble = 0;
                            break;
                        }
                    }
                    if (memeEnsemble) {
                        ensembleExiste = 1;
                        deterministe.mat[i][j][k] = 1;
                        break;
                    }
                }
            }

            if (!ensembleExiste) {
                deterministe.nbE++;
                ensembles = realloc(ensembles, deterministe.nbE * sizeof(EnsembleEtats));
                initialiserEnsemble(&ensembles[deterministe.nbE - 1]);
                for (int k = 0; k < nouvelEnsemble.taille; k++) {
                    ajouterEtat(&ensembles[deterministe.nbE - 1], nouvelEnsemble.ensemble[k]);
                }
                deterministe.mat = realloc(deterministe.mat, deterministe.nbE * sizeof(int **));
                deterministe.mat[deterministe.nbE - 1] = (int **)calloc(deterministe.nSy, sizeof(int *));
                for (int k = 0; k < deterministe.nSy; k++) {
                    deterministe.mat[deterministe.nbE - 1][k] = (int *)calloc(deterministe.nbE, sizeof(int));
                }
                deterministe.mat[i][j][deterministe.nbE - 1] = 1;
            }

            libererEnsemble(&nouvelEnsemble);
        }
    }

    for (int i = 0; i < deterministe.nbE; i++) {
        libererEnsemble(&ensembles[i]);
    }
    free(ensembles);

    return deterministe;
}

/**
 * @liberation de la mémoire
 * 
 * @param automate 
 */
void supprimerAutomate(Automate*automate){
    // Libérer la mémoire allouée pour la matrice de transitions
    for (int i = 0; i < automate->nbE; i++) {
        for (int j = 0; j < automate->nSy; j++) {
            free(automate->mat[i][j]);
        }
        free(automate->mat[i]);
    }
    free(automate->mat);

    // Remettre à zéro les informations de l'automate
    automate->nbE = 0;
    automate->nSy = 0;
    automate->transition = 0;
}
