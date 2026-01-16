#include <stdio.h>
#include <stdlib.h>   // Para abs, labs, llabs (caso precise comparar)
#include <inttypes.h> // imaxabs, imaxdiv, strtoimax, strtoumax, wcstoimax, wcstoumax
#include <wchar.h>    // Para wcstoumax, wcstoimax (wchar_t)
#include <errno.h>    // Para errno e strerror
#include <string.h>   // Para strerror

/**
 * @brief Tipos de funções do <inttypes.h> suportadas
 */
typedef enum
{
    IMAX_ABS,      // imaxabs
    IMAX_DIV,      // imaxdiv
    STR_TO_IMAX,   // strtoimax
    STR_TO_UMAX,   // strtoumax
    WCSTR_TO_IMAX, // wcstoimax
    WCSTR_TO_UMAX, // wcstoumax
    IMAX_COUNT
} ImaxType;

/**
 * @brief Metadados para cada tipo de função
 */
typedef struct
{
    ImaxType type;
    const char *name;        // Nome da função (para impressão)
    const char *format_spec; // Especificador printf para intmax_t/uintmax_t
    int is_unsigned;         // 1 se o retorno é unsigned
    int needs_base;          // 1 se a função aceita parâmetro 'base'
    int is_wide;             // 1 se usa wchar_t
} ImaxMetadata;

const ImaxMetadata IMAX_LOOKUP[IMAX_COUNT] = {
    [IMAX_ABS] = {IMAX_ABS, "imaxabs", "%" PRIdMAX, 0, 0, 0},
    [IMAX_DIV] = {IMAX_DIV, "imaxdiv", "%" PRIdMAX, 0, 0, 0},
    [STR_TO_IMAX] = {STR_TO_IMAX, "strtoimax", "%" PRIdMAX, 0, 1, 0},
    [STR_TO_UMAX] = {STR_TO_UMAX, "strtoumax", "%" PRIuMAX, 1, 1, 0},
    [WCSTR_TO_IMAX] = {WCSTR_TO_IMAX, "wcstoimax", "%" PRIdMAX, 0, 1, 1},
    [WCSTR_TO_UMAX] = {WCSTR_TO_UMAX, "wcstoumax", "%" PRIuMAX, 1, 1, 1},
};

/**
 * @brief Estrutura genérica para resultado de imaxdiv
 */
typedef struct
{
    intmax_t quot;
    intmax_t rem;
} ImaxDivResult;

/**
 * @brief Estrutura genérica para resultados das funções de conversão
 */
typedef struct
{
    intmax_t signed_val;
    uintmax_t unsigned_val;
    char *endptr_char;     // Para strto*
    wchar_t *endptr_wchar; // Para wcsto*
    int errno_val;
    ImaxType type;
} ImaxConvResult;

/**
 * @brief Calcula o valor absoluto (imaxabs)
 *
 * @param num Número inteiro de maior tamanho
 * @return Valor absoluto de num
 */
intmax_t compute_imaxabs(intmax_t num)
{
    return imaxabs(num);
}

/**
 * @brief Calcula divisão com resto (imaxdiv)
 *
 * @param numer Numerador
 * @param denom Denominador
 * @return Estrutura com quociente e resto
 */
ImaxDivResult compute_imaxdiv(intmax_t numer, intmax_t denom)
{
    ImaxDivResult res = {0, 0};
    if (denom == 0)
    {
        fprintf(stderr, "ERRO: Divisão por zero em imaxdiv!\n");
        return res;
    }
    imaxdiv_t d = imaxdiv(numer, denom);
    res.quot = d.quot;
    res.rem = d.rem;
    return res;
}

/**
 * @brief Converte string (char* ou wchar_t*) para intmax_t/uintmax_t
 *
 * @param str    String a converter (char* ou wchar_t*)
 * @param base   Base da conversão (0 = auto)
 * @param type   Tipo da função
 * @return Estrutura com resultado e status
 */
ImaxConvResult compute_imaxconv(const void *str_void, int base, ImaxType type)
{
    ImaxConvResult res = {.signed_val = 0, .unsigned_val = 0, .endptr_char = NULL, .endptr_wchar = NULL, .errno_val = 0, .type = type};

    if (str_void == NULL)
    {
        res.errno_val = EINVAL;
        return res;
    }

    const char *str_char = (const char *)str_void;
    const wchar_t *str_wide = (const wchar_t *)str_void;

    errno = 0;

    switch (type)
    {
    case STR_TO_IMAX:
        res.signed_val = strtoimax(str_char, &res.endptr_char, base);
        break;

    case STR_TO_UMAX:
        res.unsigned_val = strtoumax(str_char, &res.endptr_char, base);
        break;

    case WCSTR_TO_IMAX:
        res.signed_val = wcstoimax(str_wide, &res.endptr_wchar, base);
        break;

    case WCSTR_TO_UMAX:
        res.unsigned_val = wcstoumax(str_wide, &res.endptr_wchar, base);
        break;

    default:
        res.errno_val = EINVAL;
        break;
    }

    res.errno_val = errno;
    return res;
}

/**
 * @brief Imprime resultado de imaxabs
 *
 * @param num Número original
 */
void print_imaxabs(intmax_t num)
{
    intmax_t res = compute_imaxabs(num);
    printf("[imaxabs] Valor original: %" PRIdMAX "\n", num);
    printf("  Absoluto:          %" PRIdMAX "\n\n", res);
}

/**
 * @brief Imprime resultado de imaxdiv
 *
 * @param numer Numerador
 * @param denom Denominador
 */
void print_imaxdiv(intmax_t numer, intmax_t denom)
{
    if (denom == 0)
    {
        printf("[imaxdiv] ERRO: Divisão por zero!\n\n");
        return;
    }
    ImaxDivResult res = compute_imaxdiv(numer, denom);
    printf("[imaxdiv] %" PRIdMAX " / %" PRIdMAX "\n", numer, denom);
    printf("  Quociente: %" PRIdMAX "\n", res.quot);
    printf("  Resto:     %" PRIdMAX "\n\n", res.rem);
}

/**
 * @brief Imprime resultado de conversão
 *
 * @param str_void String original (char* ou wchar_t*)
 * @param base     Base da conversão
 * @param type     Tipo da função
 */
void print_imaxconv(const void *str_void, int base, ImaxType type)
{
    if (type >= IMAX_COUNT || (type != STR_TO_IMAX && type != STR_TO_UMAX && type != WCSTR_TO_IMAX && type != WCSTR_TO_UMAX))
    {
        printf("[ERRO] Tipo inválido para conversão\n\n");
        return;
    }

    const ImaxMetadata *meta = &IMAX_LOOKUP[type];
    ImaxConvResult res = compute_imaxconv(str_void, base, type);

    printf("[%s] ", meta->name);

    if (meta->is_wide)
        wprintf(L"\"%ls\"", (const wchar_t *)str_void);
    else
        printf("\"%s\"", (const char *)str_void);

    if (meta->needs_base)
        printf(" (base %d)", base);
    printf("\n");

    if (res.errno_val != 0)
    {
        printf("  ERRO: %s (código %d)\n", strerror(res.errno_val), res.errno_val);
    }

    if ((meta->is_wide && res.endptr_wchar && *res.endptr_wchar != L'\0') ||
        (!meta->is_wide && res.endptr_char && *res.endptr_char != '\0'))
    {
        if (meta->is_wide)
            wprintf(L"  Parou em: \"%ls\"\n", res.endptr_wchar);
        else
            printf("  Parou em: \"%s\"\n", res.endptr_char);
    }

    if (meta->is_unsigned)
        printf("  Resultado: %" PRIuMAX "\n", res.unsigned_val);
    else
        printf("  Resultado: %" PRIdMAX "\n", res.signed_val);

    printf("\n");
}

int main(int argc, char **argv)
{
    printf("=== Exemplos de funções do <inttypes.h> ===\n\n");

    // 1. imaxabs
    printf("VALORES ABSOLUTOS (imaxabs)\n");
    printf("----------------------------\n");
    print_imaxabs(123456789012345LL);
    print_imaxabs(-9223372036854775807LL - 1); // INTMAX_MIN (cuidado com overflow)

    // 2. imaxdiv
    printf("DIVISÃO COM RESTO (imaxdiv)\n");
    printf("----------------------------\n");
    print_imaxdiv(123456789012345LL, 987654321LL);
    print_imaxdiv(-100, 7);
    print_imaxdiv(42, 0); // Erro intencional

    // 3. Conversões (strtoimax, strtoumax, wcstoimax, wcstoumax)
    printf("CONVERSÕES DE STRING (strto*/wcsto*)\n");
    printf("-------------------------------------\n");

    // strtoimax / strtoumax
    print_imaxconv("  -1234567890123456789abc", 10, STR_TO_IMAX);
    print_imaxconv("  18446744073709551615", 10, STR_TO_UMAX); // UINTMAX_MAX
    print_imaxconv("999999999999999999999", 10, STR_TO_UMAX);  // Overflow
    print_imaxconv("0xCAFEBABE", 0, STR_TO_UMAX);              // Hex auto

    // wcstoimax / wcstoumax (usando strings largas)
    const wchar_t *wstr1 = L"  -987654321098765";
    const wchar_t *wstr2 = L"  1234567890xyz";
    print_imaxconv(wstr1, 10, WCSTR_TO_IMAX);
    print_imaxconv(wstr2, 10, WCSTR_TO_UMAX);

    return 0;
}
