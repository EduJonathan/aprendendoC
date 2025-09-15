#ifndef PESSOA_H
#define PESSOA_H

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Estrutura que representa uma pessoa.
 *
 * Contém informações básicas como idade, nome, altura e peso.
 */
struct Pessoa
{
    unsigned idade; ///< Idade da pessoa
    char nome[100]; ///< Nome da pessoa (máximo 100 caracteres)
    float altura;   ///< Altura da pessoa em metros
    float peso;     ///< Peso da pessoa em kg
};

/**
 * @brief Estrutura que representa o IMC de uma pessoa.
 *
 * Contém o valor do IMC e sua descrição (categoria).
 */
struct IMC
{
    float valor;        ///< Valor do IMC
    char descricao[50]; ///< Descrição da categoria do IMC
};

/**
 * @brief Inicializa uma estrutura de pessoa com as informações fornecidas.
 *
 * Atribui os valores de nome, idade, altura e peso à estrutura fornecida.
 *
 * @param pessoa Ponteiro para a estrutura de pessoa a ser inicializada.
 * @param nome Nome da pessoa (máximo 99 caracteres).
 * @param idade Idade da pessoa.
 * @param altura Altura da pessoa em metros.
 * @param peso Peso da pessoa em kg.
 * @return true se a inicialização for bem-sucedida, false caso contrário.
 */
bool setPessoa(struct Pessoa *pessoa, const char *nome, unsigned idade, float altura, float peso);

/**
 * @brief Imprime as informações de uma pessoa.
 *
 * Exibe os dados da estrutura de pessoa fornecida.
 *
 * @param pessoa Ponteiro para a estrutura de pessoa.
 */
void getPessoa(const struct Pessoa *pessoa);

/**
 * @brief Calcula o IMC (Índice de Massa Corporal) da pessoa.
 *
 * A fórmula do IMC é: IMC = peso / (altura * altura).
 *
 * @param pessoa Ponteiro para a estrutura de pessoa.
 * @return O valor do IMC calculado, ou -1 se houver erro.
 */
float calcularIMC(const struct Pessoa *pessoa);

/**
 * @brief Classifica o IMC da pessoa em uma categoria.
 *
 * Retorna uma estrutura IMC com o valor do IMC e sua descrição (categoria).
 *
 * @param pessoa Ponteiro para a estrutura de pessoa.
 * @return Estrutura IMC com o valor e a descrição da categoria.
 */
struct IMC classificarIMC(const struct Pessoa *pessoa);

/**
 * @brief Imprime o IMC da pessoa.
 *
 * Exibe o IMC calculado e sua categoria para a pessoa fornecida.
 *
 * @param pessoa Ponteiro para a estrutura de pessoa.
 */
void imprimirIMC(const struct Pessoa *pessoa);

/**
 * @brief Verifica se a pessoa está obesa com base no IMC.
 *
 * A obesidade é definida como IMC >= 30.
 *
 * @param pessoa Ponteiro para a estrutura de pessoa.
 * @return true se a pessoa estiver obesa, false caso contrário.
 */
bool verificarObesidade(const struct Pessoa *pessoa);

/**
 * @brief Imprime se a pessoa está obesa ou não.
 *
 * Exibe uma mensagem indicando se a pessoa está obesa com base no IMC.
 *
 * @param pessoa Ponteiro para a estrutura de pessoa.
 */
void imprimirObesidade(const struct Pessoa *pessoa);

#endif // PESSOA_H
