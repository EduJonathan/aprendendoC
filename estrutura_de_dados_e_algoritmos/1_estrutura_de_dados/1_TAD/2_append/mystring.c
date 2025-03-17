#include <stdio.h>
#include "append.h"

/**
 * TAD: (Abstract Data Type ou Tipo Abstrato de Dados) Se trata de um conjunto de
 * regras ou regras de comportamento que define o comportamento de um conjunto de
 * dados, ou seja, é um modelo conceitual que define um conjunto de operações e
 * comportamento para um tipo de dado, sem especificar como essas operações serão
 * implementadas ou estão organizados na memória.
 *
 * TESE: TAD é utilizado para modelar um conjunto de dados e comportamentos,
 * mas ocultando todo o processo de implementação do programa.
 */

int main(int argc, char **argv)
{
    // Declarando a string
    string minhaString;

    // iniciando a string
    string_init(minhaString);

    // insirindo caractere por caractere
    string_append(minhaString, 'I');  // Caractere: 'I'
    string_append(minhaString, 'T');  // Caractere: 'T'
    string_append(minhaString, '\''); // Caractere: '
    string_append(minhaString, 'S');  // Caractere: 'S'
    string_append(minhaString, ' ');  // Caractere: ' '
    string_append(minhaString, 'W');  // Caractere: 'W'
    string_append(minhaString, 'O');  // Caractere: 'O'
    string_append(minhaString, 'R');  // Caractere: 'R'
    string_append(minhaString, 'K');  // Caractere: 'K'
    string_append(minhaString, 'I');  // Caractere: 'I'
    string_append(minhaString, 'N');  // Caractere: 'N'
    string_append(minhaString, 'G');  // Caractere: 'G'
    string_append(minhaString, '!');  // Caractere: '!'

    // Exibindo a string
    string_print(minhaString);
    return 0;
}
