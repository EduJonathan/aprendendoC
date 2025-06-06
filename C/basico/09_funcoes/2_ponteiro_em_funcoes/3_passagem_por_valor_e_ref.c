#include <stdio.h>

/**
 * Passagem por valor: A função trabalha com uma cópia do valor e não altera o valor
 * da variável original.
 * Passagem por referência (via ponteiro): A função altera diretamente a variável original, 
 * pois trabalha com o endereço de memória da variável.
 */

/**
 * @brief Dobra o valor de um inteiro local.
 *
 * Esta função recebe um inteiro, dobra seu valor e imprime o resultado. A variável `num`
 * é uma cópia local da variável que foi passada para a função, portanto, qualquer modificação
 * feita dentro da função não afeta a variável original fora da função. O valor impresso
 * será o dobro do valor passado.
 *
 * @param num O inteiro a ser dobrado. O valor original não é alterado fora da função.
 */
void soma(int num)
{
    num = num + num;
    printf(" NA FUNÇÃO SOMA: num = %d\n", num); // O valor impresso será o dobro do valor passado

    // 16 é considerado por conta do printf, a qual a variável recebeu a instrução dentro da sua
    // própria função o escopo de varíavel local e a função no momento que ela for chamada já
    // fará toda o procedimento não afetando a variável original fora da função, e na main?
}

/**
 * @brief Dobra o valor de um inteiro usando ponteiro.
 *
 * Esta função recebe um ponteiro para um inteiro, dobra o valor apontado pelo ponteiro e
 * imprime o resultado. A variável original fora da função é afetada porque a função
 * modifica o valor na memória onde o ponteiro aponta.
 *
 * @param n1 Ponteiro para o inteiro.
 */
void soma_com_ponteiros(int *n1)
{
    // Dobra o valor do inteiro apontado por n1
    *n1 += *n1;

    // O valor impresso será o dobro do valor original
    printf(" NA FUNÇÃO soma_com_ponteiros: n1 = %d\n", *n1);
}

int main(int argc, char **argv)
{
    printf("\n\t>>USANDO A FUNÇÃO SEM PONTEIROS<<\n");
    int valor = 8;

    soma(valor);                                                   // 16
    printf(" NA MAIN: Valor da varíavel pela valor: %d\n", valor); // 8

    /**
     * A função soma recebe uma cópia do valor da variável. Ou seja, quando você passa
     * uma variável para a função, a função recebe uma cópia desse valor e qualquer alteração
     * feita na cópia não afeta a variável original.
     * Após a execução da função, a cópia é destruída e o valor da variável original
     * permanece inalterado.
     */
    printf("\n\n\t>>USANDO A FUNÇÃO COM PONTEIROS<<\n");

    int referencia = 9;

    soma_com_ponteiros(&referencia);                                         // 18
    printf(" NA MAIN: Valor da varíavel pela referencia: %d\n", referencia); // 18

    /**
     * A função `soma_com_ponteiros` recebe o endereço de memória de `referencia`.
     * Ou seja, ao passar um ponteiro, a função modifica diretamente o valor da variável 
     * original, já que está trabalhando com a localização de memória da variável.
     * O valor de 'referencia' é alterado fora da função.
     */
    return 0;
}
