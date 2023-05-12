#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "lista.h"
#include "datatype.h"

#define MAX_PROD 100

int inserirProduto(ELEMENTO **iniLista, PRODUTO newInfo){

    ELEMENTO *aux = NULL, *novo = NULL;
    novo = (ELEMENTO*) malloc (sizeof(ELEMENTO));

    if(novo == NULL){
        printf("ERRO ao alocar memÃ³ria");
        return -1;
    }

    novo->info = newInfo;
    novo->seguinte = NULL;

    if(*iniLista == NULL){

        *iniLista = novo;

    }else{

        aux = *iniLista;

        while(aux->seguinte != NULL){

            aux = aux->seguinte;
        }

        aux->seguinte = novo;
    }

    return 0;
}


/*int removerProduto(ELEMENTO *iniLista,ELEMENTO *fimLista, int nCodigo) {

    ELEMENTO *aux = NULL;
    ELEMENTO *anterior = NULL;

    while (aux != NULL && aux->info.codigo != nCodigo){
        aux = aux->seguinte;
    }

    if (aux == NULL) {
        printf("Produto nao encontrado.\n");
        return -1;
    }

    if (aux->anterior == NULL) {
        *iniLista = aux->seguinte;
        if(*iniLista != NULL){
            (*iniLista).anterior = NULL;
        }
    } else {
        aux->anterior->seguinte = aux->seguinte;
    }

    if (aux->seguinte == NULL) {
        *fimLista = aux->anterior;
        if (*fimLista != NULL) {
            (*fimLista).seguinte = NULL;
        } else {
            aux->seguinte->anterior = aux->anterior;
        }
    }

    free(aux);
    printf("Produto removido com sucesso.\n");
    return 0;
}


void listarPorNome(ELEMENTO *iniLista, int num_prod){
    int i, j;
    PRODUTO AUX;
    struct produto catalogo[MAX_PROD];
    ELEMENTO *aux = NULL;

    if(iniLista == NULL){
        printf("Lista vazia");
        return;
    }

    aux = iniLista;

    for(i = 0; i < num_prod-1; i++){
        for(j = 0; j < num_prod-i-1; j++){
            if(strcasecmp(catalogo[j].nome, catalogo[j+1].nome) > 0){
                AUX = catalogo[j];
                catalogo[j] = catalogo[j+1];
                catalogo[j+1] = AUX;
            }
        }
    }

    while(aux!=NULL){
        printf("\n%12ld%5s%12s%16.2f%12s%12s%5d%10s%12s\n", aux->info.codigo, aux->info.nome, aux->info.descricao, aux->info.preco, aux->info.marca, aux->info.modelo, aux->info.stock, aux->info.data, aux->info.categoria);
        aux = aux->seguinte;
    }

}


void listarPorMarca(ELEMENTO *iniLista, int num_prod){
    int i, j;
    PRODUTO AUX;
    struct produto catalogo[MAX_PROD];
    ELEMENTO *aux = NULL;

    if(iniLista == NULL){
        printf("Lista vazia");
        return;
    }

    aux = iniLista;

    for(i = 0; i < num_prod-1; i++){
        for(j = 0; j < num_prod-i-1; j++){
            if(strcasecmp(catalogo[j].marca, catalogo[j+1].marca) > 0){
                AUX = catalogo[j];
                catalogo[j] = catalogo[j+1];
                catalogo[j+1] = AUX;
            }
        }
    }

    while(aux!=NULL){
        printf("\n%12s%12ld%5s%12s%16.2f%12s%5d%10s%12s\n", aux->info.marca, aux->info.codigo, aux->info.nome, aux->info.descricao, aux->info.preco, aux->info.modelo, aux->info.stock, aux->info.data, aux->info.categoria);
        aux = aux->seguinte;
    }
}*/


void pesquisarPorNome(ELEMENTO *iniLista, char *nome) {

    ELEMENTO *aux = iniLista;

    while (aux != NULL) {
        if (strcmp(aux->info.nome, nome) == 0) {

            printf("\n%12s%12ld%5s%12s%16.2f%12s%5d%10s%12s\n", aux->info.marca, aux->info.codigo, aux->info.nome, aux->info.descricao, aux->info.preco, aux->info.modelo, aux->info.stock, aux->info.data, aux->info.categoria);
            return;
        }
        aux = aux->seguinte;
    }

    printf("Produto nÃ£o encontrado.\n");
}