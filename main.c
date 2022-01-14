#include <stdio.h>
#include <stdlib.h>
#include "etudiant.h"
#include <string.h>
//TP IN213
/*
Ceci est la fonction main permettant de tester l'implementation
 du programme de gestion des absences
L'auteur de ce mini programme est Okono Mehitang Wilfried Loïc
*/
int main()
{
    printf("____________________BIENVENU____________________ \n");
    menu(); //L'appel de cette fonction lancera le menu
    printf("____________________________Au revoir_____________________________ \n\n");

    return 0;
}


//Implémentation du programme menu
void menu(){
    char option[3] = "NON";
    while((strcmp(option, "OUI") !=0) && (strcmp(option, "oui") !=0)){  //while pour repéter le menu tant que l'utilisateur n'entre pas OUI ou oui au moment indiquer
        int choixMenu;
        printf("\n\n  ==================  Menu ==================\n\n");
        printf("1 - Ajouter des etudiant dans le groupe.\n");
        printf("2 - Rechercher un etudiant.\n");
        printf("3 - Afficher tous les etudiants deja enregistrer.\n");
        printf("4 - Determiner le nombre d'etudiant enregistrer.\n");
        printf("5 - Ajouter des absents.\n");
        printf("6 - Determiner le nombre d'absence d'un etudiant donnee.\n");
        printf("7 - Liste des absents.\n");
        printf("8 - Quitter le programme.\n ");
        printf("Entrez votre choix ?  \t");
        scanf("%d", &choixMenu);
        printf("\n");

        switch(choixMenu)
        {
            case 1:
                addNewStudent();
                decision(option);
                break;
            case 2:
                printf("Entrez le matricule de l'etudiant que vous rechercher :");
                char matEtudiant[8];
                scanf("%s", matEtudiant);
                char* deci="NON";
                if(rechercheEtudiant(matEtudiant)==1)//pour afficher OUI ou NON comme resultat de la recherche
                    deci="OUI";
                printf("L'etudiant de matricule %s est-il present : %s\n", matEtudiant, deci);
                decision(option);
                break;
            case 3:
                afficheGroupeEtudiant();
                decision(option);
                break;
            case 4:
                printf("Le nombre d'etudiant est %d etudiant(s)\n", nombreEtudiant());
                decision(option);
                break;
            case 5:
                saveAbsence();
                printf("Save reussi");
                decision(option);
                break;
            case 6:
                printf("Entrez le matricule de l'etudiant:\t");
                char matEtud[8];
                scanf("%s", matEtud);
                int i = nbrAbsence(matEtud);
                printf("%s a : %d absence(s).\n", matEtud, i);
                decision(option);
                break;
            case 7:
                listAbsence();
                decision(option);
                break;
            case 8:
                decision2(option);
                break;
            default:
                decision(option);
                break;

        }
    }

    printf("\nMerci d'avoir utiliser notre mini-programme. :)\n");
    printf("\n  =========================  Arret =========================\n\n");
}
