#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    int documento;
    int idade;
} Pessoa;

void preencherPessoa(Pessoa *pessoa) {
    printf("Digite o nome da pessoa: ");
    fgets(pessoa->nome, MAX_NOME, stdin);
    pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0'; // Remove a nova linha

    printf("Digite o número do documento: ");
    scanf("%d", &pessoa->documento);

    printf("Digite a idade: ");
    scanf("%d", &pessoa->idade);
}

void imprimirPessoa(Pessoa pessoa) {
    printf("Nome: %s\n", pessoa.nome);
    printf("Documento: %d\n", pessoa.documento);
    printf("Idade: %d\n", pessoa.idade);
}

void atualizarIdade(Pessoa *pessoa, int novaIdade) {
    pessoa->idade = novaIdade;
}

void encontrarMaisVelhaEMaisNova(Pessoa pessoas[], int numPessoas) {
    int i, maisVelha = 0, maisNova = 0;

    for (i = 1; i < numPessoas; i++) {
        if (pessoas[i].idade > pessoas[maisVelha].idade) {
            maisVelha = i;
        } else if (pessoas[i].idade < pessoas[maisNova].idade) {
            maisNova = i;
        }
    }

    printf("\nPessoa mais velha:\n");
    imprimirPessoa(pessoas[maisVelha]);

    printf("\nPessoa mais nova:\n");
    imprimirPessoa(pessoas[maisNova]);
}

int main() {
    int numPessoas, i;
    Pessoa pessoas[100]; // Ajustar o tamanho conforme necessário

    printf("Digite o número de pessoas: ");
    scanf("%d", &numPessoas);

    for (i = 0; i < numPessoas; i++) {
        printf("\nPessoa %d:\n", i + 1);
        preencherPessoa(&pessoas[i]);
    }

    encontrarMaisVelhaEMaisNova(pessoas, numPessoas);

    return 0;
}
