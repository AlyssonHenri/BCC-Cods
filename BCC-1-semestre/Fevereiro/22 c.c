#include <stdio.h>
int main()
{
    int c = 0;
    float a, b, r;
    printf(" Digite 1 P/Adicao \n Digite 2 P/Subtracao \n Digite 3 P/Multiplicao \n Digite 4 P/Divisao \n Digite 0 P/Sair \n");
    scanf("%i", &c);
    while (c!=0)
    {
        switch (c)
        {
            case 1:  
                printf("digite os valores:\n");
                scanf("%f %f", &a, &b);  
                r=a+b;
                printf("%f", r);
                break;
            case 2:
                printf("digite os valores:\n");
                scanf("%f %f", &a, &b);  
                r=a-b;
                printf("%f", r);
                break;
            case 3:
                printf("digite os valores:\n");
                scanf("%f %f", &a, &b);  
                r=a*b;
                printf("%f", r);
                break;
            case 4:
                printf("digite os valores:\n");
                scanf("%f %f", &a, &b);  
                r=a/b;
                printf("%f", r);
                break;
            default:
                printf("Valor invalido \n");
                break;
            }
            scanf("%i", c);
    }
    printf("Calculadora encerrada");   
    return 0;
}
