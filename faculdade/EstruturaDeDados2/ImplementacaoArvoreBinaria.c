#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_DISTINCT_PALAVRAS 15000
#define TAM_PALAVRA 100
#define MAX_LINE 1024

typedef char string[TAM_PALAVRA];

// Estrutura para armazenar a palavra e sua frequência
typedef struct {
    char Termo[TAM_PALAVRA];
    int Ocorrencias;
} PalavraChave;

typedef struct No{
    string valor;
    struct No *direita;
    struct No *esquerda;
    int ocorrencias;
} No;

/*

    normalizar
    Função para remover espaços e converter para minúsculas.
    Padroniza os tokens para garantir contagem correta.
    
*/
void normalizar(char *str) {
    char *dest = str;
    char *src = str;

    // Remove espaços no início
    while (isspace((char)*src)) src++;
    
    while (*src) {
        *dest = tolower((char)*src);
        dest++;
        src++;
    }
    *dest = '\0';

    // Remove espaços no fim
    if (dest > str) {
        dest--;
        while (dest >= str && isspace((unsigned char)*dest)) {
            *dest = '\0';
            dest--;
        }
    }
}

/*

    criarNo
    Função auxiliar que realiza a criação de um Nó

*/
No* criarNo(string valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    strcpy(novoNo->valor, valor) ;
    novoNo->direita = NULL;
    novoNo->esquerda = NULL;
    novoNo->ocorrencias = 1;
    return novoNo;
}

/*

    adicionarNo
    Função auxiliar que adiciona um novo No na arvore principal.

*/
No* adicionarNo(No *arvore, string valor, int *totalDistintas) {
    if (arvore == NULL) {
        arvore = criarNo(valor);
        (*totalDistintas)++;
        return arvore;
    }

    int comp = strcmp(arvore->valor, valor);
    if (comp == 0) {
        // quando for igual
        arvore->ocorrencias++;
    } else if (comp < 0) {
        // quando for esquerda
        arvore->esquerda = adicionarNo(arvore->esquerda, valor, totalDistintas);
    } else if (comp > 0) {       
        // quando for direita
        arvore->direita = adicionarNo(arvore->direita, valor, totalDistintas);
    }
    return arvore;
}
/*

    imprimirCrescente
    Função para imprimir a arvore na ordenação crescente
    
*/
void imprimirCrescente(No *arvore) {
    if (arvore == NULL)
        return;
    
    // acessar esquerda
    imprimirCrescente(arvore->direita);
    printf("%-40s | %d\n", arvore->valor, arvore->ocorrencias);
    
    // acessar direita
    imprimirCrescente(arvore->esquerda);
}

/*

    imprimirDecrescente
    Função para imprimir a arvore na ordenação decrescente

*/
void imprimirDecrescente(No *arvore) {
    if (arvore == NULL)
        return;
    
    // acessar esquerda
    imprimirDecrescente(arvore->esquerda);
    printf("%-40s | %d\n", arvore->valor, arvore->ocorrencias);
    
    // acessar direita
    imprimirDecrescente(arvore->direita);
}
/*

    liberarArvore 
    Função para liberar a arvore e seus nó da memória

*/
void liberarArvore(No *arvore) {
    if (arvore == NULL){
        return;
    }
    liberarArvore(arvore->direita);
    liberarArvore(arvore->esquerda);
    free(arvore);
}

/*

    Função principal do programa
    Abre o arquivo savedrecs_total e pega as palavras chaves
    e adiciona dentro de uma arvore binaria
    
*/
int main() {
    PalavraChave Lista[MAX_DISTINCT_PALAVRAS];
    int TotalDistintas = 0;

    FILE *Arquivo = fopen("savedrecs_total.txt", "r");
    if (Arquivo == NULL) {
        printf("Erro: savedrecs_total.txt nao encontrado.\n");
        return 1;
    }

    char Linha[MAX_LINE];
    No* arvore = NULL;

    while (fgets(Linha, sizeof(Linha), Arquivo)) {
        // As fontes identificam palavras-chave pela etiqueta DE
        if (strncmp(Linha, "DE ", 3) == 0) {
            char *Conteudo = Linha + 3;
            // Tokens separados por ponto e vírgula conforme os registros
            char *Token = strtok(Conteudo, ";\n");

            while (Token != NULL) {
                char Temp[TAM_PALAVRA];
                strncpy(Temp, Token, TAM_PALAVRA - 1);
                Temp[TAM_PALAVRA - 1] = '\0';
                
                normalizar(Temp);

                if (strlen(Temp) > 0) {
                    arvore = adicionarNo(arvore, Temp, &TotalDistintas);
                }
                Token = strtok(NULL, ";\n");
            }
        }
    }
    fclose(Arquivo);

    // Exibição do resultado final

    printf("Total distintas: %d\n", TotalDistintas);

    // imprimir na ordem crescer
    printf("\n\nImprimindo na crescente\n\n");
    imprimirCrescente(arvore);
    
    // imprimir na ordem decrescente
    printf("\n\nImpriindo na decrescente\n\n");
    imprimirDecrescente(arvore);
    
    // liberarArvore da memória
    liberarArvore(arvore);
    return 0;
}