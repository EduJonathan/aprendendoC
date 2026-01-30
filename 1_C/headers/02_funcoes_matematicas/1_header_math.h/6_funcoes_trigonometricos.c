#include <stdio.h>
#include <math.h>

#define M_PI 3.14159265358979323846L

/* Enumeração das operações */
typedef enum
{
    MATH_SIN,
    MATH_COS,
    MATH_TAN,
    MATH_ASIN,
    MATH_ACOS,
    MATH_ATAN,
    MATH_ATAN2,
    MATH_COUNT
} FUNCOES_TRIGONOMETRICAS;

/* Estrutura que descreve cada operação */
typedef struct
{
    FUNCOES_TRIGONOMETRICAS type;
    const char *name;
    int num_args; // 1 para unárias, 2 para atan2

    float       (*f_func)(float); // unárias
    double      (*d_func)(double);
    long double (*ld_func)(long double);

    // Versões binárias para atan2
    float       (*f_bin)(float, float);
    double      (*d_bin)(double, double);
    long double (*ld_bin)(long double, long double);
} MathOperation;

/* Tabela central – tudo definido aqui */
const MathOperation MATH_OPERATIONS[MATH_COUNT] = {
    [MATH_SIN]   = {MATH_SIN,   "sin",   1, sinf,  sin,  sinl,  NULL,   NULL,  NULL},
    [MATH_COS]   = {MATH_COS,   "cos",   1, cosf,  cos,  cosl,  NULL,   NULL,  NULL},
    [MATH_TAN]   = {MATH_TAN,   "tan",   1, tanf,  tan,  tanl,  NULL,   NULL,  NULL},
    [MATH_ASIN]  = {MATH_ASIN,  "asin",  1, asinf, asin, asinl, NULL,   NULL,  NULL},
    [MATH_ACOS]  = {MATH_ACOS,  "acos",  1, acosf, acos, acosl, NULL,   NULL,  NULL},
    [MATH_ATAN]  = {MATH_ATAN,  "atan",  1, atanf, atan, atanl, NULL,   NULL,  NULL},
    [MATH_ATAN2] = {MATH_ATAN2, "atan2", 2, NULL,  NULL, NULL,  atan2f, atan2, atan2l},
};

/* Estrutura de resultados */
typedef struct
{
    double x; // primeiro argumento
    double y; // segundo argumento (usado apenas por atan2)
    float f_result;
    double d_result;
    long double ld_result;
    FUNCOES_TRIGONOMETRICAS type;
} ResultadosMatematicos;

/**
 * @brief Função para computar a operação matemática especificada
 *
 * @param x Primeiro argumento
 * @param y Segundo argumento (se aplicável)
 * @param type Tipo da operação matemática
 * @return ResultadosMatematicos Estrutura contendo os resultados em diferentes precisões
 */
ResultadosMatematicos compute_math(double x, double y, FUNCOES_TRIGONOMETRICAS type)
{
    ResultadosMatematicos res = {
        .x = x,
        .y = y,
        .type = type,
        .f_result = 0.0f,
        .d_result = 0.0,
        .ld_result = 0.0L};

    if (type >= MATH_COUNT)
    {
        return res;
    }

    const MathOperation *op = &MATH_OPERATIONS[type];

    /* Funções unárias */
    if (op->f_func)
        res.f_result = op->f_func((float)x);

    if (op->d_func)
        res.d_result = op->d_func(x);

    if (op->ld_func)
        res.ld_result = op->ld_func((long double)x);

    /* Função binária (atan2) */
    if (op->f_bin)
        res.f_result = op->f_bin((float)y, (float)x); // ordem: y, x

    if (op->d_bin)
        res.d_result = op->d_bin(y, x);

    if (op->ld_bin)
        res.ld_result = op->ld_bin((long double)y, (long double)x);

    return res;
}

/* Impressão dos resultados */
void print_math_result(const ResultadosMatematicos *r)
{
    const MathOperation *op = &MATH_OPERATIONS[r->type];

    if (op->num_args == 2)
        printf("[%s] f(%.13g, %.13g)\n", op->name, r->y, r->x); // atan2(y, x)
    else
        printf("[%s] f(%.13g)\n", op->name, r->x);

    printf("  float:       %.9g\n", r->f_result);
    printf("  double:      %.17g\n", r->d_result);
    printf("  long double: %.21Lg\n", r->ld_result);
    printf("\n");
}

typedef struct
{
    FUNCOES_TRIGONOMETRICAS op;
    double x;
    double y; // usado apenas por atan2
} TestarValores;

int main(int argc, char **argv)
{
    printf("=== Funções trigonométricas em diferentes precisões ===\n\n");

    /* Casos de teste unários (ângulos em radianos) */
    TestarValores testes_unarios[] = {
        {MATH_SIN,  0.0,      0.0},
        {MATH_SIN,  M_PI / 6, 0.0}, // 30°
        {MATH_SIN,  M_PI / 4, 0.0}, // 45°
        {MATH_COS,  M_PI / 3, 0.0}, // 60°
        {MATH_TAN,  M_PI / 4, 0.0}, // 45°
        {MATH_ASIN, 0.5,      0.0},
        {MATH_ACOS, 0.5,      0.0},
        {MATH_ATAN, 1.0,      0.0}};

    const size_t n_unarios = sizeof(testes_unarios) / sizeof(testes_unarios[0]);

    for (size_t i = 0; i < n_unarios; ++i)
    {
        ResultadosMatematicos r =
            compute_math(testes_unarios[i].x,
                         testes_unarios[i].y,
                         testes_unarios[i].op);

        print_math_result(&r);
    }

    printf("--------------------------------------------------\n\n");

    /* Casos de teste binários (atan2) */
    TestarValores testes_binarios[] = {
        {MATH_ATAN2, 1.0, 1.0},   //  45°
        {MATH_ATAN2, 1.0, -1.0},  // 135°
        {MATH_ATAN2, -1.0, -1.0}, // -135°
        {MATH_ATAN2, -1.0, 1.0}   // -45°
    };

    const size_t n_binarios = sizeof(testes_binarios) / sizeof(testes_binarios[0]);

    for (size_t i = 0; i < n_binarios; ++i)
    {
        ResultadosMatematicos r =
            compute_math(testes_binarios[i].x,
                         testes_binarios[i].y,
                         testes_binarios[i].op);

        print_math_result(&r);
    }

    return 0;
}
