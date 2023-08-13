#include <stdio.h>

int main(void)
{
    char menu;
    float nota1, nota2, nota3, media, peso1, peso2, peso3;
    do
    {
        printf("O que deseja fazer\n (A)Calcualr media aritimetica\n (P)Calcualr media ponderada\n (S)Sair\n");
        fflush(stdin);
        menu = tolower( getchar());
    
        if (menu=='a')
        {
            printf("Digite a primeira nota: ");
            scanf("%f", &nota1);

            printf("Digite a segunda nota: ");
            scanf("%f", &nota2);

            media=(nota1+nota2)/2;
            printf("A media e: %.2f\n",media);
        }

        if (menu=='p')
        {
            printf("Digite a primeira nota: ");
            scanf("%f", &nota1);
            printf("Digite o peso dessa nota: ");
            scanf("%f", &peso1);
            nota1=nota1*peso1;

            printf("Digite a primeira nota: ");
            scanf("%f", &nota2);
            printf("Digite o peso dessa nota: ");
            scanf("%f", &peso2);
            nota2=nota2*peso2;

            printf("Digite a primeira nota: ");
            scanf("%f", &nota3);
            printf("Digite o peso dessa nota: ");
            scanf("%f", &peso3);
            nota3=nota3*peso3;

            media=(nota1+nota2+nota3)/(peso1+peso2+peso3);
            printf("A media e: %.2f\n",media);
        }
        
        if (menu!='a' && menu!='p' && menu!='s')
        {
            printf("---ENTRADA INVALIDA---\n");   
            menu=0;
        }
        
        
    } while (menu!='s');
    

    return 0;
}
