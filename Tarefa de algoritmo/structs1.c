#include <stdio.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float salario;
    int identificador;
    char cargo[MAX_NOME];
} Funcionario;

void preencherFuncionario(Funcionario *func) {
    printf("Digite o nome do funcionario: ");
    fgets(func->nome, MAX_NOME, stdin);
    func->nome[strcspn(func->nome, "\n")] = '\0'; // Remove a nova linha

    printf("Digite o salario: ");
    scanf("%f", &func->salario);

    printf("Digite o identificador: ");
    scanf("%d", &func->identificador);

    printf("Digite o cargo: ");
    fgets(func->cargo, MAX_NOME, stdin);
    func->cargo[strcspn(func->cargo, "\n")] = '\0';
}

void imprimirFuncionario(Funcionario func) {
    printf("Nome: %s\n", func.nome);
    printf("Salario: %.2f\n", func.salario);
    printf("Identificador: %d\n", func.identificador);
    printf("Cargo: %s\n", func.cargo);
}

void alterarSalario(Funcionario *func, float novoSalario) {
    func->salario = novoSalario;
}

void encontrarMaiorEMenorSalario(Funcionario funcionarios[], int numFuncionarios) {
    int i, maiorIndice = 0, menorIndice = 0;

    for (i = 1; i < numFuncionarios; i++) {
        if (funcionarios[i].salario > funcionarios[maiorIndice].salario) {
            maiorIndice = i;
        } else if (funcionarios[i].salario < funcionarios[menorIndice].salario) {
            menorIndice = i;
        }
    }

    printf("\nFuncionario com maior salario:\n");
    imprimirFuncionario(funcionarios[maiorIndice]);

    printf("\nFuncionario com menor salario:\n");
    imprimirFuncionario(funcionarios[menorIndice]);
}

int main() {
    int numFuncionarios, i;
    Funcionario funcionarios[100]; // Ajustar o tamanho conforme necessário

    printf("Digite o numero de funcionarios: ");
    scanf("%d", &numFuncionarios);

    for (i = 0; i < numFuncionarios; i++) {
        printf("\nFuncionario %d:\n", i + 1);
        preencherFuncionario(&funcionarios[i]);
    }

    encontrarMaiorEMenorSalario(funcionarios, numFuncionarios);

    return 0;
}
