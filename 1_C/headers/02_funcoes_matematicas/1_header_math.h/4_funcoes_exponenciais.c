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
    int num_args; // 1 ou 2

    /* Funções que recebem dois argumentos do mesmo tipo (só ldexp usa int, tratado separado) */
    float       (*f_func) (float, float);
    double      (*d_func) (double, double);
    long double (*ld_func)(long double, long double);
    
    /* Para frexp: fração + expoente (int *) */
    float       (*f_frexp) (float, int *);
    double      (*d_frexp) (double, int *);
    long double (*ld_frexp)(long double, int *);
    
    /* Para modf: fração + parte inteira (mesmo tipo *) */
    float       (*f_modf) (float, float *);
    double      (*d_modf) (double, double *);
    long double (*ld_modf)(long double, long double *);
} MathOperation;

/* Tabela central – tudo definido aqui */
const MathOperation MATH_OPERATIONS[MATH_COUNT] = {
    [MATH_EXP]   = {MATH_EXP,   "exp",   1, NULL, NULL, NULL, NULL,   NULL,  NULL,   NULL, NULL,  NULL},
    [MATH_EXP2]  = {MATH_EXP2,  "exp2",  1, NULL, NULL, NULL, NULL,   NULL,  NULL,   NULL, NULL,  NULL},
    [MATH_FREXP] = {MATH_FREXP, "frexp", 1, NULL, NULL, NULL, frexpf, frexp, frexpl, NULL, NULL,  NULL},
    [MATH_LDEXP] = {MATH_LDEXP, "ldexp", 2, NULL, NULL, NULL, NULL,   NULL,  NULL,   NULL, NULL,  NULL}, // tratado separado
    [MATH_LOG]   = {MATH_LOG,   "log",   1, NULL, NULL, NULL, NULL,   NULL,  NULL,   NULL, NULL,  NULL},
    [MATH_LOG2]  = {MATH_LOG2,  "log2",  1, NULL, NULL, NULL, NULL,   NULL,  NULL,   NULL, NULL,  NULL},
    [MATH_LOG10] = {MATH_LOG10, "log10", 1, NULL, NULL, NULL, NULL,   NULL,  NULL,   NULL, NULL,  NULL},
    [MATH_MODF]  = {MATH_MODF,  "modf",  1, NULL, NULL, NULL, NULL,   NULL,  NULL,   modff, modf, modfl},
};

/* Estrutura de resultados – com partes fracionárias e inteiras/expoentes */
typedef struct
{
    double x;
    double y; // usado apenas por ldexp
    float f_result;
    double d_result;
    long double ld_result;

    int f_exp; // expoente (frexp) ou não usado em modf
    int d_exp;
    int ld_exp;

    double f_intpart; // para modf (parte inteira em float)
    double d_intpart; // para modf
    long double ld_intpart;
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
        .ld_exp = 0,
        .f_intpart = 0.0,
        .d_intpart = 0.0,
        .ld_intpart = 0.0L};

    if (type >= MATH_COUNT)
        return res;

    const MathOperation *op = &MATH_OPERATIONS[type];

    // Caso especial: ldexp (segundo argumento é int)
    if (type == MATH_LDEXP)
    {
        int exp = (int)y; // y deve ser inteiro em valor
        res.f_result = ldexpf((float)x, exp);
        res.d_result = ldexp(x, exp);
        res.ld_result = ldexpl((long double)x, exp);
        return res;
    }

    // Funções normais de 1 argumento (exp, exp2, log*, etc.), não precisam de y
    if (op->f_func)
        res.f_result = op->f_func((float)x, (float)y);

    if (op->d_func)
        res.d_result = op->d_func(x, y);

    if (op->ld_func)
        res.ld_result = op->ld_func((long double)x, (long double)y);

    // frexp
    if (op->f_frexp)
        res.f_result = op->f_frexp((float)x, &res.f_exp);

    if (op->d_frexp)
        res.d_result = op->d_frexp(x, &res.d_exp);

    if (op->ld_frexp)
        res.ld_result = op->ld_frexp((long double)x, &res.ld_exp);

    // modf – parte inteira no ponteiro (mesmo tipo!)
    if (op->f_modf)
    {
        float intpart;
        res.f_result = op->f_modf((float)x, &intpart);
        res.f_intpart = intpart;
    }
    
    if (op->d_modf)
    {
        double intpart;
        res.d_result = op->d_modf(x, &intpart);
        res.d_intpart = intpart;
    }
    
    if (op->ld_modf)
    {
        long double intpart;
        res.ld_result = op->ld_modf((long double)x, &intpart);
        res.ld_intpart = intpart;
    }

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
    {
        printf("[%s] (%.13g, %.0f)\n", op->name, r->x, r->y);
    }
    else
    {
        printf("[%s] (%.13g)\n", op->name, r->x);
    }

    if (r->type == MATH_FREXP)
    {
        printf(" float:   mantissa = %.9g   expoente = %d\n", r->f_result, r->f_exp);
        printf(" double:  mantissa = %.17g  expoente = %d\n", r->d_result, r->d_exp);
        printf(" ldouble: mantissa = %.21Lg expoente = %d\n", r->ld_result, r->ld_exp);
    }
    else if (r->type == MATH_MODF)
    {
        printf(" float:   fração = %.9g   parte inteira = %.9g\n", r->f_result, r->f_intpart);
        printf(" double:  fração = %.17g  parte inteira = %.17g\n", r->d_result, r->d_intpart);
        printf(" ldouble: fração = %.21Lg parte inteira = %.21Lg\n", r->ld_result, r->ld_intpart);
    }
    else if (r->type == MATH_LDEXP)
    {
        printf(" float:   %.9g\n", r->f_result);
        printf(" double:  %.17g\n", r->d_result);
        printf(" ldouble: %.21Lg\n", r->ld_result);
    }
    else
    {
        printf(" float:   %.9g\n", r->f_result);
        printf(" double:  %.17g\n", r->d_result);
        printf(" ldouble: %.21Lg\n", r->ld_result);
    }
    printf("\n");
}

int main(void)
{
    printf("=== Funções exponenciais e logarítmicas em diferentes precisões ===\n\n");

    const struct
    {
        double x;
        double y;
        FUNCOES_EXPONENCIAIS type;
    } tests[] = {
        {1.0,     0.0, MATH_EXP},
        {8.0,     0.0, MATH_EXP2},
        {1.0,     0.0, MATH_LOG},
        {1024.0,  0.0, MATH_LOG2},
        {1000.0,  0.0, MATH_LOG10},
        {6.5,     3.0, MATH_LDEXP},
        {13.625,  0.0, MATH_FREXP},
        {-13.625, 0.0, MATH_MODF},
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        ResultadosMatematicos r = compute_math(tests[i].x, tests[i].y, tests[i].type);
        print_math_result(&r);
    }

    return 0;
}
