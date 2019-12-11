#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Intervalle {
    int mini;
    int maxi;
};

typedef struct Intervalle T_Inter;

struct Noeud{
    T_Inter I;
    int ID_ent;
    struct Noeud *g;
    struct Noeud *d;
};

typedef struct Noeud T_Noeud;
typedef T_Noeud* T_Arbre;



/* Declaration des fonctions */
T_Noeud* creer_noeud(int ,T_Inter); // Fonction 1
void ajouter_noeud(T_Arbre*, T_Noeud*); // Fonction 2
T_Noeud* recherche(T_Arbre ,T_Inter,int); // Fonction 3
void Supp_noeud(T_Arbre*,T_Inter, int); // Fonction 4
void modif_noeud(T_Arbre ,T_Inter,int,T_Inter); // Fonction 5
void affiche_abr(T_Arbre); // Fonction 6
void affiche_entr(T_Arbre ,int ); // Fonction 7
T_Arbre creer_abr(); // Fonction 8
void detruire_arbre(T_Arbre*); // Fonction 9


int verif_date(int, int ); // Fonction Bonus
