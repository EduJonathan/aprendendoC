#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Enum para identificar as funções que vamos demonstrar
typedef enum
{
    FUNC_STRCSPN,
    FUNC_STRLEN,
    FUNC_STRDUP,
    FUNC_STRXFRM,
    FUNC_SNPRINTF
} Funcoes_Restantes;

// Estrutura para guardar informações da operação
typedef struct
{
    const char *str;         // string principal
    const char *reject;      // para strcspn
    size_t resultado_size_t; // resultados que retornam size_t
    int resultado_int;       // para snprintf
    char *resultado_str;     // para strdup
    size_t len_transformed;  // para strxfrm
    Funcoes_Restantes type;  // Tipo da função que foi executada
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
        return "Função Desconhecida";
    }
}

/**
 * @brief Executa e exibe a demonstração da função escolhida
 *
 * @param str A string principal
 * @param reject A string de rejeição (para strcspn)
 * @param type O tipo de função a demonstrar
 */
void demonstrar(const char *str, const char *reject, Funcoes_Restantes tipo)
{
    if (str == NULL || (tipo != FUNC_SNPRINTF && reject == NULL))
    {
        printf("[%s] Erro: string NULL não permitida para esta função\n", get_func_name(tipo));
        return;
    }

    printf("[%s] ", get_func_name(tipo));

    switch (tipo)
    {
    case FUNC_STRCSPN:
    {
        if (reject == NULL)
        {
            printf("Erro: conjunto de rejeição NULL\n");
            return;
        }
        size_t pos = strcspn(str, reject);
        printf("\"%s\"  →  prefixo sem caracteres de \"%s\" tem %zu bytes\n", str, reject, pos);

        if (pos < strlen(str))
            printf("   Primeiro caractere rejeitado: '%c' (posição %zu)\n", str[pos], pos);
        else
            printf("   Nenhum caractere de \"%s\" encontrado\n", reject);
        break;
    }

    case FUNC_STRLEN:
    {
        size_t len = strlen(str);
        printf("\"%s\"  →  comprimento = %zu bytes\n", str, len);
        break;
    }

    case FUNC_STRDUP:
    {
        char *dup = strdup(str);
        if (dup == NULL)
        {
            printf("Falha na alocação de memória (strdup retornou NULL)\n");
        }
        else
        {
            printf("\"%s\"  →  duplicata alocada em %p: \"%s\"\n", str, (void *)dup, dup);
            free(dup);
        }
        break;
    }

    case FUNC_STRXFRM:
    {
        // Configurar locale de collation apenas uma vez (idealmente no main)
        static int locale_configurado = 0;
        if (!locale_configurado)
        {
            if (setlocale(LC_COLLATE, "pt_BR.UTF-8") == NULL)
                printf("(Aviso: não foi possível configurar LC_COLLATE pt_BR.UTF-8)\n");
            locale_configurado = 1;
        }

        char buffer[128] = "";
        size_t len_necessario = strxfrm(buffer, str, sizeof(buffer));

        printf("\"%s\"  →  forma de ordenação local: \"%s\"\n", str, buffer);

        if (len_necessario >= sizeof(buffer))
            printf("   (buffer pequeno → seriam necessários %zu bytes)\n", len_necessario + 1);
        else
            printf("   (tamanho da transformação: %zu bytes)\n", len_necessario);
        break;
    }

    case FUNC_SNPRINTF:
    {
        char buffer[60];
        int idade = 35;
        double altura = 1.78;
        const char *cidade = "Teresina";

        int ret = snprintf(buffer, sizeof(buffer), "Idade: %d anos | Altura: %.2f m | Cidade: %s", idade, altura, cidade);

        printf("Formatação → \"%s\"\n", buffer);
        printf("   Retorno: %d (bytes escritos%s)\n", ret, (ret >= (int)sizeof(buffer)) ? " — TRUNCADO!" : "");

        break;
    }
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("=== DEMONSTRAÇÃO DAS FUNÇÕES RESTANTES DE <string.h> ===\n\n");

    printf("1. strcspn\n");
    printf("-----------------------\n");

    demonstrar("Olá mundo", "aeiou",      FUNC_STRCSPN);
    demonstrar("xyz123456", "0123456789", FUNC_STRCSPN);
    demonstrar("abcdefghi", "xyz",        FUNC_STRCSPN);

    printf("\n2. strlen\n");
    printf("-----------------------\n");

    demonstrar("São Paulo",        NULL, FUNC_STRLEN);
    demonstrar("",                 NULL, FUNC_STRLEN);
    demonstrar("café com leite\n", NULL, FUNC_STRLEN);

    printf("\n3. strdup\n");
    printf("-----------------------\n");

    demonstrar("Alocação dinâmica", NULL, FUNC_STRDUP);
    demonstrar("",                  NULL, FUNC_STRDUP);

    printf("\n4. strxfrm  (ordenação local / collation)\n");
    printf("-----------------------------------------------\n");

    demonstrar("café",      NULL, FUNC_STRXFRM);
    demonstrar("cacao",     NULL, FUNC_STRXFRM);
    demonstrar("São Paulo", NULL, FUNC_STRXFRM);

    printf("\n5. snprintf  (formatação segura)\n");
    printf("-----------------------------------------------\n");
    demonstrar(NULL, NULL, FUNC_SNPRINTF);

    printf("\n=== FIM DOS EXEMPLOS ===\n\n");

    printf("Observações rápidas:\n");
    printf("• strcspn   → comprimento do prefixo até encontrar caractere rejeitado\n");
    printf("• strlen    → comprimento sem contar o \\0 final\n");
    printf("• strdup    → aloca + copia (lembre-se de free!)\n");
    printf("• strxfrm   → transforma string para ordenação de acordo com LC_COLLATE\n");
    printf("• snprintf  → formatação segura com limite de tamanho\n");
    return 0;
}
