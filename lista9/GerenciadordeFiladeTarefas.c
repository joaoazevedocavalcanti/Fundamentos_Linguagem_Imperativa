#include <stdio.h>
#include <stdlib.h>

// cada tarefa é um nó da lista
typedef struct Tarefa {
    int id;
    int prioridade;
    struct Tarefa* prox;
} Tarefa;

// a fila tem um ponteiro pro início e um pro fim
Tarefa* inicio = NULL;
Tarefa* fim = NULL;

// insere no FINAL da fila
void inserir(int id, int prioridade) {
    Tarefa* nova_tarefa = malloc(sizeof(Tarefa));
    nova_tarefa->id = id;
    nova_tarefa->prioridade = prioridade;
    nova_tarefa->prox = NULL;

    if (fim == NULL) {
        // fila tava vazia
        inicio = nova_tarefa;
        fim = nova_tarefa;
    } else {
        // liga o último nó na nova tarefa
        fim->prox = nova_tarefa;
        fim = nova_tarefa;
    }
}

// remove do INÍCIO da fila
void remover() {
    if (inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }

    Tarefa* tarefa_removida = inicio;
    printf("Removida: id=%d prioridade=%d\n",
           tarefa_removida->id,
           tarefa_removida->prioridade);

    inicio = inicio->prox;

    // se a fila ficou vazia, fim também vira NULL
    if (inicio == NULL) {
        fim = NULL;
    }

    free(tarefa_removida);
}

// lista todas as tarefas do início ao fim
void listar() {
    if (inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }

    Tarefa* atual = inicio;
    while (atual != NULL) {
        printf("id=%d prioridade=%d\n", atual->id, atual->prioridade);
        atual = atual->prox;
    }
}

int main() {
    char comando;
    int id, prioridade;

    while (scanf(" %c", &comando) == 1) {
        if (comando == 'I') {
            scanf("%d %d", &id, &prioridade);
            inserir(id, prioridade);

        } else if (comando == 'R') {
            remover();

        } else if (comando == 'L') {
            listar();

        } else if (comando == 'F') {
            break;
        }
    }

    return 0;
}