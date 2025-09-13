#include <stdio.h>
#include "1_extern.c"

/*
 * global_extern = 3;
 * type defaults to 'int' in declaration of 'global_extern' [-Wimplicit-int]gcc
 * <error - type> global_extern
 */

int global_extern = 3;
/*
 * Por mais que a varíavel esteja visível, é importante "saltar" o mesmo nome da varíavel
 * extern que está no outro arquivo, declarando seu tipo também.
 */

// Declarando uma constante de um vetor de 5 caracteres
const char meuArray[5] = {'0', '1', '2', '3', '4'};

/**
 * @brief Com a utilização da keyword extern criamos uma função chamada "extern_function"
 * que irá apenas calcular a soma de 2 valores floats
 *
 * @param num1 Parêmetro para inserir o primeiro valor
 * @param num2 Parêmetro para inserir o segundo valor
 * @return Retorna a soma dos valores dos parâmetros
 */
float extern_function(float num1, float num2)
{
    float resultado = num1 + num2;
    printf("Resultado = %f\n", resultado);
    return resultado;
}

int main(int argc, char **argv)
{
    extern_function(56.0F, 4.0F);
    printf("\n-------------------------------------\n");

    printf("Endereço de global_extern no arquivo main.c: %p\n", &global_extern);
    teste();
    return 0;
}
