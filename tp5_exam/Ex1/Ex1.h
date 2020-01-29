#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element* suivant;
};

typedef Element* Pile;

void empiler(Pile *pile,int valeur);
int depiler(Pile *pile);
void afficher(Pile pile);
void echanger(Pile *pile);
