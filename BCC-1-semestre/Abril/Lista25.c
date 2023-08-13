#include <stdio.h>

int main(void)
{
    int tipo, cod;
    float valor, mes, total = 0, juros = 0;

    while (1){
        printf("Digite o código: ");
        scanf("%i", &cod);
        if (cod <= 0){
            break;
        }
        printf("Digite o tipo: ");
        scanf("%i", &tipo);
        printf("Digite o valor: ");
        scanf("%f", &valor);

        if(tipo == 1){
            mes = 1.015;
        }else if(tipo == 2){
            mes = 1.02;
        }else if(tipo == 3){
            mes = 1.04;
        }else{
            printf("Tipo Inválido!");
            mes = 0;
        }

        total += mes * valor;
        juros += (mes-1) * valor;
        
    }

    printf("Total: %.2f\n", total);
    printf("Total de Juros: %.2f\n", juros);


    return 0;
}