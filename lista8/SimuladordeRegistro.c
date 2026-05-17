#include <stdio.h>

//montando a union
union SensorGeral {
    //o byte bruto
    unsigned char byteBruto;
    //struct com as classificações
    struct {
        unsigned char erro    : 1;  
        unsigned char modo    : 3;  
        unsigned char leitura : 4;
    } campos_de_bits;
};

int main(){
    //declarando as variaveis gerais
    union SensorGeral sensor;
    unsigned int bit_Entrada; 
    
    //recebendo
    scanf("%u", &bit_Entrada);

    //atribuindo para o sensor 
    sensor.byteBruto = (unsigned char)bit_Entrada;

    //printando 
    printf("Byte bruto: %u | Erro: %u | Modo: %u | Leitura: %u\n", sensor.byteBruto, sensor.campos_de_bits.erro, sensor.campos_de_bits.modo, sensor.campos_de_bits.leitura);   

    return 0;
}