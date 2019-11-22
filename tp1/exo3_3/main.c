#include <stdio.h>
int main(){
    char tableau[3][4];
    for(int i=0;i!=3;i++)
    {
        for(int j=0;j!=4;j++)
        {
            tableau[i][j]=12+j+4*i;
            printf("%d  ",tableau[i][j]);
        }
        printf("\n");
    }
    return 0;
}
