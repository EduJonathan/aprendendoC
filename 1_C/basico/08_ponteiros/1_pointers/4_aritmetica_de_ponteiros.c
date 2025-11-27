#include <stdio.h>

/**
 * A aritmética de ponteiros é um recurso da linguagem C que permite realizar operações
 * diretamente sobre endereços de memória armazenados em ponteiros.
 * Esse recurso é especialmente útil para percorrer arrays, estruturas ou qualquer região
 * contínua de memória. No código a seguir, serão demonstrados exemplos de
 * aritmética de ponteiros com operadores aritméticos, além das operações de incremento e decremento.
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

    float n1 = 89.0f, n2 = 56.0f;

    // Ponteiros para n1 e n2
    float *p1 = &n1;
    float *p2 = &n2;

    // Operações aritméticas usando desreferenciação
    float soma = *p1 + *p2;
    float subtracao = *p1 - *p2;
    float multiplicacao = *p1 * *p2;
    float divisao = *p1 / *p2;
    float resto = (float)((int)*p1 % (int)*p2); // resto exige inteiros

    printf("Soma:          %.2f + %.2f = %.2f\n", *p1, *p2, soma);
    printf("Subtração:     %.2f - %.2f = %.2f\n", *p1, *p2, subtracao);
    printf("Multiplicação: %.2f * %.2f = %.2f\n", *p1, *p2, multiplicacao);
    printf("Divisão:       %.2f / %.2f = %.2f\n", *p1, *p2, divisao);
    printf("Resto (int):   %.2f %% %.2f = %.2f\n", *p1, *p2, resto);

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
    int *pointer1 = &v1;
    int *pointer2 = &v2;

    printf("\n=============================================================================\n");
    printf("\n-- Endereços e Conteúdos Iniciais --\n");

    printf("v1: %d (endereço %p)\n", v1, (void *)&v1);
    printf("v2: %d (endereço %p)\n", v2, (void *)&v2);
    printf("pointer1 aponta para %p, pointer2 aponta para %p\n",
           (void *)pointer1, (void *)pointer2);

    printf("\n=============================================================================\n");

    // Incremento e decremento utilizando os ponteiros
    ++(*pointer1); // Incrementa o valor de v1 (apontado por pointer1)
    (*pointer2)++; // Incrementa o valor de v2 (apontado por pointer2)

    // Mostra o conteúdo após incremento
    printf(" CONTEÚDO DE v1: %d CONTEÚDO DE v2: %d CONTEÚDO DE pointer1: %d CONTEÚDO DE pointer2: %d\n", v1, v2, *pointer1, *pointer2);

    printf("\nApós ++(*pointer1) e (*pointer2)++:\n");
    printf("v1 = %d, v2 = %d\n", v1, v2);

    // Diferença entre ++*p e *p++
    ++*pointer1; // incrementa o valor apontado por pointer1 (v1)
    *pointer2++; // incrementa o ponteiro pointer2 (não o valor de v2!)

    /*
     * ++*pointer1 -> Incrementa o valor armazenado no endereço apontado.
     *
     * *pointer2++ -> Incrementa o ponteiro primeiro, depois tenta acessar o valor
     *                antigo (atenção: pode gerar comportamento indefinido se não
     *                houver memória válida adiante).
     */

    printf("\nApós ++*pointer1 e *pointer2++:\n");
    printf("v1 = %d, v2 = %d\n", v1, v2);
    printf("pointer2 agora aponta para %p\n", (void *)pointer2);
    return 0;
}
