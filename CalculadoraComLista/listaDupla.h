//
// Created by regis on 12/10/2019.
//

#ifndef CALCULADORACOMLISTA_LISTADUPLA_H
#define CALCULADORACOMLISTA_LISTADUPLA_H

typedef struct nodo {
    struct nodo *prox;
    struct nodo *ant;
    int val;
} nodo;

typedef struct {
    nodo *inicio;
    int counter;
} lista;

// Cria a Lista
lista *criaLista();

// Cria um Nodo
nodo *criaNodo(int val);

// Verifica se está vázia
int estaVazia(lista *l);

// Pega um nodo por uma posição
nodo *get(lista *l, int pos);

// Pega o valor de um nodo por uma posição
int getVal(lista *l, int pos);

// Insere no início de uma lista
int insereNoInicio(lista *l, int val);

// Insere no final de uma lista
int insereNoFim(lista *l, int val);

// Insere por uma posição
int insereNaPos(lista *l, int val, int pos);

// Deletado o primeiro nodo da lista
int deletaNoInicio(lista *l);

// Deleta o último nodo da lista
int deletaNoFim(lista *l);

// Deleta um nodo por posição
int deletaNaPos(lista *l, int pos);

// Visualiza uma lista, mostrando índice e valor
void visualiza(lista *l);

// Deleta a estrutura lista
void deletaLista(lista **l);

#endif //CALCULADORACOMLISTA_LISTADUPLA_H
