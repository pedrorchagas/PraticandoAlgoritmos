#include<stdio.h>

int main() {
    int nota;
    char conceito;

    scanf("%d", &nota);

    if (nota >= 86 && nota <= 100) {
        conceito = 'A';
    } else if (nota >= 61 && nota <= 85) {
        conceito = 'B';
    } else if (nota >= 36 && nota <= 60) {
        conceito = 'C';
    } else if (nota >= 1 && nota <= 35) {
        conceito = 'D';
    } else {
        conceito = 'E';
    }

    printf("%c\n", conceito);

    return 0;
}