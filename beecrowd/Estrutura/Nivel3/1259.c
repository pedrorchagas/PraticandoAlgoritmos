#include<stdio.h>
#include<stdlib.h>

/*
    se 0 são iguais
    se positivo A vem antes de B
    se negativo B vem antes de A
*/

int compASC(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return x - y; // ordem crescente
}

int compDESC(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return y - x; // ordem crescente
}

//void orderVetor(int* vetor, int qntLinhas) {
    /*
    int aux;
    int i, j;

    for (i = 0; vetor[i] % 2 == 0; i++) {
        if (vetor[i] > vetor[i + 1]) {
            for (j = i + 1; vetor[j] % 2 == 0; j++) {
                if (vetor[i] > vetor[j]) {
                    change(&vetor[i], &vetor[j]);
                }
            }
        }
    }

    for (i ; i < qntLinhas; i++) {
        if (vetor[i] < vetor[i + 1]) {
            for (j = i + 1; j < qntLinhas; j++){
                if (vetor[i] < vetor[j]) {
                    change(&vetor[i], &vetor[j]);
                }
            }
        }
    }
    */

    //qsort(vetor, qntLinhas, sizeof(int), )

//}

int main() {
    int vectorSize;
    int *pairVector;
    int *oddVector;
    int i;
    int indexPair = 0;
    int indexOdd = 0;
    int value;

    scanf("%d", &vectorSize);

    pairVector = (int *) malloc(vectorSize * sizeof(int));
    oddVector = (int *) malloc(vectorSize * sizeof(int));

    for (i = 0; i < vectorSize; i++) {
        scanf("%d", &value);

        if (value % 2 == 0) {
            // é par
            pairVector[indexPair] = value;
            indexPair++;
        } else {
            // é impar
            oddVector[indexOdd] = value;
            indexOdd++;
        }
    }

    // ordendar vetor de par
    qsort(pairVector, vectorSize, sizeof(int), compASC);

    // ordenar vetor de impares
    qsort(oddVector, vectorSize, sizeof(int), compDESC);


    for (i = 0; i < vectorSize; i++) {
        if (pairVector[i] > 0 )
            printf("%d\n", pairVector[i]);
    }
    for (i = 0; i < vectorSize; i++) {
        if (oddVector[i] > 0 )
            printf("%d\n", oddVector[i]);
    }
    
    return 0;
}