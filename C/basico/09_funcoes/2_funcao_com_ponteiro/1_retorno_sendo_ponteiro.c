#include <stdio.h>

/**
 * @brief Retorna o ponteiro para o maior valor entre dois valores flutuantes.
 *
 * Esta função compara os valores apontados por `n1` e `n2` e retorna o ponteiro
 * para o maior valor.
 *
 * @param n1 Ponteiro para o primeiro valor flutuante.
 * @param n2 Ponteiro para o segundo valor flutuante.
 * @return Um ponteiro para o valor flutuante que é maior entre `n1` e `n2`.
 */
float *minimo(float *n1, float *n2)
{
    if (*n1 < *n2)
    {
        // Retorna o ponteiro para o maior valor
        return n1;
    }

    // Retorna o ponteiro para o maior valor
    return n2;
}

/**
 * @brief Retorna o ponteiro para o maior valor entre dois valores inteiros.
 *
 * Esta função compara os valores apontados por `n1` e `n2` e retorna o ponteiro para o
 * maior valor. A função usa um operador ternário para determinar o maior valor entre os
 * dois ponteiros. A verificação adicional `if` é redundante e foi removida para simplificação.
 *
 * @param n1 Ponteiro para o primeiro valor inteiro.
 * @param n2 Ponteiro para o segundo valor inteiro.
 * @return Um ponteiro para o valor inteiro que é maior entre `n1` e `n2`.
 */
int *max(int *n1, int *n2)
{
    // Comparando os valores em operações térnaria tanto se é menor quanto maior
    int *maior = (n1 > n2) ? n1 : n2;
    int *menor = (n1 < n2) ? n2 : n1;

    // Se for maior retorne o maior numero se não
    if (*maior > *menor)
    {
        return maior;
    }

    // Se for menor retorne o menor
    return menor;
}

/**
 * @brief Retorna o ponteiro para o caractere que é diferente entre dois caracteres.
 *
 * Esta função compara os caracteres apontados por `letra1` e `letra2` e retorna o ponteiro
 * para o caractere que é diferente. Se os caracteres forem iguais, a função retorna o ponteiro
 * para `letra2`.
 *
 * @param letra1 Ponteiro para o primeiro caractere.
 * @param letra2 Ponteiro para o segundo caractere.
 * @return Um ponteiro para o caractere que é diferente entre `letra1` e `letra2`.
 * Se ambos forem iguais
 */
const char *letraIsDiferente(char *letra1, char *letra2)
{
    // Comparando os caracteres
    return (*letra1 == *letra2) ? "true" : "false";
}

int main(int argc, char **argv)
{
    int intN1 = 23;
    int intN2 = 14;
    int *maximo = NULL;

    maximo = max(&intN1, &intN2);
    printf("O maior numero e: %d\n", *maximo);

    printf("\n----------------------------------\n");

    float floatN1 = 60.0F;
    float floatN2 = 59.0F;

    float *Min = minimo(&floatN1, &floatN2);
    printf("O maior numero e: %f\n", *Min);

    printf("\n----------------------------------\n");

    char charN1 = 'A';
    char charN2 = 'A';

    const char *diferente = letraIsDiferente(&charN1, &charN2);
    printf("As letras são iguais? %s\n", diferente);
    return 0;
}
