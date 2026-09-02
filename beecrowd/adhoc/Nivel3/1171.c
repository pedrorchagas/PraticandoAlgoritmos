#include<stdio.h>
#include<stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
    // x < y  -> retorna -1 -> x fica antes de y (ordem crescente)
    // x == y -> retorna  0 -> indiferente
    // x > y  -> retorna  1 -> x fica depois de y
}

int main() {
    int qntNumeros, i, j, leituraNumero, listaNumeros[100001] = {}, varAux, qntEncontrada, numeroBusca;

    scanf("%d", &qntNumeros);

    if (qntNumeros <= 0) {
        return 0; // nada a fazer
    }

    for (i = 0; i < qntNumeros; i++) {
        scanf("%d", &leituraNumero);
        listaNumeros[i] = leituraNumero;
    }

    qsort(&listaNumeros, qntNumeros, sizeof(int), cmp_int);

    qntEncontrada = 0;
    numeroBusca = listaNumeros[0];
    for (i = 0; i < qntNumeros; i++) {
        if (listaNumeros[i] == numeroBusca) {
            qntEncontrada += 1;
        }

        if (numeroBusca != listaNumeros[i] || i == qntNumeros) {
            printf("%d aparece %d vez(es)\n", numeroBusca, qntEncontrada);
            numeroBusca = listaNumeros[i];
            qntEncontrada = 1;
        } 
    }
    printf("%d aparece %d vez(es)\n", numeroBusca, qntEncontrada);
    return 0;
}