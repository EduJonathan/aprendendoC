#include <stdio.h>
#include <complex.h>

/**
 * Números complexos são números que têm duas partes: uma parte real e uma parte imaginária,
 * representados da forma: 𝑧 = 𝑎 + 𝑏𝑖
 * Onde:
 * 𝑎 => é a parte real,
 * 𝑏 => é a parte imaginária,
 * 𝑖 => é a unidade imaginária, tal que 𝑖² = −1
 *
 * a biblioteca <complex.h> oferece uma maneira prática de manipular números complexos.
 * Usando o tipo complex e as funções fornecidas, você pode realizar operações como
 * soma, multiplicação, conjugado, cálculo de módulo e argumento com facilidade.
 */

int main(int argc, char **argv)
{
    // Definindo um número complexo
    double complex z1 = 3.0 + 4.0 * I; // Parte real = 3, Parte imaginária = 4
    double complex z2 = 1.0 + 2.0 * I; // Parte real = 1, Parte imaginária = 2

    // I é a constante da unidade imaginária em C
    // Em números complexos, a unidade imaginária é denotada por 𝑖,
    // e é definida pela propriedade: 𝑖² = − 1, em outras palavras a declaração
    // double complex z1 = 3.0 + 4.0 * I;
    // é interpretada como declarando um número complexo: 3 + 4i

    // Operações com números complexos
    double complex soma = z1 + z2;       // Soma de números complexos
    double complex produto = z1 * z2;    // Produto de números complexos
    double complex conjugado = conj(z1); // Conjugado de z1

    // Módulo de um número complexo
    double modulo = cabs(z1); // |z1| = sqrt(3^2 + 4^2)

    // Argumento (fase) de um número complexo
    double argumento = carg(z1); // ângulo em radianos

    // Exibindo os resultados
    printf("Número complexo z1: %.2f + %.2fi\n", creal(z1), cimag(z1));
    printf("Número complexo z2: %.2f + %.2fi\n", creal(z2), cimag(z2));

    printf("Soma de z1 e z2: %.2f + %.2fi\n", creal(soma), cimag(soma));
    printf("Produto de z1 e z2: %.2f + %.2fi\n", creal(produto), cimag(produto));
    printf("Conjugado de z1: %.2f + %.2fi\n", creal(conjugado), cimag(conjugado));

    printf("Módulo de z1: %.2f\n", modulo);
    printf("Argumento (fase) de z1: %.2f rad\n", argumento);

    // creal(z): Retorna a parte real de um número complexo z.
    // cimag(z) : Retorna a parte imaginária de um número complexo z.

    /**
     * Na biblioteca <complex.h>, Os números complexos tem funções de retornos semelhantes
     * ao math.h para se trabalhar com resultados dos tipos flutuantes(float, double e long double)
     * e retornos de funções, exemplo no math.h, temos o (pow, sqrt, etc...), o complex.h
     * possue essas funções porém com uma diferença na nomeação que basta inserir um 'c' antes
     * da função, exemplo (cpow, csqrt, etc...), tendo suas variações para outros tipos de dados
     * flutuantes. Como por exemplo(cpow(double), cpowf(float), cpowl(long double)) assim
     * como dentre outras funções
     *
     * FUNÇÕES DA BIBLIOTECA <complex.h> e dentre várias outras funções,
     * a cppreference é uma documentação bastante completa tanto para C e C++:
     * @link https://en.cppreference.com/w/c/header/complex (ctrl + botão esquerdo do mouse para acessar no VsCode)
     */
    return 0;
}
