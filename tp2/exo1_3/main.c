#include <stdio.h>

#define NMAX 100


int calcul_det(&tab,n)
{
    int i=0;
    float det=0;
    if(n==1){
        return LUIMEME;
    }
    else
    {
        for(i=0;i<n;i++){
            if(i%1==0){
               calcul_det+=calcul_det(,n-1);
            }
            else{
                calcul_det-=calcul_det(,n-1);
            }
        }
    }
}
int main(){
    float matrice [3][3]={0};
    printf("Determinant = %f\n",calcul_det(,3));
    return 0;
}
