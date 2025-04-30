#include <stdio.h>

#define VAZIO 3     /**< Valor que representa uma célula vazia */
#define JOGADOR_X 1 /**< Valor que representa o jogador X */
#define JOGADOR_O 0 /**< Valor que representa o jogador O */

/**
 * Função para imprimir o tabuleiro do jogo.
 *
 * @param tabuleiro O tabuleiro 3x3 representando o estado do jogo.
 */
void imprimirTabuleiro(int tabuleiro[3][3])
{
    printf("\n    0   1   2\n");
    printf("  -------------\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d |", i); // Exibe o índice da linha
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == VAZIO)
                printf("   |");
            else if (tabuleiro[i][j] == JOGADOR_X)
                printf(" X |");
            else
                printf(" O |");
        }
        printf("\n  -------------\n");
    }
}

/**
 * Função para verificar se algum jogador venceu.
 *
 * @param tabuleiro O tabuleiro 3x3 representando o estado do jogo.
 * @param jogador O jogador que será verificado (1 para X, 0 para O).
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int verificarVencedor(int tabuleiro[3][3], int jogador)
{
    // Verificação de linhas, colunas
    for (int i = 0; i < 3; i++)
    {
        if ((tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) ||
            (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador))
        {
            return 1;
        }
    }
    // Verificação das diagonais
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador))
    {
        return 1;
    }
    return 0;
}

/**
 * Função para verificar se o tabuleiro está cheio (empate).
 *
 * @param tabuleiro O tabuleiro 3x3 representando o estado do jogo.
 *
 * @return 1 se o tabuleiro estiver cheio (empate), 0 caso contrário.
 */
int verificarEmpate(int tabuleiro[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == VAZIO)
            {
                return 0; // Ainda há espaços vazios
            }
        }
    }
    return 1; // O tabuleiro está cheio
}

/**
 * Função para realizar a jogada de um jogador.
 *
 * @param tabuleiro O tabuleiro 3x3 representando o estado do jogo.
 * @param jogador O jogador que está fazendo a jogada (1 para X, 0 para O).
 *
 * @return 0 após a jogada ser realizada.
 */
int realizarJogada(int tabuleiro[3][3], int jogador)
{
    int linha = 0, coluna = 0;
    while (1)
    {
        printf("Jogador %c, escolha a linha e a coluna (Exemplo: 0-1, 1-1, 0-2): ", jogador == JOGADOR_X ? 'X' : 'O');
        scanf("%d-%d", &linha, &coluna); // Altera a entrada para o formato "linha-coluna"

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3 && tabuleiro[linha][coluna] == VAZIO)
        {
            tabuleiro[linha][coluna] = jogador;
            break;
        }
        else
        {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    int tabuleiro[3][3] = {
        {VAZIO, VAZIO, VAZIO},
        {VAZIO, VAZIO, VAZIO},
        {VAZIO, VAZIO, VAZIO}};

    int turno = 0; // 0 para Jogador X, 1 para Jogador O
    int vencedor = 0;

    printf("Bem-vindo ao Jogo da Velha!\n");

    while (1)
    {
        imprimirTabuleiro(tabuleiro);
        if (turno == 0)
        {
            realizarJogada(tabuleiro, JOGADOR_X); // Jogador X faz a jogada
            vencedor = verificarVencedor(tabuleiro, JOGADOR_X);
            if (vencedor)
            {
                imprimirTabuleiro(tabuleiro);
                printf("Jogador X venceu!\n");
                break;
            }
        }
        else
        {
            realizarJogada(tabuleiro, JOGADOR_O); // Jogador O faz a jogada
            vencedor = verificarVencedor(tabuleiro, JOGADOR_O);
            if (vencedor)
            {
                imprimirTabuleiro(tabuleiro);
                printf("Jogador O venceu!\n");
                break;
            }
        }

        // Verifica se houve empate
        if (verificarEmpate(tabuleiro))
        {
            imprimirTabuleiro(tabuleiro);
            printf("Empate!\n");
            break;
        }

        // Troca o turno
        turno = 1 - turno;
    }

    return 0;
}
