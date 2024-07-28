#include <stdio.h>

int main() {
    int N, i;
    char sexo[100], opiniao[100];
    int cont_mulheres_gostaram = 0, cont_homens_nao_gostaram = 0;

    printf("Digite o numero de pessoas entrevistadas: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Pessoa %d:\n", i+1);
        printf("Sexo (M/F): ");
        scanf(" %c", &sexo[i]); // O espaço antes de %c evita problemas com espaços em branco
        printf("Opiniao (G/N): ");
        scanf(" %c", &opiniao[i]);

        if (sexo[i] == 'F' && opiniao[i] == 'G') {
            cont_mulheres_gostaram++;
        } else if (sexo[i] == 'M' && opiniao[i] == 'N') {
            cont_homens_nao_gostaram++;
        }
    }

    float porcentagem_mulheres_gostaram = (float)cont_mulheres_gostaram / N * 100;
    float porcentagem_homens_nao_gostaram = (float)cont_homens_nao_gostaram / N * 100;

    printf("\nResultados:\n");
    printf("Porcentagem de mulheres que gostaram: %.2f%%\n", porcentagem_mulheres_gostaram);
    printf("Porcentagem de homens que nao gostaram: %.2f%%\n", porcentagem_homens_nao_gostaram);

    return 0;
}
