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

/**
 * Função para remover espaços e converter para minúsculas.
 * Padroniza os tokens para garantir contagem correta.
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

/**
 * Função de comparação para o qsort (ordem alfabética).
 */
/*
int comparar_alfabetico(const PalavraChave *a, const PalavraChave *b) {
    PalavraChave p1 = a;
    PalavraChave p2 = b;
    return strcmp(p1->Termo, p2->Termo);
}
*/

/*
int busca_binaria_iterativa(PalavraChave listaDistintas, char alvo, int totalPalavras){
	int esquerda = 0;
	int direita = totalPalavras - 1;
	int meio = 0;
	int verificacao = 0;
	int indice = -1;
	
	printf("A: %s, T: %d\n", alvo, totalPalavras);
	
	do {
		meio = (esquerda + direita)/2;
		verificacao = strcmp(listaDistintas[meio].Termo, alvo);
		if (verificacao > 0) {
			// esta a direita
			esquerda = meio;
		} else if (verificacao < 0) {
			// esta a esquerda
			direita = meio;
		} else {
			indice = meio;
		}
	} while(verificacao != 0 && direita-1 != esquerda && meio != 0); 
	
	return indice;
}
*/

No* criarNo(string valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    strcpy(novoNo->valor, valor) ;
    novoNo->direita = NULL;
    novoNo->esquerda = NULL;
    novoNo->ocorrencias = 1;
    return novoNo;
}

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

void imprimirCrescente(No *arvore) {

    if (arvore == NULL)
        return;
    
    // acessar esquerda
    imprimirCrescente(arvore->direita);
    if (arvore->ocorrencias > 1)
        printf("%-40s | %d\n", arvore->valor, arvore->ocorrencias);
    // acessar direita
    imprimirCrescente(arvore->esquerda);
}

void imprimirDecrescente(No *arvore) {

    if (arvore == NULL)
        return;
    
    // acessar esquerda
    imprimirDecrescente(arvore->esquerda);
    if (arvore->ocorrencias > 1)
        printf("%-40s | %d\n", arvore->valor, arvore->ocorrencias);
    // acessar direita
    imprimirDecrescente(arvore->direita);
}

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

    // imprimir na ordem crescer

    // imprimir na ordem decrescente

    printf("Total distintas: %d\n", TotalDistintas);

    printf("\n\nImprimindo na crescente\n\n");
    imprimirCrescente(arvore);
    printf("\n\nImpriindo na decrescente\n\n");
    imprimirDecrescente(arvore);
    return 0;
}