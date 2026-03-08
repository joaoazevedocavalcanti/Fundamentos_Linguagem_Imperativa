#include <stdio.h>

int main() {

    int N, A, B;

    scanf("%d", &N);
    scanf("%d %d", &A, &B);

    //soma de 1 até o N
    int somaN = N * (N + 1) / 2;

    //multiplos de A e B
    int multiplosAB = A * B;

    //multiplos apenas de A 
    int qtmultiplosA = N / A;
    int multiplosA = A * (qtmultiplosA * (qtmultiplosA + 1) / 2);

    //multiplos apenas de B
    int qtmultiplosB = N / B;
    int multiplosB = B * (qtmultiplosB * (qtmultiplosB + 1) / 2);

    //soma total
    int somaTotal = somaN + multiplosAB - (multiplosA + multiplosB);

    //print do numero
    printf("%d\n", somaTotal);
    //se for par
    if (somaTotal % 2 == 0) {
        printf("Lá ele!!!");
    } else {
        printf("Opa xupenio AULAS...");
    }

}