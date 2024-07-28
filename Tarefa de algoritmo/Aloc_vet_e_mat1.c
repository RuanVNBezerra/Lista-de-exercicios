#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *vetor;

    // Lendo o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    // Alocando memória dinamicamente para o vetor
    vetor = (int *)malloc(n * sizeof(int));

    // Verificando se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Lendo os elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    // Imprimindo os elementos na ordem inversa
    printf("Elementos do vetor na ordem inversa:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }

    // Liberando a memória alocada
    free(vetor);

    return 0;
}
