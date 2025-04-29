#include <stdio.h>

/**
 * @brief Função para copiar uma string para outra.
 *
 * Esta função copia o conteúdo de uma string para outra, caractere por caractere,
 * até encontrar o caractere nulo ('\0'), que marca o final da string.
 *
 * @param origem A string de origem que será copiada.
 * @param destino A string de destino onde o conteúdo da string de origem será copiado.
 */
void copiarString(const char *origem, char *destino)
{
    int i = 0;

    // Copiar os caracteres de origem para destino até encontrar o caractere nulo '\0'
    while (origem[i] != '\0')
    {
        destino[i] = origem[i]; // Copia o caractere da origem para o destino
        i++;
    }

    // Adiciona o caractere nulo ('\0') ao final da string de destino
    destino[i] = '\0';
}

int main(int argc, char **argv)
{
    char string1[17] = "Hello World"; /**< String original */
    char string2[17];                 /**< String de destino para armazenar a cópia de string1 */

    // Chama a função para copiar string1 para string2
    copiarString(string1, string2);

    // Exibe o conteúdo de string2
    printf("O conteúdo da string2 agora é: %s\n", string2);

    return 0;
}
