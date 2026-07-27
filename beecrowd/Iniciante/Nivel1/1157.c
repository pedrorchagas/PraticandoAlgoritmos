#include<stdio.h>

void divisor(int valor, int base) {
    if (valor <= 0)
        return;
    divisor(valor - 1, base);
    if (base % valor == 0)
        printf("%d\n", valor);
}

int main() {
    int valor;
    scanf("%d", &valor);
    divisor(valor, valor);
    return 0;
}