#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função para alocar a matriz
int** allocar_matriz(int linhas, int colunas){
    int **matriz = malloc(linhas * sizeof(int*));

    for(int i = 0; i < linhas; i++){
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

//Função para Printar
void imprimir_matriz(int **matriz, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j ++){
            if (j > 0){
                printf(" ");
            }
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

//Função para liberar memoria
void liberar_memo(int **matriz, int linhas){
    for (int i = 0; i < linhas; i++){
        free(matriz[i]);
    }
    free(matriz);
}

//Função para montar a matriz de camadas
int** declarando_camadas(int **camadas, int linhas, int colunas, int X, int Y){
    //declarando camadas 1
    camadas[X][Y] = 1;
    //direita e esquerda
    if (X - 1 >= 0)(camadas[X - 1][Y] = 1);
    if (X + 1 < colunas)(camadas[X + 1][Y] = 1);
    //cima e baixo
    if (Y - 1 >= 0)(camadas[X][Y - 1] = 1);
    if (Y + 1 < colunas)(camadas[X][Y + 1] = 1);

    //declarando camada dois
    for (int i = 0; i < linhas; i++){
        for (int j = 0;j < colunas; j++){
            if (camadas[i][j] == 1){ //caso seja 1
                //cima e baixo
                if (i - 1 >= 0 && camadas[i - 1][j] == 0)(camadas[i - 1][j] = 2);
                if (i + 1 < linhas && camadas[i + 1][j] == 0)(camadas[i + 1][j] = 2);
                //direita e esquerda
                if (j - 1 >= 0 && camadas[i][j - 1] == 0)(camadas[i][j - 1] = 2);
                if (j + 1 < colunas && camadas[i][j + 1] == 0)(camadas[i][j + 1] = 2);
                //diagonais
                //superior esquerdo
                if (i - 1 >= 0 && j - 1 >= 0 && camadas[i - 1][j - 1] == 0)(camadas[i - 1][j - 1] = 2);
                //inferior esquerdo
                if (i + 1 < linhas && j - 1 >= 0 && camadas[i + 1][j - 1] == 0)(camadas[i + 1][j - 1] = 2);
                //superior direito
                if (i - 1 >= 0 && j + 1 < colunas && camadas[i - 1][j + 1] == 0)(camadas[i - 1][j + 1] = 2);
                //inferior direito
                if (i + 1 < linhas && j + 1 < colunas && camadas[i + 1][j + 1] == 0)(camadas[i + 1][j + 1] = 2);

            }
        }
    }
    return camadas;
}

//Função para copiar 
int **copiar(int **matriz, int linhas, int colunas){
    int **nova = allocar_matriz(linhas, colunas);

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            nova[i][j] = matriz[i][j];
        }
    }
    return nova;
}

//Função para Explosão Arcana
int** Explosao_Arcana(int **matriz_modificada, int linhas, int colunas, int **camadas){
    int **copia = copiar(matriz_modificada, linhas, colunas);

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            //camada 1
            if (camadas[i][j] == 1 && copia[i][j] > 0)(matriz_modificada[i][j] -= 50);
            //camada 2
            if (camadas[i][j] == 2 && copia[i][j] > 0)(matriz_modificada[i][j] -= 25);            
        
            //caso seja negativo
            if (matriz_modificada[i][j] < 0)(matriz_modificada[i][j] = 0);
        }
    }

    liberar_memo(copia, linhas);

    printf("Estado do mapa após usar a Explosão Arcana:\n");
    imprimir_matriz(matriz_modificada, linhas, colunas);
   
    return matriz_modificada;
}

//Função para contar os vizinhos
int contar_vizinhos(int **matriz, int linhas, int colunas, int x, int y){
    int qt_vizinhos = 0;
    //esquerda e direita
    if (x - 1 >= 0 && matriz[x - 1][y] > 0)(qt_vizinhos++);
    if (x + 1 < colunas && matriz[x + 1][y] > 0)(qt_vizinhos++);

    //cima e baixo
    if (y - 1 >= 0 && matriz[x][y - 1] > 0)(qt_vizinhos++);
    if (y + 1 < linhas && matriz[x][y + 1] > 0)(qt_vizinhos++);
    
    //diagonais
    //superior esquerdo
    if (x - 1 >= 0 && y - 1 >= 0 && matriz[x - 1][y - 1] > 0)(qt_vizinhos++);
    //inferior esquerdo
    if (x - 1 >= 0 && y + 1 < linhas && matriz[x - 1][y + 1] > 0)(qt_vizinhos++);
    //superior direito
    if (x + 1 < colunas && y - 1 >= 0 && matriz[x + 1][y - 1] > 0)(qt_vizinhos++);
    //inferior direito
    if (x + 1 < colunas && y + 1 < linhas && matriz[x + 1][y + 1] > 0)(qt_vizinhos++);

    return qt_vizinhos;
}

//Funçao para Verificar se todos foram zerados
int todos_zerados(int **matriz_modificada, int linhas, int colunas, int **camadas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (camadas[i][j] != 0 && matriz_modificada[i][j] > 0){
                return 0;
            }
        }
    }
    return 1;
}

//Função para Nuvem Venenosa
int** Nuvem_Venenosa(int **matriz_modificada, int linhas, int colunas, int **camadas){
    int qt_vizinhos = 0;
    int reducao = 0;
    //print inicial da função
    printf("Estado do mapa, por turno, após usar a Nuvem Venenosa:\n");

    
    for (int turnos = 0; turnos < 3; turnos++){
        int **copia = copiar(matriz_modificada, linhas, colunas);
        for (int i = 0; i < linhas; i++){
            for (int j = 0; j < colunas; j++){
                //caso seja um dos atingidos
                if(camadas[i][j] != 0){
                    //quantidade de vizinhos
                    qt_vizinhos = contar_vizinhos(copia, linhas, colunas, i, j);
                    //reduzir
                    reducao = 5 + (8 * qt_vizinhos);
                    matriz_modificada[i][j] -= reducao;
                    //caso deixe algum valor negativo
                    if (matriz_modificada[i][j] < 0)(matriz_modificada[i][j] = 0);
                    
                }
            }
        }
        liberar_memo(copia, linhas);
        //print por turno
        imprimir_matriz(matriz_modificada, linhas, colunas);
        printf("\n");

        //caso todos os numeros sejam zerados
        if (todos_zerados(matriz_modificada, linhas, colunas, camadas)){
            return matriz_modificada;
            break;
        }
    }
    return matriz_modificada;
}

int main(){
    //Recebendo linhas e colunas
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    //Recebendo a matriz principal
    int **matriz = allocar_matriz(linhas, colunas);
    ler_matriz(matriz, linhas, colunas);

    //Recebendo as coordenadas do ponto central
    int X_Ataque, Y_Ataque;
    scanf("%d %d", &X_Ataque, &Y_Ataque);

    //Recebendo o tipo do tipo_ataque
    char tipo_ataque[20];
    scanf("%s", tipo_ataque);

    //motando a matriz das camadas
    int **camadas = allocar_matriz(linhas, colunas);
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            camadas[i][j] = 0;
        }
    }
    camadas = declarando_camadas(camadas, linhas, colunas, X_Ataque, Y_Ataque);

    //fazer a copia principal
    int **matriz_modificada = copiar(matriz, linhas, colunas);

    //Print inicial
    printf("Estado inicial do mapa:\n");
    imprimir_matriz(matriz_modificada, linhas, colunas);
    printf("\n");

    //Ponteiro para Função
    int** (*operacao)(int**, int, int, int**);

    //Caso seja o Explosao Arcana
    if (strcmp(tipo_ataque, "EXPLOSAO_ARCANA") == 0){
        operacao = Explosao_Arcana;
    }

    //Caso seja a Nuvem Venenosa
    if (strcmp(tipo_ataque, "NUVEM_VENENOSA") == 0){
       operacao = Nuvem_Venenosa;
    }

    //Aplicando a operação
    matriz_modificada = operacao(matriz_modificada, linhas, colunas, camadas);

    //Liberando a memoria
    liberar_memo(matriz_modificada, linhas);
    liberar_memo(matriz, linhas);
    
    return 0;

}