#include<stdio.h>

int main() {

    unsigned int curupira, boitata, boto, mapinguari, iara;
    int total = 0;

    scanf("%d", &curupira);
    scanf("%d", &boitata);
    scanf("%d", &boto);
    scanf("%d", &mapinguari);
    scanf("%d", &iara);

    total += curupira * 300;
    total += boitata * 1500;
    total += boto * 600;
    total += mapinguari * 1000;
    total += iara * 150;
    total += 225;

    printf("%d\n", total);

    return 0;
}