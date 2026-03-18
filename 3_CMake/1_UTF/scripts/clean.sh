#!/usr/bin/env bash
set -euo pipefail

# scripts/clean.sh
PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_DIR="$PROJECT_DIR/bin"

echo "🧹  Limpando arquivos gerados..."

if [ -d "$BIN_DIR" ]; then
    echo "   Removendo $BIN_DIR/..."
    rm -rf "$BIN_DIR"
fi

# Limpar objetos soltos na raiz ou src (se alguém compilar manualmente)
find "$PROJECT_DIR" -maxdepth 3 \( -name "*.o" -o -name "*.out" -o -name "*.exe" \) -type f -delete 2>/dev/null || true

echo "✅  Limpeza finalizada!"
