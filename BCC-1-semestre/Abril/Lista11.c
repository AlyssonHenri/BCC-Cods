#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //Faça um programa que receba o valor de um carro e mostre uma tabela com os seguintes dados: preço 
    //final, quantidade de parcelas e valor da parcela

    float carro, valorP=0, precoF=0, acressimo=0;
    int parcela=0;
    char pagamento;

    printf("Digite o valor do carro: ");
    scanf("%f", &carro);
    do
    {
        printf("Deseja realizar pagamento a vista(V) ou parcelado(P): ");
        fflush(stdin);
        pagamento = tolower( getchar());
        if (pagamento=='p')
        {
            do
            {
                printf("Em quantas parcelas deseja pagar (6, 12, 18, 24, 30, 36, 42, 48, 54, 60): ");
                scanf("%i", &parcela);
                if (parcela!=6 && parcela!=12 && parcela!=24 && parcela!=30 && parcela!=42 && parcela!=48 && parcela!=54 && parcela!=60)
                {
                    printf("---ENTRADA INVALIDA---\n");
                }
            } while (parcela!=6 && parcela!=12 && parcela!=24 && parcela!=30 && parcela!=42 && parcela!=48 && parcela!=54 && parcela!=60);
            
            acressimo = (parcela / 2);
            precoF = carro + (acressimo * (carro / 100));
            valorP = precoF / parcela;            
            
        }

        if (pagamento=='v')
        { 
           precoF = (carro - (20 * (carro / 100))); 
        }
        
        if (pagamento!='p' && pagamento!='v')
        {
            printf("---ENTRADA INVALIDA---\n");
        }          
        
    } while (pagamento!='v' && pagamento!='p');
    
    printf("---------------------------------------------------------------\n");
    printf("|Preco final| |Quantidade de parcelas| |Valor de cada parcela |\n");
    printf("  %.2f          %i                       %.2f                  \n", precoF, parcela, valorP);
    printf("---------------------------------------------------------------\n");
   
    return 0;
}
