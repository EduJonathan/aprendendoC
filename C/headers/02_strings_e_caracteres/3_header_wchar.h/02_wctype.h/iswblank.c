#include <stdio.h>
#include <wchar.h>
#include <wctype.h>
#include <locale.h>

// iswblank(): Checa o caractere largo entregue é um caractere branco

int main(int argc, char **argv)
{
    wchar_t c = L'\u3000';
    printf("Na localidade padrão, iswblank(%#x) = %d\n", c, !!iswblank(c));
    setlocale(LC_ALL, "en_US.UTF-8");
    printf("Na localidade Unicode, iswblank(%#x) = %d\n", c, !!iswblank(c));
    return 0;
}
