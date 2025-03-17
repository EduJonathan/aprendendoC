#include <stdio.h>

/**
 * @brief Tipo definido para um ponteiro para função que soma dois inteiros. Este tipo define
 * um ponteiro para uma função que recebe dois inteiros como parâmetros e retorna um inteiro.
 */
typedef int (*funcaoSomar)(int, int);

/**
 * @brief Soma dois inteiros.
 *
 * Esta função recebe dois inteiros como parâmetros e retorna a soma desses inteiros.
 *
 * @param a Primeiro inteiro a ser somado.
 * @param b Segundo inteiro a ser somado.
 * @return A soma de a e b.
 */
int somar(int a, int b)
{
    return a + b;
}

int main(int argc, char **argv)
{
    /**
     * @brief Declara e inicializa um ponteiro para a função de soma.
     *
     * O ponteiro para a função `ptrSoma` é inicializado para apontar para a função `somar`.
     * Em seguida, é utilizado para calcular a soma de dois inteiros.
     */
    funcaoSomar ptrSoma = somar;

    /**
     * @brief Calcula a soma de dois números usando o ponteiro para função.
     *
     * A função `ptrSoma` é chamada com os valores 3 e 5, e o resultado é armazenado
     * na variável `resultado`.
     */
    int resultado = ptrSoma(3, 5);
    printf("Soma: %d\n", resultado);
    return 0;
}
