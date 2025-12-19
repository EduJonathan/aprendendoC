#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAVE_VALOR 100 /**< Tamanho máximo para chave e valor */

/**
 * @struct ParChaveValor
 * @brief Estrutura para armazenar um par chave-valor.
 *
 * Contém uma chave e um valor, ambos como strings com tamanho máximo definido.
 */
typedef struct Chave_valor
{
    char chave[MAX_CHAVE_VALOR]; /**< Chave associada ao valor */
    char valor[MAX_CHAVE_VALOR]; /**< Valor associado à chave */
} ParChaveValor;

/**
 * @struct Dicionario
 * @brief Estrutura que representa um dicionário de pares chave-valor.
 *
 * Usa um array dinâmico para armazenar pares, com busca linear (O(n)).
 * A capacidade define o número máximo de pares, e tamanho indica os pares atuais.
 */
typedef struct Dicionario
{
    ParChaveValor **pares; /**< Array de ponteiros para pares chave-valor */
    size_t tamanho;        /**< Número atual de pares */
    size_t capacidade;     /**< Capacidade máxima do dicionário */
} Dicionario;

/**
 * @brief Cria um dicionário com a capacidade especificada.
 *
 * Aloca memória para o dicionário e inicializa o array de pares como NULL.
 *
 * @param capacidade Capacidade máxima do dicionário (deve ser maior que 0).
 * @return Ponteiro para o dicionário criado ou NULL em caso de falha.
 */
Dicionario *criarDicionario(size_t capacidade)
{
    if (capacidade == 0)
    {
        fprintf(stderr, "Erro: Capacidade deve ser maior que 0\n");
        return NULL;
    }

    Dicionario *dict = (Dicionario *)malloc(sizeof(Dicionario));
    if (dict == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o dicionário\n");
        return NULL;
    }

    dict->pares = (ParChaveValor **)calloc(capacidade, sizeof(ParChaveValor *));
    if (dict->pares == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o array de pares\n");
        free(dict);
        return NULL;
    }
    dict->tamanho = 0;
    dict->capacidade = capacidade;
    return dict;
}

/**
 * @brief Insere um par chave-valor no dicionário.
 *
 * Atualiza o valor se a chave existe; caso contrário, adiciona um novo par se houver espaço.
 * Complexidade: O(n) devido à busca linear.
 *
 * @param dict Dicionário.
 * @param chave Chave a ser inserida (não nula ou vazia).
 * @param valor Valor associado (não nulo).
 * @return 1 se inserido/atualizado com sucesso, 0 se falhou.
 */
int inserirPar(Dicionario *dict, const char *chave, const char *valor)
{
    if (dict == NULL || chave == NULL || *chave == '\0' || valor == NULL)
    {
        fprintf(stderr, "Erro: Dicionário nulo, chave ou valor inválidos\n");
        return 0;
    }

    for (size_t i = 0; i < dict->tamanho; i++)
    {
        if (strncmp(dict->pares[i]->chave, chave, MAX_CHAVE_VALOR) == 0)
        {
            strncpy(dict->pares[i]->valor, valor, MAX_CHAVE_VALOR - 1);
            dict->pares[i]->valor[MAX_CHAVE_VALOR - 1] = '\0';
            return 1;
        }
    }

    if (dict->tamanho >= dict->capacidade)
    {
        fprintf(stderr, "Erro: Dicionário cheio\n");
        return 0;
    }

    ParChaveValor *novo = (ParChaveValor *)malloc(sizeof(ParChaveValor));
    if (novo == NULL)
    {
        fprintf(stderr, "Erro: Falha na alocação de memória para o par\n");
        return 0;
    }
    strncpy(novo->chave, chave, MAX_CHAVE_VALOR - 1);
    novo->chave[MAX_CHAVE_VALOR - 1] = '\0';
    strncpy(novo->valor, valor, MAX_CHAVE_VALOR - 1);
    novo->valor[MAX_CHAVE_VALOR - 1] = '\0';
    dict->pares[dict->tamanho] = novo;
    dict->tamanho++;
    return 1;
}

/**
 * @brief Busca o valor associado a uma chave no dicionário.
 *
 * Complexidade: O(n) devido à busca linear.
 *
 * @param dict Dicionário.
 * @param chave Chave a ser buscada.
 * @return Valor associado ou NULL se não encontrado.
 */
char *buscarValor(Dicionario *dict, const char *chave)
{
    if (dict == NULL || chave == NULL || *chave == '\0')
    {
        return NULL;
    }

    for (size_t i = 0; i < dict->tamanho; i++)
    {
        if (strncmp(dict->pares[i]->chave, chave, MAX_CHAVE_VALOR) == 0)
        {
            return dict->pares[i]->valor;
        }
    }
    return NULL;
}

/**
 * @brief Exibe todos os pares chave-valor no dicionário.
 *
 * @param dict Dicionário.
 */
void imprimirDicionario(Dicionario *dict)
{
    if (dict == NULL || dict->tamanho == 0)
    {
        printf("{}\n");
        return;
    }

    printf("{\n");
    for (size_t i = 0; i < dict->tamanho; i++)
    {
        printf("  \"%s\": \"%s\"%s\n", dict->pares[i]->chave, dict->pares[i]->valor,
               i < dict->tamanho - 1 ? "," : "");
    }
    printf("}\n");
}

/**
 * @brief Libera a memória alocada para o dicionário.
 *
 * @param dict Dicionário.
 */
void liberarDicionario(Dicionario *dict)
{
    if (dict == NULL)
    {
        return;
    }

    for (size_t i = 0; i < dict->tamanho; i++)
    {
        free(dict->pares[i]);
        dict->pares[i] = NULL;
    }
    free(dict->pares);
    free(dict);
}

int main(int argc, char **argv)
{
    Dicionario *dict = criarDicionario(MAX_CHAVE_VALOR);
    if (dict == NULL)
    {
        fprintf(stderr, "Erro: Falha na criação do dicionário\n");
        return EXIT_FAILURE;
    }

    inserirPar(dict, "Chave 1", "Valor 1");
    inserirPar(dict, "Chave 2", "Valor 2");
    inserirPar(dict, "Chave 3", "Valor 3");

    imprimirDicionario(dict);

    char *valor = buscarValor(dict, "Chave 2");
    printf("Valor para 'Chave 2': %s\n", valor ? valor : "Não encontrado");

    liberarDicionario(dict);
    return 0;
}
