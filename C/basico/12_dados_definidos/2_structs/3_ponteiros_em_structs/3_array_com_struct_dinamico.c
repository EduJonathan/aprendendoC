#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Definição de uma estrutura chamada `arr` com um campo inteiro.
 *
 * Esta estrutura é usada para armazenar um valor inteiro. Pode ser utilizada em
 * diversas situações onde é necessário encapsular um valor inteiro dentro de uma estrutura.
 */
struct arr
{
    int valor; /**< Campo que armazena um valor inteiro. */
};

/**
 * @brief Função para alocar dinamicamente um array de structs 'arr'.
 *
 * @param tamanho Número de elementos a serem alocados.
 * @return Um ponteiro para o array alocado, ou NULL se a alocação falhar.
 */
struct arr *alocarArray(size_t tamanho)
{
    // Aloca o array dinamicamente para a struct `arr`
    struct arr *array = (struct arr *)malloc(tamanho * sizeof(struct arr));

    // Verifica o array
    if (array == NULL)
    {
        // Imprime uma mensagem de erro
        printf("Erro na alocação de memória.\n");

        // Retorna NULL
        return NULL;
    }

    // Retorna o array
    return array;
}

/**
 * @brief Função para inicializar os valores do array de structs 'arr'.
 *
 * Esta função inicializa o campo `valor` de cada elemento do array
 * com um valor calculado com base no índice do elemento.
 *
 * @param array Ponteiro para o array de structs a ser inicializado.
 * @param tamanho Tamanho do array.
 */
void inicializarArray(struct arr *array, size_t tamanho)
{
    // Inicializa o campo `valor` de cada elemento do array
    for (size_t i = 0; i < tamanho; i++)
    {
        // Calcula o valor a ser armazenado no campo `valor`
        array[i].valor = (int)(i * 2);
    }
}

/**
 * @brief Função para imprimir os valores do array de structs 'arr' utilizando
 * indexação tradicional.
 *
 * @param array Ponteiro para o array de structs a ser impresso.
 * @param tamanho Tamanho do array.
 */
void imprimirArrayComIndexacaoTradicional(const struct arr *array, size_t tamanho)
{
    printf("IMPRIMINDO VALORES UTILIZANDO TRADICIONALMENTE\n");

    // Imprime os valores do array
    for (size_t i = 0; i < tamanho; i++)
    {
        // Imprime o valor armazenado no campo `valor`
        printf("%d ", array[i].valor);
    }

    // Imprime uma nova linha
    putchar('\n');
}

/**
 * @brief Função para imprimir os valores do array de structs 'arr' utilizando
 * aritmética de ponteiros.
 *
 * @param array Ponteiro para o array de structs a ser impresso.
 * @param tamanho Tamanho do array.
 */
void imprimirArrayComAritmeticaDePonteiros(const struct arr *array, size_t tamanho)
{
    printf("IMPRIMINDO VALORES UTILIZANDO ARITMÉTICA DE PONTEIROS\n");

    // Imprime os valores do array
    for (size_t i = 0; i < tamanho; i++)
    {
        // Imprime o valor armazenado no campo `valor`
        printf("%d ", (array + i)->valor);
    }

    // Imprime uma nova linha
    putchar('\n');
}

/**
 * @brief Procedimento para liberar a memória alocada para o array de structs 'arr'.
 *
 * @param array Ponteiro para o array a ser liberado.
 */
void liberarArray(struct arr *array)
{
    free(array);
}

int main(int argc, char **argv)
{
    // Definindo o tamanho do array
    size_t tamanhoArray = 4ULL;

    // Alocando o array
    struct arr *meuArray = alocarArray(tamanhoArray);

    // Verificando se o array está vazio
    if (meuArray == NULL)
    {
        return 1;
    }

    // Inicializando o array
    inicializarArray(meuArray, tamanhoArray);

    // Imprimindo o array
    imprimirArrayComIndexacaoTradicional(meuArray, tamanhoArray);
    imprimirArrayComAritmeticaDePonteiros(meuArray, tamanhoArray);

    // Liberando o array
    liberarArray(meuArray);
    return 0;
}
