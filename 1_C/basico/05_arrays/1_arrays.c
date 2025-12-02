#include <stdio.h>
#include <stddef.h>

/**
 * ARRAYS: Ou vetores, são estruturas unidimensionais que armazenam uma coleção de
 * valores de um único tipo de dado, simplificando, são estruturas indexadas para guardar
 * dados de um mesmo tipo. É estruturado na memória uma sequência de endereços para cada
 * indíce para armazenar um valor.
 *
 * EXE:
 * --------------------------------------------------
 * | array[0]  | array[1]  | array[2]  | array[...n]|
 * --------------------------------------------------
 * | &array[0] | &array[1] | &array[2] |   ...      |
 * --------------------------------------------------
 *
 * VETORES: Estruturas sequencias que guardam os dados de forma sequenciais indexadas.
 * INDEX: Individualizadas as posições de cada valor por meios de índices, começando por 0.
 * INDICES: limitação de quantos elementos deseja que o vetor possua
 *

 * SINTAXE: <tipo de dado><nome do array>[Nº elementos];
 * int arr[10]; // declaração de um array
 * arr[0] -> posição ou index/indíce 0
 * arr[1] -> posição ou index/indíce 1
 * arr[2] -> posição ou index/indíce 2
 * arr[3] -> posição ou index/indíce 3
 * arr[4] -> posição ou index/indíce 4
 * arr[5] -> posição ou index/indíce 5
 * arr[6] -> posição ou index/indíce 6
 * arr[7] -> posição ou index/indíce 7
 * arr[8] -> posição ou index/indíce 8
 * arr[9] -> posição ou index/indíce 9
 */

int main(int argc, char **argv)
{
    char array[5] = {0};

    array[0] = 'A';
    array[1] = 'M';
    array[2] = 'O';
    array[3] = 'R';
    array[4] = '\0';

    printf("\n=============================================================================\n");
    printf("\n\t>>IMPRIMINDO INFORMAÇÕES SOBRE ARRAY<<\n");

    size_t tamanho_total = sizeof(array);                  // Calcula o tamanho total do vetor em bytes
    size_t n_Elementos = sizeof(array) / sizeof(array[0]); // Obtém o número de elementos no vetor

    /**
     * SIZE_T: Tipo de dado sem sinal destinado a representar tamanhos e contagens de objetos em bytes.
     *
     * Vantagens sobre int/unsigned int:
     *   - Sempre sem sinal, evitando valores negativos para tamanhos e índices.
     *   - Garantido ser grande o suficiente para representar o tamanho máximo de qualquer objeto,
     *     garantindo portabilidade entre sistemas 32 e 64 bits.
     *   - Ideal para contar elementos de arrays, armazenar tamanhos retornados por sizeof
     *     e para índices de loops quando se trabalha com estruturas de dados.
     *   - Seu tamanho é praticamente um unsigned long long, sendo seu sufixo `ULL`.
     *
     * Pode ser incluído via <stddef> (ou outros headers padrão) e impresso com o formato "%zu".
     */

    printf(" Tamanho total do 'array'       : %zu bytes\n", tamanho_total);
    printf(" Número de elementos no 'array' : %zu\n", n_Elementos);

    printf("\n===================================================================\n");
    printf("\n\t>>IMPRIMINDO CONTEÚDO POSIÇÃO POR POSIÇÃO<<\n");

    printf(" POSIÇÃO 1 DE array[0] é : %c\n", array[0]);
    printf(" POSIÇÃO 2 DE array[1] é : %c\n", array[1]);
    printf(" POSIÇÃO 3 DE array[2] é : %c\n", array[2]);
    printf(" POSIÇÃO 4 DE array[3] é : %c\n", array[3]);
    printf(" POSIÇÃO 5 DE array[4] é : %c\n", array[4]);

    printf("\n\tALTERANDO CONTEÚDO POSIÇÃO POR POSIÇÃO: \n");

    printf(" ALTERANDO A POSIÇÃO 1 DE array[0] é: ");
    scanf("%c", &array[0]);
    setbuf(stdin, NULL);

    printf(" ALTERANDO A POSIÇÃO 2 DE array[1] é: ");
    scanf("%c", &array[1]);
    setbuf(stdin, NULL);

    printf(" ALTERANDO A POSIÇÃO 3 DE array[2] é: ");
    scanf("%c", &array[2]);
    setbuf(stdin, NULL);

    printf(" ALTERANDO A POSIÇÃO 4 DE array[3] é: ");
    scanf("%c", &array[3]);
    setbuf(stdin, NULL);

    printf(" ALTERANDO A POSIÇÃO 5 DE array[4] é: ");
    scanf("%c", &array[4]);
    setbuf(stdin, NULL);

    printf("\n\t>>IMPRIMINDO CONTEÚDO ALTERADO<<\n");

    printf(" POSIÇÃO 1 DE array[0] é : %c\n", array[0]);
    printf(" POSIÇÃO 2 DE array[1] é : %c\n", array[1]);
    printf(" POSIÇÃO 3 DE array[2] é : %c\n", array[2]);
    printf(" POSIÇÃO 4 DE array[3] é : %c\n", array[3]);
    printf(" POSIÇÃO 5 DE array[4] é : %c\n", array[4]);

    printf("\n=====================================================================\n");
    printf("\n\t>>IMPRIMINDO INFORMAÇÕES SOBRE ARR<<\n");

    // Declarando um array int e inicializando seus valores diretamente
    int arr[10] = {5, 8, 6, 10, 89, -75, 65, 45, 9, 6};

    /**
     * ATENCAO: Ao declarar a quantidade de índices que o vetor eles são multiplicados
     * pela quantidade de bytes que o tipo de dado possui sendo então no exemplo,
     * temos: int arr[10], a quantidades de bytes do tipo é de 4 bytes, sendo então
     * multiplicado por 10 temos 40 bytes alocados na memória para armazenar todos os
     * dados que se encontram no array arr.
     */

    size_t tamanho_Total = sizeof(arr);               // Calcula o tamanho total do arr em bytes
    size_t nElementos = sizeof(arr) / sizeof(arr[0]); // Obtém o número de elementos no arr

    printf(" Tamanho total do 'arr'       : %zu bytes\n", tamanho_Total);
    printf(" Número de elementos no 'arr' : %zu\n", nElementos);

    printf("\n======================================================================\n");
    printf("\n\tIMPRIMINDO POSIÇÃO A MAIS DO ARRAY ARR:\n");

    for (int i = 0; i <= 10; i++)
    {
        printf(" Posição[%d] = %d\n", i, arr[i]);
    }

    /*
     * GARBAGE MEMORY: Valor armazenado sem uma inicialização, ou atribuído a um valor adequado.
     * Caso tentar imprimir uma posição a mais sem que ela exista, e que por mais
     * que você adicione no final da última posição do vetor sem alterar o limite,
     * passando do limite a qual você inseriu no índice do vetor irá gerar um número
     * totalmente aleátorio, conhecido como lixo de memória.
     */

    printf("\n=======================================================================\n");
    printf("\n\t>>IMPRIMINDO ATRAVÉS DO FOR<<\n");

    for (int i = 0; i < nElementos; i++)
    {
        printf(" Posição %d: %d\n", i, arr[i]);
    }

    printf("\n=======================================================================\n");
    printf("\n\t>>ADICIONANDO +1 PARA CADA POSIÇÃO<<\n");

    for (int i = 0; i < nElementos; i++)
    {
        arr[i] = arr[i] + 1; // Vai incrementando todos os elementos do array "arr"
        printf(" Posição [%d]: %d\n", i, arr[i]);
    }

    printf("\n========================================================================\n");
    printf("\n\t>>MUDANDO O CONTEÚDO DE CADA POSIÇÃO<<\n");

    for (int i = 0; i < nElementos; i++)
    {
        printf("Insira o valor para posição [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n=====================================================================\n");

    // Exibe o valor atualizado pelo scanf
    for (size_t i = 0ull; i < nElementos; i++)
    {
        printf(" Posicao [%zu] Valor alterado para: %d\n", i, arr[i]);
    }
    // Como discutido, preferimos utilizar a variável `nElementos` em vez
    // de um número fixo como 10 for (int i = 0; i < 10; i++),
    // porque ela é mais flexível e garante que o código funcione independentemente do
    // tamanho real do array, e trabalhando melhor com números não negativos.
    return 0;
}
