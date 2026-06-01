#include <stdio.h>
#include <string.h>

char pilha[10000];
int topo = -1;

//funcao para ascresentar na pilha
void acrescentar(char blocos) {
    pilha[++topo] = blocos;
}

//funcao para retirar da pilha
char retirar() {
    return pilha[topo--];
}

//funcao para mesclar 
char mesclar(char blocos1, char blocos2) {
    if ((blocos1 == 'g' && blocos2 == 'b') || (blocos1 == 'b' && blocos2 == 'g')) return 'c';
    if ((blocos1 == 'r' && blocos2 == 'b') || (blocos1 == 'b' && blocos2 == 'r')) return 'm';
    if ((blocos1 == 'r' && blocos2 == 'g') || (blocos1 == 'g' && blocos2 == 'r')) return 'y';
    return 0; // sem fusão
}

//funcao para verificar a pilha
void verificacao() {
    int mudou = 1;
    while (mudou) {
        mudou = 0;

        // Verifica 3 iguais no topo
        if (topo >= 2 &&
            pilha[topo] == pilha[topo-1] &&
            pilha[topo] == pilha[topo-2]) {
            topo -= 3;
            mudou = 1;
            continue;
        }

        // Verifica fusão dos 2 do topo
        if (topo >= 1) {
            char f = mesclar(pilha[topo], pilha[topo-1]);
            if (f) {
                topo -= 2;
                acrescentar(f);
                mudou = 1;
                continue;
            }
        }
    }
}

// funcao para imprimir a pilha
void imprimir() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
    } else {
        for (int i = topo; i >= 0; i--) {
            printf("%c\n", pilha[i]);
        }
    }
    printf("\n");
}

int main() {
    char c;
    while (scanf(" %c", &c) == 1) {
        acrescentar(c);
        verificacao();
        imprimir();
    }
    printf("Thank You So Much For Playing My Game!\n");
    return 0;
}