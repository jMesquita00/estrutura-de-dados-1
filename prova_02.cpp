#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg_tarefa
{
  char nome[50];
  int quantidade_tarefas;
  int hora;
  int minuto;
  struct reg_tarefa *prox = NULL;
} tarefa;

typedef struct
{
  tarefa *first;
  tarefa *last;
  int length;
} queue;

queue *inicia_fila()
{
  queue *fila = (queue *)malloc(sizeof(queue));
  fila->first = NULL;
  fila->last = NULL;
  fila->length = 0;
  return fila;
}

tarefa *cria_tarefa()
{
  tarefa *novo = (tarefa *)malloc(sizeof(tarefa));
  novo->prox = NULL;

  printf("\n\n...Nome: ");
  fflush(stdin);
  fgets(novo->nome, 50, stdin);

  printf("\n...quantidade de tarefas:  ");

  scanf("%d", &novo->quantidade_tarefas);
  printf("\n...Hora de criacao (hh/mm): ");
  scanf("%d/%d", &novo->hora, &novo->minuto);

  return novo;
}

void enqueue(queue **q, tarefa *novo)
{

  (*q)->length++;
  if ((*q)->last == NULL)
  {
    (*q)->first = novo;
    (*q)->last = novo;
  }
  else
  {
    (*q)->last->prox = novo;
    (*q)->last = novo;
  }
}

tarefa *dequeue(queue **q)
{
  if ((*q)->length == 0)
  {
    return NULL;
  }

  (*q)->length--;
  tarefa *front = (*q)->first;
  (*q)->first = (*q)->first->prox;
  if ((*q)->length == 0)
  {
    (*q)->last = NULL;
  }

  front->prox = NULL;
  return front;
}

int size(queue **q) { return (*q)->length; }

int quantas_antes(queue **q)
{
  queue *aux = *q;
  int tam, conta = 0;
  int hora, min;
  printf("\n Insira a hora a ser encontrada: ");
  scanf("%d/%d", &hora, &min);

  if (aux == NULL)
  {
    printf("\n lista vazia!");
    return -1;
  }
  // else if (aux->first->hora == hora && aux->first->minuto == min)
  // {
  //   tam = size(&aux);
  //   // printf("\ntamanho do primeiro: %d", tam);
  //   return tam;
  // }
  // else
  // {
  //   while (aux->first->prox != NULL)
  //   {
  //     if (aux->first->prox->hora == hora && aux->first->prox->minuto == min)
  //     {
  //       tam = size(q) - (size(&aux) - 1);
  //       // printf("\ntamanho do meio da fila: %d", tam-1);
  //       return tam;
  //     }
  //     else
  //     {
  //       aux->first = aux->first->prox;
  //     }
  //   }

  //   if (aux->first->prox == NULL)
  //   {
  //     if (aux->first->hora == hora)
  //     {
  //       tam = size(&aux);
  //       printf("\ntamanho do ultino: %d", tam);
  //       return tam;
  //     }
  //   }
  else if (aux->first->hora == hora && aux->first->minuto == min)
  {
    tam = size(&aux)-1;
    // printf("\ntamanho do primeiro: %d", tam);
    return tam;
  }
  else
  {
    while (aux->first->prox != NULL)
    {
      if (aux->first->prox->hora == hora && aux->first->prox->minuto == min)
      {
        conta++;
        printf("\ntamanho do meio da fila: %d", tam-1);
        return conta;
      }
      else
      {
        aux->first = aux->first->prox;
      }
    }

    if (aux->first->prox == NULL)
    {
      if (aux->first->hora == hora)
      {
        tam = size(&aux)-size(&aux);
        printf("\ntamanho do ultino: %d", tam);
        return tam;
      }
    }

    printf("\n nao encontrado!");
  }
}

void inserir_tarefa(queue **cabeca)
{

  tarefa *novo = cria_tarefa();
  enqueue(cabeca, novo);
}

void print(queue **q)
{
  tarefa *aux = (*q)->first;
  while (aux != NULL)
  {
    printf("\n\n%s -> ", aux->nome);
    aux = aux->prox;
  }
  printf("NULL\n");
}
void executar(queue **q)
{
  queue *aux = *q;
  tarefa *a;
  
  
  if (aux->first == NULL)
  {
    printf("\nfila vazia!");
    return;
  }
  else
  {
    a = dequeue(q);
    a->quantidade_tarefas--;
    if (a->quantidade_tarefas == 0)
    {
      printf("\n Encerrando atividade!");
      free(a);
      return;
    }
    else
    {

      enqueue(q, a);
      printf("\n depois de diminuir a trefa!");
      print(q);
      return;
    }
  }
}
int calcular_atividade(queue **q)
{
  queue *aux = *q;
  int quant = 0;

  if (aux->first == NULL)
  {
    printf("\nLista vazia!");
    return 0;
  }
  else
  {
    while (aux->first != NULL)
    {
      quant += aux->first->quantidade_tarefas;
      // printf("\n aux com um: %d",aux->first->quantidade_tarefas);
      aux->first = aux->first->prox;
    }
    printf("\n aux com um: %d", quant);
    return quant;
  }
}
int main(int argc, char const *argv[])
{

  queue *cabeca = inicia_fila();
  tarefa *rem = NULL;

  int tamanho, valor, quantidade;

  do
  {
    printf("\n0. Para sair");
    printf("\n1. Inserir tarefa");
    printf("\n2. Remover da fila");
    printf("\n3. imprimir fila ");
    printf("\n4. Tamanho da fila ");
    printf("\n5. quantidade de tarefas depois");
    printf("\n6. quantidade de atividades");
    printf("\n7. executar");

    printf("\n   Digite: ");
    scanf("%d", &valor);

    switch (valor)
    {
    case 1:

      inserir_tarefa(&cabeca);

      break;
    case 2:

      rem = dequeue(&cabeca);
      printf("\nNOME: %s", rem->nome);
      printf("\nQUANTIDADE DE TAREFAS: %d", rem->quantidade_tarefas);
      printf("\nHORA: %d/%d", rem->hora, rem->minuto);

      break;
    case 3:
      print(&cabeca);
      break;

    case 4:

      tamanho = size(&cabeca);
      printf("\nTamanho: %d", tamanho);
      break;
    case 5:
     

      quantidade = quantas_antes(&cabeca);

      printf("\n quantidade a tras: %d", quantidade);

      break;
    case 6:
      calcular_atividade(&cabeca);
      break;

    case 7:
      executar(&cabeca);
      break;

    case 0:
      printf("\n\nSAINDO....");
      return 0;
      break;

    default:
      printf("\nOpcao invalida!\n");
      break;
    }
  } while (valor != 0);

  return 0;
}
