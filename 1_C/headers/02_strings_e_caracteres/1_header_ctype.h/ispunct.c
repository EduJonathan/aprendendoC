#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <ctype.h>

/**
 * ispunct(é pontuação): não imprime caractere: letras, digitos e espaços, apenas sinal de pontuação.
 *
 * SINTAXE: int ispunct(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro de zero se o caractere for um sinal de pontuação.
 */

/**
 * @brief Verifica se um caractere é um caractere de pontuação.
 *
 * Esta função verifica se o caractere passado como argumento é um caractere de pontuação
 * (ou seja, um símbolo usado para separar ou estruturar frases).
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for um caractere de pontuação, e falso caso contrário.
 */
bool isPunct(int caractere)
{
    bool is_punct = ispunct((unsigned char)caractere);

    printf(" O caractere '%c' %s pontuação: %d - %s\n",
           caractere,
           is_punct ? "é" : "não é",
           is_punct,
           is_punct ? "true" : "false");

    return is_punct;
}

/**
 * @brief Verifica se todos os caracteres de uma string são caracteres de pontuação.
 *
 * Esta função verifica se todos os caracteres na string fornecida são caracteres de pontuação.
 * Retorna verdadeiro se todos os caracteres forem de pontuação e falso se algum caractere
 * não for de pontuação.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem caracteres de pontuação.
 * @return false Se algum caractere da string não for um caractere de pontuação.
 */
bool stringDePontuacoes(const char *str)
{
    while (*str)
    {
        if (!isPunct(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int var1 = 't';  // Letra minúscula (não é pontuação)
    int var2 = '1';  // Dígito (não é pontuação)
    int var3 = '\\'; // Caractere de escape (não é pontuação)
    int var4 = '!';  // Símbolo de pontuação
    int var5 = ' ';  // Espaço em branco (não é pontuação)

    isPunct(var1);
    isPunct(var2);
    isPunct(var3);
    isPunct(var4);
    isPunct(var5);

    printf("\n-----------------------------------------\n");

    const char *str1 = "!?.,;:"; // String com apenas caracteres de pontuação
    const char *str2 = "Hello!"; // String com caracteres não de pontuação

    printf("A string \"%s\" %s apenas caracteres de pontuação.\n", str1, stringDePontuacoes(str1) ? "contém" : "não contém");
    printf("A string \"%s\" %s apenas caracteres de pontuação.\n", str2, stringDePontuacoes(str2) ? "contém" : "não contém");
    return 0;
}
