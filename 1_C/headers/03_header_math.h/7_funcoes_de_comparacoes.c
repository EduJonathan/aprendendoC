#include <stdio.h>
#include <math.h>

/* Enumeração das operações */
typedef enum
{
    MATH_FPCLASSIFY,
    MATH_ISINF,
    MATH_ISNAN,
    MATH_ISNORMAL,
    MATH_ISFINITE,
    MATH_ISGREATER,
    MATH_ISGREATEREQUAL,
    MATH_ISLESS,
    MATH_ISLESSEQUAL,
    MATH_ISLESSGREATER,
    MATH_ISUNORDERED,
    MATH_COUNT
} MathOpType;

typedef int (*UnaryFunc)(double);          // Ponteiro para função para quem depende de um argumento
typedef int (*BinaryFunc)(double, double); // Ponteiro para função para quem depende de dois argumentos

static int w_fpclassify(double x) { return fpclassify(x); }
static int w_isinf(double x) { return isinf(x); }
static int w_isnan(double x) { return isnan(x); }
static int w_isnormal(double x) { return isnormal(x); }
static int w_isfinite(double x) { return isfinite(x); }

static int w_isgreater(double x, double y) { return isgreater(x, y); }
static int w_isgreaterequal(double x, double y) { return isgreaterequal(x, y); }
static int w_isless(double x, double y) { return isless(x, y); }
static int w_islessequal(double x, double y) { return islessequal(x, y); }
static int w_islessgreater(double x, double y) { return islessgreater(x, y); }
static int w_isunordered(double x, double y) { return isunordered(x, y); }

/* Descrição da operação */
typedef struct
{
    MathOpType type;   // Tipo da operação
    const char *name;  // Nome da operação
    int arity;         // arity é para o número de argumentos (1 ou 2)
    UnaryFunc unary;   // Ponteiro para função unária
    BinaryFunc binary; // Ponteiro para função binária
} MathOperation;

/* Tabela central */
static const MathOperation ops[MATH_COUNT] =
    {
        {MATH_FPCLASSIFY, "fpclassify", 1, w_fpclassify, NULL},
        {MATH_ISINF, "isinf", 1, w_isinf, NULL},
        {MATH_ISNAN, "isnan", 1, w_isnan, NULL},
        {MATH_ISNORMAL, "isnormal", 1, w_isnormal, NULL},
        {MATH_ISFINITE, "isfinite", 1, w_isfinite, NULL},
        {MATH_ISGREATER, "isgreater", 2, NULL, w_isgreater},
        {MATH_ISGREATEREQUAL, "isgreaterequal", 2, NULL, w_isgreaterequal},
        {MATH_ISLESS, "isless", 2, NULL, w_isless},
        {MATH_ISLESSEQUAL, "islessequal", 2, NULL, w_islessequal},
        {MATH_ISLESSGREATER, "islessgreater", 2, NULL, w_islessgreater},
        {MATH_ISUNORDERED, "isunordered", 2, NULL, w_isunordered}};

/**
 * @brief Avalia a operação matemática.
 *
 * @param type Tipo da operação.
 * @param x Primeiro operando.
 * @param y Segundo operando (se aplicável).
 * @return Resultado da operação.
 */
static int math_eval(MathOpType type, double x, double y)
{
    const MathOperation *op = &ops[type];

    if (op->arity == 1)
        return op->unary(x);

    return op->binary(x, y);
}

/**
 * @brief Descreve a classificação de ponto flutuante.
 *
 * @param v Valor retornado por `fpclassify`.
 * @return Descrição textual.
 */
static const char *fp_desc(int v)
{
    switch (v)
    {
    case FP_NAN:
        return "NaN";

    case FP_INFINITE:
        return "Infinite";

    case FP_ZERO:
        return "Zero";

    case FP_SUBNORMAL:
        return "Subnormal";

    case FP_NORMAL:
        return "Normal";

    default:
        return "Unknown";
    }
}

/**
 * @brief Imprime o resultado da operação.
 *
 * @param type Tipo da operação.
 * @param x Primeiro operando.
 * @param y Segundo operando (se aplicável).
 */
static void print_result(MathOpType type, double x, double y)
{
    const MathOperation *op = &ops[type];
    int r = math_eval(type, x, y);

    if (op->arity == 1)
        printf("[%s](%.13g) → ", op->name, x);
    else
        printf("[%s](%.13g, %.13g) → ", op->name, x, y);

    if (type == MATH_FPCLASSIFY)
        printf("%s (%d)\n", fp_desc(r), r);
    else
        printf("%s (%d)\n", r ? "true" : "false", r);
}

int main(int argc, char **argv)
{
    printf("=== Classificação e Comparação de Ponto Flutuante (<math.h>) ===\n\n");

    /* Valores de teste */
    double valores[] = {
        0.0,
        -0.0,
        1.0,
        -5.7,
        1e-308, /* subnormal */
        INFINITY,
        -INFINITY,
        NAN};

    const size_t n_valores = sizeof(valores) / sizeof(valores[0]);

    /* ---- Testes unários ---- */
    printf("--- Testes Unários ---\n\n");

    for (size_t i = 0; i < n_valores; ++i)
    {
        double x = valores[i]; // Preenche `x` com os valores de teste

        print_result(MATH_FPCLASSIFY, x, 0.0);
        print_result(MATH_ISINF, x, 0.0);
        print_result(MATH_ISNAN, x, 0.0);
        print_result(MATH_ISNORMAL, x, 0.0);
        print_result(MATH_ISFINITE, x, 0.0);

        printf("--------------------------------------------------\n");
    }

    /* ---- Testes binários ---- */
    printf("\n--- Testes de Comparação ---\n\n");

    double pares[][2] = {
        {1.0, 2.0},
        {2.0, 1.0},
        {1.0, 1.0},
        {NAN, 1.0},
        {1.0, NAN},
        {NAN, NAN},
        {INFINITY, 1.0},
        {1.0, INFINITY},
        {-INFINITY, INFINITY}};

    MathOpType comparacoes[] = {
        MATH_ISGREATER,
        MATH_ISGREATEREQUAL,
        MATH_ISLESS,
        MATH_ISLESSEQUAL,
        MATH_ISLESSGREATER,
        MATH_ISUNORDERED};

    const size_t n_pares = sizeof(pares) / sizeof(pares[0]);
    const size_t n_comp = sizeof(comparacoes) / sizeof(comparacoes[0]);

    for (size_t i = 0; i < n_pares; ++i)
    {
        double x = pares[i][0];
        double y = pares[i][1];

        for (size_t j = 0; j < n_comp; ++j)
        {
            print_result(comparacoes[j], x, y);
        }

        printf("--------------------------------------------------\n");
    }

    return 0;
}
