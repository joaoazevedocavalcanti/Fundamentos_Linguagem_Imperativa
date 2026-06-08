#include <stdio.h>
#include <stdlib.h>

typedef struct Jogadores{
    struct Jogadores *esquerda;
    int valor;
    struct Jogadores *direita;    
} Jogadores;

Jogadores* inserir(Jogadores *raiz, int valor){
    // se a raiz for nula, cria um novo nó
    if (raiz == NULL){
        Jogadores *novo = (Jogadores*)malloc(sizeof(Jogadores));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }
    // valor menor, vai para a esquerda
    if (valor < raiz->valor){
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    // valor maior, vai para a direita
    if (valor > raiz->valor){
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

//visitidando de forma pré-ordem
void pre_ordem(Jogadores *raiz){
    if (raiz == NULL){
        return;
    }
    printf("%d ", raiz->valor); //printa o valor do jogador
    pre_ordem(raiz->esquerda); //vai para a esquerda
    pre_ordem(raiz->direita);  //vai para a direita
}

//visitando de forma em-ordem
void em_ordem(Jogadores *raiz){
    if (raiz == NULL){
        return;
    }
    em_ordem(raiz->esquerda); //vai para a esquerda
    printf("%d ", raiz->valor); //printa o valor do jogador
    em_ordem(raiz->direita);  //vai para a direita
}

//visitando de forma pós-ordem
void pos_ordem(Jogadores *raiz){
    if (raiz == NULL){
        return;
    }
    pos_ordem(raiz->esquerda); //vai para a esquerda
    pos_ordem(raiz->direita);  //vai para a direita
    printf("%d ", raiz->valor); //printa o valor do jogador
}

//contar a quantidade de nos
int contarNos (Jogadores *raiz){
    if (raiz == NULL){
        return 0;
    }
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

//contar as folhas
int contarFolhas (Jogadores *raiz){
    if (raiz == NULL){
        return 0;
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL){
        return 1;
    }
    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

//calcular a altura da arvore
int altura(Jogadores *raiz) {
    if (raiz == NULL) {
        return -1;
    }

    int altEsq = altura(raiz->esquerda);
    int altDir = altura(raiz->direita);

    // pega o maior dos dois e soma 1
    if (altEsq > altDir) { 
        return 1 + altEsq;
    }

    return 1 + altDir;
}

// encontrar o menor valor da árvore (mais à esquerda)
int menorValor(Jogadores *raiz) {
    if (raiz->esquerda == NULL){ 
    return raiz->valor;
    }
    return menorValor(raiz->esquerda);
}

// encontrar o maior valor da árvore (mais à direita)
int maiorValor(Jogadores *raiz) {
    if (raiz->direita == NULL){
        return raiz->valor;
    }
    return maiorValor(raiz->direita);
}

// liberar a memória da árvore
void liberarMemoria(Jogadores *raiz) {
    if (raiz == NULL){ 
        return;
    }
    liberarMemoria(raiz->esquerda);
    liberarMemoria(raiz->direita);
    free(raiz);
}

//Funçao principal
int main() {
    Jogadores *raiz = NULL;
    int valor;

    // lê os valores até encontrar -1
    while (scanf("%d", &valor) == 1 && valor != -1) {
        raiz = inserir(raiz, valor);
    }

    // árvore vazia
    if (raiz == NULL) {
        printf("ARVORE VAZIA\n");
        return 0;
    }

    // percursos
    printf("PREORDEM: ");
    pre_ordem(raiz);
    printf("\n");

    printf("EMORDEM: ");
    em_ordem(raiz);
    printf("\n");

    printf("POSORDEM: ");
    pos_ordem(raiz);
    printf("\n");

    // informações
    printf("NOS: %d\n",    contarNos(raiz));
    printf("FOLHAS: %d\n", contarFolhas(raiz));
    printf("ALTURA: %d\n", altura(raiz));
    printf("MENOR: %d\n",  menorValor(raiz));
    printf("MAIOR: %d\n",  maiorValor(raiz));

    liberarMemoria(raiz);
    return 0;
}