#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv)
{
    /// FORMATADORES: São usados para controlar a exibição e entrada de dados no C, sendo sempre precedidos por '%'.
    /// VARIÁVEIS: Representam identificadores que armazenam valores de diferentes tipos de dados.

    printf("\n==================================================================\n");
    printf("\n\t==>SEÇÃO FORMATADORES PARA TIPOS DE DADOS PRIMITIVOS<==\n");

    int numero_positivo = 98;  // Números inteiros positivos ou negativos
    int numero_negativo = -98; // Números inteiros negativos
    float real = 10.5;         // Valores com ponto flutuante (32 bits de precisão)
    double PI = 3.14;          // Números reais com maior precisão (64 bits)
    char letra = 'A';          // Caractere único

    printf(" O VALOR DA VARIÁVEL 'numero_positivo' É : %d\n", numero_positivo); // %d -> para tipo int
    printf(" O VALOR DA VARIÁVEL 'numero_negativo' É : %d\n", numero_negativo); // %d -> para tipo int
    printf(" O VALOR DA VARIÁVEL 'real' É : %f\n", real);                       // %f -> para tipo float
    printf(" O VALOR DA VARIÁVEL 'PI' É : %lf\n", PI);                          // %lf -> para tipo double
    printf(" O VALOR DA VARIÁVEL 'letra' É : %c\n", letra);                     // %c -> para tipo char

    /// OBS: O sinal de '=' significa atribuição ou inicialização de um valor a variáveis.

    printf("\n======================================================================\n");
    printf("\n\t==>SEÇÃO PARA VALORES BOOLEANOS<==\n");

    bool True = true;
    bool False = false;

    // _Bool foi utilizado para valores booleanos em compiladores mais antigos.
    _Bool FALSE = true;
    _Bool TRUE = false;

    // "bool", "true" e "false" são definidos pela biblioteca <stdbool.h>.
    // Em versões mais antigas de C, era necessário usar "_Bool", mas isso já não é mais necessário.

    printf(" O VALOR DA VARIÁVEL 'True'  É : %d\n", True);
    printf(" O VALOR DA VARIÁVEL 'False' É : %d\n", False);
    printf(" O VALOR DA VARIÁVEL 'FALSE' É : %d\n", FALSE);
    printf(" O VALOR DA VARIÁVEL 'TRUE'  É : %d\n", TRUE);
    // %d -> usado para exibir valores booleanos, que são armazenados como 1 (true) ou 0 (false)

    printf("\n========================================================================\n");
    printf("\n\t==>DELIMITANDO VALORES DAS CASAS DECIMAIS<==\n");

    printf(" O VALOR DA VARIÁVEL 'PI' EM 2 CASAS DECIMAIS   : %.2lf\n", PI);
    printf(" O VALOR DA VARIÁVEL 'real' EM 3 CASAS DECIMAIS : %.3f\n", real);

    printf("\n========================================================================\n");
    printf("\n\t==>SEÇÃO PARA CARACTERES LITERAIS (STRINGS)<==\n");

    char ler[20] = "Olá, mundo";
    char literal[] = {"Programar é muito legal."};
    char caracteres[12] = {'L', 'I', 'N', 'G', 'U', 'A', 'G', 'E', 'M', ' ', 'C'};
    char Caracteres[] = {'H', 'E', 'L', 'L', 'O', ' ', 'W', 'O', 'R', 'L', 'D', '\0'};
    const char *leitura = "Obrigado Senhor Deus!";

    // O '\0' é um caractere especial que indica o fim da string em C.
    // Diferenciando: char[] (array de caracteres) e char* (ponteiro para char).
    // O ponteiro char* aponta para uma sequência de caracteres, e o tipo char[] é um array de caracteres.

    printf(" O VALOR DA STRING 'ler'        É : %s\n", ler);
    printf(" O VALOR DA STRING 'caracteres' É : %s\n", caracteres);
    printf(" O VALOR DA STRING 'Caracteres' É : %s\n", Caracteres);
    printf(" O VALOR DA STRING 'literal'    É : %s\n", literal);
    printf(" O VALOR DA STRING 'leitura'    É : %s\n", leitura);
    // %s -> para exibir strings (sequência de caracteres terminadas por '\0').

    printf("\n========================================================================\n");
    printf("\n\t==>SEÇÃO FORMATADORES PARA TIPO (UNSIGNED)<==\n");

    unsigned char UC = 'M';
    unsigned U = 65535;
    unsigned short US = 0;
    unsigned long UL = 75;
    unsigned long long ULL = 9e5; // Equivalente a 900000 (9 * 10^5)

    printf(" O VALOR DA VARIÁVEL 'UC'  É : %c\n", UC);    // %c -> para tipo Unsigned char
    printf(" O VALOR DA VARIÁVEL 'U'   É : %u\n", U);     // %u -> para tipo Unsigned
    printf(" O VALOR DA VARIÁVEL 'US'  É : %hu\n", US);   // %hu -> para tipo Unsigned Short
    printf(" O VALOR DA VARIÁVEL 'UL'  É : %lu\n", UL);   // %lu -> para tipo Unsigned Long
    printf(" O VALOR DA VARIÁVEL 'ULL' É : %llu\n", ULL); // %llu -> para tipo Unsigned Long Long

    printf("\n========================================================================\n");
    printf("\n\t==>SEÇÃO FORMATADORES PARA TIPO (SIGNED)<==\n");

    signed char SC = 'A';
    signed S = -32767;
    signed short SS = 32767;
    signed long SL = 6925451;
    signed long long SLL = 263548868;

    printf(" O VALOR DA VARIÁVEL 'SC'  É : %c\n", SC);    // %c -> para tipo Signed Char
    printf(" O VALOR DA VARIÁVEL 'S'   É : %i\n", S);     // %i -> para tipo Signed
    printf(" O VALOR DA VARIÁVEL 'SS'  É : %hi\n", SS);   // %hi -> para tipo Signed Short
    printf(" O VALOR DA VARIÁVEL 'SL'  É : %ld\n", SL);   // %ld -> para tipo Signed Long
    printf(" O VALOR DA VARIÁVEL 'SLL' É : %lld\n", SLL); // %lld -> para tipo Signed Long Long

    printf("\n========================================================================\n");
    printf("\n\t==>SEÇÃO FORMATADORES PARA TIPO (LONG)<==\n");

    long L = 2147483647;
    long long LL = -2147483647;
    long double LD = 3.14155896587458962548;

    printf(" O VALOR DA VARIÁVEL 'L'  É : %ld\n", L);     // %ld -> para tipo Long
    printf(" O VALOR DA VARIÁVEL 'LL' É : %lld\n", LL);   // %lld -> para tipo Long Long
    printf(" O VALOR DA VARIÁVEL 'LD' É : %Lf\n", LD);    // %Lf -> para tipo Long Double
    printf(" O VALOR DA VARIÁVEL 'LD' É : %.10LF\n", LD); // %LF -> para tipo Long Double

    // Se o seu programa estiver imprimindo apenas 0.000000000000000, pode ser devido à
    // falta de suporte nativo do Windows para números de alta precisão (128 bits).
    // Nesse caso, pode-se utilizar uma função específica do compilador ou bibliotecas
    // externas para manipulação de alta precisão.

    // Função específica do compilador MinGW para imprimir long double com mais precisão.
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
     * Evite usar funções específicas de compilador sempre que possível,
     * para manter o código portável.
     */

    printf("\n======================================================================\n");
    printf("\n\t==>SEÇÃO DE FORMATADORES PARA TIPOS (SHORTS)<==\n");

    short SH = 767;
    printf(" O VALOR DA VARIÁVEL 'SH' É : %hd\n", SH); // %hd -> Para tipo Short

    /**
     * Regras para nomear variáveis em C:
     *
     * ✅ NOMEAÇÕES VÁLIDAS:
     *
     * 1. Devem começar com uma letra (a-z ou A-Z) ou underscore (_)
     *    Ex: nome, _valor, dados_recebidos
     *
     * 2. Podem conter números após o primeiro caractere
     *    Ex: num1, valor2, dado3_total
     *
     * 3. Não devem conter espaços ou caracteres especiais
     *    Errado: nome completo, preço$, valor@total
     *
     * 4. Não podem começar com números
     *    Errado: 1valor | Correto: valor1
     *
     * 5. Não podem ser palavras reservadas(keywords) da linguagem
     *    Errado: int, return, if, printf
     *    Obs: Mesmo com variando a capitalização das keywords, como `Int`, `Printf` são tecnicamente válidas, mas **não recomendadas**
     *
     * 6. Devem ser descritivos e significativos
     *    Evite: x, y, a1
     *    Prefira: total_alunos, idade_usuario
     *
     * 7. Devem ser únicas dentro do mesmo escopo
     *    Não é possível ter duas variáveis com o mesmo nome no mesmo bloco de código.
     *
     * 8. Devem seguir a convenção da linguagem:
     *    Em C, é comum o uso de `snake_case` (letras minúsculas e underscores).
     *    Ex: nome_completo, taxa_media
     *
     * 9. Devem ser declaradas antes de serem utilizadas
     *    Ex: int idade = 18; printf("%d", idade);
     *
     * 10. É recomendável inicializar variáveis ao declará-las
     *     Ex: int x = 0; float pi = 3.14;
     *
     * 11. Não se pode declarar a mesma variável com tipos diferentes no mesmo escopo
     *     Errado: int valor; float valor;
     *
     * 12. Se já existe uma variável com certo nome, não é possível declarar outra com o mesmo nome,
     *     mesmo que de tipo diferente, no mesmo escopo.
     *
     * 13. Os nomes devem ser consistentes com o uso
     *     Ex: `nome_completo` é mais apropriado que `n`, se a variável guarda um nome.
     *
     * 💡 DICA:
     *    Use nomes que indiquem claramente o propósito da variável. Isso facilita a leitura,
     *    manutenção e colaboração no código.
     *
     * ✅ TODAS essas regras visam garantir clareza, legibilidade e evitar erros no código.
     *    Elas são boas práticas válidas para todas as linguagens de programação.
     */

    return 0;
}
