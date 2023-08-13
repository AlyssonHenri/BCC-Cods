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

L_dupla * new (){
    L_dupla * novo = (L_dupla*) malloc (sizeof(L_dupla));
    return novo;
}

L_dupla * inserir (L_dupla * L, int valor){
    L_dupla * novo = new();
    novo->info = valor;
    novo->prox = L;
    novo->ant = NULL;
    if (L)
        L->ant = novo;
    return novo;
}

void imprimir (L_dupla * L){
    L_dupla * aux;
    for (aux = L ; aux != NULL ; aux = aux->prox )
        printf ("%d ",aux->info);
}

int tamanho (L_dupla * L){
    int qntd = 0;
    L_dupla * aux;
    for (aux = L; aux != NULL ; aux=aux->prox, qntd++);
    return qntd;
}

void imprimir_ordem(L_dupla * L){
    L_dupla * aux;
    for (aux = L; aux->prox != NULL ; aux=aux->prox);

    for ( ; aux!=NULL ; aux=aux->ant)
        printf ("%d ", aux->info);

}

L_dupla * remover (L_dupla * L , int valor){
    L_dupla * aux;
    for (aux = L; aux != NULL && aux->info != valor ; aux = aux->prox);
    if (aux == NULL)
        return L;
    if (aux == L)
        L = aux->prox;
    else
        aux->ant->prox = aux->prox;
    if (aux->prox != NULL)
        aux->prox->ant = aux->ant;
    
    free(aux);
    return L;
}

int main(){

    L_dupla * L1 = criar();
    L1 = inserir(L1, 10);
    L1 = inserir(L1, 20);
    L1 = inserir(L1, 40);
    L1 = inserir(L1, 70);
    
    imprimir(L1);
    printf ("\n");
    imprimir_ordem(L1);
    printf ("\n");
    printf ("A lista tem %d elementos\n", tamanho(L1));

    L1 = remover(L1, 10);

    imprimir(L1);
    printf ("\n");
    imprimir_ordem(L1);
    printf ("\n");
    printf ("A lista tem %d elementos\n", tamanho(L1));


    return 0;
}