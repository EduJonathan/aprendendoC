#include <stdio.h>

/*
 * A aritmética de ponteiros é uma característica da linguagem de programação C, permitindo
 * que realize operações aritméticas diretamente sobre os endereços de memória apontados
 * por ponteiros. Isso pode ser útil para navegar por arrays, estruturas ou qualquer bloco
 * contíguo de memória. Neste código estarei mostrando aritmética de ponteiro em operadores
 * aritméticos e incremento e decremento.
 */

int main(int argc, char **argv)
{
    printf("\n\tOPERAÇÕES MATEMÁTICAS COM PONTEIROS:\n");
    printf("\n=============================================================================\n");

    /**
     * LEMBRANDO: Sempre que quisermos utilizar valores que ponteiros estão obtendo de
     * uma variável através do endereço da variável, devemos lembrar da derreferência que
     * é o '*' antes do ponteiro, pois é assim que trabalhamos diretamente com o conteúdo
     * do ponteiro.
     */

    // Valores para realizar as operações
    float n1 = 89, n2 = 56;

    // Variáveis para armazenar os conteúdos das operações
    float soma = 0.0f, subtracao = 0.0f, multiplicacao = 0.0f, divisao = 0.0f, resto = 0.0f;

    // Declarando ponteiros p1 e p2 para tipos floats
    float *p1 = NULL, *p2 = NULL;

    p1 = &n1; // ponteiro p1 recebe o endereço de n1
    p2 = &n2; // ponteiro p2 recebe o endereço de n2

    // Operações matemáticas utilizando os valores apontados pelos ponteiros
    soma = *p1 + *p2;                     // soma = conteúdo de p1 + conteúdo de p2
    subtracao = *p1 - *p2;                // subtração = conteúdo de p1 - conteúdo de p2
    multiplicacao = *p1 * *p2;            // multiplicação = conteúdo de p1 * conteúdo de p2
    divisao = *p1 / *p2;                  // divisão = conteúdo de p1 / conteúdo de p2
    resto = (float)((int)*p1 % (int)*p2); // resto = (conteúdo de p1) % (conteúdo de p2), convertido para inteiro

    // Imprime os resultados das operações
    printf(" A soma do conteúdo dos ponteiros: %.2f + %.2f é = %.2f\n", *p1, *p2, soma);
    printf(" A subtração do conteúdo dos ponteiros: %.2f - %.2f é = %.2f\n", *p1, *p2, subtracao);
    printf(" A multiplicação do conteúdo dos ponteiros: %.2f * %.2f é = %.2f\n", *p1, *p2, multiplicacao);
    printf(" A divisão do conteúdo dos ponteiros: %.2f / %.2f é = %.2f\n", *p1, *p2, divisao);
    printf(" O resto da divisão do conteúdo dos ponteiros: %.2f %% %.2f é = %.2f\n", *p1, *p2, resto);

    printf("\n=============================================================================\n");
    printf("\n\tINCREMENTO E DECREMENTO:\n");

    // Variáveis inteiras para incremento e decremento
    int v1 = 5, v2 = 12;
    int *pointer1 = NULL, *pointer2 = NULL;

    pointer1 = &v1; // ponteiro pointer1 aponta para v1
    pointer2 = &v2; // ponteiro pointer2 aponta para v2

    printf("\n=============================================================================\n");
    printf("\n\t EXTRAINDO INFORMAÇÕES SOBRE\n");

    // Mostrando os valores e endereços das variáveis e ponteiros
    printf(" CONTEÚDO DE v1: %d | ENDEREÇO DE v1: %p\n", v1, &v1);
    printf(" CONTEÚDO DE v2: %d | ENDEREÇO DE v2: %p\n", v2, &v2);
    printf(" ENDEREÇO DE pointer1 : %p | ENDEREÇO DE pointer2 : %p\n", &pointer1, &pointer2);
    printf(" ENDEREÇO QUE pointer1 APONTA: %p | ENDEREÇO QUE pointer2 APONTA: %p\n", pointer1, pointer2);
    printf(" CONTEÚDO QUE pointer1 APONTA: %d | CONTEÚDO QUE pointer2 APONTA: %d\n", *pointer1, *pointer2);

    printf("\n=============================================================================\n");

    // Incremento e decremento utilizando os ponteiros
    ++(*pointer1); // Incrementa o valor de v1 (apontado por pointer1)
    (*pointer2)++; // Incrementa o valor de v2 (apontado por pointer2)

    // Mostra o conteúdo após incremento
    printf(" CONTEÚDO DE v1: %d CONTEÚDO DE v2: %d CONTEÚDO DE pointer1: %d CONTEÚDO DE pointer2: %d\n", v1, v2, *pointer1, *pointer2);

    ++*pointer1; // Incrementa o valor apontado por pointer1 (v1)
    *pointer2++; // Incrementa pointer2 (não o valor apontado por pointer2, mas o ponteiro em si)

    /**
     * DIFERENÇA ENTRE ++*pointer1 E *pointer2++:
     *
     * ++*pointer1: Incrementa o valor armazenado no endereço apontado por pointer1 (ou seja, o valor de v1).
     *
     * *pointer2++: Uma armadilha comum. O operador de incremento (++) tem maior precedência
     * que o operador de desreferenciação (*). Isso significa que primeiro pointer2 é
     * incrementado, e depois o valor armazenado no endereço original de pointer2 é acessado.
     * Portanto, o valor de v2 não é incrementado, mas o ponteiro pointer2 é movido para
     * o próximo endereço de memória.
     */

    // Exibe o conteúdo após o segundo incremento
    printf(" CONTEÚDO DE v1: %d CONTEÚDO DE v2: %d CONTEÚDO DE pointer1: %d CONTEÚDO DE pointer2: %d\n", v1, v2, *pointer1, *pointer2);
    return 0;
}
