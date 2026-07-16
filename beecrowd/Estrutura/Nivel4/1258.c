#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define TAM_STRING 40

typedef char string[TAM_STRING];

typedef struct
{
    string nome;
    string cor;
    char tamanho;
} camisa;

typedef struct no {
    camisa *resposta;
    int qntLinhas;
    struct no *proximo;
} no;

int compCor(const string a, const string b) {
    int comp = strcmp(a, b);

    if (comp > 0)
        return 1;
    if (comp < 0) 
        return -1;
    return 0;
}

int getOrderTamanho(char tamanho) {
    switch (tamanho)
    {
        case 'P':
            return 1;
        case 'M':
            return 2;
        case 'G':
            return 3;
        default:
            return 0;
    }
} 

int compTamanho(char a, char b) {
    int orderA = getOrderTamanho(a);
    int orderB = getOrderTamanho(b);

    int var = 0;

    if (orderA > orderB)
        var = 1;
    if (orderB > orderA)
        var = -1;
    return var;
}
 


int compNome(const string a, const string b) {
    int comp = strcmp(a, b);

    if (comp > 0)
        return 1;
    if (comp < 0)
        return -1;
    return 0;
}

no* adicionarNo(no *inicio, int linhas) {
    no *novoNo = malloc(sizeof(no));
    if (novoNo == NULL) {
        exit(1);
    }

    novoNo->proximo = inicio;
    novoNo->qntLinhas = linhas;
    novoNo->resposta = (camisa *) malloc(linhas * sizeof(camisa));

    return novoNo;
}

int imprimirRespostas(no *lista, int passagem) {

    if (lista == NULL)
        return 1;

    int exec = imprimirRespostas(lista->proximo, passagem + 1);

    for (int i = 0; i < lista->qntLinhas; i++) {
        printf("%s ", lista->resposta[i].cor);
        printf("%c ", lista->resposta[i].tamanho);
        printf("%s", lista->resposta[i].nome);
    }

    if(passagem != 0) {
        printf("\n");
    }
}

void liberarMem() {

}


int comp(const void *a, const void *b) {
    const camisa *p1 = (const camisa *) a;
    const camisa *p2 = (const camisa *) b;

    int pCor = 0;
    int pTamanho = 0;
    int pNome = 0;

    pCor = compCor(p1->cor, p2->cor);
    if (pCor != 0) return pCor;
    pTamanho = compTamanho(p1->tamanho, p2->tamanho);
    if (pTamanho != 0) return pTamanho;
    pNome = compNome(p1->nome, p2->nome);
    if (pNome != 0) return pNome;

    return 0; 
}

int main() {
    int qntLinhas;
    int i, j;
    int qntRepostas = 0;
    camisa *respostas;
    no *finalResposta = NULL;

    do {
        scanf("%d", &qntLinhas);
        if (qntLinhas > 0) {
            getchar();
            finalResposta = adicionarNo(finalResposta, qntLinhas);

            for (i = 0; i < qntLinhas; i++) {
                fgets(finalResposta->resposta[i].nome, TAM_STRING, stdin);
                scanf(" %s %c", finalResposta->resposta[i].cor, &finalResposta->resposta[i].tamanho);
                getchar();
            }

            qsort(finalResposta->resposta, qntLinhas, sizeof(camisa), comp);
        }
    } while (qntLinhas > 0);

    imprimirRespostas(finalResposta, 0);

    return 0;
}