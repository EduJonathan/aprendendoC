#include <stdio.h>
#include <math.h>

/* Enumeração das operações */
typedef enum
{
    MATH_EXP,
    MATH_EXP2,
    MATH_FREXP,
    MATH_LDEXP,
    MATH_LOG,
    MATH_LOG2,
    MATH_LOG10,
    MATH_MODF,
    MATH_COUNT
} FUNCOES_EXPONENCIAIS;

/* Estrutura que descreve cada operação */
typedef struct
{
    FUNCOES_EXPONENCIAIS type;
    const char *name;
    int num_args; // 1 ou 2 (ldexp usa 2)

    /* Funções principais */
    float (*f_func)(float, float);
    double (*d_func)(double, double);
    long double (*ld_func)(long double, long double);

    /* Para frexp e modf: retornam a parte fracionária e preenchem expoente/inteiro via ponteiro */
    float (*f_frac)(float, int *);
    double (*d_frac)(double, int *);
    long double (*ld_frac)(long double, int *);
} MathOperation;

/* Tabela central – tudo definido aqui */
const MathOperation MATH_OPERATIONS[MATH_COUNT] = {
    [MATH_EXP] = {MATH_EXP, "exp", 1, (float (*)(float, float))expf, (double (*)(double, double))exp, (long double (*)(long double, long double))expl, NULL, NULL, NULL},
    [MATH_EXP2] = {MATH_EXP2, "exp2", 1, (float (*)(float, float))exp2f, (double (*)(double, double))exp2, (long double (*)(long double, long double))exp2l, NULL, NULL, NULL},
    [MATH_FREXP] = {MATH_FREXP, "frexp", 1, NULL, NULL, NULL, frexpf, frexp, frexpl},
    [MATH_LDEXP] = {MATH_LDEXP, "ldexp", 2, (float (*)(float, float))ldexpf, (double (*)(double, double))ldexp, (long double (*)(long double, long double))ldexpl, NULL, NULL, NULL},
    [MATH_LOG] = {MATH_LOG, "log", 1, (float (*)(float, float))logf, (double (*)(double, double))log, (long double (*)(long double, long double))logl, NULL, NULL, NULL},
    [MATH_LOG2] = {MATH_LOG2, "log2", 1, (float (*)(float, float))log2f, (double (*)(double, double))log2, (long double (*)(long double, long double))log2l, NULL, NULL, NULL},
    [MATH_LOG10] = {MATH_LOG10, "log10", 1, (float (*)(float, float))log10f, (double (*)(double, double))log10, (long double (*)(long double, long double))log10l, NULL, NULL, NULL},
    [MATH_MODF] = {MATH_MODF, "modf", 1, NULL, NULL, NULL, modff, modf, modfl},
};

/* Estrutura de resultados – com partes fracionárias e inteiras/expoentes */
typedef struct
{
    double x;
    double y; // usado apenas por ldexp

    float f_result;
    double d_result;
    long double ld_result;

    int f_exp; // expoente (frexp) ou parte inteira (modf)
    int d_exp;
    int ld_exp;

    FUNCOES_EXPONENCIAIS type;
} ResultadosMatematicos;

/**
 * @brief Função para computar a operação matemática especificada
 *
 * @param x Primeiro argumento
 * @param y Segundo argumento (se aplicável)
 * @param type Tipo da operação matemática
 * @return ResultadosMatematicos Estrutura contendo os resultados em diferentes precisões
 */
ResultadosMatematicos compute_math(double x, double y, FUNCOES_EXPONENCIAIS type)
{
    ResultadosMatematicos res = {
        .x = x,
        .y = y,
        .type = type,
        .f_result = 0.0f,
        .d_result = 0.0,
        .ld_result = 0.0L,
        .f_exp = 0,
        .d_exp = 0,
        .ld_exp = 0};

    if (type >= MATH_COUNT)
        return res;

    const MathOperation *op = &MATH_OPERATIONS[type];

    /* Funções normais (exp, exp2, log*, ldexp) */
    if (op->f_func)
        res.f_result = op->f_func((float)x, (float)y);
    if (op->d_func)
        res.d_result = op->d_func(x, y);
    if (op->ld_func)
        res.ld_result = op->ld_func((long double)x, (long double)y);

    /* Funções que retornam fração e preenchem expoente/inteiro */
    if (op->f_frac)
        res.f_result = op->f_frac((float)x, &res.f_exp);
    if (op->d_frac)
        res.d_result = op->d_frac(x, &res.d_exp);
    if (op->ld_frac)
        res.ld_result = op->ld_frac((long double)x, &res.ld_exp);

    return res;
}

/**
 * @brief Impressão adaptada ao tipo de função.
 *
 * @param r Ponteiro para a estrutura de resultados.
 */
void print_math_result(const ResultadosMatematicos *r)
{
    const MathOperation *op = &MATH_OPERATIONS[r->type];

    if (op->num_args == 2)
        printf("[%s] f(%.13g, %.0f)\n", op->name, r->x, r->y);
    else
        printf("[%s] f(%.13g)\n", op->name, r->x);

    if (r->type == MATH_FREXP || r->type == MATH_MODF)
    {
        printf("  float:       fração = %.9g    %s = %d\n",
               r->f_result, (r->type == MATH_FREXP ? "expoente" : "inteiro"), r->f_exp);
        printf("  double:      fração = %.17g   %s = %d\n",
               r->d_result, (r->type == MATH_FREXP ? "expoente" : "inteiro"), r->d_exp);
        printf("  long double: fração = %.21Lg  %s = %d\n",
               r->ld_result, (r->type == MATH_FREXP ? "expoente" : "inteiro"), r->ld_exp);
    }
    else
    {
        printf("  float:       %.9g\n", r->f_result);
        printf("  double:      %.17g\n", r->d_result);
        printf("  long double: %.21Lg\n", r->ld_result);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    printf("=== Funções exponenciais e logarítmicas em diferentes precisões ===\n\n");
    ResultadosMatematicos r;

    r = compute_math(1.0, 0, MATH_EXP);
    print_math_result(&r);

    r = compute_math(8.0, 0, MATH_EXP2);
    print_math_result(&r);

    r = compute_math(1.0, 0, MATH_LOG);
    print_math_result(&r);

    r = compute_math(1024.0, 0, MATH_LOG2);
    print_math_result(&r);

    r = compute_math(1000.0, 0, MATH_LOG10);
    print_math_result(&r);

    r = compute_math(6.5, 3, MATH_LDEXP);
    print_math_result(&r);

    r = compute_math(13.625, 0, MATH_FREXP);
    print_math_result(&r);

    r = compute_math(-13.625, 0, MATH_MODF);
    print_math_result(&r);

    return 0;
}
