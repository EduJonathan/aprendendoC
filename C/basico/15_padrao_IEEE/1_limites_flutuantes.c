#include <stdio.h>
#include <float.h>

// Explorando diversas constantes relacionadas aos tipos de dados de ponto flutuante.
// Com eles, é útil para entender as capacidades e limitações dos tipos de dados de
// ponto flutuante em diferentes implementações de compiladores C.

int main(int argc, char **argv)
{
    // Precisão decimal necessária para serializar/deserializar um long double.
    printf(" DECIMAL_DIG = %d\n", DECIMAL_DIG);

    // Precisão decimal necessária para serializar/deserializar um float, double e long double.
    // Pelo menos 6, 10 e 10 dígitos, respectivamente, ou 9 para IEEE float e 17 para IEEE double.
    printf(" FLT_DECIMAL_DIG  = %d\n", FLT_DECIMAL_DIG);
    printf(" DBL_DECIMAL_DIG  = %d\n", DBL_DECIMAL_DIG);
    printf(" LDBL_DECIMAL_DIG = %d\n", LDBL_DECIMAL_DIG);

    // Modo de arredondamento da aritmética de ponto flutuante.
    printf(" FLT_ROUNDS = %d\n", FLT_ROUNDS);

    // Utilização de precisão alargada para resultados intermédios, onde
    // 0: não utilizado, 1: é utilizado o double em vez do float, 2: é utilizado o long double.
    printf(" FLT_EVAL_METHOD  = %d\n", FLT_EVAL_METHOD);

    // Tipos suportam números subnormais (denormais): -1: indeterminável, 0: ausente, 1: presente.
    printf(" FLT_HAS_SUBNORM  = %d\n", FLT_HAS_SUBNORM);
    printf(" DBL_HAS_SUBNORM  = %d\n", DBL_HAS_SUBNORM);
    printf(" LDBL_HAS_SUBNORM = %d\n", LDBL_HAS_SUBNORM);

    printf("\n====================================================================\n");
    printf("\n\tMENOR DIFERENÇA ENTRE OS PONTOS FLUTUANTES:\n");

    // Menor diferença entre os pontos flutuantes: aumento mínimo em 1 do último bit significativo representável.
    printf(" FLT_EPSILON  : %e\n", FLT_EPSILON);   // FLOAT
    printf(" DBL_EPSILON  : %e\n", DBL_EPSILON);   // DOUBLE
    printf(" LDBL_EPSILON : %Le\n", LDBL_EPSILON); // LONG DOUBLE

    printf("\n====================================================================\n");
    printf("\n\tCONSTANTES FLUTUANTES(FLOAT E DOUBLES):\n");

    // Base dos tipos de ponto flutuantes: número de dígitos de base float radix na mantissa.
    printf(" BASE DOS TIPOS DE PONTO FLUTUANTES FLT_RADIX : %d\n", FLT_RADIX);

    // Número de dígitos de base float radix na mantissa para float, double e long double.
    printf(" NÚMEROS DE DIGITOS DE P FLT_MANT_DIG  : %d\n", FLT_MANT_DIG);
    printf(" NÚMEROS DE DIGITOS DE P DBL_MANT_DIG  : %d\n", DBL_MANT_DIG);
    printf(" NÚMEROS DE DIGITOS DE P LDBL_MANT_DIG : %d\n", LDBL_MANT_DIG);

    printf("\n====================================================================\n");
    printf("\n\tDIGITOS DECIMAIS REPRESENTADOS SEM ARREDONDAMENTOS:\n");

    // Dígitos decimais preservados sem arredondamentos na viagem de ida e volta do texto.
    printf(" MÍNIMO DE FLT_DIG  : %d\n", FLT_DIG);  // FLOAT
    printf(" MÍNIMO DE DBL_DIG  : %d\n", DBL_DIG);  // DOUBLE
    printf(" MÍNIMO DE LDBL_DIG : %d\n", LDBL_DIG); // LONG DOUBLE

    printf("\n====================================================================\n");
    printf("\n\tMENOR E MAIOR EXPOENTE QUE GERAM PONTO FLUTUANTE NORMALIZADOS:\n");

    // Menor e maior expoente que geram ponto flutuante normalizados.
    printf(" MÍNIMO FLT_MIN_EXP  : %d E MÁXIMO FLT_MAX_EXP  : %d\n", FLT_MIN_EXP, FLT_MAX_EXP);
    printf(" MÍNIMO DBL_MIN_EXP  : %d E MÁXIMO DBL_MAX_EXP  : %d\n", DBL_MIN_EXP, DBL_MAX_EXP);
    printf(" MÍNIMO LDBL_MIN_EXP : %d E MÁXIMO LDBL_MAX_EXP : %d\n", LDBL_MIN_EXP, LDBL_MAX_EXP);

    printf("\n=====================================================================\n");
    printf("\n\tEXPOENTE 'e' DE BASE 10 QUE GERAM PONTO FLUTUANTE NORMALIZADOS:\n");

    // Menor e maior expoente para os quais 10 elevado à potência é um ponto flutuante normalizado.
    printf(" MÍNIMO FLT_MIN_10_EXP  : %d E MÁXIMO FLT_MAX_10_EXP  : %d\n", FLT_MIN_10_EXP, FLT_MAX_10_EXP);
    printf(" MÍNIMO DBL_MIN_10_EXP  : %d E MÁXIMO DBL_MAX_10_EXP  : %d\n", DBL_MIN_10_EXP, DBL_MAX_10_EXP);
    printf(" MÍNIMO LDBL_MIN_10_EXP : %d E MÁXIMO LDBL_MAX_10_EXP : %d\n", LDBL_MIN_10_EXP, LDBL_MAX_10_EXP);

    return 0;
}
