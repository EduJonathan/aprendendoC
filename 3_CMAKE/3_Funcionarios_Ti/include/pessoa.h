#ifndef PESSOA_H
#define PESSOA_H

#include <stddef.h>
#include <stdbool.h>

/**
 * @brief Níveis de experiência de uma pessoa.
 */
typedef enum
{
    JUNIOR, /**< Profissional em início de carreira */
    PLENO,  /**< Profissional com experiência intermediária */
    SENIOR  /**< Profissional experiente */
} NivelExperiencia;

/**
 * @brief Estrutura que representa uma pessoa.
 */
typedef struct
{
    char nome[50];           /**< Nome da pessoa */
    int idade;               /**< Idade da pessoa */
    float salario;           /**< Salário da pessoa */
    NivelExperiencia nivel;  /**< Nível de experiência */
    void *dados_processador; // Para dados específicos do processador
} Pessoa;

/**
 * @brief Ponteiro para função usada como callback para processar pessoas.
 */
typedef void (*Processador)(Pessoa *);

/**
 * @brief Cria uma nova pessoa.
 *
 * @param nome Nome da pessoa.
 * @param idade Idade da pessoa.
 * @param salario Salário da pessoa.
 * @param nivel Nível de experiência.
 * @return Ponteiro para a nova pessoa criada, ou NULL em caso de falha.
 */
Pessoa *criar_pessoa(const char *nome, int idade, float salario, NivelExperiencia nivel);

/**
 * @brief Libera a memória de uma pessoa criada dinamicamente.
 *
 * @param p Ponteiro para a pessoa a ser destruída.
 */
void destruir_pessoa(Pessoa *p);

/**
 * @brief Imprime os dados de uma pessoa no console.
 *
 * @param p Ponteiro constante para a pessoa a ser impressa.
 */
void imprimir_pessoa(const Pessoa *p);

/**
 * @brief Processa um array de pessoas usando uma função callback.
 *
 * @param pessoas Array de pessoas.
 * @param tamanho Quantidade de pessoas no array.
 * @param callback Função que será aplicada em cada pessoa.
 */
void processar_array(Pessoa pessoas[], size_t tamanho, Processador callback);

/**
 * @brief Promove uma pessoa para o próximo nível de experiência.
 *
 * @param p Ponteiro para a pessoa a ser promovida.
 */
void promover_pessoa(Pessoa *p);

/**
 * @brief Clona uma pessoa.
 *
 * @param original Ponteiro constante para a pessoa original.
 * @return Ponteiro para a nova pessoa clonada, ou NULL em caso de falha.
 */
Pessoa *clonar_pessoa(const Pessoa *original);

/**
 * @brief Cria um array dinâmico de pessoas.
 *
 * @param tamanho Quantidade de pessoas no array.
 * @return Ponteiro para o array de pessoas alocado, ou NULL em caso de falha.
 */
Pessoa *criar_array_pessoas(size_t tamanho);

/**
 * @brief Ordena um array de pessoas em ordem alfabética pelo nome.
 *
 * @param pessoas Array de pessoas.
 * @param tamanho Quantidade de pessoas no array.
 */
void ordenar_pessoas_por_nome(Pessoa pessoas[], size_t tamanho);

/**
 * @brief Ordena um array de pessoas em ordem crescente de salário.
 *
 * @param pessoas Array de pessoas.
 * @param tamanho Quantidade de pessoas no array.
 */
void ordenar_pessoas_por_salario(Pessoa pessoas[], size_t tamanho);

#endif // PESSOA_H
