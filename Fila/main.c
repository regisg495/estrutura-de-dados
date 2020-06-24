#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"


enum menu {
    ADICIONA = 1, RETIRA = 2, VISUALIZAR = 3, FIM = 4
};

fila *f;
int opt, tam, val, result;
nodo *n;

void menu();

int main() {
    opt = 0;
    tam = 0;
    while (tam <= 0) {
        printf("Entre com o tamanho da sua fila: ");
        scanf("%d", &tam);
    }
    f = criaFila(tam);

    while (opt != FIM) {
        menu();
        printf("\nEntre com a opcao desejada: ");
        scanf("%d", &opt);
        fflush(stdin);
        switch (opt) {
            case ADICIONA:
                printf("\nEntre com o valor que deseja colocar no nodo: ");
                scanf("%d", &val);
                fflush(stdin);
                n = criaNodo(val);
                result = enqueue(f, n);
                if (result == 1) {
                    printf("\nItem adicionado com sucesso");
                } else {
                    printf("\nNao foi possivel");
                }
                break;
            case RETIRA:
                if (f->elementos == 0) {
                    printf("\nNao ha itens na fila ainda");
                } else {
                    printf("\nRetirando da fila...");
                    n = dequeue(f);
                    printf("\nVoce retirou da fila o item %d", n->val);
                    free(n);
                }
                break;
            case VISUALIZAR:
                visualiza(f);
                break;
            case FIM:
                printf("\nThank you <3");
                deletaFila(&f);
                break;
            default:
                printf("\nEntre com uma opcao valida");
                break;
        }
    }
    printf("\nBye");

    return 0;
}

void menu() {
    printf("\nEntre com a opcao que deseja\n1 para adicionar um nodo na sua fila\n2 para retirar um nodo da fila\n3 para visualizar os itens da fila\n4 para sair");
}
