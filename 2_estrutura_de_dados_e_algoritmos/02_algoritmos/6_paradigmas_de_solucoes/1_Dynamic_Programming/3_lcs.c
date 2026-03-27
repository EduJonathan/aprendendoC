#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função auxiliar para retornar o máximo entre dois inteiros
int maximo(int a, int b)
{
    return (a > b) ? a : b;
}

/**
 * Subsequência Comum Máxima (LCS)
 * A Programação Dinâmica também é útil na solução do problema da
 * Subsequência Comum Máxima (LCS), que busca a maior subsequência que aparece em duas
 * sequências dadas, sem precisar que seus elementos estejam contíguos.
 *
 * Recorrência:
 * Se as letras de ambas as sequências são iguais, a solução para os subproblemas é:
 *
 * 𝑑𝑝[𝑖][𝑗] = 𝑑𝑝[𝑖 − 1][𝑗 − 1] + 1
 *
 * Caso contrário, a solução será o máximo entre as duas possibilidades:
 *
 * 𝑑𝑝[𝑖][𝑗] = max⁡(𝑑𝑝[𝑖 − 1][𝑗], 𝑑𝑝[𝑖][𝑗 − 1])
 *
 * @param str1 Primeira string.
 * @param str2 Segunda string.
 * @return Tamanho da LCS.
 */
int lcs_length(const char *str1, const char *str2)
{
    if (str1 == NULL || str2 == NULL)
        return 0;

    size_t m = strlen(str1);
    size_t n = strlen(str2);

    // Alocando a tabela de resultados e de rastreamento
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (size_t i = 0ull; i <= m; i++)
    {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        dp[i][0] = 0;
    }

    // Preenche a tabela com valores iniciais
    for (size_t j = 0ull; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    // Preenchimento da tabela de PD
    for (size_t i = 1ull; i <= m; i++)
    {
        for (size_t j = 1ull; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = maximo(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int result = dp[m][n];

    for (size_t i = 0ull; i <= m; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return result;
}

/**
 * @brief Recupera a LCS e armazena em `output`.
 *
 * @param str1 Primeira string.
 * @param str2 Segunda string.
 * @param output Buffer para armazenar a LCS (deve ter tamanho suficiente).
 */
void lcs_sequence(const char *str1, const char *str2, char *output)
{
    if (str1 == NULL || str2 == NULL || output == NULL)
        return;

    size_t m = strlen(str1);
    size_t n = strlen(str2);

    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (size_t i = 0ull; i <= m; i++)
    {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        dp[i][0] = 0;
    }
    
    for (size_t j = 0ull; j <= n; j++)
    {
        dp[0][j] = 0;
    }

    for (size_t i = 1ull; i <= m; i++)
    {
        for (size_t j = 1ull; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = maximo(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstrução da LCS, Recuperando a subsequência comum máxima
    size_t i = m, j = n;
    int index = dp[m][n] - 1;
    output[index + 1] = '\0'; // Terminador nulo

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            output[index--] = str1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    // Liberando a memória
    for (size_t i = 0ull; i <= m; i++)
    {
        free(dp[i]);
    }
    free(dp);
}

int main(int argc, char **argv)
{
    const char *X = "AGGTAB";
    const char *Y = "GXTXAYB";

    // Calcula o tamanho da LCS
    int length = lcs_length(X, Y);
    printf("Tamanho da LCS: %d\n", length);

    // Recupera a LCS (usando malloc para tamanho dinâmico)
    char *lcs = malloc((length + 1) * sizeof(char));
    if (lcs != NULL)
    {
        lcs_sequence(X, Y, lcs);
        printf("Subsequência comum máxima: %s\n", lcs);
        free(lcs); // Libera a memória alocada
    }
    else
    {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }

    return 0;
}
