#include "../include/campo_matriz.h"
#include <stdio.h>

void inicializarTabuleiro(Board board)
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void atualizarCampo(Board board, int linha, int coluna, char simbolo)
{
    if (campoValido(linha, coluna))
    {
        board[linha][coluna] = simbolo;
    }
}

bool campoVazio(Board board, int linha, int coluna)
{
    return campoValido(linha, coluna) && board[linha][coluna] == ' ';
}

bool campoValido(int linha, int coluna)
{
    return linha >= 0 && linha < BOARD_SIZE && coluna >= 0 && coluna < BOARD_SIZE;
}

void imprimirTabuleiro(Board board)
{
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        printf(" %c | %c | %c \n",
               board[i][0] ? board[i][0] : ' ',
               board[i][1] ? board[i][1] : ' ',
               board[i][2] ? board[i][2] : ' ');
               
        if (i < BOARD_SIZE - 1)
        {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}
