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
    int count[26] = {0};

    while (frase[c] != '\0')
    {
        char atual = frase[c];

        // Se for maiúscula, transforma em minúscula usando a lógica ASCII
        // A diferença entre 'A' (65) e 'a' (97) é sempre 32
        if (atual >= 'A' && atual <= 'Z')
        {
            atual = atual + 32;
        }

        // Agora verifica se é uma letra minúscula
        if (atual >= 'a' && atual <= 'z')
        {
            count[atual - 'a']++;
        }
        c++;
    }

    for (c = 0; c < 26; c++)
    {
        if (count[c] > 0)
        {
            // Usar 'a' + c é mais legível que 97 + c
            printf("O caractere '%c' ocorre %d vez(es).\n", 'a' + c, count[c]);
        }
    }
}

int main(int argc, char **argv)
{
    char frase[20] = {0}; /**< String onde o usuário irá inserir a frase */

    // Solicita ao usuário para inserir uma frase com no máximo 20 caracteres
    printf("Entre com uma string (MAX. 20 CARACTERES): ");
    fgets(frase, sizeof(frase), stdin);

    // Chama a função para contar a frequência de caracteres
    contarFrequenciaCaractere(frase);

    return 0;
}
