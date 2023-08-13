#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int idade, somaIdades = 0, quantidade;
    while (1){
        printf("Digite a idade: ");
        scanf("%i", &idade);

        if (idade == 0){
            break;
        }
        
        somaIdades += idade;
        quantidade++;
    }
    
    printf("Media das idades: %.2f\n", (float)somaIdades/quantidade);

    return 0;
}