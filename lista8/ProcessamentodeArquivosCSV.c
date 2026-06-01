#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrute das informações das flores
typedef struct {
    float sepal_length;
    float sepal_width;
    float petal_length;
    float petal_width;
    char species[50];
} Iris;

//funcao para moda
void calcularModa(Iris *dados, int n, char *moda) {
    char especies[3][50] = {"Iris-setosa", "Iris-versicolor", "Iris-virginica"};
    int contagem[3] = {0, 0, 0};

    //compara as strings
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            if (strcmp(dados[i].species, especies[j]) == 0)
                contagem[j]++;

    //coloca a com maior moda na variavel moda
    int max = 0;
    for (int j = 0; j < 3; j++)
        if (contagem[j] > max) {
            max = contagem[j];
            strcpy(moda, especies[j]);
        }
}

int main() {
    int qtArquivos;
    scanf("%d", &qtArquivos);

    for (int i = 1; i < qtArquivos; i++){
        //gera o nome do arquivo
        char nomeArquivo[20];
        sprintf(nomeArquivo, "iris%d.csv", i);

        //abre o arquivo
        FILE *fp = fopen(nomeArquivo, "a+");
        if (fp == NULL) {
            printf("Erro ao abrir arquivo.\n");
            return 1;
        }

        //alocando vetor
        int quantidade = 0, capacidade = 2;
        Iris *dados = malloc(capacidade * sizeof(Iris));

        //ignora o cabeçalho
        char linha[256];
        fgets(linha, sizeof(linha), fp);

        //le s dados
        while (fgets(linha, sizeof(linha), fp)) {
            //realloc
            if (quantidade == capacidade) {
                capacidade *= 2;
                Iris *temp = realloc(dados, capacidade * sizeof(Iris));
                if (temp == NULL) { 
                    free(dados); 
                    fclose(fp); 
                    return 1; 
                }
                dados = temp;
            }
            //pegando os dados
            sscanf(linha, "%f,%f,%f,%f,%s",
                &dados[quantidade].sepal_length,
                &dados[quantidade].sepal_width,
                &dados[quantidade].petal_length,
                &dados[quantidade].petal_width,
                dados[quantidade].species);
            quantidade++;
        }
         //calcula medias
        float mediasl=0, mediaw=0, mediapl=0, mediapw=0;
        for (int j = 0; j < quantidade; j++) {
            mediasl += dados[j].sepal_length;
            mediaw += dados[j].sepal_width;
            mediapl += dados[j].petal_length;
            mediapw += dados[j].petal_width;
        }
        mediasl /= quantidade; mediaw /= quantidade;
        mediapl /= quantidade; mediapw /= quantidade;

        //calcula moda
        char moda[50];
        calcularModa(dados, quantidade, moda);

         //muda o final do arquivo
        fprintf(fp, "\n--- Resultados ---\n");
        fprintf(fp, "Media sepal_length: %.2f\n", mediasl);
        fprintf(fp, "Media sepal_width: %.2f\n", mediaw);
        fprintf(fp, "Media petal_length: %.2f\n", mediapl);
        fprintf(fp, "Media petal_width: %.2f\n", mediapw);
        fprintf(fp, "Especie predominante: %s\n", moda);

        //mostra no terminal
        printf("\n=== Arquivo: %s ===\n", nomeArquivo);
        //volta ao início para imprimir tudo
        rewind(fp); 
        while (fgets(linha, sizeof(linha), fp))
            printf("%s", linha);

        //libera e fecha
        free(dados);
        fclose(fp);
    }
    return 0;
}

