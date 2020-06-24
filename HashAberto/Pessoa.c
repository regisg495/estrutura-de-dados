//
// Created by regis on 01/12/2019.
//

#include "Pessoa.h"

int ehValido(char val[]) {
    if (val == NULL || strlen(val) <= 0 || strlen(val) > maxLen) {
        return -1;
    } else {
        return 1;
    }
}

pessoa *criaPessoaP(char nome[maxLen], char telefone[maxLen], char email[maxLen]) {

    pessoa *p = (pessoa *) malloc(sizeof(pessoa));

    strcpy(p->nome, nome);
    strcpy(p->telefone, telefone);
    strcpy(p->email, email);

    return p;
}

int getLinhas(char nomeArq[maxLenArq]) {
    FILE *arq;
    char inicio[100];

    arq = fopen(nomeArq, "r");

    if (arq == NULL) {
        return -1;
    }

    fgets(inicio, 100, arq);

    fclose(arq);

    return atoi(inicio);
}

pessoa **getPessoas(char nomeArq[maxLenArq]) {

    unsigned int maxLenLine = (maxLen * 3) + 2;

    FILE *arq;
    char str[maxLenLine];
    char *val;

    char nome[maxLen];
    char email[maxLen];
    char telefone[maxLen];

    arq = fopen(nomeArq, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo");
        return NULL;
    }

    unsigned int i = 0;
    unsigned int line = 0;

    pessoa **pessoas = (pessoa **) malloc(sizeof(pessoa *) * getLinhas(nomeArq));

    while (fgets(str, maxLenLine, arq) != NULL) {
        if (line != 0) {

            val = strtok(str, ";");
            strcpy(nome, val);

            val = strtok(NULL, ";");
            strcpy(telefone, val);

            val = strtok(NULL, ";");
            strcpy(email, val);

            nome[strcspn(nome, "\n")] = 0;
            telefone[strcspn(telefone, "\n")] = 0;
            email[strcspn(email, "\n")] = 0;

            pessoas[i] = criaPessoaP(nome, telefone, email);
            i++;

        }
        line++;
    }

    fclose(arq);
    return pessoas;
}
