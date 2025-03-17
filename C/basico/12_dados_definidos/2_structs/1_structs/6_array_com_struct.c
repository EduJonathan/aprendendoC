#include <stdio.h>

/**
 * @brief Estrutura que representa um valor inteiro.
 *
 * Esta estrutura contém um único campo
 */
struct array
{
    int valor; /**< Campo valor para armanezar inteiro */
};

int main(int argc, char **argv)
{
    // Define o tamanho do array da struct.
    int tamanhoArray = 6;

    // Cria um array de structs do tipo `array`.
    struct array meuArray[tamanhoArray];

    // Tamanho do array
    size_t numElementos = sizeof(meuArray) / sizeof(meuArray[0]);
    printf("Tamanho do array : %zu\n", numElementos);

    printf("IMPRIMINDO VALORES UTILIZANDO FORMA TRADICIONAL\n");

    /*
     * Inicializando os valores, loop `for` é usado para definir o valor de cada elemento
     * com cada índice multiplicado por 2. Em seguida, os valores são impressos.
     */
    for (int i = 0; i < numElementos; i++)
    {
        meuArray[i].valor = i * 2;
        printf("%d ", meuArray[i].valor);
    }

    printf("\nIMPRIMINDO VALORES UTILIZANDO ARITMÉTICA DE PONTEIROS\n");

    /*
     * Imprime os valores do array usando aritmética de ponteiros de trás para frente.
     * Um ponteiro do tipo struct `array` é inicializado para apontar para o último
     * elemento do array. A atribuição faz com que aponte para o último elemento do array
     */
    struct array *ponteiro = &meuArray[tamanhoArray - 1];

    // Em seguida, um loop `for` é usado para imprimir os valores a partir do final do array
    // até o início, movendo o ponteiro para o elemento anterior a cada iteração.
    for (int i = tamanhoArray - 1; i >= 0; i--)
    {
        // Imprimindo os valores com a aritmética de ponteiros
        printf("%d ", ponteiro->valor);

        // Movendo o ponteiro para o elemento anterior
        ponteiro--;
    }
    return 0;
}
