//
// Created by regis on 29/10/2019.
//

#ifndef TABELAHASHSIMPLES_TABELAHASH_H
#define TABELAHASHSIMPLES_TABELAHASH_H


#define size 97
#define livre - 1
#define ocupado 1

typedef struct {
    int chave;
    char val[50];
    int status;
} item;

int opt, chave, result;
char val[50];
item* aux;
item* tabela[size];

// Gera um hash
int getHash(int chave);

// Cria um item para adicionar na tabela
item* criaItem(int chave, char val[50]);

// Pega um item da tabela
item* get(int chave);

// Insere um item na tabela
int insere(int chave, char val[50]);

// Deleta um item da tabela, dada uma chave
int deleta(int chave);

// Deleta a tabela
void deletaTabela(item* t[]);

// Visualiza a tabela
void visualiza(item* t[]);

#endif //TABELAHASHSIMPLES_TABELAHASH_H
