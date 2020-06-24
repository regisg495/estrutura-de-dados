//
// Created by regis on 29/10/2019.
//

#include "TabelaHash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getHash(int chave) {
    return size % chave;
}

item *criaItem(int chave, char val[50]) {
    item *it = (item *) malloc(sizeof(item));
    if (!it) {
        return NULL;
    } else {
        it->chave = chave;
        strcpy(it->val, val);
        return it;
    }
}

int insere(int chave, char val[50]) {
    item *it = criaItem(chave, val);

    val[strcspn(val, "\n")] = 0;

    if (it == NULL) {
        return -1;
    } else {
        int hash = getHash(chave);
        while (tabela[hash] != NULL) {
            if (tabela[hash] != NULL) {
                if (tabela[hash]->status == livre) break;
            }
            ++hash;
            hash %= size;
        }
        it->status = ocupado;
        tabela[hash] = it;
        return 1;
    }
}

item *get(int chave) {
    int hash = getHash(chave);

    while (tabela[hash] != NULL) {
        if (tabela[hash]->chave == chave) {
            return tabela[hash];
        } else {
            ++hash;
            hash %= size;
        }
    }
    return NULL;
}

int deleta(int chave) {
    int hash = getHash(chave);

    while (tabela[hash] != NULL) {
        if (tabela[hash]->chave == chave) {
            tabela[hash]->status = -1;
            return 1;
        }
        ++hash;
        hash %= size;
    }
    return -1;
}

void visualiza(item *t[]) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        if (t[i] != NULL && t[i]->status != -1) {
            printf("Indice: %d. Chave: %d. Val:%s\n", i, t[i]->chave, t[i]->val);
        }
    }
}

void deletaTabela(item *t[]) {
    for (int i = 0; i < size; i++) {
        free(t[i]);
    }
    free(t);
}

