#include <stdio.h>
#include <stdlib.h> // Inclui a biblioteca para usar a função rand, srand
#include <time.h>   // Inclui a biblioteca para usar a função time
#include <string.h>
#include <unistd.h> // Inclui a biblioteca para usar a função sleep

/**
 * @enum colors
 *
 * @brief Enumeração das cores possíveis no jogo.
 */
enum colors
{
    AZUL = 0, /**< Cor azul */
    VERMELHO, /**< Cor vermelho */
    VERDE,    /**< Cor verde */
    AMARELO,  /**< Cor amarelo */
    LARANJA   /**< Cor laranja */
};

/**
 * @brief Função que gera uma sequência aleatória de cores.
 *
 * A sequência gerada tem 5 cores aleatórias, escolhidas entre as cores definidas.
 *
 * @param sequencia Array onde a sequência de cores será armazenada.
 */
void gerarSequencia(enum colors *sequencia)
{
    for (int i = 0; i < 5; i++)
    {
        sequencia[i] = rand() % 5; /**< Escolhe uma cor aleatória entre 0 e 4 */
    }
}

/**
 * @brief Função que imprime a sequência de cores para o jogador.
 *
 * Mostra a sequência de cores na tela para que o jogador memorize.
 *
 * @param sequencia Array com a sequência de cores a ser mostrada.
 */
void imprimirSequencia(enum colors *sequencia)
{
    printf("Memorize a sequência de cores\n");

    for (int i = 0; i < 5; i++)
    {
        switch (sequencia[i])
        {
        case 0:
            printf("Azul\n");
            break;

        case 1:
            printf("Vermelho\n");
            break;

        case 2:
            printf("Verde\n");
            break;

        case 3:
            printf("Amarelo\n");
            break;

        case 4:
            printf("Laranja\n");
            break;
        }
    }

    printf("\n\n");
}

/**
 * @brief Função que compara a sequência fornecida pelo jogador com a sequência correta.
 *
 * A função verifica quantas cores o jogador acertou em relação à sequência gerada pelo jogo.
 *
 * @param sequencia1 A sequência correta de cores.
 * @param tentativa A sequência fornecida pelo jogador.
 * @return O número de acertos do jogador.
 */
int compararSequencias(enum colors *sequencia1, char tentativa[5][10])
{
    int acertos = 0;
    const char *cores[] = {"Azul", "Vermelho", "Verde", "Amarelo", "Laranja"};

    for (int i = 0; i < 5; i++)
    {
        if (strcasecmp(cores[sequencia1[i]], tentativa[i]) == 0)
        {
            /**< Se a cor do jogador corresponder à cor da sequência, incrementa os acertos */
            acertos++;
        }
    }

    return acertos;
}

int main(int argc, char **argv)
{
    srand(time(NULL));        /**< Inicializa o gerador de números aleatórios com o tempo atual */
    enum colors sequencia[5]; /**< Array que armazenará a sequência de cores gerada */
    char tentativa[5][10];    /**< Array que armazenará a tentativa do jogador */
    int acertos = 0;          /**< Variável que armazenará o número de acertos do jogador */

    printf("BEM-VINDO AO Jogo da Memória\n\n");
    printf("DECORE TODA A SEQUENCIA DE CORES E ACERTE AO MENOS 3\n\n");

    while (1)
    {
        gerarSequencia(sequencia);    /**< Gera a sequência aleatória de cores */
        imprimirSequencia(sequencia); /**< Exibe a sequência para o jogador memorizar */

        printf("VOCÊ TEM 10 SEGUNDOS PARA ACERTAR A SEQUENCIA\n\n");
        sleep(10); /**< Dá 10 segundos para o jogador memorizar a sequência */

        system("cls"); /**< Irá Limpar a tela após os 10 segundos */

        printf("Sua vez, digite a sequencia de cores\n");
        for (int i = 0; i < 5; i++)
        {
            printf("Cor %d: ", i + 1);
            scanf("%s", tentativa[i]); /**< Captura a entrada do jogador */
        }

        /**< Compara a sequência do jogador com a gerada */
        acertos = compararSequencias(sequencia, tentativa);

        if (acertos >= 3)
        {
            printf("PARABENS, VOCE ACERTOU A SEQUENCIA\n");
        }
        else
        {
            printf("VOCE NÃO ACERTOU A SEQUENCIA\n");
        }

        char jogarNovamente;

        printf("Deseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente); /**< Pergunta ao jogador se ele deseja jogar novamente */

        if (jogarNovamente != 's' && jogarNovamente != 'S')
        {
            system("cls");
            break; /**< Encerra o loop e sai do jogo se o jogador não quiser jogar novamente */
        }
        printf("\n");
    }

    /** @note Recomendo executar no terminal para melhor execução do comando system("cls") */
    printf("OBRIGADO POR JOGAR!!\n");
    return 0;
}
