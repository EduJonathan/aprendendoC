#include <stdio.h>

/* Estrutura que relaciona o valor de __STDC_VERSION__ com o nome do padrão C */
typedef struct
{
    long version;     /* Valor numérico de __STDC_VERSION__ */
    const char *name; /* Nome correspondente do padrão C */
} StdVersion;

/* Lista de versões do padrão C em ordem decrescente */
static const StdVersion c_standards[] = {
    {202000L, "C23"},
    {201710L, "C17"},
    {201112L, "C11"},
    {199901L, "C99"},
    {199409L, "C94"},
    {0, "C89"} /* Valor padrão quando __STDC_VERSION__ é 0 ou não definido */
};

/*
 * Macro para verificar se o compilador segue o padrão ANSI C
 * e exibir a versão do padrão C em uso.
 */
#define CHECA_CONFORMIDADE_DO_COMPILADOR()                                                  \
    do                                                                                      \
    {                                                                                       \
        if (__STDC__)                                                                       \
        {                                                                                   \
            printf("O compilador está em conformidade com o padrão ANSI C\n");              \
            printf("Versão do padrão C: ");                                                 \
            const char *std_name = c_standards[0].name; /* Valor inicial padrão */          \
                                                                                            \
            /* Verifica __STDC_VERSION__, se estiver definido, para identificar a versão */ \
            for (size_t i = 0; i < sizeof(c_standards) / sizeof(c_standards[0]); i++)       \
            {                                                                               \
                if (!__STDC_VERSION__ || __STDC_VERSION__ >= c_standards[i].version)        \
                {                                                                           \
                    std_name = c_standards[i].name;                                         \
                    break;                                                                  \
                }                                                                           \
            }                                                                               \
            printf("%s\n", std_name);                                                       \
        }                                                                                   \
        else                                                                                \
        {                                                                                   \
            printf("O compilador não está em conformidade com o padrão ANSI C\n");          \
        }                                                                                   \
    } while (0)

int main(int argc, char **argv)
{
    /* Chama a macro para verificar a conformidade do compilador */
    CHECA_CONFORMIDADE_DO_COMPILADOR();
    return 0;
}
