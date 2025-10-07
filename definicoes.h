#ifndef DEFINICOES_H
#define DEFINICOES_H

#define TAM_ALUNO 3
#define TAM_PROFESSOR 3
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char nome[100];
    char sexo;
    Data dataNascimento;;
    char cpf[15];
    int ativo;
} DadosComuns;

typedef struct {
    DadosComuns dados;
} Aluno;

typedef struct {
    DadosComuns dados;
} Professor;

void limparBuffer();

int menuAluno();
void cadastrarAluno(Aluno lista[], int *qtd);
void listarAlunos(Aluno lista[], int qtd);
void excluirAluno(Aluno lista[], int qtd);

int menuProfessor();
void cadastrarProfessor(Professor lista[], int *qtd);
void listarProfessores(Professor lista[], int qtd);
void excluirProfessor(Professor lista[], int qtd);

#endif 