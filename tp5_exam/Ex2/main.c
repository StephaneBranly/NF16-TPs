#include"Ex2.h"

int main()
{
    printf("### Branly Stephane - NF16 ###\n\n");
    Abr a=NULL;

    ///test insertion
    printf("Test insertion\n");
    insertion(&a,4);
    insertion(&a,2);
    insertion(&a,6);
    insertion(&a,1);
    insertion(&a,3);
    insertion(&a,5);
    insertion(&a,7);
    afficher(a);

    ///Test nombre fauilles
    printf("\nTest nombre feuilles\n");
    printf("%d\n",nombre_feuilles(a));

    ///Test nombre noeuds internes
    printf("\nTest nombre noeuds internes\n");
    printf("%d\n",nombre_noeuds_internes(a));
}
