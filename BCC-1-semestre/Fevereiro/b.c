#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a, b, c;
    scanf("%f", &a);
    scanf("%f", &b);

    c=(a*a)+(b*b);
    c=sqrt(c);
    printf("%f", c);

    return 0;
}
