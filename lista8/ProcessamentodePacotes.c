#include <stdio.h>
#include <stdlib.h>

union PropriedadePacotes {
    unsigned int DadoBruto;
    struct {
        unsigned int id_Sensor : 10;
        unsigned int cod_Status : 3;
        unsigned int bateria_Baixa : 1;
        signed int temperatura : 12;
        unsigned int controle : 6;
    } informacoes;
};

int main(){
    //allocando a memoria
    union PropriedadePacotes *pacotes = malloc(1 * sizeof(union PropriedadePacotes));

    //variaveis
    unsigned int entrada;
    int quantidade = 0;
    int capacidade = 1;
    
    //recebendo a entrada (pacote)
    scanf("%x", &entrada);
    while (entrada != 0){
        //atribuindo os valores 
        pacotes[quantidade].DadoBruto = entrada;

        //printar 
        printf("Exemplo de Saída:\n");
        printf("Pacote [%d] - Dado Bruto: %x\n", quantidade + 1, pacotes[quantidade].DadoBruto);
        printf("ID do Sensor : %u\n", pacotes[quantidade].informacoes.id_Sensor);
        printf("Status : %u\n", pacotes[quantidade].informacoes.cod_Status);
        printf("Bateria Baixa : %s\n", pacotes[quantidade].informacoes.bateria_Baixa == 0 ? "Não" : "SIM (ALERTA)");
        printf("Temperatura : %d\n", pacotes[quantidade].informacoes.temperatura);

        //verificando o realloc
        quantidade++;
        if (quantidade == capacidade){
            //dobrando a capacidade
            capacidade *= 2;

            //reallocando
            union PropriedadePacotes *temp = realloc(pacotes, capacidade * sizeof(union PropriedadePacotes));

            //verificando allocação
            if(temp == NULL){
                free(pacotes);
                exit(1);
            }
            
            //igualando
            pacotes = temp;
            
            //recebendo a nova
            scanf("%x", &entrada);
        }
    } 

    //liberando memoria 
    free(pacotes);

    return 0;
}