#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>

// Enum para identificar as funções de ctype
typedef enum
{
    CTYPE_ISASCII,
    CTYPE_ISALNUM,
    CTYPE_ISALPHA,
    CTYPE_ISBLANK,
    CTYPE_ISCNTRL,
    CTYPE_ISDIGIT,
    CTYPE_ISGRAPH,
    CTYPE_ISLOWER,
    CTYPE_ISPRINT,
    CTYPE_ISPUNCT,
    CTYPE_ISSPACE,
    CTYPE_ISUPPER,
    CTYPE_ISXDIGIT,
    CTYPE_TOLOWER,
    CTYPE_TOUPPER,
    CTYPE_COUNT
} CtypeFunction;

// Estrutura que representa uma operação da biblioteca ctype
typedef struct
{
    CtypeFunction tipo;      // Tipo da função ctype
    const char *nome;        // Nome da função
    int (*verificar)  (int); // Função de verificação/classificação
    int (*transformar)(int); // Função de transformação
} OperacaoCType;

/**
 * Definição da tabela de operações disponíveis
 * Obs: isascii não é padrão C, pode ser removido se necessário, ou apenas comentar
 */
const OperacaoCType OPERACOES_CTYPE[CTYPE_COUNT] = {
    // {CTYPE_ISASCII,  "isascii",   isascii,  NULL},
    {CTYPE_ISALNUM,  "isalnum",   isalnum,  NULL},
    {CTYPE_ISALPHA,  "isalpha",   isalpha,  NULL},
    {CTYPE_ISBLANK,  "isblank",   isblank,  NULL},
    {CTYPE_ISCNTRL,  "iscntrl",   iscntrl,  NULL},
    {CTYPE_ISDIGIT,  "isdigit",   isdigit,  NULL},
    {CTYPE_ISGRAPH,  "isgraph",   isgraph,  NULL},
    {CTYPE_ISLOWER,  "islower",   islower,  NULL},
    {CTYPE_ISPRINT,  "isprint",   isprint,  NULL},
    {CTYPE_ISPUNCT,  "ispunct",   ispunct,  NULL},
    {CTYPE_ISSPACE,  "isspace",   isspace,  NULL},
    {CTYPE_ISUPPER,  "isupper",   isupper,  NULL},
    {CTYPE_ISXDIGIT, "isxdigit",  isxdigit, NULL},
    {CTYPE_TOLOWER,  "tolower",   NULL,     tolower},
    {CTYPE_TOUPPER,  "toupper",   NULL,     toupper}
};

// Estrutura que armazena o resultado da aplicação em um caractere
typedef struct
{
    char entrada;       // Caractere de entrada
    int saida;          // Resultado da operação
    CtypeFunction tipo; // Tipo da função aplicada
} ResultadoCaractere;

// Estrutura que armazena o resultado da aplicação em uma string
typedef struct
{
    const char *entrada; // String de entrada
    bool resultado;      // Resultado final da verificação
    CtypeFunction tipo;  // Tipo da função aplicada
} ResultadoString;

// Política de avaliação de strings
typedef enum
{
    STRING_TODOS,   // Todos os caracteres devem passar no teste
    STRING_QUALQUER // Pelo menos um caractere deve passar
} PoliticaString;

/**
 * @brief Aplica uma função ctype a um único caractere
 *
 * @param c Caractere a ser avaliado
 * @param tipo Tipo da função ctype
 * @return ResultadoCaractere Estrutura com o resultado
 */
ResultadoCaractere aplicar_ctype_caractere(char c, CtypeFunction tipo)
{
    ResultadoCaractere resultado = {.entrada = c, .saida = 0, .tipo = tipo};

    if (tipo >= CTYPE_COUNT)
        return resultado;

    const OperacaoCType *op = &OPERACOES_CTYPE[tipo];
    int valor = (unsigned char)c;

    if (op->verificar)
        resultado.saida = op->verificar(valor);
    else if (op->transformar)
        resultado.saida = op->transformar(valor);

    return resultado;
}

/**
 * @brief Aplica uma função de verificação ctype a todos os caracteres de uma string
 *
 * @param texto String a ser avaliada
 * @param tipo Tipo da função ctype
 * @param politica Política de avaliação da string
 * @return ResultadoString Estrutura com o resultado
 */
ResultadoString aplicar_ctype_string(const char *texto, CtypeFunction tipo, PoliticaString politica)
{
    ResultadoString resultado = {
        .entrada = texto,
        .resultado = (politica == STRING_TODOS),
        .tipo = tipo
    };

    if (!texto || tipo >= CTYPE_COUNT)
        return resultado;

    const OperacaoCType *op = &OPERACOES_CTYPE[tipo];

    if (!op->verificar)
        return resultado;

    while (*texto)
    {
        ResultadoCaractere r = aplicar_ctype_caractere(*texto, tipo);
        bool valido = r.saida != 0;

        if (politica == STRING_TODOS && !valido)
        {
            resultado.resultado = false;
            return resultado;
        }

        if (politica == STRING_QUALQUER && valido)
        {
            resultado.resultado = true;
            return resultado;
        }

        texto++;
    }

    return resultado;
}

/**
 * @brief Transforma uma string aplicando uma função ctype modificadora
 *
 * @param texto String a ser transformada (in-place)
 * @param tipo Tipo da função de transformação
 */
void transformar_string_ctype(char *texto, CtypeFunction tipo)
{
    if (!texto || tipo >= CTYPE_COUNT)
        return;

    const OperacaoCType *op = &OPERACOES_CTYPE[tipo];

    if (!op->transformar)
        return;

    while (*texto)
    {
        ResultadoCaractere r = aplicar_ctype_caractere(*texto, tipo);
        *texto = (char)r.saida;
        texto++;
    }
}
/**
 * @brief Imprime o resultado da verificação de caractere
 *
 * @param r Ponteiro para a estrutura ResultadoCaractere contendo o resultado
 */
void print_char_result(const ResultadoCaractere *r)
{
    const OperacaoCType *op = &OPERACOES_CTYPE[r->tipo];

    printf("[%s] '%c' (0x%02X)\n", op->nome, r->entrada, (unsigned char)r->entrada);

    if (op->verificar)
        printf("  resultado: %s\n\n", r->saida ? "true" : "false");
    else
        printf("  resultado: '%c'\n\n", r->saida);
}

/**
 * @brief Imprime o resultado da verificação de string
 *
 * @param r Ponteiro para a estrutura ResultadoString contendo o resultado
 */
void print_string_result(const ResultadoString *r)
{
    const OperacaoCType *op = &OPERACOES_CTYPE[r->tipo];

    printf("[%s] \"%s\"\n", op->nome, r->entrada);
    printf("  resultado: %s\n\n", r->resultado ? "true" : "false");
}

// Estrutura para testes
typedef struct
{
    char input_char;
    const char *input_string;
} testarValores;

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    testarValores testes[] = {
        {'A', "Hello"},
        {'1', "12345"},
        {' ', " \t\n"},
        {'$', "Hello!"},
        {'a', "abcDEF"},
    };

    printf("=== Testes de Funções verificadoras de Caracteres ===\n\n");
    for (size_t i = 0; i < sizeof(testes) / sizeof(testarValores); i++)
    {
        for (CtypeFunction f = CTYPE_ISASCII; f <= CTYPE_ISXDIGIT; f++)
        {
            ResultadoCaractere cr = aplicar_ctype_caractere(testes[i].input_char, f);
            print_char_result(&cr);
        }
    }

    printf("=== Testes de Funções modificadoras de Strings ===\n\n");
    for (size_t i = 0; i < sizeof(testes) / sizeof(testarValores); i++)
    {
        for (CtypeFunction f = CTYPE_TOLOWER; f <= CTYPE_TOUPPER; f++)
        {
            char str_copy[100];
            snprintf(str_copy, sizeof(str_copy), "%s", testes[i].input_string);

            printf("Antes de [%s]: \"%s\"\n", OPERACOES_CTYPE[f].nome, str_copy);
            transformar_string_ctype(str_copy, f);
            printf("Depois de [%s]: \"%s\"\n\n", OPERACOES_CTYPE[f].nome, str_copy);
        }
    }
    return 0;
}
