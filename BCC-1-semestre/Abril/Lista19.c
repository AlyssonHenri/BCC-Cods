#include <stdio.h>

int main(void)
{
    char acao;
    float precoV=0, precoC=0, lucro=0, lucroTotal=0;
    int lucroMil=0, lucroDuz=0;

    do
    {
        printf("Digite a letra da acao: ");
        fflush(stdin);
        acao = tolower( getchar());

        printf("Digite o preco de compra: ");
        scanf("%f", &precoC);

        printf("Digite o preco de venda: ");
        scanf("%f", &precoV);

        lucro=precoV-precoC;
        lucroTotal=lucro+lucroTotal;
        
        if (lucro>=0)
        {
            printf("O lucro dessa acao e: %.2f\n", lucro);
        }else if (lucro<0)
        {
            printf("O prejuizo dessa acao foi de: %.2f\n", lucro);
        }
        
        

        if (lucro>1000)
        {
            lucroMil++;
        }
        if (lucro<200)
        {
            lucroDuz++;
        }
        
    } while (acao!='f');

    printf("\nA quantidade de acoes com lucro superior a R$ 1.000,00: %i\n", lucroMil);   
    printf("A quantidade de acoes com lucro inferior a R$ 200,00: %i\n", lucroDuz);
    printf("O lucro total da empresa foi de: %.2f\n", lucroTotal);

    return 0;
}
