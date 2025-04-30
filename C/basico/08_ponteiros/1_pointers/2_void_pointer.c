#include <stdio.h>

/*
 * void pointer (ponteiro para void): É um tipo especial de ponteiro que pode armazenar
 * o endereço de qualquer tipo de dado. É útil em situações em que se deseja criar
 * funções ou estruturas de dados genéricas, capazes de manipular diferentes tipos
 * sem a necessidade de criar versões específicas para cada um.
 *
 * Atenção: a desreferenciação de um ponteiro void só pode ser feita após a conversão
 * explícita para outro tipo de ponteiro, pois o compilador não sabe o tamanho ou o tipo
 * de dado apontado.
 */

int main(int argc, char **argv)
{
    printf("\n-----------------------------------------------------\n");
    printf("\n\t\t>>VOID POINTERS<<\n");
    printf("\n-----------------------------------------------------\n");
    printf("\t>>IMPRIMINDO INFORMAÇÕES SOBRE\n");

    int a = 10;
    float b = 5.5;
    char ch = 'b';

    printf(" CONTEÚDO DA VARIÁVEL 'a'  = %d ENDEREÇO DA VARIÁVEL   'a'  = %p\n", a, &a);
    printf(" CONTEÚDO DA VARIÁVEL 'b'  = %.2f ENDEREÇO DA VARIÁVEL 'b'  = %p\n", b, &b);
    printf(" CONTEÚDO DA VARIÁVEL 'ch' = %c ENDEREÇO DA VARIÁVEL   'ch' = %p\n", ch, &ch);

    printf("\n=============================================================================\n");
    printf("\t>>IMPRIMINDO INFORMAÇÕES SOBRE voidToPointerInt\n");

    /* Inserindo NULL em voidToPointerInt e atribuindo para receber o endereço da variável `a`*/
    void *voidToPointerInt = NULL;
    printf(" O Valor do ponteiro quando inserirmos NULL       : %p\n", voidToPointerInt);

    /* Atribuindo o endereço de memória a cada ponteiro `void`. */
    voidToPointerInt = &a;

    /* Imprimindo as informações. */
    printf(" O endereço de memória de voidToPointerInt        : %p\n", &voidToPointerInt);
    printf(" O Valor do ponteiro voidToPointerInt aponta para : %p\n", voidToPointerInt);

    printf("\n=============================================================================\n");
    printf("\t>>IMPRIMINDO INFORMAÇÕES SOBRE voidToPointerFloat\n");

    /* Inserindo NULL em voidToPointerFloat e atribuindo para recebe o endereço da variável `b` */
    void *voidToPointerFloat = NULL;
    printf(" O Valor do ponteiro quando inserirmos NULL         : %p\n", voidToPointerFloat);

    /* Atribuindo o endereço de memória a cada ponteiro `void`. */
    voidToPointerFloat = &b;

    /* Imprimindo as informações. */
    printf(" O endereço de memória de voidToPointerFloat        : %p\n", &voidToPointerFloat);
    printf(" O Valor do ponteiro voidToPointerFloat aponta para : %p\n", voidToPointerFloat);

    printf("\n=============================================================================\n");
    printf("\t>>IMPRIMINDO INFORMAÇÕES SOBRE voidToPointerChar\n");

    /* Inserindo NULL em voidToPointerChar e atribuindo receber o endereço da variável `ch`. */
    void *voidToPointerChar = NULL;
    printf(" O Valor do ponteiro quando inserirmos NULL        : %p\n", voidToPointerChar);

    /* Atribuindo o endereço de memória a cada ponteiro `void`. */
    voidToPointerChar = &ch;

    /* Imprimindo as informações. */
    printf(" O endereço de memória de voidToPointerChar        : %p\n", &voidToPointerChar);
    printf(" O Valor do ponteiro voidToPointerChar aponta para : %p\n", voidToPointerChar);

    printf("\n=============================================================================\n");
    printf("\t>>DERREFERENCIANDO CADA PONTEIRO VOID\n");

    printf(" TYPE-CASTING INT: %d\n", *(int *)voidToPointerInt);
    printf(" TYPE-CASTING FLOAT: %f\n", *(float *)voidToPointerFloat);
    /* printf(" TYPE-CASTING FLOAT: %lf\n", *(double *)voidToPointerFloat); 0.0000 */

    printf(" TYPE-CASTING CHAR: %c\n", *(char *)voidToPointerChar);
    printf(" TYPE-CASTING CHAR(ASCII): %d\n", *(char *)voidToPointerChar); // 98: b na tabela ASCII
    /* printf(" TYPE-CASTING CHAR: %d\n", *(int *)voidToPointerChar); lixo de memoria. */
    return 0;
}
