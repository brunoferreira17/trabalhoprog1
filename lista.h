#ifndef lista
#define lista

#include "datatype.h"

int inserirProduto(ELEMENTO **iniLista, PRODUTO newInfo);

/*int removerProduto(ELEMENTO *iniLista, ELEMENTO *fimLista ,int nCodigo);

void listarPorNome(ELEMENTO *iniLista, int num_prod);

void listarPorMarca(ELEMENTO *iniLista, int num_prod);*/

void pesquisarPorNome(ELEMENTO *iniLista, char *nome);

#endif