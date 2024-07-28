#include <stdio.h>

int main() {
    int N, i, j, aprovados = 0;
    char gabarito[100], respostas[10][100];
    float notas[10];

    printf("Digite o numero de questoes: ");
    scanf("%d", &N);

    printf("Digite o gabarito da prova: ");
    for (i = 0; i < N; i++) {
        scanf(" %c", &gabarito[i]); // Espaço antes de %c para evitar problemas com espaços
    }

    for (i = 0; i < 10; i++) {
        printf("\nAluno %d:\n", i+1);
        printf("Digite as respostas: ");
        for (j = 0; j < N; j++) {
            scanf(" %c", &respostas[i][j]);
        }

        // Calcula a nota do aluno
        notas[i] = 0;
        for (j = 0; j < N; j++) {
            if (respostas[i][j] == gabarito[j]) {
                notas[i] += 10.0 / N;
            }
        }

        if (notas[i] >= 6) {
            aprovados++;
        }
    }

    // Imprime as notas e a porcentagem de aprovação
    printf("\nNotas dos alunos:\n");
    for (i = 0; i < 10; i++) {
        printf("Aluno %d: %.2f\n", i+1, notas[i]);
    }

    float porcentagem_aprovacao = (float)aprovados / 10 * 100;
    printf("\nPorcentagem de aprovacao: %.2f%%\n", porcentagem_aprovacao);

    return 0;
}