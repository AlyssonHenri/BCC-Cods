#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define VERDADEIRO 1
#define FALSO      0

int main ( int argc, char *argv [] )
{
    int n;
    int ePrimo = VERDADEIRO;

    setlocale ( LC_ALL, "" );

    printf ( "Programa para verificar números primos...\n" );
    printf ( "Números de argumentos da linha de comando: %i.\n", argc );
    /*
    for ( int i = 0; i < argc; i++ )
    {
        printf ( "argv[%i] = %s\n", i, argv [ i ] );
    }
    */

    if ( argc > 1 )
    {
        n = atoi ( argv [ 1 ] );
    }
    else
    {
        printf ( "Digite um valor inteiro:" );
        scanf  ( "%i", &n );
    }

    for ( int i = 2; i <= n / 2; i++ )
    {
        if ( n % i == 0 )
        {
            ePrimo = FALSO;
            i = n;
        }
    }

    if ( ePrimo )
    {
        printf ( "%i é primo.\n", n );
    }
    else
    {
        printf ( "%i não é primo.\n", n );
    }
    return 0;
}