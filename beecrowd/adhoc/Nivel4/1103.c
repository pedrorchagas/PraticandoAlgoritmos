#include <stdio.h>
 
int main() {
    int horaFim, minutoFim, horaInicio, minutoInicio, duracao;
    do {
        scanf("%d %d %d %d", &horaInicio, &minutoInicio, &horaFim, &minutoFim);

        if (horaInicio != 0 || minutoInicio != 0 || horaFim != 0 || minutoFim != 0) {
            horaFim = horaFim * 60;
            horaInicio = horaInicio * 60;

            if ((horaFim + minutoFim) <= (horaInicio + minutoInicio)) {
                duracao = (1440 - (horaInicio + minutoInicio)) + (horaFim + minutoFim);
            } else {
                duracao = (horaFim + minutoFim) - (horaInicio + minutoInicio);
            }

            printf("%d\n", duracao);

        }
        

    } while (horaInicio != 0 || minutoInicio != 0 || horaFim != 0 || minutoFim != 0);



 
    return 0;
}