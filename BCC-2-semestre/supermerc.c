Fila* dequeue(Fila*f){ //recebe uma fila
  Lista*aux; //cria um auxiliar para andar na lista
  if (f­>ini == NULL){ //se a fila estiver vazia
    printf("Fila vazia\n"); //mensagem
    return f; //retorna a fila sem alterações
  }
  aux = f­>ini;    // aux recebe o início da fila
  f­>ini = aux­>prox;  // início passa a ser o próximo elemento
  if (f­>ini==NULL)   // se esse for o único elemento da fila
    f­>fim=NULL; // a fila ficará vazia
  free(aux); // remove o elemento
  return f; // retorna a fila sem o elemento removido
}