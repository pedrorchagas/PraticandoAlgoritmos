#include<stdio.h>
#include<string.h>

#define TAM_STRING 7

typedef char string[TAM_STRING];

int main() {
    int qntAbas;
    int qntAcoes;
    int i;
    string acao;

    scanf("%d %d", &qntAbas, &qntAcoes);

    for (i = 0; i < qntAcoes; i++) {
        scanf(" %s", acao);

        if (strcmp(acao, "fechou") == 0) {
            qntAbas += 1;
        }
        if (strcmp(acao, "clicou") == 0) {
            qntAbas -= 1; 
        }
    }

    printf("%d\n", qntAbas);
    return 0;
}