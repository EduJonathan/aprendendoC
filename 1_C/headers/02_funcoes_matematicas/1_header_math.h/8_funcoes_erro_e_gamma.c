#include <stdio.h>
#include <math.h>

/* Enumeração das operações */
typedef enum
{
    MATH_ERF,
    MATH_ERFC,
    MATH_TGAMMA,
    MATH_LGAMMA,
    MATH_COUNT
} FUNCOES_ESPECIAIS;

/* Estrutura que descreve cada operação */
typedef struct
{
    FUNCOES_ESPECIAIS type;
    const char *name;
    int num_args; // sempre 1 nestas funções

    float       (*f_func) (float);
    double      (*d_func) (double);
    long double (*ld_func)(long double);
} MathOperation;

/* Tabela central – tudo concentrado aqui */
const MathOperation MATH_OPERATIONS[MATH_COUNT] = {
    [MATH_ERF]    = {MATH_ERF,    "erf",    1, erff,    erf,    erfl},
    [MATH_ERFC]   = {MATH_ERFC,   "erfc",   1, erfcf,   erfc,   erfcl},
    [MATH_TGAMMA] = {MATH_TGAMMA, "tgamma", 1, tgammaf, tgamma, tgammal},
    [MATH_LGAMMA] = {MATH_LGAMMA, "lgamma", 1, lgammaf, lgamma, lgammal},
};

/* Estrutura de resultados (simples, pois só retorna um valor flutuante) */
typedef struct
{
    double x;
    float f_result;
    double d_result;
    long double ld_result;
    FUNCOES_ESPECIAIS type;
} ResultadosMatematicos;

/**
 * @brief Computa a função especial solicitada em diferentes precisões
 * 
 * @param x Valor de entrada
 * @param type Tipo da função especial a ser computada
 * @return ResultadosMatematicos contendo os resultados para float, double e long double
 */
ResultadosMatematicos compute_math(double x, FUNCOES_ESPECIAIS type)
{
    ResultadosMatematicos res = {
        .x = x,
        .type = type,
        .f_result = 0.0f,
        .d_result = 0.0,
        .ld_result = 0.0L
    };

    if (type >= MATH_COUNT)
        return res;

    const MathOperation *op = &MATH_OPERATIONS[type];

    if (op->f_func)
        res.f_result  = op->f_func((float)x);

    if (op->d_func)
        res.d_result  = op->d_func(x);

    if (op->ld_func)
        res.ld_result = op->ld_func((long double)x);

    return res;
}

/**
 * @brief Impressão adaptada para funções especiais
 */
void print_math_result(const ResultadosMatematicos *r)
{
    const char *nome = MATH_OPERATIONS[r->type].name;

    printf("[%s](%.10g)\n", nome, r->x);
    printf(" float:       %.10g\n", (double)r->f_result);
    printf(" double:      %.18g\n", r->d_result);
    printf(" long double: %.22Lg\n", r->ld_result);
    printf("\n");
}

int main(int argc, char **argv)
{
    printf("=== Funções especiais (erf, erfc, gamma, log-gamma) ===\n\n");

    const struct
    {
        double x;
        FUNCOES_ESPECIAIS type;
    } tests[] = {
        /* erf e erfc — valores típicos */
        {0.0,  MATH_ERF},
        {1.0,  MATH_ERF},
        {2.0,  MATH_ERF},
        {3.5,  MATH_ERF},
        {1.0,  MATH_ERFC},
        {2.0,  MATH_ERFC},
        {-1.0, MATH_ERFC},

        /* tgamma (fatorial generalizado para reais) */
        {1.0,  MATH_TGAMMA},
        {5.0,  MATH_TGAMMA}, // → 24.0
        {0.5,  MATH_TGAMMA}, // → √π ≈ 1.772453850905516
        {6.3,  MATH_TGAMMA},
        {-0.4, MATH_TGAMMA}, // valor negativo → pode ser grande

        /* lgamma (log do módulo do gamma) — mais estável numericamente */
        {1.0,   MATH_LGAMMA},
        {5.0,   MATH_LGAMMA},    // → ln(24) ≈ 3.178053830347946
        {0.5,   MATH_LGAMMA},   // → ln(√π) ≈ 0.572364942924700
        {100.0, MATH_LGAMMA},  // valores grandes → evita overflow
        {0.001, MATH_LGAMMA}, // perto de zero
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        ResultadosMatematicos r = compute_math(tests[i].x, tests[i].type);
        print_math_result(&r);
    }

    return 0;
}
