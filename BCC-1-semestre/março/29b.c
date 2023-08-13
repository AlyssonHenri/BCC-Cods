#include <stdio.h>

int main(int argc, char const *argv[])
{
    double num=0, numAt1=1, numAt2=1;
    int cont=0, quant;
    printf("digite a ate qual termo deseja calcular: ");
    scanf("%i", &quant);
    while (cont<quant)
    {
        printf("| %.0f |",num);
        numAt2=numAt1;
        numAt1=num;
        num=numAt1+numAt2;
        cont++;
    }
    
    return 0;
}
