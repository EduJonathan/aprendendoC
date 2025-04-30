#include <stdio.h>

/**
 * @brief Operador ternário (?:) para avaliação condicional simplificada.
 *
 * O operador ternário (?:) é uma forma compacta de expressar uma condição,
 * retornando um valor baseado na avaliação dessa condição. Ele permite simplificar
 * expressões condicionais, substituindo uma estrutura `if-else` tradicional, tornando o
 * código mais conciso e legível.
 *
 * @note A sintaxe é: `(condicional) ? valor verdadeiro : valor falso;`
 *
 * @param condicional A condição a ser avaliada. Se for verdadeira, o valor após o `?` será retornado.
 * @param valor verdadeiro O valor a ser retornado caso a condicional seja verdadeira.
 * @param valor falso O valor a ser retornado caso a condicional seja falsa.
 */

int main(int argc, char **argv)
{
    printf("\n======================================================================\n");
    printf("\n\t>>EXEMPLO 01: CONDIÇÃO TERNÁRIA<<\n");

    int numero1 = 10;    // Valor 10 para o numero1
    int numero2 = 54;    // Valor 54 para o numero2
    int maiorNumero = 0; // Irá armazenar a expressão ternária para determinar o maior numero
    int menorNumero = 0; // Irá armazenar a expressão ternária para determinar o menor numero

    // Exemplo de uso do operador ternário para encontrar o maior número
    maiorNumero = (numero1 > numero2) ? numero1 : numero2;
    printf("\n O maior número é %d\n", maiorNumero); // Espera-se 54, pois 54 > 10

    // Espera-se 10, pois 10 < 54
    maiorNumero = (numero2 < numero1) ? numero2 : numero1;
    printf(" O maior número é %d\n", maiorNumero);

    printf("\n=======================================================================\n");
    printf("\n\t>>EXEMPLO 02: UTILIZANDO PRINTF<<\n");

    /// ERROR: o valor de menorNumero não está sendo usado corretamente no printf.
    // Aqui, menorNumero foi passado para o printf, mas deveria ser 'numero1' ou 'numero2'.
    menorNumero = (numero1 < numero2) ? printf("O numero %d é o menor?\n", menorNumero) : printf("O numero %d é o menor?\n", menorNumero);

    /**
     * @note O erro ocorre porque estamos utilizando "menorNumero" como argumento
     * do printf, mas "menorNumero" não está sendo corretamente calculado no ternário.
     * O correto seria passar "numero1" ou "numero2" para o printf, dependendo da comparação.
     */

    printf("\n-----------------------------------------------------\n");
    printf("\n\t>>EXEMPLO 02: CORREÇÃO UTILIZANDO PRINTF<<\n");

    // Correção do exemplo anterior: agora estamos passando o número correto para o printf
    menorNumero = (numero1 < numero2) ? printf("O numero %d é o menor\n", numero1) : printf("O numero %d é o menor\n", numero2);

    printf("\n-----------------------------------------------------\n");
    printf("\n\t>>EXEMPLO 02: OPERAÇÃO TERNÁRIA<<\n");

    /// OBS: É mais aconselhavél deixar declarado dessa maneira, pois a instrução fica mais legível
    menorNumero = (numero1 < numero2) ? numero1 : numero2;
    printf("O numero %d é menor\n", menorNumero);

    printf("\n=======================================================================\n");
    printf("\n\t>>EXEMPLO 03: OPERAÇÃO COMO ARGUMENTO NO PRINTF<<\n");

    // Utilizando o operador dentro em um printf como argumento
    int numero_par = 10;
    printf("O numero %d é um numero %s\n", numero_par, (numero_par % 2 == 0) ? "par" : "impar");

    printf("\n=======================================================================\n");
    printf("\n\t>>EXEMPLO 04: CHAR E STRING NA OPERAÇÃO TERNARIA<<\n");

    // Usando o operador ternário para determinar se o número é par ou ímpar
    int e_um_numeroImpar = 5;
    char impar = ((e_um_numeroImpar % 2) == 0) ? 'F' : 'V';
    const char *e_impar = ((e_um_numeroImpar % 2) == 0) ? "par" : "impar";

    printf("O numero %d é numero %s\n", e_um_numeroImpar, e_impar);
    printf("O numero %d é numero %c\n", e_um_numeroImpar, impar);
    return 0;
}
