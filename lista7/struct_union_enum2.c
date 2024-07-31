#include <stdio.h>
#include <string.h>

// Definicao do enum para tipos de produtos
typedef enum {
    ALIMENTO,
    BEBIDA,
    ELETRONICO
} TipoProduto;

// Definicao da union para armazenar o tipo de produto
typedef union {
    TipoProduto tipo;
} Tipo;

// Definicao da struct Produto
typedef struct {
    char nome[100];
    float preco;
    Tipo tipo;
} Produto;

// Funcao para ler os dados de um produto
void lerProduto(Produto *p) {
    char tipo_str[20];
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]%*c", p->nome);
    printf("Digite o preco do produto: ");
    scanf("%f", &p->preco);
    printf("Digite o tipo do produto (ALIMENTO/BEBIDA/ELETRONICO): ");
    scanf(" %s", tipo_str);

    if (strcmp(tipo_str, "ALIMENTO") == 0) {
        p->tipo.tipo = ALIMENTO;
    } else if (strcmp(tipo_str, "BEBIDA") == 0) {
        p->tipo.tipo = BEBIDA;
    } else if (strcmp(tipo_str, "ELETRONICO") == 0) {
        p->tipo.tipo = ELETRONICO;
    } else {
        printf("Tipo invalido. Definindo como ALIMENTO por padrao.\n");
        p->tipo.tipo = ALIMENTO;
    }
}

// Funcao para imprimir os dados de um produto
void imprimirProduto(Produto p) {
    printf("Nome: %s\n", p.nome);
    printf("Preco: %.2f\n", p.preco);
    printf("Tipo: ");
    switch (p.tipo.tipo) {
        case ALIMENTO:
            printf("ALIMENTO\n");
            break;
        case BEBIDA:
            printf("BEBIDA\n");
            break;
        case ELETRONICO:
            printf("ELETRONICO\n");
            break;
        default:
            printf("Desconhecido\n");
            break;
    }
}

int main() {
    Produto p;
    lerProduto(&p);
    imprimirProduto(p);
    return 0;
}