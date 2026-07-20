#include<stdio.h>
#include<stdlib.h>

int buscaBinaria(int alvo, int qntCasas, int *casas) {
    int esquerda = 0, direita = qntCasas - 1;
    int indexBusca = (int)(esquerda + direita) / 2;

    while (alvo != casas[indexBusca]) {
        if (alvo > casas[indexBusca]) {
            esquerda = indexBusca + 1;
        }
        if (alvo < casas[indexBusca]) {
            direita = indexBusca - 1;
        }
        indexBusca = (int)(esquerda + direita) / 2;
    } 

    return indexBusca;
}


int main() {
    int qntCasas;
    int qntEncomendas;
    int *casas, *encomendas;
    int i;
    int ultimaCasa = 0, atualCasa = 0;
    int tempo = 0;

    scanf("%d %d", &qntCasas, &qntEncomendas);
    casas = (int *) malloc(qntCasas * sizeof(int));
    encomendas = (int *) malloc(qntEncomendas * sizeof(int));

    for (i = 0; i < qntCasas; i++) {
        scanf("%d", &casas[i]);
    }
    for (i = 0; i < qntEncomendas; i++) {
        scanf("%d", &encomendas[i]);
    }

    for (i = 0; i < qntEncomendas; i++) {
        atualCasa = buscaBinaria(encomendas[i], qntCasas, casas);
        tempo += abs(ultimaCasa - atualCasa);
        ultimaCasa = atualCasa;
    }

    printf("%d\n", tempo);

    return 0;
}