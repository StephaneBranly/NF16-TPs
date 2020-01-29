#include"Ex1.h"

void empiler(Pile *pile,int valeur)
{
    Element* new_element;
    new_element = malloc(sizeof(Element));
    new_element->nombre = valeur;
    new_element->suivant = *pile;
    *pile = new_element;
}

int depiler(Pile *pile)
{
    Element* dep_element = *pile;
    if(dep_element != NULL){
        int valeur=dep_element->nombre;
        *pile=dep_element->suivant;
        free(dep_element);
        return valeur;
    }
    else return NULL;
}

void afficher(Pile pile)
{
    Element* actu_element = pile;
    while(actu_element != NULL){
        printf("\n-Element : %d",actu_element->nombre);
        actu_element=actu_element->suivant;
    }
}

void echanger(Pile *pile)
{
    Element* prem_element = *pile;
    Element* pere_element = *pile;
    Element* dern_element = *pile;
    if(*pile!=NULL){
        while(dern_element->suivant != NULL){
            pere_element = dern_element;
            dern_element = dern_element->suivant;
        }
        dern_element->suivant = prem_element->suivant;
        pere_element->suivant = prem_element;
        prem_element->suivant = NULL;
        *pile = dern_element;
    }
}
