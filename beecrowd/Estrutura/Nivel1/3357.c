#include<stdio.h>
#include<math.h>

typedef char string[12];

int main() {
    int qntPessoas = 0, i;
    double litrosGarrafa = 0.0, litrosCuia = 0.0;
    string nomePessoas[10] = {};
    
    scanf("%d %lf %lf", &qntPessoas, &litrosGarrafa, &litrosCuia);

    for (i = 0; i < qntPessoas; i++) {
        getchar();
        scanf("%s", nomePessoas[i]);
    }

    double litrosResto = fmod(litrosGarrafa, litrosCuia);
    if (litrosResto == 0.0) {
        litrosResto = litrosCuia;
    }

    int qntPassadas = (litrosGarrafa - litrosResto) / litrosCuia;
    int indexPessoa = qntPassadas % qntPessoas;

    printf("%s %.1f\n", nomePessoas[indexPessoa], litrosResto);

    return 0;
}