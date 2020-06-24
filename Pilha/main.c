#include <stdio.h>
#include "Pilha.h"


enum menu {
    EMPILHAR = 1, DESEMPILHAR = 2, VISUALIZAR = 3, SAIR = 4
};

int opt, result, size, val;
nodo *n;

void menu();

int main() {
    size = 0;
    opt = 0;

    while (size <= 0) {
        printf("Entre com o tamanho da sua pilha: ");
        scanf("%d", &size);
        printf("\n");
        fflush(stdin);
    }

    pilha *p = criaPilha(size);


    while (opt != SAIR) {
        menu();
        printf("\nEntre com uma opcao valida: ");
        scanf("%d", &opt);

        fflush(stdin);

        switch (opt) {
            case EMPILHAR:
                printf("Entre com o valor do nodo: ");
                scanf("%d", &val);
                fflush(stdin);
                n = criaNodo(val);
                result = push(p, n);
                if (result == 1) {
                    printf("\nEmpilhado");
                } else {
                    printf("\nNao foi possivel empilhar o item");
                }
                break;
            case DESEMPILHAR:
                printf("\nDesempilhando...");
                result = pop(p);
                if (result == 1) {
                    printf("\nDesempilhado");
                } else {
                    printf("\nNao foi possivel desempilhar o item");
                }
                break;
            case VISUALIZAR:
                visualiza(p);
                break;
            case SAIR:
                deletaPilha(&p);
                printf("\nThank u <3");
                break;

            default:
                printf("\nEscolha uma opcao valida");
                break;
        }
    }
    printf("\nFim");

    return 0;
}

void menu() {
    printf("\nEscolha uma opcao:\n1 para empilhar\n2 para desempilhar\n3 para visualizar os items\n4 para sair");
}