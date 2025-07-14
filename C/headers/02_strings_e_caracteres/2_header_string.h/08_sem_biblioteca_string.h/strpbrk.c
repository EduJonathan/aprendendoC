#include <stdio.h>
#include <string.h>

/**
 * @brief Procedimento que irá retornar o ponteiro para a primeira ocorrencia de um caractere
 * da string de busca na string fornecida.
 *
 * @param string1 ponteiro para a primeira string
 * @param string2 ponteiro para a segunda string
 * @return retorna um ponteiro para a primeira ocorrencia de um caractere da string
 * de busca na string fornecida
 */
char *strpbrk(char *string1, char *string2)
{
    // Pecorrendo todo array de string1 até o '\0', e passando posição por posição
    int i = 0, j = 0, pos = 0, flag = 0;
    for (i = 0; string1[i] != '\0'; i++)
        ;

    // Pecorrendo todo array de string2 até o '\0', e passando posição por posição
    for (i = 0; string2[i] != '\0' && !flag; i++)
    {
        // Encontrando a primeira ocorrencia
        for (j = 0; string1[j] != '\0'; j++)
        {
            // Verificando se o caractere da string2 corresponde ao caractere da string1
            if (string2[i] == string1[j])
            {
                pos = j;  // Armazenando a posição
                flag = 1; // Flag para indicar que uma correspondência foi encontrada
                break;    // Saia do loop interno quando encontrar uma correspondência
            }
        }
    }

    if (flag == 1)
    {
        return &string1[pos]; // Retornando o ponteiro para a primeira ocorrencia
    }
    else
    {
        return NULL; // Retornando NULL se nenhuma correspondência foi encontrada
    }
}

int main(int argc, char **argv)
{
    char string1[50] = {0}, string2[50] = {0};
    char *pos = NULL;

    printf("Entre com uma string: ");
    scanf("%49[^\n]", string1);
    setbuf(stdin, NULL);

    printf("Entre com outra string: ");
    scanf("%49[^\n]", string2);
    setbuf(stdin, NULL);

    pos = strpbrk(string1, string2);

    if (pos != NULL)
    {
        printf("O caractere encontrado em string1: %c\n", *pos);
    }
    else
    {
        printf("Nenhum caractere correspondente encontrado.\n");
    }
    return 0;
}
