# Variáveis de Configuração
CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude
TARGET = log_analyzer
SRC_DIR = src
BUILD_DIR = build

# Arquivos fonte (lista de todos os .c em src/)
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Arquivos objeto (substitui .c por .o e move para o dir build)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# O alvo 'all' (o padrão) compila o executável
all: $(BUILD_DIR) $(TARGET)

# Cria o diretório de build se ele não existir
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# -----------------
# 1. Regra para o Executável Final
# Depende de todos os arquivos objeto
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# -----------------
# 2. Regra Genérica para Arquivos Objeto
# A regra abaixo diz: para criar um $(BUILD_DIR)/%.o, procure por $(SRC_DIR)/%.c
# $^ é a lista de pré-requisitos (apenas o .c neste caso, mas pode incluir .h)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# -----------------
# 3. Regra de Limpeza
# Remove os arquivos objeto e o executável
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# -----------------
# 4. Regra de Recompilação Completa (força o rebuild)
.PHONY: rebuild
rebuild: clean all
