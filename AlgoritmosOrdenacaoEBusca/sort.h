//
// Created by regis on 26/09/2019.
//

#ifndef SEARCHANDSORTALGORITHMS_SORT_H
#define SEARCHANDSORTALGORITHMS_SORT_H

#include "basiclist.h"

long iteracoesBubbleSort;
long iteracoesInsertionSort;
long iteracoesSelectionSort;
long iteracoesQuickSort;

void bubbleSort(lista* l);

void insertionSort(lista* l);

void selectionSort(lista *l);

int partRandom(lista *l, int inicio, int fim);

int particiona(lista *l, int inicio, int fim);

void quickSort(lista *l, int inicio, int fim);

#endif //SEARCHANDSORTALGORITHMS_SORT_H
