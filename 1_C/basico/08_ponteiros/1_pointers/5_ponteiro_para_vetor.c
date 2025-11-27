#include <stdio.h>

/**
 * Ponteiros e arrays são a mesma coisa?
 *
 * Não. Apesar de terem um relacionamento muito próximo, ponteiros e arrays não são equivalentes.
 *
 * Arrays representam um bloco contínuo de memória, contendo um número fixo de
 * elementos. Já um ponteiro é uma variável que ARMAZENA um endereço de memória.
 *
 * A relação entre eles surge porque, em muitas expressões, o nome de um array
 * "decai" para um ponteiro para seu primeiro elemento. Por isso, é comum usar
 * ponteiros para percorrer arrays.
 *
 * Exemplo:
 *     int *ponteiro = NULL;
 *     int arr[3] = {0};
 *     ponteiro = arr; // equivalente a: ponteiro = &arr[0];
 *
 * A partir desse momento, temos o comportamento esperado:
 *
 *     ponteiro -> arr[0]
 *
 * Ou seja, `ponteiro` passa a apontar para o primeiro elemento do array.
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
