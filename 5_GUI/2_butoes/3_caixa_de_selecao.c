#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define W 800
#define H 800

typedef struct
{
    SDL_Rect rect;
    int open;
    const char *options[5];
    int option_count;
    int selected; // -1 = nenhum
} Dropdown;

int main(int argc, char **argv)
{
    // Necessário para exibir corretamente ç, ã, é, etc. no terminal (não afeta SDL)
    setlocale(LC_ALL, "");

    SDL_Init(SDL_INIT_VIDEO); // Inicializa SDL2
    TTF_Init();               // Inicializa SDL_ttf
    SDL_StartTextInput();     // Permite entrada UTF-8

    SDL_Window *win = SDL_CreateWindow("Criação de Personagem",
                                       SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    // Fonte (coloque uma .ttf no diretório ou use caminho completo)
    TTF_Font *font = TTF_OpenFont("arial.ttf", 28);
    if (!font)
    {
        font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 28);
    }
    if (!font)
    {
        printf("Erro: fonte não encontrada! Coloque uma .ttf no diretório.\n");
        return 1;
    }

    SDL_Color white = {255, 255, 255, 255};
    SDL_Color gray = {180, 180, 180, 255};
    SDL_Color yellow = {255, 255, 100, 255};

    // Caixa de texto (nome)
    SDL_Rect textbox = {150, 80, 300, 50};
    char name[50] = "";
    int typing = 0;

    // Dropdown de classe
    Dropdown dd = {0};
    dd.rect = (SDL_Rect){150, 160, 300, 50};
    dd.options[0] = "Guerreiro";
    dd.options[1] = "Mago Negro";
    dd.options[2] = "Mago Branco";
    dd.options[3] = "Paladino";
    dd.options[4] = "Camponês";
    dd.option_count = 5;
    dd.open = 0;
    dd.selected = -1;

    // Botão "Criar Personagem"
    SDL_Rect button = {150, 240, 300, 60};
    int hover_button = 0;
    int created = 0; // Personagem já criado?
    char summary[200] = "";

    int running = 1;
    SDL_Event e;

    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                running = 0;

            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
                int mx = e.button.x, my = e.button.y;
                SDL_Point mouse = {mx, my};

                // Caixa de texto
                typing = SDL_PointInRect(&mouse, &textbox);

                // Dropdown
                if (SDL_PointInRect(&mouse, &dd.rect))
                {
                    dd.open = !dd.open;
                }

                if (dd.open)
                {
                    for (int i = 0; i < dd.option_count; i++)
                    {
                        SDL_Rect opt = {dd.rect.x, dd.rect.y + dd.rect.h * (i + 1),
                                        dd.rect.w, dd.rect.h};
                        if (SDL_PointInRect(&mouse, &opt))
                        {
                            dd.selected = i;
                            dd.open = 0;
                        }
                    }
                }

                // Botão Criar
                if (SDL_PointInRect(&mouse, &button))
                {
                    if (strlen(name) > 0 && dd.selected >= 0)
                    {
                        snprintf(summary, sizeof(summary),
                                 "Personagem criado!\nNome: %s\nClasse: %s", name, dd.options[dd.selected]);
                        created = 1;
                    }
                }

                // Clicar fora fecha dropdown
                if (dd.open && !SDL_PointInRect(&mouse, &dd.rect))
                {
                    int inside = 0;
                    for (int i = 0; i < dd.option_count; i++)
                    {
                        SDL_Rect opt = {dd.rect.x, dd.rect.y + dd.rect.h * (i + 1),
                                        dd.rect.w, dd.rect.h};
                        if (SDL_PointInRect(&mouse, &opt))
                        {
                            inside = 1;
                            break;
                        }
                    }
                    if (!inside)
                        dd.open = 0;
                }
            }

            // Hover no botão
            if (e.type == SDL_MOUSEMOTION)
            {
                hover_button = SDL_PointInRect(&(SDL_Point){e.motion.x, e.motion.y}, &button);
            }

            // Digitação (agora aceita UTF-8 completo)
            if (typing)
            {
                if (e.type == SDL_TEXTINPUT)
                {
                    if (strlen(name) + strlen(e.text.text) < sizeof(name) - 1)
                    {
                        strcat(name, e.text.text);
                    }
                }
                if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_BACKSPACE && strlen(name) > 0)
                {
                    // Remove último caractere UTF-8 corretamente (simplificado)
                    int len = strlen(name);
                    name[len - 1] = '\0';
                }
            }
        }

        // === Renderização ===
        SDL_SetRenderDrawColor(ren, 20, 20, 30, 255);
        SDL_RenderClear(ren);

        // Título
        if (font)
        {
            SDL_Surface *surf = TTF_RenderUTF8_Blended(font, "Criação de Personagem", white);
            SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surf);
            SDL_Rect dst = {150, 20, surf->w, surf->h};
            SDL_RenderCopy(ren, tex, NULL, &dst);
            SDL_DestroyTexture(tex);
            SDL_FreeSurface(surf);
        }

        // Caixa de texto
        SDL_SetRenderDrawColor(ren, typing ? 100 : 60, 60, 100, 255);
        SDL_RenderFillRect(ren, &textbox);
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderDrawRect(ren, &textbox);

        // Texto do nome
        if (font)
        {
            const char *text = name[0] ? name : "Digite seu nome...";
            SDL_Color col = name[0] ? white : gray;
            SDL_Surface *surf = TTF_RenderUTF8_Blended(font, text, col);
            SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surf);
            SDL_Rect dst = {textbox.x + 15, textbox.y + 10, surf->w, surf->h};
            SDL_RenderCopy(ren, tex, NULL, &dst);
            SDL_DestroyTexture(tex);
            SDL_FreeSurface(surf);
        }

        // Dropdown
        SDL_SetRenderDrawColor(ren, 80, 80, 120, 255);
        SDL_RenderFillRect(ren, &dd.rect);
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderDrawRect(ren, &dd.rect);

        const char *class_text = (dd.selected >= 0) ? dd.options[dd.selected] : "Selecione uma classe...";
        if (font)
        {
            SDL_Surface *surf = TTF_RenderUTF8_Blended(font, class_text, white);
            SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surf);
            SDL_Rect dst = {dd.rect.x + 15, dd.rect.y + 10, surf->w, surf->h};
            SDL_RenderCopy(ren, tex, NULL, &dst);
            SDL_DestroyTexture(tex);
            SDL_FreeSurface(surf);
        }

        // Seta dropdown
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        int tx = dd.rect.x + dd.rect.w - 30;
        int ty = dd.rect.y + dd.rect.h / 2;
        SDL_RenderDrawLine(ren, tx - 8, ty - 6, tx + 8, ty - 6);
        SDL_RenderDrawLine(ren, tx - 8, ty - 6, tx, ty + 6);
        SDL_RenderDrawLine(ren, tx, ty + 6, tx + 8, ty - 6);

        // Opções abertas
        if (dd.open)
        {
            for (int i = 0; i < dd.option_count; i++)
            {
                SDL_Rect opt = {dd.rect.x, dd.rect.y + dd.rect.h * (i + 1), dd.rect.w, dd.rect.h};
                SDL_SetRenderDrawColor(ren, 100, 100, 140, 255);
                SDL_RenderFillRect(ren, &opt);
                SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
                SDL_RenderDrawRect(ren, &opt);

                SDL_Color col = (dd.selected == i) ? yellow : white;
                SDL_Surface *surf = TTF_RenderUTF8_Blended(font, dd.options[i], col);
                SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surf);
                SDL_Rect dst = {opt.x + 15, opt.y + 10, surf->w, surf->h};
                SDL_RenderCopy(ren, tex, NULL, &dst);
                SDL_DestroyTexture(tex);
                SDL_FreeSurface(surf);
            }
        }

        // Botão Criar Personagem
        SDL_SetRenderDrawColor(ren, hover_button ? 60 : 40, 120, 60, 255);
        SDL_RenderFillRect(ren, &button);
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        SDL_RenderDrawRect(ren, &button);

        if (font)
        {
            SDL_Surface *surf = TTF_RenderUTF8_Blended(font, "Criar Personagem", white);
            SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surf);
            SDL_Rect dst = {button.x + (button.w - surf->w) / 2, button.y + 12, surf->w, surf->h};
            SDL_RenderCopy(ren, tex, NULL, &dst);
            SDL_DestroyTexture(tex);
            SDL_FreeSurface(surf);
        }

        // Resumo após criar
        if (created && font)
        {
            SDL_Surface *surf = TTF_RenderUTF8_Blended(font, summary, yellow);
            SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surf);
            SDL_Rect dst = {100, 330, surf->w, surf->h};
            SDL_RenderCopy(ren, tex, NULL, &dst);
            SDL_DestroyTexture(tex);
            SDL_FreeSurface(surf);
        }

        SDL_RenderPresent(ren);
        SDL_Delay(16);
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_StopTextInput();
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;

    /**
     * Devido às bibliotecas de extensão .h de <SDL2_ttf>, compile com:
     * gcc -o criacao ./caixa_de_selecao.c `sdl2-config --cflags --libs` -lSDL2 -lSDL2_ttf
     * ./criacao
     */
}
