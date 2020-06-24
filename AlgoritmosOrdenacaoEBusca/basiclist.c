//
// Created by regis on 26/09/2019.
//

#include "basiclist.h"
#include <stdlib.h>
#include <stdio.h>


lista *criaLista(int n) {
    n++;
    lista *l = (lista *) malloc(sizeof(lista));
    l->vet = (int *) malloc(sizeof(int) * n);
    l->tam = n;
    return l;
}

void preenche(lista *l) {
    for (int i = 0; i < l->tam + 1; i++) {
        l->vet[i] = i;
    }
}

void desordena(lista *l) {
    for (int i = 0; i < l->tam; i++) {
        troca(&l->vet[rand() % (l->tam)], &l->vet[rand() % (l->tam)]);
    }
}

void visualiza(lista *l) {
    for (int i = 0; i < l->tam; i++) {
        printf("\n%d", l->vet[i]);
    }
}

bool estaVazia(lista *l) {
    return l->tam == 0;
}

bool numMaiorQueElementos(lista *l, int busca) {
    return busca > l->tam;
}

bool numNegativo(int busca) {
    return busca < 0;
}

void troca(int *maior, int *menor) {
    int temp;
    temp = *maior;
    *maior = *menor;
    *menor = temp;
}

