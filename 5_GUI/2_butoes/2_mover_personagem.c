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

    SDL_Window *win = SDL_CreateWindow("Botões Direcionais - Mover Personagem",
                                       SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    // Personagem (quadrado azul)
    SDL_Rect player = {W / 2 - 20, H / 2 - 20, 40, 40};

    // Botões direcionais
    Button btn_up = {{260, 250, 80, 40}, {200, 200, 200, 255}, {255, 255, 255, 255}};
    Button btn_down = {{260, 310, 80, 40}, {200, 200, 200, 255}, {255, 255, 255, 255}};
    Button btn_left = {{200, 310, 60, 40}, {200, 200, 200, 255}, {255, 255, 255, 255}};
    Button btn_right = {{350, 310, 60, 40}, {200, 200, 200, 255}, {255, 255, 255, 255}};

    Button *buttons[4] = {&btn_up, &btn_down, &btn_left, &btn_right};

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

                SDL_Point p = {mouse_x, mouse_y};

                if (SDL_PointInRect(&p, &btn_up.rect))
                    player.y -= 10; // mover pra cima

                else if (SDL_PointInRect(&p, &btn_down.rect))
                    player.y += 10; // mover pra baixo

                else if (SDL_PointInRect(&p, &btn_left.rect))
                    player.x -= 10; // mover pra esquerda

                else if (SDL_PointInRect(&p, &btn_right.rect))
                    player.x += 10; // mover pra direita
            }
        }

        // Limita movimento dentro da janela
        if (player.x < 0)
            player.x = 0;
        if (player.y < 0)
            player.y = 0;
        if (player.x + player.w > W)
            player.x = W - player.w;
        if (player.y + player.h > H)
            player.y = H - player.h;

        // Fundo
        SDL_SetRenderDrawColor(ren, 30, 30, 50, 255);
        SDL_RenderClear(ren);

        // Desenha o player
        SDL_SetRenderDrawColor(ren, 50, 150, 255, 255);
        SDL_RenderFillRect(ren, &player);

        // Desenha os botões direcionais
        SDL_GetMouseState(&mouse_x, &mouse_y);
        SDL_Point mp = {mouse_x, mouse_y};

        for (int i = 0; i < 4; i++)
        {
            Button *b = buttons[i];
            int hovered = SDL_PointInRect(&mp, &b->rect);
            SDL_Color c = hovered ? b->hover_color : b->color;

            SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, 255);
            SDL_RenderFillRect(ren, &b->rect);

            SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
            SDL_RenderDrawRect(ren, &b->rect);
        }

        // Desenha símbolos (↑ ↓ ← →)
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);

        SDL_RenderDrawLine(ren, btn_up.rect.x + 40, btn_up.rect.y + 5,
                           btn_up.rect.x + 40, btn_up.rect.y + 35);
        SDL_RenderDrawLine(ren, btn_up.rect.x + 30, btn_up.rect.y + 15,
                           btn_up.rect.x + 40, btn_up.rect.y + 5);
        SDL_RenderDrawLine(ren, btn_up.rect.x + 50, btn_up.rect.y + 15,
                           btn_up.rect.x + 40, btn_up.rect.y + 5);

        SDL_RenderDrawLine(ren, btn_down.rect.x + 40, btn_down.rect.y + 5,
                           btn_down.rect.x + 40, btn_down.rect.y + 35);
        SDL_RenderDrawLine(ren, btn_down.rect.x + 30, btn_down.rect.y + 25,
                           btn_down.rect.x + 40, btn_down.rect.y + 35);
        SDL_RenderDrawLine(ren, btn_down.rect.x + 50, btn_down.rect.y + 25,
                           btn_down.rect.x + 40, btn_down.rect.y + 35);

        SDL_RenderDrawLine(ren, btn_left.rect.x + 5, btn_left.rect.y + 20,
                           btn_left.rect.x + 55, btn_left.rect.y + 20);
        SDL_RenderDrawLine(ren, btn_left.rect.x + 15, btn_left.rect.y + 10,
                           btn_left.rect.x + 5, btn_left.rect.y + 20);
        SDL_RenderDrawLine(ren, btn_left.rect.x + 15, btn_left.rect.y + 30,
                           btn_left.rect.x + 5, btn_left.rect.y + 20);
        SDL_RenderDrawLine(ren, btn_right.rect.x + 5, btn_right.rect.y + 20,
                           btn_right.rect.x + 55, btn_right.rect.y + 20);
        SDL_RenderDrawLine(ren, btn_right.rect.x + 45, btn_right.rect.y + 10,
                           btn_right.rect.x + 55, btn_right.rect.y + 20);
        SDL_RenderDrawLine(ren, btn_right.rect.x + 45, btn_right.rect.y + 30,
                           btn_right.rect.x + 55, btn_right.rect.y + 20);

        SDL_RenderPresent(ren);
        SDL_Delay(16);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    /**
     * gcc mover_personagem.c -o movimento `sdl2-config --cflags --libs`
     * ./movimento
     */
    return 0;
}
