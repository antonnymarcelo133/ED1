#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100  // Definindo o tamanho máximo para um nome completo

int main() {
    int num_pessoas;
    char **nomes;
    int *idades;

    // Solicitando ao usuário o número de pessoas
    printf("Digite o número de pessoas: ");
    scanf("%d", &num_pessoas);
    getchar();

    // Alocando memória para armazenar os nomes
    nomes = (char **)malloc(num_pessoas * sizeof(char *));
    if (nomes == NULL) {
        perror("Erro ao alocar memória para os nomes");
        return EXIT_FAILURE;
    }

    // Alocando memória para armazenar as idades
    idades = (int *)malloc(num_pessoas * sizeof(int));
    if (idades == NULL) {
        perror("Erro ao alocar memória para as idades");
        free(nomes);  // Liberar memória alocada para os nomes
        return EXIT_FAILURE;
    }

    // Lendo o nome e a idade de cada pessoa
    for (int i = 0; i < num_pessoas; i++) {
        // Alocando memória para o nome de cada pessoa
        nomes[i] = (char *)malloc(MAX_NOME * sizeof(char));
        if (nomes[i] == NULL) {
            perror("Erro ao alocar memória para um nome");
            // Liberar a memória já alocada antes de sair
            for (int j = 0; j < i; j++) {
                free(nomes[j]);
            }
            free(nomes);
            free(idades);
            return EXIT_FAILURE;
        }

        printf("Digite o nome completo da pessoa %d: ", i + 1);
        fgets(nomes[i], MAX_NOME, stdin);

        nomes[i][strcspn(nomes[i], "\n")] = '\0';

        printf("Digite a idade da pessoa %d: ", i + 1);
        scanf("%d", &idades[i]);
        getchar();
    }

    // Exibindo os nomes armazenados
    printf("\nNomes armazenados:\n");
    for (int i = 0; i < num_pessoas; i++) {
        printf("Pessoa %d: %s\n", i + 1, nomes[i]);
    }

    // Liberando a memória alocada
    for (int i = 0; i < num_pessoas; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);

    return 0;
}
