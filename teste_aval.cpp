#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct arvore
{
    char destino[50];
    int localizador;
    float preco;
    int dia;
    int mes; 
    int ano;
    int quant_voos = 0;
    int valor_total = 0;
    struct  arvore *dir;
    struct arvore *esq;
} No;

float tot(No **raiz, float soma){
    if (*raiz == NULL)return 0;
    soma = (*raiz)->preco +tot(&(*raiz)->esq, soma) + tot(&(*raiz)->dir,soma);
    

return soma;
}

// cria cada no a ser adicionado na arvore
No *cria_no(){
    No *novo = (No*)malloc(sizeof(No));
    novo->dir = NULL;
    novo->esq = NULL;

    printf("\nInsira o destino: ");
    fflush(stdin);
    fgets(novo->destino,50,stdin);
    printf("\nInsira o preco: ");
    scanf("%f",&novo->preco);
    printf("\n...Insira a data: ");
    scanf("%d/%d/%d",&novo->dia,&novo->mes,&novo->ano);
    // printf("\nInsira o identificador: ");
    // scanf("%d",&novo->localizador);
    novo->localizador = (rand() % 1000);
    printf("\n  o seu identificador eh: %d",novo->localizador);

     return novo;
}


// inserção em ordem, se for menor que a raiz fica a sua esquerda, se for maior a sua direita
void inserir_no(No **raiz,No *novo){
    
 if((*raiz) == NULL){
     *raiz = novo;
    
     
    return;
 }
  else if (novo->localizador < (*raiz)->localizador )
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

    printf(" %d\n",(*raiz)->localizador);
    
   
    imprimir_arvore(&(*raiz)->dir,tab + 1);
    
}
void imprimir_arvore_tudo(No **raiz, int tab){
    
    if ((*raiz) == NULL)  return;

    imprimir_arvore(&(*raiz)->esq,tab + 1);
     for (int i = 0; i < tab; i++) {
    printf("\t");
    }
    printf(" DESTINO: %s\n",(*raiz)->destino);
    printf(" DATA: %d/%d/%d\n",(*raiz)->dia,(*raiz)->mes,(*raiz)->ano);
    printf(" LOCALIZADOR: %d\n",(*raiz)->localizador);
    printf(" PRECO: %.2f\n",(*raiz)->preco);
   
    imprimir_arvore(&(*raiz)->dir,tab + 1);
    
}

      


      
void pesquisa(No **raiz, char *busca){
  if((*raiz) == NULL){
    //printf("\n Numero nao encontrado!");
    return;
  }
    
  if(strcmp(busca,(*raiz)->destino) == 0){
  printf("\nDestino: %s",(*raiz)->destino);
  printf("\nPreco: %d",(*raiz)->preco);
  printf("\nData: %d/%d/%d",(*raiz)->dia,(*raiz)->mes,(*raiz)->ano);
  printf("\n%d",(*raiz)->localizador);
  }

  pesquisa(&(*raiz)->esq,busca);
  pesquisa(&(*raiz)->dir,busca);
  
}
void inserir_arv(No **raiz,No **novo){
    
 if((*raiz) == NULL){
     *raiz = *novo;
  
    return;
 }
  else if ((*novo)->localizador < (*raiz)->localizador )
    {
       inserir_no(&(*raiz)->esq, (*novo));
    }
 else {

    inserir_no(&(*raiz)->dir, (*novo));
 }
 
}

///////////////////////////////////////////////////////////////////////

bool EhFolha(No **node)
{

    if (*node == NULL)
        return false;

    if ((*node)->dir == NULL && (*node)->esq == NULL)
        return true;

    return false;
}

bool temFilho(No *node)
{

    if (node == NULL)
        return false;

    if (node->esq == NULL && node->dir != NULL)
        return true;
    if (node->esq != NULL && node->dir == NULL)
        return true;

    return false;
}

No *maiorDaEsquerda(No *node)
{
    if (node == NULL)
        return NULL;

    if (node->dir == NULL)
        return node;

    return (maiorDaEsquerda(node->dir));
}

No *deletar(No **raiz, int busca)
{

    if (*raiz == NULL)
    {
        return NULL;
    }

    if ((*raiz)->localizador == busca)
    {

        No *elementoRemovido = *raiz;

        if (EhFolha(raiz) == true)
        {

            *raiz = NULL;
        }
        else if (temFilho(*raiz) == true)
        {

            if ((*raiz)->dir != NULL)
            {
                *raiz = (*raiz)->dir;
            }
            else
            {
                *raiz = (*raiz)->esq;
            }
        }
        else
        {
            No *maiorDaEsq = maiorDaEsquerda((*raiz)->esq);
            deletar(&(*raiz), maiorDaEsq->localizador); // remove
            maiorDaEsq->esq = (*raiz)->esq;
            maiorDaEsq->dir = (*raiz)->dir;
            *raiz = maiorDaEsq;
        }

        elementoRemovido->dir = NULL;
        elementoRemovido->esq = NULL;
        return elementoRemovido;
    }
    else
    {
        if (busca > (*raiz)->localizador)
        {
            return deletar(&(*raiz)->dir, busca);
        }
        else
        {
            return deletar(&(*raiz)->esq, busca);
        }
    }
};

void juncao(No **raiz1, No **raiz2, No **raiz3)
{

    while (*raiz1 != NULL)
    {
        No *removido_Raiz1 = deletar(raiz1, (*raiz1)->localizador);
        inserir_no(raiz3, removido_Raiz1);
    }

    while (*raiz2 != NULL)
    {
        No *removido_Raiz2 = deletar(raiz2, (*raiz2)->localizador);
        inserir_no(raiz3, removido_Raiz2);
    }

     imprimir_arvore(raiz3);
    /// juntou as duas árvore
};
///////////////////////////////////////////////////////////////////////


int main(int argc, char const *argv[])
{
    
    No *raiz_brasil = NULL;
    No *raiz_argentina = NULL;
    No *raiz_conca = NULL;
    int cont = 0, cont2 = 0;
    float pre1 = 0,pre2 = 0;
  
    int valor;

     do
    {
        printf("\n0. Para sair");
        printf("\n1. Inserir no");
        printf("\n2. Imprimir arvore");
        printf("\n3. Pesquisa no");
        printf("\n4. quntidade de voos e valor total");
        printf("\n5. concatena arvores ");
        printf("\n6. Deletar ");
        printf("\n   Digite: ");
        scanf("%d",&valor);
        
        switch (valor)
        {
        case 1:
            int num;
            printf("\n1. Brsail ");
            printf("\n2.argentina ");
            printf("\nDigite: ");
            scanf("%d",&num);
            switch (num)
            {
            case 1:
                inserir(&raiz_brasil);
                cont++;
                pre1 = tot(&raiz_brasil,0);
                break;
            case 2:
                inserir(&raiz_argentina);
                cont2++;
                pre2 = tot(&raiz_argentina,0);
                break;
            
            default:
            printf("\n opcao invalida!");
                break;
            }
            
            
            
            break;
        case 2:
        int tab;
        printf("\n1. brasil ");
        printf("\n2. argentina ");
        scanf("%d",&tab);      
        printf("\n......Impressao da Arvore........\n\n");
        switch (tab)
            {
            case 1:
                imprimir_arvore(&raiz_brasil);
                break;
            case 2:
                imprimir_arvore(&raiz_argentina);
                break;
            
            default:
            printf("\n opcao invalida!");
                break;
            }

                 
            break;
          case 3:
          char busca[50];
          int ta;
          printf("\n Inisra o destino a ser pesquisado: ");
          fflush(stdin);
          fgets(busca,50,stdin);
          
          printf("\n1. brasil ");
          printf("\n2. argentina ");
          scanf("%d",&ta);      
          
           switch (ta)
             {
                case 1:
                    pesquisa(&raiz_brasil,busca);
                    break;
                case 2:
                    pesquisa(&raiz_argentina,busca);
                    break;
                
                default:
                printf("\n opcao invalida!");
                break;
              }
         
            break;
        case 4:

            printf("\n1. brasil ");
            printf("\n2. argentina ");
            scanf("%d",&ta);      
           
            switch (ta)
             {
                case 1:
                    printf("\nquanidade de voos: %d",cont);
                    printf("\narrecadacao: %.2f",pre1);
                    break;
                case 2:
                    printf("\nquanidade de voos: %d",cont2);
                    printf("\narrecadacao: %.2f",pre2);
                    break;
                
                default:
                printf("\n opcao invalida!");
                break;
              }
                
            break;
        case 5:
            juncao(&raiz_brasil,&raiz_argentina,&raiz_conca);
           
            break;
        case 6:
        int delet,nume;
            printf("\n1. brasil ");
            printf("\n2. argentina ");
            scanf("%d",&ta);      
           
            switch (ta)
             {
                case 1:
                    printf("\nInsira o numero a ser deletado: ");
                    scanf("%d",&delet); 
                    deletar(&raiz_brasil,delet);
                    break;
                case 2:
                    printf("\nInsira o numero a ser deletado: ");
                    scanf("%d",&nume); 
                    deletar(&raiz_brasil,nume);
                    break;
                
                default:
                printf("\n opcao invalida!");
                break;
              }
         
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









