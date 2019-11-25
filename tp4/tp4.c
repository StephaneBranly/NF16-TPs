#include "tp4.h"

/* Fonction 1 */
T_Noeud* creer_noeud(int Id_entreprise,T_Inter intervalle) {
    T_Noeud* Nouveau_noeud;
    Nouveau_noeud = malloc(sizeof(T_Noeud)); // Allocation dynamique de mémoire

    Nouveau_noeud->d = NULL;
    Nouveau_noeud->g = NULL;
    Nouveau_noeud->ID_ent = Id_entreprise;

    Nouveau_noeud->I.mini = intervalle.mini;
    Nouveau_noeud->I.maxi = intervalle.maxi;

    return Nouveau_noeud;
}

/* Fonction 2 */
void ajouter_noeud(T_Arbre *arb, T_Noeud *noeud){
    T_Arbre abis=arb;
    int t=0;
    if (*arb==NULL)
        (*arb)=noeud;
    else{
        while(((abis->d!=NULL)||(abis->g != NULL))&&(t!=1)){
            if (((noeud->I.mini>abis->I.mini)&&(noeud->I.mini<abis->I.maxi))||((noeud->I.maxi>abis->I.mini)&&(noeud->I.maxi<abis->I.maxi))){
                printf("Votre réservation est impossible, les dates chevauchent sur une autre réservation");
                t=1;
            }
            else if(noeud->I.mini>abis->I.maxi)
                abis=abis->d;
            else if(noeud->I.maxi<abis->I.mini)
                abis=abis->g;
        }
        if(noeud->I.mini>abis->I.maxi)
            abis->d=noeud;
        else if(noeud->I.maxi<abis->I.mini)
            abis->g=noeud;
    }
}




/* Fonction 3 */
T_Noeud* recherche(T_Arbre abr ,T_Inter intervalle,int Id_entreprise){
    T_Noeud* Noeud_Parcours;
    Noeud_Parcours = abr;

    while(Noeud_Parcours != NULL){ // On parcours l'arbre tant que nous sommes sur un noeud de l'arbre
        if(Noeud_Parcours->ID_ent == Id_entreprise){ // Vérification qu'il s'agit de la bonne ID entreprise
            if((Noeud_Parcours->I.mini == intervalle.mini) && (Noeud_Parcours->I.maxi == intervalle.maxi)){ // Vérification qu'il s'agit du bon intervalle
                return Noeud_Parcours;
            }
        }

        if(Noeud_Parcours->I.mini < intervalle.mini) // On compare la clef inférieure de l'intervalle, on va soit sur le fils gauche, soit sur le fils droit
            Noeud_Parcours = Noeud_Parcours->d;
        else
            Noeud_Parcours = Noeud_Parcours->g;
    }

    return NULL;
}


/* Fonction 4 */
 void Supp_noeud(T_Arbre abr ,T_Inter intervalle, int Id_entreprise){
    T_Noeud* Noeud_a_sup = recherche(abr ,intervalle, Id_entreprise);

    if(Noeud_a_sup != NULL){ // Le noeud existe bien dans l'arbre
        printf("| Conditions noeuds, à supp...\n");
    } else {
        printf("| Le noeud n'existe pas, il n'a donc pas pu etre supprime...\n");
    }

 }


 /* Fonction 6 */
void affiche_abr(T_Arbre arb){
    if(arb!=NULL){
        if(arb->g != NULL)
        affiche_abr(arb->g);
        printf("| ID : %d    : [%d,%d]\n",arb->ID_ent, arb->I.mini, arb->I.maxi);
        if(arb->d != NULL)
            affiche_abr(arb->d);
    }
}




/* Fonctions bonus */
