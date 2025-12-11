#include <stdio.h>
#include <SDL2/SDL.h>

// Desenha um tabuleiro de xadrez que se adapta ao redimensionamento da janela

// Você pode definir o tamanho inicial da janela com #defines
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Tabuleiro de Xadrez",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE);

    if (!window)
    {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_bool running = SDL_TRUE;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = SDL_FALSE;
        }

        // obter tamanho atual da janela (para que o tabuleiro se adapte ao redimensionamento)
        int w, h;
        SDL_GetWindowSize(window, &w, &h);

        // escolhe o menor dos dois para manter tabuleiro quadrado
        int boardSize = (w < h) ? w : h;
        int tile = boardSize / 8; // tamanho de cada casa (inteiro)
        int marginX = (w - boardSize) / 2;
        int marginY = (h - boardSize) / 2;

        // limpar fundo (por exemplo, cor de borda)
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255); // cinza para margem
        SDL_RenderClear(renderer);

        // desenhar casas
        for (int row = 0; row < 8; ++row)
        {
            for (int col = 0; col < 8; ++col)
            {
                int isDark = (row + col) % 2; // 0 = clara, 1 = escura

                if (isDark)
                    SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255); // escura
                else
                    SDL_SetRenderDrawColor(renderer, 235, 235, 210, 255); // clara (bege)

                SDL_Rect r;
                r.x = marginX + col * tile;
                r.y = marginY + row * tile;
                r.w = tile;
                r.h = tile;

                SDL_RenderFillRect(renderer, &r);
            }
        }

        // opcional: desenhar linhas de grade (bordas das casas)
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 180); // linhas semitransparentes
        for (int i = 0; i <= 8; ++i)
        {
            // linhas horizontais
            int y = marginY + i * tile;
            SDL_RenderDrawLine(renderer, marginX, y, marginX + 8 * tile, y);

            // linhas verticais
            int x = marginX + i * tile;
            SDL_RenderDrawLine(renderer, x, marginY, x, marginY + 8 * tile);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(10); // pequeno descanso para evitar uso excessivo de CPU
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    /**
     * Para compilar:
     *
     * gcc -o tabuleiro tabuleiro.c `sdl2-config --cflags --libs`
     * ./tabuleiro
     */
    return 0;
}
