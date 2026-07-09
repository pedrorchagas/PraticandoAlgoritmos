// Busca na internet

// João fez uma pesquisa em seu site de busca predileto, e encontrou a resposta que estava procurando no
// terceiro link listado. Além disso, ele viu, pelo site, que t pessoas já haviam clicado neste link antes.
// João havia lido anteriormente, também na Internet, que o número de pessoas que clicam no segundo link listado é
// o dobro de número de pessoas que clicam no terceiro link listado. Nessa leitura, ele também descobriu que o número
// de pessoas que clicam no segundo link é a metade do número de pessoas que clicam no primeiro link.

// João está intrigado para saber quantas pessoas clicaram no primeiro link da busca, e, como você é amigo dele,
// quer sua ajuda nesta tarefa.

#include<stdio.h>

int main() {
    int visitors = 0;

    scanf("%d", &visitors);

    printf("%d\n", visitors * 4);

    return 0;
}