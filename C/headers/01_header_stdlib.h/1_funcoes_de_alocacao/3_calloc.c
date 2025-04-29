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

    /*
     * calloc() vs. malloc(): Diferenças entre malloc() Vs calloc():
     *
     * A função calloc() é geralmente mais adequada e eficiente do que a função malloc().
     * ambas as funções são utilizadas para atribuir espaço de memória, calloc() pode
     * atribuir múltiplos blocos de uma só vez. Não é necessário solicitar um bloco de
     * memória de cada vez.
     *
     * A função calloc() é utilizada em estruturas de dados complexas que requerem
     * um maior espaço de memória. O bloco de memória atribuído por um calloc() em C é
     * sempre inicializado com zero enquanto que na função malloc() em C, contém sempre um
     * valor de lixo.
     */
    return 0;
}
