#include <stdio.h>
#include <SDL2/SDL.h>

#define W 600
#define H 400

typedef struct
{
    SDL_Rect rect;
    SDL_Color color;
    SDL_Color hover_color;
} Button;

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *win = SDL_CreateWindow("3 Botões RGB - Muda Fundo",
                                       SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    Button btn_red = {{100, 150, 120, 100}, {255, 0, 0, 255}, {255, 100, 100, 255}};   // Cria o botão vermelho
    Button btn_green = {{240, 150, 120, 100}, {0, 255, 0, 255}, {100, 255, 100, 255}}; // Cria o botão verde
    Button btn_blue = {{380, 150, 120, 100}, {0, 0, 255, 255}, {100, 100, 255, 255}};  // Cria o botão azul

    Button *buttons[3] = {&btn_red, &btn_green, &btn_blue};
    SDL_Color bg = {30, 30, 50, 255}; // fundo inicial (azul escuro)

    int mouse_x = 0, mouse_y = 0;
    int quit = 0;

    while (!quit)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                quit = 1;
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
                mouse_x = e.button.x;
                mouse_y = e.button.y;

                if (SDL_PointInRect(&(SDL_Point){mouse_x, mouse_y}, &btn_red.rect))
                    bg = btn_red.color;
                else if (SDL_PointInRect(&(SDL_Point){mouse_x, mouse_y}, &btn_green.rect))
                    bg = btn_green.color;
                else if (SDL_PointInRect(&(SDL_Point){mouse_x, mouse_y}, &btn_blue.rect))
                    bg = btn_blue.color;
            }
        }

        // Fundo
        SDL_SetRenderDrawColor(ren, bg.r, bg.g, bg.b, 255);
        SDL_RenderClear(ren);

        // Desenha os 3 botões
        SDL_GetMouseState(&mouse_x, &mouse_y);
        for (int i = 0; i < 3; i++)
        {
            Button *b = buttons[i];
            int hovered = SDL_PointInRect(&(SDL_Point){mouse_x, mouse_y}, &b->rect);
            SDL_Color c = hovered ? b->hover_color : b->color;

            SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, 255);
            SDL_RenderFillRect(ren, &b->rect);

            // Borda mais escura
            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
            SDL_RenderDrawRect(ren, &b->rect);
        }

        SDL_RenderPresent(ren);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    /**
     * gcc butoes_rgb.c -o rgb `sdl2-config --cflags --libs`
     * ./rgb
     */
    return 0;
}
