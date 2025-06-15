#include <stdio.h>

#define SIZE 10

// void printArray(int array[])
void printArrayByIndex(int array[], int size) {
       printf("Zawartość tablicy (indeks):\n");
       for (int i = 0; i < size; i++) {
               printf("array[%d] = %d\n", i, array[i]);
           }
       printf("\n");
}

void printArrayByPointer(int *array, int size) {
       printf("Zawartość tablicy (wskaźnik):\n");
       for (int i = 0; i < size; i++) {
               printf("*(" "%p" " + %d) = %d\n", array, i, *(array + i));
           }
       printf("\n");
}

void menu(int array[], int *size) {
       printf("MENU:\n");
       printf("1. Enter the values into the array\n");
       printf("2. Display the content of the array\n");
       printf("3. Determine the minimum value\n");
       printf("4. Determine the maximum value\n");
       printf("5. Determine the average value\n");
       printf("0. EXIT\n");
}

int main() {
       int numbers[SIZE];
       int currentSize = 0;
       menu(numbers, &currentSize); // Wyświetlenie menu

       return 0;
}