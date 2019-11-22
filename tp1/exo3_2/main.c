#include <stdio.h>
int main(){
    char tableau[5];
    for(int i=0;i!=5;i++)
    {
        tableau[i]=4-i;
        printf("%d\n",tableau[i]);
    }
    return 0;
}
