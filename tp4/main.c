#include "tp4.h"

int main(){
    T_Arbre abr;
    abr=NULL;
    int ID;
    T_Inter Inter;
    T_Inter Inter2;
    T_Noeud* Noeud;
    printf("A2019 - NF16 - TP4 Arbres binaires\n\n");
    bool continuer=true;
    int choix;
    while(continuer==true){
        printf("|\n|\n------------------------     ------     ---       --          - \n");
        printf("| -- Veuillez choisir dans le menu --\n|");
        printf("\n|- 1 - Creer un ABR");
        printf("\n|- 2 - Afficher toutes les reservations");
        printf("\n|- 3 - Ajouter une reservation");
        printf("\n|- 4 - Modifier une reservation");
        printf("\n|- 5 - Supprimer une reservation");
        printf("\n|- 6 - Afficher les reservations d'une entreprise");
        printf("\n|- 7 - Supprimer l'arbre");
        printf("\n|- 8 - Quitter");
        printf("\n------------------------     ------     ---       --          - \n| >");

        scanf("%d",&choix);
        printf("|\n|\n");
        switch(choix){

            case 1:
                abr = creer_abr();
                break;
            case 2:
                printf("|\n| -- Afficher toutes les reservations --\n|\n");
                printf("| Voici l'arbre :\n");
                affiche_abr(abr);
                break;
            case 3:
                printf("|\n| -- Ajouter une reservation --\n|\n");
                printf("| Rentrez l'ID de l'entreprise :\n| >");
                scanf("%d",&ID);
                printf("| Rentrez la borne inferieure de l'intervalle :\n| >");
                scanf("%d",&Inter.mini);
                printf("| Rentrez la borne superieure de l'intervalle :\n| >");
                scanf("%d",&Inter.maxi);
                Noeud = creer_noeud(ID, Inter);
                ajouter_noeud(&abr,Noeud);
                break;
            case 4:
                printf("|\n| -- Modifier une reservation --\n|\n");
                printf("| Rentrez l'ID de l'entreprise :\n| >");
                scanf("%d",&ID);
                printf("| Rentrez la borne inferieure de l'intervalle :\n| >");
                scanf("%d",&Inter.mini);
                printf("| Rentrez la borne superieure de l'intervalle :\n| >");
                scanf("%d",&Inter.maxi);
                printf("| Rentrez la borne inferieure du nouvel intervalle :\n| >");
                scanf("%d",&Inter2.mini);
                printf("| Rentrez la borne superieure du nouvel intervalle :\n| >");
                scanf("%d",&Inter2.maxi);
                modif_noeud(abr,Inter,ID,Inter2);
                break;
            case 5:
                printf("|\n| -- Supprimer une reservation --\n|\n");
                printf("| Rentrez l'ID de l'entreprise :\n| >");
                scanf("%d",&ID);
                printf("| Rentrez la borne inferieure de l'intervalle :\n| >");
                scanf("%d",&Inter.mini);
                printf("| Rentrez la borne superieure de l'intervalle :\n| >");
                scanf("%d",&Inter.maxi);
                Noeud = recherche(abr,Inter,ID); // Sauvegarde du noeud pour effectuer un free par la suite
                if(Noeud!=NULL){
                    Supp_noeud(&abr , Inter, ID);
                    free(Noeud);
                    printf("| Le noeud a correctement ete supprime\n");
                }
                else
                    printf("| Le noeud n'a pas pu etre supprime\n");
                break;
            case 6:
                printf("|\n| -- Afficher les reservations d'une entreprise --\n|\n");
                printf("| Rentrez l'ID de l'entreprise :\n| >");
                scanf("%d",&ID);
                printf("| Voici l'arbre pour l'entreprise:\n");
                affiche_entr(abr,ID);
                break;
            case 7:
                detruire_arbre(&abr);
                break;
            case 8:
                continuer=false;
                break;
        }
    }
    return 0;
}



