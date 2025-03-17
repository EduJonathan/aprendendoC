#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura que armazena um nome.
 *
 * A estrutura `names` contém um ponteiro para um nome (uma string).
 */
struct names
{
    char *nome; /**< Ponteiro para o nome */
};

/**
 * @brief Função de comparação para buscar nomes.
 *
 * Compara dois nomes (strings) para a função `bsearch`. A comparação é feita
 * utilizando a função `strcmp`, que retorna um valor negativo, zero ou positivo,
 * dependendo da ordem alfabética dos nomes.
 *
 * @param a1 Ponteiro para o primeiro nome a ser comparado.
 * @param b2 Ponteiro para o segundo nome a ser comparado.
 * @return Um valor negativo, zero ou positivo, conforme a comparação dos nomes.
 */
int stringCall(const void *a1, const void *b2)
{
    const char *a = (const char *)a1;
    const struct names *b = (const struct names *)b2;

    /*< Compara a string procurada com o nome da estrutura */
    return strcmp(a, b->nome);
}

int main(int argc, char **argv)
{
    // Definindo um array de estruturas 'names' com nomes já definidos
    struct names nomes[5] = {{"eduardo"}, {"jonathan"}, {"maria"}, {"joao"}, {"pedro"}};

    // Nome a ser buscado
    const char *nomeBusca = "pedro";

    // Realizando a busca binária para o nome "pedro"
    struct names *encontrado = bsearch(nomeBusca, nomes, 5, sizeof(struct names), stringCall);

    // Verificando se o nome foi encontrado e imprimindo o resultado
    if (encontrado != NULL)
    {
        // Calculando a posição do nome encontrado
        int posicao = encontrado - nomes;
        printf("Encontrado: %s na posição %d\n", encontrado->nome, posicao);
    }
    else
    {
        printf("Nome nao encontrado\n");
    }

    printf("------------------------------------\n");

    // Definindo um array de estruturas 'names' com nomes já definidos
    struct names nomesDesornado[5] = {{"Pedro"}, {"Maria"}, {"João"}, {"Eduardo"}, {"Jonathan"}};

    // Realizando a busca binária para o nome "pedro"
    struct names *nomeEncontrado = bsearch("Maria", nomes, 5, sizeof(struct names), stringCall);

    // Verificando se o nome foi nomeEncontrado e imprimindo o resultado
    if (nomeEncontrado != NULL)
    {
        printf("Encontrado: %s\n", nomeEncontrado->nome);
    }
    else
    {
        printf("Nome não Encontrado\n");
    }

    /** @note A busca binária para melhor desempenho em busca, deve-se está ordenada.  */
    return 0;
}
