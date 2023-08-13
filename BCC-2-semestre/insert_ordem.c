#include <stdio.h>
#include <stdlib.h>

typedef struct l_dupla{
    int info;
    struct l_dupla *prox;
    struct l_dupla *ant;
}L_dupla;

L_dupla * criar(){
    return NULL;
}
L_dupla * new(){
    L_dupla * novo = (L_dupla*) malloc (sizeof(L_dupla));
    return novo;
}

L_dupla * inserir (L_dupla * L, int valor){
    L_dupla * novo = new();
    //int valor;
    //scanf("%d",&valor);
    novo->info = valor;
    novo->prox = L;
    novo->ant = NULL;
    if (L)
    {
        L->ant = novo;
    }
    return novo;
}

L_dupla * imprime(L_dupla * L){
    L_dupla * aux;
    for (aux=L; aux!=NULL; aux=aux->prox){
        printf("%d ",aux->info);
    }
}

L_dupla * imprime_inver(L_dupla * L){
    L_dupla * aux;
    for (aux=L; aux->prox != NULL; aux=aux->prox);
    for ( ; aux != NULL; aux=aux->ant)
        printf("%d ", aux->info);
}

L_dupla * inserir_fim(L_dupla * L, int valor){
    
}

int main()
{
    L_dupla * in = criar();

    //in = inserir(in);
    //in = inserir(in);
    in = inserir(in, 2);
    in = inserir(in, 3);
    in = inserir(in, 4);

    imprime(in);
    printf("\n");
    imprime_inver(in);
    return 0;
}
