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

    for (size_t i = 0; i <= n; i++)
    {
        result[i] = (int *)malloc((capacity + 1) * sizeof(int));
        if (!result[i])
        {
            fprintf(stderr, "Erro: Falha ao alocar linha da tabela.\n");
            exit(1);
        }
    }

    // Preenche a tabela de programação dinâmica
    for (size_t i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)
            {
                result[i][w] = 0; // Caso base
            }
            else if (weight[i - 1] <= w)
            {
                // Escolhe o máximo entre pegar ou não pegar o item
                result[i][w] = maximo(
                    value[i - 1] + result[i - 1][w - weight[i - 1]],
                    result[i - 1][w]);
            }
            else
            {
                result[i][w] = result[i - 1][w]; // Não pode pegar o item
            }
        }
    }

    printf("\n=== Resultado do Problema da Mochila 0/1 ===\n");
    printf("Valor máximo obtido: %d\n\n", result[n][capacity]);

    // Rastreamento dos itens selecionados
    printf("Itens selecionados:\n");
    printf("-------------------\n");

    int w            = capacity;
    int total_weight = 0;
    int total_value  = 0;

    for (size_t i = n; i > 0; i--)
    {
        if (result[i][w] != result[i - 1][w])
        {
            printf("Item %2zu | Peso: %3d | Valor: %3d\n", i, weight[i - 1], value[i - 1]);
            total_weight += weight[i - 1];
            total_value += value[i - 1];
            w -= weight[i - 1];
        }
    }

    printf("\nResumo:\n");
    printf("Peso total utilizado: %d / %d\n", total_weight, capacity);
    printf("Valor total obtido:   %d\n", total_value);

    // Libera memória
    for (size_t i = 0; i <= n; i++)
    {
        free(result[i]);
    }
    free(result);
}

int main(int argc, char **argv)
{
    size_t n     = 0UL;
    int capacity = 0;

    printf("=== Problema da Mochila 0/1 ===\n\n");

    printf("Digite o número de itens: ");
    if (scanf("%zu", &n) != 1 || n == 0)
    {
        fprintf(stderr, "Erro: Número de itens inválido.\n");
        return 1;
    }

    int *weight = (int *)malloc(n * sizeof(int));
    int *value  = (int *)malloc(n * sizeof(int));

    if (!weight || !value)
    {
        fprintf(stderr, "Erro: Falha ao alocar memória para os vetores.\n");
        free(weight);
        free(value);
        return 1;
    }

    printf("\nDigite os pesos dos itens:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("Peso do item %zu: ", i + 1);
        scanf("%d", &weight[i]);
    }

    printf("\nDigite os valores dos itens:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("Valor do item %zu: ", i + 1);
        scanf("%d", &value[i]);
    }

    printf("\nDigite a capacidade da mochila: ");
    scanf("%d", &capacity);

    if (capacity < 0)
    {
        fprintf(stderr, "Erro: Capacidade não pode ser negativa.\n");
        free(weight);
        free(value);
        return 1;
    }

    knapsack(capacity, n, weight, value);

    free(weight);
    free(value);
    return 0;
}
