#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Definição da estrutura 'st' que contém
 */
struct st
{
    int n;      /**< Campo para armazenar um valor inteiro 'n' */
    bool Bool;  /**< Campo para armazenar um dado booleano */
    int indice; /**< Campo para armazenar um valor inteiro 'indice' */
};

int main(int argc, char **argv)
{
    // Declaração e inicialização da variável 'IF' do tipo 'struct st' com 'n' inicializado para 3
    struct st IF = {3};

    // Declaração e inicialização da variável 'PI' como um inteiro com valor 3
    int PI = 3;

    // Verifica se 'IF.n' é igual a 'PI'
    if (IF.n == PI)
    {
        // Imprime se a condição do 'if' for verdadeira
        printf("A informação do dado da struct está correta\n");
    }
    else
    {
        // Imprime se a condição do 'if' for falsa
        printf("A informação do dado da struct não está correta\n");
    }

    printf("\n------------------------------\n");

    // Declaração e inicialização de uma struct `BOOL` com `Bool` inicializado para verdadeiro.
    struct st BOOL = {.Bool = true};

    // Loop 'while' que continua enquanto 'BOOL.Bool' for verdadeiro (valor 1)
    while (BOOL.Bool == 1)
    {
        // Incrementa 'IF.n' em cada iteração do loop
        IF.n++;

        // Imprimindo o valor atualizado de 'IF.n'
        printf("O VALOR IF.n foi atualizado para : %d\n", IF.n);

        // Verifica se 'IF.n' é maior ou igual a 5
        if (IF.n >= 5)
        {
            BOOL.Bool = false; // Define 'BOOL.Bool' como falso
            break;             // Sai do loop 'while'
        }
    }

    printf("\n------------------------------\n");
    struct st i = {.indice = 0};

    // Loop 'for' que continua enquanto 'i.indice' for menor que 10
    for (; i.indice < 10; i.indice++)
    {
        // Imprimindo o valor atualizado de 'i.indice'
        printf("O VALOR i.indice foi atualizado para : %d\n", i.indice);
    }
    return 0;
}
