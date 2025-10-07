#include <stdio.h>
#include "definicoes.h"

int main(void) {
 
    Aluno listaAluno[TAM_ALUNO];
    int qtdAluno = 0;

    Professor listaProfessor[TAM_PROFESSOR];
    int qtdProfessor = 0;

    int opcao;
    int sair = 0;

    while(!sair){
        printf("\n---- PROJETO ESCOLA ----\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 0:
                sair = 1;
                break;
            
            case 1: {
                printf("\n-- Módulo Aluno --\n");
                int sairAluno = 0;
                while(!sairAluno){
                    int opcaoAluno = menuAluno();
                    switch (opcaoAluno) {
                        case 0: {
                            sairAluno = 1;
                            break;
                        }
                        case 1: {
                            cadastrarAluno(listaAluno, &qtdAluno);
                            break;
                        }
                        case 2: {
                            listarAlunos(listaAluno, qtdAluno); 
                            break;
                        }
                        case 3: {
                            printf("\n-- Atualizar Aluno --\n");
                            break;
                        }
                        case 4: {
                            excluirAluno(listaAluno, qtdAluno);
                            break;
                        }
                        default:
                            printf("\nOpcao invalida!\n");
                            break;
                    }
                }
                break;
            }
            case 2: {
                int sairProfessor = 0;
                while(!sairProfessor){
                    int opcaoProfessor = menuProfessor();
                    switch(opcaoProfessor){
                        case 0: {
                            sairProfessor = 1; 
                            break;
                        }
                        case 1: {
                            cadastrarProfessor(listaProfessor, &qtdProfessor); 
                            break;
                        }
                        case 2: {
                            listarProfessores(listaProfessor, qtdProfessor); 
                            break;
                        }
                        case 3: {
                            printf("\n-- Atualizar Professor --\n");
                            break;
                        }
                        case 4: {
                            printf("\n-- Excluir Professor --\n");
                            break;
                        }
                        default:
                            printf("\nOpcao invalida!\n");
                            break;
                    }
                }
                break;
            }
            case 3:
                printf("\nMódulo Disciplinas (Ainda nao implementado)\n");
                break;
            default:
                printf("\nOpcao invalida\n");
                break;
        }
    }
    
    return 0;
}
