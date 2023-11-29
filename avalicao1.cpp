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
    printf("\n ....Lista Vazia!.....\n");
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
                    printf("\nOPA 15\n");
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















/*


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct livro
{
    char titulo [50];
    char autor [50];
    char isbn [50];
    int ano;
    int quant;
    struct  livro *prox ;
    struct livro *ant;
} livro;
livro *cria_livro(){
    livro *novo = (livro*)malloc(sizeof(livro));
    novo->prox = NULL;
    novo->ant = NULL;

    printf("\n\n...Titulo: ");
    scanf("%s",&novo->titulo);
    printf("\n...Autor:  ");
     scanf("%s",&novo->autor);
    printf("\n...Ano (aaaa): ");
     scanf("%d/%d/%d",&novo->ano);
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
    printf("\n ....Lista Vazia!.....\n");
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
        printf("\nremovido com sucesso!");
        return;
       }
        else
        {

            if (aux->prox != NULL)
            {
                aux->prox->ant = NULL;
            }
            
            *cabeca = aux->prox;
          printf("\nRemovido com sucesso!");
        
         
         return;
        }
       
    }
    else
    {
        while (aux->prox != NULL)
        {
            if (strcmp(aux->prox->isbn,procura) == 0)
            {
                if (aux->prox->quant > quantidade)
                {
                   
                    aux->prox->quant = aux->prox->quant - quantidade;
                     printf("\nRemovido com sucesso!");
                    return;
                }
                else
                {


                    aux->prox = aux->prox->prox;
                    if (aux->prox != NULL)
                    {
                       
                        aux->prox->ant = aux->prox;//
                        printf("\nRemovido com sucesso!");
                    }
                    
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
       printf("\nLista vazia!\n\n");
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
            printf("\nAUTOR: %s",aux->autor);
            printf("\nISBN: %s",aux->isbn);
            printf("\nANO: %d",aux->ano);
            printf("\nQUANTIDADE : %d\n\n",aux->quant);
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
            //printf("\n1. Ordem (a-z)");
            //printf("\n2. Ordem (z-a)");
           // printf("\nDigite: ");
            //scanf("%d",&ordem);
            //switch (ordem)
            //{
           // case 1:
            inserir_a_z(&cabeca);
               // break;
                //case 2:
                //inserir_z_a(&cabeca);
                //break;
            
            //default: printf("\nopcaa invalida!\n");
             //   break;
           // }

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
}*/