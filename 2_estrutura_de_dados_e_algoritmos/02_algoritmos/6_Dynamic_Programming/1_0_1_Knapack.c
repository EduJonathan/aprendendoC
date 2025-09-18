#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para retornar o máximo entre dois inteiros
int maxixmo(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * @brief Resolve o Problema da Mochila 0-1 (0-1 Knapsack) usando Programação Dinâmica.
 *
 * Esse é um exemplo clássico de PD, onde é necessário maximizar o valor de itens selecionados
 * sem ultrapassar o peso máximo permitido. A solução é construída de forma bottom-up,
 * utilizando uma tabela para armazenar os resultados intermediários e evitar recomputações.
 *
 * Formulação da recorrência:
 *
 * - Se não pegarmos o item i: K[i][w] = K[i - 1][w]
 *
 * - Se pegarmos o item i: K[i][w] = K[i - 1][w - weight[i]] + value[i]
 *
 * - A decisão depende de qual dessas escolhas fornece maior valor, considerando restrições de peso.
 *
 * @param capacity Capacidade máxima da mochila.
 * @param n Número de itens disponíveis.
 * @param weight Vetor contendo os pesos dos itens.
 * @param value Vetor contendo os valores dos itens.
 * @return Retorna o valor máximo que pode ser obtido com os itens dados sem ultrapassar a capacidade.
 */
void Knapsack(int capacity, size_t n, int weight[], int value[])
{
    // Aloca matriz de resultados [n+1][capacity+1]
    int **result = (int **)malloc((n + 1) * sizeof(int *));

    if (!result)
    {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    for (size_t i = 0ull; i <= n; i++)
    {
        result[i] = (int *)malloc((capacity + 1) * sizeof(int));
        if (!result[i])
        {
            fprintf(stderr, "Erro ao alocar memória.\n");
            exit(1);
        }
    }

    // Preenche tabela de programação dinâmica
    for (size_t i = 0ull; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                result[i][w] = 0;
            }
            else if (weight[i - 1] <= w)
            {
                result[i][w] = maxixmo(
                    value[i - 1] + result[i - 1][w - weight[i - 1]],
                    result[i - 1][w]);
            }
            else
            {
                result[i][w] = result[i - 1][w];
            }
        }
    }

    // Resultado final
    printf("\nValor máximo obtido: %d\n", result[n][capacity]);

    // Rastreia os itens selecionados
    printf("Itens selecionados:\n");

    int w = capacity;

    for (size_t i = n; i > 0; i--)
    {
        if (result[i][w] != result[i - 1][w])
        {
            printf(" - Item %zu (peso: %d, valor: %d)\n", i, weight[i - 1], value[i - 1]);
            w -= weight[i - 1];
        }
    }

    // Libera memória
    for (size_t i = 0ull; i <= n; i++)
    {
        free(result[i]);
    }
    free(result);
}

int main(int argc, char **argv)
{
    size_t n = 0ull;
    printf("Número de itens: ");
    scanf("%zu", &n);

    int *weight = (int *)malloc(n * sizeof(int));
    int *value = (int *)malloc(n * sizeof(int));
    if (!weight || !value)
    {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    printf("Peso dos itens:\n");
    for (size_t i = 0ull; i < n; i++)
    {
        printf(" - Item %zu: ", i + 1);
        scanf("%d", &weight[i]);
    }

    printf("Valor dos itens:\n");
    for (size_t i = 0ull; i < n; i++)
    {
        printf(" - Item %zu: ", i + 1);
        scanf("%d", &value[i]);
    }

    int capacity = 0;
    printf("Capacidade da mochila: ");
    scanf("%d", &capacity);

    Knapsack(capacity, n, weight, value);

    free(weight);
    free(value);
    return 0;
}
