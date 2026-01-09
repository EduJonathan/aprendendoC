#include <stdio.h>

/**
 * #pragma optimize: Diretiva específica do compilador MSVC (Microsoft Visual C++) para
 * controlar otimizações em seções específicas do código. Permite ativar/desativar otimizações
 * para ajustar desempenho, tamanho do código ou facilitar depuração.
 *
 * Sintaxe: #pragma optimize("opções", estado)
 * - Opções:
 *   - "g": Otimizações globais (ex.: inlining, eliminação de código morto).
 *   - "s": Otimiza para tamanho do código (menor binário).
 *   - "t": Otimiza para velocidade (desempenho).
 *   - "y": Habilita omissão do ponteiro de quadro (frame pointer omission).
 * - Estado: "on" (ativa) ou "off" (desativa).
 *
 * Exemplo:
 * - #pragma optimize("g", off): Desativa otimizações globais para uma função.
 * - #pragma optimize("g", on): Ativa otimizações globais.
 *
 * Limitações:
 * - Exclusiva do MSVC. GCC/Clang ignoram essa diretiva e usam #pragma GCC optimize
 *   (ex.: #pragma GCC optimize("O0") para desativar otimizações).
 * - Não é padrão C (C11/C17/C23), então afeta portabilidade.
 *
 * Alternativas para GCC/Clang:
 * - Use flags de linha de comando: -O0 (sem otimizações), -O1, -O2, -O3 (otimizações agressivas).
 * - Ou atributos: __attribute__((optimize("O0"))) por função.
 *
 * Boas práticas:
 * - Use apenas quando necessário (ex.: depuração ou código sensível a otimizações).
 * - Evite desativar otimizações globalmente, pois pode impactar desempenho.
 * - Para portabilidade, combine com #ifdef para alternar entre compiladores.
 *
 * Exemplo de compilação:
 * - MSVC: cl /O2 pragma_optimize.c
 * - GCC: gcc -std=c17 -O2 ou -O3 -o pragma_optimize pragma_optimize.c (ignora #pragma optimize)
 */

// Desativa otimizações ou #pragma GCC optimize("O0") para efeito nos compiladores(GCC/CLANG)
#pragma optimize("g", off)
void funcaoSemOtmizacao()
{
    printf("Esta função está sem otimizações.\n");
}

// Ativa otimizações ou #pragma GCC optimize("O3") para efeito nos compiladores(GCC/CLANG)
#pragma optimize("g", on)
void funcaoComOtmizacao()
{
    printf("Esta função está com otimizações.\n");
}

int main(int argc, char **argv)
{
    funcaoSemOtmizacao();
    funcaoComOtmizacao();

    /**
     * Compile com a seguintes flags:
     *
     * gcc pragma_optimize.c -o pragma_optimize -O2
     * gcc pragma_optimize.c -o pragma_optimize -O3
     *
     * Note que o #pragma optimize é específico do compilador MSVC e não é
     * parte do padrão C. Portanto, se você estiver usando outro compilador, como o GCC,
     * você deve usar as opções de linha de comando apropriadas para controlar as otimizações.
     */
    return 0;
}
