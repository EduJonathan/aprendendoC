#include <stdio.h>
#include <stdlib.h>

/**
 * exit: da biblioteca stdlib.h em C é usada para encerrar o programa com um status de saída.
 * O status de saída indica se o programa terminou bem-sucedidamente ou com falha.
 * O status de saída pode ser obtido com o comando exit.
 *
 * SINTAXE: void exit(int _Status);
 *
 * @param _Status O status de saída do programa, que indica se ele terminou bem-sucedidamente
 * ou com falha. Utilizando duas opções, o EXIT_SUCCESS (0) e EXIT_FAILURE (1) podem ser usados.
 * O EXIT_SUCCESS indica que o programa terminou bem-sucedidamente, enquanto o EXIT_FAILURE
 * indica que o programa terminou com falha.
 *
 * @note O status de saída pode ser obtido com o comando exit.
 */

/**
 * @brief Solicita um número positivo ao usuário e retorna o valor se a entrada for válida.
 * Se a entrada não for válida, encerra o programa com falha.
 *
 * @return O número positivo digitado pelo usuário.
 */
unsigned solicitarNumeroPositivo(void)
{
    unsigned numero = 0;

    printf("Digite um número positivo: ");
    if (scanf("%u", &numero) != 1)
    {
        printf("Entrada inválida. Saindo do programa com falha.\n");
        exit(EXIT_FAILURE); // ou exit(1)
    }

    // Se quisermos validar mais condições, como número negativo,
    // precisamos ajustar conforme o tipo `unsigned` não pode ser negativo.
    return numero;
}

int main(int argc, char **argv)
{
    // Obtém o número positivo da função
    unsigned numero = solicitarNumeroPositivo();

    printf("Número digitado: %u\n", numero);

    // Simulando uma operação bem-sucedida
    printf("Simulando uma operação bem-sucedida. Saindo do programa com sucesso.\n");
    exit(EXIT_SUCCESS); // ou exit(0)

    // O código abaixo não será alcançado, pois o programa já terá terminado
    printf("Este código não será executado.\n");
    return EXIT_SUCCESS;
}
