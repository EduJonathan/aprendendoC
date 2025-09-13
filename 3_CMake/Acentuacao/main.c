#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    // Força o console do Windows a usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif

    printf("Olá, mundo! Acentuação: á é í ó ú ç ã õ\n");
    printf("Dados: 🎲\t Arvore: 🌲\n");

    return 0;
}
