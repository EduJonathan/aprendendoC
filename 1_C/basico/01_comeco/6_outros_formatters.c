#include <stdio.h>

/* Exemplo de outros tipos de formatadores e especificadores de saídas de dados */

int main(int argc, char **argv)
{
    printf("\n\t\t==>OUTROS FORMATADORES<==\n");

    int OCTAL = 48;
    int HEXADECIMAL = 69;
    unsigned long int ULI = 45;
    unsigned long long int ULLI = 42;

    printf("\n============================================================\n");
    printf("\n\t==>SEÇÃO PARA FORMATOS EM OCTAIS<==\n");

    // %o: Exibe valores de um número na forma octal
    printf(" VALOR OCTAL DA VARIÁVEL 'OCTAL' : %o\n", OCTAL);

    // %lo: Para tipo long
    printf(" VALOR OCTAL DA VARIÁVEL 'ULI' : %lo\n", ULI);

    // %llo: Para tipo unsigned long long
    printf(" VALOR OCTAL DA VARIÁVEL 'ULLI' : %llo\n", ULLI);

    printf("\n-----------------------------------------------------\n");

    // %#o, %#lo ou %#llo: Exibe valores de um número na forma octal com prefixo '0'
    printf(" PREFIXO DO VALOR EM OCTAL DA VARÍAVEL 'OCTAL' : %#o\n", OCTAL); // Prefixo 0
    printf(" PREFIXO OCTAL DA VARIÁVEL 'ULI' : %#lo\n", ULI);                // Prefixo 0
    printf(" PREFIXO OCTAL DA VARIÁVEL 'ULLI' : %#llo\n", ULLI);             // Prefixo 0

    printf("\n=================================================================\n");
    printf("\n\t==>SEÇÃO PARA FORMATOS EM HEXADECIMAIS<==\n");

    // %x: Exibe valores de um número na forma hexadecimal
    printf(" VALOR EM HEXADECIMAL DA VARIÁVEL 'HEXADECIMAL' : %x\n", HEXADECIMAL);
    printf(" VALOR EM HEXADECIMAL DA VARIÁVEL 'HEXADECIMAL' : %X\n", HEXADECIMAL);

    // %lx: Para tipo unsigned long
    printf(" VALOR EM HEXADECIMAL DA VARIÁVEL 'ULI' : %lx\n", ULI);

    // %lX: Para tipo unsigned long
    printf(" VALOR EM HEXADECIMAL DA VARIÁVEL 'ULI' : %lX\n", ULI);

    // %llx: Para tipo unsigned long long
    printf(" VALOR EM HEXADECIMAL DA VARIÁVEL 'ULLI' : %llx\n", ULLI);

    // %llX: Para tipo unsigned long long
    printf(" VALOR EM HEXADECIMAL DA VARIÁVEL 'ULLI' : %llX\n", ULLI);

    printf("\n-----------------------------------------------------\n");

    // %#x ou %#X: Exibe valores de um número na forma hexadecimal com prefixo 'x' e 'X'
    printf(" PREFIXO DO VALOR EM HEXADECIMAL DA VARIÁVEL 'HEXADECIMAL' : %#x\n", HEXADECIMAL);
    printf(" PREFIXO DO VALOR EM HEXADECIMAL DA VARIÁVEL 'HEXADECIMAL' : %#X\n", HEXADECIMAL);

    // %#lx ou %#lX: Para tipo unsigned long
    printf(" PREFIXO HEXADECIMAL DA VARIÁVEL 'ULI' : %#lx\n", ULI);
    printf(" PREFIXO HEXADECIMAL DA VARIÁVEL 'ULI' : %#lX\n", ULI);

    // %#llx ou %#llX: Para tipo unsigned long long
    printf(" PREFIXO HEXADECIMAL DA VARIÁVEL 'ULLI' : %#llx\n", ULLI);
    printf(" PREFIXO HEXADECIMAL DA VARIÁVEL 'ULLI' : %#llX\n", ULLI);

    printf("\n==================================================================\n");
    printf("\n\t==>SEÇÃO PARA EXIBIR O ENDEREÇO DE MEMÓRIA DE UMA VARÍAVEL<==\n");

    printf(" O ENDEREÇO DE MEMÓRIA DA VARIÁVEL 'OCTAL' É : %p\n", &OCTAL);
    /*
     * %p: vem de pointer(ponteiro) e %x que podem são formatadores que exibem a
     * posição de memória (referência) através do operador &(endereço de) na variável.
     */

    printf(" PREFIXO DO ENDEREÇO DE MEMÓRIA DA VARIÁVEL 'HEXADECIMAL' É : %p\n", (void *)&HEXADECIMAL);
    /*
     * '#': formata o printf incluindo 0, 0x ou 0X dando uma perspectiva do prefixo de
     * números octal, hexadecimal e endereços, não recomendado seu uso, pois pode gerar
     * confusão em sua interpretação e conversão do valor.
     *
     * printf(" PREFIXO DO ENDEREÇO DE MEMÓRIA DA VARIÁVEL 'HEXADECIMAL' É : %#p\n", (void *)&HEXADECIMAL);
     * ERROR: flag '#' results in undefined behavior with 'p' conversion specifier [-Wformat]
     */

    printf("\n=====================================================================\n");
    printf("\n\t==>SEÇÃO PARA EXIBIR VALORES EM NOTAÇÕES CIENTIFICAS<==\n");

    float NOTACAO_CIENTIFICA = 045.5236F;

    printf(" VALOR DE 'NOTAÇÃO_CIENTIFICA' FORMATADA : %e\n", NOTACAO_CIENTIFICA);
    printf(" VALOR DE 'NOTAÇÃO_CIENTIFICA' FORMATADA : %E\n", NOTACAO_CIENTIFICA);
    printf(" VALOR DE 'NOTAÇÃO_CIENTIFICA' FORMATADA : %g\n", NOTACAO_CIENTIFICA);
    printf(" VALOR DE 'NOTAÇÃO_CIENTIFICA' FORMATADA : %G\n", NOTACAO_CIENTIFICA);

    printf("\n-----------------------------------------------------\n");

    long double NOTACAO = 263.78L;
    printf(" VALOR DE 'NOTAÇÃO' FORMATADA : %Le\n", NOTACAO);
    printf(" VALOR DE 'NOTAÇÃO' FORMATADA : %LE\n", NOTACAO);
    printf(" VALOR DE 'NOTAÇÃO' FORMATADA : %Lg\n", NOTACAO);
    printf(" VALOR DE 'NOTAÇÃO' FORMATADA : %LG\n", NOTACAO);
    return 0;
}
