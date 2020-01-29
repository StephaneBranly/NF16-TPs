#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud Noeud;
struct Noeud
{
    int cle;
    Noeud* fg;
    Noeud* fd;
};

typedef Noeud* Abr;

void insertion(Abr *a,int cle);
void afficher(Abr a);
int nombre_feuilles(Abr a);
int nombre_noeuds_internes(Abr a);
