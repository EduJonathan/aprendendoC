#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * O problema da troca de moedas visa encontrar o número mínimo de moedas para uma determinada
 * quantia. Esse problema é uma ótima aplicação de PD, pois podemos calcular o valor mínimo de
 * moedas para todos os valores até o valor final e, assim, encontrar a solução ótima.
 *
 * Recorrência:
 * Para cada valor 𝑣, a solução pode ser expressa como:
 *
 * 𝑑𝑝[𝑣] = min⁡(𝑑𝑝[𝑣], 𝑑𝑝[𝑣 − 𝑐𝑜𝑖𝑛] + 1)
 *
 * Onde coin são as moedas disponíveis.
 *
 * @param moedas Vetor com os valores das moedas disponíveis.
 * @param quantidade Número de tipos de moedas diferentes.
 * @param valor_alvo Valor que se deseja formar com as moedas.
 * @param moedas_usadas Ponteiro para vetor que armazenará as moedas utilizadas na solução ótima.
 * @return Número mínimo de moedas necessárias ou -1 se for impossível.
 */
int trocarMoedas(const int *moedas, size_t quantidade, int valor_alvo, int **moedas_usadas)
{
    if (valor_alvo < 0 || quantidade == 0 || moedas == NULL)
        return -1;

    int *minimo_moedas = malloc((valor_alvo + 1) * sizeof(int));
    int *ultima_moeda  = malloc((valor_alvo + 1) * sizeof(int));

    if (!minimo_moedas || !ultima_moeda)
    {
        fprintf(stderr, "Erro de alocação de memória.\n");
        free(minimo_moedas);
        free(ultima_moeda);
        return -1;
    }

    minimo_moedas[0] = 0;
    ultima_moeda[0] = -1;

    for (int i = 1; i <= valor_alvo; ++i)
    {
        minimo_moedas[i] = INT_MAX;
        ultima_moeda[i]  = -1;
    }

    for (size_t i = 0; i < quantidade; ++i)
    {
        for (int valor = moedas[i]; valor <= valor_alvo; ++valor)
        {
            if (minimo_moedas[valor - moedas[i]] != INT_MAX && minimo_moedas[valor] > minimo_moedas[valor - moedas[i]] + 1)
            {
                minimo_moedas[valor] = minimo_moedas[valor - moedas[i]] + 1;
                ultima_moeda[valor] = (int)i;
            }
        }
    }

    if (minimo_moedas[valor_alvo] == INT_MAX)
    {
        free(minimo_moedas);
        free(ultima_moeda);
        *moedas_usadas = NULL;
        return -1;
    }

    int total_moedas = minimo_moedas[valor_alvo];
    *moedas_usadas = malloc(total_moedas * sizeof(int));
    if (!*moedas_usadas)
    {
        fprintf(stderr, "Erro de alocação ao reconstruir a solução.\n");
        free(minimo_moedas);
        free(ultima_moeda);
        return -1;
    }

    int restante = valor_alvo;
    int indice   = 0;
    while (restante > 0 && indice < total_moedas)
    {
        int indice_moeda = ultima_moeda[restante];
        if (indice_moeda == -1)
            break;
        (*moedas_usadas)[indice++] = moedas[indice_moeda];
        restante -= moedas[indice_moeda];
    }

    free(minimo_moedas);
    free(ultima_moeda);
    return total_moedas;
}

int main(int argc, char **argv)
{
    int moedas_disponiveis[] = {1, 2, 3, 4};
    size_t quantidade_moedas = sizeof(moedas_disponiveis) / sizeof(moedas_disponiveis[0]);
    int valor_desejado       = 15;

    int *moedas_utilizadas = NULL;
    int total_moedas = trocarMoedas(moedas_disponiveis, quantidade_moedas, valor_desejado, &moedas_utilizadas);

    if (total_moedas == -1)
    {
        printf("Não é possível formar o valor %d com as moedas fornecidas.\n", valor_desejado);
    }
    else
    {
        printf("Número mínimo de moedas para formar %d: %d\n", valor_desejado, total_moedas);
        printf("Moedas utilizadas: ");
        for (int i = 0; i < total_moedas; ++i)
        {
            printf("%d ", moedas_utilizadas[i]);
        }
        printf("\n");
    }

    free(moedas_utilizadas);
    return 0;
}
