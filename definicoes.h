#ifndef DEFINICOES_H
#define DEFINICOES_H

#define TAM_ALUNO 500
#define TAM_PROFESSOR 100
#define TAM_DISCIPLINA 100
#define VAGAS_DISCIPLINA 100
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
    int professor_matricula; 
    int alunos_matriculados[VAGAS_DISCIPLINA];
    int qtd_alunos_matriculados;
    int ativo;
} Disciplina;

int validarData(Data data);
int validarCPF(char cpf[]);

void limparBuffer();

int menuAluno();
void cadastrarAluno(Aluno lista[], int *qtd);
void listarAlunos(Aluno lista[], int qtd);
void atualizarAluno(Aluno lista[], int qtd);
void excluirAluno(Aluno lista[], int qtd);
void matricularAlunoEmDisciplina(Aluno listaAluno[], int qtdAluno, Disciplina listaDisc[], int qtdDisc);
void listarAlunosPorSexo(Aluno lista[], int qtd, char sexo);
void listarAlunosOrnemadosPorNome(Aluno lista[], int qtd);
void listarAlunosPorDataNascimento(Aluno lista[], int qtd);
void listarAlunosMatriculadosEmMenosDe3Disciplinas(Aluno listaAluno[], int qtdAluno, Disciplina listaDisc[], int qtdDisc);

int menuProfessor();
void cadastrarProfessor(Professor lista[], int *qtd);
void listarProfessores(Professor lista[], int qtd);
void atualizarProfessor(Professor lista[], int qtd);
void excluirProfessor(Professor lista[], int qtd);
void listarProfessoresPorSexo(Professor lista[], int qtd, char sexo);
void listarProfessoresPorNome(Professor lista[], int qtd);
void listarProfessoresPorDataNascimento(Professor lista[], int qtd);

int menuDisciplina();
void cadastrarDisciplina(Disciplina listaDisc[], int *qtdDisc, Professor listaProf[], int qtdProf);
void listarDisciplinas(Disciplina listaDisc[], int qtdDisc, Professor listaProf[], int qtdProf);
void atualizarDisciplina(Disciplina listaDisc[], int qtdDisc, Professor listaProf[], int qtdProf);
void excluirDisciplina(Disciplina listaDisc[], int qtdDisc);
void listarDisciplinaComAlunos(Disciplina listaDisc[], int qtdDisc, Aluno listaAluno[], int qtdAluno);

#endif 