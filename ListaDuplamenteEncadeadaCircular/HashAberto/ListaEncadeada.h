//
// Created by regis on 01/12/2019.
//

#include "Pessoa.h"

#ifndef HASHABERTO_LISTAENCADEADA_H
#define HASHABERTO_LISTAENCADEADA_H

// structs
typedef struct nodo {
    pessoa *p;
    struct nodo *prox;
} nodo;

typedef struct {
    nodo *inicio;
    unsigned int counter;
} lista;

// cria a lista
lista *criaLista();

// verifica se está vazia
int estaVazia(lista *l);

// cria um nodo a partir de um char
nodo *criaNodo(pessoa *p);

// pega uma pessoa da lista a partir do email, retorna 1 se encontrou, - 1 se não
int getPessoa(lista *l, char email[maxLen], pessoa **p);

// insere um nodo na lista
int insereNaLista(lista *l, pessoa *p);

// deleta um nodo da lista, verificando se é igual ao char de entrada
int deletaDaLista(lista *l, char email[maxLen]);

// visualiza toda a lista
void visualizaLista(lista *l);

// deleta a lista
void deletaLista(lista **l);

#endif //HASHABERTO_LISTAENCADEADA_H
