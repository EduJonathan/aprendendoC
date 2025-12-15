#!/bin/bash
# scripts/run.sh

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_DIR="$PROJECT_DIR/bin"
EXECUTABLE="utf"

# Configurar UTF-8 baseado no sistema
case "$(uname -s)" in
    Linux*|Darwin*)
        # Linux e macOS
        export LC_ALL="en_US.UTF-8" 2>/dev/null || true
        export LANG="en_US.UTF-8" 2>/dev/null || true
        EXEC_PATH="$BIN_DIR/$EXECUTABLE"
        ;;
    CYGWIN*|MINGW*|MSYS*)
        # Windows (Git Bash, MSYS2, Cygwin)
        EXEC_PATH="$BIN_DIR/${EXECUTABLE}.exe"
        ;;
    *)
        EXEC_PATH="$BIN_DIR/$EXECUTABLE"
        ;;
esac

# Verificar se o executável existe
if [ ! -f "$EXEC_PATH" ]; then
    echo "⚠️  Executável não encontrado: $EXEC_PATH"
    echo "📦 Compilando primeiro..."
    
    # Executar script de build
    "$PROJECT_DIR/scripts/build.sh"
    
    if [ ! -f "$EXEC_PATH" ]; then
        echo "❌ Falha ao criar executável"
        exit 1
    fi
fi

echo "🚀 Executando programa..."
echo "═══════════════════════════════════════════"

# Executar o programa
if [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "cygwin" ]]; then
    # Windows - configurar UTF-8 no cmd
    chcp 65001 > /dev/null 2>&1
    "$EXEC_PATH"
else
    "$EXEC_PATH"
fi

EXIT_CODE=$?

echo "═══════════════════════════════════════════"
if [ $EXIT_CODE -eq 0 ]; then
    echo "✅ Programa executado com sucesso!"
else
    echo "⚠️  Programa retornou código: $EXIT_CODE"
fi
