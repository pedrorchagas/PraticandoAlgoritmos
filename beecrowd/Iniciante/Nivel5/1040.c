#include<stdio.h>

#define QNT_NOTAS 4

int main() {
    double notas[QNT_NOTAS];
    double notaExame;
    int i;

    for (i = 0; i < QNT_NOTAS; i++) {
        scanf("%lf", &notas[i]);
    }

    double media = ( (notas[0] * 2) + (notas[1] * 3) + (notas[2] * 4) + (notas[3] * 1) ) / 10;
    printf("Media: %.1f\n", media);
    if (media >= 7.0){
        printf("Aluno aprovado.\n");
    } else if (media < 5.0) {
        printf("Aluno reprovado.\n");
    } else {
        printf("Aluno em exame.\n");
        scanf("%lf", &notaExame);
        printf("Nota do exame: %.1f\n", notaExame);
        
        media = (media + notaExame) / 2;

        if (media >= 5.0) {
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }
        printf("Media final: %.1f\n", media);
    }

    return 0;
}