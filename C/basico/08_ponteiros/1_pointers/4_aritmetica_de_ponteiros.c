#include <stdio.h>

/*
 * A aritmética de ponteiros é uma característica da linguagem de programação C, permitindo
 * que realize operações aritméticas diretamente sobre os endereços de memória apontados
 * por ponteiros. Isso pode ser útil para navegar por arrays, estruturas ou qualquer bloco
 * contíguo de memória. Neste código estarei mostrando aritmética de ponteiro em operadores
 * aritméticos e incremento e decremento
 */

int main(int argc, char **argv)
{
    printf("\n\tOPERAÇÕES MATEMÁTICAS COM PONTEIROS:\n");
    printf("\n=============================================================================\n");

    /**
     * LEMBRANDO: Sempre que quisermos utilizar valores que ponteiros estão obtendo de
     * uma varíavel através do endereço da varíavel, devemos lembrar da derreferencia que
     * é o '*' antes do ponteiro, pois é assim que trabalharmos diretamente com o conteúdo
     * do ponteiro.
     */

    // Valores para realizar as operações
    float n1 = 89, n2 = 56;

    // Variáveis para armazenar os conteúdos das operações
    float soma, subtracao, multiplicacao, divisao, resto;

    // Declarando ponteiros p1 e p2 para tipos floats
    float *p1, *p2;

    p1 = &n1; // ponteiro p1 recebe conteúdo de n1
    p2 = &n2; // ponteiro p2 recebe conteúdo de n2

    // soma do conteúdo apontado por p1 + p2
    soma = *p1 + *p2;
    // soma = (*p1) + (*p2); || soma = *(p1) + *(p2);

    // subtração do conteúdo apontado por p1 - p2
    subtracao = *p1 - *p2;
    // subtracao = (*p1) - (*p2); || subtracao = *(p1) - *(p2);

    // multiplicação do conteúdo apontado por p1 * p2
    multiplicacao = *p1 * *p2;
    // multiplicacao = (*p1) * (*p2); || multiplicacao = *(p1) * *(p2);

    // divisão do conteúdo apontado por p1 / p2
    divisao = *p1 / *p2;
    // divisao = (*p1) / (*p2); || divisao = *(p1) / *(p2);

    // o resto do conteúdo apontado por p1 % p2
    resto = (float)((int)*p1 % (int)*p2);
    // resto = (float)((int)(*p1) % (int)(*p2)); || resto = (float)((int)*(p1) % (int)*(p2));

    printf(" A soma do conteúdo dos ponteiros: %.2f + %.2f é = %.2f\n", *p1, *p2, soma);
    printf(" A subtração do conteúdo dos ponteiros: %.2f - %.2f é = %.2f\n", *p1, *p2, subtracao);
    printf(" A multiplicação do conteúdo dos ponteiros: %.2f * %.2f é = %.2f\n", *p1, *p2, multiplicacao);
    printf(" A divisão do conteúdo dos ponteiros: %.2f / %.2f é = %.2f\n", *p1, *p2, divisao);
    printf(" O resto da divisão do conteúdo dos ponteiros: %.2f %% %.2f é = %.2f\n", *p1, *p2, resto);

    printf("\n=============================================================================\n");
    printf("\n\tINCREMENTO E DECREMENTO:\n");

    int v1 = 5, v2 = 12;
    int *pointer1, *pointer2;

    pointer1 = &v1;
    pointer2 = &v2;

    printf("\n=============================================================================\n");
    printf("\n\t EXTRAINDO INFORMAÇÕES SOBRE\n");

    printf(" CONTEÚDO DE v1: %d | ENDEREÇO DE v1: %p\n", v1, &v1, &v1);
    printf(" CONTEÚDO DE v2: %d | ENDEREÇO DE v2: %p\n", v2, &v2, &v2);
    printf(" ENDEREÇO DE pointer1 : %p | ENDEREÇO DE pointer2 : %p\n", &pointer1, &pointer2);
    printf(" ENDEREÇO QUE pointer1 APONTA: %p | ENDEREÇO QUE pointer2 APONTA: %p\n", pointer1, pointer2);
    printf(" CONTEÚDO QUE pointer1 APONTA: %d | CONTEÚDO QUE pointer2 APONTA: %d\n", *pointer1, *pointer2);

    printf("\n=============================================================================\n");

    ++(*pointer1);
    (*pointer2)++;
    // Obrigatório o uso dos parênteses para o incremento da unidade de valor a direita
    // primeiro precisamos desreferenciar, para depois aplicar o incremento,
    // caso fizer: *pointer2++ Acontecerá que a próxima região de memória seja apontada

    printf(" CONTEÚDO DE v1: %d CONTEÚDO DE v2: %d CONTEÚDO DE pointer1: %d CONTEÚDO DE pointer2: %d\n", v1, v2, *pointer1, *pointer2);

    ++*pointer1;
    *pointer2++;

    /*
     * ++*pointer1: Incrementa novamente o valor apontado por pointer1 (o valor de v1).
     *
     * *pointer2++: Aqui está uma armadilha comum. Isso é interpretado como *(pointer2++),
     * pois significa que primeiro avalia o valor apontado por pointer2 (desreferencia) e
     * depois incrementa o ponteiro. Isso resulta em um valor não incrementado de v2 sendo
     * impresso. O valor de pointer2 também será incrementado, mas não será usado nesta instrução.
     * Devido também ao precedência do operador de incremento, o valor de pointer2 é incrementado
     * após a desreferenciação, o que significa que o ponteiro pointer2 agora aponta para o próximo
     */

    printf(" CONTEÚDO DE v1: %d CONTEÚDO DE v2: %d CONTEÚDO DE pointer1: %d CONTEÚDO DE pointer2: %d\n", v1, v2, *pointer1, *pointer2);
    return 0;
}
