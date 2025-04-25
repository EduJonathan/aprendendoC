#include <stdio.h>

/**
 * Ponteiro e arrays são a mesma coisa? ponteiros tem um forte relacionamento com arrays,
 * pelo fato do array ser tratado de forma unânime e simultânea através de sua nomeação, o
 * array age por si só como um ponteiro atuando no primeiro elemento do array, porém não, não
 * são a mesma coisa, arrays são alocações contíguas na memória, enquanto ponteiro ARMAZENA
 * um endereço.
 *
 * int *ponteiro = NULL;
 * int arr[3] = {0};
 *
 * ponteiro = arr; ou &arr[0];
 *
 * Apartir deste momento acontece o que já esperado
 * [ponteiro] -> arr[0]
 */

int main(int argc, char **argv)
{
    int arr[] = {10, 20, 30, 40, 50}; // Definição de um array de inteiros
    int *ponteiro = arr;              // O ponteiro recebe o endereço do primeiro elemento do array

    printf("Array[0] usando o nome do array: %d\n", arr[0]);                         // Acesso ao primeiro elemento do array
    printf("Ponteiro apontando para o primeiro elemento do array: %d\n", *ponteiro); // Acesso ao primeiro elemento usando ponteiro

    // Acessando outros elementos do array usando o ponteiro
    printf("Ponteiro apontando para o segundo elemento do array: %d\n", *(ponteiro + 1));  // Ponteiro para o segundo elemento
    printf("Ponteiro apontando para o terceiro elemento do array: %d\n", *(ponteiro + 2)); // Ponteiro para o terceiro elemento

    // Comparando arr e ponteiro
    printf("O nome do array 'arr' é equivalente a &arr[0], que é: %p\n", (void *)arr);
    printf("O ponteiro aponta para o mesmo endereço: %p\n", (void *)ponteiro);

    printf("\nAcessando os elementos do array usando o índice:\n");

    // Iterando sobre o array com um índice
    for (int i = 0; i < 5; i++)
    {
        printf("Elemento arr[%d] = %d\n", i, arr[i]);
    }

    printf("\nAcessando os elementos do array usando ponteiro:\n");

    // Iterando sobre o array com um ponteiro
    for (int i = 0; i < 5; i++)
    {
        // O ponteiro começa no primeiro elemento e usamos aritmética de ponteiros para acessar o próximo
        printf("Elemento *(ponteiro + %d) = %d\n", i, *(ponteiro + i));
    }
    return 0;
}
