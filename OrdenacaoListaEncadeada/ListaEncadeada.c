//
// Created by regis on 25/09/2019.
//

#include "ListaEncadeada.h"
#include <stdlib.h>
#include <stdio.h>

lista *criaLista() {
    lista *l = (lista *) malloc(sizeof(lista));
    l->counter = 0;
    l->inicio = NULL;
    return l;
}

int estaVazia(lista *l) {
    if (l->counter == 0) {
        return 1;
    } else {
        return 0;
    }
}

nodo *criaNodo(int val) {
    nodo *n = (nodo *) malloc(sizeof(nodo));
    n->prox = NULL;
    n->val = val;
    return n;
}

int insereNoInicio(lista *l, nodo *nodo) {
    if (estaVazia(l) == 1) {
        l->inicio = nodo;
        l->counter++;
        return 1;
    } else {
        nodo->prox = l->inicio;
        l->inicio = nodo;
        l->counter++;
        return 1;
    }
}

int insereNoFim(lista *l, nodo *node) {
    if (estaVazia(l) == 1) {
        insereNoInicio(l, node);
        return 1;
    }

    nodo *temp = l->inicio;
    while (temp->prox != NULL) {
        temp = temp->prox;
    }
    temp->prox = node;
    l->counter++;
    return 1;
}


int insereNaPos(lista *l, nodo *node, int pos) {
    if (pos < 0 || pos > l->counter + 1) {
        return -1;
    } else if (pos == 0) {
        insereNoInicio(l, node);
        return 1;
    } else if (pos + 1 == l->counter) {
        insereNoFim(l, node);
        return 1;
    } else {
        nodo *temp = l->inicio;
        for (int i = 2; i < pos - 1; i++, temp = temp->prox) {
            if (temp == NULL) {
                break;
            }
        }
        node->prox = temp->prox;
        temp->prox = node;
        l->counter++;
        return 1;
    }

}

int deletaDoInicio(lista *l) {
    if (l->counter == 0) {
        return -1;
    } else {
        nodo *temp = l->inicio->prox;
        free(l->inicio);
        l->inicio = temp;
        l->counter--;
        return 1;
    }
}

int deletaDoFim(lista *l) {
    if (l->counter == 0) {
        return -1;
    } else {
        nodo *temp;
        nodo *novo;
        for (temp = l->inicio; novo != NULL; novo = temp, temp = temp->prox) {
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

int deletaDaPos(lista *l, int pos) {
    if (pos < 0 || pos > l->counter + 1) {
        return -1;
    } else if (pos == 0) {
        deletaDoInicio(l);
        return 1;
    } else if (pos + 1 == l->counter) {
        deletaDoFim(l);
        return 1;
    } else {
        nodo *temp = l->inicio;
        for (int i = 0; temp != NULL && i < pos - 1; i++, temp = temp->prox);
        if (temp == NULL || temp->prox == NULL) {
            return -1;
        }
        nodo *novo = temp->prox->prox;
        free(temp->prox);
        temp->prox = novo;
        l->counter--;
        return 1;
    }
}


void visualiza(lista *l) {
    printf("\n");
    int i = 0;
    for (nodo *temp = l->inicio; temp != NULL; temp = temp->prox) {
        printf("Indice: %d. Valor: %d\n", i++, temp->val);
    }
}

int ehIgual(lista *l, lista *l2) {
    if (l->counter != l2->counter) return 0;

    nodo *temp = l->inicio;
    nodo *temp2 = l2->inicio;

    int i = 1;
    while (temp != NULL && temp2 != NULL || i != 1) {
        if (temp->val != temp2->val) {
            i = 0;
        }
        temp = temp->prox;
        temp2 = temp2->prox;
    }
    return i;
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

void preenche(lista *l, int size) {
    if (l == NULL) {
        return;
    } else {
        for (int i = 0; i < size; i++) {
            nodo *n = criaNodo(i);
            int result = insereNoInicio(l, n);
            if (result == -1) {
                return;
            }
        }
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