#include <stdio.h>
#include <string.h>
#include <locale.h>

/**
 * strcoll(): Função retorna um valor que indica a relação entre as cadeias de caracteres, é
 * útil quando precisa comparar strings que podem conter caracteres específicos de um idioma
 * ou cultura, e deseja que a comparação seja sensível à localização.
 *
 * SINTAXE: int strcoll(const char *_Str1, const char *_Str2);
 *
 * @param _Str1 Primeiro ponteiro para char a ser passado
 * @param _Str2 Primeiro ponteiro para char a ser passado
 * @return Retorna um inteiro que indica o resultado da comparação.
 *
 *  Valor       |    Significado
 * Menos de 0	| string1 menor que string2
 * igual a 0    | equivalente para string2
 * Maior que 0	| string1 maior que string2
 *
 * Se é sem sucesso, errno é alterado. O valor de errno pode ser definido como EINVAL
 * (Os argumentos string1 ou string2 contêm caracteres que não estão disponíveis na localidade atual)
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
