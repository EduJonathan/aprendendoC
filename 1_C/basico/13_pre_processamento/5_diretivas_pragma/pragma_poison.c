#include <stdio.h>
#include <string.h>

/**
 * #pragma poison: Diretiva específica do GCC/Clang que marca identificadores (funções,
 * variáveis ou macros) como "venenosos", gerando um erro de compilação se forem usados.
 * É útil para:
 * - Prevenir o uso de funções inseguras (ex.: gets, strcpy) ou obsoletas.
 * - Enforçar boas práticas em projetos, especialmente em equipes grandes.
 * - Substituir código legado por alternativas seguras (ex.: usar fgets em vez de gets).
 *
 * Sintaxe: #pragma poison identificador1 identificador2 ...
 * - Exemplo: #pragma poison gets strcpy
 * - Efeito: Qualquer uso de gets ou strcpy resulta em erro de compilação.
 *
 * Limitações:
 * - Exclusivo do GCC/Clang. MSVC ignora e usa #pragma deprecated ou opções de compilação.
 * - Não é padrão C (C11/C17/C23), afetando portabilidade.
 * - Funções removidas do padrão (ex.: gets em C11) já geram erros sem #pragma poison.
 *
 * Alternativas:
 * - GCC/Clang: Use flags como -Wdeprecated-declarations ou -Werror=deprecated-declarations.
 * - MSVC: Use #pragma deprecated(gets) ou desative avisos com #pragma warning.
 * - Para portabilidade, combine com #ifdef __GNUC__.
 *
 * Boas práticas:
 * - Use para funções conhecidas como inseguras (ex.: gets, strcpy, strcat).
 * - Prefira alternativas seguras (ex.: fgets, strncpy) e documente a substituição.
 * - Teste com diferentes padrões C (ex.: -std=c99 vs. -std=c17) para verificar comportamento.
 *
 * Compilação:
 * - GCC: gcc -std=c17 -Wall -o programa pragma_poison.c
 * - Depuração: gcc -E pragma_poison.c (verifica pré-processamento)
 * gcc -std=c99 -Wall -o programa pragma_poison.c
 */

#ifdef __GNUC__
#pragma poison strcpy
#endif
#ifdef _MSC_VER
#pragma deprecated(strcpy)
#endif

#pragma poison gets

int main(int argc, char **argv)
{
    char buffer[100] = {0};
    const char *source = "Teste";

    strcpy(buffer, source); // Erro no GCC/Clang devido a #pragma poison
    // Aviso no MSVC devido a #pragma deprecated
    strncpy(buffer, source, sizeof(buffer) - 1); // Alternativa segura

    printf("Conteúdo do buffer: %s\n", buffer);

    char input[100] = {0}; // input para armazenar a entrada do usuário

    // Tentativa de usar 'gets' resultará em um erro ou aviso
    gets(input); // Deve gerar um aviso ou erro de compilação
    return 0;
}
