#include <stdio.h>

void mudanca_parede(int altura, int largura, char parede[altura][largura], char parede_controle[altura][largura], int a, int l) {
    //verifica se é a gota
    if (parede[a][l] == 'o'){
        //condição de estar livre para descer
        if (parede[a + 1][l]  == '.'){
            parede_controle[a + 1][l] = 'o';
        }
        //condição de o de baixo ser uma parede
        else if (parede[a + 1][l] == '#'){
            if (l - 1 >= 0){ //se exista espaço 
                parede_controle[a][l - 1] = 'o';
            }
            if (l + 1 < largura){ //se existe espaço
                parede_controle[a][l + 1] = 'o'; 
            }
        }
    }
}

//printar a matriz
void printar_matriz(int altura, int largura, char parede[altura][largura]){
    for (int a = 0; a < altura; a++) {
        for (int l = 0; l < largura; l++){
            printf("%c", parede[a][l]);
        }
        printf("\n");
    }
}

int main(){
    int largura, altura;
    scanf("%d %d", &altura, &largura);

    char parede[altura][largura];
    char parede_controle[altura][largura];

    //entrada da matriz e armazenamento da pos inicial
    for (int a = 0; a < altura; a++){
            scanf("%s", parede[a]);
        }

    //laço geral para mundança
    int continuar = 1; //variavel para parar o while
    while (continuar){
        int diff = 0;

        //criação de uma matriz auxiliar
        for (int a = 0; a < altura; a++){
            for (int l = 0; l < largura; l++){
                parede_controle[a][l] = parede[a][l];
            }
        }

        //chamando a função da mudança
        for (int a = 0; a < altura; a++){
            for (int l = 0; l < largura; l++){
                mudanca_parede(altura, largura, parede, parede_controle, a, l);
            }
        }

        //verificando se ainda existem diferenças, ou seja, ainda tem coisa pra modificar
        for (int a = 0; a < altura; a++){
            for (int l = 0; l < largura; l++){
                if (parede_controle[a][l] != parede[a][l]){
                    diff++;
                }
            }
        }
        //caso não exista, parar o codigo
        if (diff == 0){
            continuar = 0;
        }
        //copiar a matriz copia para a matriz original 
        for (int a = 0; a < altura; a++){
            for (int l = 0; l < largura; l++){
                parede[a][l] = parede_controle[a][l];
            }
        }
    }

    printar_matriz(altura, largura, parede);

}