#include <stdio.h>
#include "ListaDuplamenteEncadeada.h"
#include <stdlib.h>

int main() {

    size = 0;

    printf("Entre com o tamanho da sua lista:\n");
    scanf("%d", &size);

    while (size <= 0) {
        printf("\nEntre com um tamanho valido para sua lista:\n");
        scanf("%d", &size);
    }

    l = criaLista(size);

    if (l == NULL) {
        printf("\nErro ao criar a lista");
        exit(1);
    }
    menu();
    while (opt != fim) {
        printf("\nSelecione alguma das opcoes acima:\nCaso queira repetir o menu, basta digitar 0\n");
        scanf("%d", &opt);

        switch (opt) {
            case tamanhoLista:
                printf("\nTamanho atual da sua lista: %d", tamanho(l));
                break;
            case getPos:
                printf("\nEntre com a posicao que voce quer ver o conteudo: ");
                scanf("%d", &pos);
                aux = get(l, pos);
                if (aux == NULL) {
                    printf("\nNao foi possivel encontrar essa posicao");
                } else {
                    printf("\nIndice encontrado, o valor eh: %d", aux->val);
                }
                break;
            case insereInicio:
                printf("\nEntre com o valor que deseja inserir no inicio: ");
                scanf("%d", &val);
                result = insereNoInicio(l, val);
                printf("\nInserindo...");
                if (result == -1) {
                    printf("\nNao foi possivel realizar a insercao");
                } else {
                    printf("\nNodo adicionado com sucesso");
                }
                break;
            case insereFim:
                printf("\nEntre com o valor que deseja inserir no fim: ");
                scanf("%d", &val);
                result = insereNoFim(l, val);
                printf("\nInserindo...");
                if (result == -1) {
                    printf("\nNao foi possivel realizar a insercao");
                } else {
                    printf("\nNodo adicionado com sucesso");
                }
                break;
            case inserePos:
                printf("\nEntre com o valor que deseja inserir: ");
                scanf("%d", &val);
                printf("\nOk! Agora entre com a posicao em que deseja inserir: ");
                scanf("%d", &pos);
                printf("\nInserindo...");
                result = insereNaPos(l, val, pos);

                if (result == -1) {
                    printf("\nNao foi possivel realizar a insercao");
                } else {
                    printf("\nNodo adicionado com sucesso");
                }
                break;
            case deletaInicio:
                printf("\nDeletando nodo do inicio...");
                result = deletaNoInicio(l);

                if (result == -1) {
                    printf("\nNao foi possivel deletar");
                } else {
                    printf("\nNodo deletado com sucesso");
                }
                break;
            case deletaFim:
                printf("\nDeletando nodo do fim...");
                result = deletaNoFim(l);
                if (result == -1) {
                    printf("\nNao foi possivel deletar");
                } else {
                    printf("\nNodo deletado com sucesso");
                }
                break;
            case deletaPos:
                printf("\nEntre com a posicao em que deseja deletar: ");
                scanf("%d", &pos);
                printf("\nDeletando...");
                result = deletaNaPos(l, pos);
                if (result == -1) {
                    printf("\nNao foi possivel deletar");
                } else {
                    printf("\nNodo deletado com sucesso");
                }
                break;
            case visualizar:
                printf("\nVisualizando lista...");
                visualiza(l);
                break;
            case mostraMenu:
                printf("Mostrando menu...");
                menu();
                break;
            case fim:
                printf("\nThank you <3");
                deletaLista(&l);
                break;
        }
    }

    return 0;
}