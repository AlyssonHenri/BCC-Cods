#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int entrada=0;
    char termina;
    do
    {
        scanf("%i", &entrada);
        for (int i = 0; i < 11; i++)
        {
            printf("%i X %i = %i\n", entrada, i, (entrada*i));
        }

        printf("Deseja continuar (S/N): ");
        do
        {
            fflush ( stdin );
            termina = tolower ( getchar () );
            if ( ( termina != 's' ) && ( termina != 'n' ) )
            {
                printf ( "Entrada invalida. Digite apenas 'S' ou 'N': " );
            }
        } while (termina!='s' && termina!='n');
        
    } while (termina!='n');
    

    
    
    
    return 0;
}
