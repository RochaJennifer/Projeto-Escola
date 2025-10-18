#include <stdio.h>
#include "definicoes.h"

int main(void) {
 
    Aluno listaAluno[TAM_ALUNO];
    int qtdAluno = 0;

    Professor listaProfessor[TAM_PROFESSOR];
    int qtdProfessor = 0;

    Disciplina listaDisc[TAM_DISCIPLINA];
    int qtdDisc = 0;

    int opcao;
    int sair = 0;

    while(!sair){
        printf("\n---- PROJETO ESCOLA ----\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");
        printf("4 - Relatorios\n");
        printf("------------------------\n");
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
                            atualizarAluno(listaAluno, qtdAluno); 
                            break;
                        }
                        case 3: {
                            excluirAluno(listaAluno, qtdAluno);
                            break;
                        }
                        case 4: {
                            matricularAlunoEmDisciplina(listaAluno, qtdAluno, listaDisc, qtdDisc);
                            break;
                        }
                        case 5: {
                            listarAlunos(listaAluno, qtdAluno); 
                            break;
                        }
                        case 6: {
                            char sexoBusca;
                                printf("\nDigite o sexo que deseja listar (M/F): ");
                                listarAlunosPorSexo(listaAluno, qtdAluno, sexoBusca);
                            break;
                        }
                        case 7: {
                            listarAlunosOrnemadosPorNome(listaAluno, qtdAluno); 
                            break;
                        }
                        case 8: {
                            listarAlunosPorDataNascimento(listaAluno, qtdAluno); 
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
                printf("\n-- Módulo Professor--\n");
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
                            atualizarProfessor(listaProfessor, qtdProfessor);
                            break;
                        }
                        case 3: {
                           excluirProfessor(listaProfessor, qtdProfessor);
                            break;
                        }
                        case 4: {
                            listarProfessores(listaProfessor, qtdProfessor); 
                            break;
                        }
                        case 5: {
                            char sexoBusca;
                            printf("\nDigite o sexo que deseja listar (F/M): ");
                            listarProfessoresPorSexo(listaProfessor, qtdProfessor, sexoBusca);
                            break;
                        }
                        case 6: {
                            listarProfessoresPorNome(listaProfessor, qtdProfessor); 
                            break;
                        }
                        case 7: {
                            listarProfessoresPorDataNascimento(listaProfessor, qtdProfessor); 
                            break;
                        }
                        default:
                            printf("\nOpcao invalida!\n");
                            break;
                    }
                }
                break;
            }
            case 3:{
                printf("\n-- Módulo Disciplina --\n");
                int sairDisciplina = 0;
                while(!sairDisciplina){
                    int opcaoDisciplina = menuDisciplina();
                    switch(opcaoDisciplina){
                        case 0: {
                        sairDisciplina = 1; 
                        break;
                        }
                        case 1: {
                            cadastrarDisciplina(listaDisc, &qtdDisc, listaProfessor, qtdProfessor); 
                            break;
                        }
                        case 2: {
                            atualizarDisciplina(listaDisc, qtdDisc, listaProfessor, qtdProfessor);
                            
                            break;
                        }
                        case 3: {
                            excluirDisciplina(listaDisc, qtdDisc);
                            break;
                        }
                        case 4: {
                            listarDisciplinas(listaDisc, qtdDisc, listaProfessor, qtdProfessor);
                            break;
                        }
                        case 5: {
                            listarDisciplinaComAlunos(listaDisc, qtdDisc, listaAluno, qtdAluno);
                            break;                                                                                                                                                                                                                                                                                                                                                                                                                            ;
                        }
                        case 6: {
                            listarDisciplinasComMaisDe40Alunos(listaDisc, qtdDisc);
                            break;
                        }
                        default: 
                        printf("\nOpcao invalida!\n"); 
                        break;
                    }
                }
                break;
                }
            case 4: {
                printf("\n-- Módulo Relatórios --\n");
                int sairRelatorios = 0;
                while(!sairRelatorios){
                    int opcaoRelatorios = menuRelatorios();     
                    switch(opcaoRelatorios){
                        case 0: {
                            sairRelatorios = 1; 
                            break;
                        }
                        case 1: {
                            listarAniversariantesDoMes(listaAluno, qtdAluno, listaProfessor, qtdProfessor); 
                            break;
                        }
                        case 2: {
                            buscarPorNome(listaAluno, qtdAluno, listaProfessor, qtdProfessor);
                            break;
                        }
                        default:
                            printf("\nOpcao invalida!\n");
                            break;
                    }
                }
                break;
            }
            default:
                printf("\nOpcao invalida\n");
            break;
        }
    }

    return 0;
}
