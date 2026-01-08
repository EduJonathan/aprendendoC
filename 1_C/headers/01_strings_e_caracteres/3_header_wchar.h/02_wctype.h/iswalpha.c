#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <wchar.h>
#include <wctype.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, ""); // Configura locale para suportar caracteres wide
    wchar_t caractere = L'a';

    if (iswalpha(caractere))
    {
        wprintf(L"O caractere %lc é uma letra.\n", caractere);
    }

    wchar_t maiusculo = towupper(caractere);
    wprintf(L"Caractere convertido para maiúsculo: %lc\n", maiusculo);

    printf("-------------------------------\n");

    // char (ASCII)
    char c1 = 'A';
    printf("isalpha('A'): %d\n", isalpha(c1)); // 1 (true)

    // wchar_t (Unicode)
    wchar_t c2 = L'Á';
    wprintf(L"iswalpha(L'Á'): %d\n", iswalpha(c2)); // 1 (true)

    return 0;
}
