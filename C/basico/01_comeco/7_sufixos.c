#include <stdio.h>

/**
 * @brief Sufixos para identificação do tipo de dados de uma constante literal.
 *
 * Sufixos são utilizados para especificar explicitamente o tipo de dado de uma constante literal.
 * Isso é útil em situações onde o tipo da constante não pode ser automaticamente inferido pelo
 * compilador, especialmente quando lidamos com literais numéricos de diferentes tipos, como
 * inteiros e floats.
 * Por exemplo, o sufixo `U` pode ser usado para definir um valor como `unsigned`, 
 * e o sufixo `L` pode indicar que o valor é `long`.
 *
 * @note O uso de sufixos é importante para garantir a precisão do tipo e evitar problemas 
 * de tipo durante a compilação, como a promoção implícita de tipos.
 */

int main(int argc, char **argv)
{
    printf("\n\t>>SUFIXOS<<\n");

    printf("\n=========================================================\n");
    printf("\n\t==>TIPOS INTEIROS<==\n");

    unsigned int numeroSemSinal = 42U;
    // ou unsigned int numeroSemSinal = 42u;

    unsigned long outroNumeroLongo = 5678UL;
    // ou long numeroLongo = 5678ul;

    long numeroLongo = 1234L;
    // ou long numeroLongo = 1234l;

    long long numeroMuitoLongo = 123456789LL;
    // ou long long numeroMuitoLongo = 123456789ll;

    unsigned long long outroNumeroMuitoLongo = 987654321ULL;
    // ou unsigned long long outroNumeroMuitoLongo = 987654321ull;

    printf(" Unsigned int       : %u\n", numeroSemSinal);
    printf(" Long               : %ld\n", numeroLongo);
    printf(" Unsigned long      : %lu\n", outroNumeroLongo);
    printf(" Long long          : %lld\n", numeroMuitoLongo);
    printf(" Unsigned long long : %llu\n", outroNumeroMuitoLongo);

    printf("\n=========================================================\n");
    printf("\n\t==>HEXADECIMAIS, OCTAIS E BINÁRIOS<==\n");

    // valor mínimo para um inteiro de 32 bits. Em notação decimal o valor é -2147483648U.
    int hexa = 0X80000000;
    printf(" Hexa : 0x%X\n", hexa);
    printf(" Hexa : %d\n", hexa);

    // Literal hexadecimal que representa o número 171 em decimal.
    // Em hexadecimal, 0xAB é 171 em decimal.
    int numeroHexadecimal = 0xAB;
    printf(" Hexadecimal : 0x%X\n", numeroHexadecimal);
    printf(" Hexadecimal : 0x%d\n", numeroHexadecimal);

    // literal octal que representa o número 61 em decimal. Em octal, 075 é 61 em decimal.
    // O prefixo 0 indica que o número seguinte está em octal.
    int numeroOctal = 075;
    printf(" Octal : 0%o\n", numeroOctal);
    printf(" Octal : 0%d\n", numeroOctal);

    // Este é um literal binário que representa o número 10 em decimal.
    // Em binário, O '0b' indica que o número seguinte está em binário.
    int numeroBinario = 0b1010;
    printf(" Binário : 0b%d\n", numeroBinario);

    // Este é um literal hexadecimal sem sinal que representa o número 171 em decimal.
    unsigned int numeroHexSemSinal = 0xABu;
    printf(" Hexadecimal sem sinal : 0x%X\n", numeroHexSemSinal);
    printf(" Hexadecimal sem sinal : 0x%d\n", numeroHexSemSinal);

    printf("\n=========================================================\n");
    printf("\n\t==>PONTOS FLUTUANTES<==\n");

    // ou float numeroFlutuante = 3.14f;
    float numeroFlutuante = 3.14F;

    // Os computadores e compiladores atuais já tratam valores de ponto flutuante,
    // como double, sem necessitar de um sufixo
    double Double = 64.78;

    // ou long double numeroDuploPrecisao = 2.718l;
    long double numeroDuploPrecisao = 2.718L;

    printf(" Float       : %f\n", numeroFlutuante);
    printf(" Double      : %lf\n", Double);
    printf(" Long double : %.5Lf\n", numeroDuploPrecisao);

    printf("\n=========================================================\n");
    printf("\n\t==>NOTAÇÃO CIENTÍFICA<==\n");

    // Representa um número em notação científica (float) equivalente a 1.23 * 10^5.
    float numeroCientificoFloat = 1.23e5F;

    // Representa um número em notação científica (double) equivalente a 3.45 * 10^-6.
    double numeroCientificoDouble = 3.45e-6;

    // Representa um número em notação científica (long double) equivalente a 6.789 * 10^3.
    long double numeroCientificoLongDouble = 6.789e3L;

    printf(" Float notação científica       : %e\n", numeroCientificoFloat);
    printf(" Double notação científica      : %e\n", numeroCientificoDouble);
    printf(" Long double notação científica : %Le\n", numeroCientificoLongDouble);
    return 0;
}
