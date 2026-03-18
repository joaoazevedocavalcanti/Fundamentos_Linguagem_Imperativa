#include <stdio.h>

int main() {
    int linha_entrada = 0;
    int coluna_entrada = 0;
    char ultimo_mov = 'A';

    int qt_mov, coluna_saida;

    scanf("%d", &qt_mov);
    //la�o geral
    for (int movimentos = qt_mov; movimentos > 0; movimentos--){
        //variaveis
        int qt_passos;
        char direcao;

        scanf("%d %c", &qt_passos, &direcao);

        //DIREITA
        if (direcao == 'D'){
            //print dos espacos
            if (coluna_entrada > 0){
                for (int espacos = 1; espacos < coluna_entrada; espacos++){
                    printf(" ");
                }
            }
            //caso ultimo mov seja para baixo
            if (ultimo_mov == 'B'){
                printf(".");
            }
            //print dos pontos
            for (int ponto = 0; ponto < qt_passos; ponto++){
                printf(".");
            }
            
            //atualizacao da coluna
            coluna_saida = coluna_entrada + qt_passos;
            coluna_entrada += coluna_saida;
        }
        
        //ESQUERDA
        else if (direcao == 'E'){
            //CASO SEJA VALIDO
            if (coluna_entrada - qt_passos >= 0){
                coluna_saida = coluna_entrada - qt_passos;
                
                //caso o ultimo movimento seja para direita
                if (ultimo_mov == 'D'){
                    if (coluna_saida >= coluna_entrada){
                        coluna_entrada = coluna_saida;
                    } else {
                        //print espaços
                        if (coluna_entrada > 0){
                            for (int espacos = 1; espacos < coluna_saida; espacos++){
                                printf(" ");
                            }
                        }
                        //print pontos
                        for (int pontos = 0; pontos <= coluna_saida - coluna_entrada; pontos++){
                            printf(".");
                        }
                    }
                } else {
                    //print espaços
                    if (coluna_entrada > 0){
                        for (int espacos = 1; espacos < coluna_saida; espacos++){
                            printf(" ");
                        }
                    }
                    //print pontos
                    for (int pontos = 0; pontos <= qt_passos; pontos++){
                        printf(".");
                    }
                }
            //caso o movimento n�o possa acontecer
            } else {
                printf("Informacao invalida");
                break;
            }
            
            //atualizacao da coluna
            coluna_entrada = coluna_saida;
        }

        //BAIXO
        else if(direcao == 'B'){
            printf("\n");
            //caso seja o ultimo
            if (movimentos == 1){
                qt_passos += 1;
            }
            for (int linha = 1; linha < qt_passos; linha++){
                //print dos espacos
                if (coluna_entrada > 0){
                    for (int espacos = 1; espacos < coluna_saida; espacos++){
                        printf(" ");
                    }
                }
                printf(".\n"); 
            }
            //atualizacao da linha
            linha_entrada += qt_passos;
        }
    //guardando a informacao do ultimo movimento
    ultimo_mov = direcao;

    }
    return 0;

}