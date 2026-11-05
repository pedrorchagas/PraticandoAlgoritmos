#include<stdio.h>
#include<stdlib.h>

int main() {

    // Definir o vetor de notas
    int quantidade_alunos = 12;
    int* notas_alunos = malloc(quantidade_alunos * sizeof(int));

    // Ler um elemento
    int nota_aluno_2 = notas_alunos[1];

    // Escrever coisas

    return 0;
}