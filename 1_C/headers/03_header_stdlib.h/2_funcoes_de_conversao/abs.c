#include <stdio.h>
#include <stdlib.h> // abs, labs, llabs

/**
 * @brief Tipos de valor absoluto suportados
 */
typedef enum
{
    ABS_INT,   // abs     → int
    ABS_LONG,  // labs    → long
    ABS_LLONG, // llabs   → long long
    ABS_COUNT
} AbsType;

/**
 * @brief Metadados para cada tipo de valor absoluto
 */
typedef struct
{
    AbsType type;
    const char *name;        // Nome da função (para impressão)
    const char *format_spec; // Especificador de formato para printf
} AbsMetadata;

const AbsMetadata ABS_LOOKUP[ABS_COUNT] = {
    [ABS_INT]   = {ABS_INT,   "abs",   "%d"},
    [ABS_LONG]  = {ABS_LONG,  "labs",  "%ld"},
    [ABS_LLONG] = {ABS_LLONG, "llabs", "%lld"},
};

/**
 * @brief Calcula o valor absoluto de um número inteiro (qualquer tipo suportado).
 *
 * @param value  O valor a ser convertido em absoluto (passado como long long para cobrir todos os casos)
 * @param type   Tipo de valor absoluto desejado (ABS_INT, ABS_LONG ou ABS_LLONG)
 * @return O valor absoluto convertido para o tipo correspondente (retornado como long long)
 */
long long compute_abs(long long value, AbsType type)
{
    switch (type)
    {
    case ABS_INT:
        return abs((int)value); // Note: casting pode truncar se value for muito grande

    case ABS_LONG:
        return labs((long)value);

    case ABS_LLONG:
        return llabs(value);

    default:
        // Caso inválido → retorna 0 (ou poderia abortar com erro)
        return 0;
    }
}

/**
 * @brief Imprime o valor absoluto de um número de forma genérica.
 *
 * @param value  O número original
 * @param type   Tipo de valor absoluto (ABS_INT, ABS_LONG, ABS_LLONG)
 */
void print_abs_result(long long value, AbsType type)
{
    if (type >= ABS_COUNT)
    {
        printf("[ERRO] Tipo de absoluto inválido\n\n");
        return;
    }

    const AbsMetadata *meta = &ABS_LOOKUP[type];    // Obtém metadados
    long long resultado = compute_abs(value, type); // Calcula absoluto

    printf("Função: %s\n", meta->name);
    printf("  Valor original: ");
    printf(meta->format_spec, value);
    printf("\n");

    printf("  Valor absoluto: ");
    printf(meta->format_spec, resultado);
    printf("\n\n");
}

int main(int argc, char **argv)
{
    printf("=== Exemplos de valor absoluto (abs, labs, llabs) ===\n\n");

    // Exemplos com int
    print_abs_result(6, ABS_INT);
    print_abs_result(-14, ABS_INT);
    print_abs_result(0, ABS_INT);

    // Exemplos com long
    print_abs_result(-987654321L, ABS_LONG);
    print_abs_result(123456789L, ABS_LONG);

    // Exemplos com long long
    print_abs_result(564854LL, ABS_LLONG);
    print_abs_result(-9223372036854775807LL - 1, ABS_LLONG); // INT64_MIN (cuidado com overflow em algumas plataformas)

    // Exemplo de valor muito grande para int (mostra truncamento)
    printf("Aviso: valor muito grande para int:\n");
    print_abs_result(4000000000LL, ABS_INT); // Será truncado ao passar para abs()

    return 0;
}
