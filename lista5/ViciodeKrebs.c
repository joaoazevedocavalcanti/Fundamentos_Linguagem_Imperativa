#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N; 
    scanf("%d", &N);

    //vetor de ponteiros
    char *strings_geral[N];
    int tamanhos[N];
    int tamanho_total = 0;
    int maior_tamanho = 0;

    //recebimento
    for (int i = 0; i < N; i++){
        //recebendo o caractere
        char string_temp[1000];
        scanf("%s", string_temp);
        
        int tamanho_string = strlen(string_temp);
        tamanhos[i] = tamanho_string;
        tamanho_total += tamanho_string;
        if (tamanho_string > maior_tamanho){
            maior_tamanho = tamanho_string;
        }

        strings_geral[i] = malloc((tamanho_string + 1) * sizeof(char));
        if (strings_geral[i] == NULL){
            printf("Erro de alocação string n° %d", i);
            exit(1);
        }

        strcpy(strings_geral[i], string_temp);
    }
    
    char *string_mesclada = malloc((tamanho_total + 1)* sizeof(char));

    int controle_caract = 0; //controle para a posição do caractere que vai ser mesclado
    int pos_mesc = 0; //controle para saber em qual posição o caractere vai ser adicionado
    while (controle_caract < maior_tamanho){
        //laço para percorrer e mesclar
        for (int i = 0; i < N; i++){
            //verificação da mesclagem
            if (controle_caract < tamanhos[i]){
                *(string_mesclada + pos_mesc) = strings_geral[i][controle_caract];
                pos_mesc++;
            }
        }
        controle_caract++;
    }
    
    //print da string mesclada 
    for (int i = 0; i < tamanho_total; i++){
        printf("%c", *(string_mesclada + i));
    }
    printf("\n");

    //Fusão
    char *string_fusionada = malloc((tamanho_total + 1) * sizeof(char));
    int qt_carac_fusao;
    int fusao = 1;
    //Laço geral
    while (fusao){
        qt_carac_fusao = 0; //reiniciando a quantidade de caracteres fusionados
        int tem_fusao = 0; //reiniciando a verificação se teve fusao

        //laço para percorrer o mesclado
        for(int i = 0; i < tamanho_total; i++){
            //adicionar a primeira fusão
            if (*(string_mesclada + i) == *(string_mesclada + (i + 1)) && tem_fusao == 0 && (i + 1) < tamanho_total){
                if (*(string_mesclada + i) == 'z'){
                    *(string_fusionada + qt_carac_fusao) = 'a';
                    qt_carac_fusao++; 
                    tem_fusao = 1; 
                    i++;    
                }
                else {
                    *(string_fusionada + qt_carac_fusao) = *(string_mesclada + i) + 1;
                    qt_carac_fusao++; 
                    tem_fusao = 1; 
                    i++;
                }
            }   
            //adicionar o restante
            else {
                *(string_fusionada + qt_carac_fusao) = *(string_mesclada + i);
                qt_carac_fusao++;
            }
        }

        //verificar se acabou
        if (qt_carac_fusao == tamanho_total){
            fusao = 0;
        }
        
        //ajustar o primeiro ponteiro
        string_mesclada = string_fusionada;

        //ajustar o tamanho
        tamanho_total = qt_carac_fusao;
    }

    //print do fusionado
    for (int i = 0; i < qt_carac_fusao; i++){
        printf("%c", *(string_fusionada + i));
    }
}