#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

/**
 * iswctype: classifica o caractere largo wc usando o código de idioma C atual
 * @param wint_t _C -> Parâmetro que recebe o caractere que será classificado
 * @param wctype_t _Type -> Recebe a categoria LC_CTYPE , obtido para a chamada wctype
 */
const char *classificao(wchar_t wc, const char *cat)
{
    return iswctype(wc, wctype(cat)) ? "true" : "false";
}

int main(int argc, char **argv)
{
    // Configura o locale para o japonês
    setlocale(LC_ALL, "ja_JP.UTF-8");

    // Imprime o caractere \u6c34
    printf("O caractere \u6c34 é um:\n");

    // Declarando um array de strings
    const char *cats[] = {"char digito", "char alpha", "char space", "char cntrl", "jKanji"};

    // Loop para classificar os caracteres
    for (int i = 0; i < 5; ++i)
    {
        printf("\n%s? %s\n", cats[i], classificao(L'\u6c34', cats[i]));
    }
    return 0;
}
