#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    //entrada do numero de casos
    int numero_casos;
    scanf("%d", &numero_casos);

    int tamanhos[100]; //variavel para armazenar o tamanho dos leds menores
    char led_grande[100000]; //variavel para ir adicionando o led grande

    //laço geral
    for (int i = 0; i < numero_casos; i++){
        char led[60]; //variavel que vai guardar os leds menores
        int qt_clock; //quantidade de vezes que vai rolar as mudanças
        scanf("%s %d", &led, &qt_clock);

        //tamanhos dos array
        tamanhos[i] = strlen(led);

        //laço para mudança do clock 
        for (int clock = 0; clock < qt_clock; clock++){
            //caso o primeiro ja esteja desligado
            if (led[0] == 'X'){
                led[0] = 'O';
            }
            //caso o primeiro led seja deligado
            else if (led[0] == 'O'){
                led[0] = 'X';
                //laço para realizar a mudança
                for (int m = 0; m < tamanhos[i]; m++){
                    if (led[m + 1] == 'O'){
                        led[m + 1] = 'X';
                    } else {
                        led[m+1] = 'O';
                        break;
                    }
                }
            }
        }

        //print dos leds menores
        for (int p = 0; p < tamanhos[i]; p++){
            printf("%c", led[p]);
        }
        printf("\n");

        //adicionando no array grande 
        if (i == 0){ //caso seja a primeira adição
            for (int lg = 0; led[lg] != '\0'; lg++){
                led_grande[lg] = led[lg];
            }
        }
        else { //caso não seja a primeira
            int tamanho_led_grande = strlen(led_grande); //variavel que vai guardar o tamanho para ajudar na adição
            char estado_ultimo_led = led_grande[tamanho_led_grande - 1];
            char fio;
            //verificação do fio
            if (tamanho_led_grande % 2 == 0){
                //condição @
                if (estado_ultimo_led == led[0]){
                    fio = '@';
                }
                //condição $
                else {
                    fio = '$';
                }
            } else {
                if (estado_ultimo_led == led[0]){
                    fio = '#';
                }
                else {
                    fio = '%';
                }
            }
            led_grande[tamanho_led_grande] = fio;
            tamanho_led_grande++;

            for (int lg = 0; led[lg] != '\0'; lg++){
                led_grande[tamanho_led_grande + lg] = led[lg];
            } 
        }   
    }
    for (int plg = 0; led_grande[plg] != '\0'; plg++){
        printf("%c", led_grande[plg]);
    }
}

