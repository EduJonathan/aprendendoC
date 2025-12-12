#include <stdio.h>

/*
 * VOID POINTER (ponteiro para void):
 *
 * Um ponteiro para void é um tipo especial de ponteiro capaz de armazenar o endereço
 * de qualquer tipo de dado. Ele é amplamente utilizado na implementação de funções e
 * estruturas de dados genéricas, permitindo manipular diferentes tipos sem duplicar código.
 *
 * IMPORTANTE:
 * Um ponteiro void **não pode ser desreferenciado diretamente**, pois o compilador
 * não conhece o tipo nem o tamanho do dado ao qual ele aponta. Para acessar o valor,
 * é necessário converter (cast) o ponteiro para um tipo específico antes da
 * desreferenciação.
 *
 * Exemplo:
 *
 *     void *p;
 *     int x = 10;
 *     p = &x;
 *     printf("%d\n", *(int *)p); // conversão antes da desreferência
 */

int main(int argc, char **argv)
{
    printf("\n-----------------------------------------------------\n");
    printf("\n\t\t>> VOID POINTERS <<\n");
    printf("\n-----------------------------------------------------\n");
    printf("\t>> IMPRIMINDO INFORMAÇÕES DAS VARIÁVEIS\n\n");

    int a = 10;
    float b = 5.5f;
    char ch = 'b';

    printf(" CONTEÚDO 'a'  = %d   | ENDEREÇO 'a'  = %p\n", a, (void *)&a);
    printf(" CONTEÚDO 'b'  = %.2f | ENDEREÇO 'b'  = %p\n", b, (void *)&b);
    printf(" CONTEÚDO 'ch' = %c   | ENDEREÇO 'ch' = %p\n", ch, (void *)&ch);

    printf("\n=====================================================\n");
    printf("\t>> PONTEIRO VOID APONTANDO PARA INT\n\n");

    void *voidPtr = NULL;
    printf(" Valor inicial do ponteiro (NULL) : %p\n", (void *)voidPtr);

    voidPtr = &a;
    printf(" Endereço do ponteiro voidPtr     : %p\n", (void *)&voidPtr);
    printf(" Valor armazenado no ponteiro     : %p\n", (void *)voidPtr);
    printf(" Valor desreferenciado (int)      : %d\n", *(int *)voidPtr);

    printf("\n=====================================================\n");
    printf("\t>> PONTEIRO VOID APONTANDO PARA FLOAT\n\n");

    voidPtr = &b;
    printf(" Valor armazenado no ponteiro     : %p\n", (void *)voidPtr);
    printf(" Valor desreferenciado (float)    : %.2f\n", *(float *)voidPtr);

    /*
     * ERRO CONCEITUAL (comentado):
     * O ponteiro aponta para float, mas o cast é double.
     * Isso gera comportamento indefinido.
     */
    /* printf(" ERRO: %lf\n", *(double *)voidPtr); */

    printf("\n=====================================================\n");
    printf("\t>> PONTEIRO VOID APONTANDO PARA CHAR\n\n");

    voidPtr = &ch;
    printf(" Valor armazenado no ponteiro     : %p\n", (void *)voidPtr);
    printf(" Valor desreferenciado (char)     : %c\n", *(char *)voidPtr);
    printf(" Valor ASCII do char              : %d\n", (int)*(char *)voidPtr);

    /*
     * ERRO CONCEITUAL (comentado):
     * Cast incorreto gera lixo de memória.
     */
    /* printf(" ERRO: %d\n", *(int *)voidPtr); */

    printf("\n=====================================================\n");
    return 0;
}
