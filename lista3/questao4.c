#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    int numero_casos;
    scanf("%d", &numero_casos);

    int tamanhos[100];


    for (int i = 0; i < numero_casos; i++){
        char led[60];
        int qt_clock;
        scanf("%s %d", &led, &qt_clock);

        //tamanhos dos array
        tamanhos[i] = strlen(led);

        //laço para mudança do clock 
        for (int clock = 0; clock < qt_clock, clock++){
            if (led[0] == 'X'){
                led[0] = 'O';
                for (int p = 0; p < tamanhos[i]; p++){
                    printf("%s", led[p]);
                }
                break;
            }
        }

    }
}