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
    printf("\n\t>> TAMANHO EM BYTES DOS TIPOS INTEIROS <<\n");
    printf("\n=================================================================\n");

    printf(" QUANTIDADE DE BYTES DO TIPO INT              : %zu bytes\n", sizeof(int));
    printf(" QUANTIDADE DE BYTES DO TIPO SIGNED           : %zu bytes\n", sizeof(signed));
    printf(" QUANTIDADE DE BYTES DO TIPO SIGNED SHORT     : %zu bytes\n", sizeof(signed short));
    printf(" QUANTIDADE DE BYTES DO TIPO SIGNED LONG      : %zu bytes\n", sizeof(signed long));
    printf(" QUANTIDADE DE BYTES DO TIPO SIGNED LONG LONG : %zu bytes\n", sizeof(signed long long));
    printf(" QUANTIDADE DE BYTES DO TIPO SHORT            : %zu bytes\n", sizeof(short));

    printf(" QUANTIDADE DE BYTES DO TIPO UNSIGNED         : %zu bytes\n", sizeof(unsigned));
    printf(" QUANTIDADE DE BYTES DO TIPO UNSIGNED SHORT   : %zu bytes\n", sizeof(unsigned short));
    printf(" QUANTIDADE DE BYTES DO TIPO UNSIGNED LONG    : %zu bytes\n", sizeof(unsigned long));
    printf(" QUANTIDADE DE BYTES DO TIPO UNSIGNED LONG LONG : %zu bytes\n", sizeof(unsigned long long));

    printf(" QUANTIDADE DE BYTES DO TIPO LONG             : %zu bytes\n", sizeof(long));
    printf(" QUANTIDADE DE BYTES DO TIPO LONG LONG        : %zu bytes\n", sizeof(long long));

    printf("\n=================================================================\n");
    printf("\n\t>> TAMANHO EM BYTES DOS TIPOS FLOAT E DOUBLE <<\n");

    printf(" QUANTIDADE DE BYTES DO TIPO FLOAT            : %zu bytes\n", sizeof(float));
    printf(" QUANTIDADE DE BYTES DO TIPO DOUBLE           : %zu bytes\n", sizeof(double));
    printf(" QUANTIDADE DE BYTES DO TIPO LONG DOUBLE      : %zu bytes\n", sizeof(long double));

    printf("\n=================================================================\n");
    printf("\n\t>> TAMANHO EM BYTES DOS TIPOS CHAR <<\n");

    printf(" QUANTIDADE DE BYTES DO TIPO CHAR             : %zu byte\n", sizeof(char));
    printf(" QUANTIDADE DE BYTES DO TIPO SIGNED CHAR      : %zu byte\n", sizeof(signed char));
    printf(" QUANTIDADE DE BYTES DO TIPO UNSIGNED CHAR    : %zu byte\n", sizeof(unsigned char));

    printf("\n QUANTIDADE DE BYTES DO TIPO BOOL             : %zu byte\n", sizeof(bool));

    printf("\n=================================================================\n");
    printf("\n\t>> DESCOBRINDO LIMITE MÁXIMO DE CADA TIPO DE DADO <<\n");

    printf("\n\t>> RANGE MÁXIMO TIPO CHAR <<\n");

    printf(" CHAR_MAX      : %d  E CHAR_MIN       : %d\n", CHAR_MAX, CHAR_MIN);
    printf(" SIGNED CHAR_MAX : %d  E SIGNED CHAR_MIN : %d\n", SCHAR_MAX, SCHAR_MIN);
    printf(" UNSIGNED CHAR_MAX : %u\n", UCHAR_MAX);

    printf("\n=================================================================\n");
    printf("\n\t>> RANGE MÁXIMO DO TIPO INT, SIGNED E LONG <<\n");

    printf(" INT_MIN        : %d  E INT_MAX        : %d\n", INT_MIN, INT_MAX);
    printf(" SHORT_MIN      : %d  E SHORT_MAX      : %d\n", SHRT_MIN, SHRT_MAX);
    printf(" LONG_MIN       : %ld E LONG_MAX       : %ld\n", LONG_MIN, LONG_MAX);
    printf(" SIGNED LONG_LONG_MIN : %lld E SIGNED LONG_LONG_MAX : %lld\n", LLONG_MIN, LLONG_MAX);
    printf(" LONG_LONG_MIN  : %lld E LONG_LONG_MAX  : %lld\n", LONG_LONG_MIN, LONG_LONG_MAX);

    printf("\n=================================================================\n");
    printf("\n\t>> RANGE MÁXIMO DO TIPO INT UNSIGNED <<\n");

    printf(" UNSIGNED INT_MAX        : %u\n", UINT_MAX);
    printf(" UNSIGNED LONG_MAX       : %lu\n", ULONG_MAX);
    printf(" UNSIGNED LONG_LONG_MAX  : %llu\n", ULLONG_MAX);
    printf(" UNSIGNED SHORT_MAX      : %u\n", USHRT_MAX);

    printf("\n=================================================================\n");
    printf("\n\t>> RANGE MÁXIMO DO TIPO DOUBLE E FLOAT <<\n");

    printf(" FLOAT_MIN     : %g  E FLOAT_MAX     : %g\n", FLT_MIN, FLT_MAX);
    printf(" DOUBLE_MIN    : %g  E DOUBLE_MAX    : %g\n", DBL_MIN, DBL_MAX);
    printf(" LONG_DOUBLE_MIN : %LE E LONG_DOUBLE_MAX : %LE\n", LDBL_MIN, LDBL_MAX);

    /**
     * @note Lembrando que esses limites (ranges) podem variar de acordo com
     * o sistema operacional, dependendo se ele é de 32 ou 64 bits.
     */

    return 0;
}
