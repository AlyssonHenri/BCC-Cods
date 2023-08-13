#include <stdio.h>

int main(void)
{
    float val, calc, res;
    scanf("%f", &val);
    for (calc = 0; calc < 10; calc++)
    {
        res=val*calc;
        printf("%.0f x %.0f = %.2f\n",val, calc, res);
    }
    for (calc = 1; calc < 10; calc++)
    {
        res=val+calc;
        printf("%.0f + %.0f = %.2f\n",val, calc, res);
    }
    for (calc = 1; calc < 10; calc++)
    {
        res=val-calc;
        printf("%.0f - %.0f = %.2f\n",val, calc, res);
    }
    for (calc = 1; calc < 10; calc++)
    {
        res=val/calc;
        printf("%.0f / %.0f = %.2f\n",val, calc, res);
    }
    return 0;
}