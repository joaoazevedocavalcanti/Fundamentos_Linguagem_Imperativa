#include <stdio.h>

//função para o movimento e contabilização das casas
void movimento(int qt, char comandos[qt], int X, int Y, int contagem[4][4]){
    //laço para o movimento com base nos comandos
    for (int caracter = 0; comandos[caracter] != '\0'; caracter++){
        if (comandos[caracter] == 'c'){
            Y--;
        }
        else if (comandos[caracter] == 'b'){
            Y++;
        }
        else if (comandos[caracter] == 'e'){
            X--;
        }
        else if (comandos[caracter] == 'd'){
            X++;
        }
        //matriz para contabilizar quantas vezes uma casa foi visitada
        contagem[Y][X]++;
    }

    //verificação d qual casa foi mais visitada
    int maior_valor = -1; 
    int X_mais_visitado = 0;
    int Y_mais_visitado = 0;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            //define a casa mais visitada
            if (contagem[i][j] > maior_valor){
                maior_valor = contagem[i][j];
                X_mais_visitado = j;
                Y_mais_visitado = i;
            }
        }
    }
    //print final
    printf("Coordenada X:%d, Y:%d", X_mais_visitado, Y_mais_visitado);
}

int main(){
    //declarando variaveis gerais
    char comandos[21]; //vetor dos comandos
    int X = 0; 
    int Y = 0;
    int contagem[4][4] = {0}; //matriz para representar a quantidade de vezes que uma casa foi visitada

    //laço para recebimento dos comandos
    for (int c = 0; c < 20; c++){
        if (c == 0){
           scanf("%c", &comandos[c]); 
        }
        else {
            scanf(" %c", &comandos[c]);
        }
    }

    //chamando a função
    movimento(20, comandos, X, Y, contagem);

    return 0;
}