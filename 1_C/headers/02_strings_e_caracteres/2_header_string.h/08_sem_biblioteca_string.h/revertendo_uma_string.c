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
    char temp = '\0'; /**< Variável temporária para armazenar caracteres durante a inversão */

    // Encontrar o tamanho da string
    while (str[end] != '\0')
    {
        end++; // Avançar para o próximo caractere
    }

    end--; // Ajusta para o índice do último caractere

    // Inverte a string
    while (begin < end)
    {
        temp = str[begin];     // Armazena o caractere atual
        str[begin] = str[end]; // Substitui o caractere atual pelo caractere do fim
        str[end] = temp;       // Substitui o caractere do fim pelo armazenado
        begin++;               // Avançar para o próximo caractere
        end--;                 // Recuar para o caractere anterior
    }
}

int main(int argc, char **argv)
{
    char str[50] = {0}; /**< A string que será invertida */

    // Solicitar ao usuário para digitar uma frase
    printf("Digite algo: ");
    scanf("%49[^\n]", str); // Lê até 49 caracteres ou até encontrar uma quebra de linha

    // Chama a função para inverter a string
    inverterString(str);

    // Exibe a string invertida
    printf("String invertida: %s\n", str);
    return 0;
}
