#include <stdio.h>
#include "append.h"

int main(int argc, char **argv)
{
    // Declarando a string
    string minhaString = {0};

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
