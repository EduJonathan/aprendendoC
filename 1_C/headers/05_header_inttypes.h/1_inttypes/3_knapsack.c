#include <stdio.h>
#include <stdint.h>

/**
 * Este programa testa todas as combinações possíveis de itens para encontrar
 * o subconjunto com maior valor que respeita a capacidade máxima da mochila.
 * A solução é representada por um bitmask que indica quais itens foram escolhidos.
 */

/**
 * @struct item_t
 * @brief Representa um item disponível na mochila.
 */
typedef struct
{
    const char *item_name; /**< Nome do item */
    int weight;            /**< Peso em unidades arbitrárias */
    int value;             /**< Valor associado ao item */
} item_t;

/**
 * @brief Lista fixa de itens disponíveis para escolha.
 */
item_t itens[] = {
    {"Mapa", 9, 150},
    {"Maça", 39, 40},
    {"Garrafa D'agua", 153, 200},
    {"Banana", 27, 60},
    {"Guarda chuva", 73, 40},
    {"Óculos", 7, 20},
    {"Caderno de anotação", 22, 80},
    {"Livro", 30, 10},
};

/** @brief Quantidade total de itens. */
#define n_itens (sizeof(itens) / sizeof(item_t))

/** @brief Capacidade máxima da mochila. */
#define CAPACIDADE 400

/**
 * @struct solution_t
 * @brief Representa uma solução candidata ao problema.
 */
typedef struct
{
    uint32_t bits; /**< Bitmask que indica os itens incluídos */
    int value;     /**< Valor total dos itens selecionados */
    int weight;    /**< Peso total dos itens selecionados */
} solution_t;

/**
 * @brief Variável global que armazena a melhor solução encontrada.
 */
solution_t best = {0, 0, 0};

/**
 * @brief Função recursiva que explora todas as combinações possíveis de itens.
 *
 * A cada passo, decide-se:
 * - Ignorar o item atual
 * - Incluir o item atual (se couber na capacidade)
 *
 * Quando `index` chega a -1, significa que uma combinação completa foi testada.
 *
 * @param capacidade_restante Capacidade restante da mochila
 * @param index Índice do item atual (decresce até -1)
 * @param bits_atual Bitmask representando os itens escolhidos até o momento
 * @param valor_atual Soma dos valores dos itens selecionados
 * @param peso_atual Soma dos pesos dos itens selecionados
 */
void otimizar(int capacidade_restante, int index, uint32_t bits_atual, int valor_atual, int peso_atual)
{
    if (index < 0)
    {
        if (valor_atual > best.value)
        {
            best.bits = bits_atual;
            best.value = valor_atual;
            best.weight = peso_atual;
        }
        return;
    }

    // Não incluir o item atual
    otimizar(capacidade_restante,
             index - 1,
             bits_atual,
             valor_atual,
             peso_atual);

    // Incluir o item atual, se houver capacidade
    if (capacidade_restante >= itens[index].weight)
    {
        otimizar(capacidade_restante - itens[index].weight,
                 index - 1,
                 bits_atual | (1u << index),
                 valor_atual + itens[index].value,
                 peso_atual + itens[index].weight);
    }
}

int main(int argc, char **argv)
{
    otimizar(CAPACIDADE, n_itens - 1, 0, 0, 0);

    printf("Capacidade da mochila: %d\n", CAPACIDADE);
    printf("Itens selecionados:\n");

    for (int i = 0; i < n_itens; i++)
    {
        if (best.bits & (1u << i))
        {
            printf("  - %s (peso: %d, valor: %d)\n",
                   itens[i].item_name,
                   itens[i].weight,
                   itens[i].value);
        }
    }

    printf("\nValor total: %d\n", best.value);
    printf("Peso total: %d\n", best.weight);
    return 0;
}
