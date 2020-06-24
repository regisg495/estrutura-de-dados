#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "sort.h"


float tempoDecorrido1;
float tempoDecorrido2;
float tempoDecorrido3;
float tempoDecorrido4;

clock_t t1;

int busca;

FILE *file;
FILE *file2;

int main() {


    file = fopen("buscas.csv", "w+");
    fprintf(file,
            "Tamanho do Vetor;Numero para Busca;Busca Binaria (Iteracoes);Busca Binaria (MS);Busca Sequencial (Iteracoes);Busca Sequencial (MS)");

    lista *l = criaLista(1000);
    preenche(l);

    srand(time(NULL));


    busca = rand() % (l->tam - 1);

    t1 = clock();
    int result1 = buscaSequencial(l, busca);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    int result2 = buscaBinaria(l, busca);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    // printf("\n%d", result1);
    // printf("\n%d", result2);
    fprintf(file, "\n%d;%ld;%ld;%lf;%ld;%lf", l->tam - 1, busca, iteracoesBuscaB, tempoDecorrido2, iteracoesBuscaSeq,
            tempoDecorrido1);

    free(l);

    busca = rand() % (l->tam - 1);


    lista *l2 = criaLista(2000);
    preenche(l2);
    // visualiza(l2);
    busca = rand() % (l2->tam - 1);

    t1 = clock();
    result1 = buscaSequencial(l2, busca);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    result2 = buscaBinaria(l2, busca);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    // printf("\n%d", result1);
    // printf("\n%d", result2);
    fprintf(file, "\n%d;%ld;%ld;%lf;%ld;%lf", l2->tam - 1, busca, iteracoesBuscaB, tempoDecorrido2, iteracoesBuscaSeq,
            tempoDecorrido1);

    free(l2);

    lista *l3 = criaLista(5000);

    preenche(l3);
    // visualiza(l3);
    busca = rand() % (l3->tam - 1);

    t1 = clock();
    result1 = buscaSequencial(l3, busca);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    result2 = buscaBinaria(l3, busca);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    // printf("\n%d", result1);
    // printf("\n%d", result2);
    fprintf(file, "\n%d;%ld;%ld;%lf;%d;%lf", l3->tam - 1, busca, iteracoesBuscaB, tempoDecorrido2, iteracoesBuscaSeq,
            tempoDecorrido1);

    free(l3);

    lista *l4 = criaLista(50000);

    preenche(l4);
    // visualiza(l4);
    busca = rand() % (l4->tam - 1);

    t1 = clock();
    result1 = buscaSequencial(l4, busca);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    result2 = buscaBinaria(l4, busca);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    // printf("\n%d", result1);
    // printf("\n%d", result2);
    fprintf(file, "\n%d;%ld;%ld;%lf;%ld;%lf", l4->tam - 1, busca, iteracoesBuscaB, tempoDecorrido2, iteracoesBuscaSeq,
            tempoDecorrido1);

    free(l4);

    lista *la = criaLista(100000);

    preenche(la);
    // visualiza(l4);
    busca = rand() % (la->tam - 1);

    t1 = clock();
    result1 = buscaSequencial(la, busca);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    result2 = buscaBinaria(la, busca);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    // printf("\n%d", result1);
    // printf("\n%d", result2);
    fprintf(file, "\n%d;%ld;%ld;%lf;%ld;%lf", la->tam - 1, busca, iteracoesBuscaB, tempoDecorrido2, iteracoesBuscaSeq,
            tempoDecorrido1);

    free(la);

    lista *lb = criaLista(500000);

    preenche(lb);
    // visualiza(l4);
    busca = rand() % (lb->tam - 1);

    t1 = clock();
    result1 = buscaSequencial(lb, busca);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    result2 = buscaBinaria(lb, busca);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    // printf("\n%d", result1);
    // printf("\n%d", result2);
    fprintf(file, "\n%d;%ld;%ld;%lf;%ld;%lf", lb->tam - 1, busca, iteracoesBuscaB, tempoDecorrido2, iteracoesBuscaSeq,
            tempoDecorrido1);

    free(lb);

    fclose(file);


    /*
     *
     *
     * Aqui Inicia os algoritmos de ordenação
     *
     *
     */


    file2 = fopen("ordenacoes.csv", "w+");

    fprintf(file2,
            "Tamanho do Vetor;Selection Sort(Iteracoes);Selection Sort (MS);Quick Sort (Iteracoes);Quick Sort (MS);"
            "Insertion Sort(Iteracoes); Insertion Sort(MS); Bubble Sort(Iteracoes); Bubble Sort(MS)");
    lista *l7 = criaLista(1000);
    preenche(l7);
    desordena(l7);
    lista *l8 = criaLista(1000);
    preenche(l8);
    desordena(l8);
    lista *l9 = criaLista(1000);
    preenche(l9);
    desordena(l9);
    lista *l10 = criaLista(1000);
    preenche(l10);
    desordena(l10);

    t1 = clock();
    selectionSort(l7);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    quickSort(l8, 0, l8->tam - 1);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    insertionSort(l9);
    t1 = clock() - t1;
    tempoDecorrido3 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    bubbleSort(l10);
    t1 = clock() - t1;
    tempoDecorrido4 = (float) t1 / CLOCKS_PER_SEC;
    // visualiza(l7);
    // visualiza(l8);
    // visualiza(l9);
    // visualiza(l10);


    fprintf(file, "\n%d;%ld;%lf;%ld;%lf;%ld;%lf;%ld;%lf", l7->tam - 1, iteracoesSelectionSort, tempoDecorrido1,
            iteracoesQuickSort,
            tempoDecorrido2, iteracoesInsertionSort, tempoDecorrido3, iteracoesBubbleSort, tempoDecorrido4);

    free(l7);
    free(l8);
    free(l9);
    free(l10);

    lista *l11 = criaLista(2000);
    preenche(l11);
    desordena(l11);
    lista *l12 = criaLista(2000);
    preenche(l12);
    desordena(l12);
    lista *l13 = criaLista(2000);
    preenche(l13);
    desordena(l13);
    lista *l14 = criaLista(2000);
    preenche(l14);
    desordena(l14);

    t1 = clock();
    selectionSort(l11);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    quickSort(l2, 0, l2->tam - 1);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    insertionSort(l13);
    t1 = clock() - t1;
    tempoDecorrido3 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    bubbleSort(l14);
    t1 = clock() - t1;
    tempoDecorrido4 = (float) t1 / CLOCKS_PER_SEC;
    // visualiza(l11);
    // visualiza(l2);
    // visualiza(l3);
    // visualiza(l14);

    fprintf(file, "\n%d;%ld;%lf;%ld;%lf;%ld;%lf;%ld;%lf", l11->tam - 1, iteracoesSelectionSort, tempoDecorrido1,
            iteracoesQuickSort,
            tempoDecorrido2, iteracoesInsertionSort, tempoDecorrido3, iteracoesBubbleSort, tempoDecorrido4);

    free(l11);
    free(l12);
    free(l13);
    free(l14);

    lista *l15 = criaLista(5000);
    preenche(l15);
    desordena(l15);
    lista *l16 = criaLista(5000);
    preenche(l16);
    desordena(l16);
    lista *l17 = criaLista(5000);
    preenche(l17);
    desordena(l17);
    lista *l18 = criaLista(5000);
    preenche(l18);
    desordena(l18);

    t1 = clock();
    selectionSort(l15);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    quickSort(l16, 0, l16->tam - 1);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    insertionSort(l17);
    t1 = clock() - t1;
    tempoDecorrido3 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    bubbleSort(l18);
    t1 = clock() - t1;
    tempoDecorrido4 = (float) t1 / CLOCKS_PER_SEC;
    // visualiza(l15);
    // visualiza(l16);
    // visualiza(l17);
    // visualiza(l18);

    fprintf(file, "\n%d;%ld;%lf;%ld;%lf;%ld;%lf;%ld;%lf", l15->tam - 1, iteracoesSelectionSort, tempoDecorrido1,
            iteracoesQuickSort,
            tempoDecorrido2, iteracoesInsertionSort, tempoDecorrido3, iteracoesBubbleSort, tempoDecorrido4);

    free(l15);
    free(l16);
    free(l17);
    free(l18);

    lista *l19 = criaLista(50000);
    preenche(l19);
    desordena(l19);
    lista *l20 = criaLista(50000);
    preenche(l20);
    desordena(l20);
    lista *l21 = criaLista(50000);
    preenche(l21);
    desordena(l21);
    lista *l22 = criaLista(50000);
    preenche(l22);
    desordena(l22);


    t1 = clock();
    selectionSort(l19);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    quickSort(l20, 0, l20->tam - 1);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    insertionSort(l21);
    t1 = clock() - t1;
    tempoDecorrido3 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    bubbleSort(l22);
    t1 = clock() - t1;
    tempoDecorrido4 = (float) t1 / CLOCKS_PER_SEC;
    // visualiza(l19);
    // visualiza(l20);
    // visualiza(l21);
    // visualiza(l22);

    fprintf(file, "\n%d;%ld;%lf;%ld;%lf;%ld;%lf;%ld;%lf", l19->tam - 1, iteracoesSelectionSort, tempoDecorrido1,
            iteracoesQuickSort,
            tempoDecorrido2, iteracoesInsertionSort, tempoDecorrido3, iteracoesBubbleSort, tempoDecorrido4);

    free(l19);
    free(l20);
    free(l21);
    free(l22);

    lista *l23 = criaLista(100000);
    preenche(l23);
    desordena(l23);
    lista *l24 = criaLista(100000);
    preenche(l24);
    desordena(l24);
    lista *l25 = criaLista(100000);
    preenche(l25);
    desordena(l25);
    lista *l26 = criaLista(100000);
    preenche(l26);
    desordena(l26);


    t1 = clock();
    selectionSort(l23);
    t1 = clock() - t1;
    tempoDecorrido1 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    quickSort(l24, 0, l24->tam - 1);
    t1 = clock() - t1;
    tempoDecorrido2 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    insertionSort(l25);
    t1 = clock() - t1;
    tempoDecorrido3 = (float) t1 / CLOCKS_PER_SEC;
    t1 = clock();
    bubbleSort(l26);
    t1 = clock() - t1;
    tempoDecorrido4 = (float) t1 / CLOCKS_PER_SEC;
    // visualiza(l19);
    // visualiza(l20);
    // visualiza(l21);
    // visualiza(l22);

    fprintf(file, "\n%d;%ld;%lf;%ld;%lf;%ld;%lf;%ld;%lf", l26->tam - 1, iteracoesSelectionSort, tempoDecorrido1,
            iteracoesQuickSort,
            tempoDecorrido2, iteracoesInsertionSort, tempoDecorrido3, iteracoesBubbleSort, tempoDecorrido4);

    free(l23);
    free(l24);
    free(l25);
    free(l26);

    fclose(file2);

}


