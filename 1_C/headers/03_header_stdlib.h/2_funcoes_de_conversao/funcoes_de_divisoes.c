#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Tipos de divisão inteira suportados
 */
typedef enum
{
    DIV_INT,   // div    → int
    DIV_LONG,  // ldiv   → long
    DIV_LLONG, // lldiv  → long long
    DIV_COUNT
} DivType;

/**
 * @brief Metadados de cada tipo de divisão
 */
typedef struct
{
    DivType type;
    const char *name;        // para impressão
    const char *type_suffix; // sufixo para printf (%d, %ld, %lld)
} DivMetadata;

const DivMetadata DIV_LOOKUP[DIV_COUNT] = {
    [DIV_INT] = {DIV_INT, "div_t", "%d"},
    [DIV_LONG] = {DIV_LONG, "ldiv_t", "%ld"},
    [DIV_LLONG] = {DIV_LLONG, "lldiv_t", "%lld"},
};

/**
 * @brief Estrutura genérica para armazenar quociente e resto
 * (evita duplicar código para cada tipo)
 */
typedef struct
{
    long long quot;
    long long rem;
} DivResult;

/**
 * @brief Executa a divisão de acordo com o tipo escolhido
 *
 * @param num   Numerador
 * @param den   Denominador
 * @param type  Tipo de divisão (int/long/long long)
 * @return Estrutura com quociente e resto
 * @note Não verifica divisão por zero (comportamento indefinido, como na libc)
 */
DivResult compute_div(long long num, long long den, DivType type)
{
    DivResult res = {0, 0};

    switch (type)
    {
    case DIV_INT:
    {
        div_t d = div((int)num, (int)den);
        res.quot = d.quot;
        res.rem = d.rem;
        break;
    }

    case DIV_LONG:
    {
        ldiv_t d = ldiv(num, den); // long → já cabe em long long
        res.quot = d.quot;
        res.rem = d.rem;
        break;
    }

    case DIV_LLONG:
    {
        lldiv_t d = lldiv(num, den);
        res.quot = d.quot;
        res.rem = d.rem;
        break;
    }

    default:
        // Pode adicionar erro aqui se quiser
        break;
    }

    return res;
}

/**
 * @brief Imprime o resultado da divisão de forma genérica
 *
 * @param numerador   Numerador
 * @param denominador Denominador
 * @param type        Tipo de divisão
 */
void print_div_result(long long numerador, long long denominador, DivType type)
{
    if (type >= DIV_COUNT)
    {
        printf("[ERRO] Tipo de divisão inválido\n\n");
        return;
    }

    const DivMetadata *meta = &DIV_LOOKUP[type];

    printf("%s\n", meta->name);

    // Proteção básica contra divisão por zero (opcional)
    if (denominador == 0)
    {
        printf("  ERRO: Divisão por zero indefinida!\n\n");
        return;
    }

    DivResult res = compute_div(numerador, denominador, type);

    printf("  Quociente: ");
    printf(meta->type_suffix, res.quot);
    printf("\n");

    printf("  Resto:     ");
    printf(meta->type_suffix, res.rem);
    printf("\n\n");
}

int main(int argc, char **argv)
{
    printf("Exemplos de div, ldiv e lldiv\n");
    printf("================================\n\n");

    print_div_result(15, 4, DIV_INT);
    print_div_result(123456L, 789L, DIV_LONG);
    print_div_result(5LL, 5LL, DIV_LLONG);

    // Exemplos extras
    print_div_result(-17, 5, DIV_INT);
    print_div_result(0, 1, DIV_LONG);
    print_div_result(1000000000000LL, 7LL, DIV_LLONG);

    // Caso de erro (opcional)
    print_div_result(42, 0, DIV_INT);

    return 0;
}
