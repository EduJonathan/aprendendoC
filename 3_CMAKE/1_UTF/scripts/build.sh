#!/usr/bin/env bash
set -euo pipefail

# scripts/build.sh
PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
SRC_DIR="$PROJECT_DIR/src"
BIN_DIR="$PROJECT_DIR/bin"
EXECUTABLE_BASE="utf"
EXECUTABLE="$EXECUTABLE_BASE"

# Detectar Windows para extensão
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" || "$OSTYPE" == "win32" ]]; then
    EXECUTABLE="${EXECUTABLE_BASE}.exe"
fi

echo "🛠️  Iniciando compilação..."
echo "📁  Projeto: $PROJECT_DIR"

mkdir -p "$BIN_DIR"

# Escolher compilador
if command -v clang >/dev/null 2>&1; then
    COMPILER="clang"
elif command -v gcc >/dev/null 2>&1; then
    COMPILER="gcc"
else
    echo "❌ Nenhum compilador encontrado (precisa de gcc ou clang)"
    exit 1
fi

echo "🔧 Compilador: $COMPILER"

# Compilar (adicionando -O2 para Release-like)
echo "📦 Compilando src/main.c → bin/$EXECUTABLE"
"$COMPILER" -Wall -Wextra -Wpedantic -std=c11 \
    -O2 \
    -o "$BIN_DIR/$EXECUTABLE" \
    "$SRC_DIR/main.c"

if [ $? -eq 0 ]; then
    echo "✅ Compilação concluída!"
    ls -lh "$BIN_DIR/$EXECUTABLE" 2>/dev/null || true
    chmod +x "$BIN_DIR/$EXECUTABLE" 2>/dev/null || true
else
    echo "❌ Falha na compilação"
    exit 1
fi
