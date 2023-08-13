#include <stdio.h>
int main(int argc, char const *argv[])
{
    float a, b, c, h, l;
    printf("Insira os valores dos lados");
    scanf("%f %f %f",&a,&b,&c);
    if (a=b)
        {
           printf("O triangulo e isoceles");    
        }else if (b=c)
        {
            printf("O triangulo e isoceles");     
        }else if (c=a)
        {
           printf("O triangulo e isoceles");    
        }else {printf("O triangulo não e isoceles");    }    
    return 0;
}