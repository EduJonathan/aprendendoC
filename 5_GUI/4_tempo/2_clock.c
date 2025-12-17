#include <stdio.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define WINDOW_W 600            // Largura da janela
#define WINDOW_H 600            // Altura da janela
#define CLOCK_R 250             // Raio do relógio
#define PI 3.14159265359        // Valor de PI
#define CENTER_X (WINDOW_W / 2) // Centro X do relógio
#define CENTER_Y (WINDOW_H / 2) // Centro Y do relógio

SDL_Window   *window   = NULL;
SDL_Renderer *renderer = NULL;
TTF_Font     *font     = NULL;

void draw_hand(float angle_deg, float length, int thickness, Uint8 r, Uint8 g, Uint8 b)
{
    float rad = angle_deg * PI / 180.0f;
    int x = CENTER_X + length * cosf(rad);
    int y = CENTER_Y + length * sinf(rad);

    // Desenha a linha do ponteiro, thickness é uma função da SDL2_gfx que desenha linhas grossas
    thickLineRGBA(renderer,
                  CENTER_X, CENTER_Y,
                  x, y,
                  thickness,
                  r, g, b, 255);
}

void draw_clock_face()
{
    // Fundo
    SDL_SetRenderDrawColor(renderer, 20, 20, 40, 255);
    SDL_RenderClear(renderer);

    // Borda externa do relógio
    filledCircleRGBA(renderer, CENTER_X, CENTER_Y, CLOCK_R + 20, 40, 40, 60, 255);
    filledCircleRGBA(renderer, CENTER_X, CENTER_Y, CLOCK_R + 10, 10, 10, 30, 255);

    // Face principal
    filledCircleRGBA(renderer, CENTER_X, CENTER_Y, CLOCK_R, 240, 240, 255, 255);

    // Marcações dos minutos (pequenas)
    for (int i = 0; i < 60; i++)
    {
        float angle = i * 6.0f;
        float rad = angle * PI / 180.0f;
        int x1 = CENTER_X + (CLOCK_R - 15) * cosf(rad);
        int y1 = CENTER_Y + (CLOCK_R - 15) * sinf(rad);
        int x2 = CENTER_X + CLOCK_R * cosf(rad);
        int y2 = CENTER_Y + CLOCK_R * sinf(rad);

        if (i % 5 == 0)
            thickLineRGBA(renderer, x1, y1, x2, y2, 6, 0, 0, 0, 255);
        else
            thickLineRGBA(renderer, x1, y1, x2, y2, 2, 100, 100, 100, 255);
    }

    // Números das horas
    for (int h = 1; h <= 12; h++)
    {
        float angle = (h * 30.0f) - 90.0f; // -90 para começar no 12
        float rad = angle * PI / 180.0f;
        int x = CENTER_X + (CLOCK_R - 50) * cosf(rad) - 15;
        int y = CENTER_Y + (CLOCK_R - 50) * sinf(rad) + 10;

        char num[4];
        sprintf(num, "%d", h);

        SDL_Color black = {0, 0, 0};
        SDL_Surface *surf = TTF_RenderText_Solid(font, num, black);
        SDL_Texture *tex = SDL_CreateTextureFromSurface(renderer, surf);

        SDL_Rect dst = {x, y, surf->w, surf->h};
        SDL_RenderCopy(renderer, tex, NULL, &dst);

        SDL_FreeSurface(surf);
        SDL_DestroyTexture(tex);
    }

    // Ponto central
    filledCircleRGBA(renderer, CENTER_X, CENTER_Y, 12, 0, 0, 0, 255);
    filledCircleRGBA(renderer, CENTER_X, CENTER_Y, 6, 200, 200, 200, 255);
}

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1)
    {
        printf("TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    window = SDL_CreateWindow("Relógio Analógico - C + SDL2",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    font = TTF_OpenFont("arial.ttf", 36); // Coloque uma fonte no mesmo diretório ou use caminho completo
    if (!font)
    {
        font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 36); // Linux fallback
        if (!font)
            font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 36); // Windows fallback
        if (!font)
            printf("Fonte não encontrada! Números não serão exibidos.\n");
    }

    int running = 1;
    SDL_Event e;

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE))
                running = 0;
        }

        time_t rawtime;
        struct tm *timeinfo = NULL;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        int hours = timeinfo->tm_hour % 12;
        int minutes = timeinfo->tm_min;
        int seconds = timeinfo->tm_sec;

        // Ângulos (0° = 12h, sentido horário)
        float sec_angle = seconds * 6.0f;                  // 360/60
        float min_angle = minutes * 6.0f + seconds * 0.1f; // + movimento suave
        float hour_angle = hours * 30.0f + minutes * 0.5f; // 360/12 + movimento

        draw_clock_face();

        // Ponteiro das horas (grosso e curto)
        draw_hand(hour_angle - 90, CLOCK_R * 0.5f, 10, 200, 0, 0);

        // Ponteiro dos minutos (médio)
        draw_hand(min_angle - 90, CLOCK_R * 0.8f, 6, 0, 0, 200);

        // Ponteiro dos segundos (fino e vermelho)
        draw_hand(sec_angle - 90, CLOCK_R * 0.9f, 3, 255, 50, 50);

        // Atualiza tela
        SDL_RenderPresent(renderer);

        // Pequena pausa para reduzir uso de CPU
        SDL_Delay(50);
    }

    if (font)
        TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    /**
     * Para compilar:
     *
     * gcc -o relogio clock.c -lSDL2 -lSDL2_gfx -lSDL2_ttf -lm
     * ./relogio
     */
    return 0;
}
