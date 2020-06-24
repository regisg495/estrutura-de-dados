//
// Created by regis on 29/10/2019.
//

#ifndef PILHA_PILHA_H
#define PILHA_PILHA_H


typedef struct node {
    int val;
    struct node *next;
} nodo;

typedef struct {
    nodo *inicio;
    int size;
    int counter;
} pilha;

pilha *criaPilha(int maxSize);

nodo *criaNodo(int val);

int estaVazia(pilha *p);

int estaCheia(pilha *p);

int push(pilha *p, nodo *n);

int pop(pilha *p);

nodo *peek(pilha *p);

void visualiza(pilha *p);

void deletaPilha(pilha **p);

#endif //PILHA_PILHA_H
