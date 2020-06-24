//
// Created by regis on 26/09/2019.
//

#include "search.h"

int buscaSequencial(lista *l, int busca) {
    iteracoesBuscaSeq = 0;
    if (estaVazia(l) || numNegativo(busca) || numMaiorQueElementos(l, busca)) {
        return -1;
    }
    for (int i = 0; i < l->tam; i++, iteracoesBuscaSeq++) {
        if (busca == l->vet[i]) {
            return l->vet[i];
        }
    }

    return -1;
}

int buscaBinaria(lista *l, int busca) {
    iteracoesBuscaB = 0;
    if (estaVazia(l) || numNegativo(busca) || numMaiorQueElementos(l, busca)) {
        return -1;
    }
    for (int i = 0, f = l->tam, m = 0; i <= f; iteracoesBuscaB++) {
        m = (i + f) / 2;
        if (busca == l->vet[m]) {
            return l->vet[m];
        } else {
            if (busca < l->vet[m]) {
                f = m - 1;
            } else {
                i = m + 1;
            }
        }
    }
    return -1;
}
