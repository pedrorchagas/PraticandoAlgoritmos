#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_DISTINCT_PALAVRAS 15000
#define TAM_PALAVRA 100
#define MAX_LINE 1024

// Estrutura para armazenar a palavra e sua frequência
typedef struct {
	char Termo[TAM_PALAVRA];
	int Ocorrencias;
} PalavraChave;

/*
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
		*dest++;
		*src++;
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
    busca_binaria_iterativa
    Função que realiza uma busca binária de forma interativa em uma
    lista estática já ordenada
*/
int busca_binaria_iterativa(PalavraChave *listaDistintas, char *alvo, int totalPalavras) {
	int esquerda = 0;
	int direita = totalPalavras - 1;
	int meio = 0;
	int verificacao = 0;

    while (esquerda <= direita) {
        meio = esquerda + (direita - esquerda) / 2;
        verificacao = strcmp(listaDistintas[meio].Termo, alvo);
		if (verificacao > 0) {
			// esta a direita
			direita = meio - 1;
		} else if (verificacao < 0) {
			// esta a esquerda
			esquerda = meio + 1;
		} else {
			return meio;
		}
    }

	return -1;
}

/*
    busca_binaria_recursiva
    Função que realiza uma busca binária recursiva em uma lista estática
*/
int busca_binaria_recursiva(PalavraChave *listaDistintas, char *alvo, int iEsquerda, int iDireita) {

	if (iEsquerda > iDireita)
		return -1;

	int iMeio = iEsquerda + (iDireita - iEsquerda) / 2;
	int verificacao = strcmp(alvo, listaDistintas[iMeio].Termo);

	int indice = -1;

	if (verificacao > 0) {
		// esta a direita
		indice = busca_binaria_recursiva(listaDistintas, alvo, iMeio+1, iDireita);
	} else if (verificacao < 0) {
		// esta a esquerda
		indice = busca_binaria_recursiva(listaDistintas, alvo, iEsquerda, iMeio-1);
	} else {
		indice = iMeio;
	}

	return indice;
}

/*
    inserirOrdenado
    Função que insere um novo elemento na fila estática mantendo a função ordenada
*/
void inserirOrdenado(PalavraChave *ListaDistintas, char *NovoTermo, int *TotalDistintas) {
	int i = *TotalDistintas - 1;

	// desloca para a direita os termos maiores que o novo
	while (i >= 0 && strcmp(ListaDistintas[i].Termo, NovoTermo) > 0) {
		ListaDistintas[i + 1] = ListaDistintas[i];
		i--;
	}

	// insere na posição livre
	strncpy(ListaDistintas[i + 1].Termo, NovoTermo, TAM_PALAVRA - 1);
	ListaDistintas[i + 1].Termo[TAM_PALAVRA - 1] = '\0';
	ListaDistintas[i + 1].Ocorrencias = 1;
}

/*
    Função principal do programa
    realiza a leitura do sevedrecs e percorre as palavras chaves dos artigos
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
					int encontrado = 0;

					// Verifica se o Token já existe na Lista para evitar duplicação
					// busca binaria
					//int indice = busca_binaria_iterativa(Lista, Temp, TotalDistintas);
					int indice = busca_binaria_recursiva(Lista, Temp, 0, TotalDistintas);

					if (indice >= 0) {
						Lista[indice].Ocorrencias++;
						encontrado = 1;
						break;
					}


					// Se não existir e houver espaço, adiciona como novo Token
					// Inserir de forma organizada
					if (!encontrado && TotalDistintas < MAX_DISTINCT_PALAVRAS) {
						inserirOrdenado(Lista, Temp, &TotalDistintas);
						TotalDistintas++;
					}
				}
				Token = strtok(NULL, ";\n");
			}
		}
	}
	fclose(Arquivo);

	// Exibição do resultado final
	printf("%-40s | %s\n", "PALAVRA-CHAVE (ORDENADA)", "OCORRENCIAS");
	printf("-----------------------------------------|------------\n");
	for (int i = 0; i < TotalDistintas; i++) {
		printf("%-40s | %d\n", Lista[i].Termo, Lista[i].Ocorrencias);
	}
	printf("\n Total de palavras distintas: %d\n", TotalDistintas );

	int indiceA = busca_binaria_iterativa(Lista, "bandwidth usage", TotalDistintas);
	int indiceB = busca_binaria_recursiva(Lista, "load balancing", 0, TotalDistintas);

	printf("Pesquisa interativa - Palavra encontrada em: %d\n", indiceA);
	printf("Pesquisa recursiva - Palavra encontrada em: %d\n", indiceB);
	return 0;
}