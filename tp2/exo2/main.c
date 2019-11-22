#include <stdio.h>
#include <time.h>
#include <math.h>

#define NMAX 60

typedef struct Un_Tableau_Entier{
    int tableau[NMAX];
    int ncase;
} Un_Tableau_Entier;

typedef struct{
    char liste[20][60];
    int nitem;
}menu;

typedef struct tonneau{
    float d, D, L;
    char contenance[10];
}tonneau;


float calcul_volume(tonneau* tableau){
    float volume;
    volume = 3.14159*tableau->L*(tableau->d/2+2/3*(tableau->D/2-tableau->d/2))*2;
    return volume;
}
int main(){
    tonneau montonneau;
    scanf("%f",&montonneau.d);
    scanf("%f",&montonneau.D);
    scanf("%f",&montonneau.L);

    printf("Resultat trouve : %f",calcul_volume(&montonneau));
    return 0;
}
