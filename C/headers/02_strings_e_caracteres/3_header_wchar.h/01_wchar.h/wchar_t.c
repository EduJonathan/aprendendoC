#include <stdio.h>
#include <locale.h>
#include <wchar.h>

/**
 * O tipo wchar_t em C e C++ é usado para representar caracteres em conjuntos de caracteres
 * que podem ser maiores que o padrão ASCII, como caracteres internacionais e acentuados.
 * E sua biblioteca nos ajuda a ter esta vasta gama de uso de caracteres que a linguagem C
 * não tem suporte
 */

int main(int argc, char **argv)
{
    // Configura a localidade para padrão Português do Brasil em UTF-8
    if (setlocale(LC_ALL, "pt_BR.UTF-8") == NULL)
    {
        fprintf(stderr, "Erro ao configurar o locale\n");
        return 1;
    }

    // Configura a localidade para padrão inglês em UTF-8
    if (setlocale(LC_ALL, "en_US.UTF-8") == NULL)
    {
        fprintf(stderr, "Erro ao configurar o locale\n");
        return 1;
    }

    setlocale(LC_CTYPE, "pt_BR.UTF-8");
    setlocale(LC_CTYPE, "en_US.UTF-8");

    /*L é sufixo que determina o wchar_t */
    wchar_t str[] = L"Olá, você pode utilizar o sinais de acentuação(\u00E7 \u00E3 \u00F5)? \u2764";

    // Imprime a string usando wprintf
    wprintf(L"String: %ls\n", str);

    printf("------------------------------------------\n");

    // Declarando caracteres largos
    wchar_t letra1 = L'A';
    wchar_t letra2 = L'\u03C0'; // Representa 'π' (Pi)

    // Exibindo os caracteres
    wprintf(L"Caractere 1: %lc\n", letra1); // Exibe: A
    wprintf(L"Caractere 2: %lc\n", letra2); // Exibe: π

    printf("------------------------------------------\n");

    wchar_t nome[] = L"Olá, Mundo!";
    wprintf(L"Tamanho da string: %zu\n", wcslen(nome));

    wchar_t copia[20];
    wcscpy(copia, nome);
    wprintf(L"String copiada: %ls\n", copia);
    return 0;
}
