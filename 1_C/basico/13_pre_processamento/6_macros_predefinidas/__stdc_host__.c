#include <stdio.h>

/**
 * Definição: A macro __STDC_HOSTED__ é definida se o compilador estiver operando em um
 * ambiente "hospedado" (hosted environment). Se o valor de __STDC_HOSTED__ for 1, isso
 * indica que o ambiente é hospedado. Caso contrário, o ambiente é considerado
 * "free-standing" (não hospedado).
 *
 * AMBIENTE HOSPEDADO: Em um ambiente hospedado, a implementação do sistema fornece uma
 * biblioteca padrão completa, incluindo funções de entrada/saída (como printf e scanf),
 * gerenciamento de memória dinâmico (como malloc e free), e outros serviços típicos de um
 * sistema operacional completo.
 *
 * AMBIENTE FREE-STANDING: Em um ambiente free-standing, a biblioteca padrão pode estar
 * ausente ou incompleta, e o programa pode precisar de um suporte adicional para funções básicas.
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
    {0, "C89"} /* Valor padrão para C89 ou quando __STDC_VERSION__ não está definido */
};

/*
 * Macro para verificar o ambiente do compilador e o padrão C suportado
 */
#define CHECA_AMBIENTE_E_PADRAO()                                                                        \
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
    /* Chama a macro para verificar o ambiente e o padrão do compilador */
    CHECA_AMBIENTE_E_PADRAO();
    return 0;
}
