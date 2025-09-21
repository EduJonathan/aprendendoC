#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>

/**
 * isacii(é ascii): Verifica se um caractere está presente na tabela ASCII.
 *
 * SINTAXE: int isascii(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna um valor diferente de zero se o caractere estiver na tabela ASCII.
 * Retorna zero se o caractere não estiver na tabela ASCII.
 *
 * @note Quaisquer funções da ctype poderão ser aceitos valores inteiros entre 0 e 255.
 * No entanto, mas somente os valores de 0 a 127 são considerados ASCII. Valores fora desse
 * intervalo são considerados como não ASCII.
 */

/**
 * @brief Função para verificar se um caractere é ASCII
 *
 * @param caractere Inserir no parâmetro um valor caractere.
 * @return true Se o valor do caractere pertence à tabela ASCII.
 * @return false Se o valor do caractere não pertence à tabela ASCII.
 * @note Para garantir a conformidade com a especificação da função, que espera um valor de
 * caractere na faixa de unsigned char foi adicionado este casting.
 */
bool IsASCII(const char caractere) { return isascii((unsigned char)caractere); }

/**
 * @brief Função para verificar se uma string é composta apenas por caracteres ASCII.
 *
 * @param str Insere um ponteiro para char como parâmetro
 * @return true Se a string é composta por caracteres ASCII
 * @return false Se a string não é composta por caracteres ASCII
 */
bool IsASCIIString(const char *str)
{
    // Enquanto o caractere atual da string) não for o caractere nulo ('\0'),
    // que indica o final da string.
    while (*str)
    {
        // Verifica se o caractere atual (*str) não é um caractere ASCII. Se IsASCII(*str)
        // retornar false, significando que o caractere não é ASCII.
        if (!IsASCII(*str))
        {
            // Se encontrar um caractere que não é ASCII, retorna false imediatamente,
            // indicando que a string contém pelo menos um caractere não ASCII.
            return false;
        }

        // Avança para o próximo caractere na string.
        str++;
    }

    // Se o loop terminar sem encontrar caracteres não ASCII, retorna true, indicando que
    // todos os caracteres da string são ASCII.
    return true;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    /* Declarando strings para verificar se os caracteres são ASCII.*/
    const char var1 = 'A';    // Caractere 'A'
    const char var2 = '\x7F'; // Caractere DEL

    // Verifica se o caractere var1 é ASCII
    bool is_ascii = IsASCII(var1);
    printf(" O caractere '%c' é ASCII: %d - %s\n", var1, is_ascii, is_ascii ? "true" : "falso");

    // Verifica se o caractere var2 é ASCII
    is_ascii = IsASCII(var2);
    printf(" O caractere '%c' é ASCII: %d - %s\n", var2, is_ascii, is_ascii ? "true" : "falso");

    printf("\n-----------------------------------------\n");

    /* Declarando strings para verificar se de caracteres é composta por caracteres ASCII.*/
    const char str1[] = "Hello"; // vetor de caracteres "Hello"
    const char str2[] = "Olá";   // vetor de caracteres "Olá"

    // Verifica se a string str1 é composta apenas por caracteres ASCII
    bool isStringAscii = IsASCIIString(str1);
    printf(" A string \"%s\" é composta apenas por caracteres ASCII: %d - %s\n", str1, isStringAscii, isStringAscii ? "true" : "falso");

    // Verifica se a string str2 é composta apenas por caracteres ASCII
    isStringAscii = IsASCIIString(str2);
    printf(" A string \"%s\" é composta apenas por caracteres ASCII: %d - %s\n", str2, isStringAscii, isStringAscii ? "true" : "falso");
    return 0;
}
