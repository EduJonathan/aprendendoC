#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <limits.h>

/**
 * @brief Enumeração para os tipos de funções de conversão de strings suportadas
 */
typedef enum
{
    CONV_ATOF,
    CONV_ATOI,
    CONV_ATOL,
    CONV_STRTOD,
    CONV_STRTOL,
    CONV_STRTOUL,
    CONV_COUNT // Conta o número total de conversores
} CONV_TIPO;

/**
 * @brief Estrutura que descreve cada conversor
 * Cada entrada tem tipo, nome, argumentos e ponteiros para as funções reais.
 */
typedef struct
{
    CONV_TIPO type;
    const char *name;
    int num_args; // Quantidade de argumentos necessários

    // Ponteiros para as funções (assinaturas diferentes)
    double (*func_atof)(const char *);
    int (*func_atoi)(const char *);
    long (*func_atol)(const char *);
    double (*func_strtod)(const char *, char **);
    long (*func_strtol)(const char *, char **, int);
    unsigned long (*func_strtoul)(const char *, char **, int);
} Conversor;

/**
 * @brief Tabela central de conversores – tudo definido aqui
 */
const Conversor CONVERSORES[CONV_COUNT] = {
    [CONV_ATOF] = {CONV_ATOF, "atof", 1, atof, NULL, NULL, NULL, NULL, NULL},
    [CONV_ATOI] = {CONV_ATOI, "atoi", 1, NULL, atoi, NULL, NULL, NULL, NULL},
    [CONV_ATOL] = {CONV_ATOL, "atol", 1, NULL, NULL, atol, NULL, NULL, NULL},
    [CONV_STRTOD] = {CONV_STRTOD, "strtod", 2, NULL, NULL, NULL, strtod, NULL, NULL},
    [CONV_STRTOL] = {CONV_STRTOL, "strtol", 3, NULL, NULL, NULL, NULL, strtol, NULL},
    [CONV_STRTOUL] = {CONV_STRTOUL, "strtoul", 3, NULL, NULL, NULL, NULL, NULL, strtoul},
};

/**
 * @brief Estrutura para armazenar os resultados de uma conversão
 */
typedef struct
{
    const char *input;    // String original
    double d_val;         // Resultado double (para atof/strtod)
    long l_val;           // Resultado long (para atoi/atol/strtol)
    unsigned long ul_val; // Resultado unsigned long (para strtoul)
    char *endptr;         // Ponteiro para caractere não convertido
    int errno_val;        // Valor de errno após conversão
    CONV_TIPO type;       // Tipo do conversor usado
} ResultadoConv;

/**
 * @brief Função que executa a conversão usando a tabela
 *
 * @param str String a ser convertida
 * @param base Base para strtol/strtoul (0 para auto-detectar)
 * @param tipo Tipo do conversor
 * @return ResultadoConv com valores e status
 */
ResultadoConv converter(const char *str, int base, CONV_TIPO tipo)
{
    ResultadoConv res = {.input = str, .d_val = 0.0, .l_val = 0L, .ul_val = 0UL, .endptr = NULL, .errno_val = 0, .type = tipo};

    // Verificações iniciais
    if (str == NULL || *str == '\0')
    {
        res.errno_val = EINVAL;
        res.endptr = (char *)str;
        return res;
    }
    if (tipo < 0 || tipo >= CONV_COUNT)
    {
        res.errno_val = EINVAL;
        return res;
    }

    const Conversor *conv = &CONVERSORES[tipo];

    // Validação de base para strtol/strtoul
    if ((tipo == CONV_STRTOL || tipo == CONV_STRTOUL) && (base != 0 && (base < 2 || base > 36)))
    {
        res.errno_val = EINVAL;
        return res;
    }

    char *local_end = NULL;
    errno = 0;

    // Chamadas via ponteiros
    if (conv->func_atof)
        res.d_val = conv->func_atof(str);

    if (conv->func_atoi)
        res.l_val = conv->func_atoi(str);

    if (conv->func_atol)
        res.l_val = conv->func_atol(str);

    if (conv->func_strtod)
        res.d_val = conv->func_strtod(str, &local_end);

    if (conv->func_strtol)
        res.l_val = conv->func_strtol(str, &local_end, base);

    if (conv->func_strtoul)
        res.ul_val = conv->func_strtoul(str, &local_end, base);

    res.endptr = local_end ? local_end : (char *)(str + strlen(str));
    res.errno_val = errno;

    // Detecção extra de falha total (nenhum caractere convertido)
    if (res.endptr == str && res.errno_val == 0)
    {
        res.errno_val = EINVAL;
    }

    // Checagem extra de overflow/underflow (para strtol/strtoul)
    if (res.errno_val == ERANGE)
    {
        if (tipo == CONV_STRTOL && res.l_val == LONG_MIN)
        {
            // Underflow detectado
        }
        else if (tipo == CONV_STRTOUL && res.ul_val == ULONG_MAX)
        {
            // Overflow detectado
        }
    }

    return res;
}

/**
 * @brief Imprime os resultados da conversão
 *
 * @param r Ponteiro para o resultado
 */
void print_conv(const ResultadoConv *r)
{
    if (!r || !r->input)
    {
        printf("[ERRO] Resultado inválido\n\n");
        return;
    }

    const Conversor *c = &CONVERSORES[r->type];

    printf("[%s] \"%s\"", c->name, r->input);
    if (c->num_args >= 3)
    {
        printf(" (base %d)", 10);
    }
    printf("\n");

    if (r->errno_val != 0)
    {
        printf("  ERRO: %s (código %d)\n", strerror(r->errno_val), r->errno_val);
    }
    else if (r->endptr == r->input)
    {
        printf("  AVISO: Nenhum caractere válido convertido\n");
    }

    if (r->endptr && *r->endptr != '\0')
    {
        printf("  Parou em: \"%s\"\n", r->endptr);
    }

    switch (r->type)
    {
    case CONV_ATOF:
    case CONV_STRTOD:
        printf("  double  = %.17g\n", r->d_val);
        break;

    case CONV_ATOI:
    case CONV_ATOL:
    case CONV_STRTOL:
        printf("  long    = %ld\n", r->l_val);
        break;

    case CONV_STRTOUL:
        printf("  ulong   = %lu\n", r->ul_val);
        break;

    default:
        break;
    }

    printf("\n");
}

typedef struct
{
    const char *input;
    int base;
    CONV_TIPO tipo;
} CasoTeste;

const CasoTeste testes[] = {
    // Casos normais
    {"  -123.4567abc", 0, CONV_ATOF},
    {"  -123.4567abc", 0, CONV_STRTOD},
    {"  2147483647", 0, CONV_ATOI},
    {"  9223372036854775807", 0, CONV_ATOL},
    {"  0xCAFEBABE", 0, CONV_STRTOUL},

    // Casos de erro
    {NULL, 0, CONV_STRTOD},
    {"", 0, CONV_ATOI},
    {"abc", 0, CONV_STRTOL},
    {"999999999999999999999", 10, CONV_STRTOL},
    {"-999999999999999999999", 10, CONV_STRTOL},
    {"123", 37, CONV_STRTOUL},
};

int main(int argc, char **argv)
{
    printf("Testes de conversão (incluindo erros):\n");
    printf("----------------------------------------\n\n");

    size_t total = sizeof(testes) / sizeof(testes[0]);

    for (size_t i = 0; i < total; i++)
    {
        ResultadoConv r = converter(testes[i].input, testes[i].base, testes[i].tipo);
        print_conv(&r);
    }

    return 0;
}
