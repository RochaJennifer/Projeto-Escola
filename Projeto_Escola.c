#include <stdio.h>
#include <string.h>

#define TAM_ALUNO 3

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int matricula;
    char nome[100];
    char sexo;
    Data dataNascimento;
    char cpf[15];
    int ativo;
} Aluno;


int menuAluno();
void cadastrarAluno(Aluno lista[], int *qtd);
void limparBuffer();


int main(void) {
 
    Aluno listaAluno[TAM_ALUNO];
    int opcao;
    int qtdAluno = 0;
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
                             printf("\nListar Alunos (Ainda nao implementado)\n");
                             break;
                        }
                        default: {
                            printf("\nOpcao invalida!\n");
                            break;
                        }
                    }
                }
                break;
            }
            case 2:
                printf("\nMódulo Professor (Ainda nao implementado)\n");
                break;

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