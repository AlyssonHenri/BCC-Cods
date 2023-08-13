#include <stdio.h>

int fibonacci(int quant){

    double num=0, numAt1=1, numAt2=0;
    int cont=0;
    while (cont<quant){
        numAt2=numAt1;
        numAt1=num;
        num=numAt1+numAt2;
        cont++;
        printf("|%.0f|",num);
        }
    return cont;
}


int main(void)
{
    int quant;
    char repetir;
    
    do
    {
        printf("digite a ate qual termo deseja calcular: ");
        scanf("%i", &quant);
        printf("%i\n", fibonacci(quant));

        printf("dejesa repetir: (S/N)");
        fflush(stdin);
        repetir= tolower( getchar());
    } while (repetir!='n');


    
    return 0;
}
