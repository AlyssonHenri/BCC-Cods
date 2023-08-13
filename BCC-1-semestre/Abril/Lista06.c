#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char pagamento;
    float compra, totalV=0.0, totalP=0.0, compraTotal=0.0;

    for (int i = 0; i < 3; i++)
    {
        printf("Insira o valor da compra: ");
        scanf("%f", &compra);
        do
        {   
            printf("Qual forma de pagamento deseja usar, a vista(V) ou a prazo(P): ");
            fflush(stdin);
            pagamento = tolower( getchar());

            if (pagamento=='v')
            {
                totalV+=compra;
            }
            if (pagamento=='p')
            {
                totalP+=compra;
            }
            if (pagamento!='p' && pagamento!='v')
            {
                printf("--ENTRADA INVALIDA---\n");
            }
            
        } while (pagamento!='v' && pagamento!='p');
        compraTotal+=compra;
    }
    printf("Total a pagar a vista: %.2fRS\n", totalV);
    printf("Total a pagar a prazo: %.2fRS\n", totalP);
    printf("Total a pagar: %.2fRS\n", compraTotal);
    printf("primeira prestacao a pagar: %.2f\n", (totalP/3));


    return 0;
}