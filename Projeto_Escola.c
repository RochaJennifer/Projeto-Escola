#include <stdio.h>
#define TAM_ALUNO 3

int menuGeral();
int menuAluno();

typedef struct alu{
    int matricula;
    char sexo;
    int ativo;
} Aluno;

int main(void) {
 
    Aluno listaAluno[TAM_ALUNO];
    int opcao;
    int qtdAluno = 0;
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
        int sairAluno = 0;
        int opcaoAluno
        while(!sair){
            opcaoAluno =menuAluno();
            switch (opcaoAluno)
            {
            case 0:{
                sairAluno = 1;
                break;
            }
            case 1:{
                printf("Cadastrar Aluno\n");
                if (qtdAluno == TAM_ALUNO){
                    printf("Lista de alunos cheia\n");
                }else{
                    printf("Digite a matricula\n");
                    int matricula;
                    scanf("%d", &matricula);
                    if(matricula < 0){
                        printf("Matrícula inválida\n");
                    }
                    listaAluno[qtdAluno].matricula = matricula;
                    listaAluno[qtdAluno].ativo = 1
                    qtdAluno++;
                    printf("Cadastrado com sucesso\n");
                }

                break;
            }
        }

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