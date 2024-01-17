/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-01-16
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "liste.c"



int main(int argc, char const *argv[]) {
   
    Automate monAutomate;
    Noeud mot = NULL;
    int choix;
    char nomFichier[50];

    printf("Bienvenue dans le programme d'automates!\n");

    do {
        printf("\n----- Menu -----\n");
        printf("1. Créer un nouvel automate\n");
        printf("2. Importer un automate depuis un fichier\n");
        printf("3. Afficher l'automate\n");
        printf("4. Sauvegarder l'automate dans un fichier\n");
        printf("5. Vérifier si l'automate est complet\n");
        printf("6. Rendre l'automate complet\n");
        printf("7. Vérifier si l'automate est déterministe\n");
        printf("8. Rendre l'automate déterministe\n");
        printf("9. Vérifier un mot\n");
        printf("0. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                monAutomate = nouvelAutomate();
                printf("Automate créé avec succès.\n");
                break;

            case 2:
                printf("Entrez le nom du fichier à importer : ");
                scanf("%s", nomFichier);
                if (importerAutomate(nomFichier, &monAutomate)) {
                    printf("Importation réussie.\n");
                } else {
                    printf("Échec de l'importation.\n");
                }
                break;

            case 3:
                afficherAutomate(&monAutomate);
                break;

            case 4:
                printf("Entrez le nom du fichier pour sauvegarder l'automate : ");
                scanf("%s", nomFichier);
                sauvegarderAutomate(nomFichier, &monAutomate);
                printf("Automate sauvegardé avec succès.\n");
                break;

            case 5:
                if (estAutomateComplet(&monAutomate)) {
                    printf("L'automate est complet.\n");
                } else {
                    printf("L'automate n'est pas complet.\n");
                }
                break;

            case 6:
                rendreAutomateComplet(&monAutomate);
                printf("L'automate est maintenant complet.\n");
                break;

            case 7:
                if (estAutomateDeterministe(&monAutomate)) {
                    printf("L'automate est déterministe.\n");
                } else {
                    printf("L'automate n'est pas déterministe.\n");
                }
                break;

            case 8:
                monAutomate = rendreDeterministe(&monAutomate);
                printf("Automate rendu déterministe avec succès.\n");
                break;

            case 9:
                if (mot == NULL) {
                    
                    printf("Entrez un mot à vérifier : ");
                     
                    mot = saisirListe();
                    int resultat = verifierMot(&monAutomate, mot);
                    libererListe(mot); // Libérer le mot précédent
                    if (resultat) {
                        printf("Le mot est reconnu.\n");
                    } else {
                        printf("Le mot n'est pas reconnu.\n");
                    }
                } else {
                    printf("Veuillez d'abord créer un automate et un mot.\n");
                }
                break;

            case 0:
                supprimerAutomate(&monAutomate);
                printf("Automate supprimé. Au revoir!\n");
                break;

            default:
                printf("Option invalide.\n");
                break;
        }

    } while (choix != 0);

    return 0;
}


