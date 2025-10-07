# Nome do compilador C
CC = gcc

# Flags de compilação:
# -Wall e -Wextra: Ativa praticamente todos os avisos do compilador (boas práticas)
# -g3: Adiciona informações de debug para usar com o gdb
# -I.: Diz ao compilador para procurar por arquivos de cabeçalho (#include) no diretório atual
CFLAGS = -Wall -Wextra -g3 -I.

# Diretório onde o executável será salvo
OUTPUT_DIR = output

# Nome do arquivo executável final
EXEC = $(OUTPUT_DIR)/escola

# Encontra todos os arquivos fonte .c no diretório atual
SRCS = $(wildcard *.c)

# Gera os nomes dos arquivos objeto (.o) a partir dos arquivos fonte (.c)
# Ex: Projeto_Escola.c -> Projeto_Escola.o
OBJS = $(SRCS:.c=.o)

# ----------------- REGRAS (TARGETS) -----------------

# A primeira regra é a padrão, executada quando você digita apenas "make"
# Depende do executável final
all: $(EXEC)

# Regra para criar o executável final (linkagem)
# Depende de todos os arquivos objeto (.o) e do diretório de saída
$(EXEC): $(OBJS) | $(OUTPUT_DIR)
	@echo "=> Linkando para criar o executável final: $@"
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Regra para criar o diretório de saída, se ele não existir
$(OUTPUT_DIR):
	@echo "=> Criando diretório de saída: $(OUTPUT_DIR)"
	mkdir -p $(OUTPUT_DIR)

# Regra padrão para compilar arquivos .c em arquivos .o
# Qualquer arquivo .o depende do seu .c correspondente e do cabeçalho definicoes.h
# Se definicoes.h mudar, todos os arquivos serão recompilados.
%.o: %.c definicoes.h
	@echo "=> Compilando $< para $@"
	$(CC) $(CFLAGS) -c -o $@ $<

# Regra "clean" para limpar os arquivos gerados (objetos e executável)
clean:
	@echo "=> Limpando arquivos compilados..."
	rm -f $(OBJS) $(EXEC)

# Regra "run" para compilar e executar o programa
run: all
	@echo "=> Executando o projeto..."
	./$(EXEC)

# Declara que 'all', 'clean' e 'run' não são nomes de arquivos
.PHONY: all clean run