#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ELEMENTOS 10

/**
 * @struct Conjunto
 * @brief Estrutura que representa um conjunto de inteiros.
 *
 * Armazena elementos únicos em um array dinâmico, com complexidade O(n) para inserção e busca
 * devido à verificação de duplicatas. O tamanho máximo é definido na criação.
 */
typedef struct Conjunto
{
    int *elementos;    /**< Array dinâmico de elementos */
    size_t tamanho;    /**< Número de elementos atuais */
    size_t capacidade; /**< Capacidade máxima do conjunto */
} Conjunto;

/**
 * @brief Cria um conjunto com a capacidade especificada.
 *
 * @param capacidade Tamanho máximo do conjunto (deve ser maior que 0).
 * @return Ponteiro para o conjunto criado ou NULL em caso de falha.
 */
Conjunto *criarConjunto(size_t capacidade)
{
    if (capacidade == 0)
    {
        fprintf(stderr, "Erro: Capacidade deve ser maior que 0\n");
        return NULL;
    }

    Conjunto *s = (Conjunto *)malloc(sizeof(Conjunto));
    if (s == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o conjunto\n");
        return NULL;
    }

    s->elementos = (int *)calloc(capacidade, sizeof(int));
    if (s->elementos == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para os elementos\n");
        free(s);
        return NULL;
    }

    s->tamanho = 0;
    s->capacidade = capacidade;
    return s;
}

/**
 * @brief Inicializa o conjunto, configurando o tamanho para 0.
 *
 * @param s Ponteiro para o conjunto.
 */
void inicializarConjunto(Conjunto *s)
{
    if (s == NULL)
    {
        fprintf(stderr, "Erro: Conjunto nulo\n");
        return;
    }
    s->tamanho = 0;
}

/**
 * @brief Adiciona um elemento ao conjunto.
 *
 * @param s Conjunto.
 * @param elemento Elemento a ser adicionado.
 * @return true se adicionado, false se já existe ou o conjunto está cheio.
 */
bool adicionarElemento(Conjunto *s, int elemento)
{
    if (s == NULL)
    {
        fprintf(stderr, "Erro: Conjunto nulo\n");
        return false;
    }

    for (size_t i = 0; i < s->tamanho; i++)
    {
        if (s->elementos[i] == elemento)
        {
            return false; // Elemento já existe
        }
    }

    if (s->tamanho >= s->capacidade)
    {
        fprintf(stderr, "Erro: Conjunto cheio\n");
        return false;
    }

    s->elementos[s->tamanho] = elemento;
    s->tamanho++;
    return true;
}

/**
 * @brief Verifica se um elemento está no conjunto.
 *
 * @param s Conjunto.
 * @param elemento Elemento a ser buscado.
 * @return true se o elemento está presente, false caso contrário.
 */
bool contemElemento(Conjunto *s, int elemento)
{
    if (s == NULL)
    {
        return false;
    }

    for (size_t i = 0; i < s->tamanho; i++)
    {
        if (s->elementos[i] == elemento)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Imprime os elementos do conjunto.
 *
 * @param s Conjunto.
 */
void imprimirConjunto(Conjunto *s)
{
    if (s == NULL || s->tamanho == 0)
    {
        printf("{}\n");
        return;
    }

    printf("{");
    for (size_t i = 0; i < s->tamanho; i++)
    {
        printf("%d", s->elementos[i]);
        if (i < s->tamanho - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

/**
 * @brief Libera a memória alocada para o conjunto.
 *
 * @param s Conjunto.
 */
void liberarConjunto(Conjunto *s)
{
    if (s == NULL)
    {
        return;
    }

    free(s->elementos);
    free(s);
}

int main(int argc, char **argv)
{
    Conjunto *s = criarConjunto(MAX_ELEMENTOS);
    if (s == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação do conjunto\n");
        return EXIT_FAILURE;
    }

    inicializarConjunto(s);

    adicionarElemento(s, 1);
    adicionarElemento(s, 2);
    adicionarElemento(s, 3);

    imprimirConjunto(s);

    printf("Contém 1? %s\n", contemElemento(s, 1) ? "Sim" : "Não");
    printf("Contém 10? %s\n", contemElemento(s, 10) ? "Sim" : "Não");
    printf("Contém 3? %s\n", contemElemento(s, 3) ? "Sim" : "Não");

    liberarConjunto(s);
    return 0;
}