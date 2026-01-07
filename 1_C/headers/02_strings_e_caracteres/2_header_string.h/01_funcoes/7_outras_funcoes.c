#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/**
 * Enum para identificar as funções que vamos demonstrar
 */
typedef enum
{
    FUNC_STRCSPN,
    FUNC_STRLEN,
    FUNC_STRDUP,
    FUNC_STRXFRM,
    FUNC_SNPRINTF
} Funcoes_Restantes;

/**
 * Estrutura para guardar informações da operação
 */
typedef struct
{
    const char *str;         // string principal
    const char *reject;      // para strcspn
    size_t resultado_size_t; // resultados que retornam size_t
    int resultado_int;       // para snprintf
    char *resultado_str;     // para strdup
    size_t len_transformed;  // para strxfrm
    Funcoes_Restantes type;
} Resultado_Funcao;

/**
 * @brief Nome da função como string
 *
 * @param type O tipo de função
 * @return const char* Nome da função
 */
const char *get_func_name(Funcoes_Restantes type)
{
    switch (type)
    {
    case FUNC_STRCSPN:
        return "strcspn";

    case FUNC_STRLEN:
        return "strlen";

    case FUNC_STRDUP:
        return "strdup";

    case FUNC_STRXFRM:
        return "strxfrm";

    case FUNC_SNPRINTF:
        return "snprintf";

    default:
        return "unknown";
    }
}

/**
 * @brief Executa e exibe a demonstração da função escolhida
 *
 * @param str A string principal
 * @param reject A string de rejeição (para strcspn)
 * @param type O tipo de função a demonstrar
 */
void demonstrar_funcao(const char *str, const char *reject, Funcoes_Restantes type)
{
    printf("[%s] ", get_func_name(type));

    Resultado_Funcao res = {.str = str, .reject = reject, .type = type};

    switch (type)
    {
    case FUNC_STRCSPN:
    {
        size_t len = strcspn(str, reject);
        printf("\"%s\" até encontrar algum de \"%s\" → %zu caracteres\n", str, reject, len);

        if (len < strlen(str))
            printf("→ Primeiro caractere rejeitado: '%c' na posição %zu\n", str[len], len);
        else
            printf("→ Nenhum caractere de \"%s\" encontrado\n", reject);
        break;
    }
    case FUNC_STRLEN:
    {
        size_t len = strlen(str);
        printf("\"%s\" → comprimento = %zu\n", str, len);
        break;
    }
    case FUNC_STRDUP:
    {
        char *duplicata = strdup(str);
        printf("\"%s\" → duplicata alocada em %p: \"%s\"\n", str, (void *)duplicata, duplicata);
        free(duplicata); // sempre liberar!
        break;
    }
    case FUNC_STRXFRM:
    {
        setlocale(LC_COLLATE, "pt_BR.UTF-8");
        char buffer[256];
        size_t len = strxfrm(buffer, str, sizeof(buffer));
        printf("\"%s\" → transformado para ordenação local = \"%s\" (tamanho necessário: %zu)\n", str, buffer, len);
        break;
    }
    case FUNC_SNPRINTF:
    {
        char buffer[50];
        int valor = 42;
        double pi = 3.14159;

        int ret = snprintf(buffer, sizeof(buffer), "Inteiro: %d | Double: %.3f | String: %s", valor, pi, "Olá");

        printf("Formatação → buffer = \"%s\" | retorno = %d (bytes que seriam escritos)\n", buffer, ret);

        if (ret >= sizeof(buffer))
            printf("→ ATENÇÃO: buffer pequeno! Truncamento ocorreu.\n");
        break;
    }
    }
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("=== DEMONSTRAÇÃO DAS FUNÇÕES RESTANTES DE <string.h> ===\n\n");

    // strcspn
    demonstrar_funcao("Olá mundo", "aeiou", FUNC_STRCSPN);
    demonstrar_funcao("xyz123", "0123456789", FUNC_STRCSPN);
    demonstrar_funcao("abcdef", "xyz", FUNC_STRCSPN);

    printf("\n");

    // strlen
    demonstrar_funcao("Brasil", NULL, FUNC_STRLEN);
    demonstrar_funcao("", NULL, FUNC_STRLEN);
    demonstrar_funcao("Olá\nmundo", NULL, FUNC_STRLEN); // \n conta como 1 char

    printf("\n");

    // strdup
    demonstrar_funcao("Memória dinâmica", NULL, FUNC_STRDUP);
    demonstrar_funcao("", NULL, FUNC_STRDUP);

    printf("\n");

    // strxfrm
    demonstrar_funcao("café", NULL, FUNC_STRXFRM);
    demonstrar_funcao("cacao", NULL, FUNC_STRXFRM);

    printf("\n");

    // snprintf
    demonstrar_funcao(NULL, NULL, FUNC_SNPRINTF); // parâmetros ignorados aqui

    printf("\n=== FIM DA DEMONSTRAÇÃO ===\n");
    return 0;
}
