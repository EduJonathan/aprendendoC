#include <stdio.h>

// Utilizando ponteiros nas condicionais if's

int main(int argc, char **argv)
{
    // Criando um ponteiro nulo
    int *pointer = NULL;

    // Checa se o ponteiro está nulo
    if (pointer == NULL)
    {
        printf("PONTEIRO CONTINUA NULO...%p\n", pointer);
    }
    else
    {
        printf("PONTEIRO OBTEVE UM VALOR...%p\n", pointer);
    }

    // Criando uma variável inicializada com valor 78
    int valor = 78;

    // Endereço de valor
    printf("O Endereço de valor é : %p\n", &valor);

    /* Ponteiro recebe o endereço de valor. */
    pointer = &valor;

    /* Checa novamente se o ponteiro está nulo. */
    if (pointer == NULL)
    {
        printf("PONTEIRO CONTINUA NULO...%p\n", pointer);
    }
    else
    {
        printf("PONTEIRO OBTEVE UM ENDEREÇO...%p\n", pointer);
        printf("PONTEIRO OBTEVE UM VALOR...%d\n", *pointer);
    }

    /* Checa se o conteúdo que pointer aponta é igual a. */
    if (*pointer == 78)
    {
        printf("O VALOR %d é igual a 78\n", *pointer);
    }
    else
    {
        printf("O VALOR %d não é igual a 78\n", *pointer);
    }

    /* Criando um ponteiro nulo. */
    int *ptr = NULL;

    /** CURIOSIDADE: É possível fazer comparações de endereços de memória. */
    if (pointer > ptr)
    {
        printf("O ENDEREÇO DE pointer1: %p é maior que a de ptr: %p\n", &pointer, &ptr);
    }
    else
    {
        printf("O ENDEREÇO DE pointer1: %p é menor que a de ptr: %p\n", &pointer, &ptr);
    }
    return 0;
}
