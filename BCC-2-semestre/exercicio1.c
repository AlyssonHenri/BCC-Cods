#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[] = {1,2,3,4,5};
    int pedido;

    printf("Digite um numero: ");
    scanf("%i", &pedido);

    printf("%i", vetor[pedido-1]);

    return 0;
}
