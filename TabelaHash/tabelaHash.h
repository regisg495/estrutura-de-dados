//
// Created by regis on 05/10/2019.
//

#ifndef TABELAHASH_TABELAHASH_H
#define TABELAHASH_TABELAHASH_H

#include "lista.h"

// struct de tabela hash
// o tamanho é M, que vale 26 (o numero de letras do alfabeto)

typedef struct {
    lista *tabela[M];
} tabela;

char val[50];

// cria a tabela
tabela *criaTabela();

//@param faz a função de hash, para inserir no indice correto
int hash(char val[50]);

// insere o valor no indice correto, utilizando a função hash
int insereNaTabela(tabela *t, char val[50]);

// deleta um elemento da tabela
int deletaDaTabela(tabela *t, char val[50]);

// busca um nodo na tabela, a partir do valor
nodo *busca(tabela *t, char val[50]);

// visualiza a tabela por um indice
void visualizaPorIndice(tabela *t, char indice[1]);

// visualiza a tabela inteira
void visualizaTabela(tabela *t);

// deleta a tabela inteira e seus nodos
void deletaTabela(tabela *t);

#endif //TABELAHASH_TABELAHASH_H
