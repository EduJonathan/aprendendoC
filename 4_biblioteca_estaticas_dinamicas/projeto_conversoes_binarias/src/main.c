#include <stdio.h>
#include <string.h>
#include "../include/converter.h"

/**
 * PARA COMPILAR, esteja dentro do projeto (pasta projeto_conversoes_binarias) e use:
 *
 * - gcc -c src/converter.c -Iinclude -o obj/converter.o
 * - ar rcs lib/libconverter.a obj/converter.o
 * - gcc src/main.c -Iinclude -Llib -lconverter -o conversor_final
 */

typedef struct
{
    long input;
    BaseType target;
    const char *expected;
} ConversionTestCase;

void run_tests(const ConversionTestCase *tests, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        ConversionResult *res = create_conversion(tests[i].input, tests[i].target);

        printf("Teste %zu: %ld -> base %d | ",
               i + 1,
               tests[i].input,
               tests[i].target);

        if (!res)
        {
            printf("FALHA (conversao retornou NULL)\n");
            continue;
        }

        if (strcmp(res->output, tests[i].expected) == 0)
        {
            printf("OK (%s)\n", res->output);
        }
        else
        {
            printf("ERRO (esperado: %s | obtido: %s)\n", tests[i].expected, res->output);
        }

        free_conversion(res);
    }
}

int main(int argc, char **argv)
{
    ConversionTestCase tests[] = {
        {0, BASE_BIN, "0"},
        {1, BASE_BIN, "1"},
        {2, BASE_BIN, "10"},
        {10, BASE_DEC, "10"},
        {10, BASE_HEX, "A"},
        {255, BASE_HEX, "FF"},
        {255, BASE_OCT, "377"},
        {-255, BASE_BIN, "-11111111"},
        {-255, BASE_HEX, "-FF"},
    };

    size_t test_count = sizeof(tests) / sizeof(tests[0]);
    run_tests(tests, test_count);

    return 0;
}
