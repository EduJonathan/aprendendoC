#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/**
 * iscntrl(): Verifica se um caractere é um caractere de controle.
 *
 * SINTAXE: int iscntrl(int _C);
 *
 * @param _C Valor inteiro representando o caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for de controle.
 */

/**
 * @brief Verifica se um caractere é um caractere de controle.
 *
 * Esta função verifica se o caractere passado como argumento é um caractere de controle
 * (como uma nova linha, retorno de carriage, etc.).
 *
 * @param caractere Caractere a ser verificado.
 * @return Retorna verdadeiro se o caractere for um caractere de controle, e falso caso contrário.
 */
bool isCaractereDeControle(char caractere) { return iscntrl((unsigned char)caractere); }

/**
 * @brief Verifica se todos os caracteres de uma string são caracteres de controle.
 *
 * Esta função verifica se todos os caracteres na string fornecida são caracteres de controle
 * (como nova linha, retorno de carro, etc.). Retorna verdadeiro se todos os caracteres forem
 * caracteres de controle e falso se algum caractere não for um caractere de controle.
 *
 * @param str Ponteiro para a string a ser verificada.
 * @return true Se todos os caracteres da string forem caracteres de controle.
 * @return false Se algum caractere da string não for um caractere de controle.
 */
bool stringDeControles(const char *str)
{
    while (*str)
    {
        if (!isCaractereDeControle(*str))
        {
            return false;
        }
        str++;
    }
    return true;
}

int main(int argc, char **argv)
{
    char caractere1 = '\n'; // Nova linha
    char caractere2 = 'A';  // Caractere alfabético

    // Verifica se caractere1 é um caractere de controle
    if (isCaractereDeControle(caractere1))
    {
        printf("O caractere '%c' é um caractere de controle.\n", caractere1);
    }
    else
    {
        printf("O caractere '%c' não é um caractere de controle.\n", caractere1);
    }

    // Verifica se caractere2 é um caractere de controle
    if (isCaractereDeControle(caractere2))
    {
        printf("O caractere '%c' é um caractere de controle.\n", caractere2);
    }
    else
    {
        printf("O caractere '%c' não é um caractere de controle.\n", caractere2);
    }

    printf("\n-----------------------------------------\n");

    const char *str1 = "\n\t";        // String com caracteres de controle
    const char *str2 = "\n\tHello\t"; // String com caracteres não de controle

    printf("A string \"%s\" %s apenas caracteres de controle.\n", str1, stringDeControles(str1) ? "contém" : "não contém");
    printf("A string \"%s\" %s apenas caracteres de controle.\n", str2, stringDeControles(str2) ? "contém" : "não contém");
    return 0;
}
