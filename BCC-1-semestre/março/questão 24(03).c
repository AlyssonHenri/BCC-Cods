#include <stdio.h>
int main()
{
    //receba dinheiro e converta | dolar 1,80 marco 2,00 libra 3,57/
    float vIn, ini, cal;
    printf("Insira qual para qual moeda deseja converter:\nDolar: 1\nMarco: 2\nLibra: 3\nEncerrar: 0\n");
    scanf("%f", &ini);
    printf("Insira o valor a ser convertido: ");
    scanf("%f", &vIn);
    while (ini!=0)
    {    
        if (ini==1)
        {
            cal=vIn*1.80;
            printf("---------%f\n\n\n\n---------", cal);
        }else if (ini==2)
        {
            cal=vIn*2.00;
            printf("---------%f\n\n\n\n---------", cal);
        }else if (ini==3)
        {
            cal=vIn*3.75;
            printf("---------%f\n\n\n\n---------", cal);
        }else{ini==0;}
        printf("Insira qual para qual moeda deseja converter:\nDolar: 1\nMarco: 2\nLibra: 3\nEncerrar: 0\n");        
        scanf("%f", &ini);
        printf("Insira o valor a ser convertido: ");
        scanf("%f", &vIn);        
    }
    
    return 0;
}
