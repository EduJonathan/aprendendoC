#include <stdio.h>

/**
 * @brief Função para inverter uma string.
 *
 * Esta função recebe uma string como entrada e inverte seus caracteres. O conteúdo
 * da string invertida será armazenado na mesma string de entrada.
 *
 * @param str A string que será invertida.
 */
void inverterString(char *str)
{
    int begin = 0;
    int end = 0;
    char temp;

    // Encontrar o final da string
    while (str[end] != '\0')
    {
        end++;
    }
    end--; // Aponta para o caractere antes do \0

    // Ajuste para ignorar o caractere de nova linha do fgets
    if (end >= 0 && str[end] == '\n')
    {
        end--;
    }

    // Processo de inversão (Swap)
    while (begin < end)
    {
        temp = str[begin];     // Armazena o caractere inicial temporariamente
        str[begin] = str[end]; // Coloca o caractere final na posição inicial
        str[end] = temp;       // Coloca o caractere inicial na posição final

        begin++; // Move para o próximo caractere do início
        end--;   // Move para o próximo caractere do fim
    }
}

int main(int argc, char **argv)
{
    char str[50] = {0}; /**< A string que será invertida */

    // Solicitar ao usuário para digitar uma frase
    printf("Digite algo: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Removendo o caractere de nova linha lido pelo fgets

    // Chama a função para inverter a string
    inverterString(str);

    // Exibe a string invertida
    printf("String invertida: %s\n", str);
    return 0;
}
