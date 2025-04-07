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

/* f(x) = func[x] */
int f(Funcao *fdata, int x)
{
    return fdata->func[x];
}

/* Imprime os primeiros n elementos da sequência a partir de x0 */
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
 * @brief Algoritmo de Floyd para detecção de ciclos
 * @return Retorna um struct Ciclo com:
 * - lam (comprimento do ciclo)
 * - mu (posição inicial do ciclo)
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

/* Exibe os resultados: tamanho e posição do ciclo */
void displayResults(Ciclo ciclo)
{
    printf("\nTamanho do ciclo: %d\n", ciclo.lam);
    printf("Posição: %d\n", ciclo.mu + 1); // posição começa de 1
}

/* Função principal: entrada e controle geral */
int main(int argc, char **argv)
{
    int size, x0;
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
