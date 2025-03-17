#include <stdio.h>

/**
 * STATIC: Indica que uma variável tem escopo de arquivo, ou seja, é visível em todo o
 * arquivo onde é declarada, mas mantém seu valor entre chamadas da função ou
 * do bloco onde foi declarada. Isso permite persistir um estado entre chamadas
 * consecutivas. No entanto, seu uso deve ser cuidadoso, pois pode tornar o código
 * menos previsível e gerar efeitos colaterais.
 *
 * @note: Variáveis `static` não podem ser usadas como membros de `structs`.
 */

/**
 * @brief Função que irá incrementar uma variável estática a cada chamada da função
 *
 * esse exemplo demonstra o uso de variáveis estáticas.
 *
 * @return void
 */
void teste_static_global(void)
{
    // Declarando uma variável estática
    static int a = 0;

    // Incrementa essa variável a cada chamada da função por 5
    a += 5;

    // Declarando uma variável inteira
    int b = 0;

    // Incrementa essa variável a cada chamada da função por 1
    // b é uma variável local, significa que ela será reinicializada a cada vez que a
    // função é chamada. ela é incrementada em 1 a cada chamada.
    b++;

    printf("STATIC a: %d\tINT b: %d\n", a, b);
    printf("STATIC a: %d\tINT b: %d\n", a, b);
    /*
     * Note que a variável `b` dentro da função teste_static_global não é estática e,
     * portanto, é reinicializada a cada chamada da função. Isso reflete o comportamento
     * esperado das variáveis estáticas, onde o valor de `a` é mantido entre as chamadas
     * da função teste_static_global, enquanto o valor de `b` é reinicializado a
     * cada chamada.
     */
}

/**
 * @brief Procedimento que irá incrementar uma variável estática a cada chamada da função
 */
void estatico(void)
{
    // Variavel `a` é estatica e tem escopo de de função
    static int a = 5;

    // Imprimindo o valor da variável
    printf("\nValor de a: %d\n", a);

    // Vai incrementando o valor da variável
    a++;
}

int main(int argc, char **argv)
{
    estatico();
    /// OUTPUT: 5

    estatico();
    /// OUTPUT: 6

    printf("\n===================\n");

    teste_static_global();
    /// OUTPUT: 5 1

    teste_static_global();
    /// OUTPUT: 10 1
    return 0;
}
