#include <stdio.h>

/* Utilização de ponteiros em variáveis */

int main(int argc, char **argv)
{
    /* Parte 1: Operações básicas com ponteiros */

    // Criando nossos ponteiros para um inteiro
    int a = 7, b = 45;
    int *p = &a, *q = &b; // Ponteiros inicializados corretamente

    // int c = p + q; NUNCA ESQUECER A DERREFÊNCIA
    /// ERRO: invalid operands to binary + (have 'int *' and 'int *')

    // Soma correta dos valores apontados
    int soma = *p + *q;
    printf("Soma dos valores apontados: %d\n", soma);

    printf("\n===============================================\n");

    /* Parte 2: Manipulação de ponteiros */

    // Fazendo uma variável comum obter o conteúdo de um ponteiro que será o `q`
    int valor_via_ponteiro = *q; // Nome mais descritivo
    printf("Valor obtido via ponteiro q: %d\n", valor_via_ponteiro);

    q = &a; // q agora aponta para 'a'

    printf("Endereços:\n");
    printf("a: %p\nb: %p\nq: %p\n", (void *)&a, (void *)&b, (void *)q);
    /// @note: Sim é possível, mas ATENÇÃO, é muito importante o uso de somente 1 endereço ao ponteiro.

    printf("\n===============================================\n");

    /* Parte 3: Desafio lógico */
    printf("Desafio lógico:\n");

    int x = 0, y = 0;
    int *ptr = &y; // Nome mais claro para o ponteiro

    x = *ptr;  // x = 0 (valor de y)
    x = 4;     // x agora é 4
    (*ptr)++;  // y incrementado para 1
    --x;       // x decrementado para 3
    *ptr += x; // y = y + x (1 + 3 = 4)

    // No final, qual o valor de x e y e ptr?
    // printf("Resultados:\nx = %d\ny = %d\n*ptr = %d\n", x, y, *ptr);

    printf("\n===============================================\n");

    /* Parte 4: Atribuição via ponteiros */
    int numero = 20, total = 10;
    int *ptr_numero = &numero, *ptr_total = &total; // Nomes mais descritivos

    *ptr_total = *ptr_numero; // total recebe valor de numero

    printf("Atribuição via ponteiros:\n");
    printf("numero = %d\ntotal = %d\n", numero, total);

    printf("\n=================================================================\n");
    printf("\n\t>>PASSANDO O VALOR DE UM PONTEIRO PARA UMA VARIÁVEL<<\n");

    int num = 'V';
    int other = 'A';
    int *pointer = &other; // <-- APONTA PARA UM ENDEREÇO VÁLIDO

    /**
     * ERRO: num = pointer;
     * warning : assignment to 'int' from 'int *' makes integer from pointer without a cast
     * printf(" O valor da variável num atribuido pelo conteudo do ponteiro pointer : %d\n", num);
     */

    num = *pointer; // Agora OK
    /* Atribui o valor do ponteiro para a variável num usando o operador de desreferência (*). */
    /* Agora num possue o valor de pointer para si, ou seja num agora é 65, em ASCII 'A'. */
    int var = *pointer;

    printf(" O valor da variável 'num' atribuido pelo conteudo do ponteiro pointer : %d-%c\n", num, num);
    printf(" O valor da variável 'var' atribuido pelo conteudo do ponteiro pointer : %d-%c\n", var, var);

    printf("\n===============================================\n");

    /* Parte 5: Expressões complexas */
    int i = 5;
    int *ptr_i = &i; // Nome mais claro

    printf("Expressões com ponteiros:\n");
    printf("%p\t\t(Endereço armazenado em ptr_i)\n", (void *)ptr_i);
    printf("%d\t\t(*ptr_i + 2)\n", (*ptr_i + 2));
    printf("%p\t\t(*&ptr_i)\n", (void *)*&ptr_i);
    printf("%d\t\t(**&ptr_i)\n", **&ptr_i);
    printf("%d\t\t(3 * *ptr_i)\n", (3 * *ptr_i));
    printf("%d\t\t(**&ptr_i + 4)\n", (**&ptr_i + 4));

    /*
     * %x: Imprime o endereço do ponteiro ptr_i em formato hexadecimal.
     * (*ptr_i + 2): é o valor apontado por ptr_i mais 2.
     * *&ptr_i: Aponta e imprime o endereço do ponteiro ptr_i.
     * **&ptr_i: O valor apontado pelo valor apontado por ptr_i.
     * (3 * *ptr_i): 3 vezes o valor apontado por ptr_i.
     * (**&ptr_i + 4): Valor apontado pelo valor apontado por ptr_i, mais 4.
     *
     * A explicação de "**&f" é um pouco confusa, e por mais que você não vá utilizar,
     * entenda que **&f derreferencia os ponteiros suficiente para acessar o valor apontado.
     */
    return 0;
}
