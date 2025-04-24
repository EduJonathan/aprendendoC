#include <stdio.h>

/* Este programa exibe a aritmética de ponteiro em vetores. */

int main(int argc, char **argv)
{
    printf("\n\tARITMÉTCA DE PONTEIRO EM ARRAY\n");

    // Declarando um array do int com 3 valores
    int arr[3] = {5, 4, 6};

    // Inicializa o ponteiro para o primeiro elemento do array ptr = &arr[0]
    // A atribuição poderia ocorrer da mesma forma ptr = &arr[0]
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
     * O processo de incremento e decremento dos ponteiros é realizado através da
     * aritmética de ponteiros. Aritmética de ponteiros envolve operações de adição e
     * subtração realizadas nos ponteiros. Diferentemente de um array que percorre seus
     * elementos um por um, a aritmética de ponteiros percorre através dos bytes da memória.
     * --------------------------------------------
     * | Endereços |  Conteúdo (4 bytes por int)  |
     * |-----------|------------------------------|
     * | 0x5ffe78  | *ptr = &arr[0]               | <- ptr aponta para arr[0], contendo 5
     * | 0x5ffe80  | arr[0] = 5                   | <- Elemento 0 do array
     * | 0x5ffe84  | arr[1] = 4                   | <- Elemento 1 do array
     * | 0x5ffe88  | ptr[2] = 6                   | <- Elemento 2 do array
     * --------------------------------------------
     *
     * Quando incrementamos ptr (ptr++), avançamos 4 bytes, pois sizeof(int) é utilizado.
     * O ponteiro passa a apontar para o próximo dado do tipo int. Assim, ptr[0] aponta para arr[1].
     *
     * Por exemplo:
     * ptr = ptr + 1; // Avança 4 bytes (sizeof(int)) para o próximo elemento, apontando para arr[1]
     * ptr = ptr + 2; // Avança 8 bytes, apontando para arr[2]
     *
     * Essa operação é fundamental para percorrer elementos de um array e acessar dados
     * consecutivos na memória. Vale ressaltar que o tamanho do tipo é crucial na aritmética
     * de ponteiros, garantindo que o ponteiro avance adequadamente para o próximo elemento do array.
     *
     * IMPORTANTE: A última operação mencionada (ptr = ptr + 4) parece ser um equívoco,
     * e a operação correta deveria ser ptr = ptr + 1 ou ptr += 1, pois deseja-se avançar
     * para o próximo elemento, não retroceder.
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

    /*
     * A diferença entre *ptr++ e ++*ptr está relacionada à ordem das operações e ao
     * valor retornado.
     *
     * *ptr++: a operação de pós-incremento *ptr retorna o valor apontado por ptr.
     * ptr++ incrementa o ponteiro para apontar para o próximo local de memória.
     * Portanto, *ptr++ primeiro obtém o valor apontado por ptr e, em seguida,
     * incrementa o ponteiro.
     *
     * ++*ptr: A operação de pré-incremento ++*ptr primeiro incrementa o valor apontado por ptr.
     */

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
     * Este trecho de código foi introduzido demonstra que a utilização de
     * ++(*pointerChar), é atualizado com o incremento o conteúdo apontado pelo
     * ponteiro os valores, ou seja, os que se encontram contidos dentro do vetor.
     */

    for (int i = 0; i < tamCaractere; i++)
    {
        printf("Valor apontado por pointerChar[%d] : %c\n", i, *pointerChar);

        // Incrementa o valor apontado por pointerChar e imprime o valor modificado
        printf("Valor modificado do conteúdo apontado por pointerChar[%d] -> %c\n", i, ++(*pointerChar));

        /*
         * (*pointerChar)++: Porque não é permitido porque tenta incrementar um caractere
         * diretamente, o que não é suportado em C. Em vez disso, você deve manipular
         * diretamente o valor apontado por pointerChar usando atribuições simples ou
         * usar aritmética de ponteiros para navegar através dos elementos do array,
         * e além do mais, o tipo char é um tipo primitivo em C, e não é um tipo que suporta
         * a operação de incremento diretamente.
         */

        // Move pointerChar para o próximo elemento (opcional)
        pointerChar++;
    }
    return 0;
}
