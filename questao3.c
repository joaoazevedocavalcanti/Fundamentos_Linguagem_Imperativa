#include <stdio.h>

int main() {
    int numero_Xupenio, qt_canais, melhor_minuto, melhor_canal, melhor_resultado;
    int menor_diferenca = __INT_MAX__;

    scanf("%d %d", &numero_Xupenio, &qt_canais);

    //laço para os canais
    for (int canais = 1; canais <= qt_canais; canais++){
        int termo1, termo2;
        scanf("%d %d", &termo1, &termo2);
        
        int minuto = 1;
        int resultado, diferenca, melhor_resultado_canal, melhor_minuto_canal;
        int menor_diferenca_canal = __INT_MAX__;

        while(termo1 <= numero_Xupenio){
            //sequencia
            if (minuto == 1){
                resultado = termo1;
            } else if (minuto == 2){
                resultado = termo2;
            } else{
            resultado = termo1 + termo2;
            termo1 = termo2;
            termo2 = resultado;
            }
            //diferença
            diferenca = abs(resultado - numero_Xupenio);
            //verificaçao do melhor minuto
            if (diferenca < menor_diferenca_canal){
                menor_diferenca_canal = diferenca;
                melhor_minuto_canal = minuto;
                melhor_resultado_canal = resultado;
            }            
            minuto++; //acrescimo dos minutos
        }
        //verificação do melhor canal
        if (menor_diferenca_canal <= menor_diferenca){
            melhor_canal = canais;
            menor_diferenca = menor_diferenca_canal;
            melhor_minuto = melhor_minuto_canal;
            melhor_resultado = melhor_resultado_canal;
        }
    }
    //verificação do VIP
    int d1 = melhor_resultado / 10;
    int d2 = melhor_resultado % 10;
    int VIP = d1 + d2;
    if (VIP > 10){
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d e com o VIP garantido!!!\n", melhor_canal, melhor_minuto);
    } else {
        printf("Xupenio, para ir ao lulupalooza vc deve entrar no canal %d e sera chamado mais ou menos no minuto %d, mas o ingresso VIP n�o vai rolar :(\n", melhor_canal, melhor_minuto);
    }
}