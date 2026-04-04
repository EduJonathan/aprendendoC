#include <stdio.h>
#include <string.h>

/**
 * Algoritmo boyer-moore-horspool (Boyer-Moore-Horspool Algorithm) para busca de
 * padrões em textos. Encontra todas as ocorrencias de um padrão em um texto.
 *
 * COMPLEXIDADE:
 * TEMPO: O(n), onde n é o número de elementos na sequência (seja um vetor ou uma string)
 * tamanho do texto e m o tamanho do padrão.  Isso ocorre porque o algoritmo percorre o
 * vetor ou a string duas vezes: uma para encontrar o candidato e outra para contar a
 * frequência do candidato.
 *
 * ESPAÇO: O(1) ou 𝑂(𝑚) onde m é o tamanho do padrão. No caso da função majoridadeString,
 * como a string é manipulada diretamente, o uso de espaço é constante.
 */

/**
 * @brief Função para encontrar o elemento majoritário em um vetor.
 *
 * Algoritmo Boyer-Moore para encontrar o elemento majoritário.
 * O algoritmo percorre o vetor e utiliza uma abordagem de contagem para
 * encontrar um candidato, e depois verifica se esse candidato é realmente o majoritário.
 *
 * @param v Vetor de inteiros.
 * @param n Tamanho do vetor.
 */
int majoridade(int v[], int n)
{
    int contador  = 0;
    int candidato = -1;

    // Primeira fase: encontrar um possível candidato
    for (int i = 0; i < n; i++)
    {
        if (contador == 0)
        {
            candidato = v[i];
        }

        if (v[i] == candidato)
        {
            contador++;
        }
        else
        {
            contador--;
        }
    }

    // Segunda fase: verificar se o candidato é realmente o elemento majoritário
    contador = 0;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == candidato)
        {
            contador++;
        }
    }

    if (contador > n / 2)
    {
        return candidato; // Retorna o candidato se ele for majoritário
    }
    else
    {
        return -1; // Retorna -1 se não houver elemento majoritário
    }
}

/**
 * @brief Função para encontrar o caractere majoritário em uma string.
 *
 * Algoritmo Boyer-Moore para encontrar o caractere majoritário em um texto.
 * O algoritmo percorre a string e utiliza uma abordagem de contagem para
 * encontrar um candidato, e depois verifica se esse candidato é realmente o majoritário.
 *
 * @param texto Texto a ser analisado.
 */
char majoridadeString(const char *texto)
{
    int contador   = 0;
    char candidato = '\0'; // Candidato é inicialmente nulo

    // Primeira fase: encontrar um possível candidato
    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (contador == 0)
        {
            candidato = texto[i];
        }

        if (texto[i] == candidato)
        {
            contador++;
        }
        else
        {
            contador--;
        }
    }

    // Segunda fase: verificar se o candidato é realmente o caractere majoritário
    contador = 0;
    size_t n = strlen(texto);

    for (size_t i = 0ull; i < n; i++)
    {
        if (texto[i] == candidato)
        {
            contador++;
        }
    }

    if (contador > n / 2)
    {
        return candidato; // Retorna o candidato se ele for majoritário
    }
    else
    {
        return '\0'; // Retorna '\0' se não houver caractere majoritário
    }
}

int main(int argc, char **argv)
{
    int vetor[]   = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    size_t n      = sizeof(vetor) / sizeof(vetor[0]);
    int resultado = majoridade(vetor, n);

    if (resultado != -1)
    {
        printf("Elemento majoritário: %d\n", resultado);
    }
    else
    {
        printf("Não há elemento majoritário.\n");
    }

    printf("\n--------------------------\n");

    const char *texto = "aabbccccaaa";
    char result       = majoridadeString(texto);

    if (result != '\0')
    {
        printf("Caractere majoritário: %c\n", result);
    }
    else
    {
        printf("Não há caractere majoritário.\n");
    }

    printf("\n--------------------------\n");

    const char *text = "aaaaaaabb";
    char r           = majoridadeString(text);

    if (r != '\0')
    {
        printf("Caractere majoritário: %c\n", r);
    }
    else
    {
        printf("Não há caractere majoritário.\n");
    }
    return 0;
}
