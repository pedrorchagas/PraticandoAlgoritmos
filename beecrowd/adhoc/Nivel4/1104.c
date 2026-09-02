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
    int AqntCartas, BqntCartas, Acartas[100000], Bcartas[100000], i;
    int trocasAB = 0, trocasBA = 0;
    int respostas[10000] = {}, qntRespostas =0;
 
    do {
        trocasAB = 0;
        trocasBA = 0;
        // ler quantidade de cartas A
        // ler quantidade de cartas B
        scanf("%d %d", &AqntCartas, &BqntCartas);

        // se for tudo 0 pular
        if (AqntCartas != 0 || BqntCartas != 0) {
            // ler cartas A
            // ler cartas B
            for (i = 0; i < AqntCartas; i++) {
                scanf("%d", &Acartas[i]);
            }
            for (i = 0; i < BqntCartas; i++) {
                scanf("%d", &Bcartas[i]);
            }

            // for na lista A procurando por quantos B não possui
            // for na lista B procurando por quantos A não possui
            int auxCarta = Acartas[0]; 
            for (i = 0; i < AqntCartas; i++) {
                if (i == 0 || Acartas[i] > auxCarta) { 
                    int *resultado = (int *) bsearch(&Acartas[i], Bcartas, BqntCartas, sizeof(int), cmp_int);

                    if (resultado == NULL) {
                        trocasAB += 1;
                    }
                    auxCarta = Acartas[i];
                }
            }
            auxCarta = Bcartas[0];
            for (i = 0; i < BqntCartas; i++) {
                if (i == 0 || Bcartas[i] > auxCarta) { 
                    int *resultado = (int *) bsearch(&Bcartas[i], Acartas, AqntCartas, sizeof(int), cmp_int);

                    if (resultado == NULL) {
                        trocasBA += 1;
                    }
                    auxCarta = Bcartas[i];
                }
            }
            // pegar menor numero
            // mostrar
            if (trocasAB < trocasBA) {
                respostas[qntRespostas] = trocasAB; 
            } else {
                respostas[qntRespostas] = trocasBA; 
            }
            qntRespostas += 1;
        }
        
        // sair quando tudo for 0
    } while(AqntCartas != 0 || BqntCartas != 0);

    for (i = 0; i < qntRespostas; i++ ) {
        printf("%d\n", respostas[i]);
    }

 
    return 0;
}