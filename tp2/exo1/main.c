//Question 1

#include <stdio.h>
#include <time.h>
#include <math.h>

/*int factorielle(n){
    if(n==1) return 1;
    return factorielle(n-1)*n;
}

int main(){
    int i=5, fact=1;
    printf("Maniere recursive : %d  \n",factorielle(i));

    for(i=5;i!=0;i--){
        fact=fact*i;
    }
    printf("Maniere iterative : %d",fact);
    return 0;
}
*/

/*
int fibo1(int n){
    int un;
    if(n<=2){
        un=1;
    }
    else{
        un=fibo1(n-1) + fibo1(n-2);
    }
    return un;
}
*/

int fibo2(int n){
    int un;

    if(n<2){
        un=1;
    }
    else{
        if(n%2==0){
            n=n/2;
            un = pow(fibo2(n),2) + 2*fibo2(n)*fibo2(n-1);
        }
        else{
            n=(n+1)/2;
            un = pow(fibo2(n),2) + pow(fibo2(n+1),2);
        }
    }
    return un;
}

int main(){
    int i;
    scanf("%d",&i);
    printf("Resultat trouve : %d",fibo2(i));
    return 0;
}
