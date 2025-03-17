#include <stdio.h>

/**
 * @brief Struct que representa dois números para operacionar
 */
struct numeros
{
    double num1; /**< Campo para o primeiro número */
    double num2; /**< Campo para o segundo número */
};

/**
 * @brief Função que realiza uma soma
 *
 * Função que realiza a soma dos campos da struct
 *
 * @param n Recebe uma struct que irá obter os campos da struct
 * @return Retorna a soma do tipo double
 */
double somaStruct(struct numeros n)
{
    return n.num1 + n.num2;
}

int main(int argc, char **argv)
{
    struct numeros numbers = {10, 20}; // Declarando a struct e entregando valores para os campos

    // Guardando o retorno da função dentro de soma e aplicando a função, juntamente
    // com os valores declarados dos campos através da declaração struct numeros numbers
    double soma = somaStruct(numbers);

    printf("A soma dos valores %.2lf + %.2lf é: %.2lf", numbers.num1, numbers.num2, soma);
    return 0;
}
