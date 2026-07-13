#include<stdio.h>

int factorial(int num) {
    if (num == 0) {
        return 1;
    }

    return num * factorial(num - 1);
} 

int main() {
    int num;
    int response;
    scanf("%d", &num);

    response = factorial(num);

    printf("%d\n", response);
    return 0;
}