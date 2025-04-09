#ifndef PESSOA_H
#define PESSOA_H

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#ifndef PERSON_H
#define PERSON_H

/**
 * @brief Estrutura que representa uma pessoa. Esta estrutura contém as informações básicas
 * de uma pessoa, como idade, nome, altura e peso. Ela é usada para armazenar dados
 * relacionados a uma pessoa de forma organizada.
 */
struct Person
{
    unsigned idade; ///< Idade da pessoa
    char *nome;     ///< Nome da pessoa
    float altura;   ///< Altura da pessoa em metros
    float peso;     ///< Peso da pessoa em kg
};

#endif

/**
 * @brief Inicializa uma estrutura de pessoa com as informações fornecidas.
 *
 * Esta função atribui os valores de nome, idade, altura e peso à estrutura
 * de pessoa fornecida como argumento e retorna a estrutura inicializada.
 *
 * @param P Ponteiro para a estrutura de pessoa a ser inicializada.
 * @param nome Nome da pessoa.
 * @param idade Idade da pessoa.
 * @param altura Altura da pessoa.
 * @param peso Peso da pessoa.
 */
void setPessoa(struct Person *pessoa, char *nome, unsigned idade, float altura, float peso)
{
    pessoa->idade = idade;   ///< Atribui a idade à estrutura Person
    pessoa->altura = altura; ///< Atribui a altura à estrutura Person
    pessoa->peso = peso;     ///< Atribui o peso à estrutura Person
    pessoa->nome = nome;     ///< Atribui o nome à estrutura Person
}

/**
 * @brief Imprime as informações de uma estrutura de pessoa.
 *
 * Esta função imprime os dados da estrutura de pessoa fornecida como argumento.
 *
 * @param P Ponteiro para a estrutura de pessoa a ser impressa.
 */
void getPessoa(struct Person *pessoa)
{
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %u\n", pessoa->idade);
    printf("Altura: %.2f\n", pessoa->altura);
    printf("Peso: %.2f\n", pessoa->peso);
}

/**
 * @brief Calcula o IMC (Índice de Massa Corporal) da pessoa.
 *
 * A fórmula do IMC é: IMC = peso / (altura * altura)
 *
 * @param pessoa Ponteiro para a estrutura da pessoa.
 * @return O valor do IMC calculado, ou -1 se houver erro.
 */
float calcularIMC(struct Person *pessoa)
{
    // Verificar se altura e peso são válidos
    if (pessoa->altura <= 0 || pessoa->peso <= 0)
    {
        printf("Erro: altura e peso devem ser maiores que zero.\n");
        return -1; // Retorna -1 se houver erro nos valores de altura ou peso
    }
    return pessoa->peso / pow(pessoa->altura, 2); // Se não houver erro, calcular e retornar o IMC
}

/**
 * @brief Imprime o IMC da pessoa.
 *
 * Esta função imprime o IMC calculado da pessoa fornecida como argumento.
 *
 * @param pessoa Ponteiro para a estrutura da pessoa.
 */
void imprimirIMC(struct Person *pessoa)
{
    float imc = calcularIMC(pessoa);

    if (imc != -1)
    {
        printf("IMC de %s: %.2f\n", pessoa->nome, imc);
    }
}

/**
 * @brief Verifica se a pessoa está obesa com base no IMC.
 *
 * A obesidade é definida como IMC >= 30.
 *
 * @param pessoa Ponteiro para a estrutura da pessoa.
 * @return true se a pessoa estiver obesa, false caso contrário.
 */
bool verificarObesidade(struct Person *pessoa)
{
    float imc = calcularIMC(pessoa);

    if (imc == -1)
    {
        // Se o IMC não foi calculado (erro), consideramos não obeso
        return false;
    }
    if (imc >= 30)
    {
        // A pessoa está obesa
        return true;
    }
    return false; // A pessoa não está obesa
}

/**
 * @brief Imprime se a pessoa está obesa ou não.
 *
 * Esta função verifica se a pessoa está obesa e imprime a mensagem apropriada.
 *
 * @param pessoa Ponteiro para a estrutura da pessoa.
 */
void imprimirObesidade(struct Person *pessoa)
{
    if (verificarObesidade(pessoa))
    {
        printf("%s está obeso(a).\n", pessoa->nome);
    }
    else
    {
        printf("%s não está obeso(a).\n", pessoa->nome);
    }
}

#endif
