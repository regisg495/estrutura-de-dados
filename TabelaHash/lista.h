//
// Created by regis on 05/10/2019.
//

#ifndef TABELAHASH_LISTA_H
#define TABELAHASH_LISTA_H


// tamanho da tabela
#define M 26

// structs

typedef struct nodo {
    char val[50];
    struct nodo *prox;
} nodo;

typedef struct {
    nodo *inicio;
    int size;
    int counter;
} lista;

// cria a lista
lista *criaLista();

// verifica se está vazia
int estaVazia(lista *l);

// cria um nodo a partir de um char
nodo *criaNodo(char val[50]);

// pega um nodo da lista
nodo *getNodo(lista *l, char val[50]);

// insere um nodo na lista
int insereNaLista(lista *l, char val[50]);

// deleta um nodo da lista, verificando se é igual ao char de entrada
int deletaDaLista(lista* l, char val[50]);

// visualiza toda a lista
void visualizaLista(lista *l);

// deleta a lista
void deletaLista(lista **l);

#endif //TABELAHASH_LISTA_H
