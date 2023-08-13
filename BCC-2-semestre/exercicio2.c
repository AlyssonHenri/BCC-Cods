#include <stdio.h>

int main(void){
    int N, Q, i, e[101], o[101], d, j, m = -1, n;
    scanf("%d %d", &N, &Q);

    for(i=0;i<101;i++){
        e[i] = 0;
        o[i] = 0;
    }


    for(i = 1;i<=N;i++){
        scanf("%d", &e[i]);
    }
    for(i = 1;i<=N;i++){
        for(j=1;j<=N;j++){
            if (e[j]>m){
                m=e[j];
                n = j;
            }
        }
        o[i]=m;
        e[n]=-2;
        m = -1;
    }
    for(i = 1;i<=Q;i++){
        scanf("%d", &d);
        printf("%d\n", o[d]);
    }
    return 0;
}