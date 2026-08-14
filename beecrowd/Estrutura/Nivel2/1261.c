#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM_STRING 40

typedef char string[TAM_STRING];

typedef struct palavraHay
{
    string palavra;
    int valor;
} palavraHay;

int comp(const void *a, const void *b) {
    string palavraA = *(const string *)a;
    string palavraB = *(const string *)b;

    int rank = strcmp(palavraA, palavraB);
    return rank;
}

int buscaBinariaValor(string *alvo, int qntPalavras, palavraHay *palavras) {
    int iEsquerda = 0;
    int iDireita = qntPalavras - 1;
    int indexBusca = (int) (iEsquerda + iDireita)/2;

    int cmpString = strcmp(alvo, palavras[indexBusca].palavra);
    int naoExiste = 0;

    while (cmpString != 0 && naoExiste == 0)
    {
        if (iEsquerda == iDireita) {
            naoExiste = 1;
        } else {
            if (cmpString > 0) {
                iEsquerda = indexBusca;
            }
            if (cmpString < 0) {
                iDireita = indexBusca;
            }
            indexBusca = (int) (iEsquerda + iDireita)/2;
        }
    }
    
    if (naoExiste == 1) 
        return 0;

    return palavras[indexBusca].valor;
}

int main() {
    int qntPalavras = 0;
    int qntDescricoes = 0;
    int i;

    palavraHay *listPalavrasHay = NULL;
    int *valoresDescricao = NULL;

    scanf("%d %d", &qntPalavras, &qntDescricoes);

    listPalavrasHay = (palavraHay *) malloc(sizeof(palavraHay) * qntPalavras);
    
    for (i = 0; i < qntPalavras; i++) {
        getchar();
        scanf("%s %d", &listPalavrasHay->palavra, &listPalavrasHay->valor);
    }

    qsort(listPalavrasHay, sizeof(palavraHay), qntPalavras, comp);

    string subString;
    int ehPonto = 0;
    do {
        scanf(" %s", &subString);

        if (strcmp(subString, ".")) {
            ehPonto = 1;
        }







    } while (ehPonto == 1);


    return 0;
}