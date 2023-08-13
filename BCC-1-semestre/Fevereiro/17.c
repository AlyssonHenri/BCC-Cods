#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    {
        if (a<b && a<c)
        {
            printf("%d", a);
        }else if (b<a && b<c)
        {
            printf("%d", b);
        }else if (c<a && c<b)
        {
            printf("%d", c);
        }
        if (b<a<c && c<a<b)
        {
            printf("%d", a);
        }else if (a<b<c && c<b<a)
        {
            printf("%d", b);
        }else if (a<c<b && b<c<a)
        {
            printf("%d", c);
        }
        if (a>b && a>c)
        {
            printf("%d", a);
        }else if (b>a && b>c)
        {
            printf("%d", b);
        }else if (c>a && c>b)
        {
            printf("%d", c);
        }
        
        
                

    return 0;
}
