#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

void vogais (char palavra[TAM], int tam);
void inverte (char palavra[TAM], int tam);

int main()
{
    char a[TAM], b[TAM], hold, unir[TAM]="";
    int tam1,tam2,tam3;
    
    scanf("%s %s",&a,&b);

    strcat(unir,a);
    strcat(unir,b);

    tam1 = strlen(a);
    tam2 = strlen(b);
    tam3 = strlen(unir);

    printf("Qtd letras 1 = %i\nQtd letras 2 = %i\n", tam1, tam2);
    if (strcmp(a,b)==0)
    {
        printf("IGUAIS\n");
    }
    else(
        printf("DIFERENTES\n")
    );
    
    vogais(a, tam1);
    vogais(b, tam2);

    inverte(b, tam2);

    printf("%s\n",unir);

    for (int i = 0; i < tam3; i++)
    {
        for (int x = i+1; x < tam3; x++)
        {
            if (unir[i]==unir[x])
            {
                for (int z = x; z < tam3; z++)
                {
                    unir[z]=unir[z+1];
                }
                
            }
            
        }
        
        
    }
    printf("%s\n",unir);
    

    return 0;
}

void vogais (char palavra[], int tam){
    int vog=0;
    for (int i = 0; i < tam; i++)
    {
        if (palavra[i]=='a')
        {
            vog++;
        }
        if (palavra[i]=='e')
        {
            vog++;
        }
        if (palavra[i]=='i')
        {
            vog++;
        }
        if (palavra[i]=='o')
        {
            vog++;
        }
        if (palavra[i]=='u')
        {
            vog++;
        }
    }
    printf("%i VOGAIS\n",vog);
}

void inverte (char palavra[], int tam){
    char hold;
    for (int i = 0; i < tam/2; i++)
    {
        hold=palavra[i];
        palavra[i]=palavra[tam-1-i];
        palavra[tam-1-i]=hold;
    }

    for (int i = 0; i < tam; i++)
    {
        printf("%c",palavra[i]);
    }
    printf("\n");
}
