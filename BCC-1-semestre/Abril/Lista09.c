#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]){

    int idade, somaIdades, qtdeCondUm = 0, qtdePessoasDT;
    float peso, altura;

    for (int i = 1; i <= 10; i++){
        printf("Digite sua idade: ");
        scanf("%i", &idade);
        printf("Digite seu peso: ");
        scanf("%f", &peso);
        printf("Digite sua altura: ");
        scanf("%f", &altura);

        somaIdades += idade;

        if((peso>90) && (altura<1.50)){
            qtdeCondUm++;
        }

        if (((idade >= 10) && (idade <= 30)) && (altura > 1.90)){
            qtdePessoasDT++;
        }

        printf("%i pessoas restantes para registro.\n", (10-i));
    }

    printf("Média das idades: %.2f\n", ((float)somaIdades/10));
    printf("Quantidade de pessoas com peso superior a 90 kg e altura inferior a 1,50 metro: %i\n", qtdeCondUm);
    printf("Porcentagem de Pessoas entre 10 e 30 anos que medem mais de 1,90 m: %.2f%%\n", (qtdePessoasDT/10));

    
    return 0;
}