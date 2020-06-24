//
// Created by regis on 25/09/2019.
//

#ifndef LINKEDLIST_LISTAENCADEADA_H
#define LINKEDLIST_LISTAENCADEADA_H


typedef struct nodo {
    int val;
    struct nodo* prox;
} nodo;

typedef struct {
    nodo* inicio;
    int counter;
} lista;

// Cria a estrutura Lista
lista* criaLista();

// Verifica se está vazia
int estaVazia(lista* l);

// Cria um nodo
nodo* criaNodo(int val);

// Insere um nodo no Inicio
int insereNoInicio(lista* l, nodo* nodo);

// Insere um nodo no fim
int insereNoFim(lista* l, nodo* nodo);

// Insere um nodo na posição especifica
int insereNaPos(lista * l, nodo* nodo, int pos);

// Deleta um nodo do inicio
int deletaDoInicio(lista* l);

// Deleta um nodo do fim
int deletaDoFim(lista* l);

// Deleta um nodo da posição especifica
int deletaDaPos(lista* l, int pos);

// Visualiza a lista
void visualiza(lista* l);

// Verifica se é igual
int ehIgual(lista* l, lista* l2);

// Deleta a lista
void deletaLista(lista** l);

void preenche(lista* l, int size);

nodo* get(lista* l, int pos);

#endif //LINKEDLIST_LISTAENCADEADA_H
