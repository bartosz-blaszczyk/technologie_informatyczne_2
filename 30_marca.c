#include <stdio.h> // Dołączenie biblioteki standardowej wejścia/wyjścia do obsługi funkcji printf i scanf

#define SIZE 10 // Definicja stałej SIZE o wartości 10 (rozmiar tablicy)

void printArray(int array[]) { // Funkcja do wyświetlania elementów tablicy
    for (int i = 0; i < SIZE; ++i) { // Iteracja przez wszystkie elementy tablicy
        printf("array[%d] = %d\n", i, array[i]); // Wyświetlenie indeksu i wartości elementu
    }
}

int findMinMax(int array[], int findMax) { // Funkcja do znajdowania wartości minimalnej lub maksymalnej w tablicy
    int result = array[0]; // Inicjalizacja wyniku pierwszym elementem tablicy
    for (int i = 1; i < SIZE; ++i) { // Iteracja przez resztę tablicy
        if ((findMax && array[i] > result) || (!findMax && array[i] < result)) {
            // Jeśli findMax = 1 -> szukamy maksimum, jeśli findMax = 0 -> szukamy minimum
            result = array[i]; // Aktualizacja wyniku, jeśli znaleziono nową wartość ekstremalną
        }
    }
    return result; // Zwrócenie wartości minimalnej lub maksymalnej
}

double findAverage(int array[]) { // Funkcja do obliczania średniej wartości elementów tablicy
    int sum = 0; // Zmienna przechowująca sumę elementów
    for (int i = 0; i < SIZE; ++i) sum += array[i]; // Sumowanie wszystkich elementów tablicy
    return (double)sum / SIZE; // Zwrócenie średniej (konwersja sumy na double, aby uzyskać wartość dziesiętną)
}

void menu() { // Funkcja do wyświetlenia menu opcji
    printf("1. Enter values\n2. Display array\n3. Min value\n4. Max value\n5. Average\n0. EXIT\nSelect: ");
    // Wyświetlenie dostępnych opcji do wyboru
}

int main() { // Funkcja główna programu
    int array[SIZE] = {1, 2, 3, -4, 50, 6, 7, 8, 9, 10}, option; // Inicjalizacja tablicy wartościami domyślnymi oraz zmiennej option do obsługi menu
    printf("SIMPLE ARRAY\n\n"); // Wyświetlenie nagłówka programu

    do { // Pętla obsługująca menu, działająca do momentu wybrania opcji 0 (EXIT)
        menu(); // Wywołanie funkcji menu
        scanf("%d", &option); // Pobranie wyboru użytkownika

        switch (option) { // Obsługa różnych opcji menu
            case 1: // Opcja wprowadzania wartości do tablicy
                printf("Enter %d values: \n", SIZE); // Informacja o liczbie wymaganych wartości
                for (int i = 0; i < SIZE; ++i) scanf("%d", &array[i]); // Pobranie nowych wartości do tablicy
                break;
            case 2: printArray(array); break; // Opcja wyświetlenia tablicy
            case 3: printf("Min: %d\n", findMinMax(array, 0)); break; // Opcja znalezienia wartości minimalnej
            case 4: printf("Max: %d\n", findMinMax(array, 1)); break; // Opcja znalezienia wartości maksymalnej
            case 5: printf("Average: %.2f\n", findAverage(array)); break; // Opcja obliczenia średniej wartości
            case 0: printf("Exiting...\n"); break; // Opcja zakończenia programu
            default: printf("Choose a valid option... \n\n"); // Obsługa nieprawidłowego wyboru
        }
    } while (option); // Pętla działa, dopóki użytkownik nie wybierze opcji 0

    printf("THE END!\n"); // Komunikat końcowy
    return 0; // Zakończenie programu
}