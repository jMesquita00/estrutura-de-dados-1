/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[30];
  int idade;

} Pessoa;

typedef struct node {
  Pessoa *pessoa;
  struct node *filho1 = NULL;
  struct node *filho2 = NULL;
  struct node *filho3 = NULL;
} No;


void imprimir(No *node, int tab = 0) {
  if (node == NULL) return;

  for (int i = 0; i < tab; i++) {
    printf("\t");
  }

  printf("%s - %d\n", node->pessoa->nome, node->pessoa->idade);
  imprimir(node->filho1, tab + 1);
  imprimir(node->filho2, tab + 1);
  imprimir(node->filho3, tab + 1);
}
No *criar_no() {
  Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
  No *node = (No *)malloc(sizeof(No));

  printf("Digite o nome: ");
  scanf(" %s", p->nome);
  printf("Digite a idade: ");
  scanf("%d", &p->idade);

  node->pessoa = p;
  node->filho1 = NULL;
  node->filho2 = NULL;
  node->filho3 = NULL;
  
  return node;
}


int main(){

  No *a,*b,*c,*d;
  a = criar_no();
  b = criar_no();
  c = criar_no();
  d = criar_no();
imprimir(a,0);
imprimir(b,1);
imprimir(c,1);
imprimir(d,2);
 
  return 0;
}

*/
/*

///////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <string.h>


typedef struct no {
  int conteudo;
  struct no *dir = NULL;
  struct no *esq = NULL;
} No;


No* criaAB(int dado)
{
	// Aloca memória para o novo nó.
	No *node = (No*)malloc(sizeof(No));
	// Define o dado do nó.
	node->conteudo = dado;
	// Inicializa os filhos da esquerda e direita e o pai como NULL.
	node->esq = NULL;
	node->dir = NULL;
	
  printf("\n criado com sucesso: %d", node->conteudo);
	return node;
}

void inserirAB(No **raiz, No *novo){

	if (*raiz == NULL)
	{
		// printf("Erro 3");
		*raiz = novo;
		 printf("\n conteudo da raiz: %d",(*raiz)->conteudo);
		return;
	}
	else if(novo->conteudo < (*raiz)->conteudo)
	{
		inserirAB(&(*raiz)->esq,novo);
	
	}
	else
	inserirAB(&(*raiz)->dir,novo);
	
}

void imprimirAB(No **raiz){
	
	if((*raiz) == NULL){
		 printf("Erro 3");
		return;
	}

	imprimirAB(&(*raiz)->esq);
	printf("\n %d",(*raiz)->conteudo);
	imprimirAB(&(*raiz)->dir);
	
}
// void inserir(No *novo){
	
// 	No * node = criaAB(novo->conteudo);
// 	inserirAB(node)
// }


int main(){

  No *raiz = (No*)malloc(sizeof(No));
  No *novo;
  
  printf("\n Insira um numero: ");
  scanf("%d",&raiz->conteudo);
  printf("\n numero digitado: %d\n", raiz->conteudo);

 novo = criaAB(raiz->conteudo);
 inserirAB(&raiz,novo);
 inserirAB(&raiz,novo);
 
//  printf("Erro 1");
  imprimirAB(&raiz);
  

  return 0;
}

*/

///////////////////////////////////////////////////////////////////////////



#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct arvore
{
    int conteudo;
    struct  arvore *dir;
    struct arvore *esq;
} No;

// cria cada no a ser adicionado na arvore
No *cria_no(){
    No *novo = (No*)malloc(sizeof(No));
    novo->dir = NULL;
    novo->esq = NULL;

    printf("\n...Insira um numero: ");
    scanf("%d",&novo->conteudo);

     return novo;
}

// inserção em ordem, se for menor que a raiz fica a sua esquerda, se for maior a sua direita
void inserir_no(No **raiz,No *novo){
    
 if((*raiz) == NULL){
     *raiz = novo;
    return;
 }
  else if (novo->conteudo < (*raiz)->conteudo )
    {
       inserir_no(&(*raiz)->esq, novo);
    }
 else {

    inserir_no(&(*raiz)->dir, novo);
 }
 
   
}

// recebe a a raiz, cria um novo no na função "cria_no" e manda a raiz e o novo_no criado para enserir na arvore
void inserir( No **raiz){
    No *novo = cria_no();
    inserir_no(raiz,novo);
 }


/*void remover (No **raiz){
  

}*/
//imprimir arvore
void imprimir_arvore(No **raiz, int tab = 0){
    
    if ((*raiz) == NULL)  return;

    imprimir_arvore(&(*raiz)->esq,tab + 1);
     for (int i = 0; i < tab; i++) {
    printf("\t");
    }
    printf(" %d\n",(*raiz)->conteudo);
    imprimir_arvore(&(*raiz)->dir,tab + 1);
    
}


//impressão em ordem
void imprimir_em(No **raiz, int tab = 0){
    
    if ((*raiz) == NULL)  return;

    
    imprimir_em(&(*raiz)->esq,tab + 1);
    printf(" %d\n",(*raiz)->conteudo);
    imprimir_em(&(*raiz)->dir,tab + 1);
    
}
// imprimir pre_ordem
void imprimir_pre(No **raiz, int tab = 0){
    
    if ((*raiz) == NULL)  return;

    
    printf("\n %d ",(*raiz)->conteudo);
    imprimir_pre(&(*raiz)->esq,tab + 1);
   
    imprimir_pre(&(*raiz)->dir,tab + 1);
    
}


//imprimir em pos ordem, 
void imprimir_pos(No **raiz, int tab = 0){
    
    if ((*raiz) == NULL)  return;

     
    imprimir_pos(&(*raiz)->esq,tab + 1);
    imprimir_pos(&(*raiz)->dir,tab + 1);
    printf("  %d\n",(*raiz)->conteudo);
}


// imprimir em nivel,
void imprimir_em_nivel(No **raiz){
  
  if ((*raiz) == NULL) return;
  // ,
    
   
    if((*raiz)->esq != NULL){
      printf("%d",(*raiz)->esq->conteudo);
    }
    if ((*raiz)->dir != NULL)
    {
      printf("%d",(*raiz)->dir->conteudo);
    }
    imprimir_em_nivel(&(*raiz)->esq);//
    imprimir_em_nivel(&(*raiz)->dir);//
    }

  void imprimir_raiz(No **raiz){
  if ((*raiz) == NULL) return;
  printf ("%d",(*raiz)->conteudo);
  imprimir_em_nivel(raiz);
}
       
No *pesquisa(No **raiz, int busca){
  if((*raiz) == NULL){
    //printf("\n Numero nao encontrado!");
    return 0;
  }
  if (busca == (*raiz)->conteudo)
  {
    return (*raiz);
  }
  
  else if (busca < (*raiz)->conteudo)
  {
     return pesquisa(&(*raiz)->esq, busca);
    
  }
  else
   return pesquisa(&(*raiz)->dir, busca);
  
}

int main(int argc, char const *argv[])
{
    
    No *raiz = NULL;
  
  
    int valor;

     do
    {
        printf("\n0. Para sair");
        printf("\n1. Inserir no");
        printf("\n2. Imprimir arvore");
        printf("\n3. Pesquisa no");
        printf("\n   Digite: ");
        scanf("%d",&valor);
        
        switch (valor)
        {
        case 1:
           
            inserir(&raiz);
                

            break;
        case 2:
        int tab, esc;
        printf("\nInsira um valor tab: ");
        scanf("%d",&tab);
        do
        {
          printf("\n0. sair");
          printf("\n1. imprimir em pre ordem ");
          printf("\n2. imprimir em ordem ");
          printf("\n3. imprimir em pos ordem ");
          printf("\n4. imprimir em nivel ");  
          printf("\n5. imprimir arvore ");        
          printf("\nDigite: ");
          scanf("%d",&esc);
          

          switch (esc)
          {
          case 0:
              printf("\n...SAINDO...\n");
              return 0;
            break;
          case 1:
             printf("\n......Impressao em pre ordem.........\n");
              imprimir_pre(&raiz,tab);
            break;
          case 2:
              printf("\n.......Impressao em ordem...........\n");
               imprimir_em(&raiz,tab);
            break;
          case 3:
              printf("\n......Impressao em pos ordem........\n");
               imprimir_pos(&raiz,tab);
            break;
          case 4:
              printf("\n......Impressao em Nivel........\n\n");
               imprimir_raiz(&raiz);
            break;
          case 5:
          printf("\n......Impressao da Arvore........\n\n");
          imprimir_arvore(&raiz,tab);
            break;
          
          default:
             printf("\nOpcao invalida!\n");
            break;
          }
          
        } while (esc != 0);
        
            break;
          case 3:
          int num;
          No *aux;
          printf("\n Inisra o numero a ser pesquisado: ");
          scanf("%d",&num);
            
            aux =  pesquisa(&raiz, num);
            printf(" \nNO pesquisado : %d",aux->conteudo);
              
            break;
       
        case 0:
            printf("\n\nSAINDO....\n\n");
            return 0;
            break;
        
        default:
        printf("\nOpcao invalida!\n");
            break;
        }
    } while (valor != 0);
    
    
    return 0;
}









