#include<stdio.h>
#include<math.h>

int main() {
    int qntLinhas;
    int i = 1, quadrado = 1, cubo = 1;

    scanf("%d", &qntLinhas);
    
    for (i = 1; i <= qntLinhas; i++) {
        quadrado = pow(i, 2);
        cubo = pow(i, 3);
        printf("%d %d %d\n", i, quadrado, cubo);
    }

    return 0;
}