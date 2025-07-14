#include <stdio.h>
#include <stdlib.h>

/**
 * floyd_cycle: O Algoritmo é um algoritmo de detecção de ciclo em um grafo.
 * Encontra um ciclo no grafo usando o algoritmo de Floyd-Warshall.
 *
 * COMPLEXIDADE:
 * TEMPO: O(n^3), onde n é o número de vertices no grafo.
 *
 * ESPAÇO: O(1), pois utiliza apenas variáveis locais.
 */

/* Struct para armazenar a função f(x), representada por um vetor */
typedef struct
{
    int *func; // vetor com os valores de f(x)
    int size;  // tamanho da função (número de elementos)
} Funcao;

/* Struct para armazenar os resultados do algoritmo de Floyd */
typedef struct
{
    int lam; // comprimento do ciclo (λ)
    int mu;  // início do ciclo (μ)
} Ciclo;

/**
 * @brief Calcula o valor da função para um determinado índice x.
 *
 * A função f é definida por meio da estrutura Funcao, que armazena uma sequência de valores.
 * O valor de f(x) é o valor armazenado no índice x da sequência.
 *
 * @param fdata Ponteiro para a estrutura Funcao contendo os dados da sequência.
 * @param x Índice para o qual o valor da função será calculado.
 * @return O valor da função para o índice x.
 */
int f(Funcao *fdata, int x)
{
    return fdata->func[x];
}

/**
 * @brief Imprime os primeiros n elementos da sequência a partir de um valor inicial.
 *
 * A função percorre a sequência, aplicando a função f iterativamente, e imprime os primeiros
 * n elementos da sequência gerada.
 *
 * @param fdata Ponteiro para a estrutura Funcao contendo os dados da sequência.
 * @param x0 Valor inicial da sequência.
 */
void printSequence(Funcao *fdata, int x0)
{
    int tempx = x0;
    printf("\nPrimeiros %d elementos da sequência:\n%d", fdata->size, tempx);
    for (int i = 0; i < fdata->size; i++)
    {
        tempx = f(fdata, tempx);
        printf(" %d", tempx);
    }
    printf("\n");
}

/**
 * @brief Algoritmo de Floyd para detecção de ciclos em uma sequência.
 *
 * O algoritmo de Floyd, também conhecido como "tartaruga e lebre", é utilizado
 * para detectar ciclos em sequências que podem ser representadas por funções iterativas.
 * O ciclo é detectado através de duas fases principais:
 *
 * - Fase 1: encontra o ponto de encontro entre a tartaruga e a lebre.
 * - Fase 2: encontra o início do ciclo.
 * - Fase 3: determina o tamanho do ciclo.
 *
 * @param fdata Ponteiro para a estrutura Funcao contendo os dados da sequência.
 * @param x0 Valor inicial da sequência.
 * @return Retorna uma estrutura Ciclo contendo o tamanho e a posição do ciclo.
 */
Ciclo findCycle(Funcao *fdata, int x0)
{
    // Inicializa tartaruga e lebre
    int tortoise = f(fdata, x0);       // 1 passo
    int hare = f(fdata, f(fdata, x0)); // 2 passos

    // Fase 1: encontrar encontro entre tartaruga e lebre
    while (tortoise != hare)
    {
        tortoise = f(fdata, tortoise);
        hare = f(fdata, f(fdata, hare));
    }

    // Fase 2: encontrar início do ciclo (mu)
    int mu = 0;
    tortoise = x0;
    while (tortoise != hare)
    {
        tortoise = f(fdata, tortoise);
        hare = f(fdata, hare);
        mu++;
    }

    // Fase 3: determinar o tamanho do ciclo (lam)
    int lam = 1;
    hare = f(fdata, tortoise);
    while (tortoise != hare)
    {
        hare = f(fdata, hare);
        lam++;
    }

    // Retorna o resultado em uma struct
    Ciclo ciclo = {lam, mu};
    return ciclo;
}

/**
 * @brief Exibe os resultados da detecção de ciclo.
 *
 * A função imprime o tamanho do ciclo e a posição do ciclo na sequência.
 *
 * @param ciclo Estrutura Ciclo contendo as informações do ciclo detectado.
 */
void displayResults(Ciclo ciclo)
{
    printf("\nTamanho do ciclo: %d\n", ciclo.lam);
    printf("Posição: %d\n", ciclo.mu + 1); // posição começa de 1
}

int main(int argc, char **argv)
{
    int size = 0, x0 = 0;
    Funcao fdata; // struct para armazenar a função f(x)

    printf("Teste do Algoritmo de Floyd\n\n");

    // Entrada do tamanho da lista
    printf("Digite o tamanho da lista: ");
    scanf("%d", &size);

    // Aloca memória para o vetor func[]
    fdata.size = size;
    fdata.func = (int *)malloc(size * sizeof(int));

    // Entrada dos valores de f(x)
    printf("\nDigite os elementos de f(x):\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &fdata.func[i]);
    }

    // Entrada do valor inicial x0
    printf("\nDigite x0: ");
    scanf("%d", &x0);

    // Imprime a sequência a partir de x0
    printSequence(&fdata, x0);

    // Encontra e exibe o ciclo
    Ciclo ciclo = findCycle(&fdata, x0);
    displayResults(ciclo);

    // Libera memória
    free(fdata.func);
    return 0;
}
