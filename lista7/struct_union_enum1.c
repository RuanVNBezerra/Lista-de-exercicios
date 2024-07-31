#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

// Definindo o tipo enumerado para o gênero
typedef enum {
    MASCULINO,
    FEMININO
} Genero;

// Definindo a estrutura Pessoa
typedef struct {
    char nome[MAX_NOME];
    int idade;
    Genero genero;
} Pessoa;

void lerPessoa(Pessoa *pessoa) {
    printf("Digite o nome: ");
    fgets(pessoa->nome, MAX_NOME, stdin);
    pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0'; 

    printf("Digite a idade: ");
    scanf("%d", &pessoa->idade);

    printf("Digite o gênero (0 - Masculino, 1 - Feminino): ");
    scanf("%d", (int*)&pessoa->genero);
}

void imprimirPessoa(Pessoa pessoa) {
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Gênero: %s\n", (pessoa.genero == MASCULINO) ? "Masculino" : "Feminino");
}

int main() {
    Pessoa pessoa;

    lerPessoa(&pessoa);
    imprimirPessoa(pessoa);

    return 0;
}
