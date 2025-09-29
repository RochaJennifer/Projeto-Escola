#include <stdio.h>

int main(void) {

    int opcao;
    int sair = 0;//false

    while(!sair){

    printf("Projeto Escola\n");
    printf("0-Sair\n");
    printf("1-Aluno\n");
    printf("2-Professor\n");
    printf("3-Disciplinas\n");

    scanf("%d", &opcao);

    switch (opcao){
    case 0:
        sair = 1;
        break;
    
    case 1:
        printf("Módulo Aluno\n");
        break;

    case 2:
        printf("Módulo Professor\n");
        break;

    case 3:
        printf("Módulo Disciplinas\n");
        break;
    default:
        printf("Opção invalida\n");
        break;
    }

    return 0;
}