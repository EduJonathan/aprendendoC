
#include <stdio.h>
#include <stdlib.h>

/*
 * A recursão é uma ferramenta poderosa em estruturas de dados mais complexas,
 * como árvores e grafos, onde a definição recursiva é natural. Porém, quando
 * não utilizada corretamente, pode levar a problemas como estouro de pilha
 * (stack overflow) ou desempenho ruim.
 */

/**
 * @brief Conta recursivamente as ocorrências de um elemento em um array
 *
 * Percorre o array recursivamente, comparando cada elemento com a chave
 * procurada e contabilizando as ocorrências.
 *
 * @param arr Ponteiro para o array de inteiros
 * @param n Tamanho do array
 * @param chave Valor a ser contabilizado
 * @param indice Índice atual (começar com 0)
 *
 * @return Número de ocorrências da chave no array
 * @warning Cuidado com arrays muito grandes - pode causar stack overflow
 */
int ocorrencia_de_dados(int *arr, int n, int chave, int indice)
{
    // Caso base: atingiu o final do array
    if (indice == n)
        return 0;

    // Caso recursivo: suma 1 se achou a chave, mais as ocorrências no resto do array
    return (arr[indice] == chave ? 1 : 0) + ocorrencia_de_dados(arr, n, chave, indice + 1);
}


/**
 * @brief Busca recursiva linear de um elemento no array
 *
 * Percorre o array até encontrar a chave ou chegar ao final.
 *
 * @param arr Ponteiro para o array de inteiros
 * @param n Tamanho do array
 * @param chave Elemento a buscar
 * @param indice Índice atual (começar com 0)
 *
 * @return Índice do elemento se encontrado, -1 caso contrário
 */
int busca_recursiva(int *arr, int n, int chave, int indice)
{
    // Caso base: elemento encontrado
    if (indice == n)
        return -1;

    if (arr[indice] == chave)
        return indice;

    // Caso recursivo: continua procurando
    return busca_recursiva(arr, n, chave, indice + 1);
}

/**
 * @brief Calcula potência com divisão e conquista (mais eficiente)
 *
 * Usa estratégia divide-and-conquer:
 * a^n = (a^(n/2))^2         se n é par
 * a^n = a * a^(n-1)         se n é ímpar
 *
 * @param base Base da potência
 * @param expoente Expoente (>= 0)
 *
 * @return base elevado à potência expoente!
 */
long long potencia_otimizada(int base, int expoente)
{
    // Caso base
    if (expoente == 0)
        return 1;

    // Se expoente é par
    if (expoente % 2 == 0)
    {
        long long meio = potencia_otimizada(base, expoente / 2);
        return meio * meio;
    }

    // Se expoente é ímpar
    return base * potencia_otimizada(base, expoente - 1);
}

/**
 * @brief Inverte um array recursivamente
 *
 * Troca elementos de forma simétrica usando dois índices que se aproximam.
 *
 * @param arr Ponteiro para o array de inteiros
 * @param inicio Índice do início (começar com 0)
 * @param fim Índice do final (começar com n-1)
 */
void inverter_array(int *arr, int inicio, int fim)
{
    // Caso base: se cruzaram os índices, termina
    if (inicio >= fim)
        return;

    // Troca elementos
    int temp = arr[inicio];
    arr[inicio] = arr[fim];
    arr[fim] = temp;

    // Caso recursivo
    inverter_array(arr, inicio + 1, fim - 1);
}

/**
 * @brief Função auxiliar para exibir um array
 *
 * @param arr Ponteiro para o array
 * @param n Tamanho do array
 */
void exibir_array(int *arr, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

int main(int argc, char **argv)
{
    printf("=== EXEMPLOS DE RECURSÃO ===\n\n");

    // Array de teste
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    size_t n  = sizeof(arr) / sizeof(arr[0]);

    // 1. Ocorrências
    printf("1. Ocorrência de Dados:\n");
    printf("   Array: ");
    exibir_array(arr, n);
    printf("   Ocorrências de 2: %d\n\n", ocorrencia_de_dados(arr, n, 2, 0));

    // 4. Busca
    printf("2. Busca Recursiva:\n");
    int pos = busca_recursiva(arr, n, 4, 0);
    printf("   Elemento 4 encontrado no índice: %d\n\n", pos);

    // Potência
    printf("   2^10 (otimizada) = %lld\n\n", potencia_otimizada(2, 10));

    //Inverter array
    printf("3. Inverter Array:\n");
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = 5;

    printf("   Antes: ");
    exibir_array(arr2, n2);
    inverter_array(arr2, 0, n2 - 1);
    printf("   Depois: ");
    
    exibir_array(arr2, n2);

    return 0;
}
