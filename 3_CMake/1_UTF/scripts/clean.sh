#!/bin/bash
# scripts/clean.sh

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BIN_DIR="$PROJECT_DIR/bin"

echo "🧹 Limpando arquivos gerados..."

# Remover executáveis
if [ -d "$BIN_DIR" ]; then
    echo "Removendo executáveis em $BIN_DIR/"
    rm -f "$BIN_DIR"/* 2>/dev/null || true
    rmdir "$BIN_DIR" 2>/dev/null || true
fi

# Remover arquivos objeto (.o) se existirem
find "$PROJECT_DIR" -name "*.o" -type f -delete 2>/dev/null || true
find "$PROJECT_DIR" -name "*.out" -type f -delete 2>/dev/null || true

echo "✅ Limpeza concluída!"
