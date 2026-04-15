#include <stdio.h>
#include <stdlib.h>

//Função para calcular a Media
float calcular_media(float *notas, int qt_alunos){
    float soma = 0;
    for(int i = 0; i < qt_alunos; i++){
        soma += notas[i];
    }
    return soma / qt_alunos;
}

//Função para a maior nota e seu respectivo aluno
void maior_nota_aluno(float *notas, int qt_alunos, float *nota, int *aluno){
    *nota = notas[0];
    *aluno = 1;
    for(int i = 0; i < qt_alunos; i++){
        if(notas[i] > *nota){
            *nota = notas[i];
            *aluno = i + 1;
        }
    }
}

//Função para a menor nota e seu respectivo aluno
void menor_nota_aluno(float *notas, int qt_alunos, float *nota, int *aluno){
    *nota = notas[0];
    *aluno = 1;
    for (int i = 0; i < qt_alunos; i++){
        if (notas[i] < *nota){
            *nota = notas[i];
            *aluno = i + 1;
        }
    }
}

//Função para alunos acima da media
int alunos_acima_media(float *notas, int qt_alunos, float media){
    int qt_alunos_acima_media = 0;
    for (int i = 0; i < qt_alunos; i++){
        if (notas[i] > media){
            qt_alunos_acima_media++;
        }
    }
    return qt_alunos_acima_media;
}

//Função para a mediana
float calcular_mediana(float *notas, int qt_alunos){
    
    //ordenar primeiro
    for(int i = 0; i < qt_alunos - 1; i++){
        for (int j = 0; j < qt_alunos - 1 - i; j++){
            if(notas[j] > notas[j + 1]){
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }

    //calcular mediana
    if(qt_alunos % 2 == 1){
        return notas[qt_alunos / 2];
    }
    else{
        return (notas[qt_alunos / 2] + notas[(qt_alunos / 2) - 1]) / 2;
    }
}

//Função para calcular a Moda
void calcular_moda(float *notas, int qt_alunos, float *m, int *possui_moda){
    int maior_frequencia = 0;
    float moda = 0;
    int qt_notas_moda = 0;

    for(int i = 0; i < qt_alunos; i++){
        int frequencia_controle = 0;
        for (int j = 0; j < qt_alunos; j++){
            if(notas[j] == notas[i]){
                frequencia_controle++;
            }
        }

        if (frequencia_controle > maior_frequencia){
            moda = notas[i];
            maior_frequencia = frequencia_controle;
            qt_notas_moda = 1;
        }
        else if (frequencia_controle == maior_frequencia && notas[i] != moda){
            qt_notas_moda++;
        }
    }

    if (qt_notas_moda > 1 || maior_frequencia == 1){
        *possui_moda = 0;
    }else{
        *possui_moda = 1;
        *m = moda;
    }
}

int main(){
    int qt_alunos;
    //quantidade de alunos iniciais
    int qt_alunos_iniciais;
    scanf("%d", &qt_alunos_iniciais);

    //alocando espaço para notas
    float *notas = malloc(qt_alunos_iniciais * sizeof(float));
    if (notas == NULL){ //verificação
        printf("Erro de alocação de notas");
        exit(1);
    }
    //recebendo notas inciais
    for (int i = 0; i < qt_alunos_iniciais; i++){
        scanf("%f", &notas[i]);
    }
    qt_alunos = qt_alunos_iniciais;

    //Media
    float media = calcular_media(notas, qt_alunos);
    //Maior Nota e aluno
    float maior_nota;
    int aluno_maior_nota;
    maior_nota_aluno(notas, qt_alunos, &maior_nota, &aluno_maior_nota);
    //Menor Nota e aluno
    float menor_nota;
    int aluno_menor_nota;
    menor_nota_aluno(notas, qt_alunos, &menor_nota, &aluno_menor_nota); 
    //Acima da Média
    int qt_alunos_acima_media = alunos_acima_media(notas, qt_alunos, media);
    //Mediana
    float *copia = malloc(qt_alunos * sizeof(float));
    for(int i = 0; i < qt_alunos; i++){
        copia[i] = notas[i];
    }
    float mediana = calcular_mediana(copia, qt_alunos);
    free(copia);
    //Moda
    float moda;
    int possui_moda;
    calcular_moda(notas, qt_alunos, &moda, &possui_moda);

    //RELATORIO INICIAL
    printf("Relatorio inicial\n");
    printf("Media: %.2f\n", media);
    printf("Maior nota: %.2f (aluno %d)\n", maior_nota, aluno_maior_nota);
    printf("Menor nota: %.2f (aluno %d)\n", menor_nota, aluno_menor_nota);
    printf("Acima da media: %d\n", qt_alunos_acima_media);
    printf("Mediana: %.2f\n", mediana);
    if (possui_moda == 0){
        printf("Moda: Nao ha moda unica\n");
    } else {
        printf("Moda: %.2f\n", moda);
    }

    //quantidade de alunos novos
    int qt_alunos_novos;
    scanf("%d", &qt_alunos_novos);

    //realocando o ponteiro para um espaço de memoria maior
    float *temp = realloc(notas, (qt_alunos_iniciais + qt_alunos_novos) * sizeof(float));
    if(temp == NULL){
        printf("Erro na alocação de temp");
        exit(1);
    }
    notas = temp; //atualizando o ponteiro de notas

    //recebendo as novas notas
    for (int i = qt_alunos_iniciais; i < qt_alunos_iniciais + qt_alunos_novos; i++){
        scanf("%f", &notas[i]);
    }
    qt_alunos = qt_alunos_iniciais + qt_alunos_novos;   

    //Media
    media = calcular_media(notas, qt_alunos);
    //Maior Nota e aluno
    maior_nota_aluno(notas, qt_alunos, &maior_nota, &aluno_maior_nota);
    //Menor Nota e aluno
    menor_nota_aluno(notas, qt_alunos, &menor_nota, &aluno_menor_nota); 
    //Acima da Média
    qt_alunos_acima_media = alunos_acima_media(notas, qt_alunos, media);
    //Mediana
    mediana = calcular_mediana(notas, qt_alunos);
    //Moda
    calcular_moda(notas, qt_alunos, &moda, &possui_moda);

    //RELATORIO INICIAL
    printf("\n");
    printf("Relatorio atualizado\n");
    printf("Media: %.2f\n", media);
    printf("Maior nota: %.2f (aluno %d)\n", maior_nota, aluno_maior_nota);
    printf("Menor nota: %.2f (aluno %d)\n", menor_nota, aluno_menor_nota);
    printf("Acima da media: %d\n", qt_alunos_acima_media);
    printf("Mediana: %.2f\n", mediana);
    if (possui_moda == 0){
        printf("Moda: Nao ha moda unica\n");
    } else {
        printf("Moda: %.2f\n", moda);
    }
}
