#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
  char info[100];
  struct No *prox;
}no;

no*inicio;
no*fim;

void entra(char val[])
{
    no*new=(no*)malloc(sizeof(no));
    //new->info = val;
    strcpy(new->info,val);
    new->prox = NULL;
    if (fim!=NULL)
    {
        fim->prox = new;
    }else{
        inicio=new;
    }
    fim=new;
}

void imprimir()
{ 
  printf("\n");
  printf("------------------------\n");
  if (inicio == NULL)
    printf("Fila Vazia\n");
  else{
    no*aux;
    for (aux=inicio; aux!=NULL; aux=aux->prox)
    { 
      printf ("%s\n",aux->info);
    }  
  }
  printf("------------------------");
}

void remover()
{
  no*aux;
  aux=inicio;
  inicio=aux->prox;
  free(aux);
}

void menu()
{
  printf("\n");
  printf("1-Inserir pessoa na fila\n");
  printf("2-Listar todos os integrantes da fila\n");
  printf("3-Remover primeira pessoa da fila\n");
  printf("4-Buscar pessoa\n");
  printf("5-Encerrar\n");
  printf("\n");
}

void procura(char bus[])
{
  printf("1");
  int cont=1;
  no*aux;
  for (aux=inicio; aux!=NULL; aux=aux->prox)
  {
    printf("2");
    if (strcmp(bus,aux->info)==0)
    {
      printf("Posição %i",cont);
    }else{
      cont++;
    }
  }
  
}

int main()
{
  char tex[1000];
  char bus[1000];
  int choi;
  do
  {
    menu();
    scanf("%i",&choi);
    switch (choi)
    {
      case 1:
      fflush(stdin);
      scanf("%[^\n]s",tex);
      entra(tex);
      break;

    case 2:
      imprimir();
      break;
    
    case 3:
      remover();
      break;

    case 4:
      fflush(stdin);
      scanf("%[^\n]s",bus);
      break;

    default:
      return 0;    
      break;
    }
  } while (1);
  return 0;
}
