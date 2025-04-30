#include <stdio.h>
#include <string.h>

/**
 * RECURSÃO:
 * A recursão é uma técnica onde uma função chama a si mesma para resolver um problema.
 * Isso  pode ser útil quando um problema pode ser dividido em subproblemas menores de
 * forma semelhante ao original.
 * Em termos simples, uma função recursiva divide o problema em partes menores e resolve
 * essas partes de forma repetida até que um caso base seja atingido, ou seja, um cenário
 * simples onde o problema pode ser resolvido diretamente.
 *
 * COMO FUNCIONA:
 * Caso Base: A recursão sempre precisa de um ponto de parada, que é o chamado "caso base".
 * Esse é o momento em que a função não chama mais a si mesma. Sem esse caso base, a função
 * ficaria chamando a si mesma infinitamente, o que causaria um estouro de pilha (stack overflow).
 *
 * Chamada Recursiva: A função chama a si mesma, mas com parâmetros diferentes,
 * geralmente reduzindo o problema até que atinja o caso base.
 */

/**
 * @brief Função recursiva para imprimir os `n` números consecutivos
 *        pares ou ímpares, dependendo se `n` é par ou ímpar.
 *
 * A função recursiva imprime os `n` números consecutivos pares ou ímpares,
 * dependendo se o número `n` é par ou ímpar. A cada chamada recursiva,
 * decrementa `n` em 2 até que `n` seja menor ou igual a 0, quando a recursão termina.
 *
 * @param n O número para o qual a função será chamada.
 */
void recursao(int n)
{
    if (n <= 0)
    {
        return;
    }

    printf("%d ", n);
    recursao(n - 2);
}

/**
 * @brief Função recursiva que imprime números repetidos.
 *
 * A função imprime o número `n` e depois chama a si mesma duas vezes com
 * o valor `n - 1`.
 *
 * @param n O número inicial para impressão.
 */
void fun(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        fun(n - 1);
        fun(n - 1);
    }
}

/**
 * @brief Função recursiva para inverter uma string.
 *
 * A função inverte os caracteres da string entre os índices `inicio` e `fim`.
 *
 * @param str A string a ser invertida.
 * @param inicio O índice inicial da string.
 * @param fim O índice final da string.
 */
void function(char *str, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return;
    }

    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;

    function(str, inicio + 1, fim - 1);
}

int main(int argc, char **argv)
{
    // Teste com o número 5 para a função recursiva de números decrescentes
    recursao(5);

    printf("\n--------------------------------------\n");

    // Teste com o número 3 para a função recursiva de impressão repetida
    fun(3);

    printf("\n--------------------------------------\n");

    // Teste com a função de inversão de string
    char str[] = "Hello";
    printf("Antes de inverter: %s\n", str);
    function(str, 0, strlen(str) - 1);
    printf("Depois de inverter: %s\n", str);

    return 0;
}
