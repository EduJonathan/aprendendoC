#include <stdio.h>

/**
 * Passagem por valor: A função trabalha com uma cópia do valor e não altera a
 * variável original.
 *
 * Passagem por referência (via ponteiro): A função recebe o endereço de memória
 * de uma variável e pode modificar diretamente seu valor original.
 */

/**
 * @brief Dobra o valor de um inteiro local.
 *
 * Esta função recebe um inteiro por valor, dobra seu valor e imprime o resultado.
 * A variável `num` é uma cópia da variável passada à função, portanto qualquer
 * modificação dentro da função não afeta a variável original fora dela.
 *
 * @param num O inteiro a ser dobrado (cópia local). O valor original permanece
 *            inalterado após a execução.
 */
void soma(int num)
{
    num = num + num;
    printf(" NA FUNÇÃO soma: num = %d\n", num);

    /*
     * Observação:
     * Apesar de `num` assumir o valor 16 aqui (no caso do exemplo),
     * isso ocorre apenas dentro do escopo da função. Quando a função é chamada,
     * `num` recebe uma COPIA do valor original, realiza o cálculo e depois essa
     * variável local deixa de existir ao sair da função.
     *
     * É por isso que na main o valor original permanece inalterado.
     */
}

/**
 * @brief Dobra o valor de um inteiro usando ponteiro.
 *
 * Esta função recebe um ponteiro para um inteiro, dobra o valor apontado por esse
 * ponteiro e imprime o resultado. Como a operação é feita diretamente na memória
 * onde está o valor original, a variável fora da função é modificada.
 *
 * @param n1 Ponteiro para o inteiro cujo valor será dobrado.
 */
void soma_com_ponteiros(int *n1)
{
    *n1 += *n1; // Dobra o valor na memória
    printf(" NA FUNÇÃO soma_com_ponteiros: n1 = %d\n", *n1);
}

int main(int argc, char **argv)
{
    printf("\n\t>>USANDO A FUNÇÃO SEM PONTEIROS<<\n");

    int valor = 8;
    soma(valor);                                                  // Imprime 16
    printf(" NA MAIN: Valor da variável por valor: %d\n", valor); // Continua 8

    /**
     * Explicação:
     * A função soma() recebe uma cópia de 'valor'. A modificação ocorre apenas
     * nessa cópia e não altera a variável original. Quando a função termina,
     * a variável local é descartada.
     */

    printf("\n\n\t>>USANDO A FUNÇÃO COM PONTEIROS<<\n");

    int referencia = 9;
    soma_com_ponteiros(&referencia);                                        // Imprime 18
    printf(" NA MAIN: Valor da variável por referência: %d\n", referencia); // Agora é 18

    /**
     * Explicação:
     * Aqui passamos o endereço de memória de 'referencia'. Assim, qualquer modificação
     * feita por soma_com_ponteiros() afeta diretamente o valor original, já que a função
     * acessa a variável pela memória.
     */

    return 0;
}
