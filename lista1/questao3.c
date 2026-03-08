#include <stdio.h>

int main() {
    int premio, p1, p2, p3, resto; 
    int dinheiro_rebeka = 3;

    scanf("%d", &premio);
    scanf("%d", &p1);
    scanf("%d", &p2);
    scanf("%d", &p3);


    //divisao dos premios
    double div1 = premio * (p1/100.0);
    double div2 = premio * (p2/100.0);
    double div3 = premio * (p3/100.0);

    //verificação se é inteiro
    if (div1 == (int)div1 && div2 == (int)div2 && div3 == (int)div3) {
        //print do valor que cada homem ficou
        printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)div1, (int)div2, (int)div3);

        resto = premio - (int)(div1 + div2 + div3);
        //sobrou alguma coisa
        if (resto > 0){
            dinheiro_rebeka += resto;
        }
    }
    if (div1 != (int)div1 || div2 != (int)div2 || div3 != (int)div3){ //não é inteiro

            //investir um real 
            int premio1 = premio + 1;
            div1 = premio1 * (p1/100.0);
            div2 = premio1 * (p2/100.0);
            div3 = premio1 * (p3/100.0);
            resto = premio1 - (int)(div1 + div2 + div3);
            //as divisões são interias e o resto é maior ou igual a 2 (1 a mais do que ela investiu)
            if (div1 == (int)div1 && div2 == (int)div2 && div3 == (int)div3 && resto >= 2) {
                printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)div1, (int)div2, (int)div3);
                dinheiro_rebeka -= 1;
                dinheiro_rebeka += resto; 
            }
            
            //investir 2 reais
            int premio2 = premio + 2;
            div1 = premio2 * (p1/100.0);
            div2 = premio2 * (p2/100.0);
            div3 = premio2 * (p3/100.0);
            resto = premio2 - (int)(div1 + div2 + div3);
            //as divisões são inteiras e o resto é maior ou igual a 3 (1 a mais do que ela investiu)
            if (div1 == (int)div1 && div2 == (int)div2 && div3 == (int)div3 && resto >= 3) {
                //print do valor que cada homem ficou
                printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)div1, (int)div2, (int)div3);
                dinheiro_rebeka -= 2;
                dinheiro_rebeka += resto;
                //entrada das letras
                int letra = 0;
                int soma_letras = 0;
                while ((letra = getchar()) != EOF){
                    switch (letra) {
                    case 'a':
                        soma_letras += 1;
                        break;
                    case 'b': 
                        soma_letras += 2;
                        break;
                    case 'c':
                        soma_letras += 3;
                        break;
                    case 'd':
                        soma_letras += 4;
                        break;
                    case 'e':
                        soma_letras += 5;
                        break;
                    case 'f':
                        soma_letras += 6;
                        break;
                    case 'g':
                        soma_letras += 7;
                        break;
                    case 'h':
                        soma_letras += 8;
                        break;
                    case 'i':
                        soma_letras += 9;
                        break;
                    case 'j':
                        soma_letras += 10;
                        break;
                    case 'k':
                        soma_letras += 11;
                        break;
                    case 'l':
                        soma_letras += 12;
                        break;
                    case 'm':
                        soma_letras += 13;
                        break;
                    case 'n':
                        soma_letras += 14; 
                        break;
                    case 'o':
                        soma_letras += 15;
                        break;
                    case 'p':
                        soma_letras += 16;
                        break;
                    case 'q':     
                        soma_letras += 17;
                        break;
                    case 'r':
                        soma_letras += 18;
                        break;
                    case 's':
                        soma_letras += 19;
                        break;        
                    case 't':
                        soma_letras += 20;    
                        break;
                    case 'u':
                        soma_letras += 21;
                        break;
                    case 'v':
                        soma_letras += 22;
                        break;
                    case 'w':
                        soma_letras += 23;
                        break;
                    case 'x':
                        soma_letras += 24;
                        break;
                    case 'y':
                        soma_letras += 25;
                        break;
                    case 'z':
                        soma_letras += 26;
                        break;
                    case '\n':
                    case '\t':
                    case ' ':
                        break;
                    }
                }
                //print do resultado das letras
                printf("%d\n", soma_letras);
            }    

            //investir 3 reais
            int premio3 = premio + 3;
            div1 = premio3 * (p1/100.0);
            div2 = premio3 * (p2/100.0);
            div3 = premio3 * (p3/100.0);
            resto = premio3 - (int)(div1 + div2 + div3);
            //as divisões são inteiras e o resto é maior ou igual a 4 (1 a mais do que ela investiu)
            if (div1 == (int)div1 && div2 == (int)div2 && div3 == (int)div3 && resto >= 4) {
                //print do valor que cada homem ficou
                printf("Cada homem ficou com %d, %d e %d reais, respectivamente\n", (int)div1, (int)div2, (int)div3);
                dinheiro_rebeka -= 3;
                dinheiro_rebeka += resto;

                //entrada das idades e calculo das parcelas
                int idade1, idade2, idade3;
                int somaparcelas = 0;
                scanf("%d %d %d", &idade1, &idade2, &idade3);
                if (idade1 % 3 == 0){
                    somaparcelas += idade1 / 3;
                }
                if (idade2 % 3 == 0){
                    somaparcelas += idade2 / 3;
                }
                if (idade3 % 3 == 0){
                    somaparcelas += idade3 / 3;
                }
                //print do resultado das idades
                printf("%d\n", somaparcelas);
            }  
            if (div1 != (int)div1 || div2 != (int)div2 || div3 != (int)div3){ //não é inteiro
                printf("Nao foi dessa vez que Rebeka pode ajudar...\n");
            } 
    }
    if (dinheiro_rebeka >= 7){
        printf("Ela conseguiu! Rebeka voltou para casa e apanhou da mae por sumir noite passada!\n");
    } else {
        printf("E parece que Rebeka vai ter que voltar andando...\n");
    }
}
