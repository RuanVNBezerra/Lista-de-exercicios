#include <stdio.h>
#include <stdlib.h>

int main() {
    int linhas, colunas, i, j;
    int **matriz;

    
    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    matriz = (int **)malloc(linhas * sizeof(int *));
    for (i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    
    if (matriz == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    
    printf("Digite os elementos da matriz:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz original:\n");
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz transposta:\n");
    for (i = 0; i < colunas; i++) {
        for (j = 0; j < linhas; j++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }

    for (i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
