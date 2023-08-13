#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int voto = 1, qtdeCandUm = 0, qtdeCandDois = 0, qtdeCandTres = 0, qtdeCandQuatro = 0, qtdeNulo = 0, qtdeBranco = 0, totalVotos;
    float porcNulos, porcBrancos;
    while (voto != 0){
        printf("Digite o seu voto: ");
        scanf("%i", &voto);
        switch (voto)
        {
        case 1:
            qtdeCandUm++;
            break;
        case 2:
            qtdeCandDois++;
            break;
        case 3:
            qtdeCandTres++;
            break;
        case 4:
            qtdeCandQuatro++;
            break;
        case 5:
            qtdeNulo++;
            break;
        case 6: 
            qtdeBranco++;
            break;
        case 0:
            break;
        default:
            printf("Opção Inválida!");
            break;
        }
    }
    
    totalVotos = qtdeCandUm + qtdeCandDois + qtdeCandTres + qtdeCandQuatro + qtdeNulo + qtdeBranco;
    
    printf("Total de Votos para o candidato 1: %i\n", qtdeCandUm);
    printf("Total de Votos para o candidato 2: %i\n", qtdeCandDois);
    printf("Total de Votos para o candidato 3: %i\n", qtdeCandTres);

    printf("Total de Votos Nulos: %i\n", qtdeNulo);
    printf("Total de Votos em Branco: %i\n\n", qtdeBranco);

    printf("Porcentagem de Nulos: %.2f%%\n", ((float)qtdeNulo/totalVotos)*100);
    printf("Porcentagem de Brancos: %.2f%%\n", ((float)qtdeBranco/totalVotos)*100);

    return 0;
}