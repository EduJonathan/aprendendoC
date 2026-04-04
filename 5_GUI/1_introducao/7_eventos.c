/**
 * Eventos
 * Eventos são ações ou ocorrências que acontecem durante a execução de um programa, e que podem ser detectados e respondidos pelo programa.
 *
 * Em C, os eventos podem ser gerados por interações do usuário, como cliques de mouse ou pressionamento de teclas,
 * ou por mudanças no estado do programa, como a chegada de dados em uma rede ou a conclusão de uma operação de entrada/saída.
 *
 * Em C, os eventos são geralmente tratados usando funções de callback, que são funções que são chamadas em resposta a um evento específico.
 *
 * Por exemplo, em uma interface gráfica, você pode ter uma função de callback que é chamada quando o usuário clica em um botão,
 * e essa função pode executar uma ação específica, como exibir uma mensagem ou atualizar a interface do usuário.
 *
 * O tratamento de eventos é uma parte fundamental do desenvolvimento de aplicativos interativos, e é importante entender
 * como os eventos funcionam em C para criar programas que respondam de maneira eficaz às ações do usuário e às mudanças
 * no estado do programa.
 */

/**
 * Este código irá tratar quadrantes com clicks do mouse, e a cada click irá aparecer uma legenda impressa
 * onde o mouse foi clicado(Exemplo: você está no quadrante 198x198). O programa também irá tratar um botão
 * que ao clicar irá selecionar um quadrante aleatório, e irá imprimir a legenda do quadrante selecionado aletoriamente.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Configurações da janela e grade
#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 800
#define GRID_SIZE     200

// Botão
#define BUTTON_W 380
#define BUTTON_H 80
#define BUTTON_X (WINDOW_WIDTH - BUTTON_W) / 2
#define BUTTON_Y WINDOW_HEIGHT - 120

// Cores
#define COLOR_BG     20, 20, 25, 255
#define COLOR_GRID   60, 60, 60, 255
#define COLOR_BUTTON 70, 130, 180, 255
#define COLOR_HOVER  100, 180, 240, 255
#define COLOR_TEXT   255, 255, 255, 255

/**
 * @brief Callback para clique do mouse, identificando o quadrante clicado
 *
 * @param x Coordenada x do clique
 * @param y Coordenada y do clique
 */
void on_mouse_click(int x, int y)
{
    if(x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
        return;

    int col = x / GRID_SIZE;
    int row = y / GRID_SIZE;
    if (col >= 0 && col < 4 && row >= 0 && row < 4)
    {
        printf("Você clicou no quadrante (%d, %d) → ~%d,%d\n",
               col, row, col * GRID_SIZE + GRID_SIZE / 2, row * GRID_SIZE + GRID_SIZE / 2);
    }
}

/**
 * @brief Callback para seleção aleatória de um quadrante
 */
void on_random_select()
{
    int col = rand() % 4;
    int row = rand() % 4;
    printf("Quadrante sorteado: (%d, %d) → ~%d,%d\n",
           col, row, col * GRID_SIZE + GRID_SIZE / 2, row * GRID_SIZE + GRID_SIZE / 2);
}

/**
 * @brief Desenha a grade de quadrantes na tela
 *
 * @param renderer O renderizador para desenhar a grade
 */
void draw_grid(SDL_Renderer *renderer)
{
    if(!renderer)
        return;

    SDL_SetRenderDrawColor(renderer, COLOR_GRID);
    for (int i = 1; i < 4; i++)
    {
        SDL_RenderDrawLine(renderer, i * GRID_SIZE, 0, i * GRID_SIZE, WINDOW_HEIGHT);
        SDL_RenderDrawLine(renderer, 0, i * GRID_SIZE, WINDOW_WIDTH, i * GRID_SIZE);
    }
}

/**
 * @brief Desenha um botão na tela, mudando a cor se o mouse estiver sobre ele
 *
 * @param renderer O renderizador para desenhar o botão
 * @param font A fonte para renderizar o texto do botão
 * @param mouse_over Indica se o mouse está sobre o botão (1 para sim, 0 para não)
 */
void draw_button(SDL_Renderer *renderer, TTF_Font *font, int mouse_over)
{
    if(!renderer || !font || mouse_over < 0)
        return;

    SDL_Rect button_rect = {BUTTON_X, BUTTON_Y, BUTTON_W, BUTTON_H};

    // Fundo do botão
    SDL_SetRenderDrawColor(renderer, mouse_over ? COLOR_HOVER : COLOR_BUTTON);
    SDL_RenderFillRect(renderer, &button_rect);

    // Borda
    SDL_SetRenderDrawColor(renderer, 200, 200, 220, 255);
    SDL_RenderDrawRect(renderer, &button_rect);

    if (!font)
        return;

    // Texto
    SDL_Color text_color = {COLOR_TEXT};
    const char *texto = "Selecionar Quadrante aleatório";

    SDL_Surface *text_surface = TTF_RenderUTF8_Blended(font, texto, text_color);
    if (!text_surface)
    {
        printf("Erro ao renderizar texto: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
    if (!text_texture)
    {
        SDL_FreeSurface(text_surface);
        return;
    }

    // Centralizar texto no botão
    SDL_Rect text_rect;
    text_rect.w = text_surface->w;
    text_rect.h = text_surface->h;
    text_rect.x = BUTTON_X + (BUTTON_W - text_rect.w) / 2;
    text_rect.y = BUTTON_Y + (BUTTON_H - text_rect.h) / 2;

    SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);

    // Limpeza
    SDL_DestroyTexture(text_texture);
    SDL_FreeSurface(text_surface);
}

/**
 * @brief Verifica se o mouse está sobre o botão
 *
 * @param mx Coordenada x do mouse
 * @param my Coordenada y do mouse
 * @return 1 se o mouse estiver sobre o botão, 0 caso contrário
 */
int is_mouse_over_button(int mx, int my)
{
    if (mx < 0 || mx >= WINDOW_WIDTH || my < 0 || my >= WINDOW_HEIGHT)
        return 0;

    return (mx >= BUTTON_X && mx < BUTTON_X + BUTTON_W &&
            my >= BUTTON_Y && my < BUTTON_Y + BUTTON_H);
}

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1)
    {
        fprintf(stderr, "TTF_Init Error: %s\n", TTF_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Quadrantes + Botão com Texto",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Carregar fonte (ajuste o caminho/nome!)
    TTF_Font *font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 24);

    // Alternativas: "arial.ttf", "DejaVuSans.ttf", etc.
    if (!font)
    {
        printf("Erro ao carregar fonte: %s\n", TTF_GetError());
        // Continua rodando mesmo sem fonte (botão fica sem texto)
    }

    srand((unsigned)time(NULL));

    int running = 1;
    SDL_Event event;
    int mouse_x = 0, mouse_y = 0;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = 0;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (is_mouse_over_button(event.button.x, event.button.y))
                    {
                        on_random_select();
                    }
                    else
                    {
                        on_mouse_click(event.button.x, event.button.y);
                    }
                }
                break;

            case SDL_MOUSEMOTION:
                mouse_x = event.motion.x;
                mouse_y = event.motion.y;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_SPACE || event.key.keysym.sym == SDLK_r)
                {
                    on_random_select();
                }
                break;
            }
        }

        // Desenho
        SDL_SetRenderDrawColor(renderer, COLOR_BG);
        SDL_RenderClear(renderer);

        draw_grid(renderer);
        draw_button(renderer, font, is_mouse_over_button(mouse_x, mouse_y));

        SDL_RenderPresent(renderer);
    }

    // Limpeza
    if (font)
        TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    /**
     * Para compilar:
     *
     * gcc -o events 7_eventos.c -lSDL2 -lSDL2_ttf -lm
     * ./relogio
     */

    return 0;
}

