#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m, n, i, j, cont = 0;
    char **matriz;

    // Restrição de tamanho da matriz
    do
    {
        printf("Digite o numero de linhas e colunas.\nDeve ser maior que 1 e menor que 1000: ");
        scanf("%d %d", &m, &n);
    } while (m < 1 || m > 1000 || n < 1 || n > 1000);

    // Alocar memória para a matriz
    matriz = (char **)malloc(m * sizeof(char *));
    for (i = 0; i < m; i++)
        matriz[i] = (char *)malloc((n + 1) * sizeof(char));

    printf("Digite o mapa em linhas: . para mar e # para terra:\n ");
    for (i = 0; i < m; i++)
    {
        scanf("%s", matriz[i]);
    }

    // Imprime a matriz
    printf("\nMapa informado: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%c ", matriz[i][j]);
        printf("\n");
    }

    // Conta as costas
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (matriz[i][j] == '#')
            {
                if (i == 0 || matriz[i - 1][j] == '.' ||     // Acima
                    i == m - 1 || matriz[i + 1][j] == '.' || // Abaixo
                    j == 0 || matriz[i][j - 1] == '.' ||     // Esquerda
                    j == n - 1 || matriz[i][j + 1] == '.')
                { // Direita
                    cont++;
                }
            }
        }
    }

    // Imprime o número de costas
    printf("\nO mapa contem %d costas\n", cont);

    // Libera a matriz
    for (i = 0; i < m; i++)
        free(matriz[i]);
    free(matriz);

    return 0;
}