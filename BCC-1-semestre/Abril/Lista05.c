#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++){
        for(int x = 0; x <= 10; x++){
        printf("%i x %i = %i\n", i, x, (i*x));
        }
        printf("\n");
    }
    return 0;
}