#include <stdio.h>
#include <stdlib.h>

//Função para Allocação
int** allocacao(int linhas, int colunas){
    int** matriz = malloc(linhas * sizeof(int*));

    for (int i = 0; i < linhas; i++){
        matriz[i] = malloc(colunas * sizeof(int));
    }

    return matriz;
}

//Função para ler a matriz 
void ler_matriz(int **matriz, int linhas, int colunas){
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

//Função para calibração
int calibracao(int x){
    return x + 5;
}

//Função para saturação
int saturacao(int x){
    if (x > 80){
        return 80;
    } else {
        return x;
    }
}

//Função para amplificar
int amplificador(int x){
    return x * 2;
}

//Função para aplicar
void modificar(int **matriz, int linhas, int colunas, int (*op)(int)){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matriz[i][j] = op(matriz[i][j]);
        }
    }
}

//Função para pegar o maior valor 
void maior_valor(int **matriz, int linhas, int colunas, int *x, int *y, int *valor){
    int m_valor = 0;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (matriz[i][j] > m_valor){
                m_valor = matriz[i][j];
                *x = i;
                *y = j;
            }
        }
    }
    *valor = m_valor;
}


int main(){
    //linahs e colunas
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    //matriz principal
    int **matriz = allocacao(linhas, colunas);
    ler_matriz(matriz, linhas, colunas);

    //Ponteiro para função
    int (*filtros[3])(int) = {calibracao, saturacao, amplificador};

    //laço principal
    int comando;
    while (scanf("%d", &comando) && comando != 0 ){
        //caso seja o pipeline
        if (comando == 4){
            int k;
            scanf("%d", &k);
            for (int i = 0; i < k; i++){
                scanf("%d", &comando);
                //função modificar
                modificar(matriz, linhas, colunas, filtros[comando - 1]);
            }
        }
        //caso não seja 
        else {
            //função modificar
            modificar(matriz, linhas, colunas, filtros[comando - 1]);
        }
    }

    //print da matriz processada
    printf("Matriz processada:\n");
    imprimir(matriz, linhas, colunas);
    printf("\n");

    //pegando e printando o maior valor
    int x_maior;
    int y_maior;
    int sensor_critico; 
    maior_valor(matriz, linhas, colunas, &x_maior, &y_maior, &sensor_critico);
    printf("Sensor critico: %d\n", sensor_critico);
    printf("Posicao: (%d,%d)\n", x_maior, y_maior);

    //liberar a memoria
    liberar_memo(matriz, linhas);

    return 0;
}