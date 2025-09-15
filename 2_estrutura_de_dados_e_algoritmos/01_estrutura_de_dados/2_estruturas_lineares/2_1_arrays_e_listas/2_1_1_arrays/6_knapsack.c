#include <stdio.h>

/**
 * @brief Retorna o max valor entre dois inteiros.
 *
 * Esta função compara dois inteiros e retorna o max deles.
 *
 * @param a Primeiro valor.
 * @param b Segundo valor.
 * @return O max valor entre a e b.
 */
int max(int a, int b)
{
    // Retorna o max entre a e b usando o operador ternário
    return (a > b) ? a : b;
}

/**
 * @brief Resolve o problema da mochila utilizando programação dinâmica.
 *
 * O algoritmo do Problema da Mochila (ou Knapsack Problem) é um clássico problema de
 * otimização que pode ser resolvido usando programação dinâmica. O objetivo é maximizar o
 * valor total dos itens selecionados para colocar em uma mochila, sem ultrapassar a
 * capacidade máxima dessa mochila.
 *
 * @param capacidade Máximo de peso que a mochila pode carregar.
 * @param pesos Vetor contendo os pesos dos itens.
 * @param valores Vetor contendo os valores dos itens.
 * @param n Número total de itens.
 * @return O valor máximo que pode ser obtido sem exceder a capacidade da mochila.
 */
int mochila(int capacidade, int pesos[], int valores[], size_t n)
{
    // variável dp(dinamic programming) matriz bidimensional de tamanho (n + 1) x (capacidade + 1)
    int dp[n + 1][capacidade + 1];

    // Preenche a matriz dp com as soluções ótimas. Para cada item (de 0 até n)
    for (int i = 0; i <= n; i++)
    {
        // Para cada capacidade (de 0 até a capacidade da mochila)
        for (int j = 0; j <= capacidade; j++)
        {
            // Se não há itens ou capacidade 0
            if (i == 0 || j == 0)
            {
                // A solução ótima é 0, já que a mochila está vazia
                dp[i][j] = 0;
            }
            else if (pesos[i - 1] <= j)
            {
                // Se o peso do item atual é menor ou igual à capacidade restante
                // Calcula o máximo entre:
                // 1) Incluir o item (somando o valor do item + solução para a capacidade restante)
                // 2) Não incluir o item (mantendo a solução sem o item)
                dp[i][j] = max(valores[i - 1] + dp[i - 1][j - pesos[i - 1]], dp[i - 1][j]);
            }
            else
            {
                // Se o item não pode ser incluído (o peso é max que a capacidade)
                // Não inclui o item, então mantém o valor da solução anterior
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    
    // Retorna o valor máximo que pode ser obtido com todos os itens e a capacidade da mochila
    return dp[n][capacidade];
}

int main(int argc, char **argv)
{
    int valores[] = {60, 100, 120};               // Valores dos itens
    int pesos[] = {10, 20, 30};                   // Pesos dos itens
    int capacidade = 50;                          // Capacidade máxima da mochila
    int n = sizeof(valores) / sizeof(valores[0]); // Número total de itens

    // Chama a função mochila para calcular o valor máximo que pode ser obtido
    printf("%d", mochila(capacidade, pesos, valores, n));

    printf("\n----------------------------------\n");

    int valorItens[] = {60, 100, 120, 80};                    // valorItens dos itens
    int weights[] = {10, 20, 30, 40};                         // weights dos itens
    int capacity = 50;                                        // capacidade máxima da mochila
    size_t size = sizeof(valorItens) / sizeof(valorItens[0]); // Número total de itens

    // Chama a função mochila para calcular o valor máximo que pode ser obtido
    int valor = mochila(capacity, weights, valorItens, size);

    // Verifica se o valor total dos itens selecionados excedeu a capacity
    int pesoTotal = 0;

    for (int i = 0; i < size; i++)
    {
        if (pesoTotal + weights[i] <= capacity)
        {
            // Adiciona o peso se não ultrapassar a capacity
            pesoTotal += weights[i];
        }
    }

    printf("Valor máximo da mochila: %d\n", valor);
    printf("Peso total selecionado: %d\n", pesoTotal);

    if (pesoTotal > capacity)
    {
        printf("A mochila foi excedida. Peso total ultrapassa a capacidade!\n");
    }
    else
    {
        printf("A mochila não foi excedida. Peso total dentro da capacidade.\n");
    }
    return 0;
}
