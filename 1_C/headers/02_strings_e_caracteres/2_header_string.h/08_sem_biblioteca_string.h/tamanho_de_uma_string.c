#include <stdio.h>

/**
 * @brief Função para calcular o tamanho de uma string.
 *
 * Esta função recebe uma string e retorna o número de caracteres
 * até o caractere nulo ('\0') que indica o fim da string.
 *
 * @param str A string cujo tamanho será calculado.
 *
 * @return O tamanho da string (número de caracteres).
 */
int calcularTamanhoString(const char *str)
{
    int i = 0;

    // Percorre a string até encontrar o caractere nulo '\0'
    while (str[i] != '\0')
    {
        // Incrementa o contador para cada caractere
        i++;
    }

    // Retorna o tamanho da string
    return i;
}

int main(int argc, char **argv)
{
    char str[50] = {0}; /**< A string inserida pelo usuário */

    // Solicitar ao usuário para digitar uma frase
    printf("Digite uma frase (MAX.: 50 CARACTERES): ");
    scanf("%49[^\n]", str); // Lê até 49 caracteres ou até encontrar uma quebra de linha

    // Chama a função para calcular o tamanho da string
    int tamanho = calcularTamanhoString(str);

    // Exibe o tamanho da string
    printf("O tamanho da string é: %d\n", tamanho);

    return 0;
}
