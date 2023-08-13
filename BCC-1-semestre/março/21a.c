#include <stdio.h>

int main(void)
{
    for (int i = 0; i+1 < 257; i++)
    {
        printf("%03i - %c | ", i, i);
        if (i%9 == 0)
        {
            printf("\n");
        }
    }
    
    return 0;
}
