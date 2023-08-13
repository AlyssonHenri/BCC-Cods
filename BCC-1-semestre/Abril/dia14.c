#include <stdio.h>
#include <stdlib.h>

#define VET 3

void scan(int vetor[]);
void print(int vetor[]);
int soma(int vetor[]);

int main(void)
{
    int vetor[VET];
    scan(vetor);
    print(vetor);
    printf("Soma dos elementos do vetor: %i\n", soma(vetor));
    return 0;
}


void scan(int vetor[])
{
    for (int i = 0; i < VET; i++)
    {
        printf("Digite o numero: ");
        scanf("%i", &vetor[i]);
    }
}

void print(int vetor[])
{
    for (int i = 0; i < VET; i++)
    {
        printf("%i\n", vetor[i]);
    }
}

int soma(int vetor[])
{
    int somaV = 0 ;
    for (int i = 0; i < VET; i++)
    {
        somaV=+vetor[i];
    }
    return somaV;

}



