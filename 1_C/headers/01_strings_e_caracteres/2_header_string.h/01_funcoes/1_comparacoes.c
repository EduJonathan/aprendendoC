#include <stdio.h>
#include <locale.h>
#include <string.h>

// Observação importante:
// strcasecmp e strncasecmp NÃO são padrão C (são POSIX)
// No Windows você pode precisar de #define _GNU_SOURCE ou usar _stricmp / _strnicmp

// Tipos para funções de comparação de strings definidas em <string.h>
typedef enum
{
    CMP_STRCMP,
    CMP_STRNCMP,
    CMP_STRCASECMP,
    CMP_STRNCASECMP,
    CMP_STRCOLL
} COMPARE_STRINGS;

// Estrutura para armazenar o resultado de uma comparação de strings e informações relacionadas
typedef struct
{
    const char *s1;       // primeira string
    const char *s2;       // segunda string
    int result;           // resultado da comparação
    size_t n;             // usado apenas pelas funções `n`
    COMPARE_STRINGS type; // tipo de comparação realizada
} Resultado_Comparacao_String;

/**
 * @brief Funções para comparar strings e obter o nome da função de comparação
 *
 * @param type Tipo de comparação de strings
 * @return const char* Nome da função de comparação
 */
const char *interpretar_resultado(int res)
{
    if (res == 0)
        return "IGUAIS";

    if (res < 0)
        return "S1 VEM ANTES (MENOR)";

    return "S1 VEM DEPOIS (MAIOR)";
}

/**
 * @brief Compara duas strings usando a função de comparação especificada
 *
 * @param s1 Primeira string
 * @param s2 Segunda string
 * @param n Número máximo de caracteres a comparar (usado apenas pelas funções "n")
 * @param type Tipo de comparação de strings
 * @return Resultado_Comparacao_String Estrutura contendo o resultado da comparação e informações relacionadas
 */
const char *get_compare_name(COMPARE_STRINGS type)
{
    switch (type)
    {
    case CMP_STRCMP:
        return "strcmp";

    case CMP_STRNCMP:
        return "strncmp";

    case CMP_STRCASECMP:
        return "strcasecmp";

    case CMP_STRNCASECMP:
        return "strncasecmp";

    case CMP_STRCOLL:
        return "strcoll";

    default:
        return "Função Desconhecida";
    }
}

/**
 * @brief Compara duas strings usando a função de comparação especificada
 *
 * @param s1 Primeira string
 * @param s2 Segunda string
 * @param n Número máximo de caracteres a comparar (usado apenas pelas funções "n")
 * @param type Tipo de comparação de strings
 */
void compare_strings(const char *s1, const char *s2, size_t n, COMPARE_STRINGS type)
{
    if (!s1 || !s2)
    {
        printf("ERRO: string NULL\n");
        return;
    }

    // Evita comportamento indefinido / confuso com n == 0 nas funções "n"
    if ((type == CMP_STRNCMP || type == CMP_STRNCASECMP) && n == 0)
    {
        printf("[AVISO] n = 0 nas funções strncmp/strncasecmp → sempre retorna 0\n");
    }

    int res = 0;

    // Tenta configurar localidade apenas para strcoll
    if (type == CMP_STRCOLL)
    {
        if (!setlocale(LC_COLLATE, "pt_BR.UTF-8"))
        {
            printf("[AVISO] Não foi possível configurar pt_BR.UTF-8\n");
        }
    }

    switch (type)
    {
    case CMP_STRCMP:
        res = strcmp(s1, s2);
        break;

    case CMP_STRNCMP:
        res = strncmp(s1, s2, n);
        break;

    #ifdef _WIN32
        case CMP_STRCASECMP:
            res = _stricmp(s1, s2);
            break;
        case CMP_STRNCASECMP:
            res = _strnicmp(s1, s2, n);
            break;
    #else
        case CMP_STRCASECMP:
            res = strcasecmp(s1, s2);
            break;
        case CMP_STRNCASECMP:
            res = strncasecmp(s1, s2, n);
            break;
    #endif

    case CMP_STRCOLL:
        res = strcoll(s1, s2);
        break;
    }

    printf("[%s] \"%s\" vs \"%s\"%s -> %d (%s)\n", get_compare_name(type), s1, s2,
           (type == CMP_STRNCMP || type == CMP_STRNCASECMP) ? printf(" (n=%zu)", n), "" : "",
           res, interpretar_resultado(res));
}

int main(int argc, char **argv)
{
    printf("--- INICIANDO TESTES DE COMPARACAO ---\n\n");

    compare_strings("Brasil", "EUA",    0, CMP_STRCMP);
    compare_strings("Brasil", "brasil", 0, CMP_STRCASECMP);
    compare_strings("Sim",    "Não",    0, CMP_STRCOLL);

    // Exemplos mais pedagógicos com n > 0
    compare_strings("casa",    "casa",    4, CMP_STRNCMP);
    compare_strings("casa",    "casado",  4, CMP_STRNCMP); // igual nos 4 primeiros
    compare_strings("Abacaxi", "Abacate", 5, CMP_STRNCMP); // igual nos 5 primeiros
    compare_strings("Abacaxi", "Abacaxi", 7, CMP_STRNCMP); // igual até o fim
    return 0;
}
