#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    //entrada do numero de casos
    int numero_casos;
    scanf("%d", &numero_casos);

    int tamanhos[100]; //variavel para armazenar o tamanho dos leds menores
    char led_grande[10000]; //variavel para ir adicionando o led grande

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
                for (int m = 1; m < tamanhos[i]; m++){
                    if (led[m] == 'X'){
                        led[m] = 'O';
                    } else {
                        led[m] = 'X';
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
            for (int lg = 0; led[lg] != '\0'; lg++){
                led_grande[tamanho_led_grande + lg] = led[lg];
            } 
        }
    }
    //verificação dos fios
    int tamanho_led_grande = strlen(led_grande);
    char estado_ultimo_led = led_grande[tamanho_led_grande - 1]; //estado do ultimo led
    char led_grande_finalizado[tamanho_led_grande + numero_casos]; //array final com os leds e os fios

    int qt_fios = 0; //variavel que vai me ajudar a adcionar os fios
    //laço geral da adicão dos fios, esse verifica o local onde os fios vao ser adicionados
    for (int f = 0; f < numero_casos; f++){
        //definindo onde cada laço vai começar e acabar
        int comeco, final;
        if (f == 0) {
            comeco = 0;
            final = tamanhos[f + 1];
        } else {
            comeco = tamanhos[f] + qt_fios;
            final = tamanhos[f + 1] + qt_fios;
        }

        //laço para adicionar os fios 
        for (int add = comeco; add <= final; add++){
            //caso seja o momento onde eu devo adicionar            
            if (add == final){
                //caso seja par 
                if (tamanho_led_grande % 2 == 0){
                    //condição @
                    if(estado_ultimo_led == led_grande[final]){
                        led_grande_finalizado[add] = '@';
                        qt_fios++;
                    }
                    //condição $
                    else if (estado_ultimo_led != led_grande[final]){
                        led_grande_finalizado[add] = '$';
                        qt_fios++;
                    }
                }
                //caso seja impar 
                else {
                    //condição # 
                    if (estado_ultimo_led == led_grande[final]){
                        led_grande_finalizado[add] = '#';
                        qt_fios++;
                    }
                    //condição %
                    else if (estado_ultimo_led != led_grande[final]){
                        led_grande_finalizado[add] = '%';
                        qt_fios++;
                    }
                }
            }else {
                led_grande_finalizado[add] = led_grande[add - qt_fios];
            }
        }
    }   
    //print final 
    for (int pf = 0; led_grande_finalizado[pf] != '\0'; pf++){
        printf("%c", led_grande_finalizado[pf]);
    }
}

