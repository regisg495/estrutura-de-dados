//
// Created by regis on 01/12/2019.
//

#ifndef HASHABERTO_PESSOA_H
#define HASHABERTO_PESSOA_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define maxLen 100
#define maxLenArq 30

// struct de pessoa
typedef struct {
    char nome[maxLen];
    char telefone[maxLen];
    char email[maxLen];
} pessoa;

// valida valores (nome, telefone e email)
int ehValido(char val[]);

// cria pessoa
pessoa *criaPessoaP(char nome[maxLen], char telefone[maxLen], char email[maxLen]);

// recebe o nome de um arquivo e pega o cabeçalho (numero de pessoas desse arquivo)
int getLinhas(char nomeArq[maxLenArq]);

// popula um vetor de pessoas através de um arquivo, recebe como parametro o nome
pessoa **getPessoas(char nomeArq[maxLenArq]);

#endif //HASHABERTO_PESSOA_H
