//
// Created by regis on 01/12/2019.
//

#ifndef HASHABERTO_TABELAHASH_H
#define HASHABERTO_TABELAHASH_H

#include "ListaEncadeada.h"

// struct de tabela
// tem um vetor de lista, um size (tamanho fisico) e um contador de elementos que foram inseridos
typedef struct {
    lista **tabela;
    unsigned int size;
    unsigned int elements;
} tabelahash;

// cria uma tabela hash a partir de um size fisico
tabelahash *criaTabela(unsigned int size);

// popula uma tabela com um vetor de pessoas, recebe tambem o nome do arquivo
int populaTabela(tabelahash *t, pessoa **p, char nomeArq[maxLenArq]);

// função de hash utilizando email e o tamanho da tabela
unsigned int hash(tabelahash *t, char email[maxLen]);

// função de redimensionamento da tabela
int rehash(tabelahash **t);

int existeChave(tabelahash* t, char email[maxLen]);

// inserção de uma pessoa na tabela
int insereNaTabela(tabelahash *t, pessoa *p);

// deleta uma pessoa na tabela
int deletaDaTabela(tabelahash *t, char email[maxLen]);

// busca uma pessoa na tabela
int buscaNaTabela(tabelahash *t, char email[maxLen], pessoa **p);

// imprime os dados de desempenho da tabela
void dadosDesempenho(tabelahash *t);

// imprime o fator de ocupação
double fatorOcupacao(tabelahash *t);

// visualiza a tabela hash (o conteudo de todas as listas internas)
void visualizaTabela(tabelahash *t);

// deleta a tabela e todas as suas listas internas
void deletaTabela(tabelahash **t);

// uma função auxiliar para ter um load factor de 0.5 caso você insira vários nomes primeiro e depois use o arquivo para popular
// a tabela
int reinicializa(tabelahash **t, char nomeArq[maxLenArq]);

#endif //HASHABERTO_TABELAHASH_H
