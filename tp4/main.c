#include "tp4.h"

int main(){
    T_Arbre abr;
    abr=NULL;
    int ID;
    T_Inter Inter;
    T_Noeud* Noeud;
    printf("A2019 - NF16 - TP4 Arbres binaires\n\n");
    bool continuer=true;
    int choix;
    while(continuer==true){
        printf("\n\n------------------------\n");
        printf("Veuillez choisir dans le menu:\n|");
        printf("\n|- 1 - Creer un ABR");
        printf("\n|- 2 - Afficher toutes les reservations");
        printf("\n|- 3 - Ajouter une reservation");
        printf("\n|- 4 - Modifier une reservation");
        printf("\n|- 5 - Supprimer");
        printf("\n|- 6 - Afficher les reservations d'une entreprise");
        printf("\n|- 7 - Supprimer l'arbre");
        printf("\n|- 8 - Quitter");
        printf("\n------------------------\n");

        scanf("%d",&choix);
        printf("\n\n");
        switch(choix){
            case 1:
                break;
            case 2:
                printf("AFFICHAGE DE L ABRE\n");
                affiche_abr(abr);
                break;
            case 3:
                printf("| Rentrez l'ID de l'entreprise :\n|");
                scanf("%d",&ID);
                printf("| Rentrez la borne inferieure de l'intervalle :\n|");
                scanf("%d",&Inter.mini);
                printf("| Rentrez la borne superieure de l'intervalle :\n|");
                scanf("%d",&Inter.maxi);
                Noeud = creer_noeud(ID, Inter);
                ajouter_noeud(&abr,Noeud);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                continuer=false;
                break;
        }
    }
    return 0;
}

