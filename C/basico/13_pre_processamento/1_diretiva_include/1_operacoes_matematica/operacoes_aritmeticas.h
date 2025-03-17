#ifndef OPERACOES_ARITMETICAS_H
#define OPERACOES_ARITMETICAS_H

#include "functions_aritmeticas.h"

/**
 * @brief Implementação da função de adição
 *
 * @param a primeiro valor a ser inserido
 * @param b segundo valor a ser inserido
 * @return float retorna soma dos dois parâmetros
 */
float add(float a, float b)
{
    return a + b;
}

/**
 * @brief Implementação da função de subtração
 *
 * @param a primeiro valor a ser inserido
 * @param b segundo valor a ser inserido
 * @return float retorna subtração dos dois parâmetros
 */
float subtract(float a, float b)
{
    return a - b;
}

/**
 * @brief Implementação da função de multiplicação
 *
 * @param a primeiro valor a ser inserido
 * @param b segundo valor a ser inserido
 * @return float retorna multiplicação dos dois parâmetros
 */
float multiply(float a, float b)
{
    return a * b;
}

/**
 * @brief Implementação da função de divisão
 *
 * @param a primeiro valor a ser inserido
 * @param b segundo valor a ser inserido
 * @return float retorna multiplicação dos dois parâmetros
 */
float divide(float a, float b)
{
    // Tratamento de divisão por zero
    if (b == 0.0F)
    {
        // Imprime mensagem de erro
        printf("Não é possível realizar a divisão por zero!\n");
        return 0.0F;
    }

    // Se não houver erro, realiza a divisão
    return a / b;
}

#endif
