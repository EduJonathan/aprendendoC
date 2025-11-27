#include <stdio.h>

/* Este programa exibe a aritmética de ponteiro em vetores. */

int main(int argc, char **argv)
{
    printf("\n\tARITMÉTCA DE PONTEIRO EM ARRAY\n");

    // Declarando um array do int com 3 valores
    int arr[3] = {5, 4, 6};
    int *ptr = arr;

    // Incremento
    printf(" Valor apontado por ptr atualmente: %d\n", *ptr);

    ptr++; // Agora, ptr está apontando para o próximo elemento (ptr[1])
    printf(" Valor após incrementar para ptr[1]: %d\n", *ptr);

    ++ptr; // Agora, ptr está apontando para o próximo elemento (ptr[2])
    printf(" Valor após incrementar para ptr[2]: %d\n", *ptr);

    printf("\n**********************************\n");

    // Decremento
    printf("\n\t>>DECREMENTANDO EM UM ARRAY:\n");
    printf(" Valor apontado por ptr atualmente: %d\n", *ptr);

    ptr--; // Agora, ptr está apontando para o elemento anterior (ptr[1])
    printf(" Valor após decrementar para ptr[1]: %d\n", *ptr);

    --ptr; // Agora, ptr está apontando para o elemento anterior (ptr[0])
    printf(" Valor após decrementar para ptr[0]: %d\n", *ptr);

    /**
     * INCREMENTO E DECREMENTO DE PONTEIROS:
     *
     * O incremento e decremento de ponteiros é realizado através da **aritmética de ponteiros**,
     * que permite adicionar ou subtrair valores a um ponteiro, movendo-o entre elementos
     * consecutivos de um array ou bloco contíguo de memória.
     *
     * Diferente de arrays, que utilizam índices, a aritmética de ponteiros navega pelos
     * endereços de memória levando em conta o tamanho do tipo apontado.
     *
     * Exemplo de memória para um array de inteiros (4 bytes cada):
     *
     * ----------------------------------------
     * | Endereços |  Conteúdo                |
     * |-----------|--------------------------|
     * | 0x5ffe78  | arr[0] = 5               | <- ptr aponta para arr[0]
     * | 0x5ffe7c  | arr[1] = 4               |
     * | 0x5ffe80  | arr[2] = 6               |
     * ----------------------------------------
     *
     * Quando incrementamos o ponteiro:
     *
     *     ptr++;       // Avança sizeof(int) bytes (4 bytes), agora aponta para arr[1]
     *     ptr = ptr+2; // Avança 2 * sizeof(int) bytes, apontando para arr[2]
     *
     * Assim, o ponteiro sempre avança em blocos do tamanho do tipo que aponta, garantindo
     * acesso correto aos elementos consecutivos do array.
     *
     * IMPORTANTE:
     * - O tamanho do tipo é crucial: para `int*`, o ponteiro avança 4 bytes; para `double*`,
     *   normalmente 8 bytes, etc.
     * - Operações como `ptr = ptr + 4` só fazem sentido se você realmente deseja pular 4 elementos,
     *   não apenas o próximo.
     */

    printf("\n=============================================================================\n");
    printf("\n\t>>EXTRAINDO INFORMAÇÕES SOBRE O PONTEIRO 'ptr' E VETOR 'arr'\n");

    printf(" Endereço de ptr: %p\tO ponteiro aponta para: %p\n", &ptr, ptr);
    for (int i = 0; i < 3; i++)
    {
        printf(" Indice[%d] = valor %d\tendereço: %p\n", i, arr[i], &arr[i]);
    }

    putchar('\n');

    // Trecho de código que permite visualizar o avanço que o ponteiro tem
    for (int i = 0; i < 3; i++)
    {
        printf(" Valor apontado por ptr[%d]: %d\n", i, *ptr);

        // Determina o avanço em bytes
        int avanco_em_bytes = (char *)(ptr + 1) - (char *)(ptr);
        printf(" Avanço em bytes de ptr[%d] para ptr[%d]: %d\n", i, i + 1, avanco_em_bytes);

        // Avançar para o próximo elemento
        ptr++;
    }

    printf("\n=============================================================================\n");
    printf("\n\t>>DIFERENÇA ENTRE *PTR++ E *++PTR:\n");

    int array[4] = {1, 2, 3, 4};
    int *pointer = array;

    // Imprimindo o valor inicial apontado por pointer
    printf(" Valor inicial: %d\n", *pointer);

    // Imprime o valor atual apontado por pointer e depois incrementa pointer
    printf(" *pointer++: %d\n", *pointer++);
    printf(" Novo valor de pointer: %d\n", *pointer);

    // Reinicializa pointer para o início do array
    pointer = array;

    printf("\n ++*pointer: %d\n", ++*pointer);

    // Incrementa o valor apontado por pointer e depois imprime o novo valor
    printf(" Novo valor de pointer: %d\n", *pointer);

    printf("\n=============================================================================\n");
    printf("\n>>CURIOSIDADE\n");

    char caracteres[3] = {'A', 'B', 'C'};
    size_t tamCaractere = sizeof(caracteres) / sizeof(caracteres[0]);
    char *pointerChar = caracteres;

    /*
     * Este trecho de código demonstra que a utilização de ++(*pointerChar)
     * atualiza o conteúdo apontado por pointerChar. Ou seja, o valor armazenado no
     * endereço de memória apontado por pointerChar é incrementado, o que modifica o valor no vetor.
     */

    for (int i = 0; i < tamCaractere; i++)
    {
        printf("Valor apontado por pointerChar[%d] : %c\n", i, *pointerChar);

        // Incrementa o valor apontado por pointerChar e imprime o valor modificado
        printf("Valor modificado do conteúdo apontado por pointerChar[%d] -> %c\n", i, ++(*pointerChar));

        /*
         * (*pointerChar)++: O operador pós-incremento é válido em C e incrementa o valor
         * armazenado no endereço apontado por pointerChar, mas a desreferenciação
         * (leitura do valor) ocorre antes do incremento. Ou seja, o valor de pointerChar
         * é incrementado após a operação de leitura.
         */

        // Move pointerChar para o próximo elemento (opcional)
        pointerChar++;
    }
    return 0;
}
