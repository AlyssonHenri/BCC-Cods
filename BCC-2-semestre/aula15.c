#include <stdio.h>
#include <stdlib.h>

#define TAM 100

int main()
{
    char nome[]="primeiro segundo terceiro quarto", Pnome[TAM]="", Unome[TAM]="";
    int tam, p=1, pri, ult;

    tam=strlen(nome);

    for (int i = 0; i < tam; i++)
    {
        if (nome[i]==' ')
        {
            p++;
        }
        if (nome[i]==' ' && p==2)
        {
            pri=i;
            for (int x = 0; x < i; x++)
            {
                Pnome[x]=nome[x];
            }
            
        }
        
    }

    printf("%i palavras\n\n",p);

    return 0;
}
