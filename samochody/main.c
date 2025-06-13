#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CARS 20

typedef struct {
    char marka[30];
    char model[30];
    int rok_produkcji;
    char nr_rejestracyjny[15];
    int przebieg;
    char silnik[20];
    char paliwo[10];
} Samochod;

int walidujPaliwo(const char *paliwo) {
    return strcmp(paliwo, "benzyna") == 0 ||
           strcmp(paliwo, "diesel") == 0 ||
           strcmp(paliwo, "lpg") == 0;
}

void dodajSamochod(Samochod auta[], int *liczba_samochodow) {
    if (*liczba_samochodow >= MAX_CARS) {
        printf("Osiagnieto maksymalna liczbe samochodow.\n");
        return;
    }

    Samochod *s = &auta[*liczba_samochodow];
    printf("Dodawanie nowego samochodu:\n");
    printf("Marka: ");
    scanf(" %[^\n]", s->marka);
    printf("Model: ");
    scanf(" %[^\n]", s->model);
    printf("Rok produkcji: ");
    scanf("%d", &s->rok_produkcji);
    printf("Numer rejestracyjny: ");
    scanf(" %[^\n]", s->nr_rejestracyjny);
    printf("Przebieg (km): ");
    scanf("%d", &s->przebieg);
    printf("Silnik (np. 2.0 TDI): ");
    scanf(" %[^\n]", s->silnik);

    do {
        printf("Rodzaj paliwa (benzyna/diesel/lpg): ");
        scanf(" %[^\n]", s->paliwo);
        for (int i = 0; s->paliwo[i]; i++)
            s->paliwo[i] = tolower(s->paliwo[i]);
        if (!walidujPaliwo(s->paliwo)) {
            printf("Niepoprawny rodzaj paliwa. Sprobuj ponownie.\n");
        }
    } while (!walidujPaliwo(s->paliwo));

    (*liczba_samochodow)++;
}

void wyswietlSamochody(Samochod auta[], int liczba_samochodow) {
    printf("\nLista samochodow:\n");
    for (int i = 0; i < liczba_samochodow; i++) {
        Samochod *s = &auta[i];
        printf("%d. %s %s (%d), Rejestracja: %s, Przebieg: %d km, Silnik: %s, Paliwo: %s\n",
               i + 1, s->marka, s->model, s->rok_produkcji, s->nr_rejestracyjny,
               s->przebieg, s->silnik, s->paliwo);
    }
}

void zapiszDoPliku(Samochod auta[], int liczba_samochodow, const char *nazwa_pliku) {
    FILE *plik = fopen(nazwa_pliku, "w");
    if (plik == NULL) {
        perror("Blad przy otwieraniu pliku do zapisu");
        return;
    }

    for (int i = 0; i < liczba_samochodow; i++) {
        Samochod *s = &auta[i];
        fprintf(plik, "%s;%s;%d;%s;%d;%s;%s\n",
                s->marka, s->model, s->rok_produkcji,
                s->nr_rejestracyjny, s->przebieg,
                s->silnik, s->paliwo);
    }

    fclose(plik);
    printf("Dane zapisano do pliku %s\n", nazwa_pliku);
}

void wczytajZPliku(Samochod auta[], int *liczba_samochodow, const char *nazwa_pliku) {
    FILE *plik = fopen(nazwa_pliku, "r");
    if (plik == NULL) {
        perror("Blad przy otwieraniu pliku do odczytu");
        return;
    }

    *liczba_samochodow = 0;
    while (*liczba_samochodow < MAX_CARS &&
           fscanf(plik, " %29[^;];%29[^;];%d;%14[^;];%d;%19[^;];%9[^\n]\n",
                  auta[*liczba_samochodow].marka,
                  auta[*liczba_samochodow].model,
                  &auta[*liczba_samochodow].rok_produkcji,
                  auta[*liczba_samochodow].nr_rejestracyjny,
                  &auta[*liczba_samochodow].przebieg,
                  auta[*liczba_samochodow].silnik,
                  auta[*liczba_samochodow].paliwo) == 7) {
        (*liczba_samochodow)++;
    }

    fclose(plik);
    printf("Dane wczytano z pliku %s\n", nazwa_pliku);
}

int main() {
    Samochod auta[MAX_CARS];
    int liczba_samochodow = 0;
    int wybor;
    const char *plik = "samochody.txt";

    do {
        printf("\nMENU:\n");
        printf("1. Dodaj samochod\n");
        printf("2. Wyswietl samochody\n");
        printf("3. Zapisz do pliku\n");
        printf("4. Wczytaj z pliku\n");
        printf("0. Wyjscie\n");
        printf("Twoj wybor: ");
        scanf("%d", &wybor);

        switch (wybor) {
            case 1:
                dodajSamochod(auta, &liczba_samochodow);
                break;
            case 2:
                wyswietlSamochody(auta, liczba_samochodow);
                break;
            case 3:
                zapiszDoPliku(auta, liczba_samochodow, plik);
                break;
            case 4:
                wczytajZPliku(auta, &liczba_samochodow, plik);
                break;
            case 0:
                printf("Zamykanie programu.\n");
                break;
            default:
                printf("Niepoprawna opcja.\n");
        }
    } while (wybor != 0);

    return 0;
}
