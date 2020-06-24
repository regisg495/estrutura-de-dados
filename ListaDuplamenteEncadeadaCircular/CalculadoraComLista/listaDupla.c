//
// Created by regis on 12/10/2019.
//

#include "listaDupla.h"
#include <stdlib.h>
#include <stdio.h>

lista *criaLista() {
    lista *l = (lista *) malloc(sizeof(lista));
    if (!l) {
        return NULL;
    } else {
        l->inicio = NULL;
        l->counter = 0;
        return l;
    }
}

nodo *criaNodo(int val) {
    nodo *n = (nodo *) malloc(sizeof(nodo));
    if (!n) {
        return NULL;
    } else {
        n->prox = NULL;
        n->ant = NULL;
        n->val = val;
        return n;
    }
}

int estaVazia(lista *l) {
    if (l == NULL || l->counter == 0) {
        return 1;
    } else {
        return 0;
    }
}

nodo *get(lista *l, int pos) {
    if (pos < 0 || l == NULL || estaVazia(l) == 1 || pos > l->counter) {
        return NULL;
    } else {
        int i = 0;
        for (nodo *temp = l->inicio; temp != NULL; temp = temp->prox, i++) {
            if (pos == i) {
                return temp;
            }
        }
        return NULL;
    }
}

int getVal(lista *l, int pos) {
    return get(l, pos)->val;
}

int insereNoInicio(lista *l, int val) {
    if (l == NULL) {
        return -1;
    }
    nodo *n = criaNodo(val);
    if (!n) {
        return -1;
    }
    n->ant = NULL;
    if (estaVazia(l) == 1) {
        l->inicio = n;
        l->counter++;
        return 1;
    } else {
        l->inicio->ant = n;
        n->prox = l->inicio;
        l->inicio = n;
        l->counter++;
        return 1;
    }
}

int insereNoFim(lista *l, int val) {
    if (l == NULL) {
        return -1;
    }
    if (estaVazia(l) == 1) {
        return insereNoInicio(l, val);
    }
    nodo *n = criaNodo(val);
    if (!n) {
        return -1;
    }
    nodo *temp = l->inicio;
    while (temp->prox != NULL) temp = temp->prox;
    temp->prox = n;
    n->ant = temp;
    l->counter++;
    return 1;
}

int insereNaPos(lista *l, int val, int pos) {
    if (l == NULL || pos < 0) {
        return -1;
    }

    if (pos == 0) {
        return insereNoInicio(l, val);
    }
    if (pos - 1 == l->counter) {
        return insereNoFim(l, val);
    }

    nodo *n = criaNodo(val);

    if (!n) {
        return -1;
    }

    nodo *temp = l->inicio;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->prox;
    }

    n->prox = temp->prox;
    n->ant = temp;
    temp->prox->ant = n;
    temp->prox = n;
    l->counter++;
    return 1;
}

int deletaNoInicio(lista *l) {
    if (estaVazia(l) == 1 || l == NULL) {
        return -1;
    } else {
        nodo *temp = l->inicio->prox;
        free(l->inicio);
        l->inicio = temp;
        l->counter--;
        return 1;
    }
}

int deletaNoFim(lista *l) {
    if (estaVazia(l) == 1 || l == NULL) {
        return -1;
    } else {
        nodo *novo;
        for (nodo *temp = l->inicio; novo != NULL; novo = temp, temp = temp->prox) {
            if (temp->prox == NULL) {
                novo->prox = NULL;
                free(temp->prox);
                l->counter--;
                return 1;
            }
        }
        return -1;
    }
}

int deletaNaPos(lista *l, int pos) {
    if (estaVazia(l) == 1 || pos < 0 || l == NULL) {
        return -1;
    }
    if (pos == 0) {
        return deletaNoInicio(l);
    }
    if (pos == l->counter - 1) {
        return deletaNoFim(l);
    }
    nodo *temp = l->inicio;
    for (int i = 0; i < pos; i++) {
        temp = temp->prox;
    }
    temp->ant->prox = temp->prox;
    temp->prox->ant = temp->ant;
    l->counter--;
    free(temp);
    return 1;
}

void visualiza(lista *l) {
    int i = 0;
    printf("\n");
    for (nodo *temp = l->inicio; temp != NULL; temp = temp->prox) {
        printf("Indice: %d. Val: %d\n", i++, temp->val);
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