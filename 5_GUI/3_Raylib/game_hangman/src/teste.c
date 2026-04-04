#include "raylib.h"

int main()
{
    InitWindow(800, 450, "Módulo 5 - Jogo da Forca");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // 1. LÓGICA / INPUT
        if (IsKeyPressed(KEY_A))
        { 
            /* verifica se tem 'A' na palavra */
        }

        // 2. DESENHO
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Adivinhe a palavra:", 100, 100, 20, DARKGRAY);
        // Aqui você desenha a forca baseado no número de erros
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
