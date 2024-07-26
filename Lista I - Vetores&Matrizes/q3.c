#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;

    srand(time(NULL));

    printf("Digite um numero inteiro positivo (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, digite um numero positivo.\n");
        return 1;
    }

    int **matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = (rand() % 100) + 1;
        }
    }

    printf("Matriz %dx%d preenchida com numeros aleatorios:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

