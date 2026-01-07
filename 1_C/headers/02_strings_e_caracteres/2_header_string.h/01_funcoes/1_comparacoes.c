#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>

/**
 * Tipos para funções de comparação de strings definidas em <string.h>
 */
typedef enum
{
    CMP_STRCMP,
    CMP_STRNCMP,
    CMP_STRCASECMP,
    CMP_STRNCASECMP,
    CMP_STRCOLL
} Funcoes_Comparacao_String;

/**
 * Estrutura para armazenar o resultado de uma comparação de strings e informações relacionadas
 */
typedef struct
{
    const char *s1;                 // primeira string
    const char *s2;                 // segunda string
    int result;                     // resultado da comparação
    size_t n;                       // usado apenas pelas funções `n`
    Funcoes_Comparacao_String type; // tipo de comparação realizada
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
const char *get_compare_name(Funcoes_Comparacao_String type)
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
        return "unknown";
    }
}

/**
 * @brief Interpreta o resultado numérico da comparação de strings
 *
 * @param res Resultado numérico da comparação
 * @return const char* Interpretação do resultado ("IGUAIS", "S1 VEM ANTES (MENOR)", "S1 VEM DEPOIS (MAIOR)")
 */
Resultado_Comparacao_String compare_strings(const char *s1, const char *s2, size_t n, Funcoes_Comparacao_String type)
{
    Resultado_Comparacao_String res;
    res.s1 = s1;
    res.s2 = s2;
    res.n = n;
    res.type = type;

    // Configuração de localidade apenas para strcoll
    if (type == CMP_STRCOLL)
    {
        setlocale(LC_COLLATE, "pt_BR.UTF-8");
    }

    switch (type)
    {
    case CMP_STRCMP:
        res.result = strcmp(s1, s2);
        break;

    case CMP_STRNCMP:
        res.result = strncmp(s1, s2, n);
        break;

    case CMP_STRCASECMP:
        res.result = strcasecmp(s1, s2);
        break;

    case CMP_STRNCASECMP:
        res.result = strncasecmp(s1, s2, n);
        break;

    case CMP_STRCOLL:
        res.result = strcoll(s1, s2);
        break;
    }

    // Saída muito mais clara e didática
    printf("[%s] \"%s\" vs \"%s\" -> %d (%s)\n",
           get_compare_name(type),
           s1, s2,
           res.result,
           interpretar_resultado(res.result));

    return res;
}

int main(int argc, char **argv)
{
    printf("--- INICIANDO TESTES DE COMPARACAO ---\n\n");

    compare_strings("Brasil", "EUA", 0, CMP_STRCMP);
    compare_strings("Brasil", "brasil", 0, CMP_STRCASECMP);
    compare_strings("Sim", "Não", 0, CMP_STRCOLL);
    compare_strings("casa", "casa", 4, CMP_STRNCMP);
    compare_strings("Abacaxi", "Abacate", 5, CMP_STRNCMP);

    return 0;
}
