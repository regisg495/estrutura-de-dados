//
// Created by regis on 19/11/2019.
//

#ifndef ORDENACAOLISTAENCADEADA_ALGORITMOSORDENACAO_H
#define ORDENACAOLISTAENCADEADA_ALGORITMOSORDENACAO_H

#include "ListaEncadeada.h"
#include <stdlib.h>

void troca(nodo *maior, nodo *menor);

void bubbleSort(lista *l);

void selectionSort(lista *l);

void insertionSort(lista *l);

int particiona(lista *, int inicio, int fim);

int partRandom(lista *l, int inicio, int fim);

void quickSort(lista *l, int inicio, int fim);

#endif //ORDENACAOLISTAENCADEADA_ALGORITMOSORDENACAO_H
