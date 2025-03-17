#include <stdio.h>

/**
 * #ifdef: Verifica se uma macro foi criada
 * #ifndef: Verifica se a macro não foi criada
 */

/* Macro que realiza a impressão dos caracteres da tabela ASCII tanto maiúsculos e minúsculos. */
#define MACRO()                     \
    for (int c = 65; c <= 90; c++)  \
    {                               \
        printf("%d - %c\n", c, c);  \
    }                               \
                                    \
    for (int c = 97; c <= 122; c++) \
    {                               \
        printf("%d - %c\n", c, c);  \
    }

/* Verifica se o macro MACRO está definida se sim!. */
#ifdef MACRO

/* Crie outra macro apenas para informa que a impressão dos caracteres irão ocorrer na compilação. */
#define IMPRESSAO_REALIZADA() \
    printf("IMPRESSÃO DOS CARACTERES IRÁ OCORRER\n");

/* Se não ocorrer não corresponderá a condição #ifdef. */
#else
#define IMPRESSAO_NAO_REALIZADA() \
    printf("IMPRESSÃO DOS CARACTERES NÃO IRÁ OCORRER\n");
#endif

/**
 * @brief Procedimento que chama 2 macros para exibir os valores enquanto a macro não é desfeita
 */
void caracteresImpressos(void)
{
    IMPRESSAO_REALIZADA();
    MACRO();
}

/* Desfazendo a macro MACRO. */
#undef MACRO

/* Verificando se a macro foi desfeita com undef. */
#ifndef MACRO

/* Cria macro para informar que foi desfeita. */
#define MACRO_DESFEITA() \
    printf("A macro foi desfeita");
#else

/* Se não cria macro para informar que não foi desfeita. */
#define MACRO_NAO_DESFEITA() \
    printf("A macro foi desfeita");
#endif

int main(int argc, char **argv)
{
    // Chamando a função para exibir os caracteres
    caracteresImpressos();

    // Chamando a macro para informar que  macro foi desfeita?
    MACRO_DESFEITA();
    return 0;
}
