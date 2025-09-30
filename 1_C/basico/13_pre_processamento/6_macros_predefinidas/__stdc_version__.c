#include <stdio.h>

/*
 * __STDC_VERSION__: A constante inteira 199901L se a implementação estiver em conformidade
 * com C99, o padrão ANSI C de janeiro de 1999, a constate fornece a versão do padrão ANSI C
 * (ou ISO C) que o compilador segue, retonando um número inteiro.
 */

/* Estrutura que relaciona o valor de __STDC_VERSION__ com o nome do padrão C */
typedef struct
{
    long version;     /* Valor de __STDC_VERSION__ */
    const char *name; /* Nome correspondente do padrão C */
} StdVersion;

/* Lista de versões do padrão C em ordem decrescente */
static const StdVersion c_standards[] = {
    {202000L, "C23"},
    {201710L, "C17"},
    {201112L, "C11"},
    {199901L, "C99"},
    {199409L, "C94"},
    {0, "C89"} /* Valor padrão para C89 ou quando __STDC_VERSION__ não definido */
};

/*
 * Macro para verificar os padrões do compilador e o ambiente de execução
 */
#define CHECA_COMPILADOR_COMPLETO()                                                                      \
    do                                                                                                   \
    {                                                                                                    \
        /* Verifica conformidade com ANSI C */                                                           \
        printf("Conformidade com ANSI C: %s\n", __STDC__ ? "Sim" : "Não");                               \
                                                                                                         \
        /* Verifica a versão do padrão C */                                                              \
        printf("Versão do padrão C: ");                                                                  \
        const char *std_name = c_standards[0].name; /* Valor inicial padrão */                           \
        for (size_t i = 0; i < sizeof(c_standards) / sizeof(c_standards[0]); i++)                        \
        {                                                                                                \
            if (!__STDC_VERSION__ || __STDC_VERSION__ >= c_standards[i].version)                         \
            {                                                                                            \
                std_name = c_standards[i].name;                                                          \
                break;                                                                                   \
            }                                                                                            \
        }                                                                                                \
        printf("%s\n", std_name);                                                                        \
                                                                                                         \
        /* Verifica se o compilador está em ambiente hospedado ou livre-standing */                      \
        printf("Ambiente: ");                                                                            \
        printf("%s\n",                                                                                   \
               __STDC_HOSTED__ == 1 ? "Hospedado" : __STDC_HOSTED__ == 0 ? "Livre-standing"              \
                                                                         : "Informação não disponível"); \
    } while (0)

int main(int argc, char **argv)
{
    /* Chama a macro para verificar padrões e ambiente do compilador */
    CHECA_COMPILADOR_COMPLETO();
    return 0;
}
