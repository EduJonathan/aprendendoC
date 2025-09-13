#include <stdio.h>
#include <stdlib.h>

/**
 * atexit: da biblioteca stdlib.h em C é usada para registrar funções que serão executadas
 * automaticamente quando o programa terminar. Elas serão executadas quando o programa
 * terminar, seja por meio da execução bem-sucedida ou de uma chamada a exit.
 *
 * SINTAXE: int atexit(void (*)(void));
 *
 * @param func Ponteiro para uma função de limpeza.
 * @return 0 se a função de limpeza foi registrada com sucesso.
 * @note Essa função deve ser registrada antes da chamada a exit.
 */

/**
 * @brief Função de limpeza 1 executada.
 *
 * @note Essa função deve ser registrada antes da chamada a exit.
 */
void cleanupFunction1(void)
{
    printf("Função de limpeza 1 executada.\n");
}

/**
 * @brief Função de limpeza 2 executada.
 *
 * @note Essa função deve ser registrada antes da chamada a exit.
 */
void cleanupFunction2(void)
{
    printf("Função de limpeza 2 executada.\n");
}

int main(int argc, char **argv)
{
    // Registrando funções de limpeza
    if (atexit(cleanupFunction1) != 0 || atexit(cleanupFunction2) != 0)
    {
        printf("Erro ao registrar funções de limpeza.\n");
        return EXIT_FAILURE;
    }

    printf("Programa em execução...\n");

    // Simulando uma chamada a exit
    exit(EXIT_SUCCESS);
}
