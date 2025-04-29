#include <stdio.h>

/**
 * @brief Função que imprime o valor inteiro recebido através de um ponteiro void.
 *
 * Esta função recebe um ponteiro genérico (`void *`) que é convertido para um ponteiro
 * para inteiro. O valor do inteiro apontado pelo ponteiro é então impresso.
 *
 * @param arg Ponteiro genérico (`void *`) que deve apontar para um valor inteiro.
 */
void argGeneric(void *arg)
{
    // Suponhamos que o ponteiro aponta para um inteiro
    int *valorint = (int *)arg;
    printf("\nValor como int: %d\n", *valorint);

    // Ponteiro também pode apontar para um float
    float *valorfloat = (float *)arg;
    printf("Valor como float: %.2f\n", *valorfloat);

    // Ponteiro também pode apontar para um char
    char *valorchar = (char *)arg;
    printf("Valor como char: %c\n\n", *valorchar);
}

/**
 * @brief Função que retorna a string fornecida como argumento.
 *
 * Esta função simplesmente retorna o ponteiro para a string que foi passado como argumento.
 *
 * @param str Ponteiro para uma string (`const char *`) que será retornada.
 * @return `const char *` Ponteiro para a string fornecida.
 */
const char *argStr(const char *str)
{
    // Retorna o ponteiro para a string passada como argumento
    return str;
}

int main(int argc, char **argv)
{
    int meuInteiro = 42;
    float meuFloat = 3.14;
    char letra = 'Q';

    // Chamando a função com um ponteiro para um inteiro
    argGeneric(&meuInteiro);

    // Chamando a função com um ponteiro para um float
    argGeneric(&meuFloat);

    // Chamando a função com um ponteiro para um int
    argGeneric(&letra);

    // Essa é uma das vantagens além de conter quaisquer endereços, basta converte-lo
    // para o tipo de dado que desejar, o problema é que essas conversões perdem suas
    // informações sobre, então seu uso necessita ser bem cuidado.

    const char *str = "Hello World";
    const char *string = argStr(str);

    /// O primeiro @param de printf é "const char *__format"
    printf(string);
    return 0;
}
