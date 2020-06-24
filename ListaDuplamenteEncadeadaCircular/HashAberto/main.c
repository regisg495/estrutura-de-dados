#include <windows.h>
#include "TabelaHash.h"

enum menu {
    LERARQ = 1, INSERIR = 2, DELETAR = 3, BUSCAR = 4, DESEMPENHO = 5, REDIMENSIONAR = 6, SAIR = 7, IMPRIMIR = 8
};

pessoa *p;
pessoa **pessoas;
int opt, result = 0, usouArquivo = 0;
char nome[maxLen], telefone[maxLen], email[maxLen], nomeArq[maxLenArq];

void menu();

int main() {

    SetConsoleOutputCP(65001);

    tabelahash *t = criaTabela(12);

    printf("Escolha a opção que melhor lhe agrade: ");

    while (opt != SAIR) {

        menu();
        scanf("%d", &opt);

        fflush(stdin);

        switch (opt) {
            case LERARQ :

                if (usouArquivo == 1) {
                    printf("\nVocê já usou essa opção");
                    break;
                }

                printf("\nEntre com o nome do arquivo + a extensão: ");
                fgets(nomeArq, maxLenArq, stdin);

                nomeArq[strcspn(nomeArq, "\n")] = 0;

                if (getLinhas(nomeArq) == -1) {
                    printf("\nArquivo Inválido");
                    break;
                }

                if (t->elements >= 1) {
                    result = reinicializa(&t, nomeArq);
                } else {
                    deletaTabela(&t);
                    t = criaTabela(getLinhas(nomeArq) * 2);
                }

                if (t == NULL || result == -1) break;

                pessoas = getPessoas(nomeArq);

                result = populaTabela(t, pessoas, nomeArq);

                if (result == -1) {
                    printf("\nNão foi possível popular sua tabela hash ;(");
                } else {
                    printf("\nTabela hash populada com sucesso :)");
                    usouArquivo = 1;
                }

                break;

            case INSERIR:

                printf("\nEntre com o nome da pessoa: ");
                fgets(nome, maxLen, stdin);

                printf("\nEntre com o telefone da pessoa: ");
                fgets(telefone, maxLen, stdin);

                printf("\nEntre com o email da pessoa: ");
                fgets(email, maxLen, stdin);

                fflush(stdin);

                if (ehValido(nome) == -1 || ehValido(telefone) == -1 || ehValido(email) == -1) {
                    printf("\nDados Inválidos");
                    break;
                }

                nome[strcspn(nome, "\n")] = 0;
                telefone[strcspn(telefone, "\n")] = 0;
                email[strcspn(email, "\n")] = 0;

                if(existeChave(t, email) == 1) {
                    printf("\nJá existe uma pessoa cadastrada com o email %s", email);
                    break;
                }

                p = criaPessoaP(nome, telefone, email);

                result = insereNaTabela(t, p);

                if (result == 1) {
                    printf("\n%s Foi inserido com sucesso", nome);
                } else {
                    printf("\nUm erro ocorreu");
                }


                break;

            case DELETAR:

                printf("\nEntre com email da pessoa que deseja deletar: ");
                fgets(email, maxLen, stdin);

                fflush(stdin);

                if (ehValido(email) == -1) {
                    printf("\nO email que você digitou é invalido");
                    break;
                }

                email[strcspn(email, "\n")] = 0;

                int result = deletaDaTabela(t, email);

                if (result == 1) {
                    printf("\nA pessoa de email %s foi deletada com sucesso!", email);
                } else {
                    printf("\nNão foi possível deletar");
                }


                break;

            case BUSCAR:

                printf("\nEntre com email que deseja buscar: ");
                fgets(email, maxLen, stdin);

                fflush(stdin);

                if (ehValido(email) == -1) {
                    printf("\nO email que você digitou é invalido");
                    break;
                }

                email[strcspn(email, "\n")] = 0;
                result = buscaNaTabela(t, email, &p);
                if (result == 1) {
                    printf("\nPessoa encontrada! Nome: %s. Telefone: %s. Email: %s.", p->nome, p->telefone, p->email);
                } else {
                    printf("\nNao foi possível encontrar a pessoa");
                }

                break;

            case DESEMPENHO:

                dadosDesempenho(t);
                break;

            case REDIMENSIONAR:
                printf("\nRedimensionando o tamanho da sua tabela...");
                result = rehash(&t);

                if (result == 1) {
                    printf("\nTabela redimensionada! Agora sua tabela tem um tamanho de %d e seu fator de carga é %lf",
                           t->size, fatorOcupacao(t));
                } else {
                    printf("\nNão foi possivel redimensionar =(");
                }

                break;

            case SAIR:

                printf("\nDeletando tabela...");
                deletaTabela(&t);
                printf("\nBye!");
                break;

            case IMPRIMIR:
                visualizaTabela(t);
                break;

            default:
                printf("\nEntre com uma opção válida");
                break;


        }

    }

    return 0;
}

void menu() {
    printf("\n1 para popular uma tabela hash a partir de um arquivo");
    printf("\n2 para inserir uma nova pessoa");
    printf("\n3 para deletar uma pessoa pelo email");
    printf("\n4 para buscar uma pessoa pelo email");
    printf("\n5 para imprimir dados de desempenho");
    printf("\n6 para redimensionar o tamanho da tabela");
    printf("\n7 para sair");
    printf("\n8 para imprimir a tabela\n");
}