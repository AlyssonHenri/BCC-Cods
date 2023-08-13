#include <stdio.h>
int main()
{
    
    int m, media, idadeM, idade;
    m=0;
    idadeM=0;
    do
    {
        m++;
        printf("Digite uma idade\n");
        scanf("%i", &idade);
        idadeM = idade + idadeM;
        media = idadeM / m;
        printf("A media de idades e:%i\n", media);

    } while (idade != 0);
    

    return 0;
}
