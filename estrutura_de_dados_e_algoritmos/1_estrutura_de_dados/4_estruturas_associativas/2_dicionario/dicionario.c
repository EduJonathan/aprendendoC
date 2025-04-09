#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MAX_CHAVE_VALOR 100 // Tamanho máximo para chave e valor

#ifndef PARES_H
#define PARES_H

/**
 * @struct pares
 * @brief Estrutura para armazenar um par chave-valor.
 *
 * Esta estrutura contém uma chave e um valor, ambos como strings.
 */
typedef struct pares
{
    char chave[MAX_CHAVE_VALOR]; /**< A chave associada ao valor, com tamanho fixo. */
    char valor[MAX_CHAVE_VALOR]; /**< O valor associado à chave, com tamanho fixo. */
} ChavesValores;

#endif

#ifndef DICT_H
#define DICT_H

/**
 * @struct dictionary
 * @brief Estrutura que representa um dicionário de pares chave-valor.
 *
 * O dicionário é uma estrutura que contém um vetor de pares chave-valor,
 * com um limite de tamanho definido.
 */
typedef struct dictionary
{
    ChavesValores *keysValues[SIZE]; /**< Vetor de ponteiros para os pares chave-valor. */
    size_t tamanho;                  /**< O número atual de pares chave-valor no dicionário. */
} Dicionario;

#endif

/**
 * @brief Inicializa o dicionário, configurando seu tamanho para 0.
 *
 * Esta função prepara o dicionário para inserção de novos pares chave-valor.
 *
 * @param dict Ponteiro para o dicionário a ser inicializado.
 */
void inicializar(Dicionario *dict)
{
    dict->tamanho = 0;
}

/**
 * @brief Insere um par chave-valor no dicionário.
 *
 * Se a chave já existir, o valor é atualizado. Caso contrário, um novo par é adicionado.
 *
 * @param dict Ponteiro para o dicionário onde o par será inserido.
 * @param chave A chave a ser inserida ou atualizada.
 * @param valor O valor a ser associado à chave.
 */
void inserir(Dicionario *dict, const char *chave, const char *valor)
{
    for (int i = 0; i < dict->tamanho; i++)
    {
        if (strncmp(dict->keysValues[i]->chave, chave, MAX_CHAVE_VALOR) == 0)
        {
            // Atualiza o valor se a chave já existir
            strncpy(dict->keysValues[i]->valor, valor, MAX_CHAVE_VALOR - 1);
            dict->keysValues[i]->valor[MAX_CHAVE_VALOR - 1] = '\0'; // Garantir terminação nula
            return;
        }
    }

    if (dict->tamanho < SIZE)
    {
        dict->keysValues[dict->tamanho] = (ChavesValores *)malloc(sizeof(ChavesValores));

        // Copia a chave e valor com segurança
        strncpy(dict->keysValues[dict->tamanho]->chave, chave, MAX_CHAVE_VALOR - 1);
        dict->keysValues[dict->tamanho]->chave[MAX_CHAVE_VALOR - 1] = '\0'; // Garantir terminação nula

        strncpy(dict->keysValues[dict->tamanho]->valor, valor, MAX_CHAVE_VALOR - 1);
        dict->keysValues[dict->tamanho]->valor[MAX_CHAVE_VALOR - 1] = '\0'; // Garantir terminação nula
        dict->tamanho++;
    }
}

/**
 * @brief Busca o valor associado a uma chave no dicionário.
 *
 * A função retorna o valor correspondente à chave fornecida, caso exista.
 *
 * @param dict Ponteiro para o dicionário onde a busca será realizada.
 * @param chave A chave a ser buscada.
 * @return O valor associado à chave, ou NULL caso a chave não exista.
 */
char *buscar(Dicionario *dict, const char *chave)
{
    for (int i = 0; i < dict->tamanho; i++)
    {
        if (strncmp(dict->keysValues[i]->chave, chave, MAX_CHAVE_VALOR) == 0)
        {
            return dict->keysValues[i]->valor;
        }
    }    
    return NULL;
}

/**
 * @brief Exibe todos os pares chave-valor presentes no dicionário.
 *
 * A função percorre o dicionário e imprime todos os pares chave-valor.
 *
 * @param d Ponteiro para o dicionário a ser exibido.
 */
void exibir(Dicionario *dict)
{
    printf("{\n");
    for (int i = 0; i < dict->tamanho; i++)
    {
        printf(" \"%s\": \"%s\"\n", dict->keysValues[i]->chave, dict->keysValues[i]->valor);
    }
    printf("}\n");
}

/**
 * @brief Libera a memória alocada para o dicionário.
 *
 * A função libera a memória utilizada pelas chaves e valores armazenados.
 *
 * @param dict Ponteiro para o dicionário a ser liberado.
 */
void liberar(Dicionario *dict)
{
    for (int i = 0; i < dict->tamanho; i++)
    {
        free(dict->keysValues[i]); // Liberar memória do par chave-valor
    }
}

int main(int argc, char **argv)
{
    Dicionario dict;

    // Inicializa o dicionário
    inicializar(&dict);

    // Insere pares chave-valor
    inserir(&dict, "Chave 1", "Valor 1");
    inserir(&dict, "Chave 2", "Valor 2");
    inserir(&dict, "Chave 3", "Valor 3");

    // Exibe o conteúdo do dicionário
    exibir(&dict);

    // Realiza busca
    char *valor = buscar(&dict, "Chave 2");
    printf("valor: %s\n", valor ? valor : "Nao encontrado");

    // Libera a memória alocada para o dicionário
    liberar(&dict);

    return 0;
}
