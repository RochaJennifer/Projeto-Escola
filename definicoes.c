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
