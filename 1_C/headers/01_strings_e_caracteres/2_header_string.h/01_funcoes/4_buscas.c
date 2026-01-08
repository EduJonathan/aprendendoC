#include <stdio.h>
#include <locale.h>
#include <string.h>

/**
 * Enum para as funções de busca em strings
 */
typedef enum
{
    SEARCH_STRCHR,  // Procura a primeira ocorrência de um caractere
    SEARCH_STRRCHR, // Procura a última ocorrência de um caractere
    SEARCH_STRSTR,  // Procura a primeira ocorrência de uma substring
    SEARCH_STRPBRK  // Procura o primeiro caractere que esteja em um conjunto
} BUSQUE_STRINGS;

/**
 * @brief Retorna o nome da função de busca
 *
 * @param type O tipo de função de busca
 * @return Nome da função como string
 */
const char *get_search_name(BUSQUE_STRINGS type)
{
    switch (type)
    {
    case SEARCH_STRCHR:
        return "strchr";

    case SEARCH_STRRCHR:
        return "strrchr";

    case SEARCH_STRSTR:
        return "strstr";

    case SEARCH_STRPBRK:
        return "strpbrk";

    default:
        return "Função Desconhecida";
    }
}

/**
 * @brief Executa a busca e imprime o resultado de forma clara
 *
 * @param haystack A string onde será feita a busca
 * @param needle A substring ou caractere(s) a serem buscados
 * @param type O tipo de função de busca a ser utilizada
 */
void demonstrar_busca(const char *haystack, const char *needle, BUSQUE_STRINGS type)
{
    const char *resultado = NULL;

    printf("[%s] ", get_search_name(type));

    if (type == SEARCH_STRCHR || type == SEARCH_STRRCHR)
    {
        char ch = needle[0]; // Assume needle tem pelo menos 1 char
        printf("Procurando o caractere '%c' em \"%s\" → ", ch, haystack);

        if (type == SEARCH_STRCHR)
            resultado = strchr(haystack, ch);
        else
            resultado = strrchr(haystack, ch);
    }
    else if (type == SEARCH_STRSTR)
    {
        printf("Procurando a substring \"%s\" em \"%s\" → ", needle, haystack);
        resultado = strstr(haystack, needle);
    }
    else if (type == SEARCH_STRPBRK)
    {
        printf("Procurando qualquer um de \"%s\" em \"%s\" → ", needle, haystack);
        resultado = strpbrk(haystack, needle);
    }

    if (resultado)
    {
        printf("ENCONTRADO! A partir daí: \"%s\"\n", resultado);
    }
    else
    {
        printf("NÃO ENCONTRADO.\n");
    }
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    printf("=== DEMONSTRAÇÃO DAS FUNÇÕES DE BUSCA EM STRINGS ===\n\n");

    // Exemplos didáticos
    demonstrar_busca("hello world", "o", SEARCH_STRCHR);      // primeiro 'o'
    demonstrar_busca("hello world", "o", SEARCH_STRRCHR);     // último 'o'
    demonstrar_busca("hello world", "world", SEARCH_STRSTR);  // substring
    demonstrar_busca("hello world", "aeiou", SEARCH_STRPBRK); // primeira vogal

    printf("\nMais exemplos:\n");
    demonstrar_busca("banana", "a", SEARCH_STRCHR);  // primeiro 'a'
    demonstrar_busca("banana", "a", SEARCH_STRRCHR); // último 'a'
    demonstrar_busca("programacao em C", "em", SEARCH_STRSTR);
    demonstrar_busca("abc123xyz", "0123456789", SEARCH_STRPBRK); // primeiro dígito
    demonstrar_busca("abcdef", "xyz", SEARCH_STRPBRK);           // nenhum → NULL

    printf("\nObservações importantes:\n");
    printf("- strchr  → primeira ocorrência do caractere\n");
    printf("- strrchr → última ocorrência do caractere\n");
    printf("- strstr  → primeira ocorrência de uma substring\n");
    printf("- strpbrk → primeiro caractere que pertença ao conjunto (qualquer um)\n");
    printf("- Todas retornam NULL se não encontrarem nada.\n");

    return 0;
}
