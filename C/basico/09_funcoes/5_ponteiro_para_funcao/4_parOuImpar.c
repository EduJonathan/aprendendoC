#include <stdio.h>

/**
 * @brief Informa se o valor é par
 */
void par(void) { printf("O número é par!!!\n"); }

/**
 * @brief Informa se o valor é impar
 */
void impar(void) { printf("O número é impar!!!\n"); }

// Agora 'fparOuImpar' é um sinônimo para um ponteiro para função que não tem retorno
typedef void (*parOuImpar)(void);

/**
 * Declaração de um ponteiro para função com typedef:
 * SINTAXE: typedef tipoDoRetorno(*nomeDoPonteiroParaFunção)(arg1, arg2, ...,)
 * Caso fizemos: `typedef void *parOuImpar(void);` se não colocasse os parênteses
 * o compilador entenderia que o retorno é um ponteiro para void, sendo que queremos o
 * retorno seja para void, e que o nome desse tipo de ponteiro para função seja parOuImpar.
 */

int main(int argc, char **argv)
{
    int eImparOuPar = 45;
    parOuImpar aponta;

    // Se eImparOuPar é par ou ímpar, atribui à variável aponta o endereço da função par ou impar.
    if ((eImparOuPar % 2) == 0)
    {
        aponta = par;
    }
    else
    {
        aponta = impar;
    }

    // Chama a função referenciada pelo ponteiro
    (aponta)();

    // Esta linha dereferencia o ponteiro da função e chama a função referenciada.
    // Ou seja, se aponta foi atribuído à função par, então (aponta)(); chamará par();.
    // Se aponta foi atribuído à função impar, então (aponta)(); chamará impar();
    return 0;
}
