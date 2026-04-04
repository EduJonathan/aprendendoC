#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

/**
 * Keywords
 * 
 * keywords no GUI, são comportamentos que definem como os elementos interagem de acordo com o teclado para realizar ações.
 * Por exemplo, usar as setas do teclado para mover um personagem, ou usar a tecla Enter para confirmar uma escolha.
 * Eles ocorrem quando o usuário pressiona uma tecla específica, e o programa responde a essa ação de acordo com a lógica definida.
 *
 * Para exemplificar o conceito de keywords este código utilizarmos uma base de movimento do jogo space invarders.
 */

#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 600
#define PLAYER_SPEED  5
#define BULLET_SPEED  8

typedef struct
{
    int x, y;
    bool active;
} Bullet;

int main(int argc, char **argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Space Invaders - Teclas (Keyboard Events)",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN
    );

    if (!window)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Estado do jogador
    int player_x  = SCREEN_WIDTH / 2 - 25;
    int player_y  = SCREEN_HEIGHT - 80;
    Bullet bullet = {0, 0, false}; // só permite 1 tiro por vez (simples)

    bool left_pressed  = false;
    bool right_pressed = false;

    bool running = true;
    SDL_Event event;

    while (running)
    {
        // 1. Processar eventos (teclas pressionadas/soltas)
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    left_pressed = true;
                    break;

                case SDLK_RIGHT:
                    right_pressed = true;
                    break;
                
                case SDLK_SPACE:
                    if (!bullet.active)
                    {
                        bullet.x = player_x + 20; // centro da nave
                        bullet.y = player_y - 10;
                        bullet.active = true;
                        printf("Tiro disparado!\n");
                    }
                    break;
                    
                case SDLK_ESCAPE:
                    running = false;
                    break;
                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    left_pressed = false;
                    break;

                case SDLK_RIGHT:
                    right_pressed = false;
                    break;
                }
                break;
            }
        }

        // 2. Atualizar lógica com base nas teclas pressionadas (suave)
        if (left_pressed && player_x > 0)
        {
            player_x -= PLAYER_SPEED;
        }
        if (right_pressed && player_x < SCREEN_WIDTH - 50)
        {
            player_x += PLAYER_SPEED;
        }

        // Atualizar bala
        if (bullet.active)
        {
            bullet.y -= BULLET_SPEED;
            if (bullet.y < 0)
            {
                bullet.active = false;
            }
        }

        // 3. Desenhar
        SDL_SetRenderDrawColor(renderer, 0, 0, 20, 255); // fundo escuro
        SDL_RenderClear(renderer);

        // Nave do jogador (retângulo branco simples)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect player_rect = {player_x, player_y, 50, 30};
        SDL_RenderFillRect(renderer, &player_rect);

        // Bala (se ativa)
        if (bullet.active)
        {
            SDL_SetRenderDrawColor(renderer, 255, 100, 100, 255); // vermelho
            SDL_Rect bullet_rect = {bullet.x - 3, bullet.y - 10, 6, 20};
            SDL_RenderFillRect(renderer, &bullet_rect);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16); // ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    /**
     * Para Compilar
     *
     * gcc -o space_invaders 4_keywords.c -lSDL2
     * ./space_invaders
     */

    return 0;
}
