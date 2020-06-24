//
// Created by regis on 03/10/2019.
//

#ifndef DOUBLYCIRCULARLINKEDLIST_LISTADUPLAMENTEENCADEADACIRCULAR_H
#define DOUBLYCIRCULARLINKEDLIST_LISTADUPLAMENTEENCADEADACIRCULAR_H

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

// Cria a estrutura Lista
lista* criaLista(int size);

// Cria um nodo por um valor
nodo* criaNodo(int val);

// Verifica se está vazia
int estaVazia(lista* l);

// Verifica se está cheia
int estaCheia(lista* l);

// Pega o ultimo elemento da lista
nodo* getUltimoLista(lista* l);

// Pega um nodo por uma posição
nodo* get(lista* l, int pos);

// Verifica o tamanho
int tamanho(lista* l);

// Insere no inicio da lista
int insereNoInicio(lista* l, int val);

// Insere no fim da lista
int insereNoFim(lista* l, int val);

// Insere na posição especifica
int insereNaPos(lista* l, int val, int pos);

// Deleta do inicio da lista
int deletaNoInicio(lista* l);

// Deleta do fim da lista
int deletaNoFim(lista* l);

// Deleta da posição especifica da lista
int deletaNaPos(lista* l, int pos);

// Visualiza os elementos da lista
void visualiza(lista* l);

// Visualiza a circularidade da lista (loop)
void visualizaCircular(lista* l);

// Deleta a estrutura lista
void deletaLista(lista** l);

#endif //DOUBLYCIRCULARLINKEDLIST_LISTADUPLAMENTEENCADEADACIRCULAR_H
