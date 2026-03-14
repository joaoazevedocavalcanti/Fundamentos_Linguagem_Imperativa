#include <stdio.h>

int main(){
    int N, K, P;

    scanf("%d %d %d", &N, &K, &P);

    int P_contagem = 0;
    int valor_resposta = 0;
    int Q = 0;

    for (int contador = N; contador < K; contador++){
        P_contagem = 0;
        
        //3 é impar e primo e não entra na verificação, por isso coloquei fora
        if ((contador % 3 == 0) && (contador / 3) % 3 != 0){
            P_contagem += 1;
        }

        //VERIFICAÇÃO DOS FATORES PRIMOS IMPARES
        for (int i = 5; i * i <= contador; i += 2){
                int e_primo = 1;
                for (int j = 2; j * j <= i; j++){
                    if (i % j == 0){
                        e_primo = 0;
                        break;
                    }
                }
                if (e_primo == 1 && contador % i == 0 && (contador / i) % i != 0){
                    P_contagem += 1;
                }
        }
        //colocar valores que sejam iguais a P  
        if (contador != N && P_contagem == P && valor_resposta != 0){
            Q += 1;
        }
        //colocar o primeiro valor que dê fatores primos impares e distintos
        if (P_contagem == P && valor_resposta == 0){
            valor_resposta = contador;
        }

    }

    if (valor_resposta == 0){
        printf("Poxa dudinha, me desculpa, nao achei os numeros mas vou te mandar uma foto de um gatinho fofo.");
    } else {
        printf("%d %d\n", valor_resposta, Q);
    }
    
    return 0;
}