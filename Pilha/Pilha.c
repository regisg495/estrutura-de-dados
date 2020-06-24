//
// Created by regis on 29/10/2019.
//

#include "Pilha.h"
#include <stdlib.h>
#include <stdio.h>


pilha *criaPilha(int maxSize) {
    pilha *p = (pilha *) malloc(sizeof(pilha));
    if (p == NULL) {
        exit(1);
    }
    p->inicio = NULL;
    p->size = maxSize;
    p->counter = 0;
    return p;
}

nodo *criaNodo(int val) {
    nodo *n = (nodo *) malloc(sizeof(nodo));
    if (n == NULL) {
        return NULL;
    }
    n->val = val;
    n->next = NULL;
    return n;
}

int estaCheia(pilha *p) {
    if (p->counter == p->size) {
        return 1;
    } else {
        return 0;
    }
}

int estaVazia(pilha *p) {
    if (p->counter == 0) {
        return 1;
    } else {
        return 0;
    }
}

int push(pilha *p, nodo *n) {
    if (estaCheia(p) == 1) {
        return -1;
    } else if (estaVazia(p) == 1) {
        p->inicio = n;
        p->counter++;
        return 1;
    } else {
        n->next = p->inicio;
        p->inicio = n;
        p->counter++;
        return 1;
    }
}

int pop(pilha *p) {
    if (estaVazia(p) == 1) {
        return -1;
    } else {
        nodo *n = p->inicio;
        p->inicio = p->inicio->next;
        p->counter--;
        free(n);
        return 1;
    }
}

nodo *peek(pilha *p) {
    if (p == NULL || p->counter == 0) {
        return NULL;
    } else {
        return p->inicio;
    }
}

void visualiza(pilha *p) {
    if (estaVazia(p) == 1) {
        return;
    }
    nodo *n;
    int i = 0;
    for (n = p->inicio; n != NULL; n = n->next) {
        printf("\nIndice: %d. Val: %d", i++, n->val);
    }
}

void deletaPilha(pilha **p) {
    pilha *temp = *p;
    nodo *next = temp->inicio;
    while (temp->inicio != NULL) {
        next = temp->inicio->next;
        free(temp->inicio);
        temp->inicio = next;
    }
    *p = NULL;
}
