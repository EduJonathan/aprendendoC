#include <stdio.h>
#include <stdlib.h>

/**
 * itoa(): Converte Inteiro para String.
 *
 * SINTAXE: char *itoa(int _Val, char *_DstBuf, int _Radix);
 *
 * @param Val Valor para ser convertido.
 * @param Str Entregar um ponteiro para armazenar o resultado.
 * @param Radix Base numérica usada para representar o valor como uma string.
 * @return Retorna um ponteiro para a string resultante.
 */

/**
 * Converte um inteiro para uma string e imprime o resultado.
 *
 * @param val Valor inteiro a ser convertido.
 * @param radix Base numérica usada para representar o valor como uma string.
 */
void converterEImprimir(int val, int radix)
{
    char str[32]; // Buffer para armazenar a string resultante

    // Usando itoa para converter o inteiro para string
    char *valorConvertido = itoa(val, str, radix);

    printf("Inteiro convertido para string: %s\n", valorConvertido);
    printf("Verificando tamanho da conversão em bytes: %zu\n", sizeof(str));
}

int main(int argc, char **argv)
{
    int num = 54321;
    converterEImprimir(num, 10);
    return 0;
}
