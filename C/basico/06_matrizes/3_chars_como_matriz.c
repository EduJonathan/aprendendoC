#include <stdio.h>

/*
 * Os tipos chars sendo utilizado tem um uso interessante, pois como sabemos chars sendo um vetor
 * deverão unir caracteres mais em um único espaço formando uma string mais no caso de uma matriz que
 * temos em exatos um vetor de vetores, devemos formar 2 vetores de caracteres.
 */

int main(int argc, char const *argv[])
{
    /*
     * Declarando uma matriz meses com 12 linhas (uma para cada mês) e cada linha pode armazenar uma
     * string de até 20 caracteres.
     */
    const char meses[12][10] = {
        "Janeiro",
        "Fevereiro",
        "Março",
        "Abril",
        "Maio",
        "Junho",
        "Julho",
        "Agosto",
        "Setembro",
        "Outubro",
        "Novembro",
        "Dezembro"};

    // Obtém o número de linhas da matriz meses
    size_t num_Linhas = sizeof(meses) / sizeof(meses[0]);

    // Obtém o número de colunas da matriz meses
    size_t num_Colunas = sizeof(meses[0]) / sizeof(meses[0][0]);

    // Calcula tamanho total da matriz meses em bytes
    size_t tamanho_Total = num_Linhas * num_Colunas * sizeof(meses[0][0]);

    printf(" Tamanho total da matriz     'meses' : %zu bytes\n", tamanho_Total);
    printf(" Número de linhas da matriz  'meses' : %zu\n", num_Linhas);
    printf(" Número de colunas da matriz 'meses' : %zu\n", num_Colunas);

    putchar('\n');

    // Utilizando dois for aninhados para percorrer a matriz
    for (size_t i = 0; i < num_Linhas; i++)
    {
        for (size_t j = 0; j < num_Colunas; j++)
        {
            if (meses[i][j] == '\0')
            {
                break; // Se encontrar o caractere nulo, termina a string
            }

            printf("%c", meses[i][j]);
        }
        printf("\n"); // Após imprimir o mês, imprime uma quebra de linha
    }

    putchar('\n');

    // Podemos utilizar o for aninhado porém há mais simples de imprimir basta fazermos
    // Impressão dos meses com índice
    for (int i = 0; i < num_Linhas; i++)
    {
        printf("%d - %s\n", i + 1, meses[i]);
    }

    // No quesito programação desta matriz de caracteres, para o caso de programar no exemplo acima
    // um calendário, Nomes e Sobrenomes, Palavras e Frases, Concatenação, Comparações de duas strings.
    return 0;
}
