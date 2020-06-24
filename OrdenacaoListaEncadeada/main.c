#include <stdio.h>
#include "ListaEncadeada.h"
#include "AlgoritmosOrdenacao.h"

int main() {
        lista *l = criaLista();

        preenche(l, 100);

        visualiza(l);

        quickSort(l, 0, l->counter - 1);
        visualiza(l);

    return 0;
}