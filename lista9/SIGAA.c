#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Aluno {
    char mat[12];
    int pri;
    double cr;
    long long L, R;
    int score;
    struct Aluno* prox;
} Aluno;

typedef struct {
    Aluno* inicio;
    Aluno* fim;
} Fila;

void iniciar(Fila* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void adicionar(Fila* f, Aluno* a) {
    a->prox = NULL;
    if (f->fim == NULL) {
        f->inicio = a;
        f->fim = a;
    } else {
        f->fim->prox = a;
        f->fim = a;
    }
}

Aluno* retirar(Fila* f) {
    if (f->inicio == NULL) return NULL;

    Aluno* a = f->inicio;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    a->prox = NULL;
    return a;
}

int main() {
    char comando[10];
    char nome_disc[55];
    int vagas;

    Fila fila, confirmados;
    iniciar(&fila);
    iniciar(&confirmados);

    long long relogio = 1;  // relógio GLOBAL, nunca reinicia

    while (scanf("%s", comando) == 1) {

        if (strcmp(comando, "START") == 0) {
            scanf("%s %d", nome_disc, &vagas);

        } else if (strcmp(comando, "ADD") == 0) {
            Aluno* a = malloc(sizeof(Aluno));
            scanf("%s %d %lf %lld %lld",
                  a->mat, &a->pri, &a->cr, &a->L, &a->R);

            a->score = (int)round(a->cr * 100) / a->pri;
            a->prox = NULL;

            adicionar(&fila, a);

        } else if (strcmp(comando, "PROC") == 0) {
            int qtd;
            scanf("%d", &qtd);

            int processados = 0;

            while (processados < qtd && fila.inicio != NULL) {
                Aluno* a = retirar(&fila);

                // se servidor tá ocioso, pula o relógio pro L do aluno
                if (relogio < a->L) {
                    relogio = a->L;
                }

                // timeout: relógio passou do limite do aluno
                if (relogio > a->R) {
                    printf("[TIMEOUT] mat=%s | Desconectado da fila.\n",
                           a->mat);
                    free(a);
                    // NÃO avança relógio nem contador
                    continue;
                }

                if (vagas > 0) {
                    printf("[ALOCADO] mat=%s | score=%d | Processado no seg: %lld\n",
                           a->mat, a->score, relogio);
                    adicionar(&confirmados, a);
                    vagas--;
                } else {
                    printf("[LOTADO] mat=%s | score=%d | Processado no seg: %lld\n",
                           a->mat, a->score, relogio);
                    free(a);
                }

                relogio++;
                processados++;
            }

        } else if (strcmp(comando, "FIM") == 0) {
            printf("--- LISTA OFICIAL: %s ---\n", nome_disc);

            int pos = 1;
            Aluno* a;
            while ((a = retirar(&confirmados)) != NULL) {
                printf("%d. Matricula: %s\n", pos++, a->mat);
                free(a);
            }
            break;
        }
    }

    return 0;
}