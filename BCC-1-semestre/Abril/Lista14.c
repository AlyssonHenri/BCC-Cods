#include <stdio.h>
#include <stdlib.h>

int main(void){

    int idade, opiniao, otimo, otimoNumero = 0, regular = 0, bom = 0;

    for (int i = 0; i < 15; i++){
        printf("Digite sua idade: ");
        scanf("%i", &idade);
        printf("Digite sua opinião: ");
        scanf("%i", &opiniao);

        if (opiniao == 3){
            otimo += idade;
            otimoNumero++;
        }else if (opiniao == 2){
            regular++;
        }else if (opiniao == 1){
            bom++;
        }else{
            printf("Opiniao Invalida! Nao sera contabilizada.\n");
        }
        
        printf("Registros Restantes: %i\n\n", (15-(i+1)));
    }

    printf("Media das idades das pessoas que responderam atimo: %.2f\n", (otimo/(float)otimoNumero));
    printf("Quantidade de pessoas que responderam regular: %i\n", regular);
    printf("Porcentagem de pessoas que responderam bom, entre todos: %.2f%%", (((float)bom/15) * 100));
    
    return 0;
}