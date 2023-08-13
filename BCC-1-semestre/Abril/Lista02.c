#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int despesas=200, quantidade=120;
    float ingresso=5.0, lucro;

    printf("|Valor|-|Lucro |-|Quantidade   |\n");
    
    for (ingresso = 5.00; ingresso >= 1.00; ingresso-=0.5, quantidade+=26)
    {        
        lucro = (ingresso * quantidade)-despesas;
        printf("|%.2f |-|%.2f|-|%i Ingressos|\n",ingresso, lucro, quantidade);
    }
    

    return 0;
}
