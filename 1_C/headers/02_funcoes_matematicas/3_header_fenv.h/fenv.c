#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <fenv.h>

#pragma STDC FENV_ACCESS ON

/**
 * @brief Modos de arredondamento disponíveis
 */
typedef enum
{
    ROUND_NEAREST_TIE_EVEN = FE_TONEAREST, // Padrão IEEE 754
    ROUND_TOWARD_POSITIVE = FE_UPWARD,
    ROUND_TOWARD_NEGATIVE = FE_DOWNWARD,
    ROUND_TOWARD_ZERO = FE_TOWARDZERO,
    ROUND_DEFAULT = FE_TONEAREST
} rounding_mode_t;

/**
 * @brief Flags de exceção de ponto flutuante
 */
typedef enum
{
    EXC_INVALID_OPERATION = FE_INVALID,
    EXC_DIVISION_BY_ZERO = FE_DIVBYZERO,
    EXC_OVERFLOW = FE_OVERFLOW,
    EXC_UNDERFLOW = FE_UNDERFLOW,
    EXC_INEXACT = FE_INEXACT,
    EXC_ALL = FE_ALL_EXCEPT,
    EXC_NONE = 0
} fp_exception_t;

/**
 * @brief Status de operações com fenv
 */
typedef enum
{
    FENV_SUCCESS = 0,
    FENV_ERROR = -1,
    FENV_EXCEPTION_ACTIVE = 1
} fenv_status_t;

/**
 * @brief Converte modo de arredondamento para string
 *
 * @param mode Modo de arredondamento
 * @return const char* Representação em string do modo
 */
static const char *rounding_mode_to_string(rounding_mode_t mode)
{
    switch (mode)
    {
    case ROUND_NEAREST_TIE_EVEN:
        return "Arredondamento para mais próximo (empate para par)";

    case ROUND_TOWARD_POSITIVE:
        return "Arredondamento para +infinito";

    case ROUND_TOWARD_NEGATIVE:
        return "Arredondamento para -infinito";

    case ROUND_TOWARD_ZERO:
        return "Arredondamento para zero (truncamento)";

    default:
        return "Modo desconhecido";
    }
}

/**
 * @brief Verifica se uma exceção específica está ativa
 *
 * @param exc Exceção a ser verificada
 * @return true Se a exceção estiver ativa
 * @return false Se a exceção não estiver ativa
 */
static bool fp_exception_is_active(fp_exception_t exc)
{
    return fetestexcept(exc) != 0;
}

/**
 * @brief Limpa exceções específicas
 *
 * @param exc Exceção a ser limpa
 */
static void fp_exception_clear(fp_exception_t exc)
{
    feclearexcept(exc);
}

/**
 * @brief Sinaliza uma exceção
 *
 * @param exc Exceção a ser sinalizada
 */
static void fp_exception_raise(fp_exception_t exc)
{
    feraiseexcept(exc);
}

/**
 * @brief Obtém o modo de arredondamento atual
 *
 * @return rounding_mode_t Modo de arredondamento atual
 */
static rounding_mode_t get_current_rounding_mode(void)
{
    return (rounding_mode_t)fegetround();
}

/**
 * @brief Define o modo de arredondamento
 *
 * @param mode Modo de arredondamento a ser definido
 * @return fenv_status_t Status da operação
 */
static fenv_status_t set_rounding_mode(rounding_mode_t mode)
{
    return (fesetround(mode) == 0) ? FENV_SUCCESS : FENV_ERROR;
}

/**
 * @brief Demonstra o gerenciamento de exceções de ponto flutuante
 */
void test_fenv_exception(void)
{
    printf("=== TESTE DE EXCEÇÕES DE PONTO FLUTUANTE ===\n\n");

    fexcept_t flag;
    bool has_exceptions;

    // 1. Estado inicial
    fp_exception_clear(EXC_ALL);
    has_exceptions = fp_exception_is_active(EXC_ALL);

    printf("Estado inicial:\n");
    printf("  - Exceções ativas: %s\n\n", has_exceptions ? "SIM" : "NÃO");

    // 2. Levantar exceção de divisão por zero
    printf("Levantando exceção de divisão por zero...\n");
    fp_exception_raise(EXC_DIVISION_BY_ZERO);

    if (fp_exception_is_active(EXC_DIVISION_BY_ZERO))
    {
        printf("  ✓ Exceção de divisão por zero ativada\n");
    }

    // 3. Salvar estado
    fegetexceptflag(&flag, EXC_ALL);
    printf("  ✓ Estado das exceções salvo\n\n");

    // 4. Limpar exceção e verificar
    fp_exception_clear(EXC_DIVISION_BY_ZERO);
    printf("Exceção limpa. Verificando estado:\n");

    if (!fp_exception_is_active(EXC_DIVISION_BY_ZERO))
    {
        printf("  ✓ Exceção de divisão por zero foi limpa\n");
    }

    // 5. Restaurar estado
    fesetexceptflag(&flag, EXC_ALL);
    printf("\nEstado restaurado. Verificando:\n");

    if (fp_exception_is_active(EXC_DIVISION_BY_ZERO))
    {
        printf("  ✓ Exceção de divisão por zero foi restaurada\n");
    }

    // 6. Limpeza final
    fp_exception_clear(EXC_ALL);
    printf("\nFinal: Todas as exceções foram limpas.\n");
}

/**
 * @brief Demonstra diferentes modos de arredondamento
 */
void test_rounding_modes(void)
{
    printf("\n=== TESTE DE MODOS DE ARREDONDAMENTO ===\n\n");

    rounding_mode_t original_mode = get_current_rounding_mode();
    double numerator = 1.0;
    double denominator = 3.0;
    double exact_value = numerator / denominator; // 0.333333...

    printf("Valor exato: 1.0 / 3.0 = %.15f\n\n", exact_value);
    printf("Modo original: %s\n\n", rounding_mode_to_string(original_mode));

    // Testar cada modo de arredondamento
    rounding_mode_t modes[] = {
        ROUND_NEAREST_TIE_EVEN,
        ROUND_TOWARD_POSITIVE,
        ROUND_TOWARD_NEGATIVE,
        ROUND_TOWARD_ZERO};

    const char *mode_names[] = {
        "FE_TONEAREST",
        "FE_UPWARD",
        "FE_DOWNWARD",
        "FE_TOWARDZERO"};

    for (size_t i = 0; i < sizeof(modes) / sizeof(modes[0]); i++)
    {
        if (set_rounding_mode(modes[i]) == FENV_SUCCESS)
        {
            double result = numerator / denominator;
            printf("Modo: %s\n", mode_names[i]);
            printf("Descrição: %s\n", rounding_mode_to_string(modes[i]));
            printf("Resultado: %.15f\n", result);
            printf("Diferença: %+.15f\n\n", result - exact_value);
        }
    }

    // Restaurar modo original
    set_rounding_mode(original_mode);
    printf("Modo de arredondamento restaurado para o original.\n");
}

/**
 * @brief Demonstra operações avançadas com ambiente de ponto flutuante
 */
void test_fenv_operations(void)
{
    printf("\n=== TESTE DE OPERAÇÕES AVANÇADAS DO AMBIENTE ===\n\n");

    fenv_t original_env, saved_env;

    // 1. Salvar ambiente original
    if (fegetenv(&original_env) != 0)
    {
        printf("✗ Erro ao obter ambiente original\n");
        return;
    }
    printf("✓ Ambiente original salvo\n");

    // 2. Criar um novo ambiente com exceção
    feclearexcept(EXC_ALL);
    fp_exception_raise(EXC_INVALID_OPERATION);
    printf("✓ Exceção de operação inválida levantada\n");

    // 3. Verificar exceção
    if (fp_exception_is_active(EXC_INVALID_OPERATION))
    {
        printf("✓ Exceção está ativa\n");
    }

    // 4. Salvar ambiente atual e congelar exceções
    feholdexcept(&saved_env);
    printf("\n✓ Ambiente salvo com feholdexcept()\n");
    printf("  Exceções congeladas: %s\n", fp_exception_is_active(EXC_INVALID_OPERATION) ? "NÃO" : "SIM");

    // 5. Modificar ambiente atual
    set_rounding_mode(ROUND_TOWARD_POSITIVE);
    printf("\n✓ Modo de arredondamento alterado para FE_UPWARD\n");

    // 6. Restaurar ambiente original com atualização
    feupdateenv(&original_env);
    printf("✓ Ambiente atualizado com estado original\n");

    // Verificar se exceções do ambiente original foram mantidas
    printf("  Exceções após update: %s\n", fp_exception_is_active(EXC_ALL) ? "ATIVAS" : "INATIVAS");

    // 7. Restaurar ambiente salvo
    if (fesetenv(&saved_env) == 0)
    {
        printf("\n✓ Ambiente restaurado com fesetenv()\n");
        printf("  Modo de arredondamento atual: %s\n", rounding_mode_to_string(get_current_rounding_mode()));
    }

    // 8. Limpeza final
    fp_exception_clear(EXC_ALL);
    fesetenv(&original_env);
    printf("\n✓ Ambiente totalmente restaurado ao estado inicial\n");
}

/**
 * @brief Demonstra o impacto do arredondamento em operações reais
 */
void test_rounding_impact(void)
{
    printf("\n=== IMPACTO DO ARREDONDAMENTO EM CÁLCULOS ===\n\n");

    const double values[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    const size_t count = sizeof(values) / sizeof(values[0]);

    rounding_mode_t modes[] = {
        ROUND_NEAREST_TIE_EVEN,
        ROUND_TOWARD_POSITIVE,
        ROUND_TOWARD_NEGATIVE,
        ROUND_TOWARD_ZERO};

    const char *mode_titles[] = {
        "TONEAREST",
        "UPWARD",
        "DOWNWARD",
        "TOWARDZERO"};

    rounding_mode_t original_mode = get_current_rounding_mode();

    for (size_t m = 0; m < sizeof(modes) / sizeof(modes[0]); m++)
    {
        set_rounding_mode(modes[m]);

        double sum = 0.0;
        double product = 1.0;

        printf("Modo: %s\n", mode_titles[m]);
        printf("Valores: ");

        for (size_t i = 0; i < count; i++)
        {
            printf("%.1f ", values[i]);
            sum += values[i];
            product *= values[i];
        }

        printf("\n  Soma:      %12.8f\n", sum);
        printf("  Produto:   %12.8f\n", product);
        printf("  Média:     %12.8f\n\n", sum / count);
    }

    set_rounding_mode(original_mode);
}

int main(void)
{
    printf("===============================================\n");
    printf("TESTE DA BIBLIOTECA <fenv.h>\n");
    printf("Compilador: %s\n",
#if defined(__STDC_VERSION__)
           __STDC_VERSION__ >= 199901L ? "C99 ou superior" : "C89/C90"
#else
           "Desconhecido"
#endif
    );

    printf("IEEE 754 Suportado: %s\n", FE_TONEAREST == 0 ? "Provavelmente SIM" : "Verificar implementação");
    printf("===============================================\n\n");

    // Testar funcionalidades básicas
    test_fenv_exception();

    printf("\n");
    for (int i = 0; i < 50; i++)
        printf("-");
    printf("\n");

    // Testar modos de arredondamento
    test_rounding_modes();

    printf("\n");
    for (int i = 0; i < 50; i++)
        printf("-");
    printf("\n");

    // Testar operações avançadas
    test_fenv_operations();

    printf("\n");
    for (int i = 0; i < 50; i++)
        printf("-");
    printf("\n");

    // Teste adicional: impacto prático
    test_rounding_impact();

    printf("\n===============================================\n");
    printf("TESTES CONCLUÍDOS\n");
    printf("Modo final de arredondamento: %s\n", rounding_mode_to_string(get_current_rounding_mode()));

    // Verificar se alguma exceção permanece ativa
    if (fp_exception_is_active(EXC_ALL))
    {
        printf("AVISO: Exceções de ponto flutuante ativas ao final!\n");
        fp_exception_clear(EXC_ALL);
    }

    printf("===============================================\n");

    return 0;
}
