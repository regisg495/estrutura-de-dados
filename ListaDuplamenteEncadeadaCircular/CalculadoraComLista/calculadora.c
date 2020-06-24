//
// Created by regis on 12/10/2019.
//

#include "calculadora.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int ehValido(char val[maxLengthVal]) {
    if (val == NULL || strlen(val) <= 0) {
        return -1;
    } else {
        if (val[0] == '-') {
            for (int i = 1; i < strlen(val); i++) {
                if (val[i] < 48 || val[i] > 57) return -1;
            }
        } else {
            for (int i = 0; i < strlen(val); i++) {
                if (val[i] < 48 || val[i] > 57) return -1;
            }
            return 1;
        }
    }
}

int adicionaParaCalculo(lista *l, char val[maxLengthVal]) {
    int k = positivo;
    int erro = 0;

    if (val[0] == '-') {
        k = negativo;
    }

    for (int i = strlen(val) - 1; i >= k; i -= 3) {
        char aux[] = "000";
        int count = 2;
        for (int j = i; j >= k && count >= 0; j--) {
            aux[count] = val[j];
            count--;
        }

        erro = insereNoInicio(l, atoi(aux));
        if (erro == -1) return erro;

    }

    if (k == negativo) {
        erro = insereNoFim(l, negativo);
    } else {
        erro = insereNoFim(l, positivo);
    }

    return erro;
}

int getSinal(lista *l) {
    if (l == NULL || estaVazia(l) == 1) {
        return 0;
    } else {
        return getVal(l, l->counter - 1);
    }
}

int trocaSinal(lista *l) {
    if (l == NULL || estaVazia(l) == 1) {
        return -1;
    } else {
        nodo *temp = get(l, l->counter - 1);
        if (temp->val == positivo) {
            temp->val = negativo;
        } else {
            temp->val = positivo;
        }
        return 1;
    }
}

int ehMaior(lista *l, lista *l2) {

    for (int i = 0; i <= l->counter - 1; i++) {

        int valL1 = getVal(l, i);
        int valL2 = getVal(l2, i);


        if (valL1 < 0) {
            valL1 *= -1;
        }

        if (valL2 < 0) {
            valL2 *= -1;
        }

        if (valL1 > valL2) {
            return 1;
        }

        if (valL2 > valL1) {
            return 0;
        }
    }
    return 2;
}

int inverteValor(lista *l) {

    if (l == NULL || estaVazia(l) == 1) {
        return -1;
    } else {
        for (int i = 0; i <= l->counter - 1; i++) {
            nodo *tmp = get(l, i);
            tmp->val *= -1;
        }
    }
    return 1;
}

int iguala(lista *l1, lista *l2) {
    if (l2->counter == l1->counter) return 1;

    int result;

    if (l1->counter > l2->counter) {
        for (int i = l1->counter - l2->counter; i > 0; i--) {
            result = insereNoInicio(l2, 0);
            if (result == -1) return result;
        }

    } else {
        for (int i = l2->counter - l1->counter; i > 0; i--) {
            result = insereNoInicio(l1, 0);
            if (result == -1) return result;
        }
    }

    return 1;
}

lista *soma(lista *l, lista *l2) {
    lista *resp = criaLista();

    if (!resp) {
        return NULL;
    }

    if (estaVazia(l) == 1 && estaVazia(l2) == 1 || l == NULL || l2 == NULL) {
        insereNoInicio(resp, 0);
        return resp;
    }

    int sinalL1 = getSinal(l);
    int sinalL2 = getSinal(l2);

    iguala(l, l2);

    if (sinalL1 == positivo && sinalL2 == negativo) {

        if (ehMaior(l, l2) == 1) {
            deletaLista(&resp);
            trocaSinal(l2);
            resp = subtrai(l, l2);
            return resp;
        }

        if (ehMaior(l, l2) == 0) {
            deletaLista(&resp);
            trocaSinal(l2);
            resp = subtrai(l2, l);
            inverteValor(resp);
            return resp;
        }

    }

    if (sinalL1 == negativo && sinalL2 == positivo) {
        if (ehMaior(l, l2) == 1) {
            deletaLista(&resp);
            inverteValor(l2);
            resp = subtrai(l, l2);
            inverteValor(resp);
            return resp;
        }
        if (ehMaior(l, l2) == 0) {
            deletaLista(&resp);
            trocaSinal(l);
            resp = subtrai(l2, l);
            return resp;
        }
    }


    int sobra = 0;

    for (int i = l->counter - 2; i >= 0; i--) {
        int resultSoma = ((getVal(l, i)) + (getVal(l2, i)) + sobra) % 1000;
        sobra = ((getVal(l, i)) + (getVal(l2, i)) + sobra) / 1000;

        insereNoInicio(resp, resultSoma);

    }

    if (sobra != 0) {
        insereNoInicio(resp, sobra);
    }

    if (sinalL1 == negativo && sinalL2 == negativo) {
        inverteValor(resp);
    }

    return resp;

}

lista *subtrai(lista *l, lista *l2) {
    lista *resp = criaLista();

    if (!resp) {
        return NULL;
    }

    if (estaVazia(l) == 1 && estaVazia(l2) == 1 || l == NULL || l2 == NULL) {
        insereNoInicio(resp, 0);
        return resp;
    }

    iguala(l, l2);

    int sinalL1 = getSinal(l);
    int sinalL2 = getSinal(l2);


    if (sinalL1 == positivo && sinalL2 == positivo && ehMaior(l, l2) == 0) {
        deletaLista(&resp);
        trocaSinal(l);
        inverteValor(l);
        resp = soma(l2, l);
        inverteValor(resp);
        return resp;
    }
    if (sinalL1 == negativo && sinalL2 == positivo) {
        deletaLista(&resp);
        trocaSinal(l2);
        resp = soma(l, l2);
        return resp;
    }
    if (sinalL1 == negativo && sinalL2 == negativo && ehMaior(l, l2) == 0) {
        deletaLista(&resp);
        trocaSinal(l);
        inverteValor(l2);
        resp = soma(l2, l);
        inverteValor(resp);
        return resp;
    }
    if (sinalL1 == positivo && sinalL2 == negativo) {
        deletaLista(&resp);
        trocaSinal(l2);
        resp = soma(l, l2);
        return resp;
    }

    int pede = 0;

    for (int i = l->counter - 2; i >= 0; i--) {

        if (getVal(l, i) >= getVal(l2, i) + pede) {
            int result = (getVal(l, i) - getVal(l2, i)) - pede;
            insereNoInicio(resp, result);
            pede = 0;
        }

        if (getVal(l, i) < getVal(l2, i) + pede) {
            int result = ((getVal(l, i) + 1000) - getVal(l2, i)) - pede;
            pede = 1;
            insereNoInicio(resp, result);
        }

    }

    if (sinalL1 == negativo && sinalL2 == negativo) {
        inverteValor(resp);
    }

    return resp;
}

void visualizaListaCalculada(lista *l) {
    if (l == NULL || estaVazia(l) == 1) return;

    printf("\nResultado: ");
    for (nodo *temp = l->inicio; temp != NULL; temp = temp->prox) {
        if (temp == l->inicio) {
            printf("%d", temp->val);
        } else if (temp != l->inicio && temp->val >= 0 && temp->val <= 9) {
            printf("00%d", temp->val);
        } else if (temp != l->inicio && temp->val >= 10 && temp->val <= 99) {
            printf("0%d", temp->val);
        } else if (temp != l->inicio && temp->val >= 100 && temp->val <= 999) {
            printf("%d", temp->val);
        } else if (temp != l->inicio && temp->val <= -1 && temp->val >= -9) {
            printf("00%d", temp->val * -1);
        } else if (temp != l->inicio && temp->val <= -10 && temp->val >= -99) {
            printf("0%d", temp->val * -1);
        } else if (temp != l->inicio && temp->val <= -100 && temp->val >= -999) {
            printf("%d", temp->val * -1);
        }
    }
    printf("\n");
}
