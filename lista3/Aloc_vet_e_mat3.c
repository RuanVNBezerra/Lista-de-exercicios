#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j;
    int **matriz;

    
    srand(time(NULL));

   
    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);

    matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    
    if (matriz == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100 + 1; 
        }
    }

    printf("\nMatriz:\n");
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
