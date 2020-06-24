//
// Created by regis on 05/10/2019.
//

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

lista *criaLista() {
    lista *l = (lista *) malloc(sizeof(lista));
    if (!l) {
        exit(1);
    } else {
        l->counter = 0;
        l->inicio = NULL;
        return l;
    }
}

int estaVazia(lista *l) {
    if (l->size == 0) {
        return 1;
    } else {
        return 0;
    }
}

nodo *criaNodo(char val[50]) {
    nodo *n = (nodo *) malloc(sizeof(nodo));
    if (!n) {
        return NULL;
    } else {
        n->prox = NULL;
        strcpy(n->val, val);
        return n;
    }
}

nodo *getNodo(lista *l, char val[50]) {
    for (nodo *temp = l->inicio; temp != NULL; temp = temp->prox) {
        if (strcmp(temp->val, val) == 0) {
            return temp;
        }
    }
    return NULL;
}

int insereNaLista(lista *l, char val[50]) {
    nodo *n = criaNodo(val);

    if (n == NULL) {
        return -1;
    }

    if (l->inicio == NULL) {
        l->inicio = n;
    } else {
        nodo *temp = l->inicio;

        while (temp->prox != NULL) {
            temp = temp->prox;
        }

        temp->prox = n;
    }
    l->counter++;
    return 1;
}

int deletaDaLista(lista *l, char val[50]) {
    if (estaVazia(l) == 1) {
        return -1;
    } else {

        nodo *temp = l->inicio;
        nodo *aux;

        if (strcmp(temp->val, val) == 0) {
            nodo *temp = l->inicio->prox;
            free(l->inicio);
            l->inicio = temp;
            l->counter--;
            return 1;
        } else {
            while(temp != NULL) {
                aux = temp;
                temp = temp->prox;
                if(temp != NULL && strcmp(temp->val, val) == 0) {
                    aux->prox = temp->prox;
                    free(temp);
                    l->counter--;
                    return 1;
                }
            }
            return -1;
        }
    }
}

void visualizaLista(lista *l) {
    printf("\n");
    int i = 0;
    for (nodo *temp = l->inicio; temp != NULL; temp = temp->prox) {
        printf("Indice na Lista: %d. Valor: %s\n", i++, temp->val);
    }
}

void deletaLista(lista **l) {
    lista *temp = *l;
    nodo *prox;

    while (temp->inicio != NULL) {
        prox = temp->inicio->prox;
        free(temp->inicio);
        temp->inicio = prox;
    }
    *l = NULL;
}

