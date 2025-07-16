#include <stdio.h>

/* Utilização de ponteiros em variáveis */

int main(int argc, char **argv)
{
    // Crinado nossos ponteiro para um inteiro
    int *p = NULL;
    int *q = NULL;

    // Criando nossas variáveis
    int a = 7;
    int b = 45;

    p = &a; // o valor de p é o endereço de a
    q = &b; // q aponta para b

    // int c = p + q; NUNCA ESQUECER A DERREFÊNCIA
    /// ERRO: invalid operands to binary + (have 'int *' and 'int *')

    // Soma o conteúdo dos ponteiros
    int c = *p + *q;
    printf("A soma do conteúdo dos ponteiros é : %d\n", c);
    printf("\n===============================================\n");

    // Fazendo uma variável comum obter o conteúdo de um ponteiro que será o `q`
    int varObtemPtrQ = *q;
    printf("Valor de varObtemPtrQ é : %d %c\n", varObtemPtrQ, varObtemPtrQ);

    // Após declarado e inicializado um ponteiro é possível ele obter um outro endereço, exemplo?
    q = &a; // O ponteiro 'q' armazena o endereço de b, é possível substituir por a.

    printf("Endereço de 'a': %p\nEndereço de 'b' %p\nEndereço que o ponteiro 'q' armazena: %p\n", &a, &b, q);
    /// @note: Sim é possível, mas ATENÇÃO, é muito importante o uso de somente 1 endereço ao ponteiro.

    printf("\n===============================================\n");
    printf("\nDesafio lógico\n");

    // Declarando 2 variáveis e 1 ponteiro
    int x = 0, y = 0, *ptr = NULL;

    // y recebe 0
    y = 0;

    // Logo após ptr recebe o endereço de y
    ptr = &y;

    // x recebe o conteúdo de ptr que é y
    x = *ptr;

    // x recebe 4
    x = 4;

    // Incrementa o valor para o qual p aponta. Neste caso, incrementa y de 0 para 1.
    (*ptr)++;

    // Decrementa x em 1. Assim, x passa a ser 3 (pois estava 4 antes).
    --x;

    // Adiciona o valor de x ao valor para o qual p aponta. x é 3 e y (para o qual p aponta) é 1.
    // neste ponto então, y se torna 1 + 3 = 4.
    (*ptr) += x;

    // No final, qual o valor de x e y e ptr?
    // printf("x= %d  y= %d *p= %d", x, y, *ptr);

    printf("\n===============================================\n");

    int *pointer = NULL, *pointer1 = NULL;
    int numero = 20, total = 10;

    pointer = &numero;
    pointer1 = &total;

    // A variável apontada por ptr1 recebe o mesmo conteúdo da variável apontada por ptr;
    *pointer1 = *pointer;
    printf("Numero = %d\n", numero);
    printf("Total = %d", total);

    printf("\n===============================================\n");

    int i = 5;
    int *f = &i;

    // O que será impresso?
    printf("\n%x, %d, %x, %d, %d, %d", f, (*f + 2), *&f, **&f, (3 * *f), (**&f + 4));

    /*
     * %x: Imprime o endereço do ponteiro f em formato hexadecimal.
     * (*f + 2): é o valor apontado por f mais 2.
     * *&f: Aponta e imprime o endereço do ponteiro f.
     * **&f: O valor apontado pelo valor apontado por f.
     * (3 * *f): 3 vezes o valor apontado por f.
     * (**&f + 4): Valor apontado pelo valor apontado por f, mais 4.
     *
     * A explicação de "**&f" é um pouco confusa, e por mais que você não vá utilizar,
     * entenda que **&f derreferencia os ponteiros suficiente para acessar o valor apontado.
     */
    return 0;
}
