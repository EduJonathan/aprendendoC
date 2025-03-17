#include <stdio.h>

/**
 * @brief Troca os valores de duas variáveis inteiras.
 *
 * Esta função troca os valores de duas variáveis inteiras. A troca é feita usando uma
 * variável temporária para armazenar o valor de uma das variáveis durante o processo.
 *
 * @param n1 Primeiro valor inteiro a ser trocado.
 * @param n2 Segundo valor inteiro a ser trocado.
 * @note Os valores das variáveis `n1` e `n2` são alterados apenas localmente dentro da função.
 * Esta função não modifica os valores das variáveis passadas por referência.
 */
void swap(int n1, int n2)
{
    // Armazena o valor de `n1` em uma variável temporária
    int temp = n1;

    // Atribui o valor de `n2` a `n1`
    n1 = n2;

    // Atribui o valor armazenado em `temp` a `n2`
    n2 = temp;

    // Imprime os valores das variáveis após a troca
    // printf("\n\n==>TROCA DE VALORES<==\n");
    // printf("\n NA FUNÇÃO SWAP: n1 = %d\tn2 = %d\n", n1, n2);
}

int main(int argc, char **argv)
{
    // Declaração e inicialização de variáveis
    int x = 30, y = 20;

    // Imprime os valores iniciais
    printf("===>Antes da troca<===\n");
    printf(" x = %d\ty = %d", x, y);

    // Passamos os valores de x e y
    swap(x, y);

    // Imprime os valores depois da troca
    printf("\n===>Depois da troca<===\n");
    printf("\n NA FUNÇÃO MAIN: x = %d\ty = %d", x, y);
    return 0;
}
