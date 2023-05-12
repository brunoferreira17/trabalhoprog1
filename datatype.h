
#ifndef DATATYPE
#define DATATYPE

//Struct que guardará informação de cada porduto do catalogo
typedef struct produto{
    long codigo;
    char nome[100];
    char descricao[300];
    float preco;
    char marca[50];
    char modelo[50];
    int stock;
    char data[10];
    char categoria[50];

}PRODUTO;

//Struct que guardará a informação de cada cliente
typedef struct cliente{

    char nome[100];
    char endereco[150];
    char email[80];
    char telemovel[10];
}c;


typedef struct elemento{

    PRODUTO info;
    struct elemento *seguinte;
    struct elemento *atual;
    struct elemento *anterior;

}ELEMENTO;

#endif
