#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int main()
{
    int in, run=4, qtd;
    scanf("%i",&qtd);

    do
    {        
        scanf("%i",&in);
        unsigned long long int mat[in][in], ma[in], tam[in];
        char seg[30];

        for(int j=0; j<in; j++)
        {
            ma[j] = 0;
            tam[j] = 0;
        }

        for (int l = 0; l < in; l++)
        {
            for (int c = 0; c < in; c++)
            {
                scanf("%llu",&mat[l][c]);
                mat[l][c] *= mat[l][c];

                if (mat[l][c]>ma[c])
                {
                    ma[c]=mat[l][c];
                } 
            }   
        }
        for (int i = 0; i < in; i++)
        {
            while(ma[i]>=1)
            {
                ma[i]/=10;
                tam[i]+=1;
            }
        }
        if(run!=4)
        {
            printf("\n");
        }
        printf("Quadrado da matriz #%i:\n",run); 
        for (int l = 0; l < in; l++)
        { 
            for (int c = 0; c < in; c++)
            {    
                if(c != 0)
                {
                    printf(" ");
                }
                sprintf(seg, "%%%llullu", tam[c]);
                printf(seg, mat[l][c]);
            }
            printf("\n");   
        }
        run++;
        qtd--;
    } while (qtd>0);
                    
    return 0;
}