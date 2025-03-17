#include <stdio.h>

int main(int argc, char **argv)
{
    // Valor de uma variável char declarado
    char valor = 'A';

    printf("**************************************\n");
    printf("Valor antes do incremento : %c\n", valor);
    printf("Endereço de \"valor\"     : %p\n", &valor);
    printf("**************************************\n");

    // Ponteiro recebe o endereço de valor, para incrementar
    char *ptrIncrementador = &valor;

    printf("\n*************************************************\n");
    printf("Endereço de \"ptrIncrementador\"            : %p\n", &ptrIncrementador);
    printf("Valor de \"ptrIncrementador\" do incremento : %c\n", *ptrIncrementador);
    printf("Endereço de \"ptrIncrementador\"            : %p\n", ptrIncrementador);
    printf("*************************************************\n");

    // Incrementando com o ponteiro, obrigatório os parênteses
    (*ptrIncrementador)++;
    printf("Valor depois do incremento : %c\n", *ptrIncrementador);

    // Incrementando com o ponteiro
    (*ptrIncrementador)++;
    printf("Valor depois do incremento : %c\n", *ptrIncrementador);
    return 0;
}
