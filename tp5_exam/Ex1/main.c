#include"Ex1.h"

int main()
{
    printf("### Branly Stephane - NF16 ###\n\n");
    Pile p=NULL;

    ///Test empiler
    printf("Test empiler\n");
    for(int i=1;i<=20;i++)
        empiler(&p,i);
    afficher(p);

    ///Test depiler
    printf("\nTest depiler\n");
    for(int i=0;i<10;i++)
        if(p!=NULL) printf("%d\n",depiler(&p));

    ///Test echange
    printf("\nTest echange\n");
    echanger(&p);
    afficher(p);

    return 0;
}
