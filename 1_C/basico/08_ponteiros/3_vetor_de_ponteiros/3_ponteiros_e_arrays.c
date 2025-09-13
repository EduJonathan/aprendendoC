#include <stdio.h>

int main(int argc, char **argv)
{
    printf("\n<===Primeiro caso====>\n");

    // Declaração e inicialização de um vetor de caracteres (string)
    const char vetor[7] = {"Hello"}; // Vetor de 7 caracteres, incluindo o '\0' terminador da string
    const char *ptr = NULL;          // Ponteiro para caractere, inicializado como NULL

    // Atribui o endereço do vetor ao ponteiro
    ptr = vetor;

    // Loop para imprimir os caracteres do vetor e seus endereços
    for (int i = 0; i < 6; i++, ptr++)
    {
        // Imprime o caractere no índice i, o valor no vetor e o endereço de memória de
        // vetor[i] O ponteiro ptr é incrementado a cada iteração, mas não é utilizado para
        // acessar os valores na impressão
        printf(" vetor[%d] = %c\t Endereço: %p\n", i, vetor[i], (void *)&vetor[i]);
    }

    printf("\n<===Segundo caso====>\n");

    // Declaração de um array de inteiros
    int array[10];

    // Preenche o array com valores inseridos pelo usuário
    for (int i = 0; i < 10; i++)
    {
        printf("Insira o valor da posição[%d]: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Declaração e inicialização de um ponteiro para inteiro
    int *pointer = NULL;

    // Atribui o endereço do array ao ponteiro
    pointer = array;

    printf("\n*********************************\n");
    printf("\nIndice\tValor\tEndereço\n");

    // Loop para imprimir os valores do array e seus endereços
    for (int i = 0; i < 10; i++, pointer++)
    {
        // Imprime o índice (i + 1), o valor do elemento acessado pelo ponteiro, o endereço
        // do elemento e o próprio ponteiro &pointer[i] é equivalente a pointer[i] ou
        // *(pointer + i), que acessa o valor de array[i]
        printf("%d\t%d\t%p\t%p\n", i + 1, *pointer, (void *)&array[i], (void *)pointer);
    }
    return 0;
}
