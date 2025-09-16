#ifndef ARMSTRONG_FUNC_H
#define ARMSTRONG_FUNC_H

#include <stdbool.h>
#include <math.h>
#include "is_armstrong.h"

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
        number /= 10;
        count++;
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
    int sum = 0, rem = 0, temp = candidate;
    int num_digits = count_digits(candidate);
    while (candidate != 0)
    {
        rem = candidate % 10;
        sum += pow(rem, num_digits);
        candidate /= 10;
    }
    return sum == temp;
}

#endif