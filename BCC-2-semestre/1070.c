#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtd, entrada, in=0, out=0;

    scanf("%i", &qtd);
    for (int i = 0; i < qtd; i++)
    {
        scanf("%i", &entrada);
        if (entrada>=10 && entrada<=20)
        {
            in++;
        }else{
            out++;
        }
    }
    printf("%i in\n%i out\n", in, out);
    return 0;
}