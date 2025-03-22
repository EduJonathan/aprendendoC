#include <stdio.h>

/**
 * TYPEDEF: É uma keyword (palavra reservada) que criam sinônimos e não um novo tipo
 * de dado, são declaradas para tipos de dados, arrays, structs, unions, ponteiros para
 * função e enums.
 *
 * @note typedef NÃO cria um novo tipo de dado, ele cria um sinônimo para o tipo de dado
 */

typedef char charactere_Global; // Redefinindo o tipo de dado char global para charactere_Global
typedef float *pointerToFloat;  // Redefinindo um ponteiro global para um tipo float

int main(int argc, char **argv)
{
    typedef int numero_local;  // Redefinindo o tipo de dado int numero
    /* typedef float float; */ // Nomes iguais não pode e muito menos outras palavras reservadas

    charactere_Global caractereGlobal = 'A'; // char redefinido passamos um identificador e um valor
    numero_local inteiroLocal = 1;           // int redefinido passamos um identificador e um valor
    // Caso tentarmos apenas charactere = 'A' e numero = 1;
    // Dar erro, pois são apenas os tipos renomeados, então precisamos dos identificadores

    // Imprimindo os valores
    printf("caractereGlobal = %c\n", caractereGlobal);
    printf("inteiroLocal = %d\n", inteiroLocal);

    // Renomeando um vetor com typedef
    typedef const char str[11];

    // Variável para o ponteiro pointerToFloat
    float PI = 3.14F;

    // Inserindo valores para
    pointerToFloat toFloat = &PI;
    str string = "Obrigado";

    // Imprimindo os valores
    printf("toFloat = %f\n", *toFloat);
    printf("string = %s\n", string);
    return 0;
}
