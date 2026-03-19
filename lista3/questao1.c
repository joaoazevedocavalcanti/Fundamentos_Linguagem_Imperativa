#include <stdio.h>

int main(){
    //entrada numero de casos
    int numero_casos;
    scanf("%d", &numero_casos);

    //laço para os casos
    for (int casos = 0; casos < numero_casos; casos++){
        //entrada tamanho array
        int tamanho_array;
        scanf("%d", &tamanho_array);

        int sequencia[tamanho_array]; //definindo o array

        //adicionando no vetor
        for (int i = 0; i < tamanho_array; i++){
            scanf("%d", &sequencia[i]);
        }
        
        //variaveis auxiliares da verificação
        int inicio_geral = 0;
        int tamanho_geral = 0;
        int inicio_atual = 0;
        int tamanho_atual = 0;

        //laço verificação da sequencia
        for (int i = 1; i < tamanho_array; i++){
            if (sequencia[i] < sequencia[i - 1]){
                tamanho_atual += 1;
            } else {
                if (tamanho_atual > tamanho_geral){
                    tamanho_geral = tamanho_atual;
                    inicio_geral = inicio_atual;
                }
                inicio_atual = i;
                tamanho_atual = 0;
            }
        }

        if (tamanho_atual > tamanho_geral){
            tamanho_geral = tamanho_atual;
            inicio_geral = inicio_atual;
        }

        //caso exista sequencia
        if (tamanho_geral > 0){
            tamanho_geral += 1; //aumentar para corrigir
            printf("%d\n", tamanho_geral);
            for (int i = inicio_geral; i < inicio_geral + tamanho_geral; i++){
                if (i == inicio_geral + tamanho_geral - 1){
                    printf("%d \n", sequencia[i]);
                } else {
                    printf("%d ", sequencia[i]);
                }
            }
        } 
        else { //caso não exista sequencia
            printf("%d\n", tamanho_geral);
        }
    }
    return 0;
}