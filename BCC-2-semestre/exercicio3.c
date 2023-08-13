#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define tam 2

typedef struct teste
{
    char nome[30];
    double altura;
}registro;

void ler_menor (registro pessoa [tam]);
void ler_maior (registro pessoa [tam]);

int main()
{
    registro pessoa [tam];

    for (int i = 0; i < tam; i++)
    {
        printf("Insira o nome da pessoa: ");
        scanf("%[^\n]s", pessoa[i].nome);
        fflush (stdin);

        printf("Insira o tamanho da pessoa: ");
        scanf("%lf", &pessoa[i].altura);
        fflush (stdin); 
    }

    
    ler_menor(pessoa);
    ler_maior(pessoa);
    calc_media(pessoa);

    return 0;
}

void calc_media (registro pessoa [tam])
{
    
}

void ler_maior (registro pessoa [tam])  
{
    int menor = INT_MIN, menorPos;

    for (int i = 0; i < tam; i++)
    {
        if (pessoa[i].altura > menor)
        {
            menor = pessoa[i].altura;
            menorPos = i;
        }
    }
    printf("A menor pessoa e %s", pessoa[menorPos].nome);
    
}

void ler_menor (registro pessoa [tam])
{
    int maior = INT_MAX, maiorPos;

    for (int i = 0; i < tam; i++)
    {
        if (pessoa[i].altura < maior)
        {
            maior = pessoa[i].altura;
            maiorPos = i;
        }
    }
    printf("A menor pessoa e %s", pessoa[maiorPos].nome);

}