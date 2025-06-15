#include <stdio.h>

#define SIZE 10

int main() {
    int numbers[SIZE] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};

    printf("Arrays\n");

    printf("\n");
    printf("Display numbers:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("numbers [%d] = %d\n", i, numbers[i]);
    }

    int minimum = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
    }

    printf("minimum = %d\n", minimum);

    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += numbers[i];
    }
    int maximum = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] > maximum) {
            maximum = numbers[i];  
        }
    }
    printf("maximum = %d\n", maximum);

    float average = (float) sum / SIZE;

    printf("sum = %d\n", sum);
    printf("average = %f\n", average);

    return 0;
}