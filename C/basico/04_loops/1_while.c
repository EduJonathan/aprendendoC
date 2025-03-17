#include <stdio.h>
#include <stdbool.h>

/**
 * WHILE: Ou enquanto é uma estrutura de repetição que irá se repetir determinada
 * vezes enquanto a condição for verdadeira. o uso do while depende de quantas vezes
 * até que um evento aconteça.
 *
 * SINTAXE:
 * while (// condição)
 * {
 *    // instrução
 * }
 */

int main(int argc, char **argv)
{
    printf("\n\t>>EXEMPLO 01: WHILE<<\n");

    // Variável numero inicializada
    int numero = 0;

    /*
     * Aqui temos a sintaxe do while, que enquanto o usuário ficar alterando a
     * variável "numero" sempre que for diferente de 1 o laço repete.
     */

    while (numero != 1)
    {
        printf("DIGITE QUALQUER NUMERO DIFERENTE DE 1 :: ");
        scanf("%d", &numero);
    }

    printf("\n====================================================\n");
    printf("\n\t>>EXEMPLO 02: WHILE SIMPLES<<\n");

    int i = 0;

    while (i < 10)
    {
        printf("Contador i é : %d\n", i);
        i++;
    }

    /*
     * No exemplo 2, a variável "i" é inicializada com o valor 0, e a condição "i < 10",
     * é verificada antes de cada iteração. O código dentro do loop imprime o valor de "i"
     * em cada iteração, e o incremento "i++" é executado após cada iteração, e o loop é
     * executado 10 vezes, até que a condição "i < 10" se torne falsa.
     */

    printf("\n====================================================\n");
    printf("\n\t>>EXEMPLO 03: WHILE COM OPERADORES LÓGICOS<<\n");

    int contador = 0;
    int valorMaximo = 10;
    bool condicaoAdicional = true;

    // Loop enquanto o contador for menor que valorMaximo e condicaoAdicional for verdadeira
    while (contador < valorMaximo && condicaoAdicional)
    {
        printf("Contador: %d\n", contador);

        // Simula uma mudança na condicaoAdicional
        if (contador == 5)
        {
            condicaoAdicional = false; // Muda a condição para false
        }
        contador++; // Incrementa o contador
    }

    printf("\n====================================================\n");
    printf("\n\t>>EXEMPLO 04: WHILE ANINHADOS<<\n");

    // Incializando uma variável com valor 8
    int num = 8;

    // O loop externo decrementa 'num' e continua enquanto 'num' não for false(0)
    while (--num)
    {
        printf(" O valor da variável num chegou em : %d\n", num);

        // O loop interno é acionado quando 'num' é menor ou igual a 5
        while (num <= 5)
        {
            // Quebra o loop do while
            break;
        }

        // Enquanto o decremento de num não em maior ou igual a 5
        while (num >= 5)
        {
            // Esta condição não será executada enquanto 'num' estiver decrementando e
            // só será menor que 5 no próximo loop externo
            if (num == 5)
            {
                printf(" O valor da variável num chegou em : %d\n", num);
            }

            // Quebra o loop do while
            break;
        }
    }
    return 0;
}
