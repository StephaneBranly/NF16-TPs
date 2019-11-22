#include <stdio.h>
int main(){
    float a, b;
    float somme;
    printf("Donnez la valeur de a\n");
    scanf("%f", &a);
    printf("Donnez la valeur de b\n");
    scanf("%f", &b);
    somme = a+b;
    printf("La somme de a et b vaut\n");
    printf("%f", somme);

    return 0;
}
