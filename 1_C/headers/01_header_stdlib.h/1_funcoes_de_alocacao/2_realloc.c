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
void AlocarERealocarArray(size_t tamanhoInicial, size_t novoTamanho)
{
    if (tamanhoInicial == 0 || novoTamanho == 0)
    {
        fprintf(stderr, "Tamanhos devem ser maiores que zero\n");
        return;
    }

    int *ptr = malloc(tamanhoInicial * sizeof(int));
    if (ptr == NULL)
    {
        fprintf(stderr, "Falha na alocação inicial\n");
        return;
    }
    printf("Memória alocada com sucesso (%zu elementos)\n", tamanhoInicial);

    // Preenche com valores iniciais para demonstrar preservação
    for (size_t i = 0; i < tamanhoInicial; i++)
    {
        ptr[i] = (int)i;
    }

    int *novo_ptr = realloc(ptr, novoTamanho * sizeof(int));
    if (novo_ptr == NULL)
    {
        fprintf(stderr, "Falha na realocação\n");
        free(ptr); // Libera o original
        return;
    }
    ptr = novo_ptr; // Atualiza o ponteiro

    printf("Memória realocada com sucesso (%zu elementos)\n", novoTamanho);
    printf("Conteúdo preservado (primeiros %zu): ", (tamanhoInicial < novoTamanho ? tamanhoInicial : novoTamanho));
    for (size_t i = 0; i < (tamanhoInicial < novoTamanho ? tamanhoInicial : novoTamanho); i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

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
    size_t n_size = 0;
    int soma = 0;
    size_t tamanho_antigo = 0;
    int *p = NULL;

    printf("Digite o tamanho inicial do array: ");
    if (scanf("%zu", &n_size) != 1 || n_size == 0)
    {
        fprintf(stderr, "Tamanho inválido\n");
        return;
    }

    p = malloc(n_size * sizeof(int));
    if (p == NULL)
    {
        fprintf(stderr, "Falha na alocação\n");
        return;
    }

    printf("Preencha o array:\n");
    for (size_t i = 0; i < n_size; i++)
    {
        printf("Elemento %zu: ", i);
        if (scanf("%d", &p[i]) != 1)
        {
            fprintf(stderr, "Entrada inválida\n");
            free(p);
            return;
        }
    }

    printf("Valores: ");
    soma = 0;
    for (size_t i = 0; i < n_size; i++)
    {
        printf("%d ", p[i]);
        soma += p[i];
    }
    printf("\nSoma: %d\n", soma);

    tamanho_antigo = n_size;
    printf("Novo tamanho do array: ");
    if (scanf("%zu", &n_size) != 1 || n_size == 0)
    {
        fprintf(stderr, "Novo tamanho inválido\n");
        free(p);
        return;
    }

    int *novo_p = realloc(p, n_size * sizeof(int));
    if (novo_p == NULL)
    {
        fprintf(stderr, "Falha na realocação\n");
        free(p);
        return;
    }
    p = novo_p;

    if (n_size > tamanho_antigo)
    {
        printf("Preencha os novos elementos:\n");
        for (size_t i = tamanho_antigo; i < n_size; i++)
        {
            printf("Elemento %zu: ", i);
            if (scanf("%d", &p[i]) != 1)
            {
                fprintf(stderr, "Entrada inválida\n");
                free(p);
                return;
            }
        }
    }

    printf("Novos valores: ");
    soma = 0;
    for (size_t i = 0; i < n_size; i++)
    {
        printf("%d ", p[i]);
        soma += p[i];
    }
    printf("\nNova soma: %d\n", soma);

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
    const char *texto_inicial = "Programming";
    const char *texto_adicional = " In 'C'";
    size_t tamanho_inicial = strlen(texto_inicial) + 1; // +1 para '\0'
    size_t tamanho_novo = tamanho_inicial + strlen(texto_adicional);

    char *pointer = malloc(tamanho_inicial * sizeof(char));
    if (pointer == NULL)
    {
        fprintf(stderr, "Falha na alocação inicial\n");
        return;
    }

    strcpy(pointer, texto_inicial);
    printf("String inicial: '%s', Endereço: %p\n", pointer, (void *)pointer);

    char *novo_pointer = realloc(pointer, tamanho_novo * sizeof(char));
    if (novo_pointer == NULL)
    {
        fprintf(stderr, "Falha na realocação\n");
        free(pointer);
        return;
    }
    pointer = novo_pointer;
    strcat(pointer, texto_adicional);
    printf("String expandida: '%s', Endereço: %p\n", pointer, (void *)pointer);
    free(pointer);
}

int main(int argc, char **argv)
{
    printf("\n=== Demonstração de Realloc em C ===\n");

    printf("\n1. Realocação Simples de Array:\n");
    AlocarERealocarArray(10, 20);

    printf("\n2. Gerenciamento de Array Dinâmico:\n");
    GerenciarArrayDinamico();

    printf("\n3. Gerenciamento de String Dinâmica:\n");
    GerenciarStringDinamica();
    return 0;
}
