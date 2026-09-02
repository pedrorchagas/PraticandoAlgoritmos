#include <stdio.h>
 
int main() {
    
    int Avar, Bvar, i;
    long long int Afactorial = 1, Bfactorial = 1;
    long long int Resposta;

    while (scanf("%d %d", &Avar, &Bvar) != EOF) {
        Afactorial = 1;
        Bfactorial = 1;
        for (i = 1; i <= Avar; i++) {
            Afactorial *= i;
        }

        for (i = 1; i <= Bvar; i++) {
            Bfactorial *= i;
        }

        Resposta = Afactorial + Bfactorial;

        printf("%lld\n", Resposta);
    }

    return 0;
}