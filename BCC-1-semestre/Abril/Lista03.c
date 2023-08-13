#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int entrada, quantidade=0, faixa1=0, faixa2=0, faixa3=0, faixa4=0, faixa5=0;
    
    do
    {
        printf("Digite uma idade: (0 para finalizar)");
        scanf("%i", &entrada);

        if (entrada<=15 && entrada!=0)
        {
            faixa1++;
        }
        if (entrada>16 && entrada<=30)
        {
            faixa2++;
        }
        if (entrada>31 && entrada<=45)
        {
            faixa3++;
        }
        if (entrada>46 && entrada<=60)
        {
            faixa4++;
        }
        if (entrada>60)
        {
            faixa5++;
        }
        if (entrada!=0)
        {
            quantidade++;
        }    
    } while (entrada>0);
    
    printf("----------------------------------------------------------\n");
    printf("quantidade de pessoas na primeira faixa %i\n", faixa1);
    printf("quantidade de pessoas na segunda faixa %i\n", faixa2);
    printf("quantidade de pessoas na terceira faixa %i\n", faixa3);
    printf("quantidade de pessoas na quarta faixa %i\n", faixa4);
    printf("quantidade de pessoas na quinta faixa %i\n", faixa5);

    printf("----------------------------------------------------------\n");
    printf("Porcentagem de pessoas na 1 faixa: %i\n", ((faixa1*100)/quantidade));
    
    printf("Porcentagem de pessoas na 5 faixa: %i\n", ((faixa5*100)/quantidade));
    printf("----------------------------------------------------------\n");
    
    return 0;
}
