#include <stdio.h>

/* Este código demonstra o uso e comportamento de chaves "{}" nos if's */

int main(int argc, char **argv)
{
    printf("\n========================================================\n");
    printf("\t>>EXEMPLO 01: Sem chaves no IF<<\n");

    // Condição verdadeira (1 == 1)
    // Aqui o primeiro printf é executado, mas os próximos printf são sempre executados
    if (1 == 1)             // Condição verdadeira
        printf("True\n");   // Executado
    printf("Verdadeiro\n"); // Executado (independente da condição)
    printf("False\n");      // Executado (independente da condição)
    printf("Falso\n");      // Executado (independente da condição)

    /**
     * OUTPUT:
     * True
     * Verdadeiro
     * False
     * Falso
     */

    printf("\n========================================================\n");
    printf("\t>>EXEMPLO 02: Condição falsa<<\n");

    // Condição falsa (1 == 2)
    // O primeiro printf não é executado, mas os outros são sempre executados
    if (1 == 2)               // Condição falsa
        printf("True\n");     // Não executado
    printf("\nVerdadeiro\n"); // Executado
    printf("False\n");        // Executado
    printf("Falso\n");        // Executado

    /**
     * OUTPUT:
     * Verdadeiro
     * False
     * Falso
     */

    printf("\n========================================================\n");
    printf("\t>>EXEMPLO 03: Vários if's sem chaves<<\n");

    // Vários if's, sem chaves, cada um executando de forma independente
    if (1 == 1)                 // Condição verdadeira
        printf("True\n");       // Executado
    if (1 != 2)                 // Condição verdadeira
        printf("Verdadeiro\n"); // Executado
    printf("False\n");          // Executado
    printf("Falso\n");          // Executado

    /**
     * OUTPUT:
     * True
     * Verdadeiro
     * False
     * Falso
     */

    printf("\n========================================================\n");
    printf("\t>>EXEMPLO 04: Condições falsas em if's separados<<\n");

    // Condições falsas em if's separados, sem execução de printf dentro dos if's
    if (1 == 2)            // Condição falsa
        printf("False\n"); // Não executado
    if (2 != 2)            // Condição falsa
        printf("Falso\n"); // Não executado
    printf("False\n");     // Executado
    printf("Falso\n");     // Executado

    /**
     * OUTPUT:
     * False
     * Falso
     */

    printf("\n========================================================\n");
    printf("\t>>EXEMPLO 05: Usando chaves para agrupar instruções<<\n");

    // Usando chaves para agrupar várias instruções dentro do if
    if (1 == 1) // Condição verdadeira
    {
        printf("\nTrue\n");     // Executado
        printf("Verdadeiro\n"); // Executado
        printf("False\n");      // Executado
        printf("Falso\n");      // Executado
    }

    /**
     * OUTPUT:
     * True
     * Verdadeiro
     * False
     * Falso
     */

    printf("\n========================================================\n");
    printf("\t>>EXEMPLO 06: Usando chaves com condição falsa<<\n");

    // Usando chaves com condição falsa - Nenhuma instrução é executada
    if (1 == 2) // Condição falsa
    {
        printf("\nTrue\n");     // Não executado
        printf("Verdadeiro\n"); // Não executado
        printf("False\n");      // Não executado
        printf("Falso\n");      // Não executado
    }

    /**
     * OUTPUT:
     * Nenhuma saída
     */

    /**
     * @note O uso de chaves vem na visão do programador, ou seja na tese não tem problema
     * em não utilizar {}, mas é recomendado o uso para evitar confusão no controle de fluxo.
     * Mesmo que o uso de chaves não seja obrigatório,
     * elas ajudam a garantir que todas as instruções sejam executadas corretamente dentro
     * de um bloco condicional.
     */

    return 0;
}
