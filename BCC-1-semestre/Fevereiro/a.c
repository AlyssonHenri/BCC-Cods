#include <stdio.h>

int main(int argc, char const *argv[])
{
    float pi, r, a, r2;
    pi = 3.14;
    scanf("%f", &r);
    r2 = r*r;
    a=pi*r2;

    printf("%f", a);


    return 0;
}
