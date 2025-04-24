#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_TABULEIRO 4
#define NUM_NAVIOS 5
#define NUM_BOMBAS 3

/**
 * * @brief Função para inicializar o tabuleiro com navios e bombas.
 *
 * @param tabuleiro O tabuleiro do jogo.
 * @param navios Array para armazenar as posições dos navios.
 * @param bombas Array para armazenar as posições das bombas.
 *
 * @note O tabuleiro é representado por um array 2D de caracteres, onde 'N' representa um navio,
 * 'B' representa uma bomba e '~' representa água.
 */
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int navios[][2], int bombas[][2])
{
    // Inicializa o tabuleiro com água (representado por '~')
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            tabuleiro[i][j] = '~';
        }
    }

    // Coloca os navios no tabuleiro
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

    // Coloca as bombas no tabuleiro
    for (int i = 0; i < NUM_BOMBAS; i++)
    {
        int linha = rand() % TAMANHO_TABULEIRO;
        int coluna = rand() % TAMANHO_TABULEIRO;
        // Garante que não haja sobreposição de bombas
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
 * @brief Função para exibir o tabuleiro atual.
 *
 * @param tabuleiro O tabuleiro do jogo.
 */
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO])
{
    printf("Tabuleiro atual:\n");
    printf("   1  2  3  4\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        printf("%c  ", 'A' + i); // Letras de A a D
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Função para jogar um turno, verificando se o jogador encontrou um navio ou uma bomba.
 *
 * @param tabuleiro O tabuleiro do jogo.
 * @param linhaChar A letra correspondente à linha (A, B, C ou D).
 * @param coluna O número correspondente à coluna (1, 2, 3 ou 4).
 * @param bombasEncontradas Ponteiro para o contador de bombas encontradas.
 * @param naviosEncontrados Ponteiro para o contador de navios encontrados.
 * @return 1 se um navio foi encontrado, -1 se uma bomba foi encontrada, 0 se água foi encontrada.
 */
int jogarTurno(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], char linhaChar, int coluna, int *bombasEncontradas, int *naviosEncontrados)
{
    int linha = linhaChar - 'A'; // Converte a letra para índice da linha (A = 0, B = 1, etc.)

    if (tabuleiro[linha][coluna] == 'N')
    {
        printf("Você encontrou um navio!\n");
        tabuleiro[linha][coluna] = 'X'; // Marca o navio como encontrado
        (*naviosEncontrados)++;
        return 1; // Encontrei um navio
    }
    else if (tabuleiro[linha][coluna] == 'B')
    {
        printf("Você encontrou uma bomba!\n");
        tabuleiro[linha][coluna] = 'O'; // Marca a bomba como encontrada
        (*bombasEncontradas)++;
        return -1; // Encontrei uma bomba
    }
    else
    {
        printf("Você acertou água.\n");
        tabuleiro[linha][coluna] = 'O'; // Marca o tiro como água
        return 0;                       // Não encontrei nada
    }
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int navios[NUM_NAVIOS][2]; // Armazena as posições dos navios
    int bombas[NUM_BOMBAS][2]; // Armazena as posições das bombas

    int naviosEncontrados = 0;
    int bombasEncontradas = 0;

    // Inicializa o tabuleiro com navios e bombas
    inicializarTabuleiro(tabuleiro, navios, bombas);

    printf("Bem-vindo ao Jogo de Batalha Naval!\n");
    printf("Objetivo: Encontrar 5 navios sem acertar 3 bombas.\n");

    // Loop do jogo
    while (naviosEncontrados < NUM_NAVIOS && bombasEncontradas < NUM_BOMBAS)
    {
        char linhaChar;
        int coluna;

        // Exibe o tabuleiro
        exibirTabuleiro(tabuleiro);

        // Solicita a jogada do jogador
        printf("Digite a coordenada (ex: A-3 ou 2-B): ");
        scanf(" %c-%d", &linhaChar, &coluna);

        // Verifica se as coordenadas estão dentro dos limites do tabuleiro
        if ((linhaChar < 'A' || linhaChar > 'D') || (coluna < 1 || coluna > 4))
        {
            printf("Coordenada inválida. Tente novamente.\n");
            continue;
        }

        // Converte a coordenada para os índices do tabuleiro
        coluna -= 1; // Ajusta para índice de 0 a 3

        // Faz o movimento do jogador
        int resultado = jogarTurno(tabuleiro, linhaChar, coluna, &bombasEncontradas, &naviosEncontrados);

        // Checa se o jogo terminou devido a bombas
        if (bombasEncontradas >= NUM_BOMBAS)
        {
            printf("Você encontrou 3 bombas! Você perdeu!\n");
            break;
        }

        // Checa se o jogador encontrou todos os navios
        if (naviosEncontrados == NUM_NAVIOS)
        {
            printf("Parabéns! Você encontrou todos os navios e venceu o jogo!\n");
            break;
        }
    }
    return 0;
}
