//
// Created by regis on 29/10/2019.
//

#include "Fila.h"
#include <stdlib.h>
#include <stdio.h>

fila *criaFila(int tamanhoMax) {
    fila *f = (fila *) malloc(sizeof(fila));
    if (f == NULL) {
        printf("Nao foi possivel criar a fila");
        exit(1);
    }
    f->elementos = 0;
    f->tamanhoMax = tamanhoMax;
    f->inicio = NULL;
    f->fim = NULL;
}

nodo *criaNodo(int val) {
    nodo *n = (nodo *) malloc(sizeof(nodo));
    if (n == NULL) {
        exit(1);
    }
    n->val = val;
    n->prox = NULL;
}

int estaVazia(fila *f) {
    if (f->elementos == 0) {
        return 1;
    } else {
        return 0;
    }
}

int estaCheia(fila *f) {
    if (f->elementos == f->tamanhoMax) {
        return 1;
    } else {
        return 0;
    }
}

int enqueue(fila *f, nodo *node) {

    if (estaCheia(f) == 1) {
        return -1;
    } else if (f->elementos == 0) {
        f->inicio = node;
        f->fim = node;
        f->elementos++;
        return 1;
    } else {
        f->fim->prox = node;
        f->fim = node;
        f->elementos++;
        return 1;
    }
}


nodo *dequeue(fila *f) {
    if (f->elementos == 0) {
        return NULL;
    } else {
        nodo *node = f->inicio;
        f->inicio = (f->inicio)->prox;
        f->elementos--;
        return node;
    }
}

nodo *peek(fila *f) {
    if (estaVazia(f) == 1) {
        return NULL;
    } else {
        return f->inicio;
    }
}

void visualiza(fila *f) {
    if (f == NULL || estaVazia(f) == 1) {
        printf("\nNao ha elementos ainda");
        return;
    }
    nodo *temp;
    int i = 0;
    for (temp = f->inicio; temp != NULL; temp = temp->prox) {
        printf("\nIndice: %d. Valor: %d", i++, temp->val);
    }
}

void deletaFila(fila **f) {
    fila *temp = *f;
    if (f == NULL) {
        return;
    } else if (temp->elementos == 0) {
        free(f);
        return;
    } else {
        nodo *prox;
        while (temp->inicio != NULL) {
            prox = temp->inicio->prox;
            free(temp->inicio);
            temp->inicio = prox;
        }
        *f = NULL;
    }
}
