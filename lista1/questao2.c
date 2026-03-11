#include <stdio.h>

int main() {

    long long N, A, B;

    scanf("%lld", &N);
    scanf("%lld %lld", &A, &B);

    //soma de 1 at? o N
    long long somaN = N * (N + 1) / 2;

    //multiplos de A e B
    long long qt_multiploAB_aparece = N / (A * B);
    long long multiplosAB = ((A*B + qt_multiploAB_aparece*A*B) * qt_multiploAB_aparece) / 2;
    

    //multiplos apenas de A 
    long long qtmultiplosA = N / A;
    long long multiplosA = ((A + qtmultiplosA * A) * qtmultiplosA) / 2;

    //multiplos apenas de B
    long long qtmultiplosB = N / B;
    long long multiplosB = ((B + qtmultiplosB * B) * qtmultiplosB) / 2;

    //soma total
    long long somaTotal = somaN + multiplosAB - (multiplosA + multiplosB);

    //print do numero
    printf("%lld\n", somaTotal);
    //se for par
    if (somaTotal % 2 == 0) {
        printf("Lá ele!!!");
    } else {
        printf("Opa xupenio AULAS...");
    }

    return 0;
}