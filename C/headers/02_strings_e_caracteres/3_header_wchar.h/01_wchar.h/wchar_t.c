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
    // Configura o locale para Português do Brasil
    if (setlocale(LC_ALL, "pt_BR.UTF-8") == NULL)
    {
        fprintf(stderr, "Erro ao configurar o locale\n");
        return 1;
    }

    // Configura o locale para Português do Brasil
    if (setlocale(LC_ALL, "en_US.UTF-8") == NULL)
    {
        fprintf(stderr, "Erro ao configurar o locale\n");
        return 1;
    }

    setlocale(LC_CTYPE, "pt_BR.UTF-8");
    setlocale(LC_CTYPE, "en_US.UTF-8");

    wchar_t str[] = L"Olá, você pode utilizar o sinais de acentuação(\u00E7 \u00E3 \u00F5)? \u2764";

    // Imprime a string usando wprintf
    wprintf(L"String: %ls\n", str);
    return 0;
}
