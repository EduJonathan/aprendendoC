#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <locale.h>

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

// Estrutura para operações de ctype
typedef struct
{
    CtypeFunction type;     // Tipo da função
    const char *name;       // Nome da função
    int (*classify) (int);  // Ponteiro para função que classifica caracteres
    int (*transform)(int);  // Ponteiro para função que transforma caracteres
} CtypeOperation;

// Definição do array de operações, detalhe isascii não é padrão C, então se não estiver disponível
// pode ser substituído por uma função personalizada, ou apenas removido se não for necessário.
const CtypeOperation CTYPE_OPERATIONS[CTYPE_COUNT] = {
    {CTYPE_ISASCII,  "isascii",  isascii,  NULL},
    {CTYPE_ISALNUM,  "isalnum",  isalnum,  NULL},
    {CTYPE_ISALPHA,  "isalpha",  isalpha,  NULL},
    {CTYPE_ISBLANK,  "isblank",  isblank,  NULL},
    {CTYPE_ISCNTRL,  "iscntrl",  iscntrl,  NULL},
    {CTYPE_ISDIGIT,  "isdigit",  isdigit,  NULL},
    {CTYPE_ISGRAPH,  "isgraph",  isgraph,  NULL},
    {CTYPE_ISLOWER,  "islower",  islower,  NULL},
    {CTYPE_ISPRINT,  "isprint",  isprint,  NULL},
    {CTYPE_ISPUNCT,  "ispunct",  ispunct,  NULL},
    {CTYPE_ISSPACE,  "isspace",  isspace,  NULL},
    {CTYPE_ISUPPER,  "isupper",  isupper,  NULL},
    {CTYPE_ISXDIGIT, "isxdigit", isxdigit, NULL},
    {CTYPE_TOLOWER,  "tolower",  NULL,     tolower},
    {CTYPE_TOUPPER,  "toupper",  NULL,     toupper}};

// Estrutura para resultados em caracteres
typedef struct
{
    char input;
    int output;
    CtypeFunction type;
} CtypeCharResult;

// Estrutura para resultados em strings
typedef struct
{
    const char *input;  // string de entrada
    bool result;        // resultado da verificação
    CtypeFunction type; // tipo da função aplicada
} CtypeStringResult;

// Política para verificação de strings
typedef enum
{
    STRING_ALL, // todos os caracteres devem passar
    STRING_ANY  // pelo menos um caractere deve passar
} StringPolicy;

/**
 * @brief Aplica uma função de verificação de caractere a um único caractere
 *
 * @param c Caractere a ser verificado
 * @param type Tipo de função de verificação (CTYPE_IS*)
 * @return CtypeCharResult Estrutura contendo o resultado da verificação
 */
CtypeCharResult ctype_apply_char(char c, CtypeFunction type)
{
    CtypeCharResult res = {.input = c, .output = 0, .type = type};

    if (type >= CTYPE_COUNT)
        return res;

    const CtypeOperation *op = &CTYPE_OPERATIONS[type];
    int uc = (unsigned char)c;

    if (op->classify)
        res.output = op->classify(uc);
    else if (op->transform)
        res.output = op->transform(uc);

    return res;
}

/**
 * @brief Aplica uma função de verificação de caractere a todos os caracteres de uma string
 *
 * @param str String a ser verificada
 * @param type Tipo de função de verificação (CTYPE_IS*)
 * @param policy Política de verificação (STRING_ALL ou STRING_ANY)
 * @return CtypeStringResult Estrutura contendo o resultado da verificação
 */
CtypeStringResult ctype_apply_string(const char *str, CtypeFunction type, StringPolicy policy)
{
    CtypeStringResult res = {
        .input = str,
        .result = (policy == STRING_ALL),
        .type = type};

    if (!str || type >= CTYPE_COUNT)
        return res;

    const CtypeOperation *op = &CTYPE_OPERATIONS[type];

    if (!op->classify)
        return res;

    while (*str)
    {
        CtypeCharResult r = ctype_apply_char(*str, type); // Aplica a função ao caractere atual
        bool ok = r.output != 0;                          // Converte para bool, verifica se é diferente de zero

        if (policy == STRING_ALL && !ok)
        {
            res.result = false;
            return res;
        }

        if (policy == STRING_ANY && ok)
        {
            res.result = true;
            return res;
        }

        str++;
    }

    return res;
}

/**
 * @brief Transforma uma string aplicando a função de transformação especificada
 *
 * @param str String a ser transformada (modificada in-place)
 * @param type Tipo de função de transformação (CTYPE_TOLOWER ou CTYPE_TOUPPER)
 */
void ctype_transform_string(char *str, CtypeFunction type)
{
    if (!str || type >= CTYPE_COUNT)
        return;

    const CtypeOperation *op = &CTYPE_OPERATIONS[type];

    if (!op->transform)
        return;

    while (*str)
    {
        CtypeCharResult r = ctype_apply_char(*str, type);
        *str = (char)r.output;
        str++;
    }
}

/**
 * @brief Imprime o resultado da verificação de caractere
 *
 * @param r Ponteiro para a estrutura CtypeCharResult contendo o resultado
 */
void print_char_result(const CtypeCharResult *r)
{
    const CtypeOperation *op = &CTYPE_OPERATIONS[r->type];

    printf("[%s] '%c' (0x%02X)\n",
           op->name, r->input, (unsigned char)r->input);

    if (op->classify)
        printf("  resultado: %s\n\n", r->output ? "true" : "false");
    else
        printf("  resultado: '%c'\n\n", r->output);
}

/**
 * @brief Imprime o resultado da verificação de string
 *
 * @param r Ponteiro para a estrutura CtypeStringResult contendo o resultado
 */
void print_string_result(const CtypeStringResult *r)
{
    const CtypeOperation *op = &CTYPE_OPERATIONS[r->type];

    printf("[%s] \"%s\"\n", op->name, r->input);
    printf("  resultado: %s\n\n", r->result ? "true" : "false");
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
            CtypeCharResult cr = ctype_apply_char(testes[i].input_char, f);
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

            printf("Antes de [%s]: \"%s\"\n", CTYPE_OPERATIONS[f].name, str_copy);
            ctype_transform_string(str_copy, f);
            printf("Depois de [%s]: \"%s\"\n\n", CTYPE_OPERATIONS[f].name, str_copy);
        }
    }
    return 0;
}
