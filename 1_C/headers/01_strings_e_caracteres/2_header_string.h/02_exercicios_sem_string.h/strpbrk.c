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
char *meu_strpbrk(char *string1, char *string2)
{
    int i, j;

    // Loop externo: percorre a string principal
    for (i = 0; string1[i] != '\0'; i++)
    {
        // Ignorar o \n do fgets para não dar falso positivo
        if (string1[i] == '\n')
            continue;

        // Loop interno: verifica se o caractere atual existe na string de busca
        for (j = 0; string2[j] != '\0'; j++)
        {
            if (string1[i] == string2[j])
            {
                // Encontramos o primeiro caractere da string1 que está na string2
                return &string1[i];
            }
        }
    }

    return NULL; // Nenhuma correspondência encontrada
}

int main(int argc, char **argv)
{
    char s1[50], s2[50];
    char *resultado = NULL;

    printf("String principal: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Caracteres de busca: ");
    fgets(s2, sizeof(s2), stdin);

    resultado = meu_strpbrk(s1, s2);

    if (resultado)
        printf("Primeira ocorrencia encontrada: %c (na memoria: %p)\n", *resultado, (void *)resultado);
    else
        printf("Nenhum caractere correspondente.\n");
    return 0;
}
