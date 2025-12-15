#include <stdio.h>
#include <locale.h>
#include <wchar.h>

/**
 * Para compilar e executar este código utilizando os scripts:
 *
 * 1. Navegue até o diretório do projeto:
 *    3_CMake/1_UTF
 *
 * 2. Dê permissão de execução aos scripts (apenas uma vez no Linux):
 *    chmod +x scripts/build.sh scripts/run.sh scripts/clean.sh
 *
 * 3. Compile o programa:
 *    ./scripts/build.sh
 *
 * 4. Execute o programa:
 *    ./scripts/run.sh
 *
 * 5. (Opcional) Limpe os arquivos gerados:
 *    ./scripts/clean.sh
 */

#ifdef _WIN32
#include <windows.h>
#endif

int main(void)
{
#ifdef _WIN32
    // Força o console do Windows a usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
#endif

    // Ativa suporte a Unicode (UTF-8)
    setlocale(LC_ALL, "");

    // Texto normal
    printf("Olá, mundo! Acentuação: á é í ó ú ç ã õ\n");
    printf("Dados: 🎲\t Árvore: 🌲\n");
    printf("Coração: ❤️\t Sorriso: 😊\n\n");

    return 0;
}
