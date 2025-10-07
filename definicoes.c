#include <stdio.h>
#include <string.h>
#include "definicoes.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &lista[*qtd].dados.dataNascimento.dia,
                        &lista[*qtd].dados.dataNascimento.mes,
                        &lista[*qtd].dados.dataNascimento.ano);
    limparBuffer();

    printf("Digite o CPF: ");
    fgets(lista[*qtd].dados.cpf, 15, stdin);
    lista[*qtd].dados.cpf[strcspn(lista[*qtd].dados.cpf, "\n")] = 0;

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

    int menuProfessor(){
    int opcao;
    printf("\n-- Menu Professor --\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professores\n");
    printf("3 - Atualizar Professor\n");
    printf("4 - Excluir Professor\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
    }

    void cadastrarProfessor(Professor lista[], int *qtd){
    printf("\n-- Cadastro de Professor --\n");
    if (*qtd == TAM_PROFESSOR){ printf("Lista de professores cheia!\n"); return; }
    
    printf("Digite a matricula: ");
    scanf("%d", &lista[*qtd].dados.matricula);
    if (lista[*qtd].dados.matricula <= 0){ printf("Matrícula invalida!\n"); return; }

    limparBuffer();
    
    printf("Digite o nome: ");
    fgets(lista[*qtd].dados.nome, 100, stdin);
    lista[*qtd].dados.nome[strcspn(lista[*qtd].dados.nome, "\n")] = 0;
    
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &lista[*qtd].dados.sexo);
    while (lista[*qtd].dados.sexo != 'M' && lista[*qtd].dados.sexo != 'm' && lista[*qtd].dados.sexo != 'F' && lista[*qtd].dados.sexo != 'f') {
        printf("Sexo invalido! Digite M ou F: ");
        scanf(" %c", &lista[*qtd].dados.sexo);
    }
    
    limparBuffer();
    
    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &lista[*qtd].dados.dataNascimento.dia, &lista[*qtd].dados.dataNascimento.mes, &lista[*qtd].dados.dataNascimento.ano);
    
    limparBuffer();
    
    printf("Digite o CPF: ");
    fgets(lista[*qtd].dados.cpf, 15, stdin);
    lista[*qtd].dados.cpf[strcspn(lista[*qtd].dados.cpf, "\n")] = 0;

    lista[*qtd].dados.ativo = 1;
    (*qtd)++;
    
    printf("\nProfessor cadastrado com sucesso!\n");
}

void listarProfessores(Professor lista[], int qtd) {
    printf("\n-- Lista de Professores --\n");
    if (qtd == 0) {
        printf("Nenhum professor cadastrado.\n");
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