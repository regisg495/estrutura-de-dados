//
// Created by regis on 01/12/2019.
//

#include "TabelaHash.h"

tabelahash *criaTabela(unsigned int size) {
    tabelahash *t = (tabelahash *) malloc(sizeof(tabelahash));

    if (!t) {
        exit(1);
    }

    t->tabela = (lista **) malloc(sizeof(lista *) * size);

    if (!t->tabela) {
        exit(1);
    }

    t->size = size;
    t->elements = 0;
    for (int i = 0; i < size; i++) {
        t->tabela[i] = NULL;
    }
    return t;

}

int populaTabela(tabelahash *t, pessoa **p, char nomeArq[maxLenArq]) {

    if (getLinhas(nomeArq) == -1) {
        return -1;
    }

    for (int i = 0; i < getLinhas(nomeArq); i++) {
        int result = insereNaTabela(t, p[i]);
        if (result == -1) return -1;
    }

    free(p);

    return 1;
}

unsigned int hash(tabelahash *t, char email[maxLen]) {

    unsigned int valorHash;


    for (valorHash = 0; *email != '\0'; email++) {
        valorHash = *email + 31 * valorHash;
    }

    return valorHash % t->size;

}

int rehash(tabelahash **t) {
    if (*t == NULL) return -1;

    tabelahash *cursor = *t;

    tabelahash *temp = criaTabela(cursor->size * 2);

    if (!temp) {
        return -1;
    }

    for (int i = 0; i < cursor->size; i++) {
        if (cursor->tabela[i] != NULL) {
            for (nodo *aux = cursor->tabela[i]->inicio; aux != NULL; aux = aux->prox) {
                pessoa *p = aux->p;
                int result = insereNaTabela(temp, p);
                if (result == -1) {
                    deletaTabela(&temp);
                    return -1;
                }
            }
        }
    }

    deletaTabela(t);
    *t = temp;

    return 1;

}

int existeChave(tabelahash *t, char email[maxLen]) {
    unsigned int valorHash = hash(t, email);
    pessoa* p;
    if(t->tabela[valorHash] == NULL) return - 1;
    return getPessoa(t->tabela[valorHash], email, &p);
}

int insereNaTabela(tabelahash *t, pessoa *p) {

    if (p == NULL || ehValido(p->email) == -1 || t == NULL) {
        return -1;
    }

    unsigned int valorHash = hash(t, p->email);
    if (t->tabela[valorHash] == NULL) {
        t->tabela[valorHash] = criaLista();
    }
    int r = insereNaLista(t->tabela[valorHash], p);
    if (r == 1) {
        t->elements++;
    }
    return r;

}

int deletaDaTabela(tabelahash *t, char email[maxLen]) {

    if (ehValido(email) == -1) {
        return -1;
    } else {
        unsigned int valorHash = hash(t, email);
        return deletaDaLista(t->tabela[valorHash], email);
    }
}

int buscaNaTabela(tabelahash *t, char email[maxLen], pessoa **p) {
    if (ehValido(email) == -1) {
        return -1;
    } else {
        unsigned int valorHash = hash(t, email);
        if (t->tabela[valorHash] == NULL) return -1;
        if (getPessoa(t->tabela[valorHash], email, p) == 1) {
            return 1;
        } else {
            return -1;
        }
    }
}

void dadosDesempenho(tabelahash *t) {
    if (t == NULL) return;

    unsigned int numChaves = 0;
    unsigned int numColisoes = 0;

    for (int i = 0; i < t->size; i++) {
        if (t->tabela[i] != NULL) {
            numChaves++;
            if (t->tabela[i]->counter >= 2) {
                numColisoes = numColisoes + (t->tabela[i]->counter - 1);
            }
        }
    }

    printf("\nMédia do Tamanho dos Clusters: %lf", (double) t->elements / numChaves);
    printf("\nNúmero de Colisoes: %d", numColisoes);
    printf("\nFator de ocupação: %lf", fatorOcupacao(t));

}

double fatorOcupacao(tabelahash *t) {
    if (t == NULL) {
        return 0;
    }
    return (double) t->elements / t->size;
}

void visualizaTabela(tabelahash *t) {
    for (int i = 0; i < t->size; i++) {
        if (t->tabela[i] != NULL) {
            printf("\nIndice da tabela %d ", i);
            visualizaLista(t->tabela[i]);
        }
    }
}

void deletaTabela(tabelahash **t) {
    if (*t == NULL) {
        return;
    }

    tabelahash *temp = *t;

    for (int i = 0; i < temp->size; i++) {
        if (temp->tabela[i] != NULL) {
            deletaLista(&temp->tabela[i]);
        }
    }
    free(temp->tabela);
    free(temp);
    *t = NULL;
}

int reinicializa(tabelahash **t, char nomeArq[maxLenArq]) {
    if (*t == NULL || getLinhas(nomeArq) == -1) {
        return -1;
    }
    tabelahash *cursor = *t;
    tabelahash *temp = criaTabela((cursor->elements + getLinhas(nomeArq)) * 2);

    if (!temp) {
        return -1;
    }

    for (int i = 0; i < cursor->size; i++) {
        if (cursor->tabela[i] != NULL) {
            for (nodo *aux = cursor->tabela[i]->inicio; aux != NULL; aux = aux->prox) {
                pessoa *p = aux->p;
                int r = insereNaTabela(temp, p);
                if (r == -1) {
                    deletaTabela(&temp);
                    return -1;
                }
            }
        }
    }
    deletaTabela(t);
    *t = temp;
    return 1;
}

