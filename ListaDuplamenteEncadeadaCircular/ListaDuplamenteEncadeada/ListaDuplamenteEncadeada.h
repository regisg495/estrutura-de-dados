//
// Created by regis on 01/10/2019.
//

#ifndef DOUBLYLINKEDLIST_LISTADUPLAMENTEENCADEADA_H
#define DOUBLYLINKEDLIST_LISTADUPLAMENTEENCADEADA_H

enum menu {tamanhoLista = 1, getPos = 2, insereInicio = 3, insereFim = 4, inserePos = 5, deletaInicio = 6, deletaFim = 7, deletaPos = 8,
           visualizar = 9, mostraMenu = 0, fim = 10};


typedef struct nodo {
    struct nodo* prox;
    struct nodo* ant;
    int val;
} nodo;

typedef struct {
    nodo* nodes;
    int counter;
    int size;
} lista;

lista* l;
int opt, result, size, pos, val;
nodo* aux;

lista* criaLista(int size);

nodo* criaNodo(int val);

int estaCheia(lista* l);

int estaVazia(lista* l);

int tamanho(lista* l);

nodo* get(lista* l, int pos);

int insereNoInicio(lista* l, int val);

int insereNoFim(lista* l, int val);

int insereNaPos(lista* l, int val, int pos);

int deletaNoInicio(lista* l);

int deletaNoFim(lista* l);

int deletaNaPos(lista* l, int pos);

void visualiza(lista* l);

void deletaLista(lista** l);

void menu();

#endif //DOUBLYLINKEDLIST_LISTADUPLAMENTEENCADEADA_H
