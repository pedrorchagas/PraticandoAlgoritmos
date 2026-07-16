#include<stdio.h>
#include<stdlib.h>

int main() {
    int carta1, carta2;
    int *resposta;
    int qntCasosDeTeste = 0;
    int i;
    int resto;

    scanf("%d", &qntCasosDeTeste);
    resposta = (int *) malloc(qntCasosDeTeste * sizeof(int));

    for (i = 0; i < qntCasosDeTeste; i++) {
        scanf("%d %d", &carta1, &carta2);

        do {
            resto = carta1 % carta2;
            if (resto != 0) {
                carta1 = carta2;
                carta2 = resto;
            }
        } while (resto != 0);
        resposta[i] = carta2;
    }

    for (i = 0; i < qntCasosDeTeste; i++) {
        printf("%d\n", resposta[i]);
    }

    return 0;
}