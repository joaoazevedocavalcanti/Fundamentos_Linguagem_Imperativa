#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    int periculosidade;
    char funcao[50];
} Cidade;

//Função para usar o qsort
int comparar(const void *a, const void *b) {
    Cidade *ca = (Cidade *)a;
    Cidade *cb = (Cidade *)b;
    if (cb->populacao != ca->populacao)
        return cb->populacao - ca->populacao;
    if (cb->periculosidade != ca->periculosidade)
        return cb->periculosidade - ca->periculosidade;
    return strcmp(ca->nome, cb->nome);
}

//Função para formatar os nomes
void formatar(char *str) {
    str[0] = toupper(str[0]);
    for (int i = 1; str[i] != '\0'; i++)
        str[i] = tolower(str[i]);
}

int main(){
    char mensagem[200];
    int qt_cidade = 1; //variavel para saber quantas cidades - usada no malloc e realloc
    int c_v = 0; //variavel para saber a posição da cidadae
    int exclamacao = 0; //se teve exclamação ou n
    int chave;

    Cidade *cidadela = malloc(qt_cidade * sizeof(Cidade));
    if (cidadela == NULL){
        free(cidadela);
        exit(1);
    }

    while (fgets(mensagem, 200, stdin)){
        int exclamacao_linha = 0;
        qt_cidade++;
        
        //reallocação para o tamanho da cidadela
        Cidade *temp = realloc(cidadela, qt_cidade * sizeof(Cidade));
        if (temp == NULL){
            free(temp);
            exit(1);
        }
        cidadela = temp;
        memset(&cidadela[c_v], 0, sizeof(Cidade));

        //verificação se tem exclamação
        if (strchr(mensagem, '!') != NULL) {
            exclamacao = 1;
            exclamacao_linha = 1;
        }

        //Nome da Cidade
        int qt_letras_nome = 0; //variavel para saber a posição da letra no nome
        for(int i = 0; mensagem[i] != '\0'; i++){
            //caso seja maiuscula
            if(mensagem[i] > 64 && mensagem[i] < 91){
                cidadela[c_v].nome[qt_letras_nome] = mensagem[i];
                qt_letras_nome++;
            }  
        }
        
        //População
        int qt_num_populacao = 0; //posição do numero da string - pra depois mudar para inteiro
        char pop[20];
        for(int i = 0; mensagem[i] != '\0'; i++){
            //pegar numeros 
            if(isdigit(mensagem[i])){
                pop[qt_num_populacao] = mensagem[i];
                qt_num_populacao++;
            }
        }
        pop[qt_num_populacao] = '\0'; 

        // Se tem exclamacao, os digitos são chave, se não, são população
        if (exclamacao_linha == 1)
            chave = atoi(pop) - 1;
        else
            cidadela[c_v].populacao = atoi(pop);

        //Periculosidade 
        for (int i = 0; mensagem[i] != '\0'; i++){
            if(mensagem[i] == '*'){
                cidadela[c_v].periculosidade++;
            }
        }

        //Função
        int qt_letras_funcao = 0; //posicao da letra na string da funcao
        for (int i = 0; mensagem[i] != '\0'; i++){
            if(mensagem[i] == ' ' && mensagem[i + 1] == ' '){
                cidadela[c_v].funcao[qt_letras_funcao] = mensagem[i + 2];
                qt_letras_funcao++;
            }
        }
        
        c_v++; //adicionando para variavel do slot
    }

    if (exclamacao == 0){
        printf("Gingrey ainda não foi achada, vamos esperar mais um pouco.");
    }
    else {
        //ordenar de forma decrescente
        qsort(cidadela, c_v, sizeof(Cidade), comparar);

        //formatando nome e funcao
        formatar(cidadela[chave].nome);
        formatar(cidadela[chave].funcao);

        //transformando periculosidade em *
        char peri_cidade[20];
        for(int i = 0; i < cidadela[chave].periculosidade; i++){
            peri_cidade[i] = '*';
            peri_cidade[i + 1] = '\0';
        }

        //print caso encontre a cidade
        printf("Gingrey foi encontrada em %s, uma cidadela com %d mil habitantes cuja função é %s e periculosidade %s.", cidadela[chave].nome, cidadela[chave].populacao, cidadela[chave].funcao, peri_cidade);
        
        //Prints finais
        if(cidadela[chave].populacao > 1000 && cidadela[chave].periculosidade > 3){
            printf(" Talvez seja melhor desistir...");
        }
        else{
            if(cidadela[chave].populacao > 1000){
                printf(" Um lugar denso, vai ser difícil achar ela.");
            }

            if(cidadela[chave].periculosidade > 3){
                printf(" Vai ser complicado entrar lá.");
            }
        }
    }

    //liberar memoria 
    free(cidadela);
    
    return 0;
}