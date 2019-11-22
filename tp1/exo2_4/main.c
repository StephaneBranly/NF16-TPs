#include <stdio.h>
int main(){
    printf("Donnez un caractere\n");
    switch(getchar())
    {
        case '1':
            printf("Un");
            break;
        case '2':
            printf("Deux");
            break;
        case '3':
            printf("Trois");
            break;
        case '4':
            printf("Quatre");
            break;
        case '5':
            printf("Cinq");
            break;
        case '6':
            printf("Six");
            break;
        case '7':
            printf("Sept");
            break;
        case '8':
            printf("Huit");
            break;
        case '9':
            printf("Neuf");
            break;
        default:
            printf("Autre caractere");
    }
    return 0;
}
