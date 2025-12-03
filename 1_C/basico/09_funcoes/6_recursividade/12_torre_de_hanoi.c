#include <stdio.h>

/**
 * Este programa imprime todos os passos necessários para mover
 * uma pilha de discos de um pino de origem para um pino de destino,
 * utilizando um pino auxiliar, seguindo as regras clássicas:
 *
 * - apenas um disco pode ser movido por vez
 * - um disco maior nunca pode ficar sobre um disco menor
 */

/**
 * @brief Resolve recursivamente a Torre de Hanói.
 *
 * A função opera da seguinte forma:
 *
 * - Caso base: se há apenas 1 disco, move diretamente.
 * - Caso geral:
 *      1. Move os (n-1) discos superiores para o pino auxiliar.
 *      2. Move o disco restante para o pino de destino.
 *      3. Move os (n-1) discos do auxiliar para o destino.
 *
 * @param num       Quantidade de discos a mover.
 * @param from_peg  Pino de origem dos discos.
 * @param to_peg    Pino de destino dos discos.
 * @param aux_peg   Pino auxiliar usado na recursão.
 */
void torre(int num, char from_peg, char to_peg, char aux_peg)
{
    // Caso base: se só tem 1 disco, move diretamente
    if (num == 1)
    {
        printf("Mova o disco 1 do pino %c para o pino %c\n", from_peg, to_peg);
        return;
    }

    // Passo 1: mover n-1 discos do pino origem para o auxiliar
    torre(num - 1, from_peg, aux_peg, to_peg);

    // Passo 2: mover o disco maior (n) da origem para o destino
    printf("Mova o disco %d do pino %c para o pino %c\n", num, from_peg, to_peg);

    // Passo 3: mover os n-1 discos do auxiliar para o destino
    torre(num - 1, aux_peg, to_peg, from_peg);
}

int main(int argc, char **argv)
{
    int n = 3; // Número de discos da Torre de Hanói

    printf("Passos para resolver a Torre de Hanói com %d discos:\n\n", n);
    torre(n, 'A', 'C', 'B'); // A = origem, C = destino, B = auxiliar
    return 0;
}
