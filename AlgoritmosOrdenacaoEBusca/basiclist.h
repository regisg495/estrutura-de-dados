//
// Created by regis on 26/09/2019.
//

#ifndef SEARCHANDSORTALGORITHMS_BASICLIST_H
#define SEARCHANDSORTALGORITHMS_BASICLIST_H

#include <stdbool.h>
// simple list

typedef struct {
    int *vet;
    int tam;
} lista;

lista *criaLista(int n);

void preenche(lista *l);

void desordena(lista *l);

void visualiza(lista *l);

bool estaVazia(lista *l);

bool numMaiorQueElementos(lista *l, int busca);

bool numNegativo(int busca);

void troca(int *maior, int *menor);




#endif //SEARCHANDSORTALGORITHMS_BASICLIST_H
