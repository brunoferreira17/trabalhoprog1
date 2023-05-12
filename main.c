#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

#define MAX_PROD 100

#include "lista.h"
#include "datatype.h"


int menu(){

    int op=0;


    printf("\n\nSelecione uma opcao:\n");
    printf("1. Inserir um produto\n");
    printf("2. Alterar informaÃ§Ãµes sobre produto\n");
    printf("3. Remover produto\n");
    printf("4. Listar todos os produtos em ordem alfabÃ©tica pelo nome\n");
    printf("5. Listar todos os produtos em ordem alfabÃ©tica pela marca\n");
    printf("6. Pesquisar produtos por nome\n");
    printf("7. Pesquisar produtos por categoria\n");
    printf("8. Fazer relatÃ³rio dos produtos com baixo stock\n");
    printf("9. \n");
    printf("10. \n");
    printf("11. \n");
    printf("0. Sair do programa\n");
    scanf("%d", &op);
    fflush(stdin);

    return op;

}


void alterarpoduto(ELEMENTO **iniLista, int num_prod){

    struct produto catalogo[MAX_PROD];
    int opcao=0, indice = -1;
    long nCodigo=0;

    if(iniLista == NULL){
        return;
    }

    printf("\nInsira o cÃ³digo do produto que deseja alterar: ");
    scanf("%ld", &nCodigo);
    fflush(stdin);
    for(int i =0; i < num_prod; i++){
        if(catalogo[i].codigo == nCodigo){
            printf("\nProduto encontrado!");
            printf("\nQue informaÃ§Ãµes deseja alterar?");
            printf("\n0 - PreÃ§o");
            printf("\n1 - DescriÃ§Ã£o");
            printf("\n2 - Stock");
            printf("\n3 - Data de adiÃ§Ã£o");
            printf("\nInsira a opÃ§Ã£o que pretende alterar: ");
            scanf("%d", &opcao);
            fflush(stdin);

            switch(opcao){
                case 0:
                    printf("\nDigite o novo preÃ§o do produto: ");
                    scanf("%f", &catalogo[indice].preco);
                    fflush(stdin);
                case 1:
                    printf("\nDigite a nova descriÃ§Ã£o do produto: ");
                    scanf("%[^\n]", &catalogo[indice].descricao);
                    fflush(stdin);
                case 2:
                    printf("\nDigite o novo stock do produto: ");
                    scanf("%d", &catalogo[indice].stock);
                    fflush(stdin);
                case 3:
                    printf("\nDigite a nova data de adiÃ§Ã£o do produto: ");
                    scanf("%[^\n]", &catalogo[indice].data);
                    fflush(stdin);
                default:
                    printf("\nERRO!! Insira uma opÃ§Ã£o vÃ¡lida");
            }
        }else {
            printf("\nERRO!! NÃ£o existe nenhum produto com esse cÃ³digo");
        }
    }
}


int main(){

    setlocale(LC_ALL, "Portuguese");

    ELEMENTO *iniLista = NULL;
    ELEMENTO *fimLista = NULL;
    int res, op, nCodigo;
    int i;
    int num_prod=0;
    char nome;
    PRODUTO p;
    struct produto catalogo[MAX_PROD];


    do{
        system("cls");
        op = menu();

        switch (op){
            case 1 :
                printf("\nInsira o cÃ³digo do produto: ");
                scanf("%ld", &p.codigo);
                fflush(stdin);

                printf("\nInsira o nome do produto: ");
                scanf("%[^\n]", p.nome);
                fflush(stdin);

                printf("\nInsira a descriÃ§Ã£o do produto: ");
                scanf("%[^\n]", p.descricao);
                fflush(stdin);

                printf("\nInsira o preÃ§o do produto: ");
                scanf("%f", &p.preco);
                fflush(stdin);

                printf("\nInsira a marca do produto: ");
                scanf("%[^\n]", p.marca);
                fflush(stdin);

                printf("\nInsira o modelo do produto: ");
                scanf("%[^\n]", p.modelo);
                fflush(stdin);

                printf("\nInsira o stock do produto: ");
                scanf("%d", &p.stock);
                fflush(stdin);

                printf("\nInsira a data de adiÃƒÂ§ÃƒÂ£o do produto no catÃ¡logo: ");
                scanf("%s", p.data);
                fflush(stdin);

                printf("\nInsira a categoria do produto: ");
                scanf("%[^\n]", p.categoria);
                fflush(stdin);

                res = inserirProduto(&iniLista, p);

                for(i =0; i < num_prod; i++){
                    if(catalogo[i].codigo == p.codigo){
                        printf("ERRO jÃ¡ existe um produto com esse cÃ³digo");
                        break;
                    }
                }

                if(res == 0){
                    printf("Produto inserido com sucesso");
                }else {
                    printf("Falha ao inserir produto");
                }

                num_prod++;
                printf("\nPressione a tecla ENTER para continuar\n");
                getchar();
                break;
            case 2 :
                alterarpoduto(&iniLista, num_prod);
                printf("Pressione a tecla ENTER para continuar\n");
                getchar();
                break;
                /*case 3 :
                    printf("\nIntroduza o cÃ³digo do produto:");
                    scanf("%d", &nCodigo);
                    fflush(stdin);
                    removerProduto(&iniLista, &fimLista, nCodigo);
                    num_prod--;
                    printf("\n\nPressione a tecla ENTER para continuar\n");
                    getchar();
                    break;
                case 4 :
                    listarPorNome(iniLista, num_prod);
                    printf("\n\nPressione a tecla ENTER para continuar\n");
                    getchar();
                    break;
                case 5 :
                    listarPorMarca(iniLista, num_prod);
                    printf("\n\nPressione a tecla ENTER para continuar\n");
                    getchar();
                    break;*/
            case 6 :
                printf("\nInsira o nome do produto que deseja listar: ");
                scanf("%s", &nome);
                fflush(stdin);
                pesquisarPorNome(iniLista, &nome);
                printf("\n\nPressione a tecla ENTER para continuar\n");
                getchar();
                break;
                /*case 7 :
                    printf("\nIntroduza o numero do colaborador:");
                    scanf("%d", &numero);
                    //removerColab(â€¦);
                case 0 :
                    guardarDados(iniLista);
                    limpaLista(&iniLista);
                    printf("A sair ...\n");
                    break;*/
            default:
                printf ("Opcao errada\n");
        }
    }while (op != 0);

    return 0;
}