#include <stdio.h>


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


typedef struct {
    int dia;
    Mes mes;
    int ano;
} Data;


void lerData(Data *d) {
    int mes;
    printf("Digite o dia: ");
    scanf("%d", &d->dia);
    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);
    d->mes = mes - 1; 
    printf("Digite o ano: ");
    scanf("%d", &d->ano);
}


void imprimirData(Data d) {
    printf("%02d/%02d/%04d\n", d.dia, d.mes + 1, d.ano);
}

int main() {
    Data data;
    lerData(&data);
    imprimirData(data);
    return 0;
}