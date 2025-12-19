#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define TAMANHO_MAXIMO 100 /**< Tamanho máximo do conjunto */
#define TAMANHO_STRING 100 /**< Tamanho máximo de cada string */

/**
 * @struct Conjunto
 * @brief Estrutura que representa um conjunto de strings.
 *
 * Armazena strings únicas em um array dinâmico, com complexidade O(n) para inserção e busca
 * devido à verificação de duplicatas. O tamanho máximo é definido na criação.
 */
typedef struct set
{
    char **dados;      /**< Array dinâmico de strings */
    size_t tamanho;    /**< Número de elementos atuais */
    size_t capacidade; /**< Capacidade máxima do conjunto */
} Conjunto;

/**
 * @brief Cria um conjunto com a capacidade especificada.
 *
 * @param capacidade Tamanho máximo do conjunto.
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

    s->dados = (char **)calloc(capacidade, sizeof(char *));
    if (s->dados == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para os dados\n");
        free(s);
        return NULL;
    }

    for (size_t i = 0; i < capacidade; i++)
    {
        s->dados[i] = NULL;
    }
    s->tamanho = 0;
    s->capacidade = capacidade;
    return s;
}

/**
 * @brief Inicializa o conjunto, configurando o tamanho para 0.
 *
 * @param s Conjunto.
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
 * @brief Verifica se um elemento está no conjunto.
 *
 * @param s Conjunto.
 * @param valor String a ser buscada.
 * @return true se presente, false caso contrário.
 */
bool contemElemento(Conjunto *s, const char *valor)
{
    if (s == NULL || valor == NULL || *valor == '\0')
    {
        return false;
    }

    for (size_t i = 0; i < s->tamanho; i++)
    {
        if (s->dados[i] && strcmp(s->dados[i], valor) == 0)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Adiciona um elemento ao conjunto.
 *
 * @param s Conjunto.
 * @param valor String a ser adicionada.
 * @return true se adicionada, false se já existe, está cheio ou é inválida.
 */
bool adicionarElemento(Conjunto *s, const char *valor)
{
    if (s == NULL || valor == NULL || *valor == '\0' || strlen(valor) >= TAMANHO_STRING)
    {
        fprintf(stderr, "Erro: Conjunto nulo, valor inválido ou muito longo\n");
        return false;
    }

    if (contemElemento(s, valor))
    {
        return false;
    }

    if (s->tamanho >= s->capacidade)
    {
        fprintf(stderr, "Erro: Conjunto cheio\n");
        return false;
    }

    s->dados[s->tamanho] = (char *)malloc(TAMANHO_STRING * sizeof(char));
    if (s->dados[s->tamanho] == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para a string\n");
        return false;
    }
    strncpy(s->dados[s->tamanho], valor, TAMANHO_STRING - 1);
    s->dados[s->tamanho][TAMANHO_STRING - 1] = '\0';
    s->tamanho++;
    return true;
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
        printf("%s", s->dados[i]);
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

    for (size_t i = 0; i < s->tamanho; i++)
    {
        free(s->dados[i]);
        s->dados[i] = NULL;
    }
    free(s->dados);
    free(s);
}

int main(int argc, char **argv)
{
    Conjunto *setx = criarConjunto(TAMANHO_MAXIMO);
    Conjunto *sety = criarConjunto(TAMANHO_MAXIMO);
    Conjunto *setz = criarConjunto(TAMANHO_MAXIMO);
    if (setx == NULL || sety == NULL || setz == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação do(s) conjunto(s)\n");
        liberarConjunto(setx);
        liberarConjunto(sety);
        liberarConjunto(setz);
        return EXIT_FAILURE;
    }

    inicializarConjunto(setx);
    inicializarConjunto(sety);
    inicializarConjunto(setz);

    adicionarElemento(setx, "Verde");
    adicionarElemento(setx, "Azul");
    adicionarElemento(sety, "Azul");
    adicionarElemento(sety, "Amarelo");

    for (size_t i = 0; i < setx->tamanho; i++)
    {
        adicionarElemento(setz, setx->dados[i]);
    }

    for (size_t i = 0; i < sety->tamanho; i++)
    {
        adicionarElemento(setz, sety->dados[i]);
    }

    printf("Conjunto X: ");
    imprimirConjunto(setx);

    printf("Conjunto Y: ");
    imprimirConjunto(sety);

    printf("União (Z): ");
    imprimirConjunto(setz);

    liberarConjunto(setx);
    liberarConjunto(sety);
    liberarConjunto(setz);
    return 0;
}
