#include"Ex2.h"

void insertion(Abr *a,int cle)
{
    Noeud* pere_noeud = *a;
    Noeud* parcours_noeud = *a;

    Noeud* nouv_noeud;
    nouv_noeud=malloc(sizeof(Noeud));
    nouv_noeud->cle=cle;
    nouv_noeud->fd=NULL;
    nouv_noeud->fg=NULL;

    if(*a == NULL){
        *a = nouv_noeud;
    }
    else{
        while(parcours_noeud!=NULL){
        pere_noeud = parcours_noeud;
        if(cle > parcours_noeud->cle){
            parcours_noeud = parcours_noeud->fd;
        }
        else{
            parcours_noeud = parcours_noeud->fg;
        }
        }
        if(cle > pere_noeud->cle){
            pere_noeud->fd = nouv_noeud;
        }
        else{
            pere_noeud->fg = nouv_noeud;
        }
    }
}

void afficher(Abr a)
{
    if(a!=NULL){
        afficher(a->fg);
        printf("\n-Noeud : %d",a->cle);
        afficher(a->fd);
    }
}

int nombre_feuilles(Abr a)
{
    if(a!=NULL){
        if(a->fg==NULL && a->fd==NULL) return 1;
        else return nombre_feuilles(a->fg) + nombre_feuilles(a->fd);
    }
    else return 0;
}

int nombre_noeuds_internes(Abr a)
{
    if(a!=NULL){
        if(a->fg==NULL && a->fd==NULL) return 0;
        else return 1 + nombre_noeuds_internes(a->fg) + nombre_noeuds_internes(a->fd);
    }
    else return 0;
}
