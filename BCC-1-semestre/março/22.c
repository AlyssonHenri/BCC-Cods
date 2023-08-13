#include <stdio.h>

int main(void)
{

    int idade=1, idadema=0, idademe=10000000000000, Fsalario=0, quantidade=0, menorIdade=0;
    char sex, sexMenor;
    float salario, salarioMedia, salarioSoma, salarioMeno=10000000000000;
    while (idade>0)
    {
    {   printf("\nInsira a idade: ");
        scanf("%i", &idade);
        if (idade<0)
        {
            break;
        }
        
        if (idade>idadema)
        {
            idadema = idade;
        }
        if (idade<idademe)
        {
            idademe = idade;
        }
        
    }

    {   printf("Insira o sexo (M/F): ");
        scanf(" %c", &sex);
        if (sex == 'M' || sex == 'F' || sex == 'm' || sex == 'f')
        {
            quantidade++;
        }else{break;}
    }
                 

    {   printf("Insira o salario: ");
        scanf("%f", &salario);
        salarioSoma = salario + salarioSoma;
        salarioMedia = salarioSoma/quantidade;
        if (salario<=200 && (sex == 'F' || sex == 'f'))
        {
            Fsalario++;
        }
        if (salario<salarioMeno)
        {
            salarioMeno = salario;
            sexMenor=sex;
            menorIdade=idade;
            
        }

    }
    {printf("----------------------------------------------------------------------------------------\n");
    printf("Media do salario: %.2f\n", salarioMedia);
    printf("Menor idade: %i\n", idademe);
    printf("Maior idade: %i\n", idadema);
    printf("Quantidade de mulheres com salario ate 200: %i\n", Fsalario);
    printf("Salario menor: %.2f\n", salarioMeno);
    printf("sexo do menor slaraio: %c\n", sexMenor);
    printf("idade do menor salario: %i\n", menorIdade);
    }
    }      
    return 0;
}
