#include<stdio.h>
#include<math.h>

int main() {
    double posA[2];
    double posB[2];
    double distance;

    scanf("%lf %lf", &posA[0], &posA[1]);
    scanf("%lf %lf", &posB[0], &posB[1]);

    distance = sqrt(pow((posB[0] - posA[0]), 2) + pow((posB[1] - posA[1]), 2));

    printf("%.4f\n", distance);
    return 0;
}