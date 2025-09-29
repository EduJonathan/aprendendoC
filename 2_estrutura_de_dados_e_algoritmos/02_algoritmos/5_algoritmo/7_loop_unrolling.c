#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

/**
 * Loops Unrolling: É uma técnica de otimização que reduz iterações de um loop, executando múltiplas
 * iterações em uma única repetição, diminuindo o overhead de controle e melhorando a eficiência
 * da CPU em operações independentes.
 *
 * @note Trade-offs: Aumenta o tamanho do código (pior cache de instruções) e pode não valer
 * para loops pequenos ou com dependências de dados.
 *
 * @note Para melhor performance, compile com:
 *   - gcc -O2 -funroll-loops 7_loop_unrolling.c -o programa
 *   - Ou mais agressivo: gcc -O3 -funroll-all-loops 7_loop_unrolling.c -o programa
 *   - Para arquitetura nativa: gcc -O2 -march=native -funroll-loops 7_loop_unrolling.c -o programa
 */

#define N 5           /**< Dimensão da matriz quadrada. */
#define SIZE 1000000  /**< Tamanho padrão do vetor para benchmarks iniciais. */
#define TAM 100000000 /**< Tamanho grande para teste de performance (100 milhões). */

/**
 * @brief Dobra cada elemento do vetor usando loop unrolling (fator 4).
 *
 * @param[in,out] arr Ponteiro para o vetor de inteiros (será modificado).
 * @param[in] n   Número de elementos do vetor.
 */
void processa_array(int *arr, size_t n)
{
    if (n == 0)
        return;
    size_t i = 0;

    for (; i + 3 < n; i += 4)
    {
        arr[i] *= 2;
        arr[i + 1] *= 2;
        arr[i + 2] *= 2;
        arr[i + 3] *= 2;
    }

    for (; i < n; i++)
    {
        arr[i] *= 2;
    }
}

/**
 * @brief Soma todos os elementos de um vetor (versão simples).
 *
 * @param[in] array Ponteiro para o vetor de inteiros (não é modificado).
 * @param[in] size  Número de elementos.
 * @return Soma total dos elementos (tipo unsigned long long).
 */
unsigned long long soma_normal(const int *array, size_t size)
{
    unsigned long long total = 0;
    for (size_t i = 0; i < size; i++)
    {
        total += (unsigned)array[i]; /* Cast para evitar negativos */
    }
    return total;
}

/**
 * @brief Soma com unrolling manual (fator 4).
 *
 * @param[in] array Ponteiro para o vetor de inteiros (não é modificado).
 * @param[in] size  Número de elementos.
 * @return Soma total dos elementos (tipo unsigned long long).
 */
unsigned long long soma_unrolling_manual_4(const int *array, size_t size)
{
    unsigned long long total = 0;
    size_t i = 0;

    for (; i + 3 < size; i += 4)
    {
        total += (unsigned)array[i] + (unsigned)array[i + 1] +
                 (unsigned)array[i + 2] + (unsigned)array[i + 3];
    }

    for (; i < size; i++)
    {
        total += (unsigned)array[i];
    }
    return total;
}

/**
 * @brief Soma com unrolling manual (fator 8), usando acumuladores locais.
 *
 * @param[in] array Ponteiro para o vetor de inteiros (não é modificado).
 * @param[in] size  Número de elementos.
 * @return Soma total dos elementos (tipo unsigned long long).
 */
unsigned long long soma_unrolling_manual_8(const int *array, size_t size)
{
    unsigned long long total = 0;
    size_t i = 0;

    for (; i + 7 < size; i += 8)
    {
        unsigned long long sum1 = (unsigned)array[i] + (unsigned)array[i + 1] +
                                  (unsigned)array[i + 2] + (unsigned)array[i + 3];
        unsigned long long sum2 = (unsigned)array[i + 4] + (unsigned)array[i + 5] +
                                  (unsigned)array[i + 6] + (unsigned)array[i + 7];
        total += sum1 + sum2;
    }

    for (; i < size; i++)
    {
        total += (unsigned)array[i];
    }
    return total;
}

/**
 * @brief Soma com unrolling via pragma do compilador (fator 4).
 *
 * @param[in] array Ponteiro para o vetor de inteiros (não é modificado).
 * @param[in] size  Número de elementos.
 * @return Soma total dos elementos (tipo unsigned long long).
 * @note Requer compilador que suporte #pragma unroll (ex.: GCC/Clang).
 */
unsigned long long soma_unrolling_pragma(const int *array, size_t size)
{
    unsigned long long total = 0;
#pragma unroll(4)
    for (size_t i = 0; i < size; i++)
    {
        total += (unsigned)array[i];
    }
    return total;
}

/**
 * @brief Multiplica duas matrizes NxN usando unrolling em blocos de 4 colunas.
 *
 * @param[in]  A Matriz A (entrada).
 * @param[in]  B Matriz B (entrada).
 * @param[out] C Matriz resultado (A x B), deve ser fornecida pelo chamador.
 */
void multiplica_matrizes(const int A[][N], const int B[][N], int C[][N])
{
    if (!A || !B || !C)
    {
        fprintf(stderr, "Matriz nula detectada.\n");
        return;
    }

    for (int i = 0; i < N; i++)
    {
        int j = 0;

        for (; j + 3 < N; j += 4)
        {
            int sum0 = 0, sum1 = 0, sum2 = 0, sum3 = 0;
            for (int k = 0; k < N; k++)
            {
                sum0 += A[i][k] * B[k][j];
                sum1 += A[i][k] * B[k][j + 1];
                sum2 += A[i][k] * B[k][j + 2];
                sum3 += A[i][k] * B[k][j + 3];
            }

            C[i][j] = sum0;
            C[i][j + 1] = sum1;
            C[i][j + 2] = sum2;
            C[i][j + 3] = sum3;
        }

        for (; j < N; j++)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL)); /* Para inicialização randômica opcional */

    /* --- Alocação para benchmark pequeno --- */
    int *array = malloc(SIZE * sizeof(int));
    if (!array)
    {
        fprintf(stderr, "Falha de alocação para array.\n");
        return 1;
    }

    for (size_t i = 0; i < SIZE; i++)
    {
        array[i] = (int)i;
    }

    int runs = 10; /* Aumentado para mais precisão */
    double t1 = 0.0, t2 = 0.0, t3 = 0.0, t4 = 0.0;
    unsigned long long s1 = 0, s2 = 0, s3 = 0, s4 = 0;

    /* Warm-up: Executa uma vez para aquecer cache */
    soma_normal(array, SIZE);
    soma_unrolling_manual_4(array, SIZE);
    soma_unrolling_manual_8(array, SIZE);
    soma_unrolling_pragma(array, SIZE);

    for (int r = 0; r < runs; r++)
    {
        clock_t start = clock();
        s1 = soma_normal(array, SIZE);
        t1 += (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        s2 = soma_unrolling_manual_4(array, SIZE);
        t2 += (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        s3 = soma_unrolling_manual_8(array, SIZE);
        t3 += (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        s4 = soma_unrolling_pragma(array, SIZE);
        t4 += (double)(clock() - start) / CLOCKS_PER_SEC;
    }

    /* Verificação de corretude */
    assert(s1 == s2 && s1 == s3 && s1 == s4);

    printf("Soma normal    : %llu (%.6fs)\n", s1, t1 / runs);
    printf("Soma unroll4   : %llu (%.6fs)\n", s2, t2 / runs);
    printf("Soma unroll8   : %llu (%.6fs)\n", s3, t3 / runs);
    printf("Soma pragma    : %llu (%.6fs)\n", s4, t4 / runs);
    printf("Speedup (Norm/Unroll4): %.2fx\n", t1 / t2);
    printf("Speedup (Norm/Unroll8): %.2fx\n", t1 / t3);
    printf("Speedup (Norm/Pragma) : %.2fx\n\n", t1 / t4);
    free(array);

    printf("----------------------------------------\n");

    /* --- Multiplicação de matrizes com benchmark --- */
    int A[N][N] = {{1, 2, 3, 4, 5},
                   {6, 7, 8, 9, 10},
                   {11, 12, 13, 14, 15},
                   {16, 17, 18, 19, 20},
                   {21, 22, 23, 24, 25}};

    int B[N][N] = {{25, 24, 23, 22, 21},
                   {20, 19, 18, 17, 16},
                   {15, 14, 13, 12, 11},
                   {10, 9, 8, 7, 6},
                   {5, 4, 3, 2, 1}};

    int C[N][N] = {0};

    /* Warm-up */
    multiplica_matrizes(A, B, C);

    double tm = 0.0;
    for (int r = 0; r < runs; r++)
    {
        clock_t start = clock();
        multiplica_matrizes(A, B, C);
        tm += (double)(clock() - start) / CLOCKS_PER_SEC;
    }
    printf("Tempo multiplicação matrizes: %.6fs\n\n", tm / runs);

    puts("Resultado C = A x B:");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%5d", C[i][j]);
        }
        putchar('\n');
    }

    printf("\n----------------------------------------\n");

    /* --- Processamento simples --- */
    int dados[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    processa_array(dados, 10);

    puts("\nVetor dobrado:");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", dados[i]);
    }
    puts("");

    printf("\n----------------------------------------\n");

    /* --- Grande benchmark (TAM) com alinhamento --- */
    int *big = malloc(TAM * sizeof(int));
    if (!big)
    {
        fprintf(stderr, "Falha de alocação para big.\n");
        return 1;
    }
    
    for (size_t i = 0; i < TAM; i++)
    {
        big[i] = (int)(i % 100);
    }

    double tb1 = 0, tb2 = 0, tb3 = 0, tb4 = 0;
    unsigned long long sb1 = 0, sb2 = 0, sb3 = 0, sb4 = 0;

    /* Warm-up */
    soma_normal(big, TAM);
    soma_unrolling_manual_4(big, TAM);
    soma_unrolling_manual_8(big, TAM);
    soma_unrolling_pragma(big, TAM);

    for (int r = 0; r < runs; r++)
    {
        clock_t start = clock();
        sb1 = soma_normal(big, TAM);
        tb1 += (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        sb2 = soma_unrolling_manual_4(big, TAM);
        tb2 += (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        sb3 = soma_unrolling_manual_8(big, TAM);
        tb3 += (double)(clock() - start) / CLOCKS_PER_SEC;

        start = clock();
        sb4 = soma_unrolling_pragma(big, TAM);
        tb4 += (double)(clock() - start) / CLOCKS_PER_SEC;
    }

    /* Verificação de corretude */
    assert(sb1 == sb2 && sb1 == sb3 && sb1 == sb4);

    printf("\nGrande benchmark (%zu elementos):\n", TAM);
    printf("Normal    : %llu (%.4fs)\n", sb1, tb1 / runs);
    printf("Unroll4   : %llu (%.4fs)\n", sb2, tb2 / runs);
    printf("Unroll8   : %llu (%.4fs)\n", sb3, tb3 / runs);
    printf("Pragma    : %llu (%.4fs)\n", sb4, tb4 / runs);
    printf("Speedup (Normal/Unroll4): %.2fx\n", tb1 / tb2);
    printf("Speedup (Normal/Unroll8): %.2fx\n", tb1 / tb3);
    printf("Speedup (Normal/Pragma) : %.2fx\n", tb1 / tb4);
    free(big);
    
    return 0;
}
