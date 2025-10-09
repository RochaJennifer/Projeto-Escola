#include <stdio.h>
#include <string.h>
#include "definicoes.h"

int menuProfessor(){
    int opcao;
    printf("\n-- Menu Professor --\n");
    printf("1 - Cadastrar Professor\n");
    printf("2 - Atualizar Professor\n");
    printf("3 - Excluir Professor\n");
    printf("4 - Listar Professores\n");
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

void atualizarProfessor(Professor lista[], int qtd) {
    int matricula, encontrado = 0;

    printf("\n-- Atualizar Professor --\n");
    printf("Digite a matrícula do professor a ser atualizado: ");
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

            printf("Digite o novo CPF: ");
            fgets(lista[i].dados.cpf, 15, stdin);
            lista[i].dados.cpf[strcspn(lista[i].dados.cpf, "\n")] = 0;

            encontrado = 1;
            printf("Professor de matricula %d atualizado com sucesso!\n", matricula);
            break;
        }
    }

    if (!encontrado) {
        printf("Professor com a matricula %d não encontrado ou está excluído.\n", matricula);
    }
}

void excluirProfessor(Professor lista[], int qtd) {
    int matricula, encontrado = 0;

    printf("\n-- Excluir Professor --\n");
    printf("Digite a matrícula do professor a ser excluído: ");
    scanf("%d", &matricula);

        limparBuffer();


    for (int i = 0; i < qtd; i++) {
        if (lista[i].dados.matricula == matricula) {
            lista[i].dados.ativo = 0;
            encontrado = 1;
            printf("Professor de matricula %d excluído com sucesso!\n", matricula);
            break;
        }
    }

    if (!encontrado) {
        printf("Professor com a matricula %d não encontrado ou já excluído.\n", matricula);
    }
}