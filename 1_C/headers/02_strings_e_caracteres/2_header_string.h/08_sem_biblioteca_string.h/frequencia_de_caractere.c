#include <stdio.h>
#include <string.h>

/**
 * @brief Função para contar a frequência de cada caractere em uma string.
 *
 * Esta função recebe uma string e conta quantas vezes cada caractere (de 'a' a 'z')
 * ocorre na string. Ela considera apenas letras minúsculas de 'a' a 'z' e ignora outras letras
 * ou caracteres não alfabéticos.
 *
 * @param frase A string que será analisada.
 */
void contarFrequenciaCaractere(const char *frase)
{
    int c = 0;
    int count[26] = {0}; /**< Vetor para armazenar a contagem de cada caractere ('a' a 'z') */

    while (frase[c] != '\0') // Enquanto não encontrar o final da string
    {
        // Verifica se o caractere está entre 'a' e 'z'
        if (frase[c] >= 'a' && frase[c] <= 'z')
        {
            // Incrementa a contagem do caractere
            count[frase[c] - 'a']++;
        }

        // Avança para o próximo caractere
        c++;
    }

    // Exibe a contagem de cada caractere
    for (c = 0; c < 26; c++)
    {
        if (count[c] > 0) // Exibe apenas os caracteres que apareceram na string
        {
            printf("O caractere '%c' ocorre %d vez(es) na frase.\n", c + 97, count[c]);
        }
    }
}

int main(int argc, char **argv)
{
    char frase[20] = {0}; /**< String onde o usuário irá inserir a frase */

    // Solicita ao usuário para inserir uma frase com no máximo 20 caracteres
    printf("Entre com uma string (MAX. 20 CARACTERES): ");
    scanf("%19[^\n]", frase); // Lê até 19 caracteres ou até a quebra de linha

    // Chama a função para contar a frequência de caracteres
    contarFrequenciaCaractere(frase);

    return 0;
}
