#include <stdio.h>
#include <stdlib.h>


#define verdadeiro 1
#define falso 0

int main(void)
{   
    int divisao, numero, primo=verdadeiro;
    printf("digite o numero: ");
    scanf("%i", &numero);

    if (numero%2==0){
        printf("%i nao e primo", numero);
    }
    else{
        for (int i = 2; i <= numero/2; i++)
        {
           if (numero%i==0)
           {
               primo=falso;
               i=numero;
           }
            
        }
        if (primo)
        {
            printf("%i e primo", )
        }
        
        


    }

    

    return 0;
}
