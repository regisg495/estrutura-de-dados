#include "TabelaHash.h"
#include <stdio.h>

enum menu {INSERIR  = 1, DELETAR = 2, PEGAR = 3, VISUALIZAR = 4, SAIR = 5, VERMENU = 6};

void menu();

int main() {

    menu();

    while (opt != SAIR) {

        printf("\nCaso queira, aperte 6 para ver o menu novamente:\n");

        scanf("%d", &opt);

        switch (opt) {

            case INSERIR:

                printf("\nEntre com a chave do item que deseja inserir: ");
                scanf("%d", &chave);
                fflush(stdin);
                printf("\nAgora entre com o valor (palavra) que deseja inserir:");
                fgets(val, 50, stdin);
                result = insere(chave, val);
                printf("\nInserindo...");
                if (result == -1) {
                    printf("\nNao foi possivel inserir");
                } else {
                    printf("\nAdicionado com sucesso");
                }

                break;

            case DELETAR:

                printf("\nEntre com a chave do item que deseja deletar: ");
                scanf("%d", &chave);
                result = deleta(chave);
                printf("\nDeletando...");
                if (result == -1) {
                    printf("\nNao foi possivel deletar");
                } else {
                    printf("\nDeletado com sucesso");
                }
                break;

            case PEGAR:
                printf("\nEntre com a chave do item que deseja pegar: ");
                scanf("%d", &chave);
                aux = get(chave);
                printf("\nPegando...");
                if (aux == NULL) {
                    printf("\nOps! Nao foi encontrado nenhum item com essa chave");
                } else {
                    printf("\nChave do item: %d. Valor: %s", aux->chave, aux->val);
                }
                break;

            case VISUALIZAR:
                printf("\nVisualizando...");
                visualiza(tabela);
                break;

            case VERMENU:
                menu();
                break;

            case SAIR:
                printf("\nSaindo...");
                deletaTabela(tabela);
        }

    }
    printf("\nThanks");

    return 0;
}

void menu() {
    printf("\nEscolha a opcao que melhor atende o que deseja\n1 para inserir um item na tabela\n2 para deletar um item da tabela\n"
           "3 para pegar um item, dado uma chave\n4 para visualizar todos os itens da tabela\n5 para sair");
}