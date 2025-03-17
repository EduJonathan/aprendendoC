#include <stdio.h>
#include <stdint.h>
#include <inttypes.h> // ou #include <stdint.h>

/**
 * inttypes.h: É utilizada para fornecer tipos inteiros com largura específica (exatas) e
 * especificadores de formato correspondentes para a impressão e a leitura desses tipos.
 * Oferecendo suporte a uma programação mais portável e segura, garantindo que os tipos de
 * dados inteiros tenham tamanhos específicos em diferentes arquiteturas.
 */

/**
 * @brief Função para imprimir os tamanhos dos tipos de dados
 */
void imprimirTamanhos(void)
{
    printf("\n\t\t>>TAMANHO EM BYTES<<\n");

    printf(" Tamanho de int8_t :  %zu bytes\n", sizeof(int8_t));
    printf(" Tamanho de int16_t : %zu bytes\n", sizeof(int16_t));
    printf(" Tamanho de int32_t : %zu bytes\n", sizeof(int32_t));
    printf(" Tamanho de int64_t : %zu bytes\n", sizeof(int64_t));
    putchar('\n');

    printf(" Tamanho de uint8_t :  %zu bytes\n", sizeof(uint8_t));
    printf(" Tamanho de uint16_t : %zu bytes\n", sizeof(uint16_t));
    printf(" Tamanho de uint32_t : %zu bytes\n", sizeof(uint32_t));
    printf(" Tamanho de uint64_t : %zu bytes\n", sizeof(uint64_t));
    putchar('\n');

    printf(" Tamanho de int_least8_t :  %zu bytes\n", sizeof(int_least8_t));
    printf(" Tamanho de int_least16_t : %zu bytes\n", sizeof(int_least16_t));
    printf(" Tamanho de int_least32_t : %zu bytes\n", sizeof(int_least32_t));
    printf(" Tamanho de int_least64_t : %zu bytes\n", sizeof(int_least64_t));
    putchar('\n');

    printf(" Tamanho de uint_least8_t :  %zu bytes\n", sizeof(uint_least8_t));
    printf(" Tamanho de uint_least16_t : %zu bytes\n", sizeof(uint_least16_t));
    printf(" Tamanho de uint_least32_t : %zu bytes\n", sizeof(uint_least32_t));
    printf(" Tamanho de uint_least64_t : %zu bytes\n", sizeof(uint_least64_t));
    putchar('\n');

    printf(" Tamanho de int_fast8_t :  %zu bytes\n", sizeof(int_fast8_t));
    printf(" Tamanho de int_fast16_t : %zu bytes\n", sizeof(int_fast16_t));
    printf(" Tamanho de int_fast32_t : %zu bytes\n", sizeof(int_fast32_t));
    printf(" Tamanho de int_fast64_t : %zu bytes\n", sizeof(int_fast64_t));
    putchar('\n');

    printf(" Tamanho de uint_fast8_t :  %zu bytes\n", sizeof(uint_fast8_t));
    printf(" Tamanho de uint_fast16_t : %zu bytes\n", sizeof(uint_fast16_t));
    printf(" Tamanho de uint_fast32_t : %zu bytes\n", sizeof(uint_fast32_t));
    printf(" Tamanho de uint_fast64_t : %zu bytes\n", sizeof(uint_fast64_t));
}

/**
 *  @brief Função para imprimir os valores mínimos e máximos dos tipos de dados
 */
void imprimirValoresMinMax(void)
{
    printf("\n\t>>IMPRIMINDO OS VALORES MÍNIMOS E MÁXIMOS<<\n");

    printf(" INT8_MIN  :  %" PRId8 "\n", INT8_MIN);
    printf(" INT8_MAX  :  %" PRId8 "\n", INT8_MAX);
    printf(" UINT8_MAX :  %" PRIu8 "\n", UINT8_MAX);
    putchar('\n');

    printf(" INT16_MIN  :  %" PRId16 "\n", INT16_MIN);
    printf(" INT16_MAX  :  %" PRId16 "\n", INT16_MAX);
    printf(" UINT16_MAX :  %" PRIu16 "\n", UINT16_MAX);
    putchar('\n');

    printf(" INT32_MIN  :  %" PRId32 "\n", INT32_MIN);
    printf(" INT32_MAX  :  %" PRId32 "\n", INT32_MAX);
    printf(" UINT32_MAX :  %" PRIu32 "\n", UINT32_MAX);
    putchar('\n');

    printf(" INT64_MIN  :  %" PRId64 "\n", INT64_MIN);
    printf(" INT64_MAX  :  %" PRId64 "\n", INT64_MAX);
    printf(" UINT64_MAX :  %" PRIu64 "\n", UINT64_MAX);
    putchar('\n');

    // Tipos de largura mínima
    printf(" INT_LEAST8_MIN : %" PRIdLEAST8 "\n", INT_LEAST8_MIN);
    printf(" INT_LEAST8_MAX : %" PRIdLEAST8 "\n", INT_LEAST8_MAX);
    putchar('\n');

    // Tipos de largura mínima mais rápidos
    printf(" INT_FAST8_MIN : %" PRIdFAST8 "\n", INT_FAST8_MIN);
    printf(" INT_FAST8_MAX : %" PRIdFAST8 "\n", INT_FAST8_MAX);
    putchar('\n');

    // Tipos de largura máxima
    printf(" INTMAX_MIN  :  %" PRIdMAX "\n", INTMAX_MIN);
    printf(" INTMAX_MAX  :  %" PRIdMAX "\n", INTMAX_MAX);
    printf(" UINTMAX_MAX :  %" PRIuMAX "\n", UINTMAX_MAX);
    putchar('\n');

    // Inteiros que podem conter valores de ponteiro
    printf(" INTPTR_MIN  :  %" PRIdPTR "\n", INTPTR_MIN);
    printf(" INTPTR_MAX  :  %" PRIdPTR "\n", INTPTR_MAX);
    printf(" UINTPTR_MAX :  %" PRIuPTR "\n", UINTPTR_MAX);
    putchar('\n');

    // Outras constantes
    printf(" PTRDIFF_MIN : %" PRIdPTR "\n", PTRDIFF_MIN);
    printf(" PTRDIFF_MAX : %" PRIdPTR "\n", PTRDIFF_MAX);
    putchar('\n');

    printf(" SIG_ATOMIC_MIN : %" PRId32 "\n", SIG_ATOMIC_MIN);
    printf(" SIG_ATOMIC_MAX : %" PRId32 "\n", SIG_ATOMIC_MAX);
    putchar('\n');

    printf(" WCHAR_MIN : %" PRId32 "\n", WCHAR_MIN);
    printf(" WCHAR_MAX : %" PRId32 "\n", WCHAR_MAX);
    putchar('\n');

    printf(" WINT_MIN : %" PRId32 "\n", WINT_MIN);
    printf(" WINT_MAX : %" PRId32 "\n", WINT_MAX);
    putchar('\n');

    printf(" SIZE_MAX : %" PRIuMAX "\n", SIZE_MAX);
}

int main(int argc, char **argv)
{
    // Chama a função para imprimir tamanhos dos tipos de dados
    imprimirTamanhos();

    // Chama a função para imprimir valores mínimos e máximos dos tipos de dados
    imprimirValoresMinMax();
    return 0;
}
