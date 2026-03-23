#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
    char string_inicial[101];
    fgets(string_inicial, 101, stdin);

    //contar quantas palavras tem
    int qt_palavras = 1;
    for (int i = 0; string_inicial[i] != '\0'; i++){
        if (string_inicial[i] == ' ' || string_inicial[i] < 'A' && string_inicial[i + 1] > 'A'){
            qt_palavras++;
        }
    }

    //encontrar o inicio de cada palavra
    int inicio_palavra[qt_palavras];
    inicio_palavra[0] = 0;
    int contador_inicio = 1;
    for (int i = 0; string_inicial[i] != '\0'; i++){
        if (string_inicial[i] == ' ' || string_inicial[i] < 'A' && string_inicial[i + 1] > 'A'){
            inicio_palavra[contador_inicio] = i + 1;
            contador_inicio++;
        }
    } 

    //tamanho de cada palavra
    int tamanho_palavras[qt_palavras];
    for (int i = 0; i < qt_palavras; i++){
        if (i == qt_palavras - 1){
            tamanho_palavras[i] = strlen(string_inicial) - inicio_palavra[i];
        } else {
            tamanho_palavras[i] = inicio_palavra[i+1] - inicio_palavra[i] - 1;
        }
    }

    //verificação dos anagramas
    int qt_pares = 0;
    int n_printado = 1;
    for (int contador_geral = 0; contador_geral < qt_palavras - 1; contador_geral++){
        int vetor1[26] = {0}; //vetor para controle das letras de uma das palavras

        for (int i = inicio_palavra[contador_geral]; string_inicial[i] != ' ' && string_inicial[i] >= 'A'; i++){
            char letra_analisada1 = tolower(string_inicial[i]); //variavel de controle
            //sinais de pontuação
            if (isalpha(letra_analisada1) == 0){
                continue;
            }
            vetor1[letra_analisada1 - 97] += 1;
        }
            //analisar segunda palavra
            for (int contador_palavra2 = contador_geral + 1; contador_palavra2 < qt_palavras; contador_palavra2++){
                int vetor2[26] = {0};
                for (int j = inicio_palavra[contador_palavra2]; string_inicial[j] != ' ' && string_inicial[j] != '\0' && string_inicial[j] >= 'A'; j++){
                    char letra_analisada2 = tolower(string_inicial[j]);
                    //sinais de pontuação
                    if (isalpha(letra_analisada2) == 0){
                        continue;
                    }
                    vetor2[letra_analisada2 - 97] += 1;
                }

                //verificação das igualdades
                int pares_iguais = 1;
                for (int n = 0; n < 26; n++){
                    if (vetor1[n] != vetor2[n]){
                        pares_iguais = 0;
                        break;
                    }
                }

                //caso existam pares
                if (pares_iguais){
                    qt_pares++;
                    if (n_printado){
                        printf("Pares de anagramas encontrados:\n");
                        n_printado = 0;
                    }
                    //primeira palavra
                    for (int l = inicio_palavra[contador_geral]; l < inicio_palavra[contador_geral] + tamanho_palavras[contador_geral]; l++){
                       //sinais de pontuação
                        if (isalpha(string_inicial[l]) == 0){
                            continue;
                        } 
                        printf("%c", string_inicial[l]);
                    }
                    //print do e
                    printf(" e ");
                    //segunda palavra
                    for (int l2 = inicio_palavra[contador_palavra2]; l2 < inicio_palavra[contador_palavra2] + tamanho_palavras[contador_palavra2]; l2++){
                       //sinais de pontuação
                        if (isalpha(string_inicial[l2]) == 0){
                            continue;
                        } 
                        printf("%c", string_inicial[l2]);
                    }
                    //print de pular linha 
                    printf("\n");
                }   
            }
    }
    //caso não exista pares
    if (n_printado){
        printf("Nao existem anagramas na frase.");
    } 
    //caso exista (printar a quantidade)
    else {
        printf("\n");
        printf("Total de pares: %d", qt_pares);
    }
    return 0;
}
