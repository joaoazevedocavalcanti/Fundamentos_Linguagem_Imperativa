#include <stdio.h>
#include <stdlib.h>

//alocar na memoria
int** allocacao(int linhas, int colunas){
    int** matriz = malloc(linhas * sizeof(int*));

    for (int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(int));
    }

    return matriz;
}

//ler a matriz
void ler_matriz(int** matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

//imprimir a matriz 
void imprimir(int **matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (j > 0){
                printf(" ");
            }
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

//liberar memoria 
void liberar_memo(int **matriz, int linhas){
    for (int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

//função para aplicar as operações
void aplicar_op(int **matriz, int linhas, int colunas, int (*op)(int)){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matriz[i][j] = op(matriz[i][j]);
        }
    }
}

//dobrar valor
int dobrar(int x){
    return x * 2;
}
//fazer o quadrado do valor
int quadrado(int x){
    return x * x;
}
//valor absoluto
int valor_absoluto(int x){
    if (x < 0){
        return -x;
    }
    else {
        return x;
    }
}

int main(){
    int linhas, colunas, operacao_escolhida;

    scanf("%d %d", &linhas, &colunas);

    int **matriz = allocacao(linhas, colunas);
    ler_matriz(matriz, linhas, colunas);

    scanf("%d", &operacao_escolhida);

    int (*operacoes[3])(int) = {dobrar, quadrado, valor_absoluto};

    aplicar_op(matriz, linhas, colunas, operacoes[operacao_escolhida - 1]);

    imprimir(matriz, linhas, colunas);

    liberar_memo(matriz, linhas);

    return 0;

}