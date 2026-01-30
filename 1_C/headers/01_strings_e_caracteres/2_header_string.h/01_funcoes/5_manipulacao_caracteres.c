#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

// Definindo explicitamente que estamos no Windows para usar strtok_s
#ifdef _WIN32
    // strtok_s está disponível nativamente
#else
    // Em sistemas não-Windows, podemos definir um alias ou desabilitar
#warning strtok_s nao esta disponivel nativamente neste sistema. Demo sera ignorada.
    #define NO_STRTOK_S
#endif

// Enum para identificar qual função estamos testando
typedef enum
{
    FUNC_STRSPN,
    FUNC_STRCSPN,
    FUNC_STRTOK,
    FUNC_STRTOK_S
} MANIPULE_STRINGS;

/**
 * Estrutura para armazenar informações do teste
 */
typedef struct
{
    const char *str;       // string principal
    const char *charset;   // conjunto de caracteres aceitos/rejeitados (para spn/cspn)
    size_t result;         // valor retornado pela função
    MANIPULE_STRINGS type; // qual função foi usada
    char *token_example;   // usado apenas para demonstrar strtok/strtok_s
} Resultado_Testes;

/**
 * Retorna o nome da função para impressão
 */
const char *get_function_name(MANIPULE_STRINGS type)
{
    switch (type)
    {
    case FUNC_STRSPN:
        return "strspn";

    case FUNC_STRCSPN:
        return "strcspn";

    case FUNC_STRTOK:
        return "strtok";

    case FUNC_STRTOK_S:
        return "strtok_s";

    default:
        return "Função Desconhecida";
    }
}

/**
 * @brief Testa strspn e strcspn
 *
 * @param str String principal
 * @param charset Conjunto de caracteres aceitos/rejeitados
 * @param type Indica se é strspn ou strcspn
 * @return size_t Comprimento do prefixo conforme a função
 */
size_t test_spn_cspn(const char *str, const char *charset, MANIPULE_STRINGS type)
{
    size_t len;
    if (type == FUNC_STRSPN)
        len = strspn(str, charset);
    else
        len = strcspn(str, charset);

    printf("[%s] str = \"%s\" | charset = \"%s\" -> retorna %zu\n", get_function_name(type), str, charset, len);

    if (type == FUNC_STRSPN)
        printf("→ Maior prefixo formado apenas por caracteres de \"%s\" tem comprimento %zu\n", charset, len);
    else
        printf("→ Maior prefixo sem nenhum caractere de \"%s\" tem comprimento %zu\n", charset, len);

    return len;
}

/**
 * @brief Demonstra strtok (não thread-safe)
 *
 * @param original String original a ser tokenizada
 */
void demo_strtok(const char *original)
{
    printf("[strtok] String original: \"%s\"\n", original);

    char buffer[256];
    strcpy(buffer, original);

    char *token = strtok(buffer, " ,.;-");
    int count = 0;
    while (token != NULL)
    {
        count++;
        printf("    Token %d: \"%s\"\n", count, token);
        token = strtok(NULL, " ,.;-");
    }
    printf("Total de tokens encontrados: %d\n\n", count);
}

#ifndef NO_STRTOK_S
/**
 * Demonstra strtok_s (thread-safe – Windows / C11 annex K)
 *
 * @note strtok_s não é parte do padrão C17, mas está disponível em algumas implementações.
 *
 * @param original String original a ser tokenizada
 */
void demo_strtok_s(const char *original)
{
    printf("[strtok_s] String original: \"%s\"\n", original);

    char buffer[256];
    strcpy(buffer, original); // strtok_s modifica a string também

    char *context = NULL; // Ponteiro de contexto obrigatório
    char *token = strtok_s(buffer, " ,.;-", &context);

    int count = 0;
    while (token != NULL)
    {
        count++;
        printf("    Token %d: \"%s\"\n", count, token);
        token = strtok_s(NULL, " ,.;-", &context); // NULL no primeiro argumento nas chamadas subsequentes
    }
    printf("    Total de tokens encontrados: %d\n\n", count);
}
#endif

int main(int argc, char **argv)
{
    printf("=== TESTES DAS FUNÇÕES strspn / strcspn / strtok / strtok_s ===\n\n");

    // 1. strspn – comprimento do prefixo formado apenas por caracteres aceitos
    test_spn_cspn("abacaxi", "abc", FUNC_STRSPN);
    test_spn_cspn("12345abc", "0123456789", FUNC_STRSPN);
    test_spn_cspn("xyz", "abc", FUNC_STRSPN);

    printf("\n");

    // 2. strcspn – comprimento do prefixo sem nenhum caractere rejeitado
    test_spn_cspn("abacaxi", "xyz", FUNC_STRCSPN);
    test_spn_cspn("read.csv", ".", FUNC_STRCSPN);
    test_spn_cspn("hello world", " ", FUNC_STRCSPN);

    printf("\n");

    // 3. strtok – tokenização (não thread-safe)
    demo_strtok("Brasil, Argentina; Peru - Chile.Colombia");

    // 4. strtok_s – tokenização thread-safe (Windows / C11 annex K)
    // demo_strtok_s("Lisboa Porto; Coimbra - Faro.Braga");
    return 0;
}
