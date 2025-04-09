#ifndef ARMSTRONG_FUNC_H
#define ARMSTRONG_FUNC_H

#include <stdbool.h>
#include <math.h>
#include "isArmstrong.h"

/**
 * @brief Conta o número de dígitos em um número inteiro.
 *
 * Esta função calcula quantos dígitos estão presentes no número inteiro fornecido.
 *
 * @param number O número inteiro para o qual contar os dígitos.
 * @return O número total de dígitos no número inteiro.
 */
int count_digits(int number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10; // Remove o último dígito dividindo por 10
        count++;      // Incrementa o contador de dígitos
    }
    return count;
}

/**
 * @brief Verifica se um número é um número de Armstrong.
 *
 * Esta função verifica se o número fornecido é um número de Armstrong.
 * Um número de Armstrong é um número que é igual à soma dos seus próprios dígitos
 * elevados a uma potência que é igual ao número de dígitos.
 *
 * @param candidate O número inteiro para verificar.
 * @return true se candidate é um número de Armstrong, false caso contrário.
 */
bool is_armstrong_number(int candidate)
{
    int sum = 0;
    int rem = 0;
    int temp = candidate;
    int num_digits = count_digits(candidate);

    // Calcula a soma dos dígitos elevados à potência num_digits
    while (candidate != 0)
    {
        rem = candidate % 10;             // Obtém o último dígito
        sum = sum + pow(rem, num_digits); // Adiciona rem elevado a num_digits à soma
        candidate /= 10;                  // Remove o último dígito de candidate
    }
    return sum == temp; // Retorna true se candidate for um número de Armstrong, senão false
}

#endif
