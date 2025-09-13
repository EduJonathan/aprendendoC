#include <stdio.h>

/**
 * ENUMS: Conjunto de valores nomeados que representam constantes simbólicas, Os enums
 * fornecem uma forma conveniente de trabalhar com conjuntos fixos de constantes
 * relacionadas em um programa.
 */

/**
 * @enum semana
 *
 * @brief Enumeração que representa os dias da semana. Esta enumeração define os dias da
 * semana usando valores inteiros para facilitar a manipulação e comparação de dias.
 * Os valores são atribuídos automaticamente, começando por 0 para `Domingo` 
 * e incrementando de 1 em 1.
 */
enum semana
{
    Domingo, /**< Representa o primeiro dia da semana (valor 0) */
    Segunda, /**< Representa o segundo dia da semana (valor 1) */
    Terca,   /**< Representa o terceiro dia da semana (valor 2) */
    Quarta,  /**< Representa o quarto dia da semana (valor 3) */
    Quinta,  /**< Representa o quinto dia da semana (valor 4) */
    Sexta,   /**< Representa o sexto dia da semana (valor 5) */
    Sabado   /**< Representa o sétimo dia da semana (valor 6) */
};

int main(int argc, char **argv)
{
    // Imprime os valores numéricos correspondentes aos dias da semana
    printf(" Domingo = %d\n", Domingo); // Imprime 0
    printf(" Segunda = %d\n", Segunda); // Imprime 1
    printf(" Terca   = %d\n", Terca);   // Imprime 2
    printf(" Quarta  = %d\n", Quarta);  // Imprime 3
    printf(" Quinta  = %d\n", Quinta);  // Imprime 4
    printf(" Sexta   = %d\n", Sexta);   // Imprime 5
    printf(" Sabado  = %d\n", Sabado);  // Imprime 6

    printf("\n--------------------------------------\n");

    // Declaração de variáveis do tipo enum 'semana'
    enum semana semana1;
    enum semana semana2;
    enum semana semana3;

    // Atribuição de valores do enum 'semana' às variáveis
    semana1 = Segunda;           // semana1 recebe o valor Segunda (1)
    semana2 = Terca;             // semana2 recebe o valor Terca (2)
    semana3 = semana1 + semana2; // semana3 recebe a soma de semana1 e semana2 (1 + 2 = 3)

    printf("\n--------------------------------------\n");

    // Imprime os valores das variáveis do enum 'semana'
    printf("\n Domingo = %d\n", Domingo); // Imprime 0
    printf(" semana 1 = %d\n", semana1);  // Imprime 1
    printf(" semana 2 = %d\n", semana2);  // Imprime 2
    printf(" semana 3 = %d\n", semana3);  // Imprime 3

    printf("\n--------------------------------------\n");

    // Declaração de mais variáveis do tipo enum 'semana'
    enum semana dia1;
    enum semana dia2;

    // Atribuição de valores do enum 'semana' às novas variáveis
    dia1 = Segunda; // dia1 recebe o valor Segunda (1)
    dia2 = Sexta;   // dia2 recebe o valor Sexta (5)

    // Verifica se dia1 é igual a dia2 e imprime uma mensagem correspondente
    if (dia1 == dia2)
    {
        printf("\n O dia é o mesmo.\n");
    }
    else
    {
        printf("\n São dias diferentes.\n");
    }
    return 0;
}
