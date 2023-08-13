#include <stdio.h>

int main(int argc, char const *argv[])
{
    float p, h;
    printf("Digite o peso:");
    scanf("%f", &p);
    printf("Digite o tamanho:");
    scanf("%f", &h);
    printf("%f", p/(h*h));
    return 0;
}
