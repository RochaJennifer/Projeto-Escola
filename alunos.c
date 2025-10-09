#include <stdio.h>
#include <string.h>
#include "definicoes.h"

int menuAluno(){
    int opcao;
    printf("\n1 - Cadastrar Aluno\n");
    printf("2 - Listar Alunos\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void cadastrarAluno(Aluno lista[], int *qtd){
    printf("\n-- Cadastro de Aluno --\n");
    
    if (*qtd == TAM_ALUNO){
        printf("Lista de alunos cheia!\n");
        return;
    }

    printf("Digite a matricula: ");
    scanf("%d", &lista[*qtd].dados.matricula);

    if (lista[*qtd].dados.matricula <= 0){
        printf("Matrícula invalida!\n");
        return;
    }

    limparBuffer();

    printf("Digite o nome: ");
    fgets(lista[*qtd].dados.nome, 100, stdin);
    lista[*qtd].dados.nome[strcspn(lista[*qtd].dados.nome, "\n")] = 0;

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &lista[*qtd].dados.sexo);

    while (lista[*qtd].dados.sexo != 'M' && lista[*qtd].dados.sexo != 'm' && 
           lista[*qtd].dados.sexo != 'F' && lista[*qtd].dados.sexo != 'f') {
        printf("Sexo invalido! Digite M ou F: ");
        scanf(" %c", &lista[*qtd].dados.sexo);
    }
    limparBuffer();

    do {
        printf("Digite a data de nascimento (dd mm aaaa): ");
        scanf("%d %d %d", &lista[*qtd].dados.dataNascimento.dia,
                            &lista[*qtd].dados.dataNascimento.mes,
                            &lista[*qtd].dados.dataNascimento.ano);
        limparBuffer();
        if (!validarData(lista[*qtd].dados.dataNascimento)) {
            printf("Data invalida! Tente novamente.\n");
        }
    } while (!validarData(lista[*qtd].dados.dataNascimento));

    do {
        printf("Digite o novo CPF: ");
        fgets(lista[*qtd].dados.cpf, 15, stdin);
        lista[*qtd].dados.cpf[strcspn(lista[*qtd].dados.cpf, "\n")] = 0;
        if (!validarCPF(lista[*qtd].dados.cpf)) {
        printf("CPF invalido! Tente novamente.\n");
        }
    } while (!validarCPF(lista[*qtd].dados.cpf));

    lista[*qtd].dados.ativo = 1;
    (*qtd)++;
    
    printf("\nAluno cadastrado com sucesso!\n");
}

void listarAlunos(Aluno lista[], int qtd) {
    printf("\n-- Lista de Alunos --\n");
    if (qtd == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    for (int i = 0; i < qtd; i++) {
        if (lista[i].dados.ativo == 1) {
            printf("-------------------------\n");
            printf("Matrícula: %d\n", lista[i].dados.matricula);
            printf("Nome: %s\n", lista[i].dados.nome);
            printf("Sexo: %c\n", lista[i].dados.sexo);
            printf("Data de Nasc.: %02d/%02d/%d\n", lista[i].dados.dataNascimento.dia,
                                                    lista[i].dados.dataNascimento.mes,
                                                    lista[i].dados.dataNascimento.ano);
            printf("CPF: %s\n", lista[i].dados.cpf);
        }
    }
    printf("-------------------------\n");
}

void atualizarAluno(Aluno lista[], int qtd) {
    int matricula, encontrado = 0;

    printf("\n-- Atualizar Aluno --\n");
    printf("Digite a matrícula do aluno a ser atualizado: ");
    scanf("%d", &matricula);

    limparBuffer();

    for (int i = 0; i < qtd; i++) {
        if (lista[i].dados.matricula == matricula && lista[i].dados.ativo == 1) {
            printf("Digite o novo nome: ");
            fgets(lista[i].dados.nome, 100, stdin);
            lista[i].dados.nome[strcspn(lista[i].dados.nome, "\n")] = 0;

            printf("Digite o novo sexo (M/F): ");
            scanf(" %c", &lista[i].dados.sexo);
        while (lista[i].dados.sexo != 'M' && lista[i].dados.sexo != 'm' && 
                lista[i].dados.sexo != 'F' && lista[i].dados.sexo != 'f') {
                printf("Sexo invalido! Digite M ou F: ");
                scanf(" %c", &lista[i].dados.sexo);
        }
            limparBuffer();

        do {
            printf("Digite a data de nascimento (dd mm aaaa): ");
            scanf("%d %d %d", &lista[i].dados.dataNascimento.dia,
                        &lista[i].dados.dataNascimento.mes,
                        &lista[i].dados.dataNascimento.ano);

            limparBuffer();

            if (!validarData(lista[i].dados.dataNascimento)) {
            printf("Data invalida! Tente novamente.\n");
            }
        } while (!validarData(lista[i].dados.dataNascimento));

        do {
                printf("Digite o novo CPF: ");
                fgets(lista[i].dados.cpf, 15, stdin);
                lista[i].dados.cpf[strcspn(lista[i].dados.cpf, "\n")] = 0;
                if (!validarCPF(lista[i].dados.cpf)) {
                    printf("CPF invalido! Tente novamente.\n");
                }
        } while (!validarCPF(lista[i].dados.cpf));

            encontrado = 1;
            printf("Aluno de matricula %d atualizado com sucesso!\n", matricula);
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com a matricula %d não encontrado ou está excluído.\n", matricula);
    }
}

void excluirAluno(Aluno lista[], int qtd) {
    int matricula, encontrado = 0;

    printf("\n-- Excluir Aluno --\n");
    printf("Digite a matrícula do aluno a ser excluído: ");
    scanf("%d", &matricula);

    limparBuffer();

    for (int i = 0; i < qtd; i++) {
        if (lista[i].dados.matricula == matricula) {
            lista[i].dados.ativo = 0;
            encontrado = 1;
            printf("Aluno de matricula %d excluído com sucesso!\n", matricula);
            break;
        }
    }

    if (!encontrado) {
        printf("Aluno com a matricula %d não encontrado ou já excluído.\n", matricula);
    }
}

void matricularAlunoEmDisciplina(Aluno listaAluno[], int qtdAluno, Disciplina listaDisc[], int qtdDisc) {
    int matriculaAluno, codigoDisciplina;  
    int alunoEncontrado = 0, disciplinaEncontrada = 0;
    if (qtdAluno == 0) {
        printf("Nenhum aluno cadastrado para matricular.\n");
        return;
    }
    if (qtdDisc == 0) {
        printf("Nenhuma disciplina cadastrada para matricular.\n");
        return;
    }
    printf("\n-- Matricular Aluno em Disciplina --\n");
    printf("Digite a matrícula do aluno: ");    
    scanf("%d", &matriculaAluno);
    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].dados.matricula == matriculaAluno && listaAluno[i].dados.ativo == 1) {
            alunoEncontrado = 1;
            break;
        }
    }
    if (!alunoEncontrado) {
        printf("Aluno com a matrícula %d não encontrado ou está excluído.\n", matriculaAluno);
        return;
    }
    printf("Digite o código da disciplina: ");    
    scanf("%d", &codigoDisciplina);
    for (int i = 0; i < qtdDisc; i++) {
        if (listaDisc[i].codigo == codigoDisciplina && listaDisc[i].ativo == 1) {
            disciplinaEncontrada = 1;
            if (listaDisc[i].qtd_alunos_matriculados >= VAGAS_DISCIPLINA) {
                printf("A disciplina %d está cheia. Não é possível matricular mais alunos.\n", codigoDisciplina);
                return;
            }
            for (int j = 0; j < listaDisc[i].qtd_alunos_matriculados; j++) {
                if (listaDisc[i].alunos_matriculados[j] == matriculaAluno) {
                    printf("Aluno já está matriculado na disciplina %d.\n", codigoDisciplina);
                    return;
                }
            }
            listaDisc[i].alunos_matriculados[listaDisc[i].qtd_alunos_matriculados] = matriculaAluno;
            listaDisc[i].qtd_alunos_matriculados++;
            printf("Aluno com matrícula %d matriculado com sucesso na disciplina %d.\n", matriculaAluno, codigoDisciplina);
            return;
        }
    }
    if (!disciplinaEncontrada) {
        printf("Disciplina com o código %d não encontrada ou está excluída.\n", codigoDisciplina);
    }   
}