//
// Created by regis on 12/10/2019.
//

#ifndef CALCULADORACOMLISTA_CALCULADORA_H
#define CALCULADORACOMLISTA_CALCULADORA_H

#include "listaDupla.h"

#define maxLengthVal 5000
#define positivo 0
#define negativo 1

// Valida a entrada digitada no console
int ehValido(char val[maxLengthVal]);

// adiciona o valor lido no console para a lista, cada nodo possui 3 digitos
int adicionaParaCalculo(lista *l, char val[maxLengthVal]);

// pega o sinal da lista (que está no fim)
int getSinal(lista *l);

// troca o sinal de uma lista
int trocaSinal(lista *l);

// verifica se o valor de uma lista é maior que a outra, independentemente de sinal
int ehMaior(lista *l, lista *l2);

// inverte o valor de uma lista (multiplica por -1)
int inverteValor(lista *l);

// Iguala o tamanho de ambas as listas, preenchendo com zero no início
int iguala(lista *l, lista *l2);

// soma uma lista com outra
lista *soma(lista *l, lista *l2);

// subtrai o valor de uma lista com outra
lista *subtrai(lista *l, lista *l2);

// visualiza uma lista calculada
void visualizaListaCalculada(lista *l);

#endif //CALCULADORACOMLISTA_CALCULADORA_H
