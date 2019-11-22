#include <stdio.h>
int main(){
    float a, b;
    printf("Donnez la valeur de a\n");
    scanf("%f", &a);
    printf("Donnez le pourcentage\n");
    scanf("%f", &b);
    printf("Pourcentage !\n");
    printf("%f", a*b/100);

    return 0;
}
