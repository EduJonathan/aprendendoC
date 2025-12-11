#include <stdio.h>
#include <SDL2/SDL.h>

// Como criar uma tela simples com SDL2

int main(int argc, char **argv)
{
    // Inicializa apenas o subsistema de vídeo
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("Erro ao inicializar SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Criação da janela
    SDL_Window *window = SDL_CreateWindow(
        "Minha Janela SDL2",    // Título
        SDL_WINDOWPOS_CENTERED, // Posição X
        SDL_WINDOWPOS_CENTERED, // Posição Y
        800,                    // Largura
        600,                    // Altura
        SDL_WINDOW_SHOWN        // Flags (visível)
    );

    if (!window)
    {
        printf("Erro ao criar janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Renderer (opcional, mas recomendado)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("Erro ao criar renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Loop principal (espera até o usuário fechar a janela)
    SDL_bool running = SDL_TRUE;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = SDL_FALSE;
            }
        }

        // Cor de fundo (RGB + Alpha)
        SDL_SetRenderDrawColor(renderer, 20, 20, 20, 255); // cinza escuro
        SDL_RenderClear(renderer);

        // Finaliza o frame
        SDL_RenderPresent(renderer);
    }

    // Limpa tudo antes de sair
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    /**
     * Para compilar este código, use o seguinte comando (ajuste o caminho do SDL2 conforme necessário):
     *
     * gcc criar_tela.c -o minha_primeira_tela `sdl2-config --cflags --libs`
     * ./minha_primeira_tela
     */

    return 0;
}
