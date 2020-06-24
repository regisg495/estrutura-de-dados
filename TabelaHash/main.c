#include <stdio.h>
#include "tabelaHash.h"
#include <string.h>

enum menu {
    INSERIR = 1, DELETAR = 2, BUSCAR = 3, VISUALIZARPORINDICE = 4, VISUALIZARTABELA = 5, MENU = 6, SAIR = 7
};

int opt, result;
nodo *aux;


void menu();

int main() {

    tabela *t = criaTabela();

    menu();

    while (opt != SAIR) {
        printf("\nCaso queira repetir o menu, digite 6\n");
        scanf("%d", &opt);
        fflush(stdin);

        switch (opt) {
            case INSERIR:
                printf("\nDigite o nome que quer inserir: ");
                fgets(val, 50, stdin);
                fflush(stdin);
                val[strcspn(val, "\n")] = 0;


                printf("\nInserindo...");
                result = insereNaTabela(t, val);

                if (result == 1) {
                    printf("\nInserido com sucesso");
                } else {
                    printf("\nNao foi possivel inserir");
                }

                break;
            case DELETAR:
                printf("\nDigite o nome que quer deletar:");
                fgets(val, 50, stdin);
                fflush(stdin);

                val[strcspn(val, "\n")] = 0;

                printf("Deletando...");
                result = deletaDaTabela(t, val);

                if (result == 1) {
                    printf("\nDeletado com sucesso");
                } else {
                    printf("\nNao foi possivel deletar");
                }

                break;

            case BUSCAR:
                printf("\nEntre com a palavra que deseja buscar: ");
                fgets(val, 50, stdin);
                fflush(stdin);
                val[strcspn(val, "\n")] = 0;

                aux = busca(t, val);
                printf("\nBuscando...");
                if (aux == NULL) {
                    printf("\nNao foi possivel encontrar");
                } else {
                    printf("\nEncontrado! %s", aux->val);
                }
                break;

            case VISUALIZARPORINDICE:
                printf("\nEntre com o indice que deseja visualizar: ");
                fgets(val, 10, stdin);
                fflush(stdin);

                visualizaPorIndice(t, val);
                break;

            case VISUALIZARTABELA:
                visualizaTabela(t);
                break;

            case MENU:
                menu();
                break;

            case SAIR:
                deletaTabela(t);
                printf("\nThanks <3");
                break;
        }
        fflush(stdin);
    }

    printf("\nBye");

    return 0;
}

void menu() {
    printf("Selecione a opcao que melhor atende sua necessidade: \n1 para inserir um nome na tabela\n2 para deletar um item da tabela"
           "\n3 para buscar um item da tabela\n4 para visualizar um indice por letra\n5 para visualizar toda a tabela\n6 para repetir o menu"
           "\n7 para sair");
}