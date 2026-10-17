#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_DISTINCT_PALAVRAS 15000
#define TAM_PALAVRA 100
#define MAX_LINE 1024

typedef char string[TAM_PALAVRA];

// Estrutura para armazenar a palavra e sua frequÃªncia
typedef struct {
	string Termo;
	int Ocorrencias;
} PalavraChave;

typedef struct No {
	string valor;
	struct No *direita;
	struct No *esquerda;
	int ocorrencias;
} No;

typedef struct {
	int index;
	PalavraChave *lista;
} VetorPalavras;

/*

    normalizar
    FunÃ§Ã£o para remover espaÃ§os e converter para minÃºsculas.
    Padroniza os tokens para garantir contagem correta.

*/
void normalizar(char *str) {
	char *dest = str;
	char *src = str;

	// Remove espaÃ§os no inÃ­cio
	while (isspace((char)*src)) src++;

	while (*src) {
		*dest = tolower((char)*src);
		dest++;
		src++;
	}
	*dest = '\0';

	// Remove espaÃ§os no fim
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
    FunÃ§Ã£o auxiliar que realiza a criaÃ§Ã£o de um NÃ³

*/
No* criarNo(string valor, int ocorrencias) {
	No* novoNo = (No*) malloc(sizeof(No));
	strcpy(novoNo->valor, valor) ;
	novoNo->direita = NULL;
	novoNo->esquerda = NULL;
	novoNo->ocorrencias = ocorrencias;
	return novoNo;
}

/*

    adicionarNo
    FunÃ§Ã£o auxiliar que adiciona um novo No na arvore principal.

*/
No* adicionarNo(No *arvore, string valor, int *totalDistintas) {
	if (arvore == NULL) {
		arvore = criarNo(valor, 1);
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

No* adicionarNoOcorrencias(No *arvore, int ocorrencia, string termo) {
	if (arvore == NULL) {
		arvore = criarNo(termo, ocorrencia);
		return arvore;
	}

	//int comp = strcmp(arvore->valor, valor);
	if (arvore->ocorrencias == ocorrencia) {
		// quando for igual
		arvore->direita = adicionarNoOcorrencias(arvore->direita, ocorrencia, termo);
	} else if (arvore->ocorrencias < ocorrencia) {
		// quando for esquerda
		arvore->esquerda = adicionarNoOcorrencias(arvore->esquerda, ocorrencia, termo);
	} else if (arvore->ocorrencias > ocorrencia) {
		// quando for direita
		arvore->direita = adicionarNoOcorrencias(arvore->direita, ocorrencia, termo);
	}
	return arvore;
}

/*

    imprimirCrescente
    FunÃ§Ã£o para imprimir a arvore na ordenaÃ§Ã£o crescente

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

void inserirNoVetor(VetorPalavras *vetor, No *arvore) {
	int index = vetor->index;
	vetor->lista[index].Ocorrencias = arvore->ocorrencias;
	strncpy(vetor->lista[index].Termo, arvore->valor, TAM_PALAVRA - 1);

	vetor->index = index + 1;
}

void inserirListaCrescente(No *arvore, VetorPalavras *vetor) {
	if (arvore == NULL)
		return;

	// acessar esquerda
	inserirListaCrescente(arvore->direita, vetor);
	//(*lista[index].Termo) = arvore->valor;
	inserirNoVetor(vetor, arvore);


	// acessar direita
	inserirListaCrescente(arvore->esquerda, vetor);
}

/*

    imprimirDecrescente
    FunÃ§Ã£o para imprimir a arvore na ordenaÃ§Ã£o decrescente

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
    FunÃ§Ã£o para liberar a arvore e seus nÃ³ da memÃ³ria

*/
void liberarArvore(No *arvore) {
	if (arvore == NULL) {
		return;
	}
	liberarArvore(arvore->direita);
	liberarArvore(arvore->esquerda);
	free(arvore);
}

int comp(const void* A, const void* B) {
	PalavraChave* a = (PalavraChave*) A;
	PalavraChave* b = (PalavraChave*) B;
	if (a->Ocorrencias > b->Ocorrencias)
		return 1;
	else if (a->Ocorrencias < b->Ocorrencias)
		return -1;
	else
		return 0;
}

/*
No* popularNovaArvoreLegal(PalavraChave *listaDistintas, int iEsquerda, int iDireita) {
	No* novoNo = NULL;
	if (iEsquerda < iDireita) {

		int iMeio = (iEsquerda + iDireita) / 2;
		int ocorrenciasLocal = listaDistintas[iMeio].Ocorrencias;

		novoNo = criarNo(listaDistintas[iMeio].Termo, listaDistintas[iMeio].Ocorrencias);

	 	// (listaDistintas, alvo, iMeio+1, iDireita)

		int auxMeioEsquerda = (iMeio+1 + iDireita) / 2;
		int auxMeioDireita = (iEsquerda + iMeio-1) / 2;

		if (listaDistintas[auxMeioEsquerda].Ocorrencias == ocorrenciasLocal)
			novoNo->esquerda = popularNovaArvoreLegal(listaDistintas, iMeio+1, iDireita);
		if (listaDistintas[auxMeioDireita].Ocorrencias == ocorrenciasLocal)

		novoNo->esquerda = popularNovaArvoreLegal(listaDistintas, iMeio+1, iDireita);
		// (listaDistintas, alvo, iEsquerda, iMeio-1)
		novoNo->direita = popularNovaArvoreLegal(listaDistintas, iEsquerda, iMeio-1);
	}

	return novoNo;
}
*/

/*

    FunÃ§Ã£o principal do programa
    Abre o arquivo savedrecs_total e pega as palavras chaves
    e adiciona dentro de uma arvore binaria

*/
int main() {
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
			// Tokens separados por ponto e vÃ­rgula conforme os registros
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

	/*
	// ExibiÃ§Ã£o do resultado final

	printf("Total distintas: %d\n", TotalDistintas);

	// imprimir na ordem crescer
	printf("\n\nImprimindo na crescente\n\n");
	imprimirCrescente(arvore);

	// imprimir na ordem decrescente
	printf("\n\nImpriindo na decrescente\n\n");
	imprimirDecrescente(arvore);
	*/

	// Salvar arvore em um vetor
	VetorPalavras* vetorPalavras = (VetorPalavras *) malloc(sizeof(VetorPalavras));
	vetorPalavras->index = 0;
	vetorPalavras->lista = (PalavraChave *) malloc(sizeof(PalavraChave) * TotalDistintas);

	inserirListaCrescente(arvore, vetorPalavras);

	int i = 0;

	// qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,int (__cdecl *_PtFuncCompare)(const void *,const void *));
	qsort(vetorPalavras->lista, TotalDistintas, sizeof(PalavraChave), comp);

	//No* arvoreOcorrencias = popularNovaArvoreLegal(vetorPalavras->lista, 0, TotalDistintas);

	No* arvoreOcorrencia = NULL;
	for (i = 0; i<TotalDistintas; i++) {
		arvoreOcorrencia = adicionarNoOcorrencias(arvoreOcorrencia, vetorPalavras->lista[i].Ocorrencias, vetorPalavras->lista[i].Termo);
	}

	printf("\n\nImprimindo na crescente\n\n");
	imprimirCrescente(arvoreOcorrencia);

	printf("\n\nImpriindo na decrescente\n\n");
	imprimirDecrescente(arvoreOcorrencia);

	// liberarArvore da memÃ³ria
	liberarArvore(arvore);
	return 0;
}


/*
	TODO:
		Arvore -> Salvar em um vetor em ordem alfabética/crescente -OK
		Ordenaar o vetor pela frequência de ocorrência das palavras - OK
		Reconstruir arvore binária pela frequência - Utilizar a função de busca binária para inserir de forma correta
		Percorrer a lista em ordem crescente de ocorrência
*/