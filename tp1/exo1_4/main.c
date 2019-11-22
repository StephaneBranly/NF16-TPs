#include <stdio.h>
int main(){
    float a, b;
    printf("Donnez la temperature en degre Fahrenheit a\n");
    scanf("%f", &a);
    b=(5./9.)*(a-32.);
    printf("Conversion en degre Celsius !\n");
    printf("%f", b);

    return 0;
}
