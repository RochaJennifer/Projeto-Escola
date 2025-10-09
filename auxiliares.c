#include <stdio.h>
#include <string.h>
#include "definicoes.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


int validarData(Data data) {
    // Validação básica
    if (data.mes < 1 || data.mes > 12 || data.dia < 1 || data.ano <= 0) {
        return 0;
    }

    // Validação de dias por mês
    if (data.mes == 2) { // Fevereiro
        int bissexto = (data.ano % 4 == 0 && data.ano % 100 != 0) || (data.ano % 400 == 0);
        if (bissexto) {
            if (data.dia > 29) return 0;
        } else {
            if (data.dia > 28) return 0;
        }
    } else if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) { // Meses com 30 dias
        if (data.dia > 30) return 0;
    } else { // Meses com 31 dias
        if (data.dia > 31) return 0;
    }

    return 1; // Data válida
}

int validarCPF(char cpfStr[]) {
    int cpf[11];
    int i, j = 0;

   
    for (i = 0; cpfStr[i] != '\0'; i++) {
        if (cpfStr[i] >= '0' && cpfStr[i] <= '9') {
            if (j < 11) {
                cpf[j++] = cpfStr[i] - '0';
            }
        }
    }

    if (j != 11) return 0; 

    for (i = 0; i < 10; i++) {
        if (cpf[i] != cpf[i + 1]) break;
    }
    if (i == 10) return 0;

    // Primeiero dígito verificador
    int soma = 0;
    for (i = 0, j = 10; i < 9; i++, j--) {
        soma += cpf[i] * j;
    }
    int resto = (soma * 10) % 11;
    if (resto == 10) resto = 0;
    if (resto != cpf[9]) return 0;

    // Segundo dígito verificador
    soma = 0;
    for (i = 0, j = 11; i < 10; i++, j--) {
        soma += cpf[i] * j;
    }
    resto = (soma * 10) % 11;
    if (resto == 10) resto = 0;
    if (resto != cpf[10]) return 0;

    return 1;
}
