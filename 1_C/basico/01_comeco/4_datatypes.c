#include <stdio.h>
#include <stdbool.h> // Arquivo que fornece a chamada do tipo de dado bool (booleano)
#include <limits.h>  // Obtém as constantes de precisão para tipos de dados inteiros
#include <float.h>   // Obtém as constantes de precisão para tipos de dados flutuantes

// Datatypes (tipos de dados): São declarações que entregam uma certa quantidade de
// precisão de valores, além de ocuparem uma certa quantidade de memória em bytes na
// memória da máquina.

int main(int argc, char **argv)
{
    printf("\n\t>> EXIBINDO TAMANHO DE BYTES DE CADA TIPO DE DADO <<\n");

    // SIZEOF: (Tamanho de/do): retorna o número de bytes que um tipo de dado ocupa na memória
    printf("\n>> TAMANHO EM BYTES DOS TIPOS INTEIROS <<\n");
    printf("\n================================================================================\n");

    printf(" %-30s : %2zu bytes\n", "INT",              sizeof(int));
    printf(" %-30s : %2zu bytes\n", "SIGNED",           sizeof(signed));
    printf(" %-30s : %2zu bytes\n", "SIGNED SHORT",     sizeof(signed short));
    printf(" %-30s : %2zu bytes\n", "SIGNED LONG",      sizeof(signed long));
    printf(" %-30s : %2zu bytes\n", "SIGNED LONG LONG", sizeof(signed long long));
    printf(" %-30s : %2zu bytes\n", "SHORT",            sizeof(short));

    printf(" %-30s : %2zu bytes\n", "UNSIGNED",           sizeof(unsigned));
    printf(" %-30s : %2zu bytes\n", "UNSIGNED SHORT",     sizeof(unsigned short));
    printf(" %-30s : %2zu bytes\n", "UNSIGNED LONG",      sizeof(unsigned long));
    printf(" %-30s : %2zu bytes\n", "UNSIGNED LONG LONG", sizeof(unsigned long long));

    printf(" %-30s : %2zu bytes\n", "LONG", sizeof(long));
    printf(" %-30s : %2zu bytes\n", "LONG LONG", sizeof(long long));

    printf("\n================================================================================\n");
    printf("\n\t>> TAMANHO EM BYTES DOS TIPOS FLOAT E DOUBLE <<\n\n");

    printf(" %-30s : %2zu bytes\n", "FLOAT",       sizeof(float));
    printf(" %-30s : %2zu bytes\n", "DOUBLE",      sizeof(double));
    printf(" %-30s : %2zu bytes\n", "LONG DOUBLE", sizeof(long double));

    printf("\n================================================================================\n");
    printf("\n\t>> TAMANHO EM BYTES DOS TIPOS CHAR <<\n\n");

    printf(" %-30s : %2zu byte\n", "CHAR",          sizeof(char));
    printf(" %-30s : %2zu byte\n", "SIGNED CHAR",   sizeof(signed char));
    printf(" %-30s : %2zu byte\n", "UNSIGNED CHAR", sizeof(unsigned char));

    printf("\n================================================================================\n");

    printf("\n\t>> TAMANHO EM BYTES DE OUTROS TIPOS <<\n\n");

    printf(" %-30s : %2zu byte\n", "BOOL",   sizeof(bool));
    printf(" %-30s : %2zu byte\n", "SIZE_T", sizeof(size_t));

    printf("\n================================================================================\n");
    printf("\n\t>> DESCOBRINDO LIMITE MÁXIMO DE CADA TIPO DE DADO <<\n\n");

    printf("\n>> RANGE MÁXIMO TIPO CHAR <<\n");
    printf("--------------------------------------------------------------------------------\n");

    printf(" %-25s : %20d  |  %-20d\n", "CHAR",          CHAR_MAX,  CHAR_MIN);
    printf(" %-25s : %20d  |  %-20d\n", "SIGNED CHAR",   SCHAR_MAX, SCHAR_MIN);
    printf(" %-25s : %20u\n",           "UNSIGNED CHAR", UCHAR_MAX);

    printf("\n================================================================================\n");
    printf("\n\t>> RANGE MÁXIMO DO TIPO INT, SIGNED E LONG <<\n\n");
    printf("--------------------------------------------------------------------------------\n");

    printf(" %-25s : %20d  |  %-20d\n",     "INT",              INT_MAX,   INT_MIN);
    printf(" %-25s : %20d  |  %-20d\n",     "SHORT",            SHRT_MAX,  SHRT_MIN);
    printf(" %-25s : %20ld  |  %-20ld\n",   "LONG",             LONG_MAX,  LONG_MIN);
    printf(" %-25s : %20lld  |  %-20lld\n", "SIGNED LONG LONG", LLONG_MAX, LLONG_MIN);
    printf(" %-25s : %20lld  |  %-20lld\n", "LONG LONG",        LLONG_MAX, LLONG_MIN);

    printf("\n================================================================================\n");
    printf("\n\t>> RANGE MÁXIMO DO TIPO INT UNSIGNED <<\n\n");
    printf("--------------------------------------------------------------------------------\n");

    printf(" %-25s : %20u\n",   "UNSIGNED INT",       UINT_MAX);
    printf(" %-25s : %20lu\n",  "UNSIGNED LONG",      ULONG_MAX);
    printf(" %-25s : %20llu\n", "UNSIGNED LONG LONG", ULLONG_MAX);
    printf(" %-25s : %20u\n",   "UNSIGNED SHORT",     USHRT_MAX);

    printf("\n================================================================================\n");
    printf("\n\t>> RANGE MÁXIMO DO TIPO DOUBLE E FLOAT <<\n\n");
    printf("--------------------------------------------------------------------------------\n");

    printf(" %-20s : %-15g  |  %-15g\n",   "FLOAT",       FLT_MAX,  FLT_MIN);
    printf(" %-20s : %-15g  |  %-15g\n",   "DOUBLE",      DBL_MAX,  DBL_MIN);
    printf(" %-20s : %-15LE  |  %-15LE\n", "LONG DOUBLE", LDBL_MAX, LDBL_MIN);

    /**
     * @note Lembrando que esses limites (ranges) podem variar de acordo com
     * o sistema operacional, dependendo se ele é de 32 ou 64 bits.
     */

    printf("\n================================================================================\n");

    return 0;
}
