#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"

int DATE;
/* Fonction 1 */
T_Transaction* ajouterTransaction(int idEtu, float montant, char *descr, T_Transaction *listeTransaction){
    T_Transaction *PremElt;

    char* nouvelle_description_p;
    nouvelle_description_p=malloc(sizeof(descr)); // Allocation dynamique de mémoire pour la description
    strcpy(nouvelle_description_p,descr);

    PremElt=malloc(sizeof(T_Transaction)); // Allocation dynamique de mémoire pour la transaction
    PremElt->idEtu=idEtu;
    PremElt->montant=montant;
    PremElt->descr=nouvelle_description_p;
    PremElt->succ=listeTransaction;
    return PremElt;
}

/* Fonction 2 */
BlockChain ajouterBlock(BlockChain bc){
    T_Block* PremB;
    PremB=malloc(sizeof(T_Block));
    PremB->date=DATE;
    PremB->T_TransactionJ=NULL;
    PremB->succ=bc;
    if (bc==NULL) // On regarde si la blockchain contient déjà au moins un block
        PremB->idBlock=0;
    else
        PremB->idBlock=PremB->succ->idBlock+1;
    return PremB;
}

/* Fonction 3 */
float totalTransactionEtudiantBlock(int idEtu, T_Block b){
    float total=0;
    T_Transaction *TransactionActuelle = b.T_TransactionJ;
    while(TransactionActuelle!=NULL){ // On parcours toutes les transactions du bloc
        if(TransactionActuelle->idEtu==idEtu)
            total+=TransactionActuelle->montant;
        TransactionActuelle = TransactionActuelle->succ;
    }

    return total;
}

/* Fonction 4 */
float soldeEtudiant(int idEtu, BlockChain bc){
    float solde_total=0;
    T_Block* Block_actuel = bc;
    while(Block_actuel!=NULL){ // On parcours tous les blocs de la chainblock
        solde_total+=totalTransactionEtudiantBlock(idEtu, *Block_actuel);
        Block_actuel = Block_actuel->succ;
    }
    return solde_total;
}

/* Fonction 5 */
void crediter(int idEtu, float montant, char *descr, BlockChain bc){
    if(montant<=0){
        printf("| Il faut un montant positif...");

    }
    else{
        bc->T_TransactionJ=ajouterTransaction(idEtu, montant, descr, bc->T_TransactionJ);
        printf("| Compte correctement credite");
    }
}

/* Fonction 6 */
int payer(int idEtu, float montant, char *descr, BlockChain bc){
    if(montant<=0){
        printf("| Il faut un montant positif...");
        return 0;
    }
    else{
        if (soldeEtudiant(idEtu,bc)<montant){
            printf("| Il n'y pas assez d'argent sur le compte...");
            return 0;
        }
        else {
            bc->T_TransactionJ=ajouterTransaction(idEtu, -montant, descr, bc->T_TransactionJ);
            printf("| Compte correctement debite");
            return 1;
        }
    }
}

/* Fonction 7 */
void consulter(int idEtu, BlockChain bc){
    T_Block *Block_actuel = bc;
    int compteur = 0;
    while(Block_actuel!=NULL && compteur<5){ // Parcours des blocks le temps qu'il y a des blocks et qu'il y a moins de 5 transactions affichées
        printf("\n|\n|\n| ###########-bloc-n%d--(%d)-######  ###    ##      #\n| #",Block_actuel->idBlock,Block_actuel->date);
        T_Transaction *TransactionActuelle = Block_actuel->T_TransactionJ;
        while(TransactionActuelle!=NULL && compteur<5){ // Affichage le tant qu'il y a des transactions dans le block est qu'il y a moins de 5 affichées
            if(TransactionActuelle->idEtu==idEtu){
                Afficher_Transaction(TransactionActuelle);
                compteur++;
            }
            TransactionActuelle = TransactionActuelle->succ;
        }
        printf("\n| #########\n|");
        Block_actuel = Block_actuel->succ;
    }
}

/* Fonction 8 */
int transfert(int idSource, int idDestination, float montant, char *descr, BlockChain bc){
    if(montant>soldeEtudiant(idSource,bc) || montant<=0)
        return 0;
    else{
        bc->T_TransactionJ=ajouterTransaction(idSource, -montant, descr, bc->T_TransactionJ);
        bc->T_TransactionJ=ajouterTransaction(idDestination, montant, descr, bc->T_TransactionJ);
        return 1;
    }
}

/* MENU 2 */
T_Block* RechercherBlock(int date, T_Block* bc){
    T_Block* Add_block=NULL;
    T_Block* Block_actuel = bc;
    while(Block_actuel!=NULL && Add_block==NULL){
        if(Block_actuel->date==date)
            Add_block=Block_actuel;
        Block_actuel = Block_actuel->succ;
    }
    return Add_block;
}
void AfficherTransactionsBlock(T_Block b){
    T_Transaction *TransactionActuelle = b.T_TransactionJ;
    printf("\n|\n|\n| ###########-bloc-n%d--(%d)-######  ###    ##      #\n| #",b.idBlock,b.date);
    while(TransactionActuelle!=NULL){ // On parcours toutes les transactions du bloc
        Afficher_Transaction(TransactionActuelle);
        TransactionActuelle = TransactionActuelle->succ;
    }
    printf("\n| #########\n|");
}
/* MENU 3 */
void AfficherTransactionEtudiantBlock(int idEtu, T_Block b){
    T_Transaction *TransactionActuelle = b.T_TransactionJ;
    while(TransactionActuelle!=NULL){ // On parcours toutes les transactions du bloc
        if(TransactionActuelle->idEtu==idEtu)
            Afficher_Transaction(TransactionActuelle);
        TransactionActuelle = TransactionActuelle->succ;
    }
}

/* MENU 6 */
void payer_repas(int idCompte, BlockChain bc){
    char description[100];
    int menu;
    float prix, montant; // Creation d'un menu
    printf("|  Veuillez choisir dans le menu des aliments/boisson:\n|");
    printf("\n|  (1) Soda a 1.1 euros");
    printf("\n|  (2) Menu non vegetarien a 2.5 euros");
    printf("\n|  (3) Menu vegetarien a 2.5 euros");
    printf("\n|  (4) Dessert a 1.5 euros \n| >");
    scanf("%d",&menu);
    switch (menu){
    case 1:
        prix=1.1;
        break;
    case 2:
        prix=2.5;
        break;
    case 3:
        prix=2.5;
        break;
    case 4:
        prix=1.5;
        break;
    default :
        printf("| Il y a une erreur dans votre choix \n|");
        break;
    }
    printf("|  Veuillez rentrer le montant correspondant a votre choix :\n| >");
    scanf("%f",&montant);
    if (montant !=prix){ // Permet de s'assurer que la personne voulait bien cet article, confirmation
        printf("| Il y a une erreur dans le montant saisi. Veuillez recommencer \n|");
    }
    else {
            printf("|  Veuillez rentrer une description :\n| >");
        scanf("%s",&description);
        payer(idCompte,montant,description,bc);
    }
}

/* Fonction bonus */
void Afficher_Transaction(T_Transaction* t){ // Affichage d'une transaction
    printf("\n| #    ###--------------------###");
    printf("\n| #            IDetu : %d",t->idEtu);
    printf("\n| #          Montant : %f",t->montant);
    printf("\n| #      Description : %s",t->descr);
    printf("\n| #    ###--------------------###\n| #");
}
void Tout_Afficher(BlockChain bc){ // Affichage des toutes les transactions avec les blocs : blokchain complete
    T_Block *Block_actuel = bc;
    while(Block_actuel!=NULL){
        printf("|\n|\n| ###########-bloc-n%d--(%d)-######  ###    ##      #\n| #",Block_actuel->idBlock,Block_actuel->date);
        T_Transaction *TransactionActuelle = Block_actuel->T_TransactionJ;
        while(TransactionActuelle!=NULL){
            Afficher_Transaction(TransactionActuelle);
            TransactionActuelle = TransactionActuelle->succ;
        }
        printf("\n| #########\n|");
        Block_actuel = Block_actuel->succ;
    }
}
void Tout_Liberer(BlockChain bc){
    T_Block *Block_actuel = bc;
    T_Block *Block_Prochain = bc;
    T_Transaction *TransactionActuelle = Block_actuel->T_TransactionJ;
    T_Transaction *TransactionProchaine = Block_actuel->T_TransactionJ;
    while(Block_Prochain!=NULL){ // Parcours de tous les blocs
        Block_actuel=Block_Prochain;
        T_Transaction *TransactionActuelle = Block_actuel->T_TransactionJ;
        while(TransactionProchaine!=NULL){ // Parcours de toutes les transactions du block
            TransactionActuelle = TransactionProchaine;
            TransactionProchaine = TransactionActuelle->succ;
            free(TransactionActuelle->descr); // Libératio de la mémoire pour la description mais aussi pour la transaction
            free(TransactionActuelle);
        }
        Block_Prochain = Block_actuel->succ;
        free(Block_actuel);
    }
    printf("\n\n--- L'espace memoire a correctement ete libere ---\n\n");
}
int verif_ID(int id){ // Formalisation des IDs des étudiants
    if ( (1000<=id) && (10000>id))
        return 1;
    else
        return 0;
}
