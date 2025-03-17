#include <stdio.h>

/**
 * #pragma push_macro: é utilizada para salvar o valor atual de uma macro específica na
 * pilha interna do compilador. Isso permite modificar temporariamente o comportamento de
 * uma macro sem perder o valor original, facilitando a restauração posterior ao estado
 * original da macro.
 */

#define PI 3.14159265359

int main(int argc, char **argv)
{
    printf("Valor de PI: %f\n", PI);

#pragma push_macro("PI")
#undef PI
#define PI 3.14

    printf("Valor de PI modificado temporariamente: %f\n", PI);

#pragma pop_macro("PI")

    printf("Valor de PI restaurado: %f\n", PI); // Retorna ao valor original

    /**
     * #pragma push_macro: é uma ferramenta útil para manipular temporariamente o valor de
     * macros em C, permitindo alterações temporárias que são restauradas de forma segura
     * usando #pragma pop_macro.
     */
    return 0;
}
