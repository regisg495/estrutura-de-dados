//
// Created by regis on 01/10/2019.
//

#include "ListaDuplamenteEncadeada.h"
#include <stdlib.h>
#include <stdio.h>

lista *criaLista(int size) {
    lista *l = (lista *) malloc(sizeof(lista));
    if (!l) {
        return NULL;
    } else {
        l->nodes = NULL;
        l->counter = 0;
        l->size = size;
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

int estaCheia(lista *l) {
    if (l->counter == l->size) {
        return 1;
    } else {
        return 0;
    }
}

int estaVazia(lista *l) {
    if (l == NULL || l->counter == 0) {
        return 1;
    } else {
        return 0;
    }
}

int tamanho(lista *l) {
    return l->counter;
}

nodo *get(lista *l, int pos) {
    if (pos < 0 || l == NULL || estaVazia(l) == 1 || pos > l->counter) {
        return NULL;
    } else {
        int i = 0;
        for (nodo *temp = l->nodes; temp != NULL; temp = temp->prox) {
            if (pos == i) {
                return temp;
            }
        }
        return NULL;
    }
}

int insereNoInicio(lista *l, int val) {
    if (estaCheia(l) == 1 || l == NULL) {
        return -1;
    }
    nodo *n = criaNodo(val);
    if (!n) {
        return -1;
    }
    n->ant = NULL;
    if (estaVazia(l) == 1) {
        l->nodes = n;
        l->counter++;
        return 1;
    } else {
        l->nodes->ant = n;
        n->prox = l->nodes;
        l->nodes = n;
        l->counter++;
        return 1;
    }
}

int insereNoFim(lista *l, int val) {
    if (l == NULL || estaCheia(l) == 1) {
        return -1;
    }
    nodo *n = criaNodo(val);
    if (!n) {
        return -1;
    }
    nodo *temp = l->nodes;
    while (temp->prox != NULL) temp = temp->prox;
    temp->prox = n;
    n->ant = temp;
    l->counter++;
    return 1;
}

int insereNaPos(lista *l, int val, int pos) {
    if (estaCheia(l) == 1 || l == NULL || pos < 0) {
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

    nodo *temp = l->nodes;
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
        nodo *temp = l->nodes->prox;
        free(l->nodes);
        l->nodes = temp;
        l->size--;
        return 1;
    }
}

int deletaNoFim(lista *l) {
    if (estaVazia(l) == 1 || l == NULL) {
        return -1;
    } else {
        nodo *novo;
        for (nodo *temp = l->nodes; novo != NULL; novo = temp, temp = temp->prox) {
            if (temp->prox == NULL) {
                novo->prox = NULL;
                free(temp->prox);
                l->size--;
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
    for (nodo *temp = l->nodes; temp != NULL; temp = temp->prox) {
        printf("Indice: %d. Val: %d\n", i++, temp->val);
    }
}

void deletaLista(lista **l) {
    lista *temp = *l;
    nodo *prox;

    while (temp->nodes != NULL) {
        prox = temp->nodes->prox;
        free(temp->nodes);
        temp->nodes = prox;
    }
    *l = NULL;
}

void menu() {
    printf("\n1 para ver o tamanho atual da sua lista\n2 para ver o conteudo de um nodo por posicao\n3"
           " para inserir um nodo no inicio da lista\n4 para inserir um nodo no fim da lista\n5 para inserir um nodo numa posicao especifica\n6"
           " para deletar um nodo do inicio\n7 para deletar um nodo do final da lista\n8 para deletar um nodo de uma posicao especifica\n9 para visualizar sua lista\n0 para repetir esse menu"
           "\n10 para sair do algoritmo");
}