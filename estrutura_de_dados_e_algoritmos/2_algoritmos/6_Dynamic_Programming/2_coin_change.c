#include <stdio.h>
#include <limits.h>

// Função auxiliar para retornar o máximo entre dois inteiros
int min(int a, int b)
{
    return (a < b) ? a : b;
}

/**
 * O problema da troca de moedas visa encontrar o número mínimo de moedas para uma determinada
 * quantia. Esse problema é uma ótima aplicação de PD, pois podemos calcular o valor mínimo de
 * moedas para todos os valores até o valor final e, assim, encontrar a solução ótima.
 *
 * Recorrência:
 * Para cada valor 𝑣, a solução pode ser expressa como:
 * 𝑑𝑝[𝑣] = min⁡(𝑑𝑝[𝑣], 𝑑𝑝[𝑣 − 𝑐𝑜𝑖𝑛] + 1)
 *
 * Onde coin são as moedas disponíveis.
 *
 * @param coins vetor com os valores das moedas disponíveis
 * @param n número de moedas diferentes
 * @param N valor alvo a ser formado;
 * @param used_coins vetor de saída para armazenar as moedas utilizadas na solução ótima.
 */
int coinChange(int coins[], size_t n, int N, int used_coins[])
{
    int dp[N + 1];
    int last_coin[N + 1]; // Rastreia a última moeda usada

    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        dp[i] = INT_MAX;
        last_coin[i] = -1;
    }

    for (size_t c = 0; c < n; c++)
    {
        for (int v = coins[c]; v <= N; v++)
        {
            if (dp[v - coins[c]] != INT_MAX && dp[v] > dp[v - coins[c]] + 1)
            {
                dp[v] = dp[v - coins[c]] + 1;
                last_coin[v] = c; // Armazena o índice da moeda
            }
        }
    }

    if (dp[N] == INT_MAX)
    {
        return -1;
    }

    // Preenche o vetor used_coins com as moedas usadas
    int remaining = N;
    int count = 0;
    while (remaining > 0)
    {
        int coin = coins[last_coin[remaining]];
        used_coins[count++] = coin;
        remaining -= coin;
    }

    return dp[N];
}

int main(int argc, char **argv)
{
    int coins[] = {1, 2, 3, 4};
    size_t n = sizeof(coins) / sizeof(coins[0]);
    int N = 15;
    int used_coins[N]; // Vetor para armazenar as moedas usadas

    int result = coinChange(coins, n, N, used_coins);
    if (result == -1)
    {
        printf("Não é possível obter o valor %d.\n", N);
    }
    else
    {
        printf("Número mínimo de moedas para %d: %d\n", N, result);
        printf("Moedas usadas: ");
        for (int i = 0; i < result; i++)
        {
            printf("%d ", used_coins[i]);
        }
        printf("\n");
    }
    return 0;
}
