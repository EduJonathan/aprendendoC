#include <stdio.h>

/*
 * __STDC_VERSION__: Contém um valor inteiro longo que identifica
 * a versão do padrão C adotado pelo compilador.
 *
 * Exemplos:
 *  - 199901L → C99
 *  - 201112L → C11
 *  - 201710L → C17
 *  - 202000L → C23
 */

/* Estrutura que relaciona o valor de __STDC_VERSION__ com o nome do padrão C */
typedef struct
{
    long version;
    const char *name;
} StdVersion;

/* Lista de versões do padrão C em ordem decrescente */
static const StdVersion c_standards[] = {
    {202000L, "C23"},
    {201710L, "C17"},
    {201112L, "C11"},
    {199901L, "C99"},
    {199409L, "C94"},
    {0, "C89"} /* Usado quando __STDC_VERSION__ não estiver definido */
};

/*
 * Macro para verificar a versão do padrão C usada pelo compilador,
 * utilizando apenas __STDC_VERSION__.
 */
#define CHECA_STDC_VERSION()                                                      \
    do                                                                            \
    {                                                                             \
        printf("Versão do padrão C detectada: ");                                 \
                                                                                  \
        long version = __STDC_VERSION__;                                          \
        const char *std_name = "C89";                                             \
                                                                                  \
        for (size_t i = 0; i < sizeof(c_standards) / sizeof(c_standards[0]); i++) \
        {                                                                         \
            if (version >= c_standards[i].version)                                \
            {                                                                     \
                std_name = c_standards[i].name;                                   \
                break;                                                            \
            }                                                                     \
        }                                                                         \
                                                                                  \
        printf("%s\n", std_name);                                                 \
        printf("__STDC_VERSION__ = %ld\n", version);                              \
    } while (0)

int main(int argc, char **argv)
{
    CHECA_STDC_VERSION();
    return 0;
}
