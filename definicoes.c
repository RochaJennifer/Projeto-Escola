#include <stdio.h>
#include <string.h>
#include "definicoes.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

    

int menuDisciplina(){
    int opcao;
    printf("\n-- Menu Disciplina --\n");
    printf("1 - Cadastrar Disciplina\n");
    printf("2 - Listar Disciplinas\n");
    printf("3 - Atualizar Disciplina\n");
    printf("4 - Excluir Disciplina\n");
    printf("0 - Voltar\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void cadastrarDisciplina(Disciplina listaDisc[], int *qtdDisc, Professor listaProf[], int qtdProf) {
    printf("\n-- Cadastro de Disciplina --\n");
    
    if (*qtdDisc ==TAM_DISCIPLINA) {
        printf("Limite de disciplinas atingido!\n");
        return;
    }

    printf("Digite o nome da disciplina: ");
    limparBuffer();
    fgets(listaDisc[*qtdDisc].nome, 100, stdin);
    listaDisc[*qtdDisc].nome[strcspn(listaDisc[*qtdDisc].nome, "\n")] = 0;

    printf("Digite o codigo da disciplina: ");
    scanf("%d", &listaDisc[*qtdDisc].codigo);
    
    limparBuffer();

    printf("Digite o semestre (ex: 20251 para 2025.1): ");
    scanf("%d", &listaDisc[*qtdDisc].semestre);

    limparBuffer();

    if (qtdProf == 0) {
        printf("\nERRO: Nao ha professores cadastrados para vincular a disciplina!\n");
        return;
    }

    int matriculaProf;
    int professorEncontrado = 0;

    do {
        printf("\n-- Professores Disponiveis --\n");
        listarProfessores(listaProf, qtdProf);
        printf("-------------------------\n");
        printf("Digite a matricula do professor para esta disciplina: ");
        scanf("%d", &matriculaProf);

        limparBuffer();

        for (int i = 0; i < qtdProf; i++) {
            if (listaProf[i].dados.matricula == matriculaProf && listaProf[i].dados.ativo) {
                listaDisc[*qtdDisc].professor_matricula = matriculaProf;
                professorEncontrado = 1;
                break;
            }
        }

        if (!professorEncontrado) {
            printf("\nMatricula de professor invalida ou inexistente. Tente novamente.\n");
        }
    } while (!professorEncontrado);
        
    listaDisc[*qtdDisc].qtd_alunos_matriculados = 0;
    listaDisc[*qtdDisc].ativo = 1;
    (*qtdDisc)++;

    printf("\nDisciplina cadastrada com sucesso!\n");
}

void listarDisciplinas(Disciplina listaDisc[], int qtdDisc, Professor listaProf[], int qtdProf) {
    printf("\n-- Lista de Disciplinas --\n");
    if (qtdDisc == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }
    for (int i = 0; i < qtdDisc; i++) {
        if (listaDisc[i].ativo == 1) {
            printf("-------------------------\n");
            printf("Codigo: %d\n", listaDisc[i].codigo);
            printf("Nome: %s\n", listaDisc[i].nome);
            printf("Semestre: %d\n", listaDisc[i].semestre);
            
            int professorEncontrado = 0;
            for (int j = 0; j < qtdProf; j++) {
                if (listaProf[j].dados.matricula == listaDisc[i].professor_matricula) {
                    printf("Professor: %s (Matricula: %d)\n", listaProf[j].dados.nome, listaProf[j].dados.matricula);
                    professorEncontrado = 1;
                    break;
                }
            }
            if (!professorEncontrado) {
                printf("Professor: Nao encontrado (Matricula: %d)\n", listaDisc[i].professor_matricula);
            }
            printf("Quantidade de Alunos Matriculados: %d\n", listaDisc[i].qtd_alunos_matriculados);
        }
    }
    printf("-------------------------\n");
}

void atualizarDisciplina(Disciplina listaDisc[], int qtdDisc, Professor listaProf[], int qtdProf) {
    int codigo, encontrado = 0;

    printf("\n-- Atualizar Disciplina --\n");
    printf("Digite o codigo da disciplina a ser atualizada: ");
    scanf("%d", &codigo);

    limparBuffer();

    for (int i = 0; i < qtdDisc; i++) {
        if (listaDisc[i].codigo == codigo && listaDisc[i].ativo == 1) {
            printf("Digite o novo nome da disciplina: ");
            fgets(listaDisc[i].nome, 100, stdin);
            listaDisc[i].nome[strcspn(listaDisc[i].nome, "\n")] = 0;

            printf("Digite o novo semestre (ex: 20251 para 2025.1): ");
            scanf("%d", &listaDisc[i].semestre);

            limparBuffer();

            if (qtdProf == 0) {
                printf("\nERRO: Nao ha professores cadastrados para vincular a disciplina!\n");
                return;
            }

            int matriculaProf;
            int professorEncontrado = 0;

            do {
                printf("\n-- Professores Disponiveis --\n");
                listarProfessores(listaProf, qtdProf);
                printf("-------------------------\n");
                printf("Digite a matricula do professor para esta disciplina: ");
                scanf("%d", &matriculaProf);

                limparBuffer();

                for (int j = 0; j < qtdProf; j++) {
                    if (listaProf[j].dados.matricula == matriculaProf && listaProf[j].dados.ativo) {
                        listaDisc[i].professor_matricula = matriculaProf;
                        professorEncontrado = 1;
                        break;
                    }
                }

                if (!professorEncontrado) {
                    printf("\nMatricula de professor invalida ou inexistente. Tente novamente.\n");
                }
            } while (!professorEncontrado);

            encontrado = 1;
            printf("Disciplina de codigo %d atualizada com sucesso!\n", codigo);
            break;
        }
    }

    if (!encontrado) {
        printf("Disciplina com o codigo %d nao encontrada ou esta excluida.\n", codigo);
    }
}

void excluirDisciplina(Disciplina listaDisc[], int qtdDisc) {
    int codigo, encontrado = 0;

    printf("\n-- Excluir Disciplina --\n");
    printf("Digite o codigo da disciplina a ser excluida: ");
    scanf("%d", &codigo);

    limparBuffer();

    for (int i = 0; i < qtdDisc; i++) {
        if (listaDisc[i].codigo == codigo) {
            listaDisc[i].ativo = 0;
            encontrado = 1;
            printf("Disciplina de codigo %d excluida com sucesso!\n", codigo);
            break;
        }
    }

    if (!encontrado) {
        printf("Disciplina com o codigo %d nao encontrada ou ja excluida.\n", codigo);
    }
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
