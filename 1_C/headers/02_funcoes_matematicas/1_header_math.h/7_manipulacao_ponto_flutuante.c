#include <stdio.h>
#include <math.h>
#include <float.h> // para FP_ILOGB0, FP_ILOGBNAN, etc.

/* Enumeração das operações */
typedef enum
{
    MATH_FREXP,
    MATH_LDEXP,
    MATH_MODF,
    MATH_SCALBN,
    MATH_SCALBLN,
    MATH_ILOGB,
    MATH_LOGB,
    MATH_NEXTAFTER,
    MATH_NEXTTOWARD,
    MATH_COPYSIGN,
    MATH_COUNT
} FUNCOES_MANIPULACAO;

/* Estrutura que descreve cada operação */
typedef struct
{
    FUNCOES_MANIPULACAO type;
    const char *name;
    int num_args; // 1 ou 2

    // Funções de 1 ou 2 argumentos float/double/ldouble
    float       (*f_func) (float);
    double      (*d_func) (double);
    long double (*ld_func)(long double);

    // Funções com 2 args (ex: ldexp, scalbn, nextafter...)
    float       (*f_func2) (float, float); // ou int/long int promovido
    double      (*d_func2) (double, double);
    long double (*ld_func2)(long double, long double);

    // frexp
    float       (*f_frexp) (float, int *);
    double      (*d_frexp) (double, int *);
    long double (*ld_frexp)(long double, int *);

    // modf
    float       (*f_modf) (float, float *);
    double      (*d_modf) (double, double *);
    long double (*ld_modf)(long double, long double *);
} MathOperation;

/* Tabela central */
const MathOperation MATH_OPERATIONS[MATH_COUNT] = {
    [MATH_FREXP] = 
    {
        MATH_FREXP, "frexp", 1,
        NULL, NULL, NULL, NULL, NULL, NULL, 
        frexpf, frexp, frexpl, 
        NULL, NULL, NULL
    },

    [MATH_LDEXP] = 
    {
        MATH_LDEXP, "ldexp", 2,
        NULL, NULL, NULL,
        ldexpf, ldexp, ldexpl,
        NULL, NULL, NULL, NULL, NULL, NULL
    },

    [MATH_MODF] =
    {
        MATH_MODF, "modf", 1,
        NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL, NULL,
        modff, modf, modfl
    },

    [MATH_SCALBN] =
    {
        MATH_SCALBN, "scalbn", 2,
        NULL, NULL, NULL,
        scalbnf, scalbn, scalbnl,
        NULL, NULL, NULL, NULL, NULL, NULL
    },

    [MATH_SCALBLN] = 
    {
        MATH_SCALBLN, "scalbln", 2,
        NULL, NULL, NULL,
        scalblnf, scalbln, scalblnl,
        NULL, NULL, NULL, NULL, NULL, NULL
    },

    [MATH_ILOGB] =
    {
        MATH_ILOGB, "ilogb", 1,
        NULL, NULL, NULL,
        ilogbf, ilogb, ilogbl,
        NULL, NULL, NULL, NULL, NULL, NULL
    },

    [MATH_LOGB] =
    {
        MATH_LOGB, "logb", 1,
        logbf, logb, logbl,
        NULL, NULL, NULL, NULL, NULL,
        NULL, NULL, NULL, NULL
    },

    [MATH_NEXTAFTER] =
    {
        MATH_NEXTAFTER, "nextafter", 2,
        NULL, NULL, NULL,
        nextafterf, nextafter, nextafterl,
        NULL, NULL, NULL, NULL, NULL, NULL
    },

    [MATH_NEXTTOWARD] =
    {
        MATH_NEXTTOWARD, "nexttoward", 2,
        NULL, NULL, NULL,
        nexttowardf, nexttoward, nexttowardl,
        NULL, NULL, NULL, NULL, NULL, NULL
    },

    [MATH_COPYSIGN] =
    {
        MATH_COPYSIGN, "copysign", 2,
        NULL, NULL, NULL,
        copysignf, copysign, copysignl,
        NULL, NULL, NULL, NULL, NULL, NULL
    },
};

/* Estrutura de resultados – adaptada para vários retornos */
typedef struct
{
    double x;
    double y; // segundo argumento quando necessário
    float f_result;
    double d_result;
    long double ld_result;
    int f_exp; // para frexp ou ilogb
    int d_exp;
    int ld_exp;
    double f_intpart; // para modf
    double d_intpart;
    long double ld_intpart;
    FUNCOES_MANIPULACAO type;
} ResultadosMatematicos;

/**
 * @brief Computa o resultado da operação matemática especificada
 * 
 * @param x Primeiro argumento (ou único argumento)
 * @param y Segundo argumento (usado apenas para funções de 2 args, caso contrário pode ser 0)
 * @param type Tipo da operação a ser realizada
 * @return Estrutura contendo os resultados para float, double e long double
 * 
 * Observação: Para funções de 1 argumento, o campo 'y' é ignorado. Para funções de 2 argumentos,
 * ambos 'x' e 'y' são usados. O campo 'type' indica qual operação foi realizada, permitindo uma impressão adaptada dos resultados.
*/
ResultadosMatematicos compute_math(double x, double y, FUNCOES_MANIPULACAO type)
{
    ResultadosMatematicos res =
    {
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
        .ld_intpart = 0.0L
    };

    if (type >= MATH_COUNT)
        return res;

    const MathOperation *op = &MATH_OPERATIONS[type];

    // frexp
    if (op->f_frexp)
        res.f_result  = op->f_frexp((float)x, &res.f_exp);

    if (op->d_frexp)
        res.d_result  = op->d_frexp(x, &res.d_exp);

    if (op->ld_frexp)
        res.ld_result = op->ld_frexp((long double)x, &res.ld_exp);

    // modf
    if (op->f_modf)
    {
        float ip      = 0.0f;
        res.f_result  = op->f_modf((float)x, &ip);
        res.f_intpart = ip;
    }
    if (op->d_modf)
    {
        double ip     = 0.0;
        res.d_result  = op->d_modf(x, &ip);
        res.d_intpart = ip;
    }

    if (op->ld_modf)
    {
        long double ip = 0.0L;
        res.ld_result  = op->ld_modf((long double)x, &ip);
        res.ld_intpart = ip;
    }

    // ldexp, scalbn, scalbln, nextafter, nexttoward, copysign
    if (op->f_func2)
    {
        if (type == MATH_LDEXP || type == MATH_SCALBN)
        {
            int exp = (int)y;
            res.f_result  = ((float (*)(float, int))op->f_func2)((float)x, exp);
            res.d_result  = ((double (*)(double, int))op->d_func2)(x, exp);
            res.ld_result = ((long double (*)(long double, int))op->ld_func2)((long double)x, exp);
        }
        else
        {
            // nextafter, nexttoward, copysign usam o segundo arg como float/double/ldouble
            res.f_result  = op->f_func2((float)x, (float)y);
            res.d_result  = op->d_func2(x, y);
            res.ld_result = op->ld_func2((long double)x, (long double)y);
        }
    }

    // ilogb (retorna int)
    if (type == MATH_ILOGB)
    {
        res.f_exp  = ilogbf((float)x);
        res.d_exp  = ilogb(x);
        res.ld_exp = ilogbl((long double)x);
    }

    // logb (retorna floating-point)
    if (op->f_func)
        res.f_result  = op->f_func((float)x);

    if (op->d_func)
        res.d_result  = op->d_func(x);

    if (op->ld_func)
        res.ld_result = op->ld_func((long double)x);

    return res;
}

/* Impressão adaptada */
void print_math_result(const ResultadosMatematicos *r)
{
    const MathOperation *op = &MATH_OPERATIONS[r->type];
    const char *nome = op->name;

    if (op->num_args == 2)
    {
        printf("[%s] (%.12g, %.12g)\n", nome, r->x, r->y);
    }
    else
    {
        printf("[%s] (%.12g)\n", nome, r->x);
    }

    if (r->type == MATH_FREXP)
    {
        printf(" float:  mantissa = %.8g   exp = %d\n", r->f_result, r->f_exp);
        printf(" double: mantissa = %.16g  exp = %d\n", r->d_result, r->d_exp);
        printf(" ldouble mantissa = %.20Lg exp = %d\n", r->ld_result, r->ld_exp);
    }
    else if (r->type == MATH_MODF)
    {
        printf(" float:  fração = %.8g   inteira = %.8g\n", r->f_result, r->f_intpart);
        printf(" double: fração = %.16g  inteira = %.16g\n", r->d_result, r->d_intpart);
        printf(" ldouble fração = %.20Lg inteira = %.20Lg\n", r->ld_result, r->ld_intpart);
    }
    else if (r->type == MATH_ILOGB)
    {
        printf(" float:  expoente = %d\n", r->f_exp);
        printf(" double: expoente = %d\n", r->d_exp);
        printf(" ldouble expoente = %d\n", r->ld_exp);
        if (r->d_exp == FP_ILOGB0)
            printf("   → FP_ILOGB0 (zero ou subnormal)\n");

        if (r->d_exp == FP_ILOGBNAN)
            printf("   → FP_ILOGBNAN (NaN)\n");
    }
    else
    {
        // ldexp, scalbn, scalbln, logb, nextafter, nexttoward, copysign
        printf(" float:  %.10g\n", (double)r->f_result);
        printf(" double: %.18g\n", r->d_result);
        printf(" ldouble %.22Lg\n", r->ld_result);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    printf("=== Manipulação de ponto flutuante (IEEE 754) ===\n\n");

    const struct
    {
        double x;
        double y;
        FUNCOES_MANIPULACAO type;
    } tests[] = {
        {13.625,    0.0,       MATH_FREXP},
        {-6.5,      0.0,       MATH_MODF},
        {3.0,       4.0,       MATH_LDEXP},  // 3.0 * 2^4 = 48.0
        {1.5,       3.0,       MATH_SCALBN}, // 1.5 * 2^3 = 12.0
        {1.5,       3L,        MATH_SCALBLN},
        {0.0,       0.0,       MATH_ILOGB},
        {INFINITY,  0.0,       MATH_ILOGB},
        {NAN,       0.0,       MATH_ILOGB},
        {3.14159,   0.0,       MATH_LOGB},
        {1.0000001, 1.000001,  MATH_NEXTAFTER},
        {1.0000001, 1.000001L, MATH_NEXTTOWARD},
        {-4.75,    -7.2,       MATH_COPYSIGN},
        {5.0,      -0.0,       MATH_COPYSIGN},
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        ResultadosMatematicos r = compute_math(tests[i].x, tests[i].y, tests[i].type);
        print_math_result(&r);
    }

    return 0;
}
