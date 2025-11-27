#include <stdio.h>

/**
 * Os operadores de incremento (++) e decremento (--) possuem embutida
 * uma operação de atribuição. Eles podem ser usados antes ou depois do nome da variável:
 *
 * => ++x (pré-incremento): soma 1 à variável x antes de utilizar seu valor.
 * => x++ (pós-incremento): soma 1 à variável x depois de utilizar seu valor.
 * => --x (pré-decremento): subtrai 1 da variável x antes de utilizar seu valor.
 * => x-- (pós-decremento): subtrai 1 da variável x depois de utilizar seu valor.
 */

int main(int argc, char **argv)
{
    printf("\n\tINCREMENTO:\n");

    int incremento = 10;
    int pre_incremento = 0;
    int pos_incremento = 0;

    printf("Valor da variável 'incremento' antes de incrementar: %d\n", incremento);

    ++incremento; // Pré-incremento: incremento é incrementado antes de ser usado.
    printf("Valor de 'incremento' após pré-incremento: %d\n", incremento);

    incremento++; // Pós-incremento: incremento é incrementado depois de ser usado.
    printf("Valor de 'incremento' após pós-incremento: %d\n", incremento);

    printf("\n=====================================================================\n");

    printf("\n\tPRÉ-INCREMENTO:\n");

    pre_incremento = ++incremento; // Incrementa primeiro, depois atribui.
    printf("Valor de 'incremento' após pré-incremento: %d\n", incremento);
    printf("Valor de 'pre_incremento': %d\n", pre_incremento);

    /*
     * O operador de pré-incremento (++incremento) é o primeiro a ser
     * realizado dentro da expressão. Somente depois de incrementado, o valor de
     * incremento é atribuído à variável pre_incremento. Equivale a:
     * incremento = incremento + 1; // incremento = 13
     * pre_incremento = incremento; // pre_incremento = 13
     */

    printf("\n\tPÓS-INCREMENTO:\n");

    pos_incremento = incremento++; // Atribui, depois incrementa.
    printf("Valor de 'pos_incremento': %d\n", pos_incremento);
    printf("Valor de 'incremento' após pós-incremento: %d\n", incremento);

    /*
     * O operador de pós-incremento (incremento++) é o último a ser realizado dentro
     * da expressão. Primeiro, o valor de incremento é atribuído à variável pos_incremento,
     * e só depois incrementa. Equivale a:
     * pos_incremento = incremento; // pos_incremento = 13
     * incremento = incremento + 1; // incremento = 14
     */

    printf("\n==================================================================\n");

    printf("\n\tDECREMENTO:\n");

    int decremento = 10;
    int pre_decremento = 0;
    int pos_decremento = 0;

    printf("Valor da variável 'decremento' antes de decrementar: %d\n", decremento);

    --decremento; // Pré-decremento: decremento é decrementado antes de ser usado.
    printf("Valor de 'decremento' após pré-decremento: %d\n", decremento);

    decremento--; // Pós-decremento: decremento é decrementado depois de ser usado.
    printf("Valor de 'decremento' após pós-decremento: %d\n", decremento);

    printf("\n====================================================================\n");

    printf("\n\tPRÉ-DECREMENTO:\n");

    pre_decremento = --decremento; // Decrementa primeiro, depois atribui.
    printf("Valor de 'decremento' após pré-decremento: %d\n", decremento);
    printf("Valor de 'pre_decremento': %d\n", pre_decremento);

    /*
     * O operador de pré-decremento (--decremento) é o primeiro a ser realizado
     * dentro da expressão. Somente depois de decrementado, o valor de decremento é
     * atribuído à variável pre_decremento. Equivale a:
     * decremento = decremento - 1; // decremento = 7
     * pre_decremento = decremento; // pre_decremento = 7
     */

    printf("\n\tPÓS-DECREMENTO:\n");

    pos_decremento = decremento--; // Atribui, depois decrementa.
    printf("Valor de 'pos_decremento': %d\n", pos_decremento);
    printf("Valor de 'decremento' após pós-decremento: %d\n", decremento);

    /*
     * O operador de pós-decremento (decremento--) é o último a ser realizado
     * dentro da expressão. Primeiro, o valor de decremento é atribuído à variável
     * pos_decremento, e só depois decrementa. Equivale a:
     * pos_decremento = decremento; // pos_decremento = 7
     * decremento = decremento - 1; // decremento = 6
     */

    printf("\n====================================================================\n");

    printf("\n\tCURIOSIDADE: UTILIZANDO INCREMENTO NO PRINTF:\n");

    int i = 1;
    printf("A saída de 'i' é: %d%d%d?\n", i, ++i, i++); // 331?

    // Explicação do comportamento da expressão no printf:
    // A função printf avalia os argumentos da direita para a esquerda.
    // Portanto:
    // 1. i++ (pós-incremento): i é 1, então o valor usado é 1, e depois i é incrementado para 2.
    // 2. ++i (pré-incremento): agora i é 2, então i é incrementado para 3 antes de ser usado.
    // 3. i (após incremento): agora i é 3, então o valor final é 3.
    return 0;
}
