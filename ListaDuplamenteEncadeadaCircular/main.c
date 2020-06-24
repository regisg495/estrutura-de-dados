#include <stdio.h>
#include "ListaDuplamenteEncadeadaCircular.h"

int main() {

    lista *l = criaLista(1000);

    for (int i = 0; i < 50; i++) {
        int r = insereNoFim(l, i);
        if (r == -1) break;
    }
    visualiza(l);



    for (int i = 0; i < 100; i++) {
        int r = insereNoInicio(l, i);
        if (r == -1) break;
    }

    visualiza(l);

    for (int i = 0; i < 150; i++) {
        int r = insereNaPos(l, i, i);
        if(r == - 1) break;
    }

    visualiza(l);


    // deleting 150 nodes

    for(int i = 0; i < 150; i++) {
        int r = deletaNaPos(l, i);
        if(r == - 1) break;
    }

    visualiza(l);

    for(int i = 0; i < 25; i++) {
        int r = deletaNoInicio(l);
        if (r == -1) break;
    }

    //visualiza(l);

    // Mostra como a lista é circular! XD
    // visualizaCircular(l);

    deletaLista(&l);

    return 0;
}