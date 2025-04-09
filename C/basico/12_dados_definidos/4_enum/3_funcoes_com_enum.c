#include <stdio.h>
#include <stdlib.h> // Inclui a biblioteca para usar a função rand, srand
#include <time.h>   // Inclui a biblioteca para usar a função time
#include <string.h>

/**
 * @enum moeda
 *
 * @brief Enumeração das escolhas do jogador.
 */
enum moeda
{
    CARA,
    COROA
};

/**
 * @brief Função que simula o lançamento de uma moeda.
 *
 * @return 0 para CARA e 1 para COROA
 */
int jogarMoeda(void)
{
    return rand() % 2;
}

/**
 * @brief Função que determina quem começa o jogo com base em dois lançamentos de moeda.
 *
 * @param jogador1 escolha do jogador 1
 * @param jogador2 escolha do jogador 2
 */
void quemComeca(enum moeda jogador1, enum moeda jogador2)
{
    int moeda1 = jogarMoeda();
    int moeda2 = jogarMoeda();

    printf("\nJogador 1 jogou a moeda e obteve %s\n", moeda1 == CARA ? "cara" : "coroa");
    printf("\nJogador 2 jogou a moeda e obteve %s\n", moeda2 == CARA ? "cara" : "coroa");

    if (moeda1 == moeda2)
    {
        // Se os dois jogadores acertarem o mesmo, a escolha é aleatória
        printf("Empate! Os dois jogadores jogaram %s. Vamos tentar novamente!\n", moeda1 == CARA ? "cara" : "coroa");

        // Recursão em caso de empate
        quemComeca(jogador1, jogador2);
    }
    else
    {
        if (moeda1 == CARA && jogador1 == COROA || moeda2 == CARA && jogador2 == COROA)
        {
            printf("\nO jogador 1 começa!\n");
        }
        else
        {
            printf("\nO jogador 2 começa!\n");
        }
    }
}

/**
 * @brief Função que determina a escolha do computador no jogo "Pedra, Papel ou Tesoura".
 *
 * @return A escolha do computador: "pedra", "papel", ou "tesoura"
 */
char *escolhaDoComputador(void)
{
    int num = rand() % 3;

    if (num == 0)
    {
        return "pedra";
    }
    else if (num == 1)
    {
        return "papel";
    }
    return "tesoura";
}

/**
 * @brief Função que compara as escolhas do jogador e do computador no jogo "Pedra, Papel ou Tesoura".
 *
 * @param escolhaDoJogador A escolha do jogador.
 * @param escolhaDoComputador A escolha do computador.
 * @return 1 se o jogador ganhar, -1 se o computador ganhar, 0 se for empate.
 */
int jogadorEscolhePedraPapelTesoura(const char *escolhaDoJogador, const char *escolhaDoComputador)
{
    // Utiliza strncmp para comparação das strings com tamanho máximo
    if (strncmp(escolhaDoJogador, escolhaDoComputador, strlen(escolhaDoJogador)) == 0)
    {
        return 0; // Empate
    }

    if ((strncmp(escolhaDoJogador, "pedra", 5) == 0 && strncmp(escolhaDoComputador, "tesoura", 7) == 0) ||
        (strncmp(escolhaDoJogador, "papel", 5) == 0 && strncmp(escolhaDoComputador, "pedra", 5) == 0) ||
        (strncmp(escolhaDoJogador, "tesoura", 7) == 0 && strncmp(escolhaDoComputador, "papel", 5) == 0))
    {
        // Caso o jogador ganhe
        return 1;
    }
    return -1; // Caso contrário, o computador ganha
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    enum moeda jogador1;
    enum moeda jogador2;

    printf("Jogador 1 escolha (0) para CARA ou (1) para COROA: ");
    scanf("%d", &jogador1);

    printf("Jogador 2 escolha (0) para CARA ou (1) para COROA: ");
    scanf("%d", &jogador2);

    // Determina quem começa com o lançamento da moeda
    quemComeca(jogador1, jogador2);

    char escolhaDoJogador[20];

    printf("Jogador 1 escolha (pedra, papel ou tesoura): ");
    scanf("%s", escolhaDoJogador);

    char *escolhaComputer = escolhaDoComputador();
    printf("Computador escolhe: %s\n", escolhaComputer);

    int resultado = jogadorEscolhePedraPapelTesoura(escolhaDoJogador, escolhaComputer);

    if (resultado == 1)
    {
        printf("Você ganhou!\n");
    }
    else if (resultado == -1)
    {
        printf("Computador ganhou!\n");
    }
    else
    {
        printf("Empate!\n");
    }

    return 0;
}
