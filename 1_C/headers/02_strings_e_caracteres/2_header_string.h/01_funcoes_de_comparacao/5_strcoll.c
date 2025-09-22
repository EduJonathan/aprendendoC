#include <stdio.h>
#include <string.h>
#include <locale.h>

/**
 * A função `strcoll()` compara as strings `str1` e `str2` considerando as regras
 * específicas de ordenação da localidade configurada no programa, o que a torna
 * útil para comparações sensíveis à cultura e idioma.
 *
 * @param str1 Ponteiro para a primeira string.
 * @param str2 Ponteiro para a segunda string.
 *
 * @return Um inteiro indicando a relação entre as strings:
 *         - < 0 : `str1` é menor que `str2`
 *         - = 0 : `str1` é igual a `str2`
 *         - > 0 : `str1` é maior que `str2`
 *
 * @note Se ocorrer erro, a variável `errno` pode ser ajustada para `EINVAL`, indicando
 *       que uma das strings contém caracteres inválidos na localidade atual.
 */

/**
 * @brief Compara duas cadeias de caracteres de acordo com o locale atual.
 *
 * Esta função compara duas strings levando em consideração as regras de ordenação
 * baseadas no locale atual. Isso é útil para comparações sensíveis ao idioma e cultura.
 *
 * @param str1 A primeira string a ser comparada.
 * @param str2 A segunda string a ser comparada.
 *
 * @return Retorna um valor menor que 0 se str1 vem antes de str2, 0 se str1 é igual a str2, e
 * um valor maior que 0 se str1 vem depois de str2.
 */
int comparar_strings_locale(const char *str1, const char *str2)
{
    return strcoll(str1, str2);
}

int main(int argc, char **argv)
{
    // Define o locale para garantir uma comparação apropriada
    setlocale(LC_ALL, "pt_BR.UTF-8");

    const char *str1 = "maçã";
    const char *str2 = "banana";

    int result = comparar_strings_locale(str1, str2);

    if (result < 0)
    {
        printf("%s vem antes de %s no locale atual.\n", str1, str2);
    }
    else if (result > 0)
    {
        printf("%s vem depois de %s no locale atual.\n", str1, str2);
    }
    else
    {
        printf("%s é igual a %s no locale atual.\n", str1, str2);
    }
    return 0;
}
