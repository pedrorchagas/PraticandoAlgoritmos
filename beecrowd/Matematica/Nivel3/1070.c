#include <stdio.h>
 
int main() {

    int qntCasos = 0;
    int resultadoDias[1000] = {};
    int dias;
    int i;
    float alimentosKilos;
    // ler quantidade de casos de teste
    scanf("%d", &qntCasos);

    // leitura dos casos
    for (i = 0; i < qntCasos; i++) {
        scanf("%f", &alimentosKilos);
        dias = 0;
        while (alimentosKilos > 1.0) {
            alimentosKilos = alimentosKilos/2;
            dias += 1;
        }
        resultadoDias[i] = dias;
    }

    // mostrar resultados
    for (i = 0; i < qntCasos; i++) {
        printf("%d dias\n", resultadoDias[i]);
    }
    return 0;
}