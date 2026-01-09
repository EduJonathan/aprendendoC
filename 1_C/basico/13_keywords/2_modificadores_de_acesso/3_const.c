#include <stdio.h>

/**
 * CONST:
 * É um modificador de tipo usado para indicar que uma variável não pode ter seu
 * valor alterado após a inicialização. Uma variável declarada como `const` é tratada
 * como somente leitura, e qualquer tentativa de modificar seu valor resulta em erro
 * de compilação.
 *
 * O uso de `const` ajuda a tornar o código mais seguro, prevenindo alterações
 * acidentais em valores que devem permanecer imutáveis, além de melhorar a clareza
 * e a intenção do programador.
 */

int main(int argc, char **argv)
{
    // Variável constante
    const int num = 78;

    /**
     * Tentar modificar 'num' gera erro de compilação:
     *
     * num = 5;           // Error: assignment of read-only variable
     * scanf("%d", &num); // Error: read-only variable is not assignable
     *
     * Isso acontece porque 'num' é somente leitura.
     */

    printf("Valor de num: %d\n", num);

    /*
     * Também podemos declarar assim:
     *
     * char const str[5] = "Olá";
     *
     * As declarações `const char` e `char const` são equivalentes. Em C, o `const`
     * sempre se aplica ao que está *à sua esquerda*; se não houver nada à esquerda,
     * aplica-se ao que está à direita.
     */
    char const str[5] = "Olá";

    /**
     * str[0] = 'h';  // Erro: não é permitido modificar um array constante.
     *
     * Arrays declarados como const têm todos os seus elementos marcados como somente leitura.
     */

    printf("Valor de str: %s\n", str);

    return 0;
}
