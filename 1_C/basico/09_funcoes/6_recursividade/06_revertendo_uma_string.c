#include <stdio.h>

/**
 * @brief Calcula o comprimento de uma string usando recursão.
 *
 * A função percorre a string caractere por caractere a partir do índice
 * fornecido, chamando-se recursivamente até encontrar o caractere nulo '\0',
 * que indica o fim da string. Cada chamada retorna 1 mais o resultado da
 * chamada seguinte, acumulando o total de caracteres.
 *
 * @param string Ponteiro para a string cujo comprimento será calculado.
 * @param index Índice atual na string.
 * @return O comprimento da string a partir do índice informado.
 */
size_t strLength(char *string, int index)
{
    // Caso base: encontrou o fim da string
    if (string[index] == '\0')
    {
        return 0;
    }

    // Caso recursivo: soma 1 e avança para o próximo caractere
    return 1 + strLength(string, index + 1);
}

/**
 * @brief Reverte uma string usando recursão.
 *
 * A função troca os caracteres nas posições `index` e `size - index - 1`,
 * movendo-se em direção ao centro da string. O processo continua até o índice
 * atingir ou ultrapassar o meio, momento em que a recursão é encerrada.
 *
 * @param string Ponteiro para a string a ser revertida.
 * @param index Índice atual que está sendo processado.
 * @param size Comprimento total da string.
 */
void reverteString(char *string, int index, int size)
{
    // Caso base: chegou ao centro da string
    if (index >= size / 2)
    {
        return;
    }

    // Troca dos caracteres
    char temp = string[index];
    string[index] = string[size - index - 1];
    string[size - index - 1] = temp;

    // Avança para o próximo par de caracteres
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
