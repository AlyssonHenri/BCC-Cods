#include <string.h>
#include <stdio.h>
#include <strings.h>

int main()
{    
    char nome[80];
    char comp[80]="A";
    char out[80];
    
    while (scanf(" %[^\n]", nome) != EOF)
    {    
        if (strcasecmp(nome, comp)==1)
        {
            strcpy(out,nome);
        }
    }
    printf("%s\n",out);
    return 0;
}