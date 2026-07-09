// 1A2
// se for maiuscula - subtrair 1o digito do 2o digito
// se for minuscula - somar
// se os dois digitos forem iguais - fazer o produto deles (esquecer a letra)

// Entrada
// 1 - Quantidade de testes que serão realizados
// 2 - (0 - 9)(a - Z)(0 - 9)


#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>


int main() {

    int qntTests = 0;
    int digit1, digit2;
    int i;
    int result;
    char letter;


    scanf("%i", &qntTests);

    int *list = (int *) malloc(sizeof(int) * qntTests);

    for (i = 0; i < qntTests; i++) {
        scanf("%d%c%d", &digit1, &letter, &digit2);
        //printf("D1: %i, L: %c, D2; %i", digit1, letter, digit2);

        if (
            (digit1 >= 0 && digit1 <= 9) &&
            (digit2 >= 0 && digit2 <= 9)
        ) {
            if (digit1 == digit2) {
                result = digit1 * digit2;
            } else if (isupper(letter)) {
                result = digit2 - digit1;
            } else if (islower(letter)) {
                result = digit1 + digit2;
            }
            
        }
        list[i] = result;
    }

    for (i = 0; i < qntTests; i++) { 
        printf("%i\n", list[i]);
    }

    return 0;
}