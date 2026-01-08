#include <stdio.h>
#include <stdlib.h>

/**
 * Abs (absolute): O valor absoluto ou módulo de um número real 'a', denotado por |a|,
 * é definido como a distância de a até 0.
 */

/**
 * SINTAXE: int abs(int _X);
 *
 * @param _X Valor int
 * @return O valor absoluto de _X
 * ---------------------------------------
 * @brief Calcula o valor absoluto de um número inteiro.
 *
 * Esta função usa a função `abs` para calcular o valor absoluto de um número inteiro.
 *
 * @param absInt O valor inteiro para o qual o valor absoluto será calculado.
 * @return O valor absoluto de `absInt`.
 *
 */
int absoluteInt(int absInt) { return abs(absInt); }

/**
 * labs(): É utilizada para calcular o valor absoluto de um número longo (long).
 *
 * SINTAXE: long labs(long _X);
 *
 * @param _X Valor long
 * @return O valor absoluto de _X
 * ---------------------------------------
 * @brief Calcula o valor absoluto de um número longo.
 *
 * Esta função usa a função `labs` para calcular o valor absoluto de um número longo.
 *
 * @param absLong O valor long para o qual o valor absoluto será calculado.
 * @return O valor absoluto de `absLong`.
 */
long absoluteLong(long absLong)
{
    /* Calcula o valor absoluto usando labs */
    long int valorAbsolutoDeLong = labs(absLong);
    return valorAbsolutoDeLong;
}

/**
 * labs(): É utilizada para calcular o valor absoluto de um número longo (long long).
 *
 * SINTAXE: long long labs(long long _X);
 *
 * @param _X Valor long long
 * @return O valor absoluto de _X
 * ---------------------------------------
 * @brief Calcula o valor absoluto de um número longo longo.
 *
 * Esta função usa a função `llabs` para calcular o valor absoluto de um número longo longo.
 * @param absLongLong O valor longo longo para o qual o valor absoluto será calculado.
 * @return O valor absoluto de `absLongLong`.
 */
long long absoluteLongLong(long long absLongLong)
{
    /* Calcula o valor absoluto usando llabs */
    long long valorAbsolutoDeLongLong = llabs(absLongLong);
    return valorAbsolutoDeLongLong;
}

int main(int argc, char **argv)
{
    printf("VALOR ABSOLUTO DE (6) e: %d\n", absoluteInt(6));     // |6| = 6
    printf("VALOR ABSOLUTO DE (-14) e: %d\n", absoluteInt(-14)); // |-14| = −(−14) = 14

    long int numeroLong = -987654321L;
    printf("O valor absoluto de %ld = %ld\n", numeroLong, absoluteLong(numeroLong));

    long long numeroLongLong = 564854LL;
    printf("O valor absoluto de %lld = %lld\n", numeroLongLong, absoluteLongLong(numeroLongLong));
    return 0;
}
