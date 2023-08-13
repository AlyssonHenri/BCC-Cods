#include <stdio.h>
#include <stdlib.h>

int fib (int n){
    if (n==1 || n==2)
    {
        return 1;
    }else{
        return fib(n-1)+fib(n-2);      
    }
}
main(){
    int n;
    printf("Digite a posicao da sequencia de Fibonacci: ");
    scanf("%d", &n);
    printf("%d ", fib(n));
}