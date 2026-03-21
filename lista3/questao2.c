#include <stdio.h>

int main() {
    int qt_total_latas = 50; //quantidade total de latinhas

    //clientes atendidos
    int clientes_atendidos;
    scanf("%d", &clientes_atendidos);

    //multiplos que compraram apenas uma lata
    int X;
    scanf("%d", &X);
 
    //recebendo a quantidade de pessoas que compraram mais de uma lata
    int qt_mais_lata;
    scanf("%d", &qt_mais_lata);
    int minutos_cml[qt_mais_lata];
    int qt_latas_cml[qt_mais_lata];

    //preenchendo os clientes que compraram mais de uma lata
    for (int cliente = 0; cliente < qt_mais_lata; cliente++){
        int horas, minutos;
        scanf("%d:%d %d", &horas, &minutos, &qt_latas_cml[cliente]);

        minutos += horas * 60;
        minutos_cml[cliente] = minutos;
    }

    int minutagem = 420; //7h em minutos
    int cliente_da_vez = 0; //variavel controle para cliente

    int cliente_vencedor; //controle do cliente que comprou a 50 lata
    int minuto_vencedor; //minuto que ele comprou essa lata

    int parar = 0; // parar o codigo

    int latas_compradas; //quantas latas foram compradas pelo cliente da vez
    int latas_compradas_vencedor; //quantidade de latas comprada pelo vencedor

    //laço geral para passagem de tempo do atendimento
    while(cliente_da_vez < clientes_atendidos && parar == 0){
        minutagem += 3; //atualização da minutagem
        cliente_da_vez++; //atualização do cliente

        int verificado = 0; //tenho que usar isso daqui para verificar se a minutagem de quem comprou mais de uma ja foi verificada e não passar na outra
        //verificar se chegou no horario da pessoa que comprou mais de uma lata
        for (int i = 0; i < qt_mais_lata; i++){
            if (minutos_cml[i] == minutagem){
                latas_compradas = qt_latas_cml[i];
                qt_total_latas -= latas_compradas;
                verificado = 1;

                //verificar se chegou na 50 lata
                if (qt_total_latas <= 0){
                    cliente_vencedor = cliente_da_vez;
                    minuto_vencedor = minutagem;
                    latas_compradas_vencedor = latas_compradas;
                    parar = 1; //parar o codigo
                }
            }
        }

        //verificar a pessoa que comprou apenas uma lata
        if (verificado == 0 && X > 0 && cliente_da_vez % X == 0){
            latas_compradas = 1;
            qt_total_latas -= latas_compradas;

            //verificar se chegou na 50 lata
            if (qt_total_latas <= 0){
                cliente_vencedor = cliente_da_vez;
                minuto_vencedor = minutagem;
                latas_compradas_vencedor = latas_compradas;
                parar = 1; //parar o codigo
            }
        }
    }

    //transformar de minuto para horario correto
    int hora_vencedora = minuto_vencedor / 60;
    minuto_vencedor %= 60;

    //caso exista um vencedor
    if (qt_total_latas <= 0){
        //caso o vencedor tenha comprado mais de uma lata
        if (latas_compradas_vencedor > 1){
            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou %d latas.", cliente_vencedor, hora_vencedora, minuto_vencedor, latas_compradas_vencedor);
        }
        //caso o vencedor tenha comprado apenas uma lata
        else {
            printf("Quem levou a cesta basica foi o %d* cliente atendido por coragem, as %02d:%02d. Que comprou 1 lata.", cliente_vencedor, hora_vencedora, minuto_vencedor);
        }
    //caso não tenha vencedor
    } else {
        //caso seja plural
        if (qt_total_latas > 1){
        printf("Ainda nao foram vendidas latas suficientes. Faltam %d latas.", qt_total_latas);
        //singular
        } else {
            printf("Ainda nao foram vendidas latas suficientes. Falta 1 lata.", qt_total_latas);
        }
    }

    return 0;
}