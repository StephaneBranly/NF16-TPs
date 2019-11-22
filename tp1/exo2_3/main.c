#include <stdio.h>
int main(){
    char a='a';
    do
    {
        printf("\n\nQuelle table de multiplication voulez-vous, tapez 0  (zero) pour sortir ?\n");
        scanf("%c", &a);
        if(!(a>='0' && a<= '9'))
        {
            printf("Ce n'est pas dans les possibilites du programme");
        }
    }while(!(a>='0' && a<= '9'));

    if(a>'0' && a<='9')
    {
        printf("Impression de la table de multiplication de %c\n", a);
        for(int i=1;i!=10;i++)
        {
            printf("%d * %c = %d\n", i, a, i*(a-'0'));
        }
    }
    printf("\n\nProgramme fini\n");
    return 0;
}
