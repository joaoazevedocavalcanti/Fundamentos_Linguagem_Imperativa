#include <stdio.h>

int main() {
    int premio, p1, p2, p3, resto; 
    int dinheiro_rebeka = 3;
    int deucerto = 0;

    scanf("%d", &premio);
    scanf("%d", &p1);
    scanf("%d", &p2);
    scanf("%d", &p3);


    //divisao dos premios
    int div1, div2, div3;

    //verificação se é inteiro
    if ((premio * p1) % 100 == 0 && (premio * p2) % 100 == 0 && (premio * p3) % 100 == 0) {
        div1 = premio * p1 / 100;
        div2 = premio * p2 / 100;
        div3 = premio * p3 / 100;
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", div1, div2, div3);
        resto = premio - (int)(div1 + div2 + div3);
        if (resto > 0){
            dinheiro_rebeka += resto;
        }
    }
    else{ //não é inteiro

            //INVESTIR UM REAL
            int premio1 = premio + 1;
            //as divisões são interias e o resto é maior ou igual a 2 (1 a mais do que ela investiu)
            if ((premio1 * p1) % 100 == 0 && (premio1 * p2) % 100 == 0 && (premio1 * p3) % 100 == 0) {
                div1 = premio1 * (p1/100.0);
                div2 = premio1 * (p2/100.0);
                div3 = premio1 * (p3/100.0);
                resto = premio1 - (div1 + div2 + div3);
                if (resto > 1) {
                    printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", div1, div2, div3);
                    dinheiro_rebeka -= 1;
                    dinheiro_rebeka += resto; 
                    deucerto = 1;
                }
            }

            //INVESTIR 2 REAIS
            int premio2 = premio + 2;
            //as divisões são inteiras e o resto é maior ou igual a 3 (1 a mais do que ela investiu)
            if ((premio2 * p1) % 100 == 0 && (premio2 * p2) % 100 == 0 && (premio2 * p3) % 100 == 0) {
                div1 = premio2 * (p1/100.0);
                div2 = premio2 * (p2/100.0);
                div3 = premio2 * (p3/100.0);
                resto = premio2 - (div1 + div2 + div3);
                if (resto > 2){
                    printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", div1, div2, div3);
                    dinheiro_rebeka -= 2;
                    dinheiro_rebeka += resto;
                    deucerto = 1;

                    //entrada das letras
                    char letra1, letra2, letra3;
                    int soma_letras = 0;
                    scanf(" %c %c %c", &letra1, &letra2, &letra3);
                    letra1 -= 96;
                    letra2 -= 96; 
                    letra3 -= 96;
                    soma_letras = letra1 + letra2 + letra3;
                    printf("%d\n", soma_letras);
                }
            }    

            //INVESTIR 3 REAIS 
            int premio3 = premio + 3;
            //as divisões são inteiras e o resto é maior ou igual a 4 (1 a mais do que ela investiu)
            if ((premio3 * p1) % 100 == 0 && (premio3 * p2) % 100 == 0 && (premio3 * p3) % 100 == 0) {
                div1 = premio3 * (p1/100.0);
                div2 = premio3 * (p2/100.0);
                div3 = premio3 * (p3/100.0);
                resto = premio3 - (div1 + div2 + div3);
                if (resto > 3){
                    printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", div1, div2, div3);
                    dinheiro_rebeka -= 3;
                    dinheiro_rebeka += resto;
                    deucerto = 1;
                }

                //entrada das idades e calculo das parcelas
                int idade1, idade2, idade3;
                int somaparcelas = 0;
                scanf("%d %d %d", &idade1, &idade2, &idade3);
                if (idade1 % 3 == 0) {
                    somaparcelas += idade1 / 3;
                }
                if (idade2 % 3 == 0){
                    somaparcelas += idade2 / 3;
                }
                if (idade3 % 3 == 0){
                    somaparcelas += idade3 / 3;
                }
                printf("%d\n", somaparcelas);
            }  

            //Caso todos os incrementos não derem certo
            if (deucerto == 0){ 
                printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
            } 
        }

    // condição se a rebeka vai ter dinheiro pra voltar ou n
    if (dinheiro_rebeka >= 7){
        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
    } else {
        printf("E parece que Rebeka vai ter que voltar andando...\n");
    }

    return 0;
}
