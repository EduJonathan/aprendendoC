#include "pragma_once.h"

/**
 * #pragma once: Diretiva de pré-processador usada em arquivos de cabeçalho (.h) para
 * garantir que o arquivo seja incluído apenas uma vez durante a compilação. Evita erros
 * de múltipla inclusão, como redefinição de símbolos (ex.: funções ou variáveis).
 *
 * Vantagens:
 * - Sintaxe simples, reduzindo erros em comparação com guardas de inclusão tradicionais
 *   (#ifndef, #define, #endif).
 * - Pode ser mais eficiente em compiladores modernos (GCC, Clang, MSVC).
 *
 * Desvantagens:
 * - Não é padrão C (C11/C17/C23), sendo uma extensão de compilador. Alguns compiladores
 *   menos comuns podem não suportar.
 * - Menos flexível que guardas de inclusão para casos complexos (ex.: inclusão condicional).
 *
 * Uso recomendado:
 * - Aplique em arquivos de cabeçalho (.h) para declarar funções, structs ou macros.
 * - Para máxima portabilidade, considere usar guardas de inclusão tradicionais:
 *   #ifndef NOME_DO_ARQUIVO_H
 *   #define NOME_DO_ARQUIVO_H
 *   // Conteúdo
 *   #endif
 *
 * Verificação:
 * - Use `gcc -E arquivo.c` para inspecionar o resultado do pré-processamento e confirmar
 *   que o arquivo de cabeçalho foi incluído apenas uma vez.
 *
 * Testar o programa
 * - gcc -std=c17 -Wall -o programa pragma_once_main.c
 *
 * Exemplo:
 * - Arquivo `pragma_once.h` com `#pragma once` contém a declaração de `minhaFuncao`.
 * - Este arquivo (`pragma_once_main.c`) inclui `pragma_once.h` e define a função.
 */

void minhaFuncao()
{
    printf("Executando minhaFuncao!\n");
}

int main(int argc, char **argv)
{
    minhaFuncao();
    return 0;
}
