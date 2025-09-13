#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX 100

int contador_puro = 0;
int contador_memo = 0;
int cache[MAX][MAX] = {0};

/**
 * @brief Inicializa a matriz de cache com -1.
 *
 * Essa função é utilizada antes da execução do algoritmo com memoização para indicar
 * que nenhuma célula da matriz de cache foi calculada ainda.
 */
void inicializar_cache()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cache[i][j] = -1;
}

/**
 * @brief Calcula o número de caminhos únicos de (0,0) até (i,j) usando recursão pura.
 *
 * Esse método é ineficiente para valores grandes de i e j, pois recalcula muitas
 * subestruturas repetidamente.
 *
 * @param i Linha destino da grade (começando de 0).
 * @param j Coluna destino da grade (começando de 0).
 * @return O número total de caminhos possíveis até a posição (i,j).
 */
int caminhos_puros(int i, int j)
{
    contador_puro++;
    if (i == 0 || j == 0)
        return 1;

    return caminhos_puros(i - 1, j) + caminhos_puros(i, j - 1);
}

/**
 * @brief Calcula o número de caminhos únicos em uma grade de (i+1) x (j+1) posições usando memoização.
 *
 * Memoização (ou memoization): Memoização é uma técnica de otimização que armazena resultados
 * de chamadas anteriores para evitar recálculos e melhorar o desempenho da recursão.
 * É como um "cache" para funções. Porém nem sempre tem resultado, como em fatorial recursivo.
 *
 * @param i A linha destino da grade (começando de 0).
 * @param j A coluna destino da grade (começando de 0).
 * @return O número total de caminhos possíveis de (0,0) até (i,j).
 */
int caminhos_memo(int i, int j)
{
    contador_memo++;
    if (i == 0 || j == 0)
        return 1;

    if (cache[i][j] != -1)
        return cache[i][j];

    cache[i][j] = caminhos_memo(i - 1, j) + caminhos_memo(i, j - 1);
    return cache[i][j];
}

/**
 * @brief Calcula o número de caminhos únicos usando programação dinâmica iterativa.
 *
 * Utiliza uma matriz auxiliar para armazenar os resultados parciais e construir
 * a solução de forma bottom-up.
 *
 * @param m Número de linhas da grade.
 * @param n Número de colunas da grade.
 * @return O número total de caminhos possíveis de (0,0) até (m-1,n-1).
 */
int caminhos_iterativo(int m, int n)
{
    int dp[MAX][MAX] = {0};

    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

/**
 * @brief Mede o tempo de execução de uma função de contagem de caminhos e exibe informações.
 *
 * Esta função também imprime a quantidade de chamadas recursivas (quando aplicável).
 *
 * @param nome Nome do método utilizado (para exibição).
 * @param func Ponteiro para a função que calcula os caminhos.
 * @param m Número de linhas da grade.
 * @param n Número de colunas da grade.
 */
void medir_tempo(const char *nome, int (*func)(int, int), int m, int n)
{
    clock_t inicio = clock();
    int resultado = func(m, n);

    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) * 1000 / CLOCKS_PER_SEC;

    printf("\nMétodo: %s\n", nome);
    printf("Caminhos de (0,0) até (%d,%d): %d\n", m - 1, n - 1, resultado);
    printf("Tempo: %.3lf ms\n", tempo);

    if (strcmp(nome, "Recursivo Puro") == 0)
        printf("Chamadas recursivas: %d\n", contador_puro);
    else if (strcmp(nome, "Memoização") == 0)
        printf("Chamadas recursivas: %d\n", contador_memo);
    else
        printf("Iterativo: 0 chamadas recursivas\n");
}

/**
 * @brief Função de apoio para adaptar a função iterativa ao formato esperado pelo medidor.
 *
 * @param m Número de linhas.
 * @param n Número de colunas.
 * @return O número de caminhos possíveis até (m-1, n-1).
 */
int wrapper_iterativo(int m, int n)
{
    return caminhos_iterativo(m, n);
}

int main(int argc, char **argv)
{
    int m = 15, n = 15;

    // Mede o tempo e mostra informações da abordagem recursiva pura (sem otimização)
    contador_puro = 0;
    medir_tempo("Recursivo Puro", caminhos_puros, m - 1, n - 1);

    // Mede o tempo e mostra informações da abordagem recursiva com memoização
    contador_memo = 0;
    inicializar_cache(); // Inicializa o cache com -1 para indicar que ainda não há valores calculados
    medir_tempo("Memoização", caminhos_memo, m - 1, n - 1);

    // Mede o tempo e mostra informações da abordagem iterativa (mais eficiente)
    medir_tempo("Iterativo", wrapper_iterativo, m, n);
    return 0;
}
