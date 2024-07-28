#include <stdio.h>

// Definicao do enum para os meses do ano
typedef enum {
    JANEIRO,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
} Mes;

// Definicao da struct Data
typedef struct {
    int dia;
    Mes mes;
    int ano;
} Data;

// Funcao para ler uma data
void lerData(Data *d) {
    int mes;
    printf("Digite o dia: ");
    scanf("%d", &d->dia);
    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);
    d->mes = mes - 1; // Ajusta o valor para o enum (0-11)
    printf("Digite o ano: ");
    scanf("%d", &d->ano);
}

// Funcao para imprimir uma data no formato dd/mm/aaaa
void imprimirData(Data d) {
    printf("%02d/%02d/%04d\n", d.dia, d.mes + 1, d.ano); // Ajusta o valor do mes para a impressao (1-12)
}

int main() {
    Data data;
    lerData(&data);
    imprimirData(data);
    return 0;
}