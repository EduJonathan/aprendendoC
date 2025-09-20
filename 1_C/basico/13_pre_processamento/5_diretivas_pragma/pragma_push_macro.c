#include <stdio.h>

/**
 * #pragma push_macro e #pragma pop_macro: Diretivas de pré-processador usadas para salvar
 * e restaurar o estado de uma macro específica, permitindo alterações temporárias sem afetar
 * o valor original. São úteis em:
 * - Projetos complexos onde macros precisam ser redefinidas temporariamente (ex.: testes, compatibilidade).
 * - Bibliotecas que requerem configurações específicas de macros em blocos de código.
 *
 * Sintaxe:
 * - #pragma push_macro("nome"): Salva o estado atual da macro (definida ou indefinida) na pilha.
 * - #pragma pop_macro("nome"): Restaura o estado salvo da macro.
 *
 * Exemplo:
 * - #define PI 3.14159265359
 * - #pragma push_macro("PI") salva o valor de PI.
 * - #undef PI e #define PI 3.14 modifica temporariamente.
 * - #pragma pop_macro("PI") restaura PI ao valor original.
 *
 * Suporte:
 * - Compatível com MSVC, GCC, e Clang, mas não é padrão C (C11/C17/C23).
 * - Compiladores não suportados ignoram a diretiva, o que pode levar a redefinições permanentes.
 * - Use #ifdef __GNUC__ ou #ifdef _MSC_VER para portabilidade.
 *
 * Boas práticas:
 * - Sempre balanceie push_macro e pop_macro para evitar estados inconsistentes.
 * - Evite redefinir macros críticas globalmente; prefira alterações locais.
 * - Teste com gcc -E para verificar a expansão das macros.
 *
 * Compilação:
 * - GCC: gcc -std=c17 -Wall -o programa pragma_push_macro.c
 * - MSVC: cl pragma_push_macro.c
 * - Depuração: gcc -E pragma_push_macro.c (verifica pré-processamento)
 */

#define PI 3.14159265359
#define MAX 100

int main(int argc, char **argv)
{
    printf("Valor de PI: %f\n", PI);
    printf("Valor de MAX: %d\n", MAX);

#ifdef __GNUC__ // Suporte para GCC/Clang
#pragma push_macro("PI")
#pragma push_macro("MAX")
#elif defined(_MSC_VER) // Suporte para MSVC
#pragma push_macro("PI")
#pragma push_macro("MAX")
#else
#warning "Compilador não suporta #pragma push_macro; redefinição de macros pode ser permanente."
#endif

#undef PI
#define PI 3.14
#undef MAX
#define MAX 50

    printf("Valor de PI modificado: %f\n", PI);
    printf("Valor de MAX modificado: %d\n", MAX);

#ifdef __GNUC__
#pragma pop_macro("PI")
#pragma pop_macro("MAX")
#elif defined(_MSC_VER)
#pragma pop_macro("PI")
#pragma pop_macro("MAX")
#endif

    printf("Valor de PI restaurado: %f\n", PI);
    printf("Valor de MAX restaurado: %d\n", MAX);

    return 0;
}
