#include <math.h>
#include <SDL2/SDL.h>

#define WIDTH 800  // Largura da janela
#define HEIGHT 600 // Altura da janela

// Função para desenhar círculo preenchido + borda
void draw_circle(SDL_Renderer *ren, int cx, int cy, int radius)
{
    // Círculo preenchido (azul)
    for (int y = -radius; y <= radius; y++)
    {
        for (int x = -radius; x <= radius; x++)
        {
            if (x * x + y * y <= radius * radius)
            {
                SDL_RenderDrawPoint(ren, cx + x, cy + y);
            }
        }
    }

    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255); // borda branca

    for (int i = 0; i < 360; i += 2)
    {
        float rad = i * 3.14159265f / 180.0f;
        int x = (int)(radius * cosf(rad));
        int y = (int)(radius * sinf(rad));
        SDL_RenderDrawPoint(ren, cx + x, cy + y);
    }
}

// Função para desenhar retângulo preenchido + borda
void draw_rect(SDL_Renderer *ren, int x, int y, int w, int h, int filled)
{
    SDL_Rect rect = {x, y, w, h};
    if (filled)
    {
        SDL_RenderFillRect(ren, &rect);
    }
    else
    {
        SDL_RenderDrawRect(ren, &rect);
    }
}

// Função para desenhar triângulo preenchido + borda
void draw_triangle(SDL_Renderer *ren, int x1, int y1, int x2, int y2, int x3, int y3)
{
    // Triângulo preenchido (amarelo)
    SDL_SetRenderDrawColor(ren, 255, 220, 0, 255);

    // Usando linhas para preencher (simples)
    int min_y = (y1 < y2 ? (y1 < y3 ? y1 : y3) : (y2 < y3 ? y2 : y3));
    int max_y = (y1 > y2 ? (y1 > y3 ? y1 : y3) : (y2 > y3 ? y2 : y3));

    for (int y = min_y; y <= max_y; y++)
    {
        int xa = x1 + (x2 - x1) * (y - y1) / (y2 - y1);
        int xb = x1 + (x3 - x1) * (y - y1) / (y3 - y1);
        if (xa > xb)
        {
            int t = xa;
            xa = xb;
            xb = t;
        }
        SDL_RenderDrawLine(ren, xa, y, xb, y);
    }

    // Borda branca
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
    SDL_RenderDrawLine(ren, x1, y1, x2, y2);
    SDL_RenderDrawLine(ren, x2, y2, x3, y3);
    SDL_RenderDrawLine(ren, x3, y3, x1, y1);
}

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erro SDL: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Formas Básicas - SDL2",
                                       SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                       WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    int running = 1;
    SDL_Event e;

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                running = 0;
        }

        // Fundo azul escuro
        SDL_SetRenderDrawColor(ren, 20, 20, 40, 255);
        SDL_RenderClear(ren);

        // === CÍRCULO (esquerda superior) ===
        SDL_SetRenderDrawColor(ren, 0, 180, 255, 255); // azul neon
        draw_circle(ren, 200, 150, 80);

        // === QUADRADO (direita superior) ===
        SDL_SetRenderDrawColor(ren, 255, 80, 80, 255); // vermelho
        draw_rect(ren, 480, 70, 160, 160, 1);
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        draw_rect(ren, 480, 70, 160, 160, 0);

        // === TRIÂNGULO (esquerda inferior) ===
        draw_triangle(ren, 180, 400, 120, 520, 240, 520);

        // === RETÂNGULO (direita inferior) ===
        SDL_SetRenderDrawColor(ren, 100, 255, 100, 255); // verde claro
        draw_rect(ren, 450, 380, 200, 120, 1);
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        draw_rect(ren, 450, 380, 200, 120, 0);

        SDL_RenderPresent(ren);
    }

    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    /**
     * gcc desenhos.c -o formas `sdl2-config --cflags --libs`
     * ./formas
     */
    return 0;
}
