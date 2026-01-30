#include <stdio.h>
#include <math.h>

/* Enumeração das operações */
typedef enum
{
    MATH_SINH,
    MATH_COSH,
    MATH_TANH,
    MATH_ASINH,
    MATH_ACOSH,
    MATH_ATANH,
    MATH_COUNT
} FUNCOES_HIPERPBOLICAS;

/* Estrutura que descreve cada operação */
typedef struct
{
    FUNCOES_HIPERPBOLICAS type;
    const char *name;
    int num_args; // sempre 1 para essas funções

    float       (*f_func)(float);
    double      (*d_func)(double);
    long double (*ld_func)(long double);
} MathOperation;

/* Tabela central – tudo definido aqui */
const MathOperation MATH_OPERATIONS[MATH_COUNT] = {
    [MATH_SINH]  = {MATH_SINH,  "sinh",  1, sinhf,  sinh,  sinhl},
    [MATH_COSH]  = {MATH_COSH,  "cosh",  1, coshf,  cosh,  coshl},
    [MATH_TANH]  = {MATH_TANH,  "tanh",  1, tanhf,  tanh,  tanhl},
    [MATH_ASINH] = {MATH_ASINH, "asinh", 1, asinhf, asinh, asinhl},
    [MATH_ACOSH] = {MATH_ACOSH, "acosh", 1, acoshf, acosh, acoshl},
    [MATH_ATANH] = {MATH_ATANH, "atanh", 1, atanhf, atanh, atanhl},
};

/* Estrutura de resultados */
typedef struct
{
    double x;
    float f_result;
    double d_result;
    long double ld_result;
    FUNCOES_HIPERPBOLICAS type;
} ResultadosMatematicos;

/**
 * @brief Função para computar a operação matemática especificada
 *
 * @param x Primeiro argumento
 * @param type Tipo da operação matemática
 * @return ResultadosMatematicos Estrutura contendo os resultados em diferentes precisões
 */
ResultadosMatematicos compute_math(double x, FUNCOES_HIPERPBOLICAS type)
{
    ResultadosMatematicos res = {
        .x = x,
        .type = type,
        .f_result = 0.0f,
        .d_result = 0.0,
        .ld_result = 0.0L};

    if (type >= MATH_COUNT)
    {
        return res;
    }

    const MathOperation *op = &MATH_OPERATIONS[type];

    if (op->f_func)
        res.f_result = op->f_func((float)x);

    if (op->d_func)
        res.d_result = op->d_func(x);

    if (op->ld_func)
        res.ld_result = op->ld_func((long double)x);

    return res;
}

/* Impressão dos resultados */
void print_math_result(const ResultadosMatematicos *r)
{
    const MathOperation *op = &MATH_OPERATIONS[r->type];

    printf("[%s] f(%.13g)\n", op->name, r->x);
    printf("  float:       %.9g\n", r->f_result);
    printf("  double:      %.17g\n", r->d_result);
    printf("  long double: %.21Lg\n", r->ld_result);
    printf("\n");
}

int main(int argc, char **argv)
{
    printf("=== Funções hiperbólicas e suas inversas em diferentes precisões ===\n\n");

    double valores[] = {
        0.0,
        1.0,
        -1.0,
        2.0,
        0.5,
        -0.5,
        10.0,
        0.99999};

    size_t n = sizeof(valores) / sizeof(valores[0]);

    for (size_t i = 0; i < n; i++)
    {
        double x = valores[i];
        ResultadosMatematicos r;

        /* Funções diretas */
        r = compute_math(x, MATH_SINH);
        print_math_result(&r);

        r = compute_math(x, MATH_COSH);
        print_math_result(&r);

        r = compute_math(x, MATH_TANH);
        print_math_result(&r);

        /* Inversas */
        r = compute_math(x, MATH_ASINH);
        print_math_result(&r);

        if (x >= 1.0)
        {
            r = compute_math(x, MATH_ACOSH);
            print_math_result(&r);
        }

        if (x > -1.0 && x < 1.0)
        {
            r = compute_math(x, MATH_ATANH);
            print_math_result(&r);
        }

        printf("--------------------------------------------------\n\n");
    }
    return 0;
}
