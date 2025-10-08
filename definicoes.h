#ifndef DEFINICOES_H
#define DEFINICOES_H

#define TAM_ALUNO 3
#define TAM_PROFESSOR 3
#define VAGAS_DISCIPLINA 40
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

typedef struct{
    int codigo;
    char nome[100];
    int semestre;
    int professor_matricula; //localizar profesor apartir da matricula já existente;
    int alunos_matriculados[VAGAS_DISCIPLINA]; //Armazenar alunos inscritos
    int qtd_alunos_matriculados;
    int ativo;
} Disciplina;

void limparBuffer();

int menuAluno();
void cadastrarAluno(Aluno lista[], int *qtd);
void listarAlunos(Aluno lista[], int qtd);
void atualizarAluno(Aluno lista[], int qtd);
void excluirAluno(Aluno lista[], int qtd);

int menuProfessor();
void cadastrarProfessor(Professor lista[], int *qtd);
void listarProfessores(Professor lista[], int qtd);
void atualizarProfessor(Professor lista[], int qtd);
void excluirProfessor(Professor lista[], int qtd);

int menuDisciplina();
void cadastrarDisciplina(Disciplina listaDisc[], int *qtdDisc, Professor listaProf[], int qtdProf);

#endif 