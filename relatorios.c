#include <stdio.h>
#include <string.h>
#include "definicoes.h"

int menuRelatorios() {
    int opcao;
    printf("\n-- Menu Relatórios --\n");
    printf("1 - Listar Aniversariantes do Mês\n");
    printf("2 - Buscar Pessoa por Nome\n");
    printf("0 - Voltar\n");
    printf("Digite sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

void listarAniversariantesDoMes(Aluno listaAluno[], int qtdAluno, Professor listaProf[], int qtdProf) {
    int mesAtual = 10;
    int encontrados = 0;

    printf("\n-- Aniversariantes de Outubro --\n");

    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].dados.ativo && listaAluno[i].dados.dataNascimento.mes == mesAtual) {
            printf("Tipo: Aluno | Matrícula: %d | Nome: %s | Data Nasc: %02d/%02d/%d\n",
                   listaAluno[i].dados.matricula,
                   listaAluno[i].dados.nome,
                   listaAluno[i].dados.dataNascimento.dia,
                   listaAluno[i].dados.dataNascimento.mes,
                   listaAluno[i].dados.dataNascimento.ano);
            encontrados++;
        }
    }

    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].dados.ativo && listaProf[i].dados.dataNascimento.mes == mesAtual) {
            printf("Tipo: Professor | Matrícula: %d | Nome: %s | Data Nasc: %02d/%02d/%d\n",
                   listaProf[i].dados.matricula,
                   listaProf[i].dados.nome,
                   listaProf[i].dados.dataNascimento.dia,
                   listaProf[i].dados.dataNascimento.mes,
                   listaProf[i].dados.dataNascimento.ano);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum aniversariante encontrado para o mês de Outubro.\n");
    }
}

void buscarPorNome(Aluno listaAluno[], int qtdAluno, Professor listaProf[], int qtdProf) {
    char busca[100];
    int encontrados = 0;

    printf("\n-- Busca por Nome --\n");
    printf("Digite pelo menos 3 letras do nome: ");
    limparBuffer();
    fgets(busca, 100, stdin);
    busca[strcspn(busca, "\n")] = 0; 

    if (strlen(busca) < 3) {
        printf("ERRO: É necessário digitar no mínimo 3 letras para a busca.\n");
        return;
    }

    printf("\n-- Resultados da Busca por '%s' --\n", busca);

    for (int i = 0; i < qtdAluno; i++) {
        if (listaAluno[i].dados.ativo && strstr(listaAluno[i].dados.nome, busca) != NULL) {
            printf("Tipo: Aluno | Matrícula: %d | Nome: %s\n",
                   listaAluno[i].dados.matricula,
                   listaAluno[i].dados.nome);
            encontrados++;
        }
    }

    for (int i = 0; i < qtdProf; i++) {
        if (listaProf[i].dados.ativo && strstr(listaProf[i].dados.nome, busca) != NULL) {
            printf("Tipo: Professor | Matrícula: %d | Nome: %s\n",
                   listaProf[i].dados.matricula,
                   listaProf[i].dados.nome);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhuma pessoa encontrada com o termo '%s'.\n", busca);
    }
}