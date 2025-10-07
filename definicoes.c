# include <stdio.h>
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
    scanf("%d", &lista[*qtd].matricula);

    if (lista[*qtd].matricula <= 0){
        printf("Matrícula invalida!\n");
        return;
    }

    limparBuffer();

    printf("Digite o nome: ");
    fgets(lista[*qtd].nome, 100, stdin);
    lista[*qtd].nome[strcspn(lista[*qtd].nome, "\n")] = 0;

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &lista[*qtd].sexo); 

    while (lista[*qtd].sexo != 'M' && lista[*qtd].sexo != 'm' && 
           lista[*qtd].sexo != 'F' && lista[*qtd].sexo != 'f') {
        printf("Sexo invalido! Digite M ou F: ");
        scanf(" %c", &lista[*qtd].sexo);
    }
    limparBuffer();

    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &lista[*qtd].dataNascimento.dia,
                        &lista[*qtd].dataNascimento.mes,
                        &lista[*qtd].dataNascimento.ano);
    limparBuffer(); 

    printf("Digite o CPF: ");
    fgets(lista[*qtd].cpf, 15, stdin);
    lista[*qtd].cpf[strcspn(lista[*qtd].cpf, "\n")] = 0;
    
    lista[*qtd].ativo = 1;
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
        if (lista[i].ativo == 1) {
            printf("-------------------------\n");
            printf("Matrícula: %d\n", lista[i].matricula);
            printf("Nome: %s\n", lista[i].nome);
            printf("Sexo: %c\n", lista[i].sexo);
            printf("Data de Nasc.: %02d/%02d/%d\n", lista[i].dataNascimento.dia,
                                                    lista[i].dataNascimento.mes,
                                                    lista[i].dataNascimento.ano);
            printf("CPF: %s\n", lista[i].cpf);
        }
    }
    printf("-------------------------\n");
}

    int menuProfessor(){
    int opcao;
    printf("\n-- Menu Professor --\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Listar Professores\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
    }

    void cadastrarProfessor(Professor lista[], int *qtd){
    printf("\n-- Cadastro de Professor --\n");
    if (*qtd == TAM_PROFESSOR){ printf("Lista de professores cheia!\n"); return; }
    
    printf("Digite a matricula: ");
    scanf("%d", &lista[*qtd].matricula);
    if (lista[*qtd].matricula <= 0){ printf("Matrícula invalida!\n"); return; }
    
    limparBuffer();
    
    printf("Digite o nome: ");
    fgets(lista[*qtd].nome, 100, stdin);
    lista[*qtd].nome[strcspn(lista[*qtd].nome, "\n")] = 0;
    
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &lista[*qtd].sexo);
    while (lista[*qtd].sexo != 'M' && lista[*qtd].sexo != 'm' && lista[*qtd].sexo != 'F' && lista[*qtd].sexo != 'f') {
        printf("Sexo invalido! Digite M ou F: ");
        scanf(" %c", &lista[*qtd].sexo);
    }
    
    limparBuffer();
    
    printf("Digite a data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &lista[*qtd].dataNascimento.dia, &lista[*qtd].dataNascimento.mes, &lista[*qtd].dataNascimento.ano);
    
    limparBuffer();
    
    printf("Digite o CPF: ");
    fgets(lista[*qtd].cpf, 15, stdin);
    lista[*qtd].cpf[strcspn(lista[*qtd].cpf, "\n")] = 0;
    
    lista[*qtd].ativo = 1;
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
        if (lista[i].ativo == 1) {
            printf("-------------------------\n");
            printf("Matrícula: %d\n", lista[i].matricula);
            printf("Nome: %s\n", lista[i].nome);
            printf("Sexo: %c\n", lista[i].sexo);
            printf("Data de Nasc.: %02d/%02d/%d\n", lista[i].dataNascimento.dia,
                                                    lista[i].dataNascimento.mes,
                                                    lista[i].dataNascimento.ano);
            printf("CPF: %s\n", lista[i].cpf);
        }
    }
    printf("-------------------------\n");
}