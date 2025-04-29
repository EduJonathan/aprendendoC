#include <locale.h>
#include <stdio.h>
#include <time.h>
#include <wchar.h>

/**
 * As constantes fazem parte do setlocale, atuando para manipular alguns pontos, sendo
 * horário, sistema monetário, númerico
 *
 * LC_ALL Todas as categorias de localidade.
 * LC_COLLATE As funções strcoll, _stricoll, wcscoll, _wcsicoll, strxfrm, _strncoll, _strnicoll,
 *  _wcsncoll, _wcsnicoll e wcsxfrm.
 * LC_CTYPE	As funções de manipulação de caracteres (exceto isdigit, isxdigit, mbstowcs e mbtowc,
 * que não são afetadas).
 * LC_TIME Apenas data e hora(strftime e wcsftime).
 * LC_NUMERIC Apenas formatação de números (ponto, vírgula).
 * LC_MONETARY Formatação de moeda retornadas pela função localeconv..
 * LC_MESSAGES Mensagens de erro ou sistema.
 */

int main(int argc, char **argv)
{
    setlocale(LC_ALL, "en_US.UTF-8");    // Configura UTF-8 no padrão americano
    setlocale(LC_NUMERIC, "de_DE.utf8"); // decimal sendo uma ',' em alemão
    setlocale(LC_TIME, "ja_JP.utf8");    // date/time vai ser formatado em Japonês

    wchar_t str[100];
    time_t t = time(NULL);

    wcsftime(str, 100, L"%A %c", localtime(&t));
    wprintf(L"Número: %.2f\nData: %Ls\n", 3.14, str);
}
