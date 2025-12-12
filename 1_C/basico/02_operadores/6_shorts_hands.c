#include <stdio.h>

/*
 * SHORT HANDS (Operadores de atribuição combinada):
 * São formas simplificadas de realizar operações diretamente sobre variáveis,
 * aplicando a operação e atribuindo o resultado à mesma variável em uma única instrução.
 *
 * Eles são bastante comuns tanto em operações aritméticas quanto em operações
 * bit a bit (bitwise), tornando o código mais enxuto e legível.
 *
 * +-------------------------------+---------------------------+
 * |    OPERADORES ARITMÉTICOS     |   OPERADORES BITWISE      |
 * +-------------------------------+---------------------------+
 * |         +=   (soma)           |       &=   (E bit a bit)  |
 * |         -=   (subtração)      |       |=   (OU bit a bit) |
 * |         *=   (multiplicação)  |       ^=   (XOR)          |
 * |         /=   (divisão)        |       >>=  (desloca dir.) |
 * |         %=   (resto)          |       <<=  (desloca esq.) |
 * +-------------------------------+---------------------------+
 */

int main(int argc, char **argv)
{
    printf("\n\t>>SHORTS-HANDS<<\n");

    printf("\nSHORT_HAND (+=): ");
    int short_soma = 5;
    short_soma += 5;
    // short_soma = short_soma + 5;
    // short_soma = 5 + 5
    // short_soma = 10;
    printf(" O VALOR DA VARIÁVEL 'short_soma' É : %d\n", short_soma);

    printf("\nSHORT_HAND (-=): ");
    int short_sub = 5;
    short_sub -= 9;
    // short_sub = short_sub - 9;
    // short_sub = 5 - 9
    // short_sub = -4;
    printf(" O VALOR DA VARIÁVEL 'short_sub' É : %d\n", short_sub);

    printf("\nSHORT_HAND (*=): ");
    int short_mult = 6;
    short_mult *= short_soma;
    // short_mult = short_mult * short_soma;
    // short_mult = 6 * 10
    // short_mult = 60;
    printf(" O VALOR DA VARIÁVEL 'short_mult' É : %d\n", short_mult);

    printf("\nSHORT_HAND (/=): ");
    int short_div = 10;
    short_div /= 5;
    // short_div = short_div / 5;
    // short_div = 10 / 5
    // short_div = 2;
    printf(" O VALOR DA VARIÁVEL 'short_div' É : %d\n", short_div);

    printf("\nSHORT_HAND (%%=): ");
    int short_mod = 5;
    short_mod %= 5;
    // short_mod = short_mod % 5;
    // short_mod = 5 % 5
    // short_mod = 0;
    printf(" O VALOR DA VARIÁVEL 'short_mod' É : %d\n", short_mod);

    printf("\n==============================================================\n");
    printf("\n\t>>SHORT HANDS PARA OPERADORES BITWISE<<\n");

    printf("\nSHORT_HAND (&=): ");
    int short_hand_result = 10;
    short_hand_result &= 2;
    // short_hand_result = short_hand_result & 2;
    // 10 = 001010
    // & 2 = 000010
    // ---------------
    // Resultado: 000010 = 2
    printf("O VALOR DA VARIÁVEL 'short_hand_result' É : %d\n", short_hand_result);

    printf("\nSHORT_HAND (|=): ");
    int or_hand_result = 5;
    or_hand_result |= 3;
    // or_hand_result = or_hand_result | 3;
    // 5 = 000101
    // | 3 = 000011
    // ---------------
    // Resultado: 000111 = 7
    printf("O VALOR DA VARIÁVEL 'or_hand_result' É : %d\n", or_hand_result);

    printf("\nSHORT_HAND (^=): ");
    int xor_hand_result = 10;
    xor_hand_result ^= 6;
    // xor_hand_result = xor_hand_result ^ 6;
    // 10 = 001010
    // ^ 6 = 000110
    // ---------------
    // Resultado: 001100 = 12
    printf("O VALOR DA VARIÁVEL 'xor_hand_result' É : %d\n", xor_hand_result);

    printf("\nRIGHT_SHIFT_HAND (>>=): ");
    int right_shift_hand_result = 30;
    right_shift_hand_result >>= 3;
    // right_shift_hand_result = right_shift_hand_result >> 3;
    // 30 = 00011110
    // >> 3
    // ---------------
    // Resultado: 00000011 = 3
    // Shift de 3 bits para a direita
    printf("O VALOR DA VARIÁVEL 'right_shift_hand_result' É : %d\n", right_shift_hand_result);

    printf("\nLEFT_SHIFT_HAND (<<=): ");
    int left_shift_hand_result = 20;
    left_shift_hand_result <<= 2;
    // left_shift_hand_result = left_shift_hand_result << 2;
    // 20 = 00010100
    // << 2
    // ---------------
    // Resultado: 01010000 = 80
    // Shift de 2 bits para a esquerda
    printf("O VALOR DA VARIÁVEL 'left_shift_hand_result' É : %d\n", left_shift_hand_result);
    return 0;
}
