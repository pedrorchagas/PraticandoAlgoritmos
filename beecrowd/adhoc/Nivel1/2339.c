#include<stdio.h>

int main() {
    int competidores, folhasTotais, folhaPorCompetidor;

    scanf("%d %d %d", &competidores, &folhasTotais, &folhaPorCompetidor);

    if (competidores * folhaPorCompetidor <= folhasTotais)
        printf("S\n");
    else
        printf("N\n"); 

    return 0;
}