#include <stdio.h>

/**
 * @brief Função para concatenar duas strings.
 *
 * Esta função recebe duas strings como entrada e as concatena. Ela copia o conteúdo
 * da segunda string (str2) para o final da primeira string (str1), garantindo que
 * a string resultante não ultrapasse o limite de 20 caracteres.
 *
 * @param str1 A primeira string, que será modificada para conter a concatenação.
 * @param str2 A segunda string, que será concatenada à primeira string.
 */
void concatenarStrings(char *str1, const char *str2)
{
    int i = 0, j = 0;

    // Encontrar o final da primeira string
    while (str1[i] != '\0')
    {
        // Loop para garantir que a string final tenha no máximo 19 caracteres (o último é '\0')
        i++; // Incrementa o contador para cada caractere
    }

    // Concatenar a segunda string ao final da primeira
    while (str2[j] != '\0' && i < 19)
    {
        // Garantir que a string final tenha no máximo 19 caracteres (o último é '\0')
        str1[i++] = str2[j++];
    }

    // Adicionar o caractere nulo ao final da string concatenada
    str1[i] = '\0';
}

int main(int argc, char **argv)
{
    char str1[20] = {0}; /**< String 1 onde será armazenada a concatenação */
    char str2[20] = {0}; /**< String 2 que será concatenada à string 1 */

    // Solicitar ao usuário para inserir a primeira string
    printf("Entre com uma frase (MAX.: 20 CARACTERES): ");
    scanf("%s19[^\n]", str1);

    // Solicitar ao usuário para inserir a segunda string
    printf("Entre com mais uma frase (MAX.: 20 CARACTERES): ");
    scanf("%s19[^\n]", str2);

    // Concatenar as duas strings
    concatenarStrings(str1, str2);

    // Exibir a string concatenada
    printf("String concatenada: %s\n", str1);

    return 0;
}
