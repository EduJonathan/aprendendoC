#include <stdio.h>

/**
 * Modificador inline em C e C++ sugere ao compilador que substitua a chamada de função
 * pelo próprio código da função, ajudando a evitar o overhead de chamadas de função em
 * determinados casos.
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
    /*
     * O compilador pode substituir soma(3, 5) pelo próprio código da função,
     * eliminando a necessidade de empilhar argumentos e desviar a execução.
     */
    return 0;
}
