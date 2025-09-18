#include <stdio.h>

/**
 * Sufixos para identificação do tipo de dados de uma constante literal.
 *
 * Sufixos especificam explicitamente o tipo de uma constante literal, garantindo que o
 * compilador a interprete corretamente. Isso evita problemas como promoção implícita de tipos
 * ou estouro de valores. Por exemplo, `42U` indica `unsigned int`, enquanto `123.45L` indica
 * `long double`.
 *
 * Tabela de sufixos e especificadores:
 *
 * Sufixo   | Tipo de Dado            | Especificador no printf()
 * ---------|-------------------------|-------------------------
 * U        | unsigned int            | %u
 * L        | long                    | %ld
 * UL       | unsigned long           | %lu
 * LL       | long long               | %lld
 * ULL      | unsigned long long      | %llu
 * F        | float                   | %f
 * (nenhum) | double                  | %lf ou %f
 * L        | long double             | %Lf
 *
 * @note: Literais binários (0b) são suportados em C11 ou posterior.
 * @note: Sufixos maiúsculos (U, L, LL) são preferidos por convenção, mas minúsculos (u, l, ll) são equivalentes.
 */

int main(int argc, char **argv)
{
    printf("\n\t>>SUFIXOS<<\n");

    printf("\n=========================================================\n");
    printf("\n\t==>TIPOS INTEIROS<==\n");

    unsigned int numeroSemSinal = 42U;
    // ou unsigned int numeroSemSinal = 42u;

    unsigned long outroNumeroLongo = 5678UL;
    // ou unsigned long outroNumeroLongo = 5678ul;

    long numeroLongo = 1234L;
    // ou long numeroLongo = 1234l;

    long long numeroMuitoLongo = 123456789LL;
    // ou long long numeroMuitoLongo = 123456789ll;

    unsigned long long outroNumeroMuitoLongo = 987654321ULL;
    // ou unsigned long long outroNumeroMuitoLongo = 987654321ull;

    printf(" Unsigned int       : %10u\n", numeroSemSinal);
    printf(" Long               : %10ld\n", numeroLongo);
    printf(" Unsigned long      : %10lu\n", outroNumeroLongo);
    printf(" Long long          : %10lld\n", numeroMuitoLongo);
    printf(" Unsigned long long : %10llu\n", outroNumeroMuitoLongo);

    // Exemplo de problema sem sufixo
    printf("\n\t==> EXEMPLO DE PROMOÇÃO DE TIPOS <==\n");

    int x = 3000000000;         // Pode causar estouro em int de 32 bits
    long long y = 3000000000LL; // Correto com sufixo LL

    printf("Sem sufixo (int): %d (comportamento indefinido)\n", x);
    printf("Com sufixo (long long): %lld\n", y);

    printf("\n=========================================================\n");
    printf("\n\t==>HEXADECIMAIS, OCTAIS E BINÁRIOS<==\n");

    // Hexadecimal representando o valor mínimo de int (32 bits). Em notação decimal o valor é -2147483648U.
    int hexa = 0x80000000;
    printf(" Hexa : 0x%X\n", hexa);
    printf(" Hexa (decimal) : %d\n", hexa);

    // Hexadecimal representando 171 em decimal
    int numeroHexadecimal = 0xAB;
    printf(" Hexadecimal : 0x%X\n", numeroHexadecimal);
    printf(" Hexadecimal (decimal) : %d\n", numeroHexadecimal);

    // Octal representando 61 em decimal
    int numeroOctal = 075;
    printf(" Octal : 0%o\n", numeroOctal);
    printf(" Octal (decimal) : %d\n", numeroOctal);

    // Binário representando 10 em decimal (C11 ou posterior)
    int numeroBinario = 0b1010;
    printf(" Binário : 0b%d\n", numeroBinario);

    // Hexadecimal sem sinal
    unsigned int numeroHexSemSinal = 0xABU;
    printf(" Hexadecimal sem sinal : 0x%X\n", numeroHexSemSinal);
    printf(" Hexadecimal sem sinal (decimal) : %u\n", numeroHexSemSinal);

    printf("\n=========================================================\n");
    printf("\n\t==>PONTOS FLUTUANTES<==\n");

    // ou float numeroFlutuante = 3.14f;
    float numeroFlutuante = 3.14F;

    // Os computadores e compiladores atuais já tratam valores de ponto flutuante,
    // como double, sem necessitar de um sufixo
    double numeroDouble = 64.78;

    // ou long double numeroDuploPrecisao = 2.718l;
    long double numeroDuploPrecisao = 2.718L;

    printf(" Float       : %10.2f\n", numeroFlutuante);
    printf(" Double      : %10.2lf\n", numeroDouble);
    printf(" Long double : %10.5Lf\n", numeroDuploPrecisao);

    printf("\n=========================================================\n");
    printf("\n\t==>NOTAÇÃO CIENTÍFICA<==\n");

    // Notação científica: <mantissa>e<expoente> significa mantissa * 10^expoente
    // Representa um número em notação científica (float) equivalente a 1.23 * 10^5.
    float numeroCientificoFloat = 1.23e5F;

    // Representa um número em notação científica (double) equivalente a 3.45 * 10^-6.
    double numeroCientificoDouble = 3.45e-6;

    // Representa um número em notação científica (long double) equivalente a 6.789 * 10^3.
    long double numeroCientificoLongDouble = 6.789e3L;

    printf(" Float notação científica       : %10.2e\n", numeroCientificoFloat);
    printf(" Double notação científica      : %10.2e\n", numeroCientificoDouble);
    printf(" Long double notação científica : %10.2Le\n", numeroCientificoLongDouble);
    return 0;
}
