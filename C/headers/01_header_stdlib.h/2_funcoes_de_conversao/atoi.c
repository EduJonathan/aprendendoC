#include <stdio.h>
#include <stdlib.h>

/**
 * atoi(): Converte String para Inteiro.
 *
 * SINTAXE: int atoi(const char *_Str);
 *
 * @param _Str Ponteiro para char.
 * @return O valor da string convertido como um inteiro.
 */

/**
 * stringParaInteiro: Converte uma string para um inteiro.
 *
 * @param str: String a ser convertida.
 * @return O valor inteiro convertido.
 */
int stringParaInteiro(const char *str)
{
    int strToInt = atoi(str);
    return strToInt;
}

int main(int argc, char **argv)
{
    /* Declarando um vetor de strings. */
    const char str[] = "12345";

    /* Declarando uma variável para armazenar o valor convertido. */
    int valorConvertido = stringParaInteiro(str);

    printf(" String convertida para inteiro : %d\n", valorConvertido);
    printf(" Verificando tamanho da conversão em bytes : %zu\n", sizeof(valorConvertido));
    return 0;
}
