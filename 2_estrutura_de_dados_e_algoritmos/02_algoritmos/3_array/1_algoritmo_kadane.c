#include <stdio.h>

/**
 * O Algoritmo de Kadane é uma técnica usada para resolver o problema da máxima
 * soma de subarray contíguo em um array. Ele encontra a soma máxima de uma sequência
 * contígua de elementos dentro de um vetor, o que é muito útil em problemas de otimização,
 * como encontrar a maior soma de lucro ou o melhor período para realizar uma transação financeira.
 *
 * COMPLEXIDADE:
 * TEMPO: O algoritmo de Kadane tem complexidade O(n), onde n é o número de elementos no array.
 * Isso ocorre porque ele percorre o vetor uma única vez.
 *
 * ESPAÇO: O(1), pois o algoritmo utiliza apenas algumas variáveis auxiliares,
 * independentemente do tamanho do array.
 */

/**
 * @brief Encontra a soma máxima de uma subarray contígua em um array.
 *
 * O algoritmo de Kadane é um algoritmo de programação dinâmica que encontra
 * a soma máxima de uma subarray contígua em um array.
 *
 * @param arr Ponteiro para o array a ser processado.
 * @param n Número de elementos do array.
 *
 * @return Soma máxima da subarray contígua.
 */
int kadane(int arr[], int n)
{
    int max_so_far = arr[0];      // Inicializa a soma máxima global com o primeiro elemento
    int max_ending_here = arr[0]; // Inicializa a soma da subarray até o índice atual com o primeiro elemento

    // Itera pelo array a partir do segundo elemento
    for (int i = 1; i < n; ++i)
    {
        if (max_ending_here + arr[i] > arr[i])
        {
            // Atualiza a soma da subarray até o índice atual
            // max_ending_here obtém o valor da soma da subarray até o índice atual
            max_ending_here = max_ending_here + arr[i];
        }
        else
        {
            // Se a soma da subarray até o índice atual for menor ou igual ao valor
            // do elemento atual, redefine a soma da subarray até o índice atual
            max_ending_here = arr[i];
        }
        
        if (max_ending_here > max_so_far)
        {
            // Atualiza a maior soma encontrada até o momento
            // max_so_far obtém o valor da maior soma encontrada até o momento
            max_so_far = max_ending_here;
        }
    }
    return max_so_far; // Retorna a soma máxima da subarray contígua
}

int main(int argc, char **argv)
{
    int arr[10] = {1, -2, 3, 4, -1, 2, 1, -5, 4, 3};
    int n = 10;
    int result = kadane(arr, n);
    printf("A soma máxima da subarray contígua é: %d\n", result);
    return 0;
}
