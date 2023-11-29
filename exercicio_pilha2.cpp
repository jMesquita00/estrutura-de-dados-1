/*
//questao 1 da lista de pilhas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg_site {
  char nome[30];
  char link[100];
  struct reg_site* prox;
} site;

typedef struct Pilha {
  site* topo;
  int tamanho;
} Pilha;

site* inicia_site(char* nome, char* link) {
  site* p = (site*)malloc(sizeof(site));
  strcpy(p->nome, nome);
  strcpy(p->link, link);
  return p;
}

Pilha* inicia_pilha() {
  Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
  pilha->topo = NULL;
  pilha->tamanho = 0;
  return pilha;
}

void push(Pilha* pilha, site* site) {
  site->prox = pilha->topo;
  pilha->topo = site;
  pilha->tamanho++;
}

site* pop(Pilha* pilha) {
  if (pilha->tamanho == 0) {
    printf("Erro: pilha vazia \n");
    return NULL;
  }
  site *novo = pilha->topo;
  pilha->topo = pilha->topo->prox;
  novo->prox = NULL;
  pilha->tamanho--;
  return novo;
}

void imprime(Pilha* pilha) {
  site* aux = pilha->topo;
  printf("\nTamanho pilha: %d\n", pilha->tamanho);
  while (aux != NULL) {
    printf("%s - %s\n", aux->nome, aux->link);
    aux = aux->prox;
  }
  printf("\n");
}

site* voltar(Pilha* pilha, int n) {
  if (n > pilha->tamanho)
  {
    n = pilha->tamanho;// aqui reduzimos o tamanho da pilha
  }
  else{
    n = n;// n recebe o seu proprio valor
  }
  
  printf("Voltando %d sites.\n", n);
  for (int i = 0; i < n; i++) {
    pop(pilha);
  }
  return pilha->topo;
}

int main() {
  Pilha* pilha = inicia_pilha();
  site *s1, *s2, *s3, *s4;
  char n1[]="Overflow",n2[]="Replit",n3[]="ChatGPT",n4[]="Youtude";
  char v1[]="www.overflow.com",v2[]="www.replit.com.br",v3[]="www.openai/chatGPT.com",v4[]="www.youtude.com";
  s1 = inicia_site(n1, v1);
  s2 = inicia_site(n2, v2);
  s3 = inicia_site(n3, v3);
  s4 = inicia_site(n4, v4);

  push(pilha, s1);
  push(pilha, s2);
  push(pilha, s3);
  push(pilha, s4);
  imprime(pilha);
  site* s = voltar(pilha, 2);
  if (s != NULL) {
    printf("Topo: %s\n", s->nome);
  }
  imprime(pilha);

  return 0;
}
*/



/*
//questao de numero 2 da lista de pilhas
#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int conteudo;
  struct cel *prox;
} celula;

typedef struct {
  celula *top = NULL;// ponteiropara o topo da pilha
  int length = 0;// tamanho da pilha
} stack;// stack significa pilha

celula* inicia_celula(int numero) {
  celula* p = (celula*)malloc(sizeof(celula));
  p->conteudo =  numero;
  return p;
}

stack* inicia_pilha() {
  stack* pilha = (stack*)malloc(sizeof(stack));
  pilha->top = NULL;
  pilha->length = 0;
  return pilha;
}


int tam(stack *s) { return s->length; }//função para  o tamanho da pilha

celula *top(stack *s) { return s->top; } //retorna o ponteiro para o topo da pilha

void imprimir(stack *s) {
  celula *aux = s->top;
  while (aux != NULL) {
    printf("%d -> ", aux->conteudo);
    aux = aux->prox;
  }
  printf("NULL\n");
}
//  a inserção deve ser feita sempre no inicio
void push(stack *s, int valor) {// função de inserir na pilha 
  celula *nova = (celula *)malloc(sizeof(celula));
  nova->conteudo = valor;
  nova->prox = s->top;
  s->top = nova;
  s->length++;
}
//  a remoção deve ser feita sempre no inicio
celula *pop(stack *s) {// função de remover na pilha
  if (s->length == 0) return NULL;

  celula *rem = s->top;
  s->top = rem->prox;
  rem->prox = NULL;
  s->length--;
  return rem;
}
stack *inverso(stack *pilha){
stack *tempo = inicia_pilha();
  celula *aux =  pilha->top;
  celula *armazena = NULL;
  
    while (aux != NULL)
    {
        aux = aux->prox;
        armazena = pop(pilha);
        push(tempo,armazena->conteudo);
    
    }

   
      return tempo;

  }
  


int main(int argc, char const *argv[]) {
  stack *pilha_1 = inicia_pilha();
  stack *pilha_2 = inicia_pilha();
  push(pilha_1,3);
  push(pilha_1,2);
  push(pilha_1,7);
  push(pilha_1,5);
  imprimir(pilha_1);
  pilha_2 = inverso(pilha_1);
  
  imprimir(pilha_2);

  

  

  

  return 0;
}*/




/*

//questao 3 da lista de pilha

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int vetor[TAM];
int top_1 = -1;
int top_2 = TAM;

void push_1(int novo_1)
{
  if (top_1 < top_2 - 1)
  {
    top_1++;
    vetor[top_1] = novo_1;
  }
  else
  {
    printf("pilha 1 cheia!\n");
  }
}

void push_2(int novo_2)
{
  if (top_1 < top_2 - 1)
  {
    top_2--;
    vetor[top_2] = novo_2;
  }
  else
  {
    printf("\npilha 2 cheia!");
  }
}

int pop_1()
{
  if (top_1 >= 0)
  {
    int novo = vetor[top_1];
    top_1--;
    return novo;
  }
  else
  {
    printf("\npilha 1  vazia!");
    return -1;
  }
}

int pop_2()
{
  if (top_2 < TAM)
  {
    int novo = vetor[top_2];
    top_2++;
    return novo;
  }
  else
  {
    printf("\npilha 2 esta vazia!");
    return -1;
  }
}

int main()
{

  
  push_1(3);
  push_2(4);
  push_1(5);
  push_2(7);
  push_1(9);
  push_2(48);
  push_1(31);
  push_2(4);
  push_1(35);
  push_2(16);
  push_1(6);
  push_2(8);
   


  printf("%d\n", pop_1());
  printf("%d\n", pop_2());
  printf("%d\n", pop_1());
  printf("%d\n", pop_2());
  printf("%d\n", pop_1());
  printf("%d\n", pop_2());
  printf("%d\n", pop_1());
  printf("%d\n", pop_2());
  printf("%d\n", pop_1());
  printf("%d\n", pop_2());
  printf("%d\n", pop_1());
  printf("%d\n", pop_2());

  return 0;
}*/