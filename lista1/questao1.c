#include <stdio.h>
#include <math.h>

int main() {
    int diaAni, mesAni, anoAni, diaAtual, mesAtual, anoAtual;

    //entrada
    scanf("%d/%d/%d %d/%d/%d", &diaAni, &mesAni, &anoAni, &diaAtual, &mesAtual, &anoAtual);

    //AMOR
    int amor = (((diaAni + mesAni + anoAni + diaAtual + mesAtual + anoAtual) * 7) % 101);

    if (amor < 20) {
        printf("Amor: %d%% Pessimo dia para se apaixonar.\n", amor);
    } else if (amor >= 20 && amor <= 40) {
        printf("Amor: %d%% Melhor manter o coracao <3 longe de perigo.\n", amor);
    } else if (amor > 40 && amor < 70) {
        printf("Amor: %d%% Se o papo e as ideias baterem, esta liberado pensar em algo.\n", amor);
    } else if (amor >= 70 && amor <= 80) {
        printf("Amor: %d%% Saia com o coracao aberto, mas lembre, nem toda troca de olhar em onibus e sinal de romance.\n", amor);
    } else {
        printf("Amor: %d%% Um dia deslumbrantemente lindo para amar. Ps: Cuidado com a intensidade.\n", amor);
    }

    //SORTE
    int sorte = (((diaAni + diaAtual + mesAni + mesAtual) * 9) + (anoAtual - anoAni)) % 101;

    if (sorte < 30){
        printf("Sorte: %d%% Nem jogue moedas pra cima hoje.", sorte);
    } else if (sorte >= 30 && sorte <= 50) {
        printf("Sorte: %d%% Melhor nao arriscar.", sorte);
    } else if (sorte > 50 && sorte < 80) {
        printf ("Sorte: %d%% Por sua conta em risco.", sorte);
    } else if (sorte >= 80 && sorte <= 90) {
        printf("Sorte: %d%% Hoje vale a pena arriscar.", sorte);        
    } else {
        printf("Sorte: %d%% Nao tenha medo de virar cartas hoje.", sorte);
    }
    printf(" Sem tigrinho nem jogos de azar, por favor!\n");
    

    //TRABALHO 
    int trabalho = ((anoAni + anoAtual) - ((diaAni + diaAtual + mesAni + mesAtual) * 8)) % 101;

    if (trabalho < 40){
        printf("Trabalho: %d%% Hoje nao sera um dia tao proveitoso, keep calm e faca o basico.\n", trabalho);
    } else if (trabalho >= 40 && trabalho <= 50) {
        printf("Trabalho: %d%% Segura a emocao, nao xinga ninguem, nao esquece de beber agua.\n", trabalho);
    } else if (trabalho > 50 && trabalho < 70) {
        printf("Trabalho: %d%% Um dia proveitoso com certeza, leve sua simpatia consigo.\n", trabalho);
    } else if (trabalho >= 70 && trabalho < 85) {
        printf("Trabalho: %d%% Boas vibracoes hoje, chances podem estar ao seu redor.\n", trabalho);
    } else {
        printf("Trabalho: %d%% Use do maximo de networking possível hoje, dia bom para negocios.\n", trabalho);
    }
    
    //COR 
    int cor = (pow(diaAni, 2) + pow(diaAtual, 2) + pow(mesAni, 2) + pow(mesAtual, 2) + pow(anoAni, 2) + pow(anoAtual, 2));
    cor = (int) cor % 11;

    switch (cor) {
        case 0: 
            printf("Cor: Cinza.");
            break;
        case 1:
            printf("Cor: Vermelho.");
            break;
        case 2:
            printf("Cor: Laranja.");
            break;
        case 3: 
            printf("Cor: Amarelo.");
            break;
        case 4: 
            printf("Cor: Verde.");
            break;
        case 5: 
            printf("Cor: Azul.");
            break;
        case 6: 
            printf("Cor: Roxo.");
            break;
        case 7:
            printf("Cor: Marrom.");
            break;
        case 8:
            printf("Cor: Rosa.");
            break;
        case 9:
            printf("Cor: Preto.");
            break;
        case 10:
            printf("Cor: Branco.");
            break;
    }

    return 0;
}