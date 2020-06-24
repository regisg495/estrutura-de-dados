//
// Created by regis on 05/10/2019.
//

#include "tabelaHash.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

tabela *criaTabela() {
    tabela *t = (tabela *) malloc(sizeof(tabela));
    if (!t) {
        exit(1);
    }

    for (int i = 0; i < M; i++) {
        t->tabela[i] = criaLista();
    }
    return t;
}

int hash(char val[50]) {
    return tolower(val[0]) - 97;
}

int insereNaTabela(tabela *t, char val[50]) {
    if (t == NULL) {
        return -1;
    }
    if (val[0] < 97 || val[0] > 122) {
        return -1;
    }

    nodo *n = criaNodo(val);
    if (n == NULL) {
        return -1;
    }
    int hashCode = hash(val);
    return insereNaLista(t->tabela[hashCode], val);

}

int deletaDaTabela(tabela *t, char val[50]) {
    int hashCode = hash(val);

    if (hashCode < 0 || hashCode > 26) {
        return -1;
    }

    return deletaDaLista(t->tabela[hashCode], val);
}

nodo *busca(tabela *t, char val[50]) {
    int hashCode = hash(val);

    if (hashCode < 0 || hashCode > 26) {
        return NULL;
    }

    nodo *n = getNodo(t->tabela[hashCode], val);
    return n;

}

void visualizaPorIndice(tabela *t, char indice[1]) {

    if (indice[0] < 97 && indice[0] > 122 || strlen(indice) > 2) {
        printf("\nIndice Invalido");
        return;
    }

    int hashCode = hash(indice);
    if (estaVazia(t->tabela[hashCode]) == 1) {
        printf("\nEsta vazia neste indice...");
        return;
    } else {
        printf("\nVisualizando: ");
        visualizaLista(t->tabela[hashCode]);
    }
}

void visualizaTabela(tabela *t) {
    printf("\nVizualizando da tabela");
    for (int i = 0; i < M; i++) {
        if (t->tabela[i]->counter > 0) {
            printf("\nIndice na tabela: %d ", i);
            visualizaLista(t->tabela[i]);
        }
    }
}

void deletaTabela(tabela *t) {
    printf("\nDeletando tabela");
    for (int i = 0; i < M; i++) {
        deletaLista(&t->tabela[i]);
    }
    free(t);
}

