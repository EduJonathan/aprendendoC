#include <stdio.h>

/*
 * Bitwise (bit a bit): São operadores que manipulam os valores binários das variáveis.
 * Ao contrário dos operadores lógicos que operam com valores booleanos, os operadores bitwise
 * atuam diretamente nos bits das variáveis. A seguir estão os operadores bitwise comuns:
 *
 * +------------+--------------------+
 * | OPERADORES |       NOMES        |
 * +------------+--------------------+
 * |    &       | AND (E)            |
 * +------------+--------------------+
 * |    |       | OR INCLUSIVO (OU)  |
 * +------------+--------------------+
 * |    ^       | XOR EXCLUSIVO (OU) |
 * +------------+--------------------+
 * |    ~       | NOT (NÃO)          |
 * +------------+--------------------+
 * |    >>      | RIGHT SHIFT        |
 * +------------+--------------------+
 * |    <<      | LEFT SHIFT         |
 * +------------+--------------------+
 */

int main(int argc, char **argv)
{
    printf("\n==============================================================\n");
    printf("\n\t>>OPERADORES BITWISE<<\n");

    int aux1 = 6; /* 6 na representação binária é 000110 */
    int aux2 = 3; /* 3 na representação binária é 000011 */

    printf("\n>>OPERADOR (&) AND: ");
    /*
     * O operador AND (&) compara cada bit de dois números. Ele retorna 1 apenas quando
     * ambos os bits forem 1. Caso contrário, o resultado será 0.
     * Sua tabela verdade:
     *
     * +---------+---------+-------+
     * | valor x | valor y | x & y |
     * +---------+---------+-------+
     * |   0     |   0     |   0   |
     * +---------+---------+-------+
     * |   0     |   1     |   0   |
     * +---------+---------+-------+
     * |   1     |   0     |   0   |
     * +---------+---------+-------+
     * |   1     |   1     |   1   |
     * +---------+---------+-------+
     */

    int and_result = aux1 & aux2;
    //   000110 (6)
    // & 000011 (3)
    // _____________
    //   000010 (2)
    printf("O VALOR DA OPERAÇÃO DA VARIÁVEL 'and_result' É : %d\n", and_result);

    printf("\n--------------------------------------------------------------\n");
    printf("\n>>OPERADOR (|) OR: ");
    /*
     * O operador OR (|) compara os bits de dois números. Ele retorna 1 quando
     * pelo menos um dos bits é 1. Caso contrário, o resultado será 0.
     * Sua tabela verdade:
     *
     * +---------+---------+-------+
     * | valor x | valor y | x | y |
     * +---------+---------+-------+
     * |   0     |   0     |   0   |
     * +---------+---------+-------+
     * |   0     |   1     |   1   |
     * +---------+---------+-------+
     * |   1     |   0     |   1   |
     * +---------+---------+-------+
     * |   1     |   1     |   1   |
     * +---------+---------+-------+
     */

    int or_result = aux1 | aux2;
    //   000110 (6)
    // | 000011 (3)
    // _____________
    //   000111 (7)
    printf("O VALOR DA OPERAÇÃO DA VARIÁVEL 'or_result' É : %d\n", or_result);

    printf("\n--------------------------------------------------------------\n");
    printf("\n>>OPERADOR (^) XOR: ");
    /*
     * O operador XOR (^) retorna 1 quando os bits comparados são diferentes
     * (um é 0 e o outro é 1). Se ambos os bits forem iguais, retorna 0:
     *
     * +---------+---------+-------+
     * | valor x | valor y | x ^ y |
     * +---------+---------+-------+
     * |   0     |   0     |   0   |
     * +---------+---------+-------+
     * |   0     |   1     |   1   |
     * +---------+---------+-------+
     * |   1     |   0     |   1   |
     * +---------+---------+-------+
     * |   1     |   1     |   0   |
     * +---------+---------+-------+
     */

    int xor_result = aux1 ^ aux2;
    //   000110 (6)
    // ^ 000011 (3)
    // _____________
    //   000101 (5)
    printf("O VALOR DA OPERAÇÃO DA VARIÁVEL 'xor_result' É : %d\n", xor_result);

    printf("\n--------------------------------------------------------------\n");

    printf("\n>>OPERADOR (~) NOT: ");
    /**
     * O operador NOT (~) inverte todos os bits de um número. Isso significa que
     * ele transforma 1 em 0 e 0 em 1. Para números inteiros, esse operador utiliza
     * a representação em complemento de dois.
     */
    int aux3 = 10;          /* 10 na representação binária é 001010 */
    int not_result = ~aux3; // Inverte os bits
    //  ~001010 (10)
    // _____________
    //  ~110101 (-11)
    printf("O VALOR DA OPERAÇÃO DA VARIÁVEL 'not_result' É : %d\n", not_result);

    printf("\n=======================================================================\n");
    printf("\n>>OPERADOR (>>) RIGHT-SHIFT: ");
    /*
     * (>>): O operador de deslocamento à direita move todos os bits para a direita,
     * descartando os bits mais à direita e preenchendo as posições vazias com 0.
     * Cada deslocamento à direita é equivalente a uma divisão por 2.
     */

    int right_shift_result = 0;
    int right = 44; // 44 = 00101100 (em binário)
    right_shift_result = right >> 2;
    /*
     * 00101100 >> 2 (deslocando 2 para a direita)
     * 00001011 = (11)
     */
    printf("O VALOR DA VARIÁVEL 'right_shift_result' DESLOCADA PARA 2 DIREITA É : %d\n", right_shift_result);

    printf("\n-----------------------------------------------------\n");

    printf("\n>>OPERADOR (<<) LEFT-SHIFT: ");
    /*
     * (<<): O operador de deslocamento à esquerda move todos os bits para a esquerda,
     * e as posições desocupadas à direita são preenchidas com 0.
     * Cada deslocamento à esquerda é equivalente a uma multiplicação por 2.
     */

    int left_shift_result = 0;
    int left = 44; // 44 = 00101100 (em binário)
    left_shift_result = left << 2;
    /*
     * 00101100 << 2 (deslocando 2 para a esquerda)
     * 10110000 = (176)
     */
    printf("O VALOR DA VARIÁVEL 'left_shift_result' DESLOCADA PARA 2 ESQUERDA É : %d\n", left_shift_result);

    // Expressões utilizando operadores bitwise
    printf("\n========================================================================\n");
    printf("\n\t>>EXPRESSÃO UTILIZANDO OPERADORES BITWISE<<\n");

    int x = 7;
    int y = 4;
    int z = 23;
    int w = 5;

    int expressao_bitwise = (x & y) | (w ^ z);
    int expressao_bitwise1 = ~(x & y) | ~~(y ^ w);
    int expressao_bitwise2 = ((x & y) | (z << 2)) ^ (~w);

    // Resultados das expressões
    printf(" O VALOR DA 'expressão_bitwise'  É = %d\n", expressao_bitwise);
    printf(" O VALOR DA 'expressão_bitwise1' É = %d\n", expressao_bitwise1);
    printf(" O VALOR DA 'expressão_bitwise2' É = %d\n", expressao_bitwise2);

    return 0;
}
