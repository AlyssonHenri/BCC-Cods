#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

void DigitarTabela(char tabuleiro[3][3]);
void Jogador1(char tabuleiro[3][3]);
void Jogador2(char tabuleiro[3][3]);
int verifica(char tabuleiro[3][3], int *ganhou);


int main(void)
{
    char tabuleiro[3][3] = {'_','_','_','_','_','_','_','_','_'};
    int *ganhou = FALSE;
    
    do
    {
        DigitarTabela(tabuleiro);
        Jogador1(tabuleiro);
        DigitarTabela(tabuleiro);
        verifica(tabuleiro, *ganhou);
        

        DigitarTabela(tabuleiro);
        Jogador2(tabuleiro);
        DigitarTabela(tabuleiro);
        verifica(tabuleiro, *ganhou);
    } while (*ganhou == FALSE);
        
    return 0;
}

int verifica(char tabuleiro[3][3], int *ganhou)
{
    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][1] != '_')
        {
           if (tabuleiro[i][0] == 'o')
           {
               printf("\n\n\nJogador 1 ganhou\n\n\n");
               *ganhou = TRUE;
           }
           else
           {
               printf("\n\n\nJogador 2 ganhou\n\n\n");
               *ganhou = TRUE;
           }
           
        }
        
    }

    for (int i = 0; i < 3; i++)
    {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[1][i] != '_')
        {
            if (tabuleiro[i][0] == 'o')
           {
               printf("\n\n\nJogador 1 ganhou\n\n\n");
               *ganhou = TRUE;
           }
           else
           {
               printf("\n\n\nJogador 2 ganhou\n\n\n");
               *ganhou = TRUE;
           }
        }
        
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[1][1] != '_')
    {
        if (tabuleiro[1][1] == 'o')
           {
               printf("\n\n\nJogador 1 ganhou\n\n\n");
               *ganhou = TRUE;
           }
           else
           {
               printf("\n\n\nJogador 2 ganhou\n\n\n");
               *ganhou = TRUE;
           }
    }

    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[1][1] != '_')
    {
        if (tabuleiro[1][1] == 'o')
           {
               printf("\n\n\nJogador 1 ganhou\n\n\n");
               *ganhou = TRUE;
           }
           else
           {
               printf("\n\n\nJogador 2 ganhou\n\n\n");
               *ganhou = TRUE;
           }
    }
    return *ganhou;
}

void Jogador1(char tabuleiro[3][3])
{
    int linha = 0, coluna = 0, jogou;
    jogou = FALSE;

    do
    {
        do
        {   
            printf("\n    Jogador 1\n ");
            printf("Em qual linha deseja jogar: ");
            scanf("%d", &linha);
            
            if (linha > 3 || linha < 1)
            {
                printf("\n\nEntrada invalida, tente novamente\n\n");
            }   
        } while (linha > 3 || linha < 1);
        linha--;

        do
        {
            printf(" Em qual coluna deseja jogar: ");
            scanf("%d", &coluna);
            
            if (coluna > 3 || coluna < 1)
            {
                printf("Entrada invalida, tente novamente\n\n");
            }
            
        } while (coluna > 3 || coluna < 1);
        coluna--;

        if (tabuleiro [linha] [coluna] == 'x' || tabuleiro [linha] [coluna] == 'o')
        {
            printf("\n\nVoce nao pode jogar nessa casa\n\n");;
        }else{
            tabuleiro [linha] [coluna] = 'o';
            jogou = TRUE;
        }

    } while (jogou == FALSE); 
}

void Jogador2(char tabuleiro[3][3])
{
    int linha = 0, coluna = 0, jogou;
    jogou = FALSE;

    do
    {
        do
        {
            printf("\n    Jogador 2\n ");            
            printf("Em qual linha deseja jogar: ");
            scanf("%d", &linha);
            
            if (linha > 3 || linha < 1)
            {
                printf("\n\nEntrada invalida, tente novamente\n");
            }

        } while (linha > 3 || linha < 1);
        linha--; 

        do
        {
            printf(" Em qual coluna deseja jogar: ");
            scanf("%d", &coluna);
            
            if (coluna > 3 || coluna < 1)
            {
                printf("\n\nEntrada invalida, tente novamente\n");
            }
            
        } while (coluna > 3 || coluna < 1);
        coluna--;

        if (tabuleiro [linha] [coluna] == 'o' || tabuleiro [linha] [coluna] == 'x')
        {
            printf("\n\nVoce nao pode jogar nessa casa\n\n");
        }
        else
        {
            tabuleiro [linha] [coluna] = 'x';
            jogou = TRUE;
        }
    } while (jogou == FALSE); 
}

void DigitarTabela(char tabuleiro[3][3])
{
    printf("\n\n");
    
    printf("     1");
    printf("   2");
    printf("   3");        
    printf("\n1  |");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c |", tabuleiro[0][i]);
    }
    
    printf("\n2  |");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c |", tabuleiro[1][i]);
    }

    printf("\n3  |");
    for (int i = 0; i < 3; i++)
    {
        printf(" %c |", tabuleiro[2][i]);
    }

    printf("\n");
}