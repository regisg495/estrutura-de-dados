//
// Created by regis on 29/10/2019.
//

#ifndef FILA_FILA_H
#define FILA_FILA_H

typedef struct no {
    struct no *prox;
    int val;
} nodo;

typedef struct {
    int elementos;
    int tamanhoMax;
    nodo *inicio;
    nodo *fim;
} fila;

fila *criaFila(int tamanhoMax);

nodo *criaNodo(int elemento);

int estaVazia(fila *f);

int estaCheia(fila *f);

int enqueue(fila *f, nodo *node);

nodo *dequeue(fila *f);

nodo* peek(fila* f);

void visualiza(fila *f);

void deletaFila(fila **f);

#endif //FILA_FILA_H
