//
// Created by regis on 26/09/2019.
//
#include <stdlib.h>
#include "sort.h"

void bubbleSort(lista *l) {
    if (estaVazia(l)) {
        return;
    }
    iteracoesBubbleSort = 0;
    for (int i = l->tam; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            iteracoesBubbleSort++;
            if (l->vet[j] > l->vet[j + 1]) {
                troca(&l->vet[j], &l->vet[j + 1]);
            }
        }
    }
}

void selectionSort(lista *l) {
    if (estaVazia(l)) {
        return;
    }
    iteracoesSelectionSort = 0;
    for (int i = 0; i < l->tam; i++, iteracoesSelectionSort++) {
        int escolha = i;
        for (int j = i + 1; j < l->tam; j++, iteracoesSelectionSort++) {
            if (l->vet[j] <= l->vet[escolha]) {
                escolha = j;
            }
        }
        troca(&l->vet[i], &l->vet[escolha]);

    }
}

void insertionSort(lista *l) {
    int j, val;
    iteracoesInsertionSort = 0;
    for (int i = 0; i <= l->tam; i++) {
        j = i - 1;
        val = l->vet[i];
        iteracoesInsertionSort++;
        while (j >= 0 && l->vet[j] > val) {
            l->vet[j + 1] = l->vet[j];
            j = j - 1;
            iteracoesInsertionSort++;
        }
        l->vet[j + 1] = val;
    }
}

int particiona(lista *l, int inicio, int fim) {
    int pivo = l->vet[fim];
    int pivoIndice = inicio;

    for (int i = inicio; i < fim; i++, iteracoesQuickSort++) {
        if (l->vet[i] <= pivo) {
            troca(&l->vet[i], &l->vet[pivoIndice]);
            pivoIndice++;
        }
    }

    troca(&l->vet[pivoIndice], &l->vet[fim]);

    return pivoIndice;
}

int partRandom(lista *l, int inicio, int fim) {
    int pivo = (rand() % (fim - inicio + 1)) + inicio;
    troca(&l->vet[pivo], &l->vet[fim]);
    return particiona(l, inicio, fim);
}

void quickSort(lista *l, int inicio, int fim) {
    if (inicio < fim) {
        int pivo = partRandom(l, inicio, fim);

        quickSort(l, inicio, pivo - 1);
        quickSort(l, pivo + 1, fim);
    }
}
