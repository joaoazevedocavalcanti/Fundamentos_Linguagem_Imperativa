#include <stdio.h>

//função para colocar os caracteres + e x
void organizar_praca(int linhas, int colunas, char praca[linhas][colunas]){
    //laço geral
    for (int l = 0; l < linhas; l++){
        for (int c = 0; c < colunas; c++){
            if (praca[l][c] == '-' || praca[l][c] == 'x'){
                //verificar para colocar um +
                if ((l - 1 >= 0 && praca[l - 1][c] == 'P') || (l + 1 < linhas && praca[l + 1][c] == 'P') || (c - 1 >= 0 && praca[l][c - 1] == 'P') || (c + 1 < colunas && praca[l][c + 1] == 'P')){
                    praca[l][c] = '+';
                }
                //verificar para colocar um x
                if ((l + 1 < linhas && c + 1 < colunas && praca[l + 1][c + 1] == 'P') || (l + 1 < linhas && c - 1 >= 0 && praca[l + 1][c - 1] == 'P')  || (l - 1 >= 0 && c + 1 < colunas && praca[l - 1][c + 1] == 'P')  || (l - 1 >= 0 && c - 1 >= 0 && praca[l - 1][c - 1] == 'P')){
                    praca[l][c] = 'x';
                }
            }
        }
    }
}

//função para printar
void imprimir_praca(int linhas, int colunas, char praca[linhas][colunas]){
        for (int l = 0; l < linhas; l++) {
            for (int c = 0; c < colunas; c++){
                printf("%c", praca[l][c]);
            }
        printf("\n");
    }
}


int main(){
    //recebimentos das dimensões    
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    //matriz da praça
    char praca[linhas][colunas];

    //recebendo a praça
    for (int l = 0; l < linhas; l++){
        scanf("%s", &praca[l]);
    }

    //chamando as funções
    organizar_praca(linhas, colunas, praca);
    imprimir_praca(linhas, colunas, praca);

    return 0;
}