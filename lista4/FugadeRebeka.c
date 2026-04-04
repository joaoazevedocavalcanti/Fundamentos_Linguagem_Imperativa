#include <stdio.h>

int percorrendo(int linha_rebeka, int coluna_rebeka, int linhas, int colunas, char labirinto[linhas][colunas], int labirinto_visitado[linhas][colunas], int mov_linhas[4], int mov_colunas[4], int qt_movimentos[1]){
    //caso saia dos limites da matriz
    if ((linha_rebeka < 0 || linha_rebeka >= linhas) || (coluna_rebeka < 0 || coluna_rebeka >= colunas)){
        return 0;
    }
    //caso ja tenha passado pelo lugar
    if (labirinto_visitado[linha_rebeka][coluna_rebeka]) {
        return 0;
    }
    //caso encontre uma parede
    if (labirinto[linha_rebeka][coluna_rebeka] == '#'){
        return 0;
    }
    //caso encontre a saida
    if (labirinto[linha_rebeka][coluna_rebeka] == 'd'){
        return 1;
    }
    //contabilizar os lugares visitados
    labirinto_visitado[linha_rebeka][coluna_rebeka] = 1;

    //fazer a recursão para percorrer o labirinto
    for (int mov = 0; mov < 4; mov++){
        if (percorrendo(linha_rebeka + mov_linhas[mov], coluna_rebeka + mov_colunas[mov], linhas, colunas, labirinto, labirinto_visitado, mov_linhas, mov_colunas, qt_movimentos)) {
            qt_movimentos[0]+=1;
            return 1;
        }
    }

    //organizar o caminho
    qt_movimentos[0]-=1;
    labirinto_visitado[linha_rebeka][coluna_rebeka] = 0;
    return 0;
}


int main(){
    //receber as variaveis de tamanho do labirinto
    int linhas, colunas;
    scanf("%dx%d", &linhas, &colunas);

    //declarando as variaveis para definir a posição da rebeka
    int linha_rebeka, coluna_rebeka;

    //declarando a matriz do labirinto
    char labirinto[linhas][colunas];
    int labirinto_visitado[linhas][colunas];
    for (int l = 0; l < linhas; l++){
        scanf("%s", labirinto[l]);
        //colcando valor nas variaveis de inicio
        for (int c = 0; c < colunas; c++){
            if (labirinto[l][c] == 'o'){
                linha_rebeka = l;
                coluna_rebeka = c;
            }
            labirinto_visitado[l][c] = 0;
        }    
    }   

    //matrizes de movimentação
    int mov_linhas[] = {1, -1, 0, 0};
    int mov_colunas[] = {0, 0, 1, -1};

    //qt_movimentos
    int qt_movimentos[1] = {0}; //usei um vetor pra conseguir alterar o valor dele dentro da função

    //impressao caso dê certo ou errado
    if (percorrendo(linha_rebeka, coluna_rebeka, linhas, colunas, labirinto, labirinto_visitado, mov_linhas, mov_colunas, qt_movimentos)) {
        printf("Apos correr %d metros e quase desistir por causa da distância, Rebeka conseguiu escapar!\n", qt_movimentos[0]);
    } else {
        printf("Poxa... Parece que nao foi dessa vez que Rebeka conseguiu fugir\n");
    }

    return 0;
}