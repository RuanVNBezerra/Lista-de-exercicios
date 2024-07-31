#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *vetor;

  
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    printf("Digite os elementos do vetor:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Elementos do vetor na ordem inversa:\n");
    for (i = n - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }

    free(vetor);

    return 0;
}
