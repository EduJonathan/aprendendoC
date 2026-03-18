#!/usr/bin/env bash
set -euo pipefail

# scripts/run.sh
PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_DIR="$PROJECT_DIR/bin"
EXECUTABLE_BASE="utf"
EXECUTABLE="$EXECUTABLE_BASE"

# Ajustar extensão no Windows
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" || "$OSTYPE" == "win32" ]]; then
    EXECUTABLE="${EXECUTABLE_BASE}.exe"
fi

EXEC_PATH="$BIN_DIR/$EXECUTABLE"

if [ ! -f "$EXEC_PATH" ]; then
    echo "⚠️  Executável não encontrado → compilando primeiro..."
    "$PROJECT_DIR/scripts/build.sh" || exit 1
fi

echo "🚀  Executando: $EXEC_PATH"
echo "═══════════════════════════════════════════"

# Tentar forçar UTF-8 no Windows (funciona melhor em cmd.exe)
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "cygwin" ]]; then
    chcp 65001 >/dev/null 2>&1 || true
fi

# Executar
"$EXEC_PATH"
EXIT_CODE=$?

echo "═══════════════════════════════════════════"

if [ $EXIT_CODE -eq 0 ]; then
    echo "✅  Execução concluída com sucesso"
else
    echo "⚠️  Programa terminou com código: $EXIT_CODE"
fi

exit $EXIT_CODE
