#include <stdio.h>
#include <math.h>
 
int main() {
    int qntCasos, i, j, naoEhPrimo = 0;
    unsigned int numero;
    double raiz;
 
    // ler qntCasos de teste
    scanf("%d", &qntCasos);

    // calcular casos de teste
    for (i = 0; i < qntCasos; i++) {
        naoEhPrimo = 0;
        // pegar valor
        scanf("%u", &numero);
        // realizar a raiz quadrada
        raiz = sqrt((double) numero);
        // fazer um for começando por 2 e pulando em cada impar

        for (j = 1; j < raiz; j += 2) {
            if (numero != 2 && numero != j) {
                if (j == 1) {
                    if ( numero % 2 == 0) {
                        naoEhPrimo = 1;
                    }
                } else {
                    if (numero % j == 0) {
                        naoEhPrimo = 1;
                    }
                }
            }
        }
        
        // se não encontrar nenhum até a raiz é um numero primo
        // se encontrar qualquer um não é numero primo
        if (naoEhPrimo == 1) {
            printf("Not Prime\n");
        } else {
            printf("Prime\n");
        }
    }
 
    return 0;
}