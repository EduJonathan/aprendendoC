#include <stdio.h>
#include <stdlib.h>

/**
 * Sobre o uso de vetores (arrays) em C:
 *
 * 1. DECLARAÇÃO BÁSICA
 *    - O tamanho do array deve ser conhecido em tempo de compilação (exceto quando alocado dinamicamente).
 *    - Os índices vão de 0 até (tamanho - 1).
 *
 * 2. TIPOS DE DECLARAÇÃO
 *    a) Tamanho fixo explícito.
 *    b) Tamanho implícito (com inicialização).
 *    c) Alocação dinâmica (quando o tamanho é desconhecido até o tempo de execução).
 *
 * 3. TABELA COMPARATIVA
 * +----------------------+------------------+---------------------+-----------------------+
 * | Declaração           | Tamanho Definido?| Inicialização       | Uso                   |
 * +----------------------+------------------+---------------------+-----------------------+
 * | int v[10];           | Sim (fixo)       | Opcional            | Uso imediato          |
 * | int v[] = {1,2,3};   | Sim (implícito)  | Obrigatória         | Uso imediato          |
 * | int v[];             | Inválido         | -                   | Erro de compilação    |
 * | int *v = malloc(n);  | Dinâmico         | Necessário free()   | Ponteiro manipulável  |
 * +----------------------+------------------+---------------------+-----------------------+
 */

#define TAMANHO_FIXO 5 // Constante para vetor fixo

int main(int argc, char **argv)
{
    // 1. Vetor com tamanho fixo
    int vetor_fixo[TAMANHO_FIXO];
    for (int i = 0; i < TAMANHO_FIXO; i++)
    {
        vetor_fixo[i] = i * 2;
    }

    printf("\n-------------------------------------\n");

    // 2. Vetor com tamanho implícito (inicialização obrigatória)
    int vetor_impl[] = {1, 3, 5, 7, 9};

    for (int i = 0; i < 5; i++)
    {
        printf("vetor_impl[indice = %d] -> %d\n", i, vetor_impl[i]);
    }

    printf("\n-------------------------------------\n");

    // 3. Vetor com tamanho fornecido pelo usuário — deve ser dinâmico!
    size_t n = 0;
    printf("Insira o tamanho do array: ");
    scanf("%zu", &n);

    int *array_para_definir = malloc(n * sizeof(int));
    if (array_para_definir == NULL)
    {
        printf("Erro ao alocar memória para array_para_definir!\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++)
    {
        array_para_definir[i] = i + 1;
        printf("array_para_definir[indice = %zu] -> %d\n", i, array_para_definir[i]);
    }

    printf("\n-------------------------------------\n");

    // 4. Vetor dinâmico (outra forma)
    int tamanho = 0;
    printf("Digite o tamanho do vetor dinâmico: ");
    scanf("%d", &tamanho);

    int *vetor_din = malloc(tamanho * sizeof(int));
    if (vetor_din == NULL)
    {
        printf("Erro na alocação de memória!\n");
        free(array_para_definir);
        return 1;
    }

    for (int i = 0; i < tamanho; i++)
    {
        vetor_din[i] = i * i;
    }

    printf("\n-------------------------------------\n");

    // 5. Exibindo vetor fixo
    printf("Elementos do vetor fixo (tamanho %d):\n", TAMANHO_FIXO);
    for (int i = 0; i < TAMANHO_FIXO; i++)
    {
        printf("vetor_fixo[%d] = %d\n", i, vetor_fixo[i]);
    }

    printf("\n-------------------------------------\n");

    // 6. Exibindo os elementos do vetor dinâmico
    printf("Elementos do vetor dinâmico (tamanho %d):\n", tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        printf("vetor_din[%d] = %d\n", i, vetor_din[i]);
    }

    // 7. Cuidado com limites de acesso!
    // Exemplo de acesso inválido:
    // printf("%d", vetor_fixo[TAMANHO_FIXO]); // Comportamento indefinido!

    // 8. Liberação de memória, extrema importância
    free(array_para_definir);
    free(vetor_din);

    /**
     * Entender esses comportamentos ajuda a programar com mais segurança,
     * principalmente ao lidar com vetores/matrizes e gerenciamento de memória em C.
     *
     * Isso evita erros como:
     * - acesso a posições inválidas (estouro de índice),
     * - vazamento de memória (não liberar com free),
     * - confusão entre vetores e ponteiros ao passar para funções.
     */
    return 0;
}
