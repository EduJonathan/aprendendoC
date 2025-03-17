#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * Algoritmo KMP (Knuth-Morris-Pratt): Para busca de padrões em textos.
 * Encontra todas as ocorrencias de um padrão em um texto.
 *
 * COMPLEXIDADE:
 * TEMPO: O(n+m), onde n é o tamanho do texto e m o tamanho do padrão. Isso ocorre porque
 * o algoritmo percorre o texto e o padrão uma única vez, sem precisar retroceder.
 *
 * ESPAÇO: O(m), onde m é o tamanho do padrão, devido ao vetor de falhas que precisa ser armazenado.
 */

/**
 * @brief Algoritmo KMP (Knuth-Morris-Pratt) para busca de padrões em textos.
 *
 * O algoritmo KMP encontra todas as ocorrências de um padrão em um texto.
 * A busca é feita de forma eficiente, com uma complexidade de tempo O(n + m),
 * onde n é o tamanho do texto e m é o tamanho do padrão, e uma complexidade de espaço O(m).
 *
 * @param texto O texto onde o padrão será buscado.
 * @param padrao O padrão que será buscado no texto.
 * @return true Se o padrão for encontrado no texto, caso contrário, false.
 */
void calcularFalhas(char *padrao, int falhas[])
{
    int tamanhoPadrao = strlen(padrao);
    int indiceFalha = 0;

    falhas[0] = -1; // O primeiro valor do vetor de falhas é sempre -1.

    // Preenche o vetor de falhas
    for (int i = 1; i < tamanhoPadrao; i++)
    {
        // Obtem o índice da falha anterior
        indiceFalha = falhas[i - 1];

        // Enquanto não houver correspondência, ajusta o índice da falha
        while (indiceFalha >= 0)
        {
            if (padrao[i] == padrao[indiceFalha])
            {
                // Caso de correspondência
                break;
            }
            else
            {
                // Segue o valor da falha anterior
                indiceFalha = falhas[indiceFalha];
            }
        }

        // Atualiza o vetor de falhas
        falhas[i] = indiceFalha + 1;
    }
}

/**
 * @brief Algoritmo KMP para encontrar ocorrências de um padrão no texto.
 *
 * O algoritmo verifica a presença do padrão no texto e retorna se encontrou ou não.
 *
 * @param texto O texto onde o padrão será buscado.
 * @param padrao O padrão a ser buscado.
 * @return true Se o padrão for encontrado no texto, caso contrário, false.
 */
bool buscarPadrao(char *texto, char *padrao)
{
    int tamanhoPadrao = strlen(padrao);
    int tamanhoTexto = strlen(texto);
    int falhas[tamanhoPadrao]; // Vetor para armazenar as falhas

    calcularFalhas(padrao, falhas); // Preenche o vetor de falhas

    int i = 0; // Índice para o texto
    int j = 0; // Índice para o padrão

    // Percorre o texto
    while (i < tamanhoTexto)
    {
        if (j == -1)
        {
            i++;
            j = 0;
        }
        else if (texto[i] == padrao[j])
        {
            i++;
            j++;

            // Quando j atingir o tamanho do padrão, encontrou uma correspondência
            if (j == tamanhoPadrao)
            {
                printf("Padrão encontrado no índice %d\n", i - tamanhoPadrao);
                return true; // Encontrou uma correspondência
            }
        }
        else
        {
            j = falhas[j]; // Ajusta j com base no vetor de falhas
        }
    }

    return false; // Não encontrou o padrão
}

int main(int argc, char **argv)
{
    char texto1[] = "AABAACAADAABAAABAA";
    char padrao1[] = "AABA";

    if (buscarPadrao(texto1, padrao1))
    {
        printf("O padrão: \"%s\" foi encontrado no texto \"%s\".\n", padrao1, texto1);
    }
    else
    {
        printf("O padrão: \"%s\" não foi encontrado no texto \"%s\".\n", padrao1, texto1);
    }

    printf("\n--------------------\n");

    char texto2[] = "AABAACAADAABAAABAA";
    char padrao2[] = "ABOO";

    if (buscarPadrao(texto2, padrao2))
    {
        printf("O padrão: \"%s\" foi encontrado no texto \"%s\".\n", padrao2, texto2);
    }
    else
    {
        printf("O padrão: \"%s\" não foi encontrado no texto \"%s\".\n", padrao2, texto2);
    }

    return 0;
}
