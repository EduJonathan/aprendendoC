#include <stdio.h>

/**
 * Exemplo com diversos especificadores de formato no printf().
 * Aborda formatações para octal, hexadecimal, notação científica e ponteiros.
 */

int main(int argc, char **argv)
{
    printf("\n\t==> OUTROS FORMATADORES <==\n");

    int OCTAL = 48;
    int HEXADECIMAL = 69;
    unsigned long int ULI = 45ul;
    unsigned long long int ULLI = 42ull;

    //================== OCTAL ==================//
    printf("\n============================================================\n");
    printf("\n\t==> FORMATOS EM OCTAL <==\n");

    printf(" OCTAL de 'OCTAL' (%%o) : %o\n", OCTAL);   // valor em base 8
    printf(" OCTAL de 'ULI' (%%lo) : %lo\n", ULI);     // long int
    printf(" OCTAL de 'ULLI' (%%llo) : %llo\n", ULLI); // long long int

    // Com prefixo '0' usando o modificador '#'
    printf("\n\t-- COM PREFIXO --\n");
    printf(" %#o (prefixado) : %#o\n", OCTAL, OCTAL); // Exe.: 060
    printf(" %#lo (prefixado) : %#lo\n", ULI, ULI);
    printf(" %#llo (prefixado) : %#llo\n", ULLI, ULLI);

    //================== HEXADECIMAL ==================//
    printf("\n=================================================================\n");
    printf("\n\t==> FORMATOS EM HEXADECIMAL <==\n");

    // Letras minúsculas (a-f)
    printf(" HEX de 'HEXADECIMAL' (%%x) : %x\n", HEXADECIMAL);

    // Letras maiúsculas (A-F)
    printf(" HEX de 'HEXADECIMAL' (%%X) : %X\n", HEXADECIMAL);
    printf(" HEX de 'ULI' (%%lx / %%lX) : %lx / %lX\n", ULI, ULI);
    printf(" HEX de 'ULLI' (%%llx / %%llX) : %llx / %llX\n", ULLI, ULLI);

    // Com prefixo '0x' ou '0X' usando '#'
    printf("\n\t-- COM PREFIXO --\n");
    printf(" %#x (minúsculo) : %#x\n", HEXADECIMAL, HEXADECIMAL); // Ex: 0x45
    printf(" %#X (maiúsculo) : %#X\n", HEXADECIMAL, HEXADECIMAL); // Ex: 0X45
    printf(" %#lx / %#lX | %#lx / %#lX\n", ULI, ULI, ULI, ULI);
    printf(" %#llx / %#llX | %#llx / %#llX\n", ULLI, ULLI, ULLI, ULLI);

    //================== ENDEREÇOS DE MEMÓRIA ==================//
    printf("\n==================================================================\n");
    printf("\n\t==> ENDEREÇOS DE MEMÓRIA (POINTERS) <==\n");

    printf(" Endereço de 'OCTAL' (%%p) : %p\n", (void *)&OCTAL);
    printf(" Endereço de 'HEXADECIMAL' : %p\n", (void *)&HEXADECIMAL);
    /*
     * %p: exibe o endereço de memória (em hexadecimal), usado com ponteiros.
     * É necessário fazer casting para (void *) em compiladores mais exigentes.
     *
     * ATENÇÃO:
     * printf(" PREFIXO DO ENDEREÇO DE MEMÓRIA DA VARIÁVEL 'OCTAL' É : %#p\n", (void *)&OCTAL);
     * ERROR: flag '#' results in undefined behavior with 'p' conversion specifier [-Wformat]
     * O modificador '#' NÃO DEVE ser usado com %p — gera comportamento indefinido.
     */

    //================== NOTAÇÃO CIENTÍFICA ==================//
    printf("\n=====================================================================\n");
    printf("\n\t==> NOTAÇÃO CIENTÍFICA <==\n");

    float NOTACAO_CIENTIFICA = 45.5236F; // Atenção: 045 seria interpretado como octal

    printf(" %e | %e\n", NOTACAO_CIENTIFICA, NOTACAO_CIENTIFICA); // Ex: 4.552360e+01
    printf(" %E | %E\n", NOTACAO_CIENTIFICA, NOTACAO_CIENTIFICA); // Ex: 4.552360E+01
    printf(" %g | %g\n", NOTACAO_CIENTIFICA, NOTACAO_CIENTIFICA); // Escolhe entre %f ou %e (menor)
    printf(" %G | %G\n", NOTACAO_CIENTIFICA, NOTACAO_CIENTIFICA); // Mesmo que %g, com 'E' maiúsculo

    printf("\n\t-- Com long double --\n");

    long double NOTACAO = 263.78L;

    printf(" %Le | %Le\n", NOTACAO, NOTACAO);
    printf(" %LE | %LE\n", NOTACAO, NOTACAO);
    printf(" %Lg | %Lg\n", NOTACAO, NOTACAO);
    printf(" %LG | %LG\n", NOTACAO, NOTACAO);

    return 0;
}
