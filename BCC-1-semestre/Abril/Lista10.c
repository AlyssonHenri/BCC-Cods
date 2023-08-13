#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int numero, somaPar=0, primoSoma=0;
    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero: ");
        scanf("%i", &numero);


        if (numero % 2 == 0)
        {
            somaPar+=numero;
        }
        else
        {
            for (int z = 2; z <= numero; z++)
            {
                if (numero % z == 0 && numero==z)
                {
                    primoSoma+=numero;                
                }
            }
        }
    }
    printf("A soma dos numeros primos e: %i\n", primoSoma);
    printf("A soma dos numeros pares e: %i\n", somaPar);   

    return 0;
}
