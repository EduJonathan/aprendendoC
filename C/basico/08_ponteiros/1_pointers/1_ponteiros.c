#include <stdio.h>

/**
 * POINTERS: Ponteiros são variáveis especiais que armazenam endereços de memória de
 * outras variáveis, para uma manipulação mais eficiente não no conteúdo da variável
 * em si, e sim na memória que o ponteiro aponta.
 */

int main(int argc, char **argv)
{
    printf("\n\t\t>>PONTEIROS<<\n");

    printf("\n\t>>IMPRIMINDO INFORMAÇÕES DA VARIÁVEL 'num'<<\n");

    /* Variável inicializada com caractere '5', na tabela ASCII o decimal de '5' é 53 */
    int num = '5';

    printf(" Valor da variável num : CARACTERE : %c ASCII : %d\n", num, num);
    printf(" Endereço de memória de num : %p\n", &num);

    printf("\n=============================================================================\n");
    printf("\n\t>>IMPRIMINDO INFORMAÇÕES DO PONTEIRO 'ptr'<<\n");

    /* Declarando um ponteiro */
    int *ptr;

    /* imprime o endereço de memória de ptr */
    printf("\n O endereço de memória de ptr : %p\n", &ptr);

    /* imprime o endereço de memória que está armazenado no ponteiro */
    printf(" O endereço que ptr armazena é : %p\n", ptr);

    // No momento o ponteiro está armazenando lixo de memória, toda vez que o programa
    // for executado um endereço aleatório irá ser exibido pois nenhum endereço de memória
    // não foi atribuido a ele, para que isso não possa acontecer utilizamos o NULL.

    /* O ponteiro se torna 0x0 ou 0000000000000000 */
    ptr = NULL;

    /**
     * NULL: Ponteiro nulo é um valor especial que representa o ponteiro para que ele seja
     * nulo, ou seja, que não aponta para nenhum acesso válido à memória a
     * derreferenciação de um ponteiro nulo não pode ser efetuada, importante sempre iniciar
     * ponteiros com NULL.
     */

    printf(" O Valor do ponteiro quando inserirmos NULL nele : %p\n", ptr);

    // ptr = 5; // Não pode! pois o ponteiro sempre deve receber um endereço
    /// ERROR: assignment to 'int *' from 'int' makes pointer from integer without a cast

    // printf(" Conteudo do ponteiro : %d\n", *ptr); // erro de segmentação
    // Enquanto o ponteiro for nulo, não podemos derrefencia-lo, então precisamos fazer o
    // ponteiro apontar para um endereço válido

    /* ptr está apontando agora para o endereço de memória de num. */
    ptr = &num;

    // VERIFICANDO...
    printf(" O endereço que ptr armazena agora é o endereço de : %p\n", ptr);
    printf(" ptr %p -> aponta para %p\n", &ptr, ptr);

    printf("\n=============================================================================\n");
    printf("\n\t\t>>DERREFÊRENCIA DO PONTEIRO<<\n");

    printf("\n\t>>IMPRIMINDO O CONTEÚDO DO PONTEIRO\n");
    /// DERREFERENCIA: Significa que podemos trabalhar com o valor do endereço que o ponteiro aponta.

    printf("O conteudo de ptr: %d\tconteudo em hexadecimal: %x\tconteudo em octal: %o\n", *ptr, *ptr, *ptr);
    printf("O conteudo de ptr: %d\tconteudo em hexadecimal: %x\tconteudo em octal: %o\n", ptr, ptr, ptr);

    /*
     * A obtenção do conteúdo de um ponteiro sempre terá de colocar o operador de
     * desreferência (*) antes pois somente assim ele irá apresentar o conteúdo do
     * valor do ponteiro. este metódo é conhecido como derrefenciação ou derreferencia.
     * mas e se não colocar o * antes do ptr?
     *
     * printf("O conteudo de ptr: %d\tconteudo em hexadecimal: %x\tconteudo em octal: %o\n", ptr, ptr, ptr);
     * %d: Imprime o valor de *ptr em formato decimal.
     * %x: Imprime o valor de *ptr em formato hexadecimal.
     * %o: Imprime o valor de *ptr em formato octal.
     */

    /*
     * Em variaveis_e_formatters e scanf vimos o que exibe ou indica o endereço de
     * memória o operador únario '&' acompanhado pelo formatador de pointer("%p"),
     * mas caso usarmos o formatter "%d"
     * printf(" O endereço de ptr : %d\n", &ptr);
     * printf(" O endereço de ptr : %x\n", &ptr);
     * printf(" O endereço de ptr : %o\n", &ptr);
     * Exibe os valores do "endereço de memória" de 'ptr' convertidos em decimal, hexadecimal e octal.
     *
     * printf(" O endereço de num : %d\n", &num);
     * printf(" O endereço de num : %x\n", &num);
     * printf(" O endereço de num : %o\n", &num);
     * Exibe os valores do "endereço de memória" de 'num' convertidos em decimal, hexadecimal e octal.
     */

    /**
     * A inicialização de ponteiro sempre terá que corresponder para o tipo de dado a
     * qual ele foi declaradado, ou seja
     * ponteiro int guarda somente tipo int
     * ponteiro char guarda somente tipo char
     * e assim por diante.
     *
     * DETALHE: Se tentarmos aplicar ao contrário, guardar o valor de um caractere
     * para um ponteiro int
     * **************************
     * * char caractere = 'A';  *
     * * int *ptr = &caractere; *
     * **************************
     * ERROR: initialization of 'int *' from incompatible pointer type 'char *'
     *
     * por conta deste erro podemos afirmar que muitas das vezes dizemos que o valor
     * de um ponteiro é o valor do tipo, mas na verdade o que estamos dizendo é que o valor
     * de um ponteiro é o endereço de memória do tipo, ou seja, o valor do ponteiro é um
     * de um ponteiro é "<PARA UM> valor do tipo" (no caso um endereço), e não que ele é
     * "<O> valor de um tipo"
     */

    printf("\n=================================================================\n");
    printf("\n\t>>PASSANDO O VALOR DE UM PONTEIRO PARA UMA VARIÁVEL<<\n");

    *ptr = 65; /* Atribuindo outro valor para o contéudo do ponteiro, pode também *ptr = 'A'; */
    /* Lembrando que char são apenas INTEIROS de 8 bits, e nosso ponteiro também é um INTEIRO. */

    /**
     * ERRO: num = ptr;
     * warning : assignment to 'int' from 'int *' makes integer from pointer without a cast
     * printf(" O valor da variável num atribuido pelo conteudo do ponteiro ptr : %d\n", num);
     */

    num = *ptr;
    /* Atribui o valor do ponteiro para a variável num usando o operador de desreferência (*). */
    /* Agora num possue o valor de ptr para si, ou seja num agora é 65, em ASCII 'A'. */

    /* Passando o conteúdo de num, apontado pelo ponteiro para var. */
    int var = *ptr;

    printf(" O valor da variável 'num' atribuido pelo conteudo do ponteiro ptr : %d-%c\n", num, num);
    printf(" O valor da variável 'var' atribuido pelo conteudo do ponteiro ptr : %d-%c\n", var, var);
    return 0;
}
