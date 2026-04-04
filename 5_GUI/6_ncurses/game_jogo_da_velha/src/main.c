#include <ncurses.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/game.h"
#include "../include/campo_matriz.h"

void draw_board(WINDOW *win, const Board board, int cy, int cx)
{
    if (!win)
        return;
        
    werase(win);
    box(win, 0, 0);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int y = 2 + i * 2;
            int x = 4 + j * 4;
            mvwprintw(win, y, x, "%c", board[i][j] == ' ' ? '.' : board[i][j]);
        }
        if (i < 2)
        {
            mvwprintw(win, 3 + i * 2, 2, "---+---+---");
        }
    }

    mvwchgat(win, 2 + cy * 2, 4 + cx * 4, 1, A_REVERSE, 0, NULL);
    wrefresh(win);
}

int main(int argc, char **argv)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    Game game;
    newGame(&game);
    escolherModo(&game);
    escolherSimbolo(&game);

    WINDOW *board_win = newwin(9, 17, (LINES - 9) / 2, (COLS - 17) / 2);

    int cursor_y = 0, cursor_x = 0;
    bool game_over = false;
    char msg[80] = "";

    while (!game_over)
    {
        draw_board(board_win, game.board, cursor_y, cursor_x);

        if (game.vsAI && game.simboloAtual == game.simboloIA)
        {
            mvprintw(LINES - 4, 0, "IA (%c) pensando...", game.simboloAtual);
            refresh();
            napms(500);

            fazerJogadaIA(&game);

            if (checarVitoria(&game))
            {
                snprintf(msg, sizeof(msg), "A IA (%c) VENCEU! 😢", game.simboloAtual);
                game_over = true;
            }
            else if (checarEmpate(&game))
            {
                snprintf(msg, sizeof(msg), "EMPATE!");
                game_over = true;
            }
            else
            {
                game.simboloAtual = game.simboloJogador1;
                msg[0] = '\0';
            }
        }
        else
        {
            mvprintw(LINES - 4, 0, "Sua vez (%c) → setas + ENTER", game.simboloAtual);
            mvprintw(LINES - 3, 0, "%s", msg);
            clrtoeol();
            refresh();

            int ch = getch();
            switch (ch)
            {
            case KEY_UP:
                if (cursor_y > 0)
                {
                    cursor_y--;
                }
                break;

            case KEY_DOWN:
                if (cursor_y < 2)
                {
                    cursor_y++;
                }
                break;

            case KEY_LEFT:
                if (cursor_x > 0)
                {
                    cursor_x--;
                }
                break;

            case KEY_RIGHT:
                if (cursor_x < 2)
                {
                    cursor_x++;
                }
                break;

            case '\n':
            case KEY_ENTER:
            case ' ':
                if (campoVazio(game.board, cursor_y, cursor_x))
                {
                    atualizarCampo(game.board, cursor_y, cursor_x, game.simboloAtual);
                    game.jogadas++;

                    if (checarVitoria(&game))
                    {
                        snprintf(msg, sizeof(msg), "VOCÊ VENCEU! 🎉");
                        game_over = true;
                    }
                    else if (checarEmpate(&game))
                    {
                        snprintf(msg, sizeof(msg), "EMPATE!");
                        game_over = true;
                    }
                    else
                    {
                        game.simboloAtual = game.vsAI ? game.simboloIA : (game.simboloAtual == game.simboloJogador1 ? game.simboloJogador2 : game.simboloJogador1);
                        msg[0] = '\0';
                    }
                }
                else
                {
                    snprintf(msg, sizeof(msg), "Posição ocupada!");
                }
                break;

            case 'q':
            case 'Q':
                game_over = true;
                break;
            }
        }
    }

    draw_board(board_win, game.board, cursor_y, cursor_x);
    mvprintw(LINES - 2, 0, "%s  Pressione qualquer tecla para sair...", msg);
    refresh();
    getch();

    delwin(board_win);
    endwin();
    return 0;
}
