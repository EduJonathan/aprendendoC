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
void concatenarStrings(char *str1, const char *str2, int tamanhoMaximo)
{
    int i = 0, j = 0;

    // Encontrar o final da primeira string (ou o limite do buffer)
    while (str1[i] != '\0' && i < tamanhoMaximo - 1)
    {
        // Remove o caractere de nova linha (\n) se ele existir
        if (str1[i] == '\n')
        {
            break; // Para aqui para começar a sobrescrever o \n
        }
        i++;
    }

    // Concatenar a segunda string
    while (str2[j] != '\0' && i < tamanhoMaximo - 1)
    {
        // Não queremos copiar o \n da segunda string também
        if (str2[j] == '\n')
        {
            j++;
            continue;
        }
        str1[i++] = str2[j++];
    }

    // Garante o fechamento da string
    str1[i] = '\0';
}

int main(int argc, char **argv)
{
    char str1[20] = {0}; /**< String 1 onde será armazenada a concatenação */
    char str2[20] = {0}; /**< String 2 que será concatenada à string 1 */

    // Solicitar ao usuário para inserir a primeira string
    printf("Entre com uma frase (MAX.: 20 CARACTERES): ");
    fgets(str1, sizeof(str1), stdin);

    // Solicitar ao usuário para inserir a segunda string
    printf("Entre com mais uma frase (MAX.: 20 CARACTERES): ");
    fgets(str2, sizeof(str2), stdin);

    // Concatenar as duas strings
    concatenarStrings(str1, str2, sizeof(str1));

    // Exibir a string concatenada
    printf("String concatenada: %s\n", str1);

    return 0;
}
