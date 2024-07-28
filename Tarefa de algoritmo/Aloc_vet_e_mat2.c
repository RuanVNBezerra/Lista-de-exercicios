#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas, i, j;
    int **matriz;

    // Lendo o número de linhas e colunas
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    // Alocando memória para a matriz
    matriz = (int **)malloc(linhas * sizeof(int *));
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    // Verificando se a alocação foi bem-sucedida
    if (matriz == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Lendo os elementos da matriz
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimindo a matriz original
    printf("\nMatriz original:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Imprimindo a matriz transposta
    printf("\nMatriz transposta:\n");
    for (i = 0; i < colunas; i++) {
        for (j = 0; j < linhas; j++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }

    // Liberando a memória alocada
    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
