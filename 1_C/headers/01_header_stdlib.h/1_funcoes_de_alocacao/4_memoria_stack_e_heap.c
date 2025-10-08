#include <stdio.h>
#include <stdlib.h>

/**
 * Uns dos conceitos fundamentais em programação em C/C++ é a alocação de memória.
 *
 * Stack:
 * - Alocação automática e rápida
 * - Tamanho limitado (tipicamente 1-8 MB)
 * - Memória liberada automaticamente quando a função retorna
 * - Acesso mais rápido
 *
 * Heap:
 * - Alocação manual e flexível(dinâmica usando malloc/calloc/realloc)
 * - Tamanho limitado apenas pela memória disponível
 * - Deve ser liberada manualmente com free()
 * - Acesso um pouco mais lento
 */

struct alocaTiposEstaticos
{
    int int_stack;       // 4 bytes
    char char_stack;     // 1 byte
    double double_stack; // 8 bytes
};

struct alocaTiposDinamicos
{
    int *int_heap;       // 8 bytes (pointer)
    char *char_heap;     // 8 bytes (pointer)
    double *double_heap; // 8 bytes (pointer)
    void *void_heap;     // 8 bytes (pointer)
};

// Função genérica para exibir rastreamento de memória
void track_memory(const char *function_name, size_t stack_size, size_t heap_size)
{
    printf("\n[Uso de Memória: %s]\n", function_name);
    printf("  Stack: %zu bytes\n", stack_size);
    printf("  Heap : %zu bytes\n", heap_size);
    printf("----------------------------------------\n");
}

// Função para demonstrar alocação na stack
void alocacao_stack(void)
{
    int stack_var = 42;         // 4 bytes
    char stack_char = 'A';      // 1 byte
    double stack_double = 3.14; // 8 bytes

    // Calcula memória da stack (incluindo padding de alinhamento)
    /// @note tamanho da stack pode incluir padding (limitado a 8 bytes)
    size_t stack_size = sizeof(stack_var) + sizeof(stack_char) + sizeof(stack_double);

    // Sem alocação na heap
    size_t heap_size = 0;

    printf("\n=== [STACK] Alocação Automática ===\n");
    printf("  Inteiro: %d  | Endereço: %p\n", stack_var, (void *)&stack_var);
    printf("  Char   : %c  | Endereço: %p\n", stack_char, (void *)&stack_char);
    printf("  Double : %.2f | Endereço: %p\n", stack_double, (void *)&stack_double);

    track_memory("alocacao_stack", stack_size, heap_size);
}

// Função para demonstrar alocação na heap
void alocacao_heap(void)
{
    // Stack: Ponteiros (8 bytes cada em sistemas 64-bit)
    int *heap_var = (int *)malloc(sizeof(int));             // Heap: 4 bytes
    char *heap_char = (char *)malloc(sizeof(char));         // Heap: 1 byte
    double *heap_double = (double *)malloc(sizeof(double)); // Heap: 8 bytes

    // Calcula memória
    size_t stack_size = sizeof(heap_var) + sizeof(heap_char) + sizeof(heap_double); // 3 ponteiros = 24 bytes
    size_t heap_size = sizeof(int) + sizeof(char) + sizeof(double);                 // Alocações na heap

    if (!heap_var || !heap_char || !heap_double) // Verifica falha na alocação
    {
        printf("Erro na alocação de memória!\n");

        // Limpeza para evitar vazamentos
        free(heap_var);
        free(heap_char);
        free(heap_double);
        track_memory("alocacao_heap", stack_size, 0); // Reporta alocação parcial
        return;
    }

    *heap_var = 42;
    *heap_char = 'B';
    *heap_double = 2.71;

    printf("\n=== [HEAP] Alocação Dinâmica ===\n");
    printf("  Inteiro: %d  | Ponteiro: %p | Valor armazenado em: %p\n", *heap_var, (void *)&heap_var, (void *)heap_var);
    printf("  Char   : %c  | Ponteiro: %p | Valor armazenado em: %p\n", *heap_char, (void *)&heap_char, (void *)heap_char);
    printf("  Double : %.2f | Ponteiro: %p | Valor armazenado em: %p\n", *heap_double, (void *)&heap_double, (void *)heap_double);

    track_memory("alocacao_heap", stack_size, heap_size);

    free(heap_var);
    free(heap_char);
    free(heap_double);
}

// Função para demonstrar vazamento de memória
void demonstra_vazamento_memoria(void)
{
    printf("\n=== [DEMONSTRAÇÃO] Vazamento de Memória ===\n");

    int *vazamento = (int *)malloc(sizeof(int) * 1000); // Heap: 4000 bytes
    size_t stack_size = sizeof(vazamento);              // 8 bytes (pointer)
    size_t heap_size = sizeof(int) * 1000;              // 4000 bytes

    if (vazamento == NULL)
    {
        printf("Erro na alocação de memória!\n");
        track_memory("demonstra_vazamento_memoria", stack_size, 0);
        return;
    }

    *vazamento = 100;
    printf("  Valor armazenado: %d | Endereço (heap): %p\n", *vazamento, (void *)vazamento);

    track_memory("demonstra_vazamento_memoria", stack_size, heap_size);
    // Intencionalmente não libera a memória para demonstrar vazamento
    // free(vazamento); // Uncomment to fix leak
}

// Função para demonstrar arrays na stack vs heap
void arrays_stack_vs_heap(void)
{
    printf("\n=== [ARRAYS] Stack vs Heap ===\n");

    int array_stack[5] = {1, 2, 3, 4, 5};                   // Stack: 20 bytes
    int tamanho = 5;                                        // Stack: 4 bytes
    int *array_heap = (int *)malloc(sizeof(int) * tamanho); // Heap: 20 bytes

    size_t stack_size = sizeof(array_stack) + sizeof(tamanho) + sizeof(array_heap); // 20 + 4 + 8
    size_t heap_size = sizeof(int) * tamanho;                                       // 20 bytes

    if (array_heap == NULL)
    {
        printf("Erro na alocação de memória!\n");
        track_memory("arrays_stack_vs_heap", stack_size, 0);
        return;
    }

    for (int i = 0; i < tamanho; i++)
    {
        array_heap[i] = i * 10;
    }

    printf("  Array Stack: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", array_stack[i]);
    }
    printf(" | Endereço base: %p\n", (void *)array_stack);

    printf("Array heap: ");
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", array_heap[i]);
    }
    printf(" | Endereço base: %p\n", (void *)array_heap);
    printf("\n");

    track_memory("arrays_stack_vs_heap", stack_size, heap_size);

    free(array_heap);
}

// Função para demonstrar matrizes na stack vs heap
void matriz_stack_vs_heap(void)
{
    printf("\n=== [MATRIZES] Stack vs Heap ===\n");

    int matriz_stack[2][3] = {{1, 2, 3}, {4, 5, 6}};            // Stack: 24 bytes
    int linhas = 2;                                             // Stack: 4 bytes
    int colunas = 3;                                            // Stack: 4 bytes
    int **matriz_heap = (int **)malloc(linhas * sizeof(int *)); // Heap: 16 bytes

    // 24 + 4 + 4 + 8
    size_t stack_size = sizeof(matriz_stack) + sizeof(linhas) + sizeof(colunas) + sizeof(matriz_heap);

    // 16 bytes for pointer array
    size_t heap_size = linhas * sizeof(int *);

    if (matriz_heap == NULL)
    {
        printf("Erro na alocação de memória!\n");
        track_memory("matriz_stack_vs_heap", stack_size, 0);
        return;
    }

    for (int i = 0; i < linhas; i++)
    {
        matriz_heap[i] = (int *)malloc(colunas * sizeof(int));
        if (!matriz_heap[i])
        {
            for (int j = 0; j < i; j++)
                free(matriz_heap[j]);
            free(matriz_heap);
            track_memory("matriz_stack_vs_heap", stack_size, heap_size);
            return;
        }

        heap_size += colunas * sizeof(int);
        for (int j = 0; j < colunas; j++)
            matriz_heap[i][j] = (i + 1) * (j + 1);
    }

    printf("  Matriz Stack (%p):\n", (void *)matriz_stack);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%d ", matriz_stack[i][j]);
        printf("\n");
    }

    printf("  Matriz Heap (%p):\n", (void *)matriz_heap);
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
            printf("%d ", matriz_heap[i][j]);
        printf("\n");
    }

    track_memory("matriz_stack_vs_heap", stack_size, heap_size);

    // Libera memória alocada na heap
    for (int i = 0; i < linhas; i++)
    {
        free(matriz_heap[i]);
    }
    free(matriz_heap);
}

int main(int argc, char **argv)
{
    printf("=== Demonstração Stack vs Heap ===\n");

    // Arrays to store memory usage for summary
    const char *functions[] = {"alocacao_stack", "alocacao_heap", "arrays_stack_vs_heap", "matriz_stack_vs_heap", "demonstra_vazamento"};
    size_t stack_sizes[5] = {13, 24, 32, 40, 8};
    size_t heap_sizes[5] = {0, 13, 20, 40, 4000};

    alocacao_stack();
    alocacao_heap();
    arrays_stack_vs_heap();
    matriz_stack_vs_heap();
    demonstra_vazamento_memoria();

    // Print CSV-like output for external visualization
    printf("\n=== Resumo de Uso de Memória ===\n");
    printf("Function | Stack (bytes) | Heap (bytes)\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%-20s | %-15zu | %-15zu\n", functions[i], stack_sizes[i], heap_sizes[i]);
    }

    printf("\n=== Fim da Demonstração ===\n");
    return 0;

    /**
     * Note:
     * - Sempre verifique se malloc/calloc/realloc retornam NULL.
     * - Sempre libere a memória alocada na heap com free() para evitar vazamentos.
     * - Use ferramentas como Valgrind para detectar vazamentos de memória.
     */
}
