#include <stdio.h>
int main(){
    float soma, entr, produt, qnt;
    soma = 0;
    do
    {
        printf("digite a quantidade de produtos: ");
        scanf("%f", &qnt);
        printf("digite o valor do produto: ");
        scanf("%f", &entr);
        produt = entr*qnt;
        soma = soma + produt;
        printf("O valor atual e: %.2f\n", soma);
    } while (entr!=0);
    

    return 0;
}