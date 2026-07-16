#include<stdio.h>

int main() {
    int qntAmostras;
    int i;
    int tempo, velocidade;
    int distancia = 0;

    scanf("%d", &qntAmostras);

    for (i = 0; i < qntAmostras; i++) {
        scanf("%d %d", &tempo, &velocidade);
        distancia += tempo * velocidade;
    }

    printf("%d\n", distancia);

    return 0;
}