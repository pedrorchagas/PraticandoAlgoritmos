#include<stdio.h>

#define QNT_COMPETIDORES 5

int main() {
    int tipoCha;
    int escolhaCompetidor;
    int qntAcertos = 0;
    int i;


    scanf("%i", &tipoCha);

    for (i = 0; i < QNT_COMPETIDORES; i++) {
        scanf("%i", &escolhaCompetidor);
        if (escolhaCompetidor == tipoCha)
            qntAcertos++;
    }

    printf("%i\n", qntAcertos);
    return 0;
}