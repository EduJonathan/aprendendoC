#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Realloc(): Utilizada para redimensionar adicionando mais tamanho para a memória
 * já alocada. Expandindo o bloco enquanto corrige o conteúdo original como estava.
 * realloc() em C significa reatribuição de memória. realloc() também pode ser usado
 * para reduzir o tamanho da memória previamente alocada.
 *
 * SINTAXE: void *realloc(void *_Memory, size_t _NewSize),
 *
 * @param _Memory: Endereço do bloco a ser reatribuído.
 * @param _NewSize: Novo tamanho da memória.
 * @return Retorna um ponteiro para o novo bloco alocado. recebendo o endereço do bloco
 * para ser alocado (ponteiro) e retorna um novo bloco alocado
 */

/**
 * @brief Aloca e realoca memória para um array de inteiros.
 *
 * Esta função aloca memória para um array de inteiros com um tamanho inicial e,
 * em seguida, realoca o array para um novo tamanho.
 *
 * @param tamanhoInicial O tamanho inicial do array.
 * @param novoTamanho O novo tamanho do array após a realocação.
 */
void AlocarERealocarArray(int tamanhoInicial, int novoTamanho)
{
    // Aloca memória para o array
    int *ptr = (int *)malloc(tamanhoInicial * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (ptr == NULL)
    {
        printf("MEMÓRIA NÃO ALOCADA\n");
        return;
    }

    printf("MEMÓRIA ALOCADA\n");

    // Realoca memória para o array com um novo tamanho
    ptr = (int *)realloc(ptr, novoTamanho * sizeof(int));

    if (ptr == NULL)
    {
        printf("MEMÓRIA REALOCADA NÃO SUCESSO\n");
        return;
    }

    printf("MEMÓRIA REALOCADA COM SUCESSO\n");

    // Libera a memória alocada
    free(ptr);
}

/**
 * @brief Gerencia um array dinâmico, incluindo alocação, preenchimento, e realocação.
 *
 * Esta função aloca memória para um array de inteiros, preenche o array com valores
 * fornecidos pelo usuário, calcula a soma dos valores, realoca o array para um novo
 * tamanho, e novamente preenche e calcula a soma dos valores.
 */
void GerenciarArrayDinamico(void)
{
    int n_size = 0;
    int soma = 0;
    int x = 0;
    int *p = NULL;

    // Solicita o tamanho inicial ao usuário
    printf("Digite o tamanho que deseja alocar: ");
    scanf("%d", &n_size);

    // Aloca memória para o array
    p = (int *)malloc(n_size * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (!p)
    {
        printf("Memória não alocada\n");
        return;
    }

    // Preenche o array com valores fornecidos pelo usuário
    for (int i = 0; i < n_size; i++)
    {
        printf("Entre com o %d valor: ", i);
        scanf("%d", (p + i));
    }

    // Exibe os valores e calcula a soma
    printf("Seus valores são: ");

    // Preenche o array com valores fornecidos pelo usuário
    for (int i = 0; i < n_size; i++)
    {
        // Exibe os valores
        printf(" %d", *(p + i));

        // Calcula a soma
        soma += *(p + i);
    }

    printf("\nSoma dos elementos é = %d", soma);

    // Solicita o novo tamanho e realoca memória
    x = n_size;
    printf("\n\nAloque um novo valor para o array: ");
    scanf("%d", &n_size);

    // Utilizando o realloc para obter um novo bloco de memória alocado
    p = (int *)realloc(p, n_size * sizeof(int));

    // Verifica se a realocação foi bem-sucedida
    if (!p)
    {
        printf("Memória não realocada\n");
        exit(1); // Encerra o programa
    }

    // Preenche os novos elementos no array
    for (int i = x; i < n_size; i++)
    {
        printf("Adicione novos valores para %d: ", i);
        scanf("%d", (p + i));
    }

    // Exibe os valores e calcula a nova soma
    printf("Os valores são: ");

    soma = 0;
    for (int i = 0; i < n_size; i++)
    {
        printf(" %d", *(p + i));
        soma += *(p + i);
    }

    printf("\nSoma dos elementos é = %d\n", soma);

    // Libera a memória alocada
    free(p);
}

/**
 * @brief Aloca, realoca e manipula uma string dinâmica.
 *
 * Esta função aloca memória para uma string, copia um texto para o espaço alocado,
 * realoca a memória para aumentar o tamanho, adiciona mais conteúdo à string e exibe o
 * texto e o endereço da memória.
 */
void GerenciarStringDinamica(void)
{
    char *pointer = NULL;

    // Aloca memória para a string inicial
    pointer = (char *)malloc(30 * sizeof(char));

    if (pointer == NULL)
    {
        printf("Memória não alocada\n");
        return;
    }

    // Copia a string para o espaço alocado
    strcpy(pointer, "Programming");

    // Exibe a string e o endereço
    printf(" %s, Address = %p\n", pointer, (void *)pointer);

    // Realoca a memória para aumentar o tamanho
    pointer = (char *)realloc(pointer, 50 * sizeof(char));
    if (pointer == NULL)
    {
        printf("Memória não realocada\n");
        return;
    }

    // Adiciona mais conteúdo à string
    strcat(pointer, " In 'C'");

    // Exibe a string e o novo endereço
    printf(" %s, Address = %p\n", pointer, (void *)pointer);

    // Libera a memória alocada
    free(pointer);
}

int main(int argc, char **argv)
{
    printf("PRIMEIRO CASO:\n");

    int tamanhoInicial = 10;
    int novoTamanho = 20;

    // Chama a função para alocar e realocar o array
    AlocarERealocarArray(tamanhoInicial, novoTamanho);

    printf("\n--------------------------------\n");
    printf("\n\nSEGUNDO CASO:\n");

    GerenciarArrayDinamico();

    printf("\n--------------------------------\n");
    printf("\n\nTERCEIRO CASO\n");

    GerenciarStringDinamica();
    return 0;
}
