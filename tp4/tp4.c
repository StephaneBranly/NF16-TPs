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

    printf("| Creation du noeud dans la memoire\n");
    return Nouveau_noeud;
}

/* Fonction 2 */
void ajouter_noeud(T_Arbre* arb, T_Noeud *noeud){
    printf("| Ajout d'un noeud\n");
    T_Arbre abis=*arb;
    T_Noeud * pere=*arb;
    int t=0;
    if (*arb==NULL)
        (*arb)=noeud;
    else{
        while((abis!=NULL) && (t!=1)){
            pere=abis;
            if(noeud->I.mini >= abis->I.mini){  // CLEF G du nouveau noeud supérieure à CLEF G du noeud actuel
                if(abis->I.maxi >= noeud->I.mini){ // Verification de non chevauchement deplacement vers la droite
                    printf("| Votre reservation est impossible, les dates chevauchent sur une autre reservation\n");
                    t=1;
                }
                else
                    abis=abis->d;
            }

            else if(noeud->I.mini <= abis->I.mini){  // CLEF G du nouveau noeud inférieure à CLEF G du noeud actuel
                if(abis->I.mini <= noeud->I.maxi){ // Verification de non chevauchement deplacement vers la gauche
                    printf("| Votre reservation est impossible, les dates chevauchent sur une autre reservation\n");
                    t=1;
                }
                else
                    abis=abis->g;
            }
        }
        if(noeud->I.mini>pere->I.maxi)
            pere->d=noeud;
        else if(noeud->I.maxi<pere->I.mini)
            pere->g=noeud;
        if(t!=1)
            printf("| Le noeud a bien ete ajoute\n");
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
    printf("| Le noeud recherche n'a pas pu etre trouve...\n");
    return NULL;
}


/* Fonction 4 */
 void Supp_noeud(T_Arbre* abr ,T_Inter intervalle, int Id_entreprise){
    T_Noeud* Noeud_a_sup = recherche(*abr ,intervalle, Id_entreprise);

    if(Noeud_a_sup != NULL){ // Le noeud existe bien dans l'arbre
        T_Noeud* Noeud_Parcours;
        T_Noeud* Noeud_Pere;
        T_Noeud* Noeud_Fils;
        Noeud_Parcours = *abr;
        Noeud_Pere = *abr;
        Noeud_Fils = *abr;

        while(Noeud_Parcours != Noeud_a_sup){ // On parcours l'arbre tant que nous sommes sur un noeud de l'arbre
            Noeud_Pere = Noeud_Parcours;
            if(Noeud_Parcours->I.mini < intervalle.mini) // On compare la clef inférieure de l'intervalle, on va soit sur le fils gauche, soit sur le fils droit
                Noeud_Parcours = Noeud_Parcours->d;
            else
                Noeud_Parcours = Noeud_Parcours->g;
        }

        if(Noeud_Parcours->d != NULL && Noeud_Parcours->g != NULL){ // Cas ou il y a 2 fils
            Noeud_Parcours=Noeud_Parcours->g;
            while(Noeud_Parcours->d!=NULL)
                Noeud_Parcours=Noeud_Parcours->d;
            Supp_noeud(abr,Noeud_Parcours->I,Noeud_Parcours->ID_ent);
            if(Noeud_Pere->I.mini > Noeud_Parcours->I.mini) // On doit le rattacher en tant que fils gauche du père
                Noeud_Pere->g = Noeud_Parcours;
            else                                            // On doit le rattacher en tant que fils droit du père
                Noeud_Pere->d = Noeud_Parcours;

            Noeud_Parcours->g = Noeud_a_sup->g;
            Noeud_Parcours->d = Noeud_a_sup->d;

            if(Noeud_a_sup==*abr) // Cas où on supprimer la racine
                *abr=Noeud_Parcours;
        }
        else{  // Cas ou il y a entre 0 et 1 fils
            if(Noeud_Parcours->d != NULL) // On rebranche au fils droit
                Noeud_Fils = Noeud_Parcours->d;
            else                          // On rebranche au fils gauche
                Noeud_Fils = Noeud_Parcours->g;

            if(Noeud_Pere->I.mini > Noeud_Parcours->I.mini) // On doit le rattacher en tant que fils gauche du père
                Noeud_Pere->g = Noeud_Fils;
            else                                            // On doit le rattacher en tant que fils droit du père
                Noeud_Pere->d = Noeud_Fils;

            if(Noeud_a_sup==*abr) // Cas où on supprimer la racine
                *abr=Noeud_Fils;


        }
        printf("| Le noeud a correctement ete detache\n");
    } else {
        printf("| Le noeud n'existe pas, il n'a donc pas pu etre supprime...\n");
    }

 }

 /* Fonction 5 */
 void modif_noeud(T_Arbre abr , T_Inter intervalle,int Id_entreprise,T_Inter Nouvelntervalle){
    T_Noeud* Noeud_a_modif=recherche(abr,intervalle,Id_entreprise); // Recherche du noeud dans l'abre
    if (Noeud_a_modif!=NULL){
        Supp_noeud(&abr,intervalle,Id_entreprise); // Detachement du noeud de l'arbre
        Noeud_a_modif->I.mini = Nouvelntervalle.mini; // Modification de l'intervalle du noeud
        Noeud_a_modif->I.maxi = Nouvelntervalle.maxi;
        ajouter_noeud (&abr, Noeud_a_modif); // rattachement du noeud dans l'arbre
        printf("| Le noeud a bien ete modifie\n");
    }
    else
        printf("| Le noeud n'a pas pu etre modifie\n");
 }

 /* Fonction 6 */
void affiche_abr(T_Arbre abr){ // Affichage de manière récursive
    if(abr!=NULL){
        if(abr->g != NULL)
            affiche_abr(abr->g);
        printf("| ID_Entr:%d -- [%d,%d]\n",abr->ID_ent, abr->I.mini, abr->I.maxi);
        if(abr->d != NULL)
            affiche_abr(abr->d);
    }
}

 /* Fonction 7 */
void affiche_entr(T_Arbre abr,int Id_entreprise ){ // Affichage de manière récursive
    if(abr!=NULL){
        if(abr->g != NULL)
            affiche_entr(abr->g,Id_entreprise);
        if(abr->ID_ent==Id_entreprise)
            printf("| ID_Entr:%d -- [%d,%d]\n",abr->ID_ent, abr->I.mini, abr->I.maxi);
        if(abr->d != NULL)
            affiche_entr(abr->d,Id_entreprise);
    }
}
