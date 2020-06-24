//
// Created by regis on 01/12/2019.
//

#include "ListaEncadeada.h"

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
    if (l->counter == 0) {
        return 1;
    } else {
        return 0;
    }
}

nodo *criaNodo(pessoa *p) {
    nodo *n = (nodo *) malloc(sizeof(nodo));
    if (!n) {
        return NULL;
    } else {
        n->prox = NULL;
        n->p = p;
        return n;
    }
}

int getPessoa(lista *l, char email[maxLen], pessoa **p) {
    for (nodo *temp = l->inicio; temp != NULL; temp = temp->prox) {
        if (strcmp(temp->p->email, email) == 0) {
            *p = temp->p;
            return 1;
        }
    }
    return -1;
}

int insereNaLista(lista *l, pessoa *p) {
    nodo *n = criaNodo(p);

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

int deletaDaLista(lista *l, char email[maxLen]) {
    if (estaVazia(l) == 1) {
        return -1;
    } else {

        nodo *temp = l->inicio;
        nodo *aux;

        if (strcmp(temp->p->email, email) == 0) {
            nodo *temp = l->inicio->prox;
            free(l->inicio);
            l->inicio = temp;
            l->counter--;
            return 1;
        } else {
            while (temp != NULL) {
                aux = temp;
                temp = temp->prox;
                if (temp != NULL && strcmp(temp->p->email, email) == 0) {
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
    if (estaVazia(l) == 1) {
        printf("\nEsta vazia");
        return;
    }

    printf("\n");
    unsigned int i = 0;
    for (nodo *temp = l->inicio; temp != NULL; temp = temp->prox) {
        printf("Indice na Lista: %d | Email: %s | Nome: %s | Telefone: %s.\n", i++, temp->p->email, temp->p->nome,
               temp->p->telefone);
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