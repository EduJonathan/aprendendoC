#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * **Função Callback**
 * - Uma *callback* é uma função cujo endereço é passado como argumento para outra função.
 * - A função que recebe esse endereço pode então invocar (*chamar*) a callback em um ponto
 *   específico da sua execução, permitindo que o comportamento seja definido externamente.
 * - Essa técnica torna o código mais flexível, pois a lógica da operação pode ser alterada
 *   simplesmente trocando a função fornecida como callback, sem modificar a função que a utiliza.
 *
 * **Ponteiro para Função**
 * - Em C, funções também possuem endereços na memória, assim como variáveis.
 * - Um *ponteiro para função* é uma variável que armazena o endereço de uma função com uma
 *   determinada assinatura (tipo de retorno e parâmetros).
 * - Por exemplo, `int (*funcao_callback)(void)` declara uma variável que pode apontar para
 *   qualquer função que retorne `int` e não receba argumentos.
 * - Esse ponteiro pode ser passado para outras funções, armazenado em estruturas ou até
 *   alterado em tempo de execução.
 */

/**
 * @brief Gera um número aleatório entre 0 e 99.
 *
 * @return Número inteiro aleatório.
 */
int get_valor_aleatorio(void)
{
    return rand() % 100;
}

/**
 * @brief Gera um valor fixo (exemplo alternativo de callback).
 *
 * @return Valor fixo 42.
 */
int get_valor_fixo(void)
{
    return 42;
}

/**
 * @brief Preenche um array com valores gerados por uma função callback.
 * @param array Ponteiro para o array a ser preenchido.
 * @param size Tamanho do array.
 * @param funcao_callback Ponteiro para a função que gera valores.
 */
void preencher_array(int *array, size_t size, int (*funcao_callback)(void))
{
    if (array == NULL || size == 0 || funcao_callback == NULL)
    {
        fprintf(stderr, "Parâmetros inválidos\n");
        return;
    }

    for (size_t i = 0; i < size; i++)
    {
        array[i] = funcao_callback();
    }
}

int main(int argc, char **argv)
{
    // Inicializa a semente para números aleatórios
    srand((unsigned)time(NULL));

    int array[10] = {0};
    const size_t size = sizeof(array) / sizeof(array[0]);

    // Preenche com números aleatórios
    printf("Preenchendo array com valores aleatórios:\n");

    preencher_array(array, size, get_valor_aleatorio);
    printf("Array: [");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    // Preenche com valor fixo (exemplo alternativo)
    printf("\nPreenchendo array com valor fixo (42):\n");

    preencher_array(array, size, get_valor_fixo);
    printf("Array: [");
    for (size_t i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("]\n");

    return 0;
}
