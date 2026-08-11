#include<stdio.h>


int main () {
    double valorTotal = 0, valorGuardado;
    int qntNotas[12] = {};

    scanf("%lf", &valorTotal);

    valorGuardado = valorTotal;

    while (valorTotal > 0) {
        if (valorTotal - 100 >= 0){
            valorTotal -= 100;
            qntNotas[0]++;
        } else if (valorTotal - 50 >= 0){
            valorTotal -= 50;
            qntNotas[1]++;
        } else if (valorTotal - 20 >= 0){
            valorTotal -= 20;
            qntNotas[2]++;
        } else if (valorTotal - 10 >= 0){
            valorTotal -= 10;
            qntNotas[3]++;
        } else if (valorTotal - 5 >= 0){
            valorTotal -= 5;
            qntNotas[4]++;
        } else if (valorTotal - 2 >= 0){
            valorTotal -= 2;
            qntNotas[5]++;
        } else if (valorTotal - 1 >= 0){
            valorTotal -= 1;
            qntNotas[6]++;
        } else if (valorTotal - 0.5 >= 0){
            valorTotal -= 0.5;
            qntNotas[7]++;
        } else if (valorTotal - 0.25 >= 0){
            valorTotal -= 0.25;
            qntNotas[8]++;
        } else if (valorTotal - 0.10 >= 0){
            valorTotal -= 0.10;
            qntNotas[9]++;
        } else if (valorTotal - 0.05 >= 0){
            valorTotal -= 0.05;
            qntNotas[10]++;
        } else if (valorTotal - 0.01 >= 0){
            valorTotal -= 0.01;
            qntNotas[11]++;
        } else {
            break;
        }
    }

    printf("NOTAS:\n");
    printf("%i nota(s) de R$ 100.00\n", qntNotas[0]);
    printf("%i nota(s) de R$ 50.00\n", qntNotas[1]);
    printf("%i nota(s) de R$ 20.00\n", qntNotas[2]);
    printf("%i nota(s) de R$ 10.00\n", qntNotas[3]);
    printf("%i nota(s) de R$ 5.00\n", qntNotas[4]);
    printf("%i nota(s) de R$ 2.00\n", qntNotas[5]);
    
    printf("MOEDAS:\n");
    printf("%i moeda(s) de R$ 1.00\n", qntNotas[6]);
    printf("%i moeda(s) de R$ 0.50\n", qntNotas[7]);
    printf("%i moeda(s) de R$ 0.25\n", qntNotas[8]);
    printf("%i moeda(s) de R$ 0.10\n", qntNotas[9]);
    printf("%i moeda(s) de R$ 0.05\n", qntNotas[10]);
    printf("%i moeda(s) de R$ 0.01\n", qntNotas[11]);

    return 0;
}