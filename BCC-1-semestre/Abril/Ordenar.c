#include <stdlib.h>
#include <stdio.h>

#define TAMVET 10



int main(void)
{

    int vet[TAMVET]={7, -1, 9, 2, 0, -8, 10, 22, 45, 11};
    int aux = 0;
    

    for(int i = 0; i < TAMVET-1; i++)
    {    

        for (int j = i + 1; j < TAMVET; j++)
        {
            if (vet[i] > vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;   
            }
              
        } 
    }

    for (int i = 0; i < TAMVET; i++)
    {
        printf("%i\n", vet[i]);
        fflush ( stdout );
    }
    

     
    return 0;
}
