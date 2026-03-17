#include <stdio.h>

int main(){
    long int N, K, P;

    scanf("%ld %ld %ld", &N, &K, &P);

    int P_contagem = 0;
    int valor_resposta = -1;
    int Q = 0;

    for (int contador = N; contador < K; contador++){
        int invalido = 0;
        P_contagem = 0;
        int contador_aux = contador;
        //VERIFICAÇAO DOS FATORES PRIMOS IMPARES
        for (int i = 3; i <= contador; i += 2){
            if (contador_aux % i == 0 && (contador_aux / i) % i != 0){
                contador_aux /= i;
                P_contagem += 1;
            //quando as condições devem ser anuladas (numero que divide duas vezes e quando o P cresce mais que o necessario)
            } else if ((contador_aux % i == 0 && (contador_aux / i) % i == 0) || P_contagem > P){
                invalido = 1;
                break;
            }
            //otimizar para anular uma divisão desnecessaria
            if (i > contador_aux){
                break;
            }
        }
        //colocar valores que sejam iguais a P  
        if (contador != N && P_contagem == P && valor_resposta != -1 && invalido != 1){
            Q += 1;
        }
        //colocar o primeiro valor que da fatores primos impares e distintos
        if (P_contagem == P && valor_resposta == -1 && invalido != 1){
            valor_resposta = contador;
        }

    }
    //condição dos prints
    if (valor_resposta == -1){
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.");
    } else {
        printf("%d %d\n", valor_resposta, Q);
    }
    
    return 0;
}