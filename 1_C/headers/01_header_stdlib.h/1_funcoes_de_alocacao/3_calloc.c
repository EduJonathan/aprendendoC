#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * CALLOC: significa alocação contínua, função é utilizada para alocar múltiplos
 * blocos de memória. A alocação dinâmica de memória é utilizada para alocar a memória a
 * estruturas de dados complexas, tais como matrizes e estruturas.
 *
 * calloc() utilizada para alocar um único bloco de espaço de memória enquanto que
 * a função calloc() em C é utilizada para alocar múltiplos blocos de espaço de memória.
 * Cada bloco atribuído pela função calloc() tem o mesmo tamanho.
 *
 * SINTAXE: void *calloc(size_t _NumOfElements, size_t _SizeOfElements);
 *
 * @param _NumOfElements Número de elementos a serem alocados.
 * @param _SizeOfElements Tamanho dos elementos a serem alocados.
 * @return Ponteiro para o primeiro byte do espaço de memória alocado.
 *
 * A afirmação acima é utilizada para alocar n blocos de memória do mesmo tamanho.
 * Após a atribuição do espaço de memória, todos os bytes são inicializados a zero.
 * O ponteiro que se encontra actualmente no primeiro byte do espaço de memória atribuído
 * é devolvido. Quando existe um erro na alocação do espaço de memória, tal como a falta de
 * memória, então um ponteiro nulo é retornado.
 */

/**
 * @brief Aloca memória para um array de inteiros, preenche o array com uma sequência de
 * valores e calcula a soma desses valores. Esta função aloca dinamicamente um array de
 * inteiros usando `calloc`, inicializa o array com uma sequência de valores começando de 0 até
 * `tamanho-1`, calcula a soma desses valores e imprime a soma. Após o cálculo, a memória
 * alocada é liberada.
 *
 * @param tamanho O número de elementos no array. Deve ser maior que 0.
 * @return Nenhum valor é retornado. A função exibe a soma dos valores no array.
 */
void CalcularSomaSequencia(int tamanho)
{
    int *ptr = NULL;
    int sum = 0;

    // Aloca memória e inicializa o array com zeros
    ptr = (int *)calloc(tamanho, sizeof(int));

    // Verifica se a alocação foi bem-sucedida, se não, encerra o programa
    if (ptr == NULL)
    {
        printf("Erro! Memória não alocada.\n");
        exit(1); // ou exit(EXIT_FAILURE) que irá encerrar o programa
    }

    // Preenche o array com a sequência e calcula a soma
    printf("Construindo e calculando a soma da sequência dos primeiros %d termos:\n", tamanho);
    for (int i = 0; i < tamanho; ++i)
    {
        *(ptr + i) = i;    // Atribui o valor i ao elemento i do array
        sum += *(ptr + i); // Soma o valor do elemento i ao acumulador
    }

    // Exibe a soma
    printf("Soma = %d\n", sum);

    // Libera a memória alocada
    free(ptr);
}

int main(int argc, char **argv)
{
    int tamanho = 10;

    // Chama a função para calcular a soma da sequência
    CalcularSomaSequencia(tamanho);

    printf("-----------------------------------------------\n");
    printf(" >> DIFERENÇA ENTRE malloc E calloc<< \n");

    // Alocação com malloc (não inicializado)
    int *arr_malloc = (int *)malloc(5 * sizeof(int));
    printf("valores do malloc (lixo): ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr_malloc[i]); // Valores imprevisíveis
    }

    // Alocação com calloc (inicializado com 0)
    int *arr_calloc = (int *)calloc(5, sizeof(int));
    printf("\nvalores calloc (zeros): ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr_calloc[i]); // Todos zeros
    }

    free(arr_malloc);
    free(arr_calloc);

    /*
     * calloc() vs. malloc(): Diferenças entre malloc() Vs calloc():
     *
     * +-----------------------------------------------------------------------------------------------------------+
     * | Característica | malloc()                                  | calloc()                                     |
     * +-----------------------------------------------------------------------------------------------------------+
     * | Inicialização  | Não inicializa a memória (valores "lixo") | Inicializa toda a memória com zeros          |
     * +-----------------------------------------------------------------------------------------------------------+
     * | Parâmetros     | Recebe apenas o tamanho total             | Recebe quantidade e tamanho de cada elemento |
     * +-----------------------------------------------------------------------------------------------------------+
     * | Performance    | Mais rápido (não inicializa)              | Mais lento (inicializa a memória)            |
     * +-----------------------------------------------------------------------------------------------------------+
     * | Uso típico     | Alocação única de objetos                 | Alocação de arrays/estruturas                |
     * +-----------------------------------------------------------------------------------------------------------+
     *
     * ✅ Use malloc() quando:
     * Você precisa de máxima performance
     * Vai inicializar os dados manualmente logo após a alocação
     * Está alocando estruturas únicas (não arrays)
     *
     * ✅ Use calloc() quando:
     * Você precisa de memória inicializada com zeros
     * Está alocando arrays ou estruturas de dados
     * Quer evitar bugs de valores não inicializados
     * Prefere segurança sobre performance
     */
    return 0;
}
