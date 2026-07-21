#include<stdio.h>


int main() {
    int treino;
    int pista;
    int termino;

    scanf("%d %d", &treino, &pista);

    termino = treino % pista;

    printf("%d\n", termino);

    return 0;
}