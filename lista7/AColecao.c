#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char titulo[100];
    char genero[100];
    char estudio[100];
    char console[100];
    int  nota;
    int  anoLancamento;
} Jogo;

//Funções
//Print com base no ano
void printAno(Jogo *col, int n, int ano) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (col[i].anoLancamento == ano) {
            printf("%s\n", col[i].titulo);
            count++;
        }
    }
    //Caso não tenha nenhum jogo com esse ano
    if (count == 0)
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
    else
        printf("Tenho %d jogos || %d.\n", count, ano);
}

//Print com base na primeira letra
void printLetra(Jogo *col, int n, char letra) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (col[i].titulo[0] == letra) {
            printf("%s\n", col[i].titulo);
            count++;
        }
    }
    //Caso não tenha jogo com essa letra
    if (count == 0)
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
    else
        printf("Tenho %d jogos || %c.\n", count, letra);
}

//Print com base no estudio
void printStudio(Jogo *col, int n, char *estudio) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(col[i].estudio, estudio) == 0) {
            printf("%s\n", col[i].titulo);
            count++;
        }
    }
    //Caso não tenha jogo com esse estudio
    if (count == 0)
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
    else
        printf("Tenho %d jogos || %s.\n", count, estudio);
}

//Print com base no console
void printConsole(Jogo *col, int n, char *console) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(col[i].console, console) == 0) {
            printf("%s\n", col[i].titulo);
            count++;
        }
    }
    //Caso não tenha jogo com esse console
    if (count == 0)
        printf("Nenhum jogo tem esse parâmetro Sr Sr Wilson.\n");
    else
        printf("Tenho %d jogos || %s.\n", count, console);
}

//Print da coleção
void printColecao(Jogo *col, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", col[i].titulo, col[i].nota);
    }
}

int main() {
    //variaveis iniciais
    Jogo colecao[100];
    int n;
    scanf("%d", &n);

    //recebendo os atributos dos jogos
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s %s %d %d", colecao[i].titulo, colecao[i].genero, colecao[i].estudio, colecao[i].console, &colecao[i].nota, &colecao[i].anoLancamento);

        //verificando entrada da nota
        if (colecao[i].nota > 7)
            printf("AWESOME! Mais um GOTY pra minha coleção!\n");
        else if (colecao[i].nota < 4)
            printf("Era melhor jogar mais um jogo de Mahjong.\n");
    }

    //variavel de função e parametro
    char funcao[50];
    char parametro[100];

   //recebendo as funções
    while (scanf("%s", funcao) == 1) {
        if (strcmp(funcao, "printColecao") == 0) {
            printColecao(colecao, n);
        } else {
            scanf("%s", parametro);
            if (strcmp(funcao, "printAno") == 0)
                printAno(colecao, n, atoi(parametro));
            else if (strcmp(funcao, "printLetra") == 0)
                printLetra(colecao, n, parametro[0]);
            else if (strcmp(funcao, "printStudio") == 0)
                printStudio(colecao, n, parametro);
            else if (strcmp(funcao, "printConsole") == 0)
                printConsole(colecao, n, parametro);
        }
    }

    printf("Enjoei de jogar, agora vou ver TV.\n");

    return 0;
}
