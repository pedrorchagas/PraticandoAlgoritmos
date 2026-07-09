#include<stdio.h>


int main() {
    int sequenceLenght = 0;
    int i;
    int actualNumber;
    int previousNumber;
    int sequenceNumbers = 0;

    scanf("%d", &sequenceLenght);

    for (i = 0; i <= sequenceLenght; i++) {
        if (i < sequenceLenght) {
            scanf("%d", &actualNumber);
        } else {
            actualNumber = 0;
        }
        
        if (i > 0) {
            if (actualNumber != previousNumber) {
                sequenceNumbers++;
            }
        }
        previousNumber = actualNumber;
    }

    printf("%d\n", sequenceNumbers);


    return 0;
}