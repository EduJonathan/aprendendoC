#include <stdio.h>

/**
 * TYPEDEF: A keyword (palavra reservada) typedef é usada para criar sinônimos para 
 * tipos de dados, incluindo tipos primitivos, arrays, structs, unions, ponteiros para funções
 * e enums.
 *
 * @note typedef NÃO cria um novo tipo de dado. Em vez disso, ele cria um **alias** ou **sinônimo**
 * para um tipo de dado existente, facilitando a legibilidade do código, especialmente quando
 * tipos complexos estão envolvidos.
 *
 * Quando usar:
 * - Para simplificar tipos complexos, como ponteiros para funções ou structs com muitos campos.
 * - Para melhorar a legibilidade do código, fornecendo nomes mais descritivos.
 * - Para tornar o código mais flexível, permitindo alterações no tipo subjacente 
 * sem precisar modificar todas as ocorrências.
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
