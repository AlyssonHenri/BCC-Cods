#include <stdio.h>
int main(int argc, char const *argv[])
{
    float a, b, c, h, l;
    printf("Insira os valores dos lados");
    scanf("%f %f %f",&a,&b,&c);
    h=a*a;
    l=b*b+c*c;
    if (a>=b && a>=c)
        {
            if (l==h){printf("O triangulo e um retangulo");}
            else{printf("O triangulo nao e um retangulo");}         
        }else if (b>=a && b>=c)
        {
            if (l==h){printf("O triangulo e um retangulo");}
            else{printf("O triangulo nao e um retangulo");}           
        }else if (c>=a && c>=b)
        {
            if (l==h){printf("O triangulo e um retangulo");}
            else{printf("O triangulo nao e um retangulo");}  
        }    
    return 0;
}