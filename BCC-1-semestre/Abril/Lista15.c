#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char sexo, resposta;
    int respostaS=0, respostaN=0, mulherS=0, homemN=0;
    for (int i = 0; i < 10; i++)
    {
        do
        {
            printf("Insira o sexo (F/M): ");
            fflush(stdin);
            sexo = tolower( getchar());
            if (sexo !='m' && sexo!='f')
            {
                printf("---ENTRADA INVALIDA---\n ");
            }
            
        } while (sexo!='m' && sexo!='f');
        
        do
        {
            printf("Insira sua resposta (S/N): ");
            fflush(stdin);
            resposta = tolower( getchar());
            if (resposta!='s' && resposta!='n')
            {
                printf("---ENTRADA INVALIDA---\n");
            }

            if (resposta=='s')
            {
                respostaS++;
            }
            if (resposta=='n')
            {
                respostaN++;
            }  
            if (resposta=='s' && sexo=='f')
            {
                mulherS++;
            }
            if (resposta=='n' && sexo=='m')
            {
                homemN++;
            }
            
        } while (resposta!='s' && resposta!='n');
        

    }
    printf("\nO numero de pessoas que responderam sim: %i\nO numero de pessoas que responderam nao: %i\n", respostaS, respostaN);
    printf("A quantidade de mulheres que responderam sim: %i\n", mulherS);
    printf("A porcentagem de homens que responderam nao: %i\n", (homemN*100)/10);
     
    return 0;
}
