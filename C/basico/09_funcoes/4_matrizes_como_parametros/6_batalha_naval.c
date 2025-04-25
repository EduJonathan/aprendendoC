#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 4
#define NUM_NAVIOS 5
#define NUM_BOMBAS 3 // Ajustando o número de bombas para 3

/**
 * @brief Função para inicializar o tabuleiro com navios e bombas.
 *
 * @param tabuleiro O tabuleiro real do jogo (oculto).
 * @param tabuleiroExibido O tabuleiro exibido ao jogador.
 * @param navios Array para armazenar as posições dos navios.
 * @param bombas Array para armazenar as posições das bombas.
 */
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                          char tabuleiroExibido[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                          int navios[][2], int bombas[][2])
{
    // Inicializa o tabuleiro real
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiro[i][j] = 'A';        // A de água
            tabuleiroExibido[i][j] = '?'; // Células ocultas representadas por ?
        }
    }

    // Coloca os navios no tabuleiro real
    for (int i = 0; i < NUM_NAVIOS; i++)
    {
        int linha = rand() % TAMANHO_TABULEIRO;
        int coluna = rand() % TAMANHO_TABULEIRO;

        // Garante que não haja sobreposição de navios
        while (tabuleiro[linha][coluna] == 'N')
        {
            linha = rand() % TAMANHO_TABULEIRO;
            coluna = rand() % TAMANHO_TABULEIRO;
        }

        tabuleiro[linha][coluna] = 'N'; // N de navio
        navios[i][0] = linha;
        navios[i][1] = coluna;
    }

    // Coloca as bombas no tabuleiro real
    for (int i = 0; i < NUM_BOMBAS; i++)
    {
        int linha = rand() % TAMANHO_TABULEIRO;
        int coluna = rand() % TAMANHO_TABULEIRO;

        // Garante que não haja sobreposição de bombas com navios
        while (tabuleiro[linha][coluna] == 'B' || tabuleiro[linha][coluna] == 'N')
        {
            linha = rand() % TAMANHO_TABULEIRO;
            coluna = rand() % TAMANHO_TABULEIRO;
        }

        tabuleiro[linha][coluna] = 'B'; // B de bomba
        bombas[i][0] = linha;
        bombas[i][1] = coluna;
    }
}

/**
 * @brief Função para exibir o tabuleiro atual ao jogador.
 *
 * @param tabuleiroExibido O tabuleiro que o jogador vê.
 */
void exibirTabuleiro(char tabuleiroExibido[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    printf("Tabuleiro atual:\n");
    printf("\t 1   2   3   4\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("  %c", 'A' + i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("  [%c]", tabuleiroExibido[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Função para jogar um turno, verificando se o jogador encontrou um navio ou uma bomba.
 *
 * @param tabuleiro O tabuleiro real do jogo.
 * @param tabuleiroExibido O tabuleiro que o jogador vê.
 * @param linhaChar A letra correspondente à linha (A, B, C ou D).
 * @param coluna O número correspondente à coluna (1, 2, 3 ou 4).
 * @param bombasEncontradas Ponteiro para o contador de bombas encontradas.
 * @param naviosEncontrados Ponteiro para o contador de navios encontrados.
 * @return 1 se um navio foi encontrado, -1 se uma bomba foi encontrada, 0 se água foi encontrada.
 */
int jogarTurno(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
               char tabuleiroExibido[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
               char linhaChar, int coluna,
               int *bombasEncontradas, int *naviosEncontrados)
{
    int linha = linhaChar - 'A'; // Converte a letra para índice da linha (A = 0, B = 1, etc.)

    if (tabuleiro[linha][coluna] == 'N')
    {
        printf("PARABÉNS! Você encontrou um navio!\n");
        tabuleiroExibido[linha][coluna] = 'N'; // Revela o navio no tabuleiro exibido
        (*naviosEncontrados)++;
        return 1; // Encontrou um navio
    }
    else if (tabuleiro[linha][coluna] == 'B')
    {
        printf("INFELIZMENTE! Você encontrou uma bomba!\n");
        tabuleiroExibido[linha][coluna] = 'B'; // Revela a bomba no tabuleiro exibido
        (*bombasEncontradas)++;
        return -1; // Encontrou uma bomba
    }
    else
    {
        printf("Você achou água.\n");
        tabuleiroExibido[linha][coluna] = 'A'; // Revela água no tabuleiro exibido
        return 0;                              // Não encontrou nada
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    char tabuleiroReal[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];    // Tabuleiro real com as posições dos navios e bombas
    char tabuleiroExibido[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Tabuleiro que o jogador vê
    int navios[NUM_NAVIOS][2];                                   // Armazena as posições dos navios
    int bombas[NUM_BOMBAS][2];                                   // Armazena as posições das bombas

    int naviosEncontrados = 0;
    int bombasEncontradas = 0;

    // Inicializa os tabuleiros
    inicializarTabuleiro(tabuleiroReal, tabuleiroExibido, navios, bombas);

    printf("Bem-vindo ao Jogo de Batalha Naval!\n");
    printf("Objetivo: Encontrar %d navios sem acertar %d bombas.\n", NUM_NAVIOS, NUM_BOMBAS);
    printf("As células estão ocultas como [?]. Após sua jogada, serão reveladas.\n");

    // Loop do jogo
    while (naviosEncontrados < NUM_NAVIOS && bombasEncontradas < 3) // Jogo termina ao encontrar 3 bombas
    {
        char linhaChar;
        int coluna;

        // Exibe o tabuleiro atual (com células ocultas)
        exibirTabuleiro(tabuleiroExibido);

        // Solicita a jogada do jogador
        printf("Digite a coordenada (ex: A-3 ou B-2): ");
        scanf(" %c-%d", &linhaChar, &coluna);

        // Verifica se as coordenadas estão dentro dos limites do tabuleiro
        if ((linhaChar < 'A' || linhaChar > 'D') || (coluna < 1 || coluna > 4))
        {
            printf("Coordenada inválida. Tente novamente.\n");
            continue;
        }

        // Converte a coordenada para os índices do tabuleiro
        coluna -= 1; // Ajusta para índice de 0 a 3

        // Verifica se a célula já foi revelada
        if (tabuleiroExibido[linhaChar - 'A'][coluna] != '?')
        {
            printf("Você já escolheu esta coordenada. Tente outra.\n");
            continue;
        }

        // Executa o turno do jogador
        int resultado = jogarTurno(tabuleiroReal, tabuleiroExibido, linhaChar, coluna, &bombasEncontradas, &naviosEncontrados);

        // Checa se o jogo terminou devido a bombas
        if (bombasEncontradas >= 3) // Ajustado para 3 bombas
        {
            printf("Você encontrou %d bombas! Você perdeu!\n", NUM_BOMBAS);
            break;
        }

        // Checa se o jogador encontrou todos os navios
        if (naviosEncontrados == NUM_NAVIOS)
        {
            printf("Parabéns! Você encontrou todos os %d navios e venceu o jogo!\n", NUM_NAVIOS);
            break;
        }
    }

    // Mostra o tabuleiro completo no final do jogo
    printf("\nTabuleiro completo:\n");
    printf("    1   2   3   4\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("  %c", 'A' + i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("  [%c]", tabuleiroReal[i][j]);
        }
        printf("\n");
    }
    return 0;
}
