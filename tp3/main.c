#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "tp3.h"
int DATE=20191108;

int main(){
    printf("A2019 - NF16 - TP3 Listes chainees\n");
    printf("D'AMECOURT Hortense - BRANLY Stephane\n\n");
    printf("Date actuelle : %d\n\n",DATE);
    bool continuer=true;
    int choix;
    float prix;
    int date_block = 0;
    T_Block* adresse_block = NULL;
    int idCompte, idCompte2;
    float montant;
    char description[100];
    BlockChain bc = NULL;
    bc = ajouterBlock(bc);

    while(continuer==true){
        printf("\n|------------------------ -----   ----     ---     --      - \n|");
        printf("\n|  Veuillez choisir dans le menu:\n|");
        printf("\n|  (1) Afficher la liste des blocs de la BlockChain");
        printf("\n|  (2) Afficher toutes les transactions d'un bloc");
        printf("\n|  (3) Afficher toutes les transactions du jour pour un etudiant");
        printf("\n|  (4) Afficher l'historique pour un etudiant");
        printf("\n|  (5) Crediter un compte");
        printf("\n|  (6) Payer un repas");
        printf("\n|  (7) Transferer des EATCoins entre deux etudiants");
        printf("\n|  (8) Quitter");
        printf("\n|  (9) Passer au jour suivant\n|");
        printf("\n|------------------------ -----   ----     ---     --      - \n| >");

        scanf("%d",&choix);
        printf("|\n");
        switch(choix){
            case 1: //Afficher la liste des blocs de la BlockChain
                Tout_Afficher(bc);
                break;
            case 2: //Afficher toutes les transactions d’un bloc
                printf("|  Veuillez indiquer la date ou vous voulez afficher les transactions :\n| >");
                scanf("%d",&date_block);
                adresse_block=RechercherBlock(date_block,bc);
                if(adresse_block!=NULL)
                    AfficherTransactionsBlock(*adresse_block);
                else
                    printf("| Il n existe pas de block avec cette date...\n|");
                break;
            case 3: //Afficher toutes les transactions du jour pour un étudiant
                printf("|  Veuillez rentrer l ID a 4 chiffres de l etudiant :\n| >");
                scanf("%d",&idCompte);
                if (verif_ID(idCompte)==0){
                    printf("| Il y a une erreur avec l'id du compte. Veuillez recommencer. \n");
                    break;
                }
            AfficherTransactionEtudiantBlock(idCompte,*bc);
            break;
            case 4: //AFficher l’historique pour un étudiant
                printf("|  Veuillez rentrer l ID a 4 chiffres de l etudiant :\n| >");
                scanf("%d",&idCompte);
                if (verif_ID(idCompte)==0){
                    printf("| Il y a une erreur avec l'id du compte. Veuillez recommencer. \n");
                    break;
                }
                consulter(idCompte, bc);
                break;
            case 5: // Créditer un compte
                printf("|  Veuillez rentrer l'ID a 4 chiffres du compte a crediter :\n| >");
                scanf("%d",&idCompte);
                if (verif_ID(idCompte)==0){
                    printf("| Il y a une erreur avec l'id du compte. Veuillez recommencer. \n");
                    break;
                }
                printf("|  Veuillez rentrer le montant :\n| >");
                scanf("%f",&montant);
                printf("|  Veuillez rentrer une description :\n| >");
                scanf("%s",&description);
                crediter(idCompte,montant,description,bc);
                break;
            case 6: // Payer un repas
                printf("|  Veuillez rentrer l'ID a 4 chiffres du compte a debiter :\n| >");
                scanf("%d",&idCompte);
                if (verif_ID(idCompte)==0){
                    printf("| Il y a une erreur avec l'ID du compte. Veuillez recommencer. \n|");
                }
                else
                            payer_repas(idCompte, bc);
                break;
            case 7: // Transférer des EATCoins entre deux étudiants
                printf("|  Veuillez rentrer l'ID a 4 chiffres du compte à prelever :\n| >");
                scanf("%d",&idCompte);
                if (verif_ID(idCompte)==0){
                    printf("| Il y a une erreur avec l'id du compte. Veuillez recommencer. \n|");
                }
                else{
                    printf("|  Veuillez rentrer l'ID du compte à crediter :\n| >");
                    scanf("%d",&idCompte2);
                    if (verif_ID(idCompte2)==0){
                        printf("| Il y a une erreur avec l'id du compte. Veuillez recommencer. \n|");
                    }
                    else {
                        printf("|  Veuillez rentrer le montant du transfert :\n| >");
                        scanf("%f",&montant);
                        printf("|  Veuillez rentrer une description :\n| >");
                        scanf("%s",&description);
                        if(transfert(idCompte, idCompte2, montant, description, bc))
                            printf("| La transaction a correctement ete effectuee");
                        else
                            printf("| La transaction n'a pas pu etre effectuee");
                    }
                }
                break;
            case 8: // QUITTER
                continuer=false;
                Tout_Liberer(bc);
                break;
            case 9: // Passer au jour suivant
                DATE++;
                printf("|  La nouvelle date est : %d\n|", DATE);
                bc=ajouterBlock(bc);
            break;
            default: printf("|  Ce choix n'est pas dans la liste...\n|");
        }
    }
    return 0;
}

