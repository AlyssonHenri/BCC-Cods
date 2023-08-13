#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int canal, numPessoas, qtdePessoas = 0, canal4 = 0, canal5 = 0, canal7 = 0, canal12 = 0;

    while(1){

        printf("Digite o número de pessoas na casa: ");
        scanf("%i", &numPessoas);
        printf("Digite o número do canal assistido: ");
        scanf("%i", &canal);

        if ((canal == 4) || (canal == 5) || (canal == 7) || (canal == 12)){
            qtdePessoas += numPessoas;

            if (canal == 4){
                canal4+= numPessoas;
            }else if(canal == 5){
                canal5+= numPessoas;
            }else if(canal == 7){
                canal7+= numPessoas;
            }else if(canal == 12){
                canal12+= numPessoas;
            }
        }else{
            if (canal == 0){
                break;
            }else{
                printf("Canal Invalido Nao sera contabilizado.\n\n");
            }
        }
    }


    printf("Porcentagem de pessoas que viram o canal 4: %.2f\n", ( ((float)canal4 / qtdePessoas) * 100) ) ;
    printf("Porcentagem de pessoas que viram o canal 5: %.2f\n", ( ((float)canal5 / qtdePessoas) * 100) ) ;
    printf("Porcentagem de pessoas que viram o canal 7: %.2f\n", ( ((float)canal7 / qtdePessoas) * 100) ) ;
    printf("Porcentagem de pessoas que viram o canal 12: %.2f\n", ( ((float)canal12 / qtdePessoas) * 100) ) ;

    return 0;
    
}