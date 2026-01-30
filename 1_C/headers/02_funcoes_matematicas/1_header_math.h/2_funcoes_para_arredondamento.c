#include <stdio.h>
#include <math.h>

/* Enumeração das operações suportadas */
typedef enum
{
    MATH_CEIL,
    MATH_FLOOR,
    MATH_ROUND,
    MATH_TRUNC,
    MATH_RINT,
    MATH_LRINT,
    MATH_LLRINT,
    MATH_LROUND,
    MATH_LLRROUND,
    MATH_COUNT
} FUNCOES_DE_ARREDONDAMENTO;

/* Estrutura que descreve cada operação matemática */
typedef struct
{
    FUNCOES_DE_ARREDONDAMENTO type; // Tipo da operação
    const char *name;               // Nome da operação

    /* Ponteiros para as versões em diferentes precisões */
    float       (*f_func)(float);          // versão float
    double      (*d_func)(double);        // versão double
    long double (*ld_func)(long double); // versão long double

    /* Ponteiros para versões que retornam inteiros (se aplicável) */
    long      (*l_func)(double);  // lrint / lround
    long long (*ll_func)(double); // llrint / llround
} MathOperation;

/* Tabela com todas as operações */
const MathOperation MATH_OPERATIONS[MATH_COUNT] = {
    [MATH_CEIL]     = {MATH_CEIL,     "ceil",    ceilf,  ceil, ceill,   NULL,  NULL},
    [MATH_FLOOR]    = {MATH_FLOOR,    "floor",   floorf, floor, floorl, NULL,  NULL},
    [MATH_ROUND]    = {MATH_ROUND,    "round",   roundf, round, roundl, NULL,  NULL},
    [MATH_TRUNC]    = {MATH_TRUNC,    "trunc",   truncf, trunc, truncl, NULL,  NULL},
    [MATH_RINT]     = {MATH_RINT,     "rint",    rintf,  rint, rintl,   NULL,  NULL},
    [MATH_LRINT]    = {MATH_LRINT,    "lrint",   NULL,   NULL, NULL,   lrint,  NULL},
    [MATH_LLRINT]   = {MATH_LLRINT,   "llrint",  NULL,   NULL, NULL,   NULL,   llrint},
    [MATH_LROUND]   = {MATH_LROUND,   "lround",  NULL,   NULL, NULL,   lround, NULL},
    [MATH_LLRROUND] = {MATH_LLRROUND, "llround", NULL,   NULL, NULL,   NULL,   llround},
};

/* Estrutura para armazenar os resultados */
typedef struct
{
    double x;
    float f_result;
    double d_result;
    long double ld_result;
    long l_result;
    long long ll_result;
    FUNCOES_DE_ARREDONDAMENTO type;
} ResultadosMatematicos;

/**
 * @brief Função única que computa tudo – sem switch!
 *
 * @param x Valor de entrada.
 * @param type Tipo de função matemática a ser aplicada.
 * @return Estrutura com todos os resultados.
 */
ResultadosMatematicos compute_math(double x, FUNCOES_DE_ARREDONDAMENTO type)
{
    ResultadosMatematicos res = {
        .x = x,
        .type = type,
        .f_result = 0.0f,
        .d_result = 0.0,
        .ld_result = 0.0L,
        .l_result = 0L,
        .ll_result = 0LL};

    if (type >= MATH_COUNT)
    {
        return res; // tipo inválido
    }

    const MathOperation *op = &MATH_OPERATIONS[type];

    if (op->f_func)
        res.f_result = op->f_func((float)x);

    if (op->d_func)
        res.d_result = op->d_func(x);

    if (op->ld_func)
        res.ld_result = op->ld_func((long double)x);

    if (op->l_func)
        res.l_result = op->l_func(x);

    if (op->ll_func)
        res.ll_result = op->ll_func(x);

    return res;
}

/**
 * @brief Função de impressão adaptada aos diferentes tipos de retorno.
 *
 * @param res Ponteiro para a estrutura de resultados.
 */
void imprimir_resultados(const ResultadosMatematicos *res)
{
    const char *nome = MATH_OPERATIONS[res->type].name;
    printf("Resultados para %s(%.6g):\n", nome, res->x);

    const MathOperation *op = &MATH_OPERATIONS[res->type];

    /* Funções que retornam valores de ponto flutuante */
    if (op->f_func || op->d_func || op->ld_func)
    {
        if (op->f_func)
            printf("  float:       %.6g\n", res->f_result);

        if (op->d_func)
            printf("  double:      %.6g\n", res->d_result);

        if (op->ld_func)
            printf("  long double: %.6Lg\n", res->ld_result);
    }

    /* Funções que retornam inteiros */
    if (op->l_func)
    {
        printf("  long:        %ld\n", res->l_result);
    }

    if (op->ll_func)
    {
        printf("  long long:   %lld\n", res->ll_result);
    }
}

int main(int argc, char **argv)
{
    double valores_teste[] = {3.7, 2.45, -1.8, 4.5, 5.6, -4.3, 0.0, 1.999999999};

    printf("=== Testando todas as funções de arredondamento ===\n\n");

    for (size_t i = 0; i < sizeof(valores_teste) / sizeof(valores_teste[0]); i++)
    {
        double x = valores_teste[i];

        for (FUNCOES_DE_ARREDONDAMENTO t = 0; t < MATH_COUNT; t++)
        {
            ResultadosMatematicos res = compute_math(x, t);
            imprimir_resultados(&res);
            printf("\n");
        }
        printf("--------------------------------------------------\n\n");
    }

    return 0;
}
