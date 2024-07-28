#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;
    int **matriz;

    // Semente para a geração de números aleatórios
    srand(time(NULL));

    // Lendo o tamanho da matriz
    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);

    // Alocando memória para a matriz
    matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Verificando se a alocação foi bem-sucedida
    if (matriz == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Preenchendo a matriz com números aleatórios
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1; // Números aleatórios entre 1 e 100
        }
    }

    // Imprimindo a matriz
    printf("\nMatriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
