#include <stdio.h>
int main()
{
    
    float n1, n2, n3, nota, media;
    char nome[50];
    printf("Insira as notas do aluno\n");
    scanf("%f %f %f",&n1,&n2,&n3);
    printf("Insira o nome do aluno\n");
    scanf("%s", &nome);
    nota=n1+n2+n3;
    media=nota/3;
    if (media>=7)
        {
            printf("O aluno %s foi aprovado com %2.f", nome, media);        
        }else{
            printf("O aluno %s foi reprovado com %2.f", nome, media);
        }
         
    return 0;
}

    
