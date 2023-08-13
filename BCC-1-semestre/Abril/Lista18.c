#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int idade, quantidade=0, idadeMa=0, idadeMe=9999999, mulher200=0, menorIdad=0, menorSalario=9999999;
    float salario, salarioSoma;
    char sexo, termina, menorSex;


        do
        {
            printf("Insira a idade: ");
            scanf("%i", &idade);

            if (idade<0)
            {

                break;
                
            }else
            {
                quantidade++;
            }

            printf("Insira o salario: ");
            scanf("%f", &salario);
            salarioSoma += salario;

            printf("insira um sexo (M/F): ");
            do
            {
                fflush (stdin);
                sexo = tolower( getchar());
                if (sexo!='m' && sexo!='f')
                {
                    printf("Entrada invalida, insira apenas M ou F: ");
                } 
            } while (sexo!='m' && sexo!='f');
            

            if (idade>idadeMa)
            {
                idadeMa=idade;
            }
            if (idade<idadeMe)
            {
                idadeMe=idade;
            }
            
            if ((sexo='f') && (salario<=200))
            {
                mulher200++;
            }
            if (salario<menorSalario)
            {
                menorSex=sexo;
                menorIdad=idade;
            }
            
            printf("Deseja inserir mais dados (S/N): ");
            do
            {
                fflush (stdin);
                termina = tolower( getchar());
                if (termina!='s' && termina!='n')
                {
                    printf("Entrada invalida, insira apenas S ou N: ");
                }
            } while (termina!='s' && termina!='n');
            
            
            
        } while (termina != 'n');

        printf("\nA media dos salarios e: %.2f\n", (salarioSoma/quantidade));
        printf("A maior idade do grupo e: %i\nA maior idade do grupo e: %i\n", idadeMa, idadeMe);
        printf("A quantidade de mulheres com salario ate 200RS: %i\n", mulher200);
        printf("Idade da pessoa com menor salario: %i\nSexo da pessoa com menor salario: %c\n", menorIdad, menorSex);

    
    
    return 0;
}
