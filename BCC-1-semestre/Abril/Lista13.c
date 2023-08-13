#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int idade, qtd1 = 0, qtd2 = 0, qtd3 = 0, qtd4 = 0;
    float peso, peso1 = 0, peso2 = 0, peso3 = 0, peso4 = 0;

    for(int i = 0; i < 15; i++){

        printf("Digite sua idade: ");
        scanf("%i", &idade);
        printf("Digite seu peso: ");
        scanf("%f", &peso);

        if((idade >= 1) && (idade <= 10)){
            peso1 += peso;
            qtd1++;
        }else if((idade >= 11) && (idade <= 20)){
            peso2 += peso;
            qtd2++;
        }else if((idade >= 21) && (idade <= 30)){
            peso3 += peso;
            qtd3++;
        }else if(idade >= 31){
            peso4 += peso;
            qtd4++;
        }

    }

    printf("Média dos pesos: 1 a 10 anos - %.2f\n", (peso1/qtd1));
    printf("Média dos pesos: 11 a 20 anos - %.2f\n", (peso2/qtd2));
    printf("Média dos pesos: 21 a 30 anos - %.2f\n", (peso3/qtd3));
    printf("Média dos pesos: acima de 31 anos - %.2f\n", (peso4/qtd4));


    return 0;
}