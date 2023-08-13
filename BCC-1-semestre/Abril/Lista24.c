#include <stdio.h>

int main(void){

    int valor, numeroMenor = 0, numeroMaior = 100000000000000;
    
    while(1){
        printf("Digite um valor maior que 0: ");
        scanf("%i", &valor);

        if (valor == 0){
            break;
        }else if (valor > 0){
            if (valor > numeroMenor){
                numeroMenor = valor;
            }
            if (valor < numeroMaior){
                numeroMaior = valor;
            }
        }

    }
        
        
    printf("Menor Valor: %i\n", numeroMaior);
    printf("Maior Valor: %i", numeroMenor);
    
    return 0;
}