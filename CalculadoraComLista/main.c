#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "calculadora.h"
#include "listaDupla.h"

enum MENU {
    SOMA = 1, SUBTRAIR = 2, SAIR = 3
};

int opt, erro;
char firstNum[maxLengthVal];
char secondNum[maxLengthVal];

void erroNoNumero();

void erroAoInserir();

void menu();


int main() {

    SetConsoleOutputCP(65001);

    printf("Escolha a opção que melhor atende sua necessidade:\n");

    while (opt != SAIR) {
        menu();

        scanf("%d", &opt);
        fflush(stdin);


        switch (opt) {

            case SOMA:
                printf("\nEntre com o primeiro número: ");
                fgets(firstNum, maxLengthVal, stdin);
                fflush(stdin);

                firstNum[strcspn(firstNum, "\n")] = 0;

                if (ehValido(firstNum) == -1) {
                    erroNoNumero();
                    break;
                }

                lista *l = criaLista();

                erro = adicionaParaCalculo(l, firstNum);

                if (erro == -1) {
                    erroAoInserir();
                    break;
                }

                printf("\nEntre agora com o segundo número: ");
                fgets(secondNum, maxLengthVal, stdin);
                secondNum[strcspn(secondNum, "\n")] = 0;

                fflush(stdin);

                if (ehValido(secondNum) == -1) {
                    erroNoNumero();
                    break;
                }

                lista *l2 = criaLista();

                erro = adicionaParaCalculo(l2, secondNum);

                if (erro == -1) {
                    erroAoInserir();
                    break;
                }

                lista *l3 = soma(l, l2);

                if (l3 != NULL) {
                    visualizaListaCalculada(l3);
                } else {
                    printf("\nAlgum erro aconteceu ao efetuar sua operação, tente novamente");
                }

                // visualiza(l3);

                deletaLista(&l);
                deletaLista(&l2);
                deletaLista(&l3);

                break;

            case SUBTRAIR:

                printf("\nEntre com o primeiro número: ");
                fgets(firstNum, maxLengthVal, stdin);
                fflush(stdin);

                firstNum[strcspn(firstNum, "\n")] = 0;

                if (ehValido(firstNum) == -1) {
                    erroNoNumero();
                    break;
                }

                l = criaLista();

                erro = adicionaParaCalculo(l, firstNum);

                if (erro == -1) {
                    erroAoInserir();
                    break;
                }

                printf("\nEntre agora com o segundo número: ");
                fgets(secondNum, maxLengthVal, stdin);

                secondNum[strcspn(secondNum, "\n")] = 0;

                fflush(stdin);

                if (ehValido(secondNum) == -1) {
                    erroNoNumero();
                    break;
                }

                l2 = criaLista();

                erro = adicionaParaCalculo(l2, secondNum);

                if (erro == -1) {
                    erroAoInserir();
                    break;
                }

                l3 = subtrai(l, l2);

                if (l3 != NULL) {
                    visualizaListaCalculada(l3);
                } else {
                    printf("\nAlgum erro aconteceu ao efetuar sua operação, tente novamente");
                }

                // visualiza(l3);

                deletaLista(&l);
                deletaLista(&l2);
                deletaLista(&l3);

                break;

            case SAIR:
                printf("\nAté mais!");
                break;

            default:
                printf("\nEscolha uma opção que seja válida");
                break;
        }
    }

    return 0;

}

void erroNoNumero() {
    printf("\nO número que você digitou é invalido");
}

void erroAoInserir() {
    printf("\nOps! Algum erro Ao inserir aconteceu");
}

void menu() {
    printf("\n1 para somar\n2 para subtrair\n3 para sair\n");
}