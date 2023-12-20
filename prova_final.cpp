#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// ALUNO: JOAO MARCOS VIEIRA DE MESQUITA CC 9


// aplicavel apesnas para letra minusculas na classificacao
typedef struct no
{
    char nome[50];
    float peso;
    int quantidade;
    char classificacao;
    int dia;
    int mes;
    int ano;
    struct  no *prox ;
    //struct No *ant;
} No;

No *cria_no(){
    No *novo = (No*)malloc(sizeof(No));
    novo->prox = NULL;
    char alimentacao = 'a',higiene = 'h',limpeza = 'l';
    

    printf("\n\n...Nome: ");
    fflush(stdin);
    fgets(novo->nome,50,stdin);
    printf("\n\n...Peso: ");
    scanf("%f",&novo->peso);
    printf("\n\n...Clacificacao: ");
    fflush(stdin);
    scanf("%c",&novo->classificacao);
    if (novo->classificacao == alimentacao || novo->classificacao == higiene|| novo->classificacao == limpeza )
    {
       printf("\n\n...Validade (dd/mm/aaaa): ");
       scanf("%d/%d/%d",&novo->dia,&novo->mes,&novo->ano);
    }
    printf("\n\n...Quantidade: ");
    scanf("%d",&novo->quantidade);
    
   
     return novo;
}

// verifica se tem alguem na lista, se nao, ensere o novo, se sim, ensere o novo sendo o primeiro da lista.
void inserir_inicio(No **cabeca,No *novo){
    No *aux = *cabeca;
    if (*cabeca == NULL) {
    (*cabeca) = novo;
    (*cabeca)->quantidade = novo->quantidade;
    printf("\n  1 inserido com sucesso!");
    return;
    }
    if (strcmp(aux->nome,novo->nome) == 0)
    {
     aux->quantidade += novo->quantidade;
      printf("\n  2 inserido com sucesso!");
     return;
    }
    

    else
    {
        while (aux != NULL)
        {
            
            
                if (strcmp(aux->nome,novo->nome) == 0)
            {
                aux->quantidade += novo->quantidade;
                return;
            }
   
            aux = aux->prox;
        }
        
            novo->prox = *cabeca ;
            *cabeca = novo;
  
            
        printf("\n  3 inserido com sucesso!");
        return;
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
        printf("\n%s",aux->nome);
        printf("%d",aux->quantidade);
        
        aux= aux->prox;
    }
    
}



void imprimir_relatorio(No **cabeca){
    No *aux = *cabeca;
    if(aux == NULL){
        printf("\n lista vazia!");
        return;
    }
    while (aux != NULL)
    {
        printf("\npeso: %.2f",aux->peso);
        printf("\nquantidade: %d",aux->quantidade);
        printf("\nclassificacao: %c",aux->classificacao);
        
        
        aux= aux->prox;
    }
    
}

void validade_memor(No **cabeca,int dia,int mes,int ano){
    No *aux = *cabeca;
    char alimentacao = 'a',higiene = 'h',limpeza = 'l';

    if (aux == NULL)
    {
        printf("\n Lista vazia!");
        return;
    }
    else
    {
        
    while (aux != NULL)
    {
      
      
      
        if( ano >= aux->ano ){
           
            if (mes >= aux->mes)
            {
                if (dia > aux->dia)
                {
                   if (aux->classificacao == alimentacao || aux->classificacao == higiene|| aux->classificacao == limpeza )
                        {
                         printf("\n nome: %s",aux->nome);
                         }
                    
                }
                
            }
            
        }
        aux = aux->prox;
    }
    
  }

}



// remover
void debitar(No **cabeca,char *busca,int quant){
    No *aux = *cabeca;
    
    if (aux == NULL)
    {
        printf("\n Lista vazia! ");
        return ;
    }
    

    else if (strcmp(aux->nome,busca) == 0)
    {
        
        if (  quant <= aux->quantidade){
           
             aux->quantidade -= quant;
             
          
            return;
        }
        else
        {
            printf("\n inposivel doar!!");
            return;
        }
        
        
    }
    else 
    {
        while (aux != NULL)
        {
            if (strcmp(aux->nome,busca) == 0)
            {
                if (quant <= aux->quantidade)
            {
                 aux->quantidade -= quant;
                 return;
            }
            else
            {
                 printf("\n inposivel doar!!");
                 return;
            }
            }
            
            
            
        aux = aux->prox;
            
        }
        
    }
  
        printf("\nNumero nao encontrado! ");
   
  

}

int menu(){
    int valor;
     printf("\n0. Para sair");
        printf("\n1. Inserir no");
        printf("\n2. imprimir relatorio");
        printf("\n3. validade menor");
        printf("\n4. debitar ");
        printf("\n   Digite: ");
        scanf("%d",&valor);
        return valor;
 }



int main()
{
    No *cabeca = NULL;
    char nome[30];
    int quantidade,m,ordem,d,mes,a;

         do
    {
         m = menu();
        
        switch (m)
        {
        case 1:
        
           inserir_inicio(&cabeca,cria_no());
      
            break;
        case 2:
              
            imprimir_relatorio(&cabeca);
               
            break;
        case 3:
        printf("\nInsira a data: ");
        scanf("%d/%d/%d",&d,&mes,&a);
        
             validade_memor(&cabeca,d,mes,a);
            break;
        case 4:
         printf("\nInsira o nome do produto: ");
        fflush(stdin);
        fgets(nome,30,stdin);
        printf("\nInsira a quantidade a ser removida: ");
        scanf("%d",&quantidade);
        debitar(&cabeca,nome,quantidade);
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
