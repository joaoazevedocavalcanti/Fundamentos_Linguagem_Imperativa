#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Mecha Mecha;

typedef struct {
    char nome[30];
    int atrib1;     // Atk: Dano Base   | Def: Blindagem Fixa | Utl: Recup. Base
    int atrib2;     // Atk: Custo Ener. | Def: Bônus de Slot   | Utl: Multiplicador
    
    // Função Modular: deve ser atribuída conforme o tipo do sistema.
    // m: ponteiro para o mecha dono do sistema.
    // slot: o índice da posição de entrada deste sistema no array sistemas[]
    // input: o dano base enviado pelo Wintermute para o combate.
    // output: onde deve ser gravado o resultado final da operação.
    void (*subrotina)(Mecha *m, int slot, int input, int *output);
} SubSistema;

struct Mecha {
    int id;                // Identificador único (0 até N-1)
    char modelo[50];
    int energia_atual;
    int num_sistemas;
    int valor_wintermute;       // Contexto de dano enviado pelo Comando
    SubSistema sistemas[]; // O Flexible Array Member (FAM)
};

//Funções 
//Defesa
void defesa(Mecha *m, int slot, int input, int *output){
    int dano_final = input - m->sistemas[slot].atrib1 - (slot * m->sistemas[slot].atrib2);
    if (dano_final < 0){
        dano_final = 0;
    }
    *output = dano_final;
}

//utilidade
void utilidade(Mecha *m, int slot, int input, int *output){
    int recuperado = m->sistemas[slot].atrib1 + (slot * m->sistemas[slot].atrib2);
    m->energia_atual += recuperado;
    *output = m->energia_atual;
}

//ataque
void ataque(Mecha *m, int slot, int input, int *output){
    if(m->energia_atual < m->sistemas[slot].atrib2){
        *output = 0;
    }
    else{
        int dano = m->sistemas[slot].atrib1 + m->energia_atual + slot - input;
        m->energia_atual -= m->sistemas[slot].atrib2;
        *output = dano;
    }
}

//liberar memoria
void liberar_memoria(int **m, int linhas){
    for (int j = 0; j < linhas; j++){
        free(m[j]);
    }
    free(m);
}

//simulação geral
void simulacao_geral(Mecha *m){

    int resultado;
    int input = m->valor_wintermute;

    //print inicial de relatorio
    printf("ID: %d | MECHA: %s | ENERGIA: %d\n", m->id, m->modelo, m->energia_atual);
    //defesa
    for (int i = 0; i < m->num_sistemas; i++){
        if (m->sistemas[i].subrotina == defesa){
            m->sistemas[i].subrotina(m, i, input, &resultado);
            printf("-> [DEFESA] %s | Dano final sofrido: %d\n", m->sistemas[i].nome, resultado);
        }
    }

    //utilidade
    for (int i = 0; i < m->num_sistemas; i++){
        if (m->sistemas[i].subrotina == utilidade){
            m->sistemas[i].subrotina(m, i, input, &resultado);
            printf("-> [UTILIDADE] %s | Energia atual: %d\n", m->sistemas[i].nome, resultado);
        }
    }

    //ataque 
    for (int i = 0; i < m->num_sistemas; i++){
         if (m->sistemas[i].subrotina == ataque){
            m->sistemas[i].subrotina(m, i, input, &resultado);  
            if (resultado == 0) {
                printf("-> [ATAQUE] %s | Energia insuficiente!\n", m->sistemas[i].nome);
            }
            else{
                printf("-> [ATAQUE] %s | Dano causado: %d | Energia restante: %d\n", m->sistemas[i].nome, resultado, m->energia_atual);
            }
        }
    }

    //print final a cada no
    printf("ENERGIA FINAL: %d\n", m->energia_atual);
    printf("-----------------------------------------\n");
}

int main(){
    int num_mechas;
    scanf("%d", &num_mechas);

    //allocação do conjunto de mechas
    Mecha **esquadrao = malloc(num_mechas * sizeof(Mecha *));

    int maior_id = 0;
    for (int i = 0; i < num_mechas; i++){
        int id, energia_atual, num_sistema;
        char modelo[50];
        scanf("%d %s %d %d", &id, modelo, &energia_atual, &num_sistema);

        //analisar o maior uid para simulação futura
        if (id > maior_id){
            maior_id = id;
        }

        //allocando memoria para os mechas e seus respectivos subsistemas
        esquadrao[i] = malloc(sizeof(Mecha) + num_sistema * sizeof(SubSistema));
        
        //verificando e liberrando memoria se necessario
        if (esquadrao[i] == NULL){
            liberar_memoria(esquadrao, i);
            exit(1);
        }


        //declarando os atributos
        esquadrao[i]->id = id;
        strcpy(esquadrao[i]->modelo, modelo);
        esquadrao[i]->energia_atual = energia_atual;
        esquadrao[i]->num_sistemas = num_sistema;

        //recebendo atributos de sistema
        for (int s = 0; s < num_sistema; s++){
            char tipo;
            scanf(" %c %s %d %d", &tipo, esquadrao[i]->sistemas[s].nome, &esquadrao[i]->sistemas[s].atrib1, &esquadrao[i]->sistemas[s].atrib2);
        
            //fazer a verificação da função de cada sistema
            if (tipo == 'D'){
                esquadrao[i]->sistemas[s].subrotina = defesa;
            }
            if (tipo == 'U'){
                esquadrao[i]->sistemas[s].subrotina = utilidade;
            }
            if (tipo == 'A'){
                esquadrao[i]->sistemas[s].subrotina = ataque;
            }
        }
        //receber sinal micelio
        int valor_wintermute;
        scanf("%d", &valor_wintermute);
        esquadrao[i]->valor_wintermute = valor_wintermute;
    }

    //print inicial da simulação
    printf("[RELATORIO DE MISSÃO: OPERAÇÃO LANÇA DE NETUNO]\n");

    //logica para simular os mecha em ordem de uid 
    for (int i = 0; i <= maior_id; i++){ //percorrer de 0, até o maior id
        for(int m = 0; m < num_mechas; m++){ //percorrer a quantidade de mechas
            if (esquadrao[m]->id == i){ //pegar os id em ordem crescente
                simulacao_geral(esquadrao[m]);
            }
        }
    }
    //print final
    printf("Esquadrao pronto para o combate.\n");

    //liberando memoria
    liberar_memoria(esquadrao, num_mechas);

    return 0;
}