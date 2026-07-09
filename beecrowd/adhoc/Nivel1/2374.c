#include<stdio.h>


int main() {
    int target = 0;
    int current = 0;
    int diff = 0;

    scanf("%i", &target);
    scanf("%i", &current);

    diff = target - current;

    printf("%i\n", diff);


    return 0;
}