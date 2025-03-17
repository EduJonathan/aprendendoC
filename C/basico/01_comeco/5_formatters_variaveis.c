#include <stdio.h>
#include <stdbool.h>

// Na linguagem C valores booleanos: true é representado por 1 e false por 0.
// O #include <stdbool.h> torna possível o uso de tipos booleanos 'bool', 'true', 'false'.

int main(int argc, char **argv)
{
    /// FORMATTERS: Formatadores são responsáveis por realizar a exibição,
    // entrada e saída de dados, sempre acompanhados pelo especificador '%'.

    /// VARIAVEIS: Identificadores são nomeações que criam abstrações para armazenar
    // valores de tipos de dados, permitindo manipulação e alteração dos dados.

    /// OBS: O sinal de '=' significa atribuição ou inicialização de um valor a variáveis.

    printf("\n==================================================================\n");
    printf("\n\t==>SEÇÃO FORMATADORES PARA TIPOS DE DADOS PRIMITIVOS<==\n");

    int numero_positivo = 98;  // Números decimais positivos ou negativos
    int numero_negativo = -98; // Números decimais positivos ou negativos
    float real = 10.5;         // Valores com números reais (32 bits de precisão)
    double PI = 3.14;          // Números reais com maior precisão (64 bits)
    char letra = 'A';          // Apenas uma única letra (caractere)

    printf(" O VALOR DA VARIÁVEL 'numero_positivo' É : %d\n", numero_positivo); // %d -> para tipo int
    printf(" O VALOR DA VARIÁVEL 'numero_negativo' É : %d\n", numero_negativo); // %d -> para tipo int
    printf(" O VALOR DA VARIÁVEL 'real' É : %f\n", real);                       // %f -> para tipo float
    printf(" O VALOR DA VARIÁVEL 'PI' É : %lf\n", PI);                          // %lf -> para tipo double
    printf(" O VALOR DA VARIÁVEL 'letra' É : %c\n", letra);                     // %c -> para tipo char

    printf("\n======================================================================\n");
    printf("\n\t==>SEÇÃO PARA VALORES BOOLEANOS<==\n");

    bool True = true;
    bool False = false;

    // _Bool utilizada para declarar valores booleanos em compiladores antecessores
    _Bool FALSE = true;
    _Bool TRUE = false;

    // Ressaltando que os valores o tipo de dado "bool", "true" e "false", só estão
    // sendo utilizados por conta da biblioteca <stdbool.h>.

    printf(" O VALOR DA VARIÁVEL 'True'  É : %d\n", True);
    printf(" O VALOR DA VARIÁVEL 'False' É : %d\n", False);
    printf(" O VALOR DA VARIÁVEL 'FALSE' É : %d\n", FALSE);
    printf(" O VALOR DA VARIÁVEL 'TRUE'  É : %d\n", TRUE);
    // %d -> para dados booleanos, pois são apenas 2 numerais (1 e 0), representando true e false

    printf("\n========================================================================\n");
    printf("\n\t==>DELIMITANDO VALORES DAS CASAS DECIMAIS<==\n");

    printf(" O VALOR DA VARIAVEL 'PI' EM 2 CASAS DECIMAIS   : %.2lf\n", PI);
    printf(" O VALOR DA VARIAVEL 'real' EM 3 CASAS DECIMAIS : %.3f\n", real);

    printf("\n========================================================================\n");
    printf("\n\t==>SEÇÃO PARA CARACTERES LITERAIS (STRINGS)<==\n");

    char ler[20] = "Olá, mundo";
    char literal[] = {"Programar é muito legal."};
    char caracteres[12] = {'L', 'I', 'N', 'G', 'U', 'A', 'G', 'E', 'M', ' ', 'C'};
    char Caracteres[] = {'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D', '\0'};
    const char *leitura = "Obrigado Senhor Deus!";

    // O '\0' é um caractere especial que determina o fim de uma string.
    // char []: Significa que o tipo de dado é um array (conjunto de dados), veremos adiante
    // char *: O '*' antes da variável indica que o tipo de dado é um ponteiro iremos ver adiante.

    printf(" O VALOR DA STRING 'ler'        É : %s\n", ler);
    printf(" O VALOR DA STRING 'caracteres' É : %s\n", caracteres);
    printf(" O VALOR DA STRING 'caracteres' É : %s\n", Caracteres);
    printf(" O VALOR DA STRING 'literal'    É : %s\n", literal);
    printf(" O VALOR DA STRING 'leitura'    É : %s\n", leitura);
    // Para tipo string (caracteres literais) seu formatter é o %s

    printf("\n========================================================================\n");
    printf("\n\t==>SEÇÃO FORMATADORES PARA TIPO (UNSIGNED)<==\n");

    unsigned char UC = 'M';
    unsigned U = 65535;
    unsigned short US = 0;
    unsigned long UL = 75;
    unsigned long long ULL = 9e5; // Equivalente 9 * 10 ^ 5 = 9 * 100.000, resultando em 900000

    printf(" O VALOR DA VARIÁVEL 'UC'  É : %c\n", UC);    // %c -> Para tipo Unsigned char
    printf(" O VALOR DA VARIÁVEL 'U'   É : %u\n", U);     // %u -> Para tipo Unsigned
    printf(" O VALOR DA VARIÁVEL 'US'  É : %hu\n", US);   // %hu -> Para tipo Unsigned Short
    printf(" O VALOR DA VARIÁVEL 'UL'  É : %lu\n", UL);   // %lu -> Para tipo Unsigned Long
    printf(" O VALOR DA VARIÁVEL 'ULL' É : %llu\n", ULL); // %llu -> Para tipo Unsigned Long Long

    printf("\n========================================================================\n");
    printf("\n\t==>SEÇÃO FORMATADORES PARA TIPO (SIGNED)<==\n");

    signed char SC = 'A';
    signed S = -32767;
    signed short SS = 32767;
    signed long SL = 6925451;
    signed long long SLL = 263548868;

    printf(" O VALOR DA VARIÁVEL 'SC'  É : %c\n", SC);    // %c -> para tipo Signed Char
    printf(" O VALOR DA VARIÁVEL 'S'   É : %i\n", S);     // %i -> Para tipo Signed
    printf(" O VALOR DA VARIÁVEL 'SS'  É : %hi\n", SS);   // %hi -> Para tipo Signed Short
    printf(" O VALOR DA VARIÁVEL 'SL'  É : %ld\n", SL);   // %ld -> Para tipo Signed Long
    printf(" O VALOR DA VARIÁVEL 'SLL' É : %lld\n", SLL); // %lld -> Para tipo Signed Long Long

    printf("\n========================================================================\n");
    printf("\n\t==>SEÇÃO FORMATADORES PARA TIPO (LONG)<==\n");

    long L = 2147483647;
    long long LL = -2147483647;
    long double LD = 3.14155896587458962548;

    printf(" O VALOR DA VARIÁVEL 'L'  É : %ld\n", L);     // %ld -> para tipo Long
    printf(" O VALOR DA VARIÁVEL 'LL' É : %lld\n", LL);   // %lld -> para tipo Long Long
    printf(" O VALOR DA VARIÁVEL 'LD' É : %Lf\n", LD);    // %Lf -> para tipo Long Double
    printf(" O VALOR DA VARIÁVEL 'LD' É : %.10LF\n", LD); // %LF -> para tipo Long Double

    // Se no seu programa estiver imprimindo apenas 0.000000000000000000?
    // o sistema operacional windows Não tem suporte para um número desse tamanho
    // de precisão (16 bytes - 128 bits) e caso possa acontecer! podemos utilizar uma
    // função própria do núcleo do compilador.

    __mingw_printf(" O VALOR DA VARIÁVEL 'LD' É : %.18Lf\n", LD);

    /**
     * __mingw_printf(): Função específica do compilador MinGW (Windows) para imprimir
     * `long double` com maior precisão, caso o `printf` padrão não seja suficiente.
     * Ela resolve limitações de precisão em sistemas Windows, mas não é portável
     * para outros compiladores (como GCC, Clang) ou sistemas operacionais.
     *
     * Para garantir portabilidade, CONSIDERE:
     * 1. Ajustar a precisão de `long double` para um nível compatível com `printf`.
     * 2. Usar tipos como `double`, se a precisão extra não for necessária.
     * 3. Explorar bibliotecas de alta precisão como `MPFR` ou `GMP`.
     *
     * Evite usar funções específicas de compilador sempre que possíve  l,
     * para manter o código portável.
     */

    printf("\n======================================================================\n");
    printf("\n\t==>SEÇÃO DE FORMATADORES PARA TIPOS (SHORTS)<==\n");

    short SH = 767;
    printf(" O VALOR DA VARIÁVEL 'SH' É : %hd\n", SH); // %hd -> Para tipo Short
    return 0;
}
