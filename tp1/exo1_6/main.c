#include <stdio.h>
int main(){
    int a;
    printf("Donnez une valeur de a\n");
    scanf("%d",a);
    a=(int)a % 2;
    printf("\n\n %d",a);
    return 0;
}
