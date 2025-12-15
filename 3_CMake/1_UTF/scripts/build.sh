#!/bin/bash
# scripts/build.sh

# Configurações
PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC_DIR="$PROJECT_DIR/src"
BIN_DIR="$PROJECT_DIR/bin"
EXECUTABLE="utf"

echo "🛠️  Iniciando compilação..."
echo "📁 Diretório do projeto: $PROJECT_DIR"

# Criar diretório bin se não existir
mkdir -p "$BIN_DIR"

# Verificar compilador
if command -v gcc &> /dev/null; then
    COMPILER="gcc"
elif command -v clang &> /dev/null; then
    COMPILER="clang"
else
    echo "❌ Erro: Nenhum compilador encontrado (gcc/clang)"
    exit 1
fi

echo "🔧 Compilador: $COMPILER"

# Compilar
echo "📦 Compilando $SRC_DIR/main.c..."
if [ "$COMPILER" = "gcc" ]; then
    $COMPILER -Wall -Wextra -std=c11 -o "$BIN_DIR/$EXECUTABLE" "$SRC_DIR/main.c"
else
    $COMPILER -Wall -Wextra -std=c11 -o "$BIN_DIR/$EXECUTABLE" "$SRC_DIR/main.c"
fi

# Verificar sucesso
if [ $? -eq 0 ]; then
    echo "✅ Compilação bem-sucedida!"
    echo "📄 Executável: $BIN_DIR/$EXECUTABLE"
    
    # Dar permissão de execução (Unix-like)
    chmod +x "$BIN_DIR/$EXECUTABLE" 2>/dev/null || true
    
    # Mostrar informações do arquivo
    echo "📊 Tamanho do executável:"
    ls -lh "$BIN_DIR/$EXECUTABLE" 2>/dev/null || \
    ls -l "$BIN_DIR/$EXECUTABLE.exe" 2>/dev/null || \
    echo "  (informações não disponíveis)"
else
    echo "❌ Falha na compilação"
    exit 1
fi
