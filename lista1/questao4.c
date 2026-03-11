#include <stdio.h>
#include <stdlib.h>

int main() {
    int x_inicial, y_inicial, x_final, y_final, quadrante_evitado, quadrante_inicial;
    scanf("%d %d %d", &x_inicial, &y_inicial, &quadrante_evitado);

    //seprando os quadrantes inciais e o x e y finais
    if (x_inicial > 0 && y_inicial > 0) {
        quadrante_inicial = 1;
        x_final = -1;
        y_final = -1;
    } else if (x_inicial < 0 && y_inicial > 0) {
        quadrante_inicial = 2;
        x_final = 1;
        y_final = -1;
    } else if (x_inicial < 0 && y_inicial < 0) {
        quadrante_inicial = 3;
        x_final = 1;
        y_final = 1;
    } else if (x_inicial > 0 && y_inicial < 0) {
        quadrante_inicial = 4;
        x_final = -1;
        y_final = 1;
    }
    
    //caso o quadrante final seja o mesmo que o inicial
    if (quadrante_inicial == quadrante_evitado){
        printf("caminhada invalida");
    }

    int x_deslocamento, y_deslocamento;

    //quadrante final em 1 e quer chegar no 3
    if (quadrante_inicial == 1){
        x_deslocamento = abs(x_final - x_inicial);
        y_deslocamento = abs(y_final - y_inicial);
        //quadrante evita 4
        if (quadrante_evitado == 4){
            printf("%d passos em x e %d passos em y", x_deslocamento, y_deslocamento);
        //quadrante evitado 2
        } else if (quadrante_evitado == 2) {
            printf("%d passos em y e %d passos em x", y_deslocamento, x_deslocamento);
        }
    //quadrante final 2 e quer chegar no 4
    } else if (quadrante_inicial == 2) {
        x_deslocamento = abs(x_final - x_inicial);
        y_deslocamento = abs(y_final - y_inicial);
        //quadrante evita 3
        if (quadrante_evitado == 3){
            printf("%d passos em x e %d passos em y", x_deslocamento, y_deslocamento);
        //quadrante evitado 2
        } else if (quadrante_evitado == 1) {
            printf("%d passos em y e %d passos em x", y_deslocamento, x_deslocamento);
        }
    //quadrante inicial 3 e quer chegar no 1
    } else if (quadrante_inicial == 3) {
        x_deslocamento = abs(x_final - x_inicial);
        y_deslocamento = abs(y_final - y_inicial);
        //quadrante evita 2
        if (quadrante_evitado == 2){
            printf("%d passos em x e %d passos em y", x_deslocamento, y_deslocamento);
        //quadrante evitado 4
        } else if (quadrante_evitado == 4) {
            printf("%d passos em y e %d passos em x", y_deslocamento, x_deslocamento);
        }
    } else if (quadrante_inicial == 4) {
        x_deslocamento = abs(x_final - x_inicial);
        y_deslocamento = abs(y_final - y_inicial);
        //quadrante evita 2
        if (quadrante_evitado == 1){
            printf("%d passos em x e %d passos em y", x_deslocamento, y_deslocamento);
        //quadrante evitado 4
        } else if (quadrante_evitado == 3) {
            printf("%d passos em y e %d passos em x", y_deslocamento, x_deslocamento);
        }
    }

    return 0;
}
