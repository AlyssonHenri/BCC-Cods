#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char olhoCor, corCabelos;
    int idade, idadeTotal, qtdeCondUm = 0, azul = 0, ruivaNAOazul = 0, qtdInf = 0;
    float altura, peso, somaIdadeAlturaInf;

    for (int i = 0; i < 6; i++){
        
        printf("Digite sua idade: ");
        scanf("%i", &idade);
        printf("Digite o seu peso: ");
        scanf("%f", &peso);
        printf("Digite sua altura: ");
        scanf("%f", &altura);
        printf("Digite a cor de seus olhos: ");
        scanf(" %c", &olhoCor);
        printf("Digite a cor de seus cabelos: ");
        scanf(" %c", &corCabelos);

        corCabelos = toupper(corCabelos);
        olhoCor = toupper(olhoCor);

        idadeTotal += idade;

        if((idade > 50) && (peso < 60)){
            qtdeCondUm++;
        }
        if (altura < 1.50){
            somaIdadeAlturaInf += idade;
            qtdInf++;
        }
        if (olhoCor == 'A'){
            azul++;
        }
        if ((corCabelos == 'R') && (olhoCor != 'A')){
            ruivaNAOazul++;
        }

    }

    printf("Quantidade de pessoas com idade superior a 50 e peso inferior a 60 kg: %i", qtdeCondUm);
    printf("Média das idades das pessoas com altura inferior a 1,50 m: %f", 
    (somaIdadeAlturaInf/qtdInf));
    printf("Porcentagem de pessoas com olhos azuis: %.2f%%", ( (azul/6) * 100) );
    printf("Quantidade de pessoas ruivas e que não possuem olhos azuis: %i", ruivaNAOazul);


    return 0;
}