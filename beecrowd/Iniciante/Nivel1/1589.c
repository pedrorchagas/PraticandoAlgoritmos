#include<stdio.h>
#include<stdlib.h>

int main() {
    int testes, raio1, raio2;
    int i;
    int *respostas;

    scanf("%d", &testes);
    respostas = (int *) malloc(testes * sizeof(int));
    for (i = 0; i < testes; i++) {
        scanf("%d %d", &raio1, &raio2);
        respostas[i] = raio1 + raio2;
    }

    for (i = 0; i < testes; i++) {
        printf("%d\n", respostas[i]);
    }

    return 0;
}