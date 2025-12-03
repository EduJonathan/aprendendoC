#include <stdio.h>
#include <string.h>

/**
 * RECURSÃO:
 * A recursão é uma técnica de programação em que uma função chama a si mesma
 * para resolver um problema. Ela é útil quando esse problema pode ser dividido
 * em subproblemas menores, semelhantes ao original.
 *
 * Em termos simples, uma função recursiva resolve pequenas partes do problema
 * repetidamente até alcançar um caso base — um ponto onde o problema se torna
 * simples o suficiente para ser resolvido diretamente.
 *
 * COMO FUNCIONA:
 * - Caso Base: Toda função recursiva deve ter um caso base, que é a condição
 *   que interrompe as chamadas recursivas. Sem ele, a função continuaria
 *   chamando a si mesma indefinidamente, resultando em um erro conhecido como
 *   "stack overflow" (estouro de pilha).
 *
 * - Chamada Recursiva: É o momento em que a função chama a si mesma, geralmente
 *   com parâmetros reduzidos, aproximando a execução do caso base.
 *
 * CUIDADOS:
 * - Garanta que o caso base sempre seja alcançado, evitando loops infinitos.
 * - Tenha atenção à lógica de retorno e às operações feitas antes e depois
 *   das chamadas recursivas, pois qualquer erro pode gerar resultados
 *   incorretos ou consumo excessivo de memória.
 */

/**
 * @brief Função recursiva que imprime números pares ou ímpares decrescentes.
 *
 * A função imprime o valor atual de `n` e chama a si mesma reduzindo o número
 * em 2. Dessa forma, se `n` for par, serão impressos números pares; se `n`
 * for ímpar, serão impressos números ímpares. A recursão termina quando `n`
 * torna-se menor ou igual a 0.
 *
 * @param n Valor inicial a ser impresso.
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
 * @brief Função recursiva que imprime números em um padrão de árvore binária.
 *
 * A função imprime o número `n` e realiza duas chamadas recursivas com o
 * valor `n - 1`. Isso gera uma estrutura de recursão em forma de árvore,
 * resultando em múltiplas repetições dos mesmos valores.
 *
 * Exemplo da ordem de impressão para n = 3:
 *   3 2 1 1 2 1 1
 *
 * @param n Valor inicial para impressão.
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
 * @brief Função recursiva para inverter uma string in-place.
 *
 * A função troca os caracteres nas posições `inicio` e `fim`, avançando
 * em direção ao centro da string até que `inicio` seja maior ou igual a `fim`,
 * momento em que a recursão é encerrada.
 *
 * @param str A string a ser invertida.
 * @param inicio Índice inicial da troca.
 * @param fim Índice final da troca.
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
