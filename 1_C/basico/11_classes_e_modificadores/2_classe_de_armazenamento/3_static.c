#include <stdio.h>

/**
 * STATIC: A palavra-chave `static` em C e C++ indica que uma variável tem escopo de arquivo,
 * ou seja, ela é visível em todo o arquivo onde foi declarada, mas mantém seu valor entre
 * chamadas consecutivas da função ou do bloco onde foi declarada. Isso significa que, ao
 * contrário de variáveis locais comuns, que são reinicializadas toda vez que a função é chamada,
 * as variáveis `static` preservam seu valor entre essas chamadas, permitindo que um estado
 * persistente seja mantido durante a execução do programa.
 *
 * USO:
 * O modificador `static` é útil quando você precisa de uma variável que mantenha seu valor
 * entre as chamadas de uma função, mas que não precise ser acessada fora dessa função ou do
 * arquivo em que foi declarada. No entanto, o uso de `static` deve ser cuidadoso, pois pode
 * tornar o código mais difícil de entender e de depurar, devido à persistência do valor,
 * o que pode levar a efeitos colaterais inesperados se o estado da variável não for
 * gerenciado corretamente.
 *
 * @note: Variáveis `static` não podem ser usadas como membros de `structs`, pois o armazenamento
 * de membros de `struct` deve ser alocado de forma consistente, o que contraria o comportamento de
 * persistência de uma variável `static`.
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
 *
 * @note A primeira vez que `estatico()` for chamada, `a` será 5. Na segunda vez, será 6,
 * e assim por diante. Isso acontece porque a variável `a` é preservada entre as chamadas,
 * mantendo seu valor.
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
