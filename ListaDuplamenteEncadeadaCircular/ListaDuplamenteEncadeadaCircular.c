//
// Created by regis on 03/10/2019.
//

#include "ListaDuplamenteEncadeadaCircular.h"
#include <stdio.h>
#include <stdlib.h>

lista *criaLista(int size) {
    lista *l = (lista *) malloc(sizeof(lista));
    if (!l) {
        return NULL;
    }

    l->counter = 0;
    l->size = size;
    return l;

}

nodo *criaNodo(int val) {
    nodo *n = (nodo *) malloc(sizeof(nodo));
    if (!n) {
        return NULL;
    }
    n->ant = NULL;
    n->prox = NULL;
    n->val = val;

    return n;
}

int estaVazia(lista *l) {
    if (l->counter == 0) {
        return 1;
    } else {
        return 0;
    }
}

int estaCheia(lista *l) {
    if (l->counter == l->size) {
        return 1;
    } else {
        return 0;
    }
}

nodo *get(lista *l, int pos) {
    if (estaVazia(l) == 1) {
        return NULL;
    } else {
        nodo *temp = l->nodes;
        for (int i = 0; i < pos; i++) {
            temp = temp->prox;
        }
        return temp;
    }
}

nodo *getUltimoLista(lista *l) {
    if (estaVazia(l) == 1) {
        return NULL;
    } else {
        nodo *temp = l->nodes;
        for (int i = 0; i < l->counter; i++, temp = temp->prox);
        return temp->prox;
    }
}

int tamanho(lista *l) {
    return l->counter;
}

int insereNoInicio(lista *l, int val) {

    nodo *n = criaNodo(val);
    if (!n) {
        return -1;
    }
    if (estaVazia(l) == 1) {
        n->prox = n;
        n->ant = n;
        l->nodes = n;
        l->counter++;
        return 1;
    } else {
        n->prox = l->nodes;
        n->ant = l->nodes->ant;
        l->nodes->ant->prox = n;
        l->nodes->ant = n;
        l->nodes = n;
        l->counter++;
        return 1;
    }

}

int insereNoFim(lista *l, int val) {
    if (estaCheia(l) == 1) {
        return -1;
    }
    if (estaVazia(l) == 1) {
        return insereNoInicio(l, val);
    }
    nodo *n = criaNodo(val);
    nodo *temp = getUltimoLista(l);
    n->prox = temp->prox;
    n->ant = temp;
    temp->prox->ant = n;
    temp->prox = n;
    l->counter++;
    return 1;
}

int insereNaPos(lista *l, int val, int pos) {
    if (estaCheia(l) == 1 || pos < 0) {
        return -1;
    }
    if (pos == 0) {
        return insereNoInicio(l, val);
    }
    if (pos - 1 == l->counter) {
        return insereNoFim(l, val);
    }
    nodo *temp = l->nodes;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->prox;
    }
    nodo *n = criaNodo(val);
    n->prox = temp->prox;
    n->ant = temp;
    temp->prox->ant = n;
    temp->prox = n;
    l->counter++;
    return 1;
}

int deletaNoInicio(lista *l) {
    if (estaVazia(l) == 1) {
        return -1;
    } else {
        nodo *n = l->nodes;
        n->ant->prox = n->prox;
        n->prox->ant = n->ant;
        l->nodes = n->prox;
        l->counter--;
        free(n);
        return 1;
    }
}

int deletaNoFim(lista *l) {
    if (estaVazia(l) == 1) {
        return -1;
    }
    nodo *temp = l->nodes;
    nodo *n;
    while (temp->prox != l->nodes) {
        n = temp;
        temp = temp->prox;
    }
    n->prox = l->nodes;
    l->counter--;
    free(temp);
    return 1;
}

int deletaNaPos(lista *l, int pos) {
    if (estaCheia(l) == 1 || pos < 0) {
        return -1;
    }
    if (pos == 0) {
        return deletaNoInicio(l);
    }
    if (pos == l->counter - 1) {
        return deletaNoFim(l);
    }
    nodo *temp = l->nodes;
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
    for (nodo *temp = l->nodes; i < l->counter; temp = temp->prox) {
        printf("Indice: %d. Val: %d\n", i++, temp->val);
    }
}

void visualizaCircular(lista *l) {
    int i = 0;
    printf("\n");
    for (nodo *temp = l->nodes; temp != NULL; temp = temp->prox) {
        printf("Indice: %d. Val: %d\n", i++, temp->val);
    }
}


// @FIX ME
void deletaLista(lista **l) {
    lista *temp = *l;
    nodo *n = temp->nodes;
    while (temp->counter != 0) {
        nodo *n1 = n->prox;
        free(n1);
        n = n1;
        temp->counter--;
    }
    *l = NULL;
    free(l);
}
