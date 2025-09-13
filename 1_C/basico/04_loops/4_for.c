#include <stdio.h>

/**
 * FOR: O `for` é uma estrutura de controle de fluxo utilizada para repetir um bloco
 * de código um número específico de vezes. Ele é particularmente útil quando sabemos de
 * antemão quantas iterações o loop precisa realizar, ou quando precisamos percorrer uma
 * sequência de valores (como em arrays, listas ou intervalos).
 *
 * SINTAXE:
 * for (inicialização; condição; incremento/decremento)
 * {
 *     // instruções
 * }
 *
 * ETAPAS DO FOR
 * 1. **Etapa de Inicialização**:
 *    - Executada **uma vez** no início do loop. Geralmente usada para declarar e inicializar
 *      uma variável de controle.
 *    - Exemplo: `int i = 0;`
 *
 * 2. **Etapa de Condição**:
 *    - Verificada **antes** de cada iteração. Se a condição for verdadeira (`true`),
 *      o código dentro do loop será executado. Se for falsa (`false`), o loop é encerrado.
 *    - Exemplo: `i < 10;`
 *
 * 3. **Etapa de Incremento/Decremento**:
 *    - Executado após cada iteração, geralmente para atualizar a variável de controle.
 *    - Exemplo: `i++`, que aumenta `i` em 1 a cada iteração.
 *    - Você pode usar outras operações de incremento ou decremento, como `i += 2`, `i--`,
 *    ou até mesmo operações aritméticas e bitwise (por exemplo, `i *= 2` ou `i &= 1`).
 *
 * NOTA:
 * - Cada uma das três partes pode ter mais de uma expressão, separada por vírgulas.
 * - As partes do `for` podem ser deixadas em branco (por exemplo, sem inicialização
 * ou incremento), o mas é importante garantir que o loop tenha uma condição de parada
 * para evitar loops infinitos.
 * - O `for` é ideal para situações em que o número de iterações é conhecido ou é facilmente
 *   determinado (como percorrer arrays ou realizar cálculos repetitivos).
 */

int main(int argc, char **argv)
{
    printf("\n\t>>FOR SIMPLES<<\n");

    // equivalente a for(int i = 0; i < 5; ++i ou i++), enquanto o valor não
    // for menor que 5, atualize `i`.
    for (int i = 0; i < 5; i = i + 1)
        printf("variavel i: %d\n", i);

    /**
     * @note Assim como if, while, o for caso apresente uma instrução de código, não precisa das
     * chaves mas como aconselhado é importante deixa-lo.
     */

    printf("\n====================================================\n");
    printf("\n\t>>EXEMPLO USANDO FOR<<\n");

    int a = 4;
    int b = 5;
    int c = (a <= b) && (b != a);
    // Com a varíavel 'a' e 'b' declaradas, não precisa declarar na etapa de inicialização.
    // Com a varíavel 'c' já declarada com uma condição, só precisamos dele na etapa de condicionaal.

    // for (int a = 4, b = 5; (a <= b) && (b != a); ) for com as etapas de inicialização
    for (; c;)
    {
        printf("(a <= b) && (b != a) : %d\n", c);
        break;
        /*
         * Utilizarmos o break, pois analisando a condição da variável c seu resultado
         * é true o loop funciona se for true e como não tem nenhuma etapa que
         * atualize (incremente) a, e muito menos na etapa da condição possuímos um valor
         * que ele deva ir para chegar seu fim ele irá ficar em loop infinito, e com isso
         * temos o break para forçar o fechamento do loop.
         */
    }

    printf("\n====================================================\n");
    printf("\n\t>>FOR COM MULTIPLOS CASO<<\n");

    // Inicializa 'up' com 1.0 e 'down' com 10.0
    // Condição de continuação: 'up' deve ser menor ou igual a 10.0 e 'down' deve ser
    // maior ou igual a 1.0. Atualização: incrementa 'up' e decrementa 'down'
    for (double up = 1.0, down = 10.0; up <= 10.0 && down >= 1.0; up++, down--)
    {
        printf(" SUBINDO: %.1lf \t\t DESCENDO: %.1lf\n", up, down);
    }

    printf("\n====================================================\n");
    printf("\n\t>>FOR ANINHADO<<\n");

    // Loop externo que controla o número de linhas do padrão. Começa em 5 e decrementa até 1.
    for (int i = 5; i >= 1; i--)
    {
        // Loop interno que controla o número de estrelas a serem impressas em cada linha.
        // Vai de 1 até o valor atual de 'i'.
        for (int j = 1; j <= i; j++)
        {
            printf("* "); // Imprime um asterisco seguido por um espaço.
                          // Este é o conteúdo da linha atual.
        }

        // Após o loop interno, imprime uma nova linha para iniciar a próxima linha do padrão.
        printf("\n");
    }

    printf("\n====================================================\n");
    printf("\n\t>>FOR QUE GERA LOOP<<\n");

    // for sem suas condições gera um loop infinito
    for (;;)
    {
        printf("LOOP\n");
        break; // Programa encerrado com return 0, break ou goto.
    }
    return 0;
}
