//
// Created by regis on 19/11/2019.
//

#include "AlgoritmosOrdenacao.h"


void troca(nodo *maior, nodo *menor) {
    int temp;
    temp = maior->val;
    maior->val = menor->val;
    menor->val = temp;
}

void bubbleSort(lista *l) {
    if (estaVazia(l) == 1) {
        return;
    }

    for (int i = l->counter; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (get(l, j)->val > get(l, j + 1)->val) {
                troca(get(l, j), get(l, j + 1));
            }
        }
    }
}

void selectionSort(lista *l) {
    if (estaVazia(l) == 1) {
        return;
    }
    for (int i = 0; i < l->counter; i++) {
        int escolha = i;
        for (int j = i + 1; j < l->counter; j++) {
            if (get(l, j)->val <= (get(l, escolha)->val)) {
                escolha = j;
            }
        }
        troca(get(l, i), get(l, escolha));

    }
}

void insertionSort(lista *l) {

    if (estaVazia(l) == 1) {
        return;
    }

    int j, val;
    for (int i = 0; i <= l->counter - 1; i++) {
        j = i - 1;
        val = get(l, i)->val;
        while (j >= 0 && get(l, j)->val > val) {
            get(l, j + 1)->val = get(l, j)->val;
            j = j - 1;
        }
        get(l, j + 1)->val = val;
    }
}

int particiona(lista *l, int inicio, int fim) {
    nodo *pivo = get(l, fim);
    int pivoIndice = inicio;

    for (int i = inicio; i < fim; i++) {
        if (get(l, i)->val <= pivo->val) {
            troca(get(l, i), get(l, pivoIndice));
            pivoIndice++;
        }
    }

    troca(get(l, pivoIndice), get(l, fim));

    return pivoIndice;
}

int partRandom(lista *l, int inicio, int fim) {
    int pivo = (rand() % (fim - inicio + 1)) + inicio;
    troca(get(l, pivo), get(l, fim));
    return particiona(l, inicio, fim);
}

void quickSort(lista *l, int inicio, int fim) {

    if (estaVazia(l) == 1) {
        return;
    }

    if (inicio < fim) {
        int pivo = partRandom(l, inicio, fim);

        quickSort(l, inicio, pivo - 1);
        quickSort(l, pivo + 1, fim);
    }
}
