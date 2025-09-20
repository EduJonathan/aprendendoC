#include <stdio.h>

/**
 * Uso de #pragma GCC diagnostic:
 *
 * A diretiva `#pragma GCC diagnostic` é usada no GCC/Clang para controlar mensagens de diagnóstico
 * (avisos ou erros) geradas durante a compilação. Ela permite ativar, desativar ou tratar avisos
 * como erros de forma seletiva, sendo especialmente útil para gerenciar avisos em seções
 * específicas do código sem afetar todo o projeto.
 *
 * - `#pragma GCC diagnostic ignored "-Wflag"`: Suprime o aviso especificado pela flag (ex.: "-Wdeprecated-declarations").
 * - `#pragma GCC diagnostic push`: Salva o estado atual dos diagnósticos, permitindo modificações temporárias.
 * - `#pragma GCC diagnostic pop`: Restaura o estado anterior dos diagnósticos.
 *
 * Exemplo prático: No código abaixo, suprimimos o aviso de uso de uma função obsoleta
 * (marcada com `__attribute__((deprecated))`) apenas para uma chamada específica, evitando
 * impactar outras partes do código.
 *
 * Nota: Esta diretiva é específica do GCC/Clang. Para outros compiladores (ex.: MSVC), use
 * alternativas como `#pragma warning`. Sempre consulte a documentação do compilador para
 * garantir portabilidade.
 */

// Função obsoleta marcada com __attribute__((deprecated))
__attribute__((deprecated("Use novaFuncao() em vez disso."))) void funcaoAntiga()
{
    printf("Esta é uma função obsoleta.\n");
}

int main(int argc, char **argv)
{
// Suprime temporariamente avisos de funções obsoletas
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

    funcaoAntiga(); // Chamada sem gerar aviso

#pragma GCC diagnostic pop // Restaura configurações de diagnóstico

    /**
     * Contexto de uso:
     * - O `#pragma GCC diagnostic` é útil em projetos legados ou ao integrar bibliotecas externas
     *   que geram avisos indesejados (ex.: funções obsoletas).
     * - Evite suprimir avisos globalmente (ex.: com -Wno-deprecated-declarations) para manter
     *   a visibilidade de problemas em outras partes do código.
     *
     * Flags de compilação relacionadas:
     * - `-Wall` e `-Wextra`: Ativam avisos, incluindo `-Wdeprecated-declarations`.
     * - `-Werror`: Transforma avisos em erros, exigindo o uso de `#pragma` para compilar.
     * - `-Wno-deprecated-declarations`: Desativa globalmente avisos de depreciação (menos granular).
     *
     * Exemplos de compilação:
     * - Básico com depuração: `gcc -std=c17 -Wall -Wextra -g -o exemplo pragma_gcc.c`
     * - Rigoroso com erros: `gcc -std=c17 -Wall -Wextra -Wpedantic -Werror -g -Og -o exemplo pragma_gcc.c`
     * - Otimizado: `gcc -std=c17 -O3 -march=native -flto -o exemplo pragma_gcc.c`
     * - Paralelismo: `gcc -std=c17 -O3 -fopenmp -march=native -o exemplo pragma_gcc.c`
     *
     * Cuidado:
     * - Suprimir avisos pode ocultar problemas reais. Use `#pragma GCC diagnostic` apenas quando
     *   necessário e justificado (ex.: código legado ou bibliotecas de terceiros).
     * - Verifique a compatibilidade com o compilador e versão usada.
     */

    return 0;
}
