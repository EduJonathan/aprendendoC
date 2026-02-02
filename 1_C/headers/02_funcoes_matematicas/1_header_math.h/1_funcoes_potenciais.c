#include <stdio.h>
#include <math.h>

// Enumeração para os tipos de operações matemáticas suportadas
typedef enum
{
    MATH_POW,
    MATH_CBRT,
    MATH_HYPOT,
    MATH_SQRT,
    MATH_COUNT // Conta o número total de operações
} FUNCOES_POTENCIAIS;

// Estrutura de metadados para operações matemáticas, Cada operação tem um tipo, nome e número de argumentos.
typedef struct
{
    FUNCOES_POTENCIAIS type; // Tipo da operação
    const char *name;        // Nome da operação
    int num_args;            // Número de argumentos necessários para a operação
} Metadados;

/**
 * @brief Tabela de metadados para as operações matemáticas suportadas
 *
 * Cada entrada contém o tipo da operação, o nome e o número de argumentos necessários.
 */
const Metadados MATH_LOOKUP[MATH_COUNT] = {
    [MATH_POW]   = {MATH_POW,   "pow",   2},
    [MATH_CBRT]  = {MATH_CBRT,  "cbrt",  1},
    [MATH_HYPOT] = {MATH_HYPOT, "hypot", 2},
    [MATH_SQRT]  = {MATH_SQRT,  "sqrt",  1}};

/**
 * @brief Estrutura para armazenar os resultados de uma operação matemática
 * em diferentes precisões. Inclui os argumentos usados e o tipo da operação.
 */
typedef struct
{
    double x;                // Primeiro argumento
    double y;                // Segundo argumento (se aplicável)
    float f_result;          // Resultado em precisão float
    double d_result;         // Resultado em precisão double
    long double ld_result;   // Resultado em precisão long double
    FUNCOES_POTENCIAIS type; // Tipo da operação matemática
} ResultadosMatematicos;

/**
 * @brief Função para computar a operação matemática especificada
 *
 * @param x Primeiro argumento
 * @param y Segundo argumento (se aplicável)
 * @param type Tipo da operação matemática
 * @return ResultadosMatematicos Estrutura contendo os resultados em diferentes precisões
 */
ResultadosMatematicos compute_math(double x, double y, FUNCOES_POTENCIAIS type)
{
    // Inicializa a estrutura de resultados
    ResultadosMatematicos res = {
        .x = x,
        .y = y,
        .type = type};

    // Verifica se o tipo de operação é válido
    if (type < 0 || type >= MATH_COUNT)
        return res;

    switch (type)
    {
    case MATH_POW:
        res.f_result = powf((float)x, (float)y);
        res.d_result = pow(x, y);
        res.ld_result = powl((long double)x, (long double)y);
        break;

    case MATH_CBRT:
        res.f_result = cbrtf((float)x);
        res.d_result = cbrt(x);
        res.ld_result = cbrtl((long double)x);
        break;

    case MATH_HYPOT:
        res.f_result = hypotf((float)x, (float)y);
        res.d_result = hypot(x, y);
        res.ld_result = hypotl((long double)x, (long double)y);
        break;

    case MATH_SQRT:
        res.f_result = sqrtf((float)x);
        res.d_result = sqrt(x);
        res.ld_result = sqrtl((long double)x);
        break;
    }

    return res;
}

/**
 * @brief Função para imprimir os resultados de uma operação matemática
 *
 * @param r Ponteiro para a estrutura ResultadosMatematicos contendo os resultados
 */
void print_math_result(const ResultadosMatematicos *r)
{
    // Obtém os metadados da operação
    const Metadados *meta = &MATH_LOOKUP[r->type];

    // Se o número de argumentos for 2, imprime ambos os argumentos, se não, apenas o primeiro
    if (meta->num_args == 2)
        printf("[%s] f(%.10g, %.10g)\n", meta->name, r->x, r->y);
    else
        printf("[%s] f(%.10g)\n", meta->name, r->x);

    // Imprime os resultados em diferentes precisões
    printf("  float       = %.9g\n", r->f_result);
    printf("  double      = %.17g\n", r->d_result);
    printf("  long double = %.21Lg\n", r->ld_result);
    printf("\n");
}

int main(int argc, char **argv)
{
    ResultadosMatematicos r1 = compute_math(2.0,  3.0, MATH_POW);
    ResultadosMatematicos r2 = compute_math(27.0, 0.0, MATH_CBRT);
    ResultadosMatematicos r3 = compute_math(3.0,  4.0, MATH_HYPOT);
    ResultadosMatematicos r4 = compute_math(16.0, 0.0, MATH_SQRT);

    /* Caso interessante para erro numérico */
    ResultadosMatematicos r5 = compute_math(10.0, 0.3333333333333, MATH_POW);

    print_math_result(&r1);
    print_math_result(&r2);
    print_math_result(&r3);
    print_math_result(&r4);
    print_math_result(&r5);

    return 0;
}
