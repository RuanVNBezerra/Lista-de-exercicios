// atv sobre alunos da ufersa
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TURMAS 10
#define MAX_VAGAS 3

// Definicao da estrutura Aluno
typedef struct
{
    int mat;
    char nome[81];
    float notas[3];
    float media;
} Aluno;

// Definicao da estrutura Turma
typedef struct
{
    char id;
    int vagas;
    Aluno *alunos[MAX_VAGAS];
} Turma;

// Variavel global para armazenar as turmas
Turma *turmas[MAX_TURMAS];

// Funcao para criar uma turma
Turma *cria_turma(char id)
{
    Turma *nova_turma = (Turma *)malloc(sizeof(Turma));
    nova_turma->id = id;
    nova_turma->vagas = MAX_VAGAS;
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        nova_turma->alunos[i] = NULL;
    }
    return nova_turma;
}

// Funcao para matricular um aluno em uma turma
void matricula_aluno(Turma *turma, int mat, char *nome)
{
    if (turma->vagas > 0)
    {
        for (int i = 0; i < MAX_VAGAS; i++)
        {
            if (turma->alunos[i] == NULL)
            {
                Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno));
                novo_aluno->mat = mat;
                strcpy(novo_aluno->nome, nome);
                for (int j = 0; j < 3; j++)
                {
                    novo_aluno->notas[j] = 0.0;
                }
                novo_aluno->media = 0.0;
                turma->alunos[i] = novo_aluno;
                turma->vagas--;
                printf("Aluno matriculado com sucesso!\n");
                return;
            }
        }
    }
    else
    {
        printf("Nao ha vagas disponiveis na turma.\n");
    }
}

// Funcao para lancar notas e calcular a media dos alunos de uma turma
void lanca_notas(Turma *turma)
{
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            printf("Matricula: %d Aluno: %s\n", turma->alunos[i]->mat, turma->alunos[i]->nome);
            for (int j = 0; j < 3; j++)
            {
                printf("Digite a nota %d: ", j + 1);
                scanf("%f", &turma->alunos[i]->notas[j]);
            }
            turma->alunos[i]->media = (turma->alunos[i]->notas[0] + turma->alunos[i]->notas[1] + turma->alunos[i]->notas[2]) / 3.0;
        }
    }
}

// Funcao para imprimir os dados de todos os alunos de uma turma
void imprime_alunos(Turma *turma)
{
    for (int i = 0; i < MAX_VAGAS; i++)
    {
        if (turma->alunos[i] != NULL)
        {
            printf("Matricula: %d\n", turma->alunos[i]->mat);
            printf("Nome: %s\n", turma->alunos[i]->nome);
            printf("Media: %.2f\n", turma->alunos[i]->media);
        }
    }
}

// Funcao para imprimir os dados de todas as turmas
void imprime_turmas(Turma **turmas, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (turmas[i] != NULL)
        {
            printf("Turma %c - %d vagas disponiveis\n", turmas[i]->id, turmas[i]->vagas);
        }
    }
}

// Funcao para procurar uma turma
Turma *procura_turma(Turma **turmas, int n, char id)
{
    for (int i = 0; i < n; i++)
    {
        if (turmas[i] != NULL && turmas[i]->id == id)
        {
            return turmas[i];
        }
    }
    return NULL;
}

int main()
{
    int opcao;
    int num_turmas = 0;

    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as\n");
    printf("funcionalidades de matricula, lancamento de notas e listagem de\n");
    printf("alunos.\n");
    printf("Autor: Ada Lovelace Versao: 1.0\n");

    while (1)
    {
        printf("MENU:\n");
        printf("1 – Criar turma\n");
        printf("2 – Listar turmas\n");
        printf("3 – Matricular aluno\n");
        printf("4 – Lancar notas\n");
        printf("5 – Listar alunos\n");
        printf("6 – Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            if (num_turmas < MAX_TURMAS)
            {
                char id;
                printf("Criando nova turma...\n");
                printf("Digite um id: ");
                scanf(" %c", &id);
                turmas[num_turmas] = cria_turma(id);
                num_turmas++;
                printf("Turma %c criada com sucesso!\n", id);
            }
            else
            {
                printf("Numero maximo de turmas atingido.\n");
            }
        }
        else if (opcao == 2)
        {
            printf("Listando turmas...\n");
            imprime_turmas(turmas, num_turmas);
        }
        else if (opcao == 3)
        {
            char id;
            int mat;
            char nome[81];
            printf("Matriculando aluno...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            Turma *turma = procura_turma(turmas, num_turmas, id);
            if (turma != NULL)
            {
                printf("Digite a matricula: ");
                scanf("%d", &mat);
                printf("Digite o nome: ");
                scanf(" %[^\n]%*c", nome);
                matricula_aluno(turma, mat, nome);
            }
            else
            {
                printf("Turma inexistente!\n");
            }
        }
        else if (opcao == 4)
        {
            char id;
            printf("Lancando notas...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            Turma *turma = procura_turma(turmas, num_turmas, id);
            if (turma != NULL)
            {
                lanca_notas(turma);
            }
            else
            {
                printf("Turma inexistente!\n");
            }
        }
        else if (opcao == 5)
        {
            char id;
            printf("Listando alunos...\n");
            printf("Digite o id da turma: ");
            scanf(" %c", &id);
            Turma *turma = procura_turma(turmas, num_turmas, id);
            if (turma != NULL)
            {
                imprime_alunos(turma);
            }
            else
            {
                printf("Turma inexistente!\n");
            }
        }
        else if (opcao == 6)
        {
            printf("Obrigado por usar este programa!\n");
            break;
        }
        else
        {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }

    // Libera a memoria alocada
    for (int i = 0; i < num_turmas; i++)
    {
        if (turmas[i] != NULL)
        {
            for (int j = 0; j < MAX_VAGAS; j++)
            {
                if (turmas[i]->alunos[j] != NULL)
                {
                    free(turmas[i]->alunos[j]);
                }
            }
            free(turmas[i]);
        }
    }

    return 0;
}