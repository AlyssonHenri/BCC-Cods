#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a, b, c, d, x1, x2;
    printf("Insira os valores de 'a' 'b' e 'c'");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
if (a != 0){
    d = (b*b) - 4 * a * c;
    if (d<0){
        printf("Nao e possivel calcular");
    }else{
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
            if (x1!=x2){
                printf("%2.f", x1);
                printf("%2.f", x2);
            }else{printf("%2.f", x1);}
    }    
}else{
    printf ("Valor 'a' invalido");
}
    return 0;
}