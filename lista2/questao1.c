#include <stdio.h>

int main () {
    char letra;
    scanf("%c", &letra);
    int linhas = letra - 64;
    //laço para as linhas
    for (int l = 1; l <= linhas; l++){
        //laço para os pontos iniciais
        for (int p1 = l; p1 <= (linhas - 1); p1++){
            printf(".");
        }
        //laço para as letras inicias
        for (int le1 = 1; le1 <= l; le1++){
            char letra_inicial = le1 + 64;
            printf("%c", letra_inicial);
        }
        //laço para as letras finais 
        for (int le2 = l - 1; le2 >= 1; le2--){
            char letra_final = le2 + 64;
            printf("%c", letra_final);
        }
        //laço para os pontos finais
        for (int p2 = l; p2 <= linhas - 1; p2++){
            if (p2 == linhas - 1){
                printf(".\n");
            } else {
                printf(".");
            }
        }
    }
}