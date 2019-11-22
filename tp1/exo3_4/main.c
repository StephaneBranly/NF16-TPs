#include <stdio.h>
int main(){
    int matrice1[3][2]={{1,2},{3,4},{5,6}},matrice2[2][3]={{1,2,3},{4,5,6}},matrice_resu[3][3];

    for(int i=0;i!=3;i++)
    {
        for(int j=0;j!=3;j++)
        {
            matrice_resu[i][j]=
            matrice1[i][0]*matrice2[0][j]+
            matrice1[i][1]*matrice2[1][j];
            printf("%d  ",matrice_resu[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/
