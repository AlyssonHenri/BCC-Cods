#include <stdio.h>
#include <string.h>

int main ()
{
    char d, num[1000000];
    do
    {
        scanf(" %c",&d);
        scanf("%s",num);
        if (d=='0')
        {
            break;
        }
        
        int tam = strlen(num);
        for (int i = 0; i < tam; i++)
        {
            if (num[i]==d)
            {                
                for (int b = i; b < tam; b++)
                {
                    num[b] = num[b+1];
                    i--;
                }  
            }
        }
        if (num[0]=='0' || num[0]==00)
        {
            printf("0\n");
        }
        else if (num[0]!=00)
        {
            printf("%s\n", num);
        }
    } while (d!='0');   

  return 0;
}