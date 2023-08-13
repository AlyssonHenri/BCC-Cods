#include <stdio.h>

int main(void)
{
    int menun, numMeses;
    float salario, novoSalario, valorFerias, valorDecimo;
    
    while (menun != 4){
        printf("\nMenu de opçoes:\n\n");
        printf("1. Novo salario\n");
        printf("2. Férias\n");
        printf("3. Décimo terceiro\n");
        printf("4. Sair\n");

        printf("Digite sua opçao: ");
        scanf("%i", &menun);

        switch (menun)
        {
        case 1:
            printf("Digite seu salario: ");
            scanf("%f", &salario);
            novoSalario = salario;
            if (salario < 210){
                novoSalario *= 1.15;
            }else if ((salario >= 210) && (salario <= 600)){
                novoSalario *= 1.10;
            }else if (salario > 600){
                novoSalario *= 1.05;
            }
            printf("Seu novo salario sera de: %.2f\n", novoSalario);
            break;
        case 2:
            printf("Digite seu salario: ");
            scanf("%f", &salario);
            valorFerias = salario + (salario/3);
            printf("Valor das férias: R$ %.2f\n", valorFerias);
            break;
        case 3:
            printf("Digite seu salario: ");
            scanf("%f", &salario);
            printf("Digite a quantidade de meses de trabalho na empresa: ");
            scanf("%i", &numMeses);
            valorDecimo = (salario * numMeses)/12;
            printf("O valor do seu Décimo Terceiro sera de: R$ %.2f\n", valorDecimo);
            break;
        case 4:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opçao Invalida \n");
            break;
        }
    }

    
    return 0;
}