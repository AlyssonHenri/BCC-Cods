#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int idade, i, cinquenta = 0, pesoMenor = 0;
    float altura, peso, alturaTotal = 0, porcPesoInf;

    for (i = 0; i < 5; i++){
        printf("Digite a sua idade: ");
        scanf("%i", &idade);
        printf("Digite a sua altura em metros: ");
        scanf("%f", &altura);
        printf("Digite a seu peso em kgs: ");
        scanf("%f", &peso);

        if(idade > 50){
            cinquenta++;
        }
        if((idade >= 10) && (idade <= 20)){
            alturaTotal += altura;
        }
        if(peso < 40){
            pesoMenor++;
        }
        printf("Número de pessoas restantes: %i\n", (4-i));
        
    }

    porcPesoInf = ((float)pesoMenor/5) * 100;


    printf("Quantidade de Pessoas com mais de 50 anos: %i\n", cinquenta);
    printf("Média das alturas das pessoas com idade entre 10 e 20 anos: %.2f\n", (alturaTotal/5));
    printf("Porcentagem de pessoas com peso inferior a 40 kg: %.1f%%\n", porcPesoInf);

    

    return 0;
}