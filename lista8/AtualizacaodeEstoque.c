#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct produto
typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
} Produto;

//struct movimento
typedef struct {
    int codigo;
    char tipo;
    int quantidade;
} Movimento;

int main() {
    //abre os arquivos
    FILE *arquivoProdutos   = fopen("produtos.txt", "r");
    FILE *arquivoMovimentos = fopen("movimentos.txt", "r");

    //verifica se os arquivos foram abertos
    if (arquivoProdutos == NULL || arquivoMovimentos == NULL) {
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    //allocando o vetor de produtos
    int qtProdutos = 0;
    int capProdutos = 2;
    Produto *produtos = malloc(capProdutos * sizeof(Produto));

    //leitura dos produtos
    while (fscanf(arquivoProdutos, "%d %s %d %f", &produtos[qtProdutos].codigo, produtos[qtProdutos].nome, &produtos[qtProdutos].quantidade, &produtos[qtProdutos].preco) == 4) {
        qtProdutos++;

        //realloc
        if (qtProdutos == capProdutos) {
            capProdutos *= 2;
            Produto *temp = realloc(produtos, capProdutos * sizeof(Produto));
            if (temp == NULL) { 
                free(produtos); 
                return 1; 
            }
            produtos = temp;
        }
    }
    fclose(arquivoProdutos);

    //variaveis dos movimentos
    int movAplicados = 0;
    int saidasRecusadas = 0;
    int semCadastro = 0;

    //abre relatorio para escrita
    FILE *arquivoRelatorio = fopen("relatorio.txt", "w");

    //guarda inconsistencias para gravar depois
    char inconsistencias[100][100];
    int qtInconsistencias = 0;

    int cod; 
    char tipo; 
    int qtd;
    while (fscanf(arquivoMovimentos, "%d %c %d", &cod, &tipo, &qtd) == 3) {
        //procura o produto no vetor
        int achou = -1;
        for (int i = 0; i < qtProdutos; i++)
            if (produtos[i].codigo == cod) { 
                achou = i; 
                break; 
            }

        //produto não encontrado
        if (achou == -1) {
            semCadastro++;
            sprintf(inconsistencias[qtInconsistencias++], "%d %c %d PRODUTO_INEXISTENTE", cod, tipo, qtd);
            continue;
        }

        //entrada
        if (tipo == 'E') {
            produtos[achou].quantidade += qtd;
            movAplicados++;

        //saida
        } else if (tipo == 'S') {
            if (produtos[achou].quantidade >= qtd) {
                produtos[achou].quantidade -= qtd;
                movAplicados++;
            } else {
                saidasRecusadas++;
                sprintf(inconsistencias[qtInconsistencias++], "%d %c %d ESTOQUE_INSUFICIENTE", cod, tipo, qtd);
            }
        }
    }
    fclose(arquivoMovimentos);

    //estoque atualizado
    FILE *arquivoEstoque = fopen("estoque_atualizado.txt", "w");
    for (int i = 0; i < qtProdutos; i++){
        fprintf(arquivoEstoque, "%d %s %d %.2f\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }
    fclose(arquivoEstoque);

    //escreve relatorio
    fprintf(arquivoRelatorio, "PRODUTOS PROCESSADOS: %d\n", qtProdutos);
    fprintf(arquivoRelatorio, "MOVIMENTOS APLICADOS: %d\n", movAplicados);
    fprintf(arquivoRelatorio, "SAIDAS RECUSADAS: %d\n", saidasRecusadas);
    fprintf(arquivoRelatorio, "MOVIMENTOS SEM CADASTRO: %d\n", semCadastro);

    fprintf(arquivoRelatorio, "ESTOQUE BAIXO:\n");
    for (int i = 0; i < qtProdutos; i++)
        if (produtos[i].quantidade <= 5) {
            fprintf(arquivoRelatorio, "%d %s %d\n", produtos[i].codigo, produtos[i].nome, produtos[i].quantidade);
        }

    fprintf(arquivoRelatorio, "INCONSISTENCIAS:\n");
    for (int i = 0; i < qtInconsistencias; i++) {
        fprintf(arquivoRelatorio, "%s\n", inconsistencias[i]);
    }

    fclose(arquivoRelatorio);

    //libera memória
    free(produtos);
    return 0;
}
