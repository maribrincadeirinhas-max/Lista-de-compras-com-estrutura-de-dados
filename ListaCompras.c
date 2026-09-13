//-------------------Bibliotecas----------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

//---------------------Struct-------------------------
typedef struct{
    char nome[20];
    bool comprado;
}Produto;

typedef struct nodo{
    Produto info;
    struct nodo *prox_prod;
}Lista;

typedef struct{
    Lista *prim;
    Lista *ult;
}ComprasEstrutura;

//--------------------Protótipo-----------------------
void InicializarLista(ComprasEstrutura **estrutura);
int menu();
int Lista_vazia(Lista *prim);
int Incluir_produto_sempreFinal(Lista **prim, Lista **ult);
int Remover_produto(Lista **prim, Lista **ult);
int Marcar_produto(Lista **prim);
int Total_produtos(Lista *prim);
int Exibir_lista(Lista *prim);
int Desmarcar_produto(Lista **prim);

//----------------Programa Principal------------------
int main(){
    //Lista *prim = NULL;
    //Lista *ult = NULL;
    ComprasEstrutura *ListaCompras = NULL;
    InicializarLista(&ListaCompras);

    int opcao = 3;
    bool retorno;

    while(opcao != 0){

        opcao = menu();

        switch(opcao){
            case 1:{
                //retorno = Incluir_valor_sempreInicio(&prim);
                retorno = Incluir_produto_sempreFinal(&ListaCompras->prim, &ListaCompras->ult);
            }break;
            case 2:{
                retorno = Remover_produto(&ListaCompras->prim, &ListaCompras->ult);
            }break;
            case 3:{
                retorno = Exibir_lista(ListaCompras->prim);
            }break;
            case 4:{
                retorno = Marcar_produto(&ListaCompras->prim);
            }break;
            case 5:{
                retorno = Desmarcar_produto(&ListaCompras->prim);
            }break;
            case 6:{
                retorno = Total_produtos(ListaCompras->prim);
                printf("Total de produtos: %d\n", retorno);
            }break;
        }
    }

    printf("Sistema encerrado.");
}

//---------------------Funções------------------------
int Total_produtos(Lista *prim){
    int qtd = 0;

    Lista *aux = prim;
    while(aux != NULL){
        qtd++;
        aux = aux->prox_prod;
    }

    return qtd;
}

int Desmarcar_produto(Lista **prim){
    if(prim == NULL){
        printf("A lista esta vazia.");
        return false;
    }

    Lista *aux;
    int index = 1;
    char nome[20];

    printf("Informe o produto: ");
    scanf("%s", nome);
    nome[0] = toupper(nome[0]);

    aux = *prim;
    while(aux != NULL && strcmp(aux->info.nome, nome)){
        index++;
        aux = aux->prox_prod;
    }
    
    if (aux == NULL)
        printf("Produto nao encontrado.\n");
    else
        if (aux->info.comprado == false)
            printf("O produto ja esta desmarcado.");
        else{
        aux->info.comprado = false;
        printf("O produto %s foi desmarcado.\n", aux->info.nome);
        }

    return true;
}

int Marcar_produto(Lista **prim){
    if(prim == NULL){
        printf("A lista esta vazia.");
        return false;
    }

    Lista *aux;
    int index = 1;
    char nome[20];

    printf("Informe o produto: ");
    scanf("%s", nome);
    nome[0] = toupper(nome[0]);

    aux = *prim;
    while(aux != NULL && strcmp(aux->info.nome, nome)){
        index++;
        aux = aux->prox_prod;
    }
    
    if (aux == NULL)
        printf("Produto nao encontrado.\n");
    else
        aux->info.comprado = true;
        printf("O produto %s foi marcado como comprado.\n", aux->info.nome);

    return true;
}

int Remover_produto(Lista **prim, Lista **ult){
    Lista *pAnt, *aux;
    aux = *prim;
    pAnt = NULL;
    char nm[20];

    if(*prim == NULL){
        printf("Lista vazia.");
        return false;
    }

    printf("Informe o produto: ");
    scanf("%s", nm);
    nm[0] = toupper(nm[0]);

    while(strcmp(aux->info.nome, nm)){
        pAnt = aux;
        aux = aux->prox_prod;
    }

    if (aux == *prim){
        *prim = (*prim)->prox_prod;   
        aux->prox_prod = NULL;
        free(aux); 
    }
    else if(aux == *ult){
        *ult = pAnt;
        (*ult)->prox_prod = NULL;
        free(aux);
    }
    else{
        pAnt->prox_prod = aux->prox_prod;
        aux->prox_prod = NULL;
        free(aux); 
    }

    return true;
}

int Incluir_produto_sempreFinal(Lista **prim, Lista **ult){
    Lista *aux;
    int valor;
    char nome[20];

    aux = (Lista *) malloc(sizeof(Lista));
    if (aux == NULL){
        printf("Erro");
        return false;
    }
    

    printf("Informe o produto: ");
    scanf("%s", nome);
    nome[0] = toupper(nome[0]);

    strcpy(aux->info.nome, nome);
    aux->info.comprado = false;
    aux->prox_prod = NULL;

    if (*prim == NULL){  //Se a lista estiver vazia, então é o primeiro e ultimo elemento.
        *ult = aux;
        *prim = aux;
    }
    else {
        (*ult)->prox_prod = aux;
        *ult = aux;
    }

    printf("Produto adicionado com sucesso.\n");

    return true;
}

int Exibir_lista(Lista *prim){
    Lista *aux;
    aux = prim;

    if (Lista_vazia(aux)){
        printf("Nao ha produtos.");
        return false;
    }
    
    printf("Lista de compras: \n");
    while(aux != NULL){
        char *status = (aux->info.comprado) ? "- Comprado" : " ";
        printf("%s - %s\n", aux->info.nome, (aux->info.comprado) ? "Comprado" : " ");
        aux = aux->prox_prod;
    }
    return true;
}

int Lista_vazia(Lista *prim){
    if (prim ==NULL)
        return true;
    else
        return false;
}

void InicializarLista(ComprasEstrutura **estrutura){
    *estrutura = (ComprasEstrutura *)malloc(sizeof(ComprasEstrutura));

    (*estrutura)->prim = NULL;
    (*estrutura)->ult = NULL;
}

int menu(){
    int op;

    printf("\n-------MENU------\n");
    printf("1 - Adicionar Produto\n");
    printf("2 - Remover Produto\n");
    printf("3 - Exibir Produtos\n");
    printf("4 - Marcar Produto\n");
    printf("5 - Desmarcar Produto\n");
    printf("6 - Total\n");
    printf("0 - Sair\n");
    printf("-----------------\n");
    printf("Escolha: ");
    scanf("%d", &op);

    return op;
}