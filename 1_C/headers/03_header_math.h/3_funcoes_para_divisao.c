#include <stdio.h>
#include <math.h>

/* Enumeração das operações */
typedef enum
{
    MATH_FABS,
    MATH_FMOD,
    MATH_REMAINDER,
    MATH_REMQUO,
    MATH_COUNT
} FuncoesPotenciais;

/* Estrutura que descreve cada operação */
typedef struct
{
    FuncoesPotenciais type;
    const char *name;
    int num_args; // 1 para fabs, 2 para as outras

    float (*f_func)(float, float);
    double (*d_func)(double, double);
    long double (*ld_func)(long double, long double);

    // Para remquo: ponteiros para as funções que preenchem o quociente
    float (*f_remquo)(float, float, int *);
    double (*d_remquo)(double, double, int *);
    long double (*ld_remquo)(long double, long double, int *);
} MathOperation;

/* Tabela central de operações */
const MathOperation MATH_OPERATIONS[MATH_COUNT] = {
    [MATH_FABS] = {MATH_FABS, "fabs", 1, (float (*)(float, float))fabsf, (double (*)(double, double))fabs, (long double (*)(long double, long double))fabsl, NULL, NULL, NULL},
    [MATH_FMOD] = {MATH_FMOD, "fmod", 2, fmodf, fmod, fmodl, NULL, NULL, NULL},
    [MATH_REMAINDER] = {MATH_REMAINDER, "remainder", 2, remainderf, remainder, remainderl, NULL, NULL, NULL},
    [MATH_REMQUO] = {MATH_REMQUO, "remquo", 2, NULL, NULL, NULL, remquof, remquo, remquol},
};

/* Estrutura de resultados – agora com quociente para remquo */
typedef struct
{
    double x;
    double y;
    float f_result;
    double d_result;
    long double ld_result;

    // Apenas usados por remquo
    int f_quotient;
    int d_quotient;
    int ld_quotient;

    FuncoesPotenciais type;
} ResultadosMatematicos;

/**
 * @brief Função para computar a operação matemática especificada
 *
 * @param x Primeiro argumento
 * @param y Segundo argumento (se aplicável)
 * @param type Tipo da operação matemática
 * @return ResultadosMatematicos Estrutura contendo os resultados em diferentes precisões
 */
ResultadosMatematicos compute_math(double x, double y, FuncoesPotenciais type)
{
    ResultadosMatematicos res = {
        .x = x,
        .y = y,
        .type = type,
        .f_result = 0.0f,
        .d_result = 0.0,
        .ld_result = 0.0L,
        .f_quotient = 0,
        .d_quotient = 0,
        .ld_quotient = 0};

    if (type >= MATH_COUNT)
    {
        return res;
    }

    const MathOperation *op = &MATH_OPERATIONS[type];

    /* Funções normais (fabs, fmod, remainder) */
    if (op->f_func)
        res.f_result = op->f_func((float)x, (float)y);
    if (op->d_func)
        res.d_result = op->d_func(x, y);
    if (op->ld_func)
        res.ld_result = op->ld_func((long double)x, (long double)y);

    /* remquo – precisa do quociente */
    if (op->f_remquo)
        res.f_result = op->f_remquo((float)x, (float)y, &res.f_quotient);
    if (op->d_remquo)
        res.d_result = op->d_remquo(x, y, &res.d_quotient);
    if (op->ld_remquo)
        res.ld_result = op->ld_remquo((long double)x, (long double)y, &res.ld_quotient);

    return res;
}

/* Impressão inteligente dos resultados */
void print_math_result(const ResultadosMatematicos *r)
{
    const MathOperation *op = &MATH_OPERATIONS[r->type];

    if (op->num_args == 2)
        printf("[%s] f(%.13g, %.13g)\n", op->name, r->x, r->y);
    else
        printf("[%s] f(%.13g)\n", op->name, r->x);

    printf("  float       = %.9g", r->f_result);
    if (r->type == MATH_REMQUO)
        printf("   (quotient: %d)\n", r->f_quotient);
    else
        printf("\n");

    printf("  double      = %.17g", r->d_result);
    if (r->type == MATH_REMQUO)
        printf("   (quotient: %d)\n", r->d_quotient);
    else
        printf("\n");

    printf("  long double = %.21Lg", r->ld_result);
    if (r->type == MATH_REMQUO)
        printf("   (quotient: %d)\n", r->ld_quotient);
    else
        printf("\n");

    printf("\n");
}

typedef struct
{
    double x;
    double y;
    FuncoesPotenciais type;
} TestCase;

int main(int argc, char **argv)
{
    printf("=== Testes com funções de módulo e valor absoluto ===\n\n");

    const TestCase tests[] = {
        {-5.7, 0.0, MATH_FABS},
        {17.8, 5.0, MATH_FMOD},
        {17.8, 5.0, MATH_REMAINDER},
        {17.8, 5.0, MATH_REMQUO},
        {-17.8, 5.0, MATH_FMOD},
        {-17.8, 5.0, MATH_REMAINDER},
        {-17.8, 5.0, MATH_REMQUO},
        {10.0, 3.0, MATH_REMQUO},
    };

    const size_t ntests = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < ntests; i++)
    {
        ResultadosMatematicos r = compute_math(tests[i].x, tests[i].y, tests[i].type);
        print_math_result(&r);
    }
    return 0;
}
