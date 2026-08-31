#include<stdio.h>
#include<stdlib.h>

int main() {
    // ler as horas
    int horaInicio, minutoInicio, horaFim, minutoFim, duracao = 0;
    scanf("%d %d %d %d", &horaInicio, &minutoInicio, &horaFim, &minutoFim);

    horaInicio = horaInicio * 60;
    horaFim = horaFim * 60;

    // calcular a duração da partida

    if ((horaFim + minutoFim) <= (horaInicio + minutoInicio)) {
        duracao = (1440 - (horaInicio + minutoInicio)) + (horaFim + minutoFim);
    } else {
        duracao = (horaFim + minutoFim) - (horaInicio + minutoInicio);
    }

    // mostrar o resultado
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao / 60, duracao % 60);

    return 0;
}