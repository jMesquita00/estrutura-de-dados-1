#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tp_data
{
  int dia;
  int mes; 
  int ano;
};
struct tp_passagem
{
  int localizador;
  float preco;
  char destino[50];
 
};


typedef struct arvore
{
    struct tp_passagem *passagem;
    struct tp_data *data;
    struct  arvore *dir;
    struct arvore *esq;
} No;

// cria cada no a ser adicionado na arvore
No *cria_no(){
    No *novo = (No*)malloc(sizeof(No));
    novo->dir = NULL;
    novo->esq = NULL;

    printf("\nInsira o destino: ");
    fflush(stdin);
    fgets(novo->passagem->destino,50,stdin);
    printf("\nInsira o preco: ");
    scanf("%f",&novo->passagem->preco);
    printf("\n...Insira a data: ");
    scanf("%d/%d/%d",&novo->data->dia,&novo->data->mes,&novo->data->ano);
    novo->passagem->localizador = (rand() % 1000);
    printf("\n  o seu identificador eh: %d",novo->passagem->localizador);

     return novo;
}

// inserção em ordem, se for menor que a raiz fica a sua esquerda, se for maior a sua direita
void inserir_no(No **raiz,No *novo){
    
 if((*raiz) == NULL){
     *raiz = novo;
    return;
 }
  else if (novo->passagem->localizador < (*raiz)->passagem->localizador )
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


//imprimir arvore
void imprimir_arvore(No **raiz, int tab = 0){
    
    if ((*raiz) == NULL)  return;

    imprimir_arvore(&(*raiz)->esq,tab + 1);
     for (int i = 0; i < tab; i++) {
    printf("\t");
    }
    printf("\n DESTINO: %s",(*raiz)->passagem->destino);
    printf("\n DATA: %d/%d/%d",(*raiz)->data->dia,(*raiz)->data->mes,(*raiz)->data->ano);
    printf("\n LOCALIZADOR: %d",(*raiz)->passagem->localizador);
    printf("\n PRECO: %.2f\n",(*raiz)->passagem->preco);
   
    imprimir_arvore(&(*raiz)->dir,tab + 1);
    
}



No *pesquisa(No **raiz, int busca){
  if((*raiz) == NULL){
    //printf("\n Numero nao encontrado!");
    return 0;
  }
  if (busca == (*raiz)->passagem->localizador)
  {
    return (*raiz);
  }
  
  else if (busca < (*raiz)->passagem->localizador)
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
        printf("\n......Impressao da Arvore........\n\n");
        imprimir_arvore(&raiz,tab);
                 
            break;
          case 3:
          int num;
          No *aux;
          printf("\n Inisra o numero a ser pesquisado: ");
          scanf("%d",&num);
            
            aux =  pesquisa(&raiz, num);
            printf(" \nNO pesquisado : %d",aux->passagem->localizador);
              
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









