#include <stdio.h>

/**
 * INLINE: O modificador `inline` em C e C++ é uma sugestão para o compilador substituir
 * a chamada de uma função pelo próprio código da função. Isso pode ser útil em funções pequenas
 * que são chamadas frequentemente, ajudando a evitar o overhead de chamadas de função e,
 * em alguns casos, melhorando o desempenho, pois elimina o custo de empurrar e puxar dados
 * da pilha durante as chamadas de função.
 *
 * No entanto, o compilador não é obrigado a obedecer a essa sugestão. Se a função for muito
 * grande ou se o compilador decidir que a substituição não trará benefício, ele pode optar
 * por não fazer a substituição.
 *
 * Um exemplo simples:
 *
 * inline int soma(int a, int b) {
 *     return a + b;
 * }
 *
 * IMPORTANTE: O uso excessivo de funções `inline` pode aumentar o tamanho do código binário,
 * pois o código da função é replicado onde quer que seja chamada. Portanto, o uso deve ser
 * equilibrado, com foco em funções pequenas e frequentemente chamadas.
 */

// Definição de uma função inline
inline int soma(int a, int b)
{
    return a + b;
}

int main(int argc, char **argv)
{
    int resultado = soma(3, 5);
    printf("Resultado: %d\n", resultado);
    /**
     * Ao chamar `soma(3, 4)`, o compilador pode substituir a chamada da função pelo código:
     * `return 3 + 4;`, evitando a sobrecarga da chamada de função.
     */
    return 0;
}
