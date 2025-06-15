#include <stdio.h>

int main(int argc, char const *argv[]) {
    int i;
    int result = 0;
    printf("Podano %d argumentow:\n", argc);
    for (i = 0; i < argc; i++) {
        printf("Argunent #%d\t-\t%s\n", i, argv[i]);
    }
if()
    result = atoi(argv[1]) + atoi(argv[3]);
    printf("Wynik dzialania %d + %d = %d \n", atoi(argv[1]), atoi(argv[3]), result);

    result = atoi(argv[1]) - atoi(argv[3]);
    printf("Wynik dzialania %d - %d = %d \n", atoi(argv[1]), atoi(argv[3]), result);

    result = atoi(argv[1]) * atoi(argv[3]);
    printf("Wynik dzialania %d * %d = %d \n", atoi(argv[1]), atoi(argv[3]), result);


    result = atoi(argv[1]) / atoi(argv[3]);
    printf("Wynik dzialania %d / %d = %f \n", atoi(argv[1]), atoi(argv[3]), result);

    return 0;


    }