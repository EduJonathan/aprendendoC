#include <stdio.h>

/**
 * @brief Calcula o comprimento da string usando recursão.
 *
 * Esta função calcula o comprimento da string a partir do índice fornecido,
 * chamando-se recursivamente até encontrar o caractere nulo '\0' que indica o fim da string.
 *
 * @param string Ponteiro para a string cujo comprimento deve ser calculado.
 * @param index Índice atual na string a ser verificado.
 * @return O comprimento da string a partir do índice fornecido.
 */
size_t strLength(char *string, int index)
{
    // Caso base: se encontrar o caractere nulo, retorna 0
    if (string[index] == '\0')
    {
        return 0;
    }

    // Caso recursivo: conta 1 mais o comprimento da substring a partir do próximo índice
    return 1 + strLength(string, index + 1);
}

/**
 * @brief Reverte a string usando recursão.
 *
 * Esta função reverte a string trocando os caracteres de posição usando recursão.
 * O processo de reversão continua até que o índice atinja o meio da string.
 *
 * @param string Ponteiro para a string que deve ser revertida.
 * @param index Índice atual da string que está sendo processado.
 * @param size Tamanho total da string.
 */
void reverteString(char *string, int index, int size)
{
    // Caso base: se o índice alcançar ou ultrapassar o meio da string, a função retorna
    if (index >= size / 2)
    {
        return;
    }

    // Troca os caracteres nas posições `index` e `size - index - 1`
    char temp = string[index];                // Armazena o caractere temporiariamente
    string[index] = string[size - index - 1]; // Troca os caracteres
    string[size - index - 1] = temp;          // Restaura o caractere original

    // Chama a função recursivamente para o próximo índice
    reverteString(string, index + 1, size);
}

int main(int argc, char *argv[])
{
    // Define um array de caracteres para a string a ser invertida
    char string[] = "Funcoes recursivas"; // Usar array para permitir modificação

    // Calcula o comprimento da string
    size_t size = strLength(string, 0);

    // Reverte a string
    reverteString(string, 0, size);

    // Imprime a string invertida
    printf("A string reversa fica: %s\n", string);

    return 0;
}
