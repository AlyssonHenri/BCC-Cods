#include <stdio.h>

int main(int argc, char const *argv[])
{
    float numero, numeroMa=0, numeroMe=9999999;
    while (1)
    {
        scanf("%f", &numero);
        if (numero==0)
        {
            printf("programa encerrado\n");
            if (numeroMe=9999999)
            {
                numeroMe=0;
            }
            break;
        }
        if (numero<0)
        {
            printf("Valor invalido\n");
            if (numeroMe=9999999)
            {
                numeroMe=0;
            }
            
            break;
        }
        if (numero<numeroMe)
        {
            numeroMe=numero;
        }
        if (numero>numeroMa)
        {
            numeroMa=numero;
        }
        
    }
    printf("o maior numero digitado e: %.2f\n",numeroMa);
    printf("o menor numero digitado e: %.2f",numeroMe);
    

    return 0;
}
