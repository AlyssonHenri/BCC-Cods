#include <stdlib.h>
#include <stdio.h>

int main(void)
{   
    int idade = 1, soma = 0;
    float altura, somaAlturas;
    while (idade > 0){
        printf("Digite uma idade: ");
        scanf("%i", &idade);
        if (idade > 0){
            printf("Digite uma altura: ");
            scanf("%f", &altura);
            if (idade > 50){
                soma++;
                somaAlturas += altura;
            } 
        }
    }

    printf("Média das alturas %.2f\n", (somaAlturas/soma));
    return 0;
}