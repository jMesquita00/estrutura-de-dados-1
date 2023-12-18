
// lista simples onde tem os metodos de criar_no  ,inserir no inicio, meio e fim, e imprimir, inserir ordenado, remover  

/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct no
{
    int conteudo;
    struct  no *prox ;
    //struct No *ant;
} No;

No *cria_no(){
    No *novo = (No*)malloc(sizeof(No));
    novo->prox = NULL;


    printf("\n\n...Titulo: ");
    scanf("%d",&novo->conteudo);
   
     return novo;
}

// verifica se tem alguem na lista, se nao, ensere o novo, se sim, ensere o novo sendo o primeiro da lista.
void inserir_inicio(No **cabeca,No *novo){
    if (*cabeca == NULL) {
    (*cabeca) = novo;
    printf("\n inserido com sucesso!");
    return;
    }
    else
    {
        novo->prox = *cabeca;
        *cabeca = novo;
         printf("\n inserido com sucesso!");
        return;
    }
    
    
}

// verifica se tem algem na lista, so ensere se tiver 2 ou +, entre eles, sempre apos o primeiro
void inserir_meio(No **cabeca, No *novo){
    No *aux = *cabeca;
if(aux == NULL){
    printf("\n ERRO! nao inserido!");
    return;
}
if(aux != NULL){
    novo->prox = aux->prox;
    //(*cabeca)->prox->ant = novo;
    aux->prox = novo;
   // novo->ant = (*cabeca);
    printf("\n inserido com sucesso!");
    return;
}
}
// verifica se tem alguem na lista, se nao enseri,se tiver percorre ate o ultimo e ensere o novo ultimo.
void inserir_fim(No **cabeca, No *novo){
    No *aux = *cabeca;
    if (aux == NULL)
    {
        printf("\n  lista vazia!");
        *cabeca = novo;
        printf("\n  inserido com sucesso!");
        return;
    }
    
    while (aux != NULL)
    {
        if(aux->prox == NULL){
            novo->prox = NULL;
            aux->prox = novo;
            printf("\n  inserido com sucesso!");
    
            return;
        }
        aux = aux->prox;
    }
    
}
 //funçao de imprimir  onde usa um aux para percorre e imprime  cada elemento da lista enquanto for diferente de nulo.
void imprimir(No **cabeca){
    No *aux = *cabeca;
    if(aux == NULL){
        printf("\n lista vazia!");
        return;
    }
    while (aux != NULL)
    {
        printf(" %d -> ", aux->conteudo);
        aux= aux->prox;
    }
    
}

// inserir ordenado
void inseir_ordenado(No **cabeca,No *novo){
 No *aux = *cabeca;
    if(aux == NULL){
        *cabeca = novo; 
        return;
    }
    else if (novo->conteudo < aux->conteudo)
    {
        novo->prox = *cabeca;
        *cabeca = novo;
    }
    else
    {
        while (aux->prox != NULL)
        {
            if (novo->conteudo < aux->prox->conteudo)
            {
                novo->prox = aux->prox;
                aux->prox = novo;
                return;
            }

        aux = aux->prox;
            
        }
        
        novo->prox = NULL;
        aux->prox = novo;

        

    }
    
}

// remover
No* remover_no(No **cabeca, int num){
    No *rem = NULL,*aux = *cabeca;
    if (aux == NULL)
    {
        printf("\n Lista vazia! ");
        return NULL;
    }
    

    else if (aux->conteudo == num)
    {
        *cabeca = aux->prox;
        aux->prox = NULL;
        rem = aux;
        return rem;
    }
    else 
    {
        while (aux->prox != NULL)
        {
            if (num == aux->prox->conteudo)
            {
                 rem = aux->prox;
                 aux->prox = rem->prox;
                 return rem;
            }
        aux = aux->prox;
            
        }
        
    }
    
    if (rem == NULL)
    {
        printf("\nNumero nao encontrado! ");
    }
    

}

int menu(){
    int valor;
     printf("\n0. Para sair");
        printf("\n1. Inserir no");
        // printf("\n2. Remover");
        printf("\n2. imprimir ");
        printf("\n3. Inserir ordenado");
        printf("\n4. remover ");
        printf("\n   Digite: ");
        scanf("%d",&valor);
        return valor;
 }

 int menu_1(){
    int valor;
     printf("\n0. Para sair");
        printf("\n1. Inserir inicio");
        printf("\n2. Inserir meio");
        printf("\n3. Inserir fim");
        printf("\n   Digite: ");
        scanf("%d",&valor);
        return valor;
 }

int main(int argc, char const *argv[])
{
    No *cabeca = NULL;
 
    int quantidade,m,ordem,remover;

         do
    {
         m = menu();
        
        switch (m)
        {
        case 1:
        int a;
        a = menu_1();
           switch (a)
           {
           case 1:
           inserir_inicio(&cabeca,cria_no());
            break;
           case 2: 
           inserir_meio(&cabeca,cria_no());
            break;
           case 3:
           inserir_fim(&cabeca,cria_no());
            break;
           
           default:
           printf("\nERRO! INSIRA ENTRE 1 A 3!");
            break;
           }
            break;
        case 2:
              
            imprimir(&cabeca);
               
            break;
        case 3:
            inseir_ordenado(&cabeca,cria_no());
            break;
        case 4:
        printf("\nInsira o numero a ser removido: ");
        scanf("%d",&remover);
        No *rem;
           rem =  remover_no(&cabeca,remover);
            printf("\nO numero removido: %d",rem->conteudo);
            break;
        
        case 0:
            printf("\n\nSAINDO....");
            return 0;
            break;
        
        default:
        printf("\nOpcao invalida!\n");
            break;
        }
    } while (m != 0);
    
    return 0;
}


*/


/////////////////////////////////////////////////////////////////////////////////////////////////////////



// lista duplamente encadeada com os metodos de cria_no, enserir  inicio, meio, fim, ordenado, imprimir, remover


/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no
{
    int conteudo;
    struct  no *prox ;
    struct no *ant;
} No;

No *cria_livro(){
    No *novo = (No*)malloc(sizeof(No));
    novo->prox = NULL;
    novo->ant = NULL;

    printf("\n...Insira um numero: ");
    scanf("%d",&novo->conteudo);
    
     return novo;
}
void inserir_inicio(No **cabeca,No *novo){
  
   if (*cabeca == NULL) 
   {
    *cabeca = novo;
    return;
   }
   else
   {
    novo->prox = *cabeca;
    (*cabeca)->ant  = novo;
    *cabeca = novo;
    printf("\n Inseirdo com sucesso!");
    return;
   }
}

void inserir_meio(No **cabeca, No *novo){
    No *aux = *cabeca;
    if(aux  && aux->prox != NULL)
    {
        novo->prox = aux->prox;
        aux->prox->ant = novo;
        aux->prox = novo;
        novo->ant = aux;
        return;
    }
}

void inserir_fim(No **cabeca, No *novo){
    No *aux = *cabeca;
    if(aux == NULL){
        *cabeca = novo;
        return;
    }
    else
    {
        while (aux != NULL)
        {
           if(aux->prox == NULL){
            novo->prox = aux->prox;
            aux->prox = novo;
            novo->ant = aux;
            return;
           }
           aux = aux->prox;
        }
        
    }
    
}

void inser_ordenado(No **cabeca, No *novo){
    No *aux = *cabeca;
    if (aux ==  NULL)
    {
        *cabeca = novo;
        return;
    }
    else if (novo->conteudo < aux->conteudo)
    {
        novo->prox = aux;
        aux->ant = novo;
        *cabeca = novo;
        return;
    }
    
    else
    {
     
        while (aux->prox != NULL)
        {
              
            if (novo->conteudo < aux->prox->conteudo)
            {
                novo->prox = aux->prox;
                aux->prox->ant = novo;
                aux->prox = novo;
                novo->ant = aux;
                return;
            }
            else if (aux->prox->prox == NULL)
            {
                novo->prox = aux->prox->prox;
                aux->prox->prox  = novo;
                novo->ant = aux->prox;
                return;
            }
            aux = aux->prox;
        }
        if (novo->conteudo > aux->conteudo){
        novo->prox = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
        return;
        }
    }
    
    printf("\n Erro  nao inserido!!!!");
    
}
void imprimir(No **cabeca){
  No *aux = *cabeca;
  if (aux == NULL)
  {
    printf("\n Lista vazia!");
    return;
  }
  while (aux != NULL)
  {
    printf(" %d -> ",aux->conteudo);
    aux = aux->prox;
  }
  
  
}

void imprimir_reverso(No **cabeca){
  No *aux = *cabeca;
  if (aux == NULL)
  {
    printf("\n Lista vazia!");
    return;
  }
  while (aux->prox != NULL)
  { 
    aux = aux->prox;
  }
  if (aux->prox == NULL)
  {
    while (aux != NULL)
    {
       printf(" %d -> ",aux->conteudo);
       aux = aux->ant;
    }
  }
  return;
}

No *remover(No **cabeca, int remove){
No *rem = NULL,*aux = *cabeca;
if (aux == NULL)
{
    printf("\n Lista vazia! ");
    return NULL;
}
else if (aux->conteudo == remove)
{
    *cabeca = aux->prox;
    rem = aux;
    aux->prox = NULL;
    aux->ant = NULL;
    return rem;
}

else
{ 
    while (aux->prox != NULL)
    {
        if (aux->prox->prox == NULL)
        {
            rem = aux->prox;
            aux->prox = NULL;
        return rem;
        }
        if (aux->prox->conteudo == remove)
        {
           rem = aux->prox;
           aux->prox = aux->prox->prox;
           aux->prox->ant = aux;         
           return rem;
        }
        
        
        
        aux = aux->prox;
    }
    
    
   
    
}
printf("\nNumero nao encontrado! ");

}

int menu(){
    int num;
    printf("\n0. Para sair");
        printf("\n1. Inserir no");
        printf("\n2. imprimir ");
        printf("\n3. imprimir reverso");
        printf("\n4. remover ");
        printf("\n5. inserir ordenado ");
        printf("\n   Digite: ");
        scanf("%d",&num);
    return num;
}

int menu1(){
    int num;
    printf("\n0. Para sair");
        printf("\n1. Inserir no inicio ");
        printf("\n2. Inserir no meio ");
        printf("\n3. Inserir no fim ");
        printf("\n   Digite: ");
        scanf("%d",&num);
    return num;
}
int main(int argc, char const *argv[])
{
    
    No *cabeca = NULL, *rem;
    char procura_isbn [50];
    char procura_autor [50];
    int quantidade,valor,ordem,remo;

     do
    {
        valor = menu();
        
        switch (valor)
        {
        case 1:
        int d;
            d = menu1();
            switch (d)
            {
            case 1:
                inserir_inicio(&cabeca,cria_livro());
                break;
            case 2:
                inserir_meio(&cabeca,cria_livro());
                break;
            case 3:
                inserir_fim(&cabeca,cria_livro());
                break;
            
            default:
                 printf("\nOpcao invalida!\n");
                break;
            }
           
            break;
        case 2:
                imprimir(&cabeca);
            break;
        case 3:
              imprimir_reverso(&cabeca);
            break;
        
        case 4:
            printf("\nInsira o numero a ser removido: ");
            scanf("%d",&remo);
           rem =  remover(&cabeca,remo);
           printf("\nO removido foi: %d",rem->conteudo);
            break;
        case 5:
            inser_ordenado(&cabeca,cria_livro());
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


*/









///////////////////////////////////////////////////////////////////////////////////////////////////////////

// exemplo de lista duplamente encadeada aplicado para um programa de uma bibioteca.
/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Livro
{
    char titulo [50];
    char autor [50];
    char isbn [50];
    int ano;
    int quant;
    struct  Livro *prox ;
    struct Livro *ant;
} livro;

livro *cria_livro(){
    livro *novo = (livro*)malloc(sizeof(livro));
    novo->prox = NULL;
    novo->ant = NULL;

    
    printf("\n\n...Titulo: ");
    fflush(stdin);
    fgets(novo->titulo,50,stdin);
    //scanf(" s[^/n]%",&novo->titulo);
    printf("\n...Autor:  ");
    fflush(stdin);
    fgets(novo->autor,50,stdin);
    //scanf("%s",&novo->autor);
    printf("\n...Ano (aaaa): ");
    scanf("%d",&novo->ano);
    printf("\n...ISBN: ");
    scanf("%s",&novo->isbn);
    printf("\n...Quantidade: ");
    scanf("%d",&novo->quant);
     return novo;
}
void inserir_ordem_a_z(livro **cabeca,livro *novo){
    livro *aux = *cabeca;
 if(aux == NULL){
    novo->prox = NULL;
    novo->ant = NULL;
    *cabeca = novo;
    return;
 }
else if (strcmp(novo->titulo,aux->titulo) == 0 )
    {
        int soma,atual;
       atual = aux->quant;
        printf("\n insira a quantidade a ser acrescentada:");
    scanf("%d",&soma);
    aux->quant = soma + atual;
    
    return;
    }
 
 else if (strcmp( aux->titulo,novo->titulo ) == 1  )
 {
    
    
    novo->prox = aux;
    aux->ant = novo;
    *cabeca = novo;
    return;
    
 }


 else {
    
    while (aux->prox != NULL)
    {
        if (strcmp(novo->titulo,aux->prox->titulo) == 0)
        {
            int soma,atual;
            atual = aux->prox->quant;
           printf("\n insira a quantidade a ser acrescentada:");
           scanf("%d",&soma);
           aux->prox->quant = soma + atual;
           return;
        }
        

        else if (strcmp( aux->prox->titulo,novo->titulo) == 1 )
        {
           novo->prox = aux->prox;
            aux->prox->ant = novo;
            aux->prox = novo;
            novo->ant = aux;
        return;
        }
         aux = aux->prox;
        
    }
    if (strcmp(aux->titulo , novo->titulo) == 0)
    {
        int soma,atual;
        atual = aux->quant;
        printf("\n insira a quantidade a ser acrescentada:");
           scanf("%d",&soma);
           aux->quant = soma +atual;
           return;
    }
    

    novo->prox = NULL;
    aux->prox = novo;
    novo->ant = aux;
    return;
    
 }
 
   
}
void inserir_ordem_z_a(livro **cabeca,livro *novo){
    livro *aux = *cabeca;
 if(aux == NULL){
    novo->prox = NULL;
    novo->ant = NULL;
    *cabeca = novo;
    return;
 }
else if (strcmp(aux->titulo,novo->titulo) == 0 )
    {
        int soma,atual;
       atual = aux->quant;
        printf("\n insira a quantidade a ser acrescentada:");
    scanf("%d",&soma);
    aux->quant = soma + atual;
    
    return;
    }
 
 else if (strcmp( novo->titulo,aux->titulo ) == 1  )
 {
    
    
    novo->prox = aux;
    aux->ant = novo;
    *cabeca = novo;
    return;
    
 }


 else {
    
    while (aux->prox != NULL)
    {
        if (strcmp(aux->prox->titulo,novo->titulo) == 0)
        {
            int soma,atual;
            atual = aux->prox->quant;
           printf("\n insira a quantidade a ser acrescentada:");
           scanf("%d",&soma);
           aux->prox->quant = soma + atual;
           return;
        }
        

        else if (strcmp(novo->titulo,aux->prox->titulo) == 1 )
        {
           novo->prox = aux->prox;
            aux->prox->ant = novo;
            aux->prox = novo;
            novo->ant = aux;
        return;
        }
         aux = aux->prox;
        
    }
    if (strcmp(novo->titulo,aux->titulo) == 0)
    {
        int soma,atual;
        atual = aux->quant;
        printf("\n insira a quantidade a ser acrescentada:");
           scanf("%d",&soma);
           aux->quant = soma +atual;
           return;
    }
    

    novo->prox = NULL;
    aux->prox = novo;
    novo->ant = aux;
    return;
    
 }
 
   
}
void inserir_a_z( livro **cabeca){
    livro *novo = cria_livro();
    inserir_ordem_a_z(cabeca,novo);
 }
 void inserir_z_a( livro **cabeca){
    livro *novo = cria_livro();
    inserir_ordem_z_a(cabeca,novo);
 }
void busca_isbn (livro **cabeca ,char *procura){
    livro *aux = *cabeca;

 if (aux == NULL)
 {
    printf("\n ....No Vazia!.....\n");
    return;
 }
 else if (strcmp(procura, aux->isbn) == 0)
 {
    //imprimir(&aux);//
     
            printf("\nTITULO: %s",aux->titulo);
            printf("\nAUTOR: %s",aux->autor);
            printf("\nISBN: %s",aux->isbn);
            printf("\nANO: %d",aux->ano);
            printf("\nQUANTIDADE : %d",aux->quant);
            return;
        }
 else
    while (aux->prox != NULL)
    {
       if (strcmp(aux->prox->isbn,procura) == 0)
       {
        //imprimir(&aux->prox);//
         
            printf("\nTITULO: %s",aux->prox->titulo);
            printf("\nAUTOR: %s",aux->prox->autor);
            printf("\nISBN: %s",aux->prox->isbn);
            printf("\nANO: %d",aux->prox->ano);
            printf("\nQUANTIDADE : %d",aux->prox->quant);
            return;
        }
        
       
       aux = aux->prox;
       
    }
    if (strcmp(aux->prox->isbn,procura) == 0)
       {
        //imprimir(&aux->prox);//
         
            printf("\nTITULO: %s",aux->titulo);
            printf("\nAUTOR: %s",aux->autor);
            printf("\nISBN: %s",aux->isbn);
            printf("\nANO: %d",aux->ano);
            printf("\nQUANTIDADE : %d",aux->quant);
            return;
        }
    
    
    printf("\n Livro nao encontrado!");
    return;
 
 
}
void busca_autor (livro **cabeca, char *procura){
    livro *aux = *cabeca;
    if (aux == NULL){
         printf("\nLista Vazia!");
        return;
    }
    else{
        while (aux!=NULL){
            if (strcmp(procura, aux->autor) == 0){
               printf("\nTITULO: %s",aux->titulo);
            }
            aux = aux->prox;
        }
        return;

    }
    
    printf("\nnao encontrado");
    

}
void remover (livro **cabeca , char *procura , int quantidade){
    livro *aux = *cabeca;
    if (aux == NULL)
    {
       printf("\nlista vazia!");
       return;
    }
    else if (strcmp(procura,aux->isbn) == 0)
    {
       if ( aux->quant > quantidade)
       {
        aux->quant = aux->quant - quantidade;
        return;
       }
        else
        {
        if (aux->prox == NULL)
        {
             *cabeca = NULL;
             return;
        }

       else{
        aux->prox->ant = NULL;
         *cabeca = aux->prox;
         
         return;

       } 
         
        }
       
    }
    else
    {
        while (aux->prox != NULL)
        {
            if (strcmp(aux->prox->isbn,procura) == 0)
            {
                if (aux->prox->prox == NULL)
                {
                    
                    aux->prox = NULL;
                    return;
                }
                else if (aux->prox->quant > quantidade)
                {
                    aux->prox->quant = aux->prox->quant - quantidade;
                    return;
                }
                
                else
                {
printf("OPA 2") ; 
                    if (aux->prox->prox != NULL)
                    {
                        printf("\naux->prox->prox exixte\n ");
                        aux->prox = aux->prox->prox;
                        aux->prox->ant = aux->prox;
                    return;
                    }
                    else
                    aux->prox = NULL;
                    return;
                }
                
                
                
                
            }
            aux = aux->prox;
            
        }
        
    }

}
void imprimir(livro **cabeca){
    livro *aux = *cabeca;
    if (aux==NULL)
    {
       printf("\n\nLista vazia!\n\n");
        return;
    }
    else
    { 
        printf("...........IMPRIMINDO...........");
        while (aux!= NULL)
        {
            
            printf("\n\n\n\n\nTITULO: %s",aux->titulo);
            printf("\nAUTOR: %s",aux->autor);
            printf("\nISBN: %s",aux->isbn);
            printf("\nANO: %d",aux->ano);
            printf("\nQUANTIDADE : %d\n\n",aux->quant);
            aux = aux->prox;
        }
        
    } return;
    
    
}
void imprimir_z_a(livro **cabeca){
    livro *aux = *cabeca;
    if (aux == NULL)
    {
       printf("\nLista Vazia!");
       return;
    }
    else
    { 
        while (aux->prox != NULL)
        {
           aux = aux->prox;
        }
        if(aux->prox == NULL){
            while (aux != NULL)
            {
                printf("\n\n\n\n\nTITULO: %s",aux->titulo);
            //printf("\nAUTOR: %s",aux->autor);
           // printf("\nISBN: %s",aux->isbn);
            //printf("\nANO: %d",aux->ano);
            //printf("\nQUANTIDADE : %d\n\n",aux->quant);
            aux = aux->ant;
               
            }
            
        }
        

    }return;
    
}
int main(int argc, char const *argv[])
{
    
    livro *cabeca = NULL;
    char procura_isbn [50];
    char procura_autor [50];
    int quantidade,valor,ordem;

     do
    {
        printf("\n0. Para sair");
        printf("\n1. Inserir livro");
        printf("\n2. Remover");
        printf("\n3. imprimir (a-z)");
        printf("\n4. imprimir (z-a)");
        printf("\n   Digite: ");
        scanf("%d",&valor);
        
        switch (valor)
        {
        case 1:
           
            inserir_a_z(&cabeca);
                

            break;
        case 2:
                printf("\n Insira ISBN do livro: ");
                scanf("%s",&procura_isbn);

                printf("\n Insira a quantidade a ser removida: ");
                scanf("%d",&quantidade);
     
                remover(&cabeca,procura_isbn,quantidade);
        
            break;
        case 3:
                imprimir(&cabeca);
            break;
        
        case 4:
                imprimir_z_a(&cabeca);
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




*/



///////////////////////////////////////////////////////////////////////////////////////////


// lista circular com metodos de enserir, no inicio meio e fim, ordenado, imprimir, remover 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no
{
    int conteudo;
    struct  no *prox ;
    struct no *ant;
} No;
typedef struct 
{
    No *inicio = NULL;
    No *fim = NULL;
    int tam = 0;
} lista;

No *cria_livro(){
    No *novo = (No*)malloc(sizeof(No));
    novo->prox = NULL;
    novo->ant = NULL;

    printf("\n...Insira um numero: ");
    scanf("%d",&novo->conteudo);
    
     return novo;
}

void inserir_inicio(lista * lista,No **cabeca,No *novo){
    if (*cabeca == NULL)
    {
        *cabeca = novo;
        novo->prox = novo;
        novo->ant = novo;
        lista->inicio = novo;
        lista->fim = novo;
        return;
    }
    else
    {
        novo->prox = *cabeca;
        novo->ant = (*cabeca);
        (*cabeca)->prox = novo;
        (*cabeca)->ant = novo;
        (*cabeca) = novo;
        lista->inicio = novo;
        
        return;
    }
    
}

void iserir_no_fim_plus(lista *lista,No **cabeca,No *novo){
   No *aux = *cabeca; 
  if (*cabeca == NULL)
    {
        *cabeca = novo;
        novo->prox = novo;
        novo->ant = novo;
        lista->inicio = novo;
        lista->fim = novo;
        return;
    }
    else
    {
        aux->ant->prox = novo;
        novo->ant = aux->ant;
        novo->prox = aux;
        aux->ant = novo;
        lista->fim = novo;
        return;
        
    }
    
    
    
}
 void inserir_fim(lista *lista,No **cabeca, No *novo){
    No *aux = *cabeca;
    if (*cabeca == NULL)
    {
        *cabeca = novo;
        novo->prox = novo;
        novo->ant = novo;
        lista->inicio = novo;
        lista->fim = novo;
        return;
    }
    else
    {
        do
        {
            if (aux->prox == lista->inicio)
            {
                novo->prox = lista->inicio;
                lista->inicio->ant = novo;
                novo->ant = aux;
                aux->prox = novo;
                lista->fim = novo;
                return;

                
       
            }
            aux = aux->prox;
            
        } while (aux != lista->inicio);
        
        
    }
    
 }

 void inserir_meio(lista *lista,No **cabeca,No *novo){
    No *aux = *cabeca;
    if (lista->inicio != NULL && lista->fim != NULL && lista->inicio != lista->fim)
    {
       novo->prox = aux->prox;
       novo->prox->ant = novo;
       aux->prox = novo;
       novo->ant = aux;
       return;
    }
    
 }
 void imprimir(lista *lista,No **cabeca){
    No *aux = *cabeca;
    if (*cabeca == NULL)
    {
        printf("\n lista vazia! ");
        return;
    }
    else
    {
        do
        {
           printf(" %d -> ",aux->conteudo);
           aux = aux->prox;
        } while (aux != lista->inicio);
        
        
    }
    
    
 }

 void inserir_ordenado(lista *lista,No **cabeca,No *novo){
    No *aux = *cabeca;
    if (aux == NULL)
    {
       *cabeca = novo;
       novo->prox = novo;
       novo->ant = novo;
       lista->inicio = novo;
       lista->fim = novo;
       return;
    }
    else if (novo->conteudo < aux->conteudo)
    {
        novo->prox = aux;
        novo->ant = aux;
       
        aux->ant->prox = novo;
         aux->ant = novo;
        lista->inicio = novo;
        *cabeca = novo;
        return;
    }
    
    
    else
    {
        
        
        
        do
        {
            if (novo->conteudo < aux->prox->conteudo)
            {
                
                novo->prox = aux->prox;
                novo->ant = aux;
                aux->prox = novo;
                novo->prox->ant= novo;
                return;
               
            }
            
            else if (aux->prox == lista->inicio)
            {
                novo->prox = aux->prox;
                novo->ant = aux;
                aux->prox = novo;
                novo->prox->ant = novo;
                lista->fim = novo;
                return;
            }
            
            
            
            
            aux = aux->prox;
        } while (aux != lista->inicio);
        
        
    }
    
    
    
 }

 No *remover(lista *lista,No **cabeca,int rem){
    No *remove,*aux = *cabeca;
    if (*cabeca == NULL)
    {
        printf("\nLista vazia!");
        return NULL;
    }
    if (aux->conteudo == rem  && lista->fim == lista->inicio)
    {
        remove = aux;
        
        lista->inicio = NULL;
        lista->fim = NULL;
        *cabeca = NULL;
        return remove;
    }
    if (aux->conteudo == rem )
    {
        remove = aux;
        aux->ant->prox =  aux->prox;
        aux->prox->ant = aux->ant;
        lista->inicio = aux->prox;
        *cabeca = aux->prox;
        return remove;
    }
    
    else
    {
        do
        {
            if (aux->prox->conteudo == rem && aux->prox == lista->fim)
            {
                remove = aux->prox;
                aux->prox = aux->prox->prox;
                aux->prox->ant = aux;
                lista->fim = aux;
                return remove;
            }
            
             else if (aux->prox->conteudo == rem)
            {
                remove = aux->prox;
               aux->prox = aux->prox->prox;
               aux->prox->ant = aux;
               return remove;

            }
            aux =aux->prox;
        } while (aux != lista->inicio);
        
    }
    
    
 }
int menu(){
    int num;
    printf("\n0. Para sair");
        printf("\n1. Inserir no");
        printf("\n2. imprimir ");
        printf("\n3. imprimir reverso");
        printf("\n4. remover ");
        printf("\n5. inserir ordenado ");
        printf("\n   Digite: ");
        scanf("%d",&num);
    return num;
}

int menu1(){
    int num;
    printf("\n0. Para sair");
        printf("\n1. Inserir no inicio ");
        printf("\n2. Inserir no meio ");
        printf("\n3. Inserir no fim ");
        printf("\n   Digite: ");
        scanf("%d",&num);
    return num;
}
int main(int argc, char const *argv[])
{
    lista a;
    No *cabeca = NULL, *rem;
    char procura_isbn [50];
    char procura_autor [50];
    int quantidade,valor,ordem,remo;

     do
    {
        valor = menu();
        
        switch (valor)
        {
        case 1:
        int d;
            d = menu1();
            switch (d)
            {
            case 1:
                inserir_inicio(&a,&cabeca,cria_livro());
                break;
            case 2:
                inserir_meio(&a,&cabeca,cria_livro());
                break;
            case 3:
                iserir_no_fim_plus(&a,&cabeca,cria_livro());
                break;
            
            default:
                 printf("\nOpcao invalida!\n");
                break;
            }
           
            break;
        case 2:
                imprimir(&a,&cabeca);
            break;
        case 3:
              //imprimir_reverso(&cabeca);
            break;
        
        case 4:
            printf("\nInsira o numero a ser removido: ");
            scanf("%d",&remo);
           rem =  remover(&a,&cabeca,remo);
           printf("\nO removido foi: %d",rem->conteudo);
            break;
        case 5:
            inserir_ordenado(&a,&cabeca,cria_livro());
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


