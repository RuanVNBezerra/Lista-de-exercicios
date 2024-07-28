#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 100 // Tamanho máximo de um nome
#define MAX_PESSOAS 100 // Número máximo de pessoas

int main() {
    int num_pessoas, i;
    char **nomes;
    int *idades;

    // Lendo o número de pessoas
    printf("Digite o número de pessoas: ");
    scanf("%d", &num_pessoas);

    // Alocando memória para os nomes
    nomes = (char **)malloc(num_pessoas * sizeof(char *));
    for (i = 0; i < num_pessoas; i++) {
        nomes[i] = (char *)malloc(MAX_NOME * sizeof(char));
    }

    // Alocando memória para as idades
    idades = (int *)malloc(num_pessoas * sizeof(int));

    // Lendo os nomes e idades
    for (i = 0; i < num_pessoas; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", nomes[i]);  // Lê uma linha inteira, incluindo espaços
        printf("Digite a idade de %s: ", nomes[i]);
        scanf("%d", &idades[i]);
    }

    // Imprimindo os nomes
    printf("\nNomes armazenados:\n");
    for (i = 0; i < num_pessoas; i++) {
        printf("%s\n", nomes[i]);
    }

    // Liberando a memória alocada
    for (i = 0; i < num_pessoas; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);

    return 0;
}
