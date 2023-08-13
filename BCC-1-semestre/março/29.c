#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numero=0; 
    double fatorial=0;

    printf("digite o numero: ");
    scanf("%i", &numero);
    
    if (numero<0)
    {
        printf("não possivel calcular\n");
        return 0;
    }
    if (numero==0 || numero==1)
    {
        printf("o fatorial e: 1");
        return 0;
    }
       

    fatorial=numero;
    for (int i = 1; i < numero-1; i++)
    {
        fatorial=fatorial*(numero-i);
    }
    printf("o fatorial e: %.2f", fatorial);

    return 0;
}
