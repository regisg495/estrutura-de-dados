#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaEncadeada.h"

enum menu {
    INSEREINICIO = 1,
    INSEREFIM = 2,
    INSEREPOS = 3,
    DELETAINICIO = 4,
    DELETAFIM = 5,
    DELETAPOS = 6,
    PRINTAR = 7,
    TAMANHO = 8,
    MENU = 9,
    SAIR = 10
};

int opt, content, result, pos;
nodo* n;

void printInsertResult(int result);

void printDeleteResult(int result);

void menu();

int main() {


    lista *l = criaLista();

    menu();

    while (opt != SAIR) {
        printf("\nPara ver as opcoes novamente, basta digitar 9");
        printf("\nEntre com a opcao que deseja: ");

        scanf("%d", &opt);
        fflush(stdin);

        switch (opt) {
            case INSEREINICIO:
                printf("\nEntre com o numero que voce quer colocar no inicio: ");
                scanf("%d", &content);
                n = criaNodo(content);
                result = insereNoInicio(l, n);
                printInsertResult(result);
                fflush(stdin);
                break;
            case INSEREFIM:
                printf("\nEntre com o numero que voce quer colocar no fim: ");
                scanf("%d", &content);
                n = criaNodo(content);
                result = insereNoFim(l, n);
                printInsertResult(result);
                fflush(stdin);
                break;
            case INSEREPOS:
                printf("\nEntre com o numero que deseja inserir: ");
                scanf("%d", &content);
                printf("\nAgora entre com a posicao em que deseja coloca-lo: ");
                scanf("%d", &pos);
                n = criaNodo(content);
                result = insereNaPos(l, n, pos);
                printInsertResult(result);
                fflush(stdin);
                break;
            case DELETAINICIO:
                printf("\nDeletando do inicio...");
                result = deletaDoInicio(l);
                printDeleteResult(result);
                break;
            case DELETAFIM:
                printf("\nDeletando do fim...");
                result = deletaDoFim(l);
                printDeleteResult(result);
                break;
            case DELETAPOS:
                printf("\nEntre com a posicao a qual voce quer deletar: ");
                scanf("%d", &pos);
                result = deletaDaPos(l, pos);
                printDeleteResult(result);
                fflush(stdin);
                break;
            case PRINTAR:
                printf("\nVisualizando...");
                visualiza(l);
                break;
            case TAMANHO:
                printf("\nTamanho da sua lista %d", l->size);
                break;
            case MENU:
                menu();
                break;
            case SAIR:
                printf("\nThank you <3");
                deletaLista(&l);
        }
    }
    printf("\nFim");


    return 0;

}

void printInsertResult(int result) {
    printf("\n");
    if (result == -1) {
        printf("Nao foi possivel realizar a insercao do item");
    } else {
        printf("Insercao realizada com sucesso!");
    }
}

void printDeleteResult(int result) {
    printf("\n");
    if (result == -1) {
        printf("Nao foi possivel realizar a remocao do item");
    } else {
        printf("Insercao realizada com sucesso!");
    }
}

void menu() {
    printf("\n1 para inserir um nodo no inicio\n2 para inserir um nodo no fim\n3 para inserir um nodo em uma determinada posicao\n"
           "4 para deletar um nodo do inicio\n5 para deletar um nodo do fim\n6 para deletar um nodo em uma determinada posicao\n"
           "7 para visualizar o conteudo\n8 para ver quantos elementos voce possui\n9 para ver as informacoes do menu novamente\n10 para sair");
}