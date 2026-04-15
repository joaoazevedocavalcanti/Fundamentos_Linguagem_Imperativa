#include <stdio.h>
#include <stdlib.h>

int main (){
    int tamanho_vetor = 1;
    int *lugares = malloc(tamanho_vetor * sizeof(int));

    int lugar_recebido;
    int qt_lugares = 0;
    while (scanf("%d", &lugar_recebido) != EOF){
        tamanho_vetor++;

        int *temp = realloc(lugares, tamanho_vetor * sizeof(int));
        if (temp == NULL){
            printf("Erro na alocação de temp");
            exit(1);
        }
        lugares = temp;

        *(lugares + qt_lugares) = lugar_recebido;
        qt_lugares++;
    }

    printf("Mais um bom dia de trabalho!\n");

    for (int j = 0; j < 2; j++){
        for (int i = 0; i < qt_lugares; i++){
            if(j == 0){
                if(*(lugares + i) % 2 == 1){
                    printf("%d\n", *(lugares + i));
                }
            }
            else{
                if(*(lugares + i) % 2 == 0){
                    printf("%d\n", *(lugares + i));
                }
            }
        }
    }
    printf("Vou visitar esses lugares de novo... algum dia.\n");
}