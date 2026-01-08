#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * rand(random): função da biblioteca de manipulação de números aleatórios (stdlib.h)
 * que retorna um número aleatório, inteiro entre 0 e RAND_MAX, que geralmente é 32767.
 *
 * SINTAXE: int rand(void);
 *
 * @return Um número aleatório inteiro entre 0 e RAND_MAX.
 * @note O valor RAND_MAX é 32767.
 */

/**
 * @brief Gera e imprime uma quantidade específica de números aleatórios no intervalo de 1 a 100.
 * Este código gera cinco números aleatórios no intervalo de 1 a 100 e os imprime na tela.
 *
 * @param quantidade Número de números aleatórios a serem gerados e impressos.
 */
void gerarENumerosAleatorios(int quantidade)
{
    /**
     * srand: Inicializa a "semente" do gerador de números aleatórios com base no tempo atual.
     * Isso garante que os números aleatórios variem a cada execução do programa.
     *
     * SINTAXE: void srand(unsigned int seed);
     *
     * @param seed O valor usado como semente para o gerador de números aleatórios.
     * @note O valor da semente deve ser sempre diferente para garantir que os números
     * aleatórios variem.
     */
    srand(time(NULL));

    printf("Números aleatórios:\n");

    // Loop para gerar e imprimir cinco numeros aleatórios
    for (int i = 0; i < quantidade; i++)
    {
        // Gera um número aleatório no intervalo de 1 a 100
        int numeroAleatorio = rand() % 100 + 1;

        // Imprime o número aleatório
        printf("%d\n", numeroAleatorio);
    }
}

int main(int argc, char **argv)
{
    // Define a quantidade de números aleatórios a serem gerados
    const int quantidadeDeNumeros = 5;

    // Chama a função para gerar e imprimir números aleatórios
    gerarENumerosAleatorios(quantidadeDeNumeros);

    /*
     * srand(time(NULL)): A função srand é utilizada para inicializar a semente do gerador
     * de números aleatórios (rand). Ao usar o tempo atual como semente (time(NULL)),
     * você garante que os números aleatórios variem a cada execução do programa.
     *
     * rand() % 100 + 1: A expressão rand() % 100 + 1 gera um número aleatório no intervalo
     * de 1 a 100. O operador % é usado para obter o resto da divisão por 100, e adicionamos 1
     * para garantir que o número não seja zero.
     *
     * Lembre-se de que, para obter sequências diferentes a cada vez, a semente (srand)
     * é inicializada com base no tempo atual.
     */
    return 0;
}
