#include <stdlib.h>
#include <stdio.h>


int main()
{
    int tam, calc, menos;
    scanf("%i",&tam);
    do
    {
        
        menos=tam-1;
        calc=tam-(tam/3);
        int vet[tam][tam];

        if (tam==0)
        {
            return 0;
        }
        
        for (int l = 0; l < tam; l++)
        {
            for (int c = 0; c < tam; c++)
            {
                vet[l][c]=0;

                if (l==c)
                {
                    vet[l][c]=2;
                }
                if (l+c==tam-1)
                {
                    vet[l][c]=3;
                }
                if (l>=tam/3 && l<calc && c>=tam/3 && c<calc)
                {
                    vet[l][c]=1;
                }    
                if (l==c && l+c==menos)
                {
                    vet[l][c]=4;
                }        
            }
            
        }
        
        for (int l = 0; l < tam; l++)
        {
            for (int c = 0; c < tam; c++)
            {   
                printf("%i",vet[l][c]);
            }
            printf("\n");
        }
        printf("\n");
    } while ((scanf("%i",&tam) != EOF));
    
             
    return 0;
}
