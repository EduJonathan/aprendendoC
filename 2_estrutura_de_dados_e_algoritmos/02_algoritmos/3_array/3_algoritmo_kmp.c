#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
 * @brief Calcula o vetor de falhas (prefix function) para o algoritmo KMP.
 *
 * @param padrao O padrão para o qual o vetor de falhas será calculado.
 * @param falhas Vetor para armazenar os valores das falhas.
 * @param tamanhoPadrao Tamanho do padrão.
 */
void calcularFalhas(const char *padrao, int *falhas, int tamanhoPadrao)
{
    falhas[0] = 0; // O primeiro valor do vetor de falhas é 0
    int j = 0;     // Índice para o prefixo

    for (int i = 1; i < tamanhoPadrao; i++)
    {
        while (j > 0 && padrao[i] != padrao[j])
        {
            j = falhas[j - 1]; // Retrocede para o último prefixo válido
        }
        if (padrao[i] == padrao[j])
        {
            j++; // Incrementa o comprimento do prefixo
        }
        falhas[i] = j; // Armazena o comprimento do maior prefixo/sufixo
    }
}

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
        falhas[i] = indiceFalha + 1; // Atualiza o vetor de falhas
    }
}

/**
 * @brief Algoritmo KMP para encontrar todas as ocorrências de um padrão no texto.
 *
 * @param texto O texto onde o padrão será buscado.
 * @param padrao O padrão a ser buscado.
 * @return true se o padrão for encontrado pelo menos uma vez, false caso contrário.
 */
bool buscarPadrao(const char *texto, const char *padrao)
{
    // Validação de entrada
    if (texto == NULL || padrao == NULL || texto[0] == '\0' || padrao[0] == '\0')
    {
        printf("Erro: Texto ou padrão inválido.\n");
        return false;
    }

    int tamanhoTexto = strlen(texto);
    int tamanhoPadrao = strlen(padrao);

    // Aloca memória para o vetor de falhas
    int *falhas = (int *)malloc(tamanhoPadrao * sizeof(int));
    if (falhas == NULL)
    {
        printf("Erro: Falha na alocação de memória.\n");
        return false;
    }

    // Calcula o vetor de falhas
    calcularFalhas(padrao, falhas, tamanhoPadrao);

    bool encontrado = false;
    int j = 0; // Índice para o padrão

    // Percorre o texto
    for (int i = 0; i < tamanhoTexto; i++)
    {
        while (j > 0 && texto[i] != padrao[j])
        {
            j = falhas[j - 1]; // Retrocede usando o vetor de falhas
        }

        if (texto[i] == padrao[j])
        {
            j++; // Avança no padrão
        }
        
        if (j == tamanhoPadrao)
        {
            printf("Padrão encontrado no índice %d\n", i - tamanhoPadrao + 1);
            encontrado = true;
            j = falhas[j - 1]; // Continua buscando outras ocorrências
        }
    }

    free(falhas); // Libera a memória alocada
    return encontrado;
}

int main(int argc, char **argv)
{
    char texto[1000], padrao[100];

    // Solicita entrada do usuário
    printf("Digite o texto: ");
    if (fgets(texto, sizeof(texto), stdin) == NULL)
    {
        printf("Erro ao ler o texto.\n");
        return 1;
    }
    // Remove o caractere de nova linha, se presente
    texto[strcspn(texto, "\n")] = '\0';

    printf("Digite o padrão: ");
    if (fgets(padrao, sizeof(padrao), stdin) == NULL)
    {
        printf("Erro ao ler o padrão.\n");
        return 1;
    }
    padrao[strcspn(padrao, "\n")] = '\0';

    // Executa a busca
    if (buscarPadrao(texto, padrao))
    {
        printf("O padrão \"%s\" foi encontrado no texto \"%s\".\n", padrao, texto);
    }
    else
    {
        printf("O padrão \"%s\" não foi encontrado no texto \"%s\".\n", padrao, texto);
    }

    return 0;
}
