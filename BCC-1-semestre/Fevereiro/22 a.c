#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a, b, c;
    printf("Insira os valores do intervalo \n");
    scanf("%f %f", &a, &b);
    printf("Insira o valor a ser verificado \n");
    scanf("%f", &c);
    if (a>c && c>b)
    {
        printf("O valor %2.f esta presente entre %2.f e %2.f", c, a, b);
    }else if (a<c && c<b)
    {
        printf("O valor %2.f esta presente entre %2.f e %2.f", c, a, b);
    }else{printf("O valor %2.f nao esta presente entre %2.f e %2.f", c, a, b);}
    return 0;
}
