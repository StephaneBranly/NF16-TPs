#include <stdio.h>
int main(){
    long int a;
    do
    {
        printf("\nDonnez la valeur de a\n");
        scanf("%ld", &a);
    }while(a>=0);

    printf("Programme fini\n");
    return 0;
}
