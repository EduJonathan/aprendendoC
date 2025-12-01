#include <stdio.h>
#include <string.h>

/**
 * Diretivas para controle de avisos do compilador:
 *
 * 1. #pragma warning (MSVC):
 * - Controla avisos no Microsoft Visual C++ (MSVC).
 * - Sintaxe:
 *   - #pragma warning(push): Salva o estado atual dos avisos.
 *   - #pragma warning(disable : número): Desativa um aviso específico (ex.: 4996 para funções inseguras como strcpy).
 *   - #pragma warning(pop): Restaura o estado anterior.
 * - Uso: Suprimir avisos em blocos específicos (ex.: uso de funções obsoletas, variáveis não utilizadas).
 * - Suporte: Exclusivo do MSVC; ignorado por GCC/Clang.
 *
 * 2. #pragma GCC diagnostic (GCC/Clang):
 * - Controla avisos no GCC/Clang.
 * - Sintaxe:
 *   - #pragma GCC diagnostic kind "-Wflag": Define o comportamento de um aviso (kind: warning, error, ignored).
 *   - #pragma GCC diagnostic push/pop: Salva/restaura o estado dos diagnósticos.
 * - Exemplo: #pragma GCC diagnostic warning "-Wuninitialized" força avisos para variáveis não inicializadas.
 * - Suporte: Exclusivo do GCC/Clang; ignorado pelo MSVC.
 *
 * Portabilidade:
 * - Ambas as diretivas são extensões específicas, não padrão C (C11/C17/C23).
 * - Use #ifdef _MSC_VER ou #ifdef __GNUC__ para aplicar condicionalmente.
 *
 * Boas práticas:
 * - Suprima avisos apenas quando necessário, para não ocultar problemas reais.
 * - Prefira funções seguras (ex.: strncpy em vez de strcpy).
 * - Sempre balanceie push/pop para evitar alterações indesejadas nos avisos.
 * - Teste com -Wall (GCC) ou /W4 (MSVC) para detectar potenciais problemas.
 *
 * Compilação:
 * - GCC: gcc -std=c11 -Wall -Wextra -o teste pragma_warning.c
 * - MSVC: cl /W4 pragma_warning.c
 * - Depuração: gcc -E pragma_warning.c (verifica pré-processamento)
 */

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic warning "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#endif

/**
 * - #pragma warning(push) → No MSVC (Visual Studio Compiler), salva o estado atual das
 * advertências antes de desativar alguma.
 * 
 * - #pragma warning(disable : 4996) → No MSVC, desativa o aviso C4996, que geralmente ocorre
 * ao usar funções consideradas inseguras, como scanf() e strcpy().
 * 
 * - #pragma warning(pop) → Restaura os warnings para o estado anterior.
 */
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996) // Desativa aviso sobre strcpy
#endif

void usarStrcpy(void)
{
    char destino[10] = {0};

    // strcpy(destino, "Hello!"); // Inseguro, substituído por strncpy
    strncpy(destino, "Hello!", sizeof(destino) - 1);
    destino[sizeof(destino) - 1] = '\0'; // Garante terminação nula
    printf("String copiada: %s\n", destino);
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#ifdef _MSC_VER
#pragma warning(pop)
#endif

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4101) // Variável não utilizada
#endif

void funcaoComVariavel(void)
{
    int x; // Variável não utilizada
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif
#ifdef _MSC_VER
#pragma warning(pop)
#endif

int main(int argc, char **argv)
{
    int x; // Inicialize a variável para evitar comportamento indefinido
    printf("Valor de x: %d\n", x);

    usarStrcpy();
    funcaoComVariavel();

    /**
     * Aconselho a compilação para melhor resultado das diretivas em cada cenário com as seguinte linhas:
     * > gcc -Wall -O1 -std=c11 pragma_warning.c -o teste
     * > gcc -O3 -std=c11 pragma_warning.c -o teste
     * > gcc -O0 -std=c11 pragma_warning.c -o teste
     * > gcc -g -O0 -std=c11 pragma_warning.c -o teste
     * > gcc -Wall -Wextra -O1 -std=c11 pragma_warning.c -o teste
     * > gcc -Wall -Werror -std=c11 pragma_warning.c -o teste
     */
    return 0;
}
